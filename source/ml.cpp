#if 0
python gen_parser.py

# === gcc ===
# g++ -std=c++11 -Wall -Wextra -pedantic -O0\
#     *.cpp -o ml_gcc $@ &&
# ./ml_gcc &&

# === clang libstdc++ ===
# clang++ -std=c++11 -stdlib=libstdc++ -Wall -Wextra -Wbind-to-temporary-copy -pedantic -fno-rtti -ferror-limit=1 -O0\
#     *.cpp -o ml_clang $@ &&
# ./ml_clang &&

# === clang libc++ ===
# clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -Wbind-to-temporary-copy -pedantic -fno-rtti -ferror-limit=1 -O0\
#     *.cpp -o ml_clang $@ &&
# ./ml_clang &&

# === with LLVM Generator ===
clang++ -std=c++11 -Wall -Wextra -Wbind-to-temporary-copy -pedantic -ferror-limit=1 -O0\
    -c ml.cpp -o ml.o $@ &&
clang++ -std=c++11 -Wall -Wbind-to-temporary-copy -pedantic -ferror-limit=1 -O0\
    LLVM-Simple-Wrapper/llvmgenerator.cpp ml.o\
    -lncurses `llvm-config --ldflags --system-libs`\
    `llvm-config --cxxflags --libs core support jit native`\
    -o ml_clang $@ &&
./ml_clang &&

# === ok ===
echo fin

exit

#endif

#include <iostream>
#include <fstream>
#include <streambuf>

#include "mylang.hpp"

using namespace mylang;
using namespace llvmgenerator;

int main(int argc, char **argv) {
    char *filename;

    if (argc > 1) {
        filename = argv[1];
    } else {
        char s1[] = "example.ml";
        filename = s1;
    }
    std::ifstream fs(filename);

    std::string input(
        (std::istreambuf_iterator<char>(fs)),
        std::istreambuf_iterator<char>()
    );

    PassReprFull<> rf(std::cout);
    PassHighlight<> hl(std::cout);

    auto parsed = Parser<>::parse(input, false);

    parsed->runPass(&hl);
    std::cout << std::endl << std::endl;

    auto env = mylang::makeEnv();
    PassAnalysis<> an(env);

    try {
        parsed->runPass(&an);
    } catch (const libblock::error_t &e) {
        std::cout << "ERROR: " << e.info;
    }
    std::cout << std::endl;

    CodeVisitorRepr(env, std::cout);
    std::cout << std::endl << std::endl;

    auto trans = CodeVisitorTranslateLLVM(env);
    (void) trans;

    // // test
    // std::vector<std::string> proto_arg;
    // proto_arg.push_back("n");

    // llvm::Function *func = instance().func("test", proto_arg, "int");

    // LLVM
    instance().dump();

    // fin
    delete env;
    delete parsed;

    std::cout << "ok!" << std::endl;

    return 0;
}
