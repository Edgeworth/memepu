#include <boost/program_options.hpp>
#include <iostream>

#include "memelang/exec.h"
#include "memelang/parser.h"
#include "verymeme/file.h"
#include "verymeme/macros.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::string input_filename;
  bool print_tokens = false;
  bool print_ast = false;
  bool no_exec = false;
  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")("input,i", po::value<std::string>())(
        "tokens,t", po::bool_switch(&print_tokens))("ast,a", po::bool_switch(&print_ast))(
        "no-exec,n", po::bool_switch(&no_exec));

    po::positional_options_description p;
    p.add("input", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);

    if (vm.count("input")) input_filename = vm["input"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

#ifdef __AFL_HAVE_MANUAL_CONTROL
  __AFL_INIT();
  constexpr int AFL_BUF_SIZE = 1024 * 4;  // 4 KB
  char afl_buf[AFL_BUF_SIZE];
  while (__AFL_LOOP(1000)) {
    memset(afl_buf, 0, AFL_BUF_SIZE);
    auto bytes = read(0, afl_buf, AFL_BUF_SIZE);
    if (bytes < 0) continue;
    std::string data(afl_buf, bytes);
    memelang::FileContents cts("stdin", data);
#else
  // TODO: Read from stdin if no input filename.
  memelang::FileContents cts(input_filename, readFile(input_filename));
#endif
    memelang::ast::Tokeniser tokeniser(&cts);
    auto tokens = tokeniser.tokenise();

    if (print_tokens)
      for (const auto& tok : tokens) printf("%s\n", tok.desc(&cts).c_str());

    memelang::ast::Parser parser(&cts, tokens);
    parser.parse();
    if (print_ast) printf("AST:\n%s\n", parser.astToString().c_str());

    if (!no_exec) {
      memelang::exec::Exec interp(parser.file(), &cts);
      interp.run();
    }
#ifdef __AFL_HAVE_MANUAL_CONTROL
  }
#endif
}
