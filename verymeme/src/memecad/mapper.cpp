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
  component.name = lib_.name + ":" + lib_component.names.front();
  component.ref = "U?";
  component.subcomponent = 1;
  component.timestamp = "5C5E9E2A";
  component.x = 1000;
  component.y = 1000;
  // F0: Reference, F1: Value, F2: Footprint, F3: Datasheet
  field_t f0 = {};
  f0.num = 0;
  f0.text = "U?";
  f0.x = 2000;
  f0.y = 2000;
  component.fields.push_back(f0);
  field_t f1 = {};
  f1.num = 1;
  f1.text = kicad_name;
  f1.x = 3000;
  f1.y = 3000;
  component.fields.push_back(f1);
  sheet_.components.push_back(component);
}

}  // memecad
