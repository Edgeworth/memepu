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

bool isInteger(const std::string& s) {
  for (auto c : s)
    if (!isdigit(c)) return false;
  return true;
}

const Lib::Pin*
lookupPinByName(const std::string& pin_name, const Lib::Component& lib_component) {
  for (const auto& pin : lib_component.pins) {
    if (pin.name == pin_name)
      return &pin;
  }
  return nullptr;
}

const Lib::Pin* lookupPinByNumber(int pin_number, const Lib::Component& lib_component) {
  for (const auto& pin : lib_component.pins) {
    if (pin.pin_number == pin_number)
      return &pin;
  }
  return nullptr;
}

std::vector<const Lib::Pin*>
parseKicadPinSpec(const std::string& pin_spec, const Lib::Component& lib_component) {
  // Pin specifier is either: a pin number; a pin name; a pin base name and integer range.
  // If a pin name does not exist, try to resolve it to a pin range. If both exist, default to
  // the single pin.
  // e.g. 1; OE; A[12:0]
  // Check for pin number.
  if (isInteger(pin_spec)) {
    const auto* pin = lookupPinByNumber(boost::lexical_cast<int>(pin_spec), lib_component);
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
      const auto* pin = lookupPinByName(pin_name, lib_component);
      verify_expr(pin, "couldn't find pin with name '%s' in pin spec", pin_name.c_str());
      pins.push_back(pin);
    }
    return pins;
  }

  // Check for singular pin.
  const auto* pin = lookupPinByName(pin_spec, lib_component);
  if (!pin) {
    // Check for implicit pins.
    int index = 0;
    std::vector<const Lib::Pin*> pins;
    while (true) {
      const std::string pin_name = pin_spec + std::to_string(index);
      const auto* ranged_pin = lookupPinByName(pin_name, lib_component);
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
parseKicadPinSpecs(std::string pin_specs, const Lib::Component& lib_component) {
  // Pin spec consists of a comma separated list of pin specs.
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

std::vector<std::string>
parseVerilogPinSpec(const std::string& pin_spec, const Yosys::RTLIL::Cell& cell) {
  std::vector<std::string> labels;
  if (pin_spec == "1") {
    labels.emplace_back("VCC");
  } else if (pin_spec == "0") {
    labels.emplace_back("GND");
  } else {
    // Collect module connections.
    auto conn_iter = cell.connections().find("\\" + pin_spec);
    verify_expr(conn_iter != cell.connections().end(),
        "invalid verilog signal '%s' in module %s'",
        pin_spec.c_str(), cell.name.c_str());
    Yosys::SigMap sigmap(cell.module);
    const auto& signal = sigmap(conn_iter->second);
    for (const auto& bit : signal.bits()) {
      verify_expr(bit.wire, "bit does not have associated wire");
      labels.push_back(std::string(bit.wire->name.c_str() + 1) + std::to_string(bit.offset));
    }
  }
  return labels;
}

Rect getLibraryComponentBounds(const Lib::Component& lib_component, int subcomponent) {
  Rect bounds;
  for (const auto& pin : lib_component.pins) {
    if (pin.subcomponent != subcomponent) continue;
    bounds.left = std::min(bounds.left, pin.x);
    bounds.right = std::max(bounds.right, pin.x);
    bounds.top = std::min(bounds.top, pin.y);
    bounds.bottom = std::max(bounds.bottom, pin.y);
  }
  bounds.inset(-200, -200);
  return bounds;
}

}

Mapper::Mapper(const std::string& memecad_json, const Lib& lib) : lib_(lib) {
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
  const auto& map = lookupMappingByCell(cell, root_);
  const std::string kicad_name = map.get<std::string>("kicad_name");
  auto& lib_component = lib_.findComponent(kicad_name);
  verify_expr(2u == lib_component.fields.size(), "library component missing fields");

  // Add components to kicad sheet.
  std::vector<Sheet::Component> subcomponents;
  for (int subcomponent = 0; subcomponent < lib_component.unit_count; ++subcomponent) {
    auto& component = subcomponents.emplace_back();
    const auto& lib_ref_field = lib_component.fields[0];

    component.name = lib_.name + ":" + lib_component.names.front();
    component.ref = lib_ref_field.text + "?";
    component.subcomponent = subcomponent;
    component.timestamp = "DEADBEEF";
    // F0: Reference, F1: Value, F2: Footprint, F3: Datasheet
    component.addLibField(lib_ref_field, component.ref);
    component.addLibField(lib_component.fields[1], kicad_name);
  }

  // Add labels for connecting each component.
  std::multimap<int, Sheet::Label> component_labels;
  for (const auto& kv : map.get_child("verilog_to_kicad_map")) {
    const auto&[verilog_pin_spec, child_tree] = kv;
    std::vector<std::string> labels = parseVerilogPinSpec(verilog_pin_spec, cell);
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
      auto kicad_pins = parseKicadPinSpecs(kicad_pin_spec, lib_component);
      verify_expr(kicad_pins.size() == labels.size(),
          "bit-width of kicad pin-spec '%s' does not match bit-width of verilog signal '%s'",
          kicad_pin_spec.c_str(), verilog_pin_spec.c_str());
      for (int i = 0; i < int(kicad_pins.size()); ++i) {
        const auto& pin = *kicad_pins[i];
        auto& label = component_labels.emplace(pin.subcomponent, Sheet::Label())->second;
        label.type = Sheet::Label::Type::LOCAL;  // TODO decide if hierarchical or local label.
        label.x = pin.x;
        label.y = pin.y;
        label.orientation = Sheet::Label::labelOrientationFromPinDirection(pin.direction);
        label.text = labels[i];
      }
    }
  }

  // Add finished components to sheet:
  int next_x = x_;
  y_ = 1000;
  for (auto& component : subcomponents) {
    Rect aabb = getLibraryComponentBounds(lib_component, component.subcomponent);
    component.offset(x_ - aabb.left, y_ - aabb.top);
    y_ += aabb.height();
    next_x = std::max(next_x, x_ + aabb.width());
    sheet_.components.push_back(component);
  }
  x_ = next_x + 500;

  // Add finished labels to sheet:
  for (auto& kv : component_labels) {
    auto& [subcomponent, label] = kv;
    label.x += subcomponents[subcomponent].x;
    label.y += subcomponents[subcomponent].y;
    sheet_.labels.push_back(label);
  }
}

}  // memecad
