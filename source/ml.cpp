#if 0
python gen_parser.py

# === gcc ===
# g++ -std=c++11 -Wall -Wextra -pedantic -O0\
#     *.cpp -o ml_gcc $@ &&\
# ./ml_gcc

# === clang libstdc++ ===
# clang++ -std=c++11 -stdlib=libstdc++ -Wall -Wextra -Wbind-to-temporary-copy -pedantic -fno-rtti -ferror-limit=1 -O0\
#     *.cpp -o ml_clang $@ &&\
# ./ml_clang

# === clang libc++ ===
clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -Wbind-to-temporary-copy -pedantic -fno-rtti -ferror-limit=1 -O0\
    *.cpp -o ml_clang $@ &&\
./ml_clang

# === (TODO) clang libc++ pch ===
# clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -Wbind-to-temporary-copy -pedantic -fno-rtti -ferror-limit=1 -O0\
#     -x c++-header parser/myparser.hpp -o parser/myparser.hpp.pch $@ &&\
# clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -Wbind-to-temporary-copy -pedantic -fno-rtti -ferror-limit=1 -O0\
#     -include parser/myparser.hpp *.cpp -o ml_clang $@ &&\
# ./ml_clang

exit
#endif

#include <iostream>
#include <fstream>
#include <streambuf>

#include "mylang.hpp"

using namespace mylang;

int main(int argc, char **argv) {
    PassReprFull<> rf(std::cout);
    PassReprFull<> rf1(std::cout, true);
    PassReprSimple<> rf2(std::cout);
    PassReprText<> rf3(std::cout);
    PassReprJSON<> rf4(std::cout);
    PassHighlight<> hl(std::cout);

    char *s;

    if (argc > 1) {
        s = argv[1];
    } else {
        s = "example.ml";
    }
    std::ifstream t(s);

    std::string s1(
        (std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>()
    );

    auto x2 = Parser<>::parse(s1, false);

    // x2->runPass(&rf1);
    // std::cout << std::endl << std::endl;
    // x2->runPass(&rf);
    // std::cout << std::endl << std::endl;
    x2->runPass(&hl);
    std::cout << std::endl << std::endl;


    auto env = mylang::makeEnv();
    PassAnalysis<> an(env);

    try {
        x2->runPass(&an);
    } catch (const libblock::error_t &e) {
        std::cout << "ERROR: " << e.info;
    }
    std::cout << std::endl;

    (void) CodeVisitorRepr(env, std::cout);

    delete env;

    delete x2;

    return 0;
}
