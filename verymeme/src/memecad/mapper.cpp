#include "memecad/mapper.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>
#include <kernel/sigtools.h>
#include "memecad/parser.h"

namespace memecad {

namespace {

const pt::ptree& lookupMappingByCell(const Yosys::RTLIL::Cell& cell, const pt::ptree& root) {
  const std::string module_name = cell.type.c_str() + 1;
  for (const auto& kv : root) {
    const auto&[k, v] = kv;
    if (module_name == v.get<std::string>("verilog_name"))
      return v;
  }
  verify_expr(false, "cannot find map for verilog module '%s'", module_name.c_str());
}

bool is_integer(const std::string& s) {
  for (auto c : s)
    if (!isdigit(c)) return false;
  return true;
}

const lib_pin_t*
lookupPinByName(const std::string& pin_name, const lib_component_t& lib_component) {
  for (const auto& pin : lib_component.pins) {
    if (pin.name == pin_name)
      return &pin;
  }
  return nullptr;
}

const lib_pin_t* lookupPinByNumber(int pin_number, const lib_component_t& lib_component) {
  for (const auto& pin : lib_component.pins) {
    if (pin.pin_number == pin_number)
      return &pin;
  }
  return nullptr;
}

std::vector<const lib_pin_t*>
getPinRange(const std::string& range_spec, const lib_component_t& lib_component) {
  // Pin range specifier is either: a pin number; a pin name; a pin base name and integer range.
  // If a pin name does not exist, try to resolve it to a pin range. If both exist, default to
  // the single pin.
  // e.g. 1; OE; A[12:0]
  // Check for pin number.
  if (is_integer(range_spec)) {
    const auto* pin = lookupPinByNumber(boost::lexical_cast<int>(range_spec), lib_component);
    verify_expr(pin, "can't find pin with number %s", range_spec.c_str());
    return {pin};
  }

  // Check for explicit pin range.
  const std::regex split(R"(^([^\]])+\[(\d+):(\d+)]$)");
  std::smatch sm;
  if (std::regex_match(range_spec, sm, split)) {
    const std::string& pin_basename = sm[1];
    const int en = boost::lexical_cast<int>(sm[2]);
    const int st = boost::lexical_cast<int>(sm[3]);
    std::vector<const lib_pin_t*> pins;
    verify_expr(st <= en, "pin ranges (currently) must be specified from MSB to LSB");
    for (int i = en; i >= st; --i) {
      const std::string pin_name = pin_basename + std::to_string(i);
      const auto* pin = lookupPinByName(pin_name, lib_component);
      verify_expr(pin, "couldn't find pin with name '%s' in range spec", pin_name.c_str());
      pins.push_back(pin);
    }
    return pins;
  }

  // Check for singular pin.
  const auto* pin = lookupPinByName(range_spec, lib_component);
  if (!pin) {
    // Check for implicit pin range.
    int index = 0;
    std::vector<const lib_pin_t*> pins;
    while (true) {
      const std::string pin_name = range_spec + std::to_string(index);
      const auto* ranged_pin = lookupPinByName(pin_name, lib_component);
      if (!ranged_pin) break;
      pins.push_back(ranged_pin);
      index++;
    }
    verify_expr(!pins.empty(), "implicit pin range '%s' does not exist", range_spec.c_str());
    return reverse(std::move(pins));
  }
  verify_expr(pin,
      "pin range spec '%s' is neither pin number, valid pin name, valid pin range",
      range_spec.c_str());
  return {pin};
}

const std::vector<const lib_pin_t*>
parseKicadPinSpec(std::string pin_spec, const lib_component_t& lib_component) {
  // Pin spec consists of a comma separated list of pin range specifiers.
  std::string pin_range_spec;
  std::vector<const lib_pin_t*> pins;
  pin_spec += ',';  // Sentinel.
  for (auto c : pin_spec) {
    if (c == ',') {
      auto range_pins = getPinRange(pin_range_spec, lib_component);
      pins.insert(pins.end(), range_pins.begin(), range_pins.end());
      pin_range_spec.clear();
    } else {
      pin_range_spec += c;
    }
  }
  return pins;
}

}

Mapper::Mapper(const std::string& memecad_json, const lib_t& lib) : lib_(lib) {
  sheet_.id = 1;
  sheet_.title = "Test sheet";

  std::stringstream s(memecad_json);
  pt::read_json(s, root_);
}

void Mapper::writeHierarchy(const std::string& directory) {
  const std::string sheet_filename = directory + "/sheet.sch";
  writeFile(sheet_filename, writeSheet(sheet_), false /* binary */);
}

void Mapper::addComponentFromCell(const Yosys::RTLIL::Cell& cell) {
  // TODO: bin pack based on size of component
  // TODO: handle subcomponents
  const auto& map = lookupMappingByCell(cell, root_);
  const std::string kicad_name = map.get<std::string>("kicad_name");
  auto& lib_component = lib_.findComponent(kicad_name);
  verify_expr(2u == lib_component.fields.size(), "library component missing fields");

  // Add components to kicad sheet.
  for (int subcomponent = 1; subcomponent <= lib_component.unit_count; ++subcomponent) {
    sheet_component_t& component = sheet_.components.emplace_back();
    const auto& lib_ref_field = lib_component.fields[0];
    const auto& lib_name_field = lib_component.fields[1];

    component.name = lib_.name + ":" + lib_component.names.front();
    component.ref = lib_ref_field.text + "?";
    component.subcomponent = subcomponent;
    component.timestamp = "DEADBEEF";
    component.x = x_;
    component.y = y_ + subcomponent * 800;
    // F0: Reference, F1: Value, F2: Footprint, F3: Datasheet
    component.fields.push_back(
        field_t::fromLibraryField(lib_ref_field, 0, component.ref, component.x, component.y));
    component.fields.push_back(
        field_t::fromLibraryField(lib_name_field, 1, kicad_name, component.x, component.y));
  }

  // Add labels for connecting each component.
  for (const auto& kv : map.get_child("verilog_to_kicad_map")) {
    const auto&[verilog_range_spec, child_tree] = kv;
    printf("Looking at verilog range spec: %s\n", verilog_range_spec.c_str());

    std::vector<std::string> labels;
    if (verilog_range_spec == "1") {
      labels.emplace_back("VCC");
    } else if (verilog_range_spec == "0") {
      labels.emplace_back("GND");
    } else {
      // Collect module connections.
      auto conn_iter = cell.connections().find("\\" + verilog_range_spec);
      verify_expr(conn_iter != cell.connections().end(),
          "invalid verilog signal '%s' in module %s'",
          verilog_range_spec.c_str(), cell.name.c_str());
      Yosys::SigMap sigmap(cell.module);
      const auto& signal = sigmap(conn_iter->second);
      for (const auto& bit : signal.bits()) {
        verify_expr(bit.wire, "bit does not have associated wire");
        printf("BIT: %p %s %d\n", bit.wire, bit.wire->name.c_str(), bit.offset);
        labels.push_back(std::string(bit.wire->name.c_str() + 1) + std::to_string(bit.offset));
        printf("Adding name: %s\n", labels.back().c_str());
      }
    }

    std::vector<std::string> kicad_pin_specs;
    if (child_tree.empty()) {
      // Single pin spec.
      kicad_pin_specs.push_back(child_tree.get_value<std::string>());
    } else {
      // Array of pin specs.
      for (const auto& kv2 : child_tree)
        kicad_pin_specs.push_back(kv2.second.get_value<std::string>());
    }
    for (const auto& kicad_pin_spec : kicad_pin_specs) {
      printf("Extracting kicad pins for spec %s\n", kicad_pin_spec.c_str());
      auto kicad_pins = parseKicadPinSpec(kicad_pin_spec, lib_component);
      verify_expr(kicad_pins.size() == labels.size(),
          "bit-width of kicad range-spec '%s' does not match bit-width of verilog signal '%s'",
          kicad_pin_spec.c_str(), verilog_range_spec.c_str());
      for (int i = 0; i < int(kicad_pins.size()); ++i) {
        const auto& pin = *kicad_pins[i];
        printf("Kicad pin: %s %d\n", pin.name.c_str(), pin.pin_number);
        // TODO: Add label at pin.
        label_t& label = sheet_.labels.emplace_back();
        label.type = Label::LOCAL;
        label.x = x_ + pin.x;
        label.y = y_ + pin.subcomponent * 800 + pin.y;
        label.orientation = label_t::labelOrientationFromPinDirection(pin.direction);
        label.dimension = 50;
        label.text = labels[i];
      }
    }
  }

  x_ += 1000;
}

}  // memecad
