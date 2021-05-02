#include "memecad/mapper.h"

#include <kernel/sigtools.h>

#include <boost/lexical_cast.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <utility>

#include "verymeme/macros.h"
#include "verymeme/util.h"

namespace memecad {

namespace {

const pt::ptree* findMappingForModuleType(const std::string& module_type, const pt::ptree& root) {
  // Discard $gen$ or $paramod$, look for the user-specified part of the name.
  const auto pos = module_type.find('\\');
  if (pos == std::string::npos) return nullptr;
  const std::string name = module_type.substr(pos + 1);
  for (const auto& kv : root) {
    const auto& [k, v] = kv;
    if (name == v.get<std::string>("verilog_name")) return &v;
  }
  return nullptr;
}

std::vector<const Lib::Pin*> parseKicadPinSpec(
    const std::string& pin_spec, const Lib::Component& lib_component) {
  // Pin specifier is either: a pin id; a pin name; a pin base name and integer range.
  // If a pin name does not exist, try to resolve it to a pin range. If both exist, default to
  // the single pin.
  // e.g. 1; OE; A[12:0]
  // Check for pin id.
  const auto* pin_by_id = lib_component.findPinById(pin_spec);
  const auto* pin_by_name = lib_component.findPinByName(pin_spec);
  verify_expr(!(pin_by_id && pin_by_name), "ambiguous pin for pin spec '%s'", pin_spec.c_str());
  if (pin_by_id) return {pin_by_id};

  // Check for explicit pin.
  const std::regex split(R"(^([^\]]+)\[(\d+):(\d+)]$)");
  std::smatch sm;
  if (std::regex_match(pin_spec, sm, split)) {
    const std::string& pin_basename = sm[1];
    const int en = boost::lexical_cast<int>(sm[2]);
    const int st = boost::lexical_cast<int>(sm[3]);
    std::vector<const Lib::Pin*> pins;
    verify_expr(st <= en, "pin specs (currently) must be specified from MSB to LSB");
    for (int i = en; i >= st; --i) {
      const std::string pin_name = pin_basename + std::to_string(i);
      const auto* pin = lib_component.findPinByName(pin_name);
      verify_expr(pin, "couldn't find pin with name '%s' in pin spec", pin_name.c_str());
      pins.push_back(pin);
    }
    return pins;
  }

  if (!pin_by_name) {
    // Check for implicit pins.
    int index = 0;
    std::vector<const Lib::Pin*> pins;
    while (true) {
      const std::string pin_name = pin_spec + std::to_string(index);
      const auto* ranged_pin = lib_component.findPinByName(pin_name);
      if (!ranged_pin) break;
      pins.push_back(ranged_pin);
      index++;
    }
    verify_expr(!pins.empty(), "implicit pin spec '%s' does not exist", pin_spec.c_str());
    return reverse(std::move(pins));
  }

  verify_expr(pin_by_name, "pin spec '%s' is neither pin number, valid pin name, valid pin range",
      pin_spec.c_str());
  return {pin_by_name};
}

std::vector<const Lib::Pin*> parseKicadSignal(
    std::string pin_specs, const Lib::Component& lib_component) {
  // Kicad signal consists of a comma separated list of pin specs.
  std::string pin_spec;
  std::vector<const Lib::Pin*> pins;
  pin_specs += ',';  // Sentinel.
  for (auto c : pin_specs) {
    if (c == ',') {
      for (const auto* pin : parseKicadPinSpec(pin_spec, lib_component)) pins.push_back(pin);
      pin_spec.clear();
    } else {
      pin_spec += c;
    }
  }
  return pins;
}

ConnectionData makeConnectionData(
    const std::pair<Yosys::IdString, Yosys::SigSpec>& conn, const Yosys::SigBit& bit, int offset) {
  // Child label is the connection id without the leading '\' - i.e. the connection name.
  // Don't include the offset if it's only a single bit.
  std::string child_label = conn.first.c_str() + 1;
  if (conn.second.size() > 1) child_label += std::to_string(offset);

  return ConnectionData{child_label, bit};
}

std::vector<ConnectionData> getConnectionsForSignal(
    const std::string& pin_spec, const Yosys::RTLIL::Cell& cell, int suggest_width) {
  std::vector<ConnectionData> conn_data;
  if (pin_spec == "1") {
    for (int i = 0; i < suggest_width; ++i) conn_data.push_back({"VCC", {Yosys::State::S1}});
  } else if (pin_spec == "0") {
    for (int i = 0; i < suggest_width; ++i) conn_data.push_back({"GND", {Yosys::State::S0}});
  } else {
    // Collect module connections.
    auto conn_iter = cell.connections().find("\\" + pin_spec);
    verify_expr(conn_iter != cell.connections().end(), "invalid verilog signal '%s' in module %s'",
        pin_spec.c_str(), cell.name.c_str());
    Yosys::SigMap sigmap(cell.module);
    const auto& signal = sigmap(conn_iter->second);
    for (int i = 0; i < signal.size(); ++i)
      conn_data.push_back(makeConnectionData(*conn_iter, signal[i], i));
  }
  return conn_data;
}

}  // namespace

Mapper::Mapper(const std::string& memecad_json, std::vector<Lib> libs) : libs_(std::move(libs)) {
  std::stringstream s(memecad_json);
  pt::read_json(s, root_);
}

void Mapper::addCell(const Yosys::RTLIL::Cell& cell) {
  // Cell type is either mapping a Kicad library component and it's in the map, or it's a parent
  // component. There should be a mapped module for each leaf module. Look up using the full
  // type name, not the result of |moduleType| because the '\' is used during lookup.
  const auto* mapping = findMappingForModuleType(moduleType(cell), root_);
  if (mapping)
    addMappedModule(cell, *mapping);
  else
    addUnmappedModule(cell);
}

void Mapper::addUnmappedModule(const Yosys::Cell& cell) {
  printf("Adding unmapped module '%s'\n", modulePath(cell).c_str());
  ChildMapping child_mapping;
  for (const auto& conn : cell.connections()) {
    for (const auto& conn_data :
        getConnectionsForSignal(conn.first.c_str() + 1, cell, -1 /* suggest_width */)) {
      verify_expr(!child_mapping.count(conn_data.child_label),
          "duplicate mapping from child label '%s'", conn_data.child_label.c_str());
      child_mapping[conn_data.child_label] = conn_data;
      printf("  Mapping %s => %s\n", conn_data.child_label.c_str(),
          getIdForSigBit(conn_data.bit).c_str());
    }
  }
  schematic_.addChildSheetToParent(
      moduleName(cell), child_mapping, moduleType(cell), parentModuleType(cell));
}

void Mapper::addMappedModule(const Yosys::RTLIL::Cell& cell, const pt::ptree& mapping) {
  printf("Adding mapped module '%s'\n", modulePath(cell).c_str());
  const auto kicad_name = mapping.get<std::string>("kicad_name");
  Lib::Component* lib_component = nullptr;
  Lib* lib;
  for (auto& l : libs_) {
    lib = &l;
    lib_component = l.findComponent(kicad_name);
    if (lib_component) break;
  }
  verify_expr(
      lib_component != nullptr, "could not find library component '%s'", kicad_name.c_str());

  // Add labels for connecting each component.
  PinMapping pin_mapping;
  for (const auto& kv : mapping.get_child("verilog_to_kicad_map")) {
    const auto& [verilog_signal, child_tree] = kv;
    std::vector<std::string> kicad_signals;
    if (child_tree.empty()) kicad_signals.push_back(child_tree.get_value<std::string>());
    for (const auto& kv2 : child_tree) kicad_signals.push_back(kv2.second.get_value<std::string>());

    for (const auto& kicad_signal_name : kicad_signals) {
      const auto& kicad_pins = parseKicadSignal(kicad_signal_name, *lib_component);
      const auto& conns =
          getConnectionsForSignal(verilog_signal, cell, kicad_pins.size() /* suggest_width */);
      verify_expr(kicad_pins.size() == conns.size(),
          "bit-width of kicad signal '%s|%d' does not match bit-width of verilog signal '%s|%d'",
          kicad_signal_name.c_str(), int(kicad_pins.size()), verilog_signal.c_str(),
          int(conns.size()));
      for (int i = 0; i < kicad_pins.size(); ++i) {
        pin_mapping[kicad_pins[i]] = conns[i];
        printf("  Mapping %s (pin %s) => %s => %s\n", kicad_pins[i]->name.c_str(),
            kicad_pins[i]->id.c_str(), conns[i].child_label.c_str(),
            getIdForSigBit(conns[i].bit).c_str());
      }
    }
  }

  schematic_.addComponentToSheet(lib->name, *lib_component, pin_mapping, parentModuleType(cell));
}

void Mapper::addModule(const Yosys::Module& module) {
  const std::string module_name = moduleName(module);
  printf("Adding module connections for '%s'\n", module_name.c_str());
  schematic_.addModuleConnectionsToSheet(module_name, module.connections());
}

bool Mapper::isMappedModule(const Yosys::RTLIL::Module& module) const {
  return findMappingForModuleType(module.name.str(), root_) != nullptr;
}

}  // namespace memecad
