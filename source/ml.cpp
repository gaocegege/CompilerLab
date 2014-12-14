#if 0
python gen_parser.py
# g++ -std=c++11 -Wall -Wextra -pedantic -O1 *.cpp -o ml_gcc $@ &&\
#     strip ml_gcc &&\
#     ./ml_gcc
# clang++ -std=c++11 -Wall -Wextra -pedantic -fno-rtti -ferror-limit=1 -O1 *.cpp -o ml_clang $@ &&\
#     strip ml_clang &&\
#     ./ml_clang
clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -pedantic -fno-rtti -ferror-limit=1 -O1 *.cpp -o ml_clang $@ &&\
#    strip ml_clang &&\
    ./ml_clang
exit
#endif

#include <iostream>
#include <fstream>
#include <streambuf>

#include "mylang.hpp"

using namespace mylang;

void test() {
    PassReprFull<> rf(std::cout);
    PassReprFull<> rf1(std::cout, true);
    PassReprSimple<> rf2(std::cout);
    PassReprText<> rf3(std::cout);
    PassReprJSON<> rf4(std::cout);
    PassHighlight<> hl(std::cout);

    std::ifstream t("example.ml");
    std::string s1(
        (std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>()
    );

    auto x2 = Parser<>::parse(s1, false);

    x2->runPass(&rf1);
    std::cout << std::endl << std::endl;
    x2->runPass(&rf);
    std::cout << std::endl << std::endl;
    x2->runPass(&hl);
    std::cout << std::endl << std::endl;

    delete x2;
}

int main() {
    // for (int i = 0; i < 100; ++i)
    test();

    return 0;
}
