#include "verymeme/string_util.h"
#include "memecad/parser.h"
#include "memecad/schematic.h"
#include "verymeme/geom.h"
#include "verymeme/util.h"

namespace memecad {

namespace {

constexpr int PADDING = 500;
// Sizes for A3.
// TODO(improvement): Size schematic dynamically?
constexpr int SHEET_WIDTH = 14000;
constexpr int SHEET_HEIGHT = 8000;
constexpr int SHEET_MARGIN = 1000;

Sheet::Label createParentLabel(const Yosys::SigBit& bit) {
  Sheet::Label parent_label = {};
  const std::string label_text = getIdForSigBit(bit);

  // Unused signal, so place a no-connect.
  if (label_text.empty()) {
    parent_label.type = Sheet::Label::Type::NOCONNECT;
    return parent_label;
  }

  if (bit.wire && bit.wire->port_id != 0) {
    // Signal supplied from a higher up module.
    parent_label.type = Sheet::Label::Type::HIERARCHICAL;
    // TODO(improvement): check direction compared to kicad
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
  parent_label.text = label_text;
  return parent_label;
}

}  // namespace

Schematic::SheetData::SheetData() : cur({SHEET_MARGIN, SHEET_MARGIN}) {}

std::vector<Schematic::SchematicFile> Schematic::writeHierarchy() {
  std::vector<Schematic::SchematicFile> files;
  for (auto& kv : sheets_) {
    auto&[sheet_name, sheet_data] = kv;
    sheet_data.sheet.title = sheet_name;
    sheet_data.sheet.id = 1;  // TODO(improvement): sheet index.

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
  std::set<Sheet::Label> child_label_set;
  for (const auto& label : child.sheet.labels) {
    if (label.type == Sheet::Label::Type::HIERARCHICAL)
      child_label_set.insert(label);
  }
  std::vector<Sheet::Label> child_labels(child_label_set.begin(), child_label_set.end());
  verify_expr(child_labels.size() == mapping.size(),
      "number of hierarchical labels in child '%s' does not match number of verilog connections"
      " - maybe missing connection / unused",
      child_name.c_str());

  // Add hierarchical label for child sheet.
  int64_t pack_y = ref.p.y + 100;
  for (int i = 0; i < int(child_labels.size()); ++i) {
    if (i == int(child_labels.size() / 2))  // Place on other side.
      pack_y = ref.p.y + 100;
    const bool left = i < int(child_labels.size() / 2);

    Sheet::RefField& ref_field = ref.fields.emplace_back();
    ref_field.num = i + Sheet::RefField::HIERARCHICAL_REF_OFFSET;
    ref_field.text = child_labels[i].text;
    ref_field.type = netTypeToPinType(child_labels[i].net_type);
    ref_field.side = left ? Direction::RIGHT : Direction::LEFT;
    ref_field.p.x = left ? ref.p.x : (ref.p.x + ref.width);
    ref_field.p.y = pack_y;
    pack_y += ref_field.dimension * 2;
  }
  ref.height = int(pack_y) - ref.p.y;

  std::vector<Rect> aabbs;
  aabbs.push_back(
      {ref.p.x, ref.p.y, ref.p.x + ref.width, ref.p.y + ref.height});

  // Add label connecting to hierarchical label for parent sheet.
  std::vector<Sheet::Label> labels;
  for (int i = 0; i < int(child_labels.size()); ++i) {
    auto conn_iter = mapping.find(child_labels[i].text);
    verify_expr(conn_iter != mapping.end(),
        "BUG: should have association from child label '%s' to parent label",
        child_labels[i].text.c_str());
    Sheet::Label& parent_label = labels.emplace_back(
        createParentLabel(conn_iter->second.bit));
    parent_label.connectToRefField(ref.fields[i]);
    aabbs.push_back(parent_label.getBoundingBox());
  }

  // Pack child sheet and offset accordingly.
  // TODO(improvement): Dynamically size width for child sheets.
  Point offset = parent.packBoxesOffset(aabbs);
  ref.offset(offset);
  for (auto& label : labels) {
    label.p += offset;
    parent.sheet.labels.push_back(label);
  }
}

void
Schematic::addComponentToSheet(const std::string& lib_name, const Lib::Component& lib_component,
    const PinMapping& mapping, const std::string& sheet_name) {
  verify_expr(2u == lib_component.fields.size(), "library component missing fields");

  // Add components.
  std::vector<Sheet::Component> subcomponents;
  for (int subcomponent = 0; subcomponent < lib_component.unit_count; ++subcomponent) {
    auto& component = subcomponents.emplace_back();
    const auto& lib_ref_field = lib_component.fields[0];

    component.name = lib_name + ":" + lib_component.names.front();
    component.ref = lib_ref_field.text + "?";
    component.subcomponent = subcomponent;
    // F0: Reference, F1: Value, F2: Footprint, F3: Datasheet
    component.addLibField(lib_ref_field, component.ref);
    component.addLibField(lib_component.fields[1], lib_component.names.front());
  }

  // Compute box size contribution from components:
  auto& data = sheets_[sheet_name];
  std::vector<Rect> aabbs;
  int y = 0;
  for (auto& component : subcomponents) {
    // Get relative positions correct.
    Rect aabb = lib_component.getBoundingBox(component.subcomponent);
    Point offset = {0, y - aabb.top};
    aabb.offset(offset);
    component.offset(offset);
    y += aabb.height();
    aabbs.push_back(aabb);
  }

  // Place labels relative to subcomponents and collect sizing data.
  std::vector<Sheet::Label> labels;
  for (const auto& kv : mapping) {
    const auto&[kicad_pin, conn] = kv;
    auto& label = labels.emplace_back(createParentLabel(conn.bit));
    label.connectToPin(*kicad_pin);

    // Move to location we placed this subcomponent.
    verify_expr(kicad_pin->subcomponent >= 0 && kicad_pin->subcomponent < int(subcomponents.size()),
        "subcomponent %d is out of range, only have %d subcomponents", kicad_pin->subcomponent,
        int(subcomponents.size()));
    label.p += subcomponents[kicad_pin->subcomponent].p;
    aabbs.push_back(label.getBoundingBox());
  }

  // Place component based on packing:
  Point offset = data.packBoxesOffset(aabbs);
  for (auto& component : subcomponents) {
    component.offset(offset);
    data.sheet.components.push_back(component);
  }

  // Add finished labels to sheet:
  for (auto& label : labels) {
    label.p += offset;
    data.sheet.labels.push_back(label);
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
    std::vector<Sheet::Wire> wires;
    int height = 0;
    for (int i = 0; i < sig.first.size(); ++i) {
      auto label0 = createParentLabel(sig0_bits[i]);
      auto label1 = createParentLabel(sig1_bits[i]);
      // One of these being a no-connect means that it will have already been put on the appropriate
      // component, and connecting no-connect to the default 0 (GND) value will cause ERC errors.
      if ((label0.type == Sheet::Label::Type::NOCONNECT && !sig1_bits[i].wire) ||
          (label1.type == Sheet::Label::Type::NOCONNECT && !sig0_bits[i].wire))
        continue;

      auto& wire = wires.emplace_back();

      // Add a wire between these two labels otherwise Kicad won't consider them connected for ERC.
      label0.p.y += height;
      label0.direction = Direction::LEFT;
      wire.start = label0.p;

      label1.p += {label0.dimension, height};
      label1.direction = Direction::RIGHT;
      wire.end = label1.p;

      height += std::max(label0.dimension, label1.dimension) * 2;
      labels.push_back(label0);
      labels.push_back(label1);
      printf("  Connecting (%s of type %s) => (%s of type %s)\n",
          label0.text.c_str(), tos(label0.type).c_str(),
          label1.text.c_str(), tos(label1.type).c_str());
    }
    if (labels.empty()) continue;

    // TODO(improvement): Compute actual width.
    Point offset = data.packBox({500, height});
    for (auto& label : labels) {
      label.p += offset;
      data.sheet.labels.push_back(label);
    }
    for (auto& wire : wires) {
      wire.start += offset;
      wire.end += offset;
      data.sheet.wires.push_back(wire);
    }
  }
}

Point Schematic::SheetData::packBox(Point box_size) {
  // Finished this line, start a new line.
  if (cur.x > SHEET_MARGIN + SHEET_WIDTH) {
    cur.x = SHEET_MARGIN;
    cur.y += max_y;
    // TODO(improvement): Dynamically size sheets.
    if (cur.y > SHEET_MARGIN + SHEET_HEIGHT)
      printf("WARNING: ran out of space on sheet");
    max_y = 0;
  }

  Point p = cur;
  cur.x += box_size.x + PADDING;
  max_y = std::max(max_y, box_size.y + PADDING);
  return p;
}

Point Schematic::SheetData::packBoxesOffset(const std::vector<Rect>& rects) {
  Rect r;
  for (const auto& rect : rects)
    r.unionRect(rect);
  const Point loc = packBox({r.width(), r.height()});
  return loc - r.origin();
}


}  // memecad
