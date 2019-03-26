#include "memecad/mapper.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>
#include <kernel/sigtools.h>

namespace memecad {

namespace {

const pt::ptree* findMappingForCell(const Yosys::RTLIL::Cell& cell, const pt::ptree& root) {
  const std::string module_type = moduleType(cell);
  for (const auto& kv : root) {
    const auto&[k, v] = kv;
    if (module_type == v.get<std::string>("verilog_name"))
      return &v;
  }
  return nullptr;
}

bool isInteger(const std::string& s) {
  for (auto c : s)
    if (!isdigit(c)) return false;
  return true;
}

std::vector<const Lib::Pin*>
parseKicadPinSpec(const std::string& pin_spec, const Lib::Component& lib_component) {
  // Pin specifier is either: a pin number; a pin name; a pin base name and integer range.
  // If a pin name does not exist, try to resolve it to a pin range. If both exist, default to
  // the single pin.
  // e.g. 1; OE; A[12:0]
  // Check for pin number.
  if (isInteger(pin_spec)) {
    const auto* pin = lib_component.findPin(boost::lexical_cast<int>(pin_spec));
    verify_expr(pin, "can't find pin with number %s", pin_spec.c_str());
    return {pin};
  }

  // Check for explicit pin.
  const std::regex split(R"(^([^\]])+\[(\d+):(\d+)]$)");
  std::smatch sm;
  if (std::regex_match(pin_spec, sm, split)) {
    const std::string& pin_basename = sm[1];
    const int en = boost::lexical_cast<int>(sm[2]);
    const int st = boost::lexical_cast<int>(sm[3]);
    std::vector<const Lib::Pin*> pins;
    verify_expr(st <= en, "pin specs (currently) must be specified from MSB to LSB");
    for (int i = en; i >= st; --i) {
      const std::string pin_name = pin_basename + std::to_string(i);
      const auto* pin = lib_component.findPin(pin_name);
      verify_expr(pin, "couldn't find pin with name '%s' in pin spec", pin_name.c_str());
      pins.push_back(pin);
    }
    return pins;
  }

  // Check for singular pin.
  const auto* pin = lib_component.findPin(pin_spec);
  if (!pin) {
    // Check for implicit pins.
    int index = 0;
    std::vector<const Lib::Pin*> pins;
    while (true) {
      const std::string pin_name = pin_spec + std::to_string(index);
      const auto* ranged_pin = lib_component.findPin(pin_name);
      if (!ranged_pin) break;
      pins.push_back(ranged_pin);
      index++;
    }
    verify_expr(!pins.empty(), "implicit pin spec '%s' does not exist", pin_spec.c_str());
    return reverse(std::move(pins));
  }
  verify_expr(pin,
      "pin spec '%s' is neither pin number, valid pin name, valid pin range",
      pin_spec.c_str());
  return {pin};
}

std::vector<const Lib::Pin*>
parseKicadSignal(std::string pin_specs, const Lib::Component& lib_component) {
  // Kicad signal consists of a comma separated list of pin specs.
  std::string pin_spec;
  std::vector<const Lib::Pin*> pins;
  pin_specs += ',';  // Sentinel.
  for (auto c : pin_specs) {
    if (c == ',') {
      auto range_pins = parseKicadPinSpec(pin_spec, lib_component);
      pins.insert(pins.end(), range_pins.begin(), range_pins.end());
      pin_spec.clear();
    } else {
      pin_spec += c;
    }
  }
  return pins;
}

ConnectionData
makeConnectionData(const std::pair<Yosys::IdString, Yosys::SigSpec>& conn,
    const Yosys::SigBit& bit, int offset) {
  // Parent label is where the connection goes to from the child.
  std::string parent_label;
  if (bit.wire) {
    parent_label = std::string(bit.wire->name.c_str() + 1);
    // A single child signal may connect to multiple different parent signals and wires, e.g.
    // .B(C[2:0], C_IN): The child signal B connects to C_IN and C[2:0]. So, use parent offset
    // and width values for deciding the parent label.
    if (bit.wire->width > 1) parent_label += std::to_string(bit.offset);
  } else {
    verify_expr(bit.data == Yosys::State::S0 || bit.data == Yosys::State::S1,
        "unsupported state in %s: %d", conn.first.c_str(), int(bit.data));
    parent_label = bit.data == Yosys::State::S1 ? "VCC" : "GND";
  }
  // Child label is the connection id without the leading '\' - i.e. the connection name.
  // Don't include the offset if it's only a single bit.
  std::string child_label = conn.first.c_str() + 1;
  if (conn.second.size() > 1) child_label += std::to_string(offset);

  return ConnectionData{parent_label, child_label, bit};
}

std::vector<ConnectionData>
getConnectionsForSignal(const std::string& pin_spec, const Yosys::RTLIL::Cell& cell) {
  std::vector<ConnectionData> conn_data;
  // TODO: Support arbitrary constants?
  if (pin_spec == "1") {
    conn_data.push_back({"VCC", "VCC", {Yosys::State::S1}});
  } else if (pin_spec == "0") {
    conn_data.push_back({"GND", "GND", {Yosys::State::S0}});
  } else {
    // Collect module connections.
    auto conn_iter = cell.connections().find("\\" + pin_spec);
    verify_expr(conn_iter != cell.connections().end(),
        "invalid verilog signal '%s' in module %s'",
        pin_spec.c_str(), cell.name.c_str());
    Yosys::SigMap sigmap(cell.module);
    const auto& signal = sigmap(conn_iter->second);
    for (int i = 0; i < signal.size(); ++i)
      conn_data.push_back(makeConnectionData(*conn_iter, signal[i], i));
  }
  return conn_data;
}

}  // namespace

Mapper::Mapper(const std::string& memecad_json, const Lib& lib) : lib_(lib), schematic_(lib) {
  std::stringstream s(memecad_json);
  pt::read_json(s, root_);
}

void Mapper::addCell(const Yosys::RTLIL::Cell& cell) {
  // Cell type is either mapping a Kicad library component and it's in the map, or it's a parent
  // component.
  const auto* mapping = findMappingForCell(cell, root_);
  if (mapping) addLeafModule(cell, *mapping);
  else addNonLeafModule(cell);
}

void Mapper::addNonLeafModule(const Yosys::Cell& cell) {
  printf("Adding non-leaf module '%s'\n", modulePath(cell).c_str());
  ChildMapping child_mapping;
  for (const auto& conn : cell.connections()) {
    for (const auto& conn_data : getConnectionsForSignal(conn.first.c_str() + 1, cell)) {
      verify_expr(!child_mapping.count(conn_data.child_label),
          "duplicate mapping from child label '%s'", conn_data.child_label.c_str());
      child_mapping[conn_data.child_label] = conn_data;
      printf("  Mapping %s => %s\n", conn_data.child_label.c_str(), conn_data.parent_label.c_str());
    }
  }
  schematic_.addChildSheetToParent(moduleName(cell), child_mapping, moduleType(cell),
      parentModuleType(cell));
}

void Mapper::addLeafModule(const Yosys::RTLIL::Cell& cell, const pt::ptree& mapping) {
  printf("Adding leaf module '%s'\n", modulePath(cell).c_str());
  const std::string kicad_name = mapping.get<std::string>("kicad_name");
  auto& lib_component = lib_.findComponent(kicad_name);

  // Add labels for connecting each component.
  PinMapping pin_mapping;
  for (const auto& kv : mapping.get_child("verilog_to_kicad_map")) {
    const auto&[verilog_signal, child_tree] = kv;
    std::vector<std::string> kicad_signals;
    if (child_tree.empty())
      kicad_signals.push_back(child_tree.get_value<std::string>());
    for (const auto& kv2 : child_tree)
      kicad_signals.push_back(kv2.second.get_value<std::string>());

    const auto& conns = getConnectionsForSignal(verilog_signal, cell);
    for (const auto& kicad_signal : kicad_signals) {
      auto kicad_pins = parseKicadSignal(kicad_signal, lib_component);
      verify_expr(kicad_pins.size() == conns.size(),
          "bit-width of kicad signal '%s' does not match bit-width of verilog signal '%s'",
          kicad_signal.c_str(), verilog_signal.c_str());
      for (int i = 0; i < int(kicad_pins.size()); ++i) {
        pin_mapping[kicad_pins[i]] = conns[i];
        printf("  Mapping %s (pin %d) => %s => %s\n", kicad_pins[i]->name.c_str(),
            kicad_pins[i]->pin_number,
            conns[i].child_label.c_str(), conns[i].parent_label.c_str());
      }
    }
  }

  schematic_.addComponentToSheet(lib_component, pin_mapping, parentModuleType(cell));
}

}  // memecad
