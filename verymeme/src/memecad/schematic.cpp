
#include <memecad/schematic.h>
#include <boost/lexical_cast.hpp>

#include "memecad/parser.h"

namespace memecad {

namespace {

constexpr int PADDING = 500;
// Sizes for A3. TODO: Size schematic dynamically?
constexpr int SHEET_WIDTH = 14000;
constexpr int SHEET_HEIGHT = 8000;
constexpr int SHEET_MARGIN = 1000;

Sheet::Label createParentLabel(const Yosys::SigBit& bit) {
  Sheet::Label parent_label = {};
  if (bit.wire && bit.wire->port_id != 0) {
    // Signal supplied from a higher up module.
    parent_label.type = Sheet::Label::Type::HIERARCHICAL;
    // TODO: check direction compared to kicad
    parent_label.net_type = bit.wire->port_input ? Sheet::Label::NetType::INPUT
                                                 : Sheet::Label::NetType::OUTPUT;
  } else if (bit.wire) {
    // Signal supplied from within this module.
    parent_label.type = Sheet::Label::Type::LOCAL;
  } else {
    // Otherwise assume it's VCC, GND, or something like that.
    parent_label.type = Sheet::Label::Type::GLOBAL;
    parent_label.net_type = Sheet::Label::NetType::PASSIVE;
  }
  parent_label.text = getIdForSigBit(bit);
  return parent_label;
}

}  // namespace

Schematic::SheetData::SheetData() : cur({SHEET_MARGIN, SHEET_MARGIN}) {}

std::vector<Schematic::SchematicFile> Schematic::writeHierarchy() {
  std::vector<Schematic::SchematicFile> files;
  for (auto& kv : sheets_) {
    auto&[sheet_name, sheet_data] = kv;
    sheet_data.sheet.title = sheet_name;
    sheet_data.sheet.id = 1;  // TODO sheet index.

    files.push_back({sheet_name + ".sch", writeSheet(sheet_data.sheet)});
  }
  return files;
}

void Schematic::addChildSheetToParent(const std::string& title, const ChildMapping& mapping,
    const std::string& child_name, const std::string& parent_name) {
  auto& parent = sheets_[parent_name];
  auto& ref = parent.sheet.refs.emplace_back();
  ref.name = title;
  ref.filename = child_name + ".sch";

  // Plumb up hierarchical labels for this module to the parent:
  verify_expr(sheets_.count(child_name), "could not find child '%s' - maybe missing file",
      child_name.c_str());
  auto& child = sheets_[child_name];
  std::set<Sheet::Label> label_set;
  for (const auto& label : child.sheet.labels) {
    if (label.type == Sheet::Label::Type::HIERARCHICAL)
      label_set.insert(label);
  }
  std::vector<Sheet::Label> labels(label_set.begin(), label_set.end());

  verify_expr(labels.size() == mapping.size(),
      "number of hierarchical labels in child '%s' does not match number of verilog connections"
      " - maybe missing connection / unused",
      child_name.c_str());

  // Add hierarchical label for child sheet.
  int pack_y = ref.y + 100;
  for (int i = 0; i < int(labels.size()); ++i) {
    if (i == int(labels.size() / 2))  // Place on other side.
      pack_y = ref.y + 100;
    const bool left = i < int(labels.size() / 2);

    Sheet::RefField& ref_field = ref.fields.emplace_back();
    ref_field.num = i + Sheet::RefField::HIERARCHICAL_REF_OFFSET;
    ref_field.text = labels[i].text;
    ref_field.type = netTypeToPinType(labels[i].net_type);
    ref_field.side = left ? Direction::RIGHT : Direction::LEFT;
    ref_field.x = left ? ref.x : (ref.x + ref.width);
    ref_field.y = pack_y;
    pack_y += ref_field.dimension * 2;
  }
  ref.height = pack_y - ref.y;

  // Pack child sheet.
  // TODO: Dynamically size width for child sheets.
  Point loc = parent.packBox({ref.width + PADDING, ref.height + PADDING});
  ref.offsetTo(loc);

  // Add label connecting to hierarchical label for parent sheet. Do this after deciding the final
  // location of the child sheet in the parent sheet.
  for (int i = 0; i < int(labels.size()); ++i) {
    auto conn_iter = mapping.find(labels[i].text);
    verify_expr(conn_iter != mapping.end(),
        "BUG: should have association from child label '%s' to parent label",
        labels[i].text.c_str());
    Sheet::Label& parent_label = parent.sheet.labels.emplace_back(
        createParentLabel(conn_iter->second.bit));
    parent_label.connectToRefField(ref.fields[i]);
  }
}

void Schematic::addComponentToSheet(const Lib::Component& lib_component, const PinMapping& mapping,
    const std::string& sheet_name) {
  verify_expr(2u == lib_component.fields.size(), "library component missing fields");

  // Add components.
  std::vector<Sheet::Component> subcomponents;
  for (int subcomponent = 0; subcomponent < lib_component.unit_count; ++subcomponent) {
    auto& component = subcomponents.emplace_back();
    const auto& lib_ref_field = lib_component.fields[0];

    // TODO: Assumes lib_component comes from lib_.
    component.name = lib_.name + ":" + lib_component.names.front();
    component.ref = lib_ref_field.text + "?";
    component.subcomponent = subcomponent;
    // F0: Reference, F1: Value, F2: Footprint, F3: Datasheet
    component.addLibField(lib_ref_field, component.ref);
    component.addLibField(lib_component.fields[1], lib_component.names.front());
  }

  // Add finished components to sheet:
  auto& data = sheets_[sheet_name];
  int max_width = 0;
  int y = 0;
  for (auto& component : subcomponents) {
    Rect aabb = lib_component.getBoundingBox(component.subcomponent);
    // Get relative positions correct.
    component.offset({-aabb.left, y - aabb.top});
    y += aabb.height();
    max_width = std::max(max_width, aabb.width());
  }

  Point loc = data.packBox({max_width, y});
  for (auto& component : subcomponents) {
    component.offset(loc);
    data.sheet.components.push_back(component);
  }

  // Add finished labels to sheet:
  for (const auto& kv : mapping) {
    const auto&[kicad_pin, conn] = kv;

    auto& label = data.sheet.labels.emplace_back(createParentLabel(conn.bit));
    label.connectToPin(*kicad_pin);

    // Move to location we placed this subcomponent.
    label.x += subcomponents[kicad_pin->subcomponent].x;
    label.y += subcomponents[kicad_pin->subcomponent].y;
  }
}

void Schematic::addModuleConnectionsToSheet(const std::string& sheet_name,
    const std::vector<Yosys::SigSig>& sigs) {
  auto& data = sheets_[sheet_name];
  for (const auto& sig : sigs) {
    verify_expr(sig.first.size() == sig.second.size(),
        "signal signal connection does not have equal sizes: %s : %s", Yosys::log_signal(sig.first),
        Yosys::log_signal(sig.second));
    const auto& sig0_bits = sig.first.bits();
    const auto& sig1_bits = sig.second.bits();
    std::vector<Sheet::Label> labels;
    int height = 0;
    for (int i = 0; i < sig.first.size(); ++i) {
      auto label0 = createParentLabel(sig0_bits[i]);
      auto label1 = createParentLabel(sig1_bits[i]);

      label0.y += height;
      label0.orientation = pinDirectionToLabelOrientation(Direction::LEFT, label0.type);
      label1.y += height;
      label1.orientation = pinDirectionToLabelOrientation(Direction::RIGHT, label1.type);

      height += std::max(label0.dimension, label1.dimension) * 2;
      labels.push_back(label0);
      labels.push_back(label1);
      printf("  Connecting %s of type %s => %s of type %s\n",
          label0.text.c_str(), boost::lexical_cast<std::string>(label0.type).c_str(),
          label1.text.c_str(), boost::lexical_cast<std::string>(label1.type).c_str());
    }
    // TODO: Compute actual width.
    Point offset = data.packBox({500, height});
    for (auto& label : labels) {
      label.x += offset.x;
      label.y += offset.y;
      data.sheet.labels.push_back(label);
    }
  }
}

Point Schematic::SheetData::packBox(Point box_size) {
  Point p = cur;
  cur.x += box_size.x + PADDING;

  // Finished this line, start a new line.
  if (cur.x > SHEET_MARGIN + SHEET_WIDTH) {
    cur.x = SHEET_MARGIN;
    cur.y += max_y;
    verify_expr(cur.y < SHEET_MARGIN + SHEET_HEIGHT, "ran out of space on sheet");
    max_y = 0;
    p = cur;
  }

  max_y = std::max(max_y, box_size.y + PADDING);
  return p;
}


}  // memecad
