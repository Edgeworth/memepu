#include "common.h"
#include "control.h"
#include "mlu.h"

int main(int argc, char *argv[]) {

  for (int i = 0; i < 3; ++i) {
    ControlLogic logic(i);
    std::string filename = std::string("out") + char('0' + i) + ".bin";
    writeFile(filename, logic.getBinaryData());
  }

  MLU mlu;
  writeFile("mlu.bin", mlu.getBinaryData());
}
