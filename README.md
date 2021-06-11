
# Building
## Dependencies
Also need:
Verilator, Yosys, Yices2, SymbiYosys

### Ubuntu
sudo apt install libsfml-dev extra-cmake-modules libboost-dev libboost-stacktrace-dev \
  build-essential clang bison flex libreadline-dev gawk tcl-dev libffi-dev git \
  graphviz xdot pkg-config python3 libboost-system-dev libboost-python-dev \
  libboost-filesystem-dev autoconf libboost-stacktrace-dev libboost-program-options-dev \
  gperf libgmp-dev cmake


### Arch
sudo pacman -S sfml extra-cmake-modules

# Memepu

TODO fill out.

## Verymeme

### Example commands:

#### memecad

#### memelang
memelang ./src/memepile/{integral,memory,pointer,stdintf,vector,string,token,main}.meme

### Running tests
Run run.py to run the tests for both SCHEMATIC and non-SCHEMATIC verilog
configurations.

### Adding new symbols
Process for adding a new leaf module for verymeme:
1. Decide which Kicad symbol to use. If it's a new symbol, add data to
   pcb/kicadtools/ and generate using that.
2. Write a verilog module corresponding to that symbol
3. Write a mapping in memecad_map.json for the verilog module and kicad symbol.
4. Add it as a verilator module in verymeme/verilog/CMakeLists.txt
5. Add it to the SymbiYosys file in verymeme/verilog/formally_verify.sby

### Fuzzing
Build with:

export PFX=./

cmake -DUSE_AFL=yes -DCMAKE_BUILD_TYPE=Release $PFX/verymeme
AFL_SKIP_CPUFREQ=yes AFL_PRELOAD=/usr/local/lib/afl/libdislocator.so \
  afl-fuzz -m 1024M -i $PFX/verymeme/test_data/memelang/parsing -o memelang_fuzz \
  -x $PFX/verymeme/assets/afl/memelang.dict -- ./memelang @@

Or for persistent mode:
cmake -DUSE_AFL=clang -DCMAKE_BUILD_TYPE=Release $PFX/verymeme

AFL_SKIP_CPUFREQ=yes AFL_PRELOAD=/usr/local/lib/afl/libdislocator.so \
  afl-fuzz -m 1024M -i $PFX/verymeme/test_data/memelang/parsing -o memelang_fuzz \
  -x $PFX/verymeme/assets/afl/memelang.dict -t 100 -- ./memelang
