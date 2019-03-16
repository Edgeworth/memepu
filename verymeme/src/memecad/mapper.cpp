#include "memecad/mapper.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "memecad/parser.h"

namespace memecad {

namespace pt = boost::property_tree;

Mapper::Mapper(const std::string& data, lib_t& lib) : lib_(lib) {
  pt::ptree ptree;
  std::stringstream s(data);
  pt::read_json(s, ptree);
  for (const auto& kv : ptree) {
    const auto&[k, v] = kv;
    const std::string& kicad_name = v.get<std::string>("kicad_name");
//    printf("Component: %s\n", lib.findComponent(kicad_name).toString().c_str());
  }
}

std::string Mapper::mapComponents() {
  sheet_.id = 1;
  sheet_.title = "Test sheet";
  addComponent("628128_TSOP32");
  return writeSheet(sheet_);
}

void Mapper::addComponent(const std::string& kicad_name) {
  sheet_component_t component = {};
  auto& lib_component = lib_.findComponent(kicad_name);
  verify_expr(2u == lib_component.fields.size(), "library component missing fields");
  const auto& lib_ref_field = lib_component.fields[0];
  const auto& lib_name_field = lib_component.fields[1];

  component.name = lib_.name + ":" + lib_component.names.front();
  component.ref = lib_ref_field.text + "?";
  component.subcomponent = 1;
  component.timestamp = "5C5E9E2A";
  // TODO need offset for field position? in wrong place?
  component.x = 1000;
  component.y = 1000;
  // F0: Reference, F1: Value, F2: Footprint, F3: Datasheet
  component.fields.push_back(field_t::fromLibraryField(lib_ref_field, 0, component.ref, component.x, component.y));
  component.fields.push_back(field_t::fromLibraryField(lib_name_field, 1, kicad_name, component.x, component.y));
  sheet_.components.push_back(component);
}

}  // memecad
