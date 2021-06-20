// Copyright 2019 E.
#include <iostream>

#include "boost/program_options.hpp"
#include "memelang/exec.h"
#include "memelang/parser.h"
#include "verymeme/file.h"
#include "verymeme/macros.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::vector<std::string> input_filenames;
  bool print_tokens = false;
  bool print_ast = false;
  bool no_exec = false;
  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")(
        "input,i", po::value<std::vector<std::string>>()->multitoken())("tokens,t",
        po::bool_switch(&print_tokens))("ast,a", po::bool_switch(&print_ast))("no-exec,n",
        po::bool_switch(&no_exec));

    po::positional_options_description p;
    p.add("input", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);

    if (vm.count("input")) input_filenames = vm["input"].as<std::vector<std::string>>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  std::vector<std::unique_ptr<memelang::FileContents>> file_cts;
#ifdef __AFL_HAVE_MANUAL_CONTROL
  __AFL_INIT();
  constexpr int AFL_BUF_SIZE = 1024 * 4;  // 4 KB
  char afl_buf[AFL_BUF_SIZE];
  while (__AFL_LOOP(1000)) {
    memset(afl_buf, 0, AFL_BUF_SIZE);
    auto bytes = read(0, afl_buf, AFL_BUF_SIZE);
    if (bytes < 0) continue;
    std::string data(afl_buf, bytes);
    file_cts.clear();
    file_cts.emplace_back(std::make_unique<memelang::FileContents>("stdin", data));
#else
  // TODO: Read from stdin if no input filename.
  for (const auto& filename : input_filenames)
    file_cts.emplace_back(std::make_unique<memelang::FileContents>(filename, readFile(filename)));
#endif
    memelang::ast::Parser parser(file_cts);
    parser.parse();

    if (print_tokens) {
      for (const auto& ctx : parser.ctxs()) {
        printf("Tokens for %s\n", ctx->cts->filename().c_str());
        for (const auto& tok : ctx->tokens()) printf("%s\n", tok.desc().c_str());
      }
    }

    if (print_ast) printf("AST:\n%s\n", parser.astToString().c_str());

    if (!no_exec) {
      memelang::exec::Exec interp(parser.module());
      interp.run();
    }
#ifdef __AFL_HAVE_MANUAL_CONTROL
  }
#endif
}
