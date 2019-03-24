#include "memecad/mapper.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>
#include <kernel/sigtools.h>

#include "memecad/parser.h"
#include "memecad/util.h"

namespace memecad {

namespace {

constexpr int PADDING = 500;

const pt::ptree& lookupMappingByCell(const Yosys::RTLIL::Cell& cell, const pt::ptree& root) {
  const std::string module_type = moduleType(cell);
  for (const auto& kv : root) {
    const auto&[k, v] = kv;
    if (module_type == v.get<std::string>("verilog_name"))
      return v;
  }
  verify_expr(false, "cannot find map for verilog module '%s'", module_type.c_str());
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

// Describes the connection between a child and parent. A child is either a child sheet or a leaf
// kicad component. A parent is a sheet. For leaf kicad components, child labels are mapped to
// pins in the kicad component via a mapping file.
struct ConnectionData {
  // TODO: Support VCC/GND for parent_label properly.
  std::string parent_label;
  std::string child_label;
  const Yosys::RTLIL::SigBit sigbit;
};

ConnectionData
makeConnectionData(const std::pair<Yosys::IdString, Yosys::SigSpec>& conn,
    const Yosys::SigBit& bit) {
  // Parent label is where the connection goes to.
  std::string parent_label;
  printf("Conn id: %s, wire name: %s\n", conn.first.c_str(),
      (bit.wire ? bit.wire->name.c_str() : "null"));
  if (bit.wire) {
    parent_label = std::string(bit.wire->name.c_str() + 1);
    if (bit.wire->width > 1) parent_label += std::to_string(bit.offset);
  } else {
    verify_expr(bit.data == Yosys::State::S0 || bit.data == Yosys::State::S1,
        "unsupported state in %s: %d", conn.first.c_str(), int(bit.data));
    parent_label = bit.data == Yosys::State::S1 ? "VCC" : "GND";
  }
  // Child label is the connection id without the leading '\' - i.e. the connection name.
  // Don't include the offset if it's only a single bit.
  std::string child_label = conn.first.c_str() + 1;
  if (bit.wire && bit.wire->width > 1) {
    printf("BIT WIDTH FOR CHILD LABEL: %d\n", bit.wire->width);
    child_label += std::to_string(bit.offset);
  }

  return ConnectionData{parent_label, child_label, bit};
}

std::vector<ConnectionData>
parseVerilogPinSpec(const std::string& pin_spec, const Yosys::RTLIL::Cell& cell) {
  std::vector<ConnectionData> conn_data;
  // TODO: handle case of no wire for signal, just connected to value
  // TODO: generalise VCC and GND below to use that system.
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
    for (const auto& bit : signal.bits())
      conn_data.push_back(makeConnectionData(*conn_iter, bit));
  }
  return conn_data;
}

}  // namespace

Mapper::Mapper(const std::string& memecad_json, const Lib& lib) : lib_(lib) {
  std::stringstream s(memecad_json);
  pt::read_json(s, root_);
}

void Mapper::writeHierarchy(const std::string& directory) {
  // TODO: Add logging for each operation, print out e.g. module name (type) -> module name (type) -> ... for each
  for (auto& kv : modules_) {
    auto&[sheet_name, sheet_data] = kv;
    const std::string sheet_filename = directory + "/" + sheet_name + ".sch";
    sheet_data.sheet.title = sheet_name;
    sheet_data.sheet.id = 1;  // TODO sheet index.

    writeFile(sheet_filename, writeSheet(sheet_data.sheet), false /* binary */);
  }
}

void Mapper::addCell(const Yosys::RTLIL::Cell& cell) {
  // Cell type is either mapping a Kicad library component inside a hierarchical sheet, and
  // adding it will populate the parent in |modules_|, or it's a parent.
  auto iter = modules_.find(moduleType(cell));
  if (iter == modules_.end()) addLeafModule(cell);
  else addNonLeafModule(cell);
}
// TODO: Split mapping and kicad sheet etc handling into separate files?

void Mapper::addNonLeafModule(const Yosys::Cell& cell) {
  const std::string module_type = moduleType(cell);
  const std::string module_name = moduleName(cell);
  printf("Adding non-leaf module '%s' of type '%s'\n", module_name.c_str(), module_type.c_str());
  auto& parent = modules_[parentModuleType(cell)];
  auto& ref = parent.sheet.refs.emplace_back();
  ref.name = module_name;
  ref.filename = module_type + ".sch";
  ref.x = parent.pack_x;
  ref.y = parent.pack_y;
  parent.pack_x += ref.width + PADDING;

  // TODO: Need to be able to connect labels onto hierarchical labels
  std::unordered_map<std::string, std::string> child_to_parent_label;
  for (const auto& conn : cell.connections()) {
    const auto& conn_id = conn.first;
    // Grab sigbits.
    // TODO: something better than +1 for each of these.
    for (const auto& conn_data : parseVerilogPinSpec(conn_id.c_str() + 1, cell))
      child_to_parent_label[conn_data.child_label] = conn_data.parent_label;
  }

  verify_expr(modules_.count(module_type), "could not find child '%s'", module_type.c_str());
  auto& sheet = modules_[module_type].sheet;

  // Plumb up hierarchical labels for this module to the parent:
  std::set<Sheet::Label> hierarchical_labels;
  for (const auto& label : sheet.labels)
    if (label.type == Sheet::Label::Type::HIERARCHICAL)
      hierarchical_labels.insert(label);

  int pack_y = ref.y + 100;
  int idx = 0;
  for (const auto& label : hierarchical_labels) {
    if (idx == int(hierarchical_labels.size() / 2))  // Place on other side.
      pack_y = ref.y + 100;
    const bool left = idx < int(hierarchical_labels.size() / 2);

    // Add hierarchical label for child sheet.
    Sheet::RefField& ref_field = ref.fields.emplace_back();
    ref_field.num = idx + Sheet::RefField::HIERARCHICAL_REF_OFFSET;
    ref_field.text = label.text;
    ref_field.type = netTypeToPinType(label.net_type);
    ref_field.side = left ? Direction::RIGHT : Direction::LEFT;
    ref_field.x = left ? ref.x : (ref.x + ref.width);
    ref_field.y = pack_y;
    pack_y += ref_field.dimension * 2;
    idx++;

    // Add label connecting to hierarchical label for parent sheet.
    printf("Looking for child label: %s\n", label.text.c_str());
    verify_expr(child_to_parent_label.count(label.text),
        "BUG: should have association from child label '%s' to parent label", label.text.c_str());
    Sheet::Label& parent_label = parent.sheet.labels.emplace_back();
    parent_label.connectToRefField(ref_field);
    parent_label.type = Sheet::Label::Type::LOCAL;  // TODO may need to plumb up further with hierarchical.
    parent_label.text = child_to_parent_label[label.text];
  }
  ref.height = pack_y - ref.y;
}

void Mapper::addLeafModule(const Yosys::RTLIL::Cell& cell) {
  printf("Adding leaf module '%s' with type '%s'\n", moduleName(cell).c_str(),
      moduleType(cell).c_str());
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
    // F0: Reference, F1: Value, F2: Footprint, F3: Datasheet
    component.addLibField(lib_ref_field, component.ref);
    component.addLibField(lib_component.fields[1], kicad_name);
  }

  // Add labels for connecting each component.
  std::multimap<int, Sheet::Label> component_labels;
  for (const auto& kv : map.get_child("verilog_to_kicad_map")) {
    const auto&[verilog_pin_spec, child_tree] = kv;
    auto conn_data = parseVerilogPinSpec(verilog_pin_spec, cell);

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
      verify_expr(kicad_pins.size() == conn_data.size(),
          "bit-width of kicad pin-spec '%s' does not match bit-width of verilog signal '%s'",
          kicad_pin_spec.c_str(), verilog_pin_spec.c_str());
      for (int i = 0; i < int(kicad_pins.size()); ++i) {
        const auto& kicad_pin = *kicad_pins[i];
        const auto& verilog_bit = conn_data[i].sigbit;
        auto& label = component_labels.emplace(kicad_pin.subcomponent, Sheet::Label())->second;
        if (verilog_bit.wire && verilog_bit.wire->port_id != 0) {
          label.type = Sheet::Label::Type::HIERARCHICAL;
          // TODO: check direction compared to kicad
          label.net_type = verilog_bit.wire->port_input ? Sheet::Label::NetType::INPUT
                                                        : Sheet::Label::NetType::OUTPUT;
        } else {
          label.type = Sheet::Label::Type::LOCAL;
        }
        label.connectToPin(kicad_pin);
        label.text = conn_data[i].parent_label;
      }
    }
  }

  // Add finished components to sheet:
  auto& data = modules_[parentModuleType(cell)];
  int next_x = data.pack_x;
  int y = data.pack_y;
  for (auto& component : subcomponents) {
    Rect aabb = lib_component.getBoundingBox(component.subcomponent);
    component.offset(data.pack_x - aabb.left, y - aabb.top);
    y += aabb.height();
    next_x = std::max(next_x, data.pack_x + aabb.width());
    data.sheet.components.push_back(component);
  }
  data.pack_x = next_x + PADDING;

  // Add finished labels to sheet:
  for (auto& kv : component_labels) {
    auto&[subcomponent, label] = kv;
    label.x += subcomponents[subcomponent].x;
    label.y += subcomponents[subcomponent].y;
    data.sheet.labels.push_back(label);
  }
}

}  // memecad
