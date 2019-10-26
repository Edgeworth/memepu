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
    desc.add_options()("help,h", "Help screen")("input,i", po::value<std::string>()->required())(
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

    input_filename = vm["input"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }
  memelang::FileContents cts(input_filename, readFile(input_filename));
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
}
