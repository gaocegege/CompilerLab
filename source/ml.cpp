#if 0
python gen_parser.py
# g++ -std=c++11 -Wall -Wextra -pedantic -O1 ml.cpp -o ml_gcc $@ &&\
#     strip ml_gcc &&\
#     ./ml_gcc
# clang++ -std=c++11 -Wall -Wextra -pedantic -O1 ml.cpp -o ml_clang $@ &&\
#     strip ml_clang &&\
#     ./ml_clang
clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -pedantic -O1 ml.cpp -o ml_clang $@ &&\
#    strip ml_clang &&\
    ./ml_clang
exit
#endif

#include <iostream>

#include "mylang_util.hpp"

using namespace mylang;

void test() {
    std::string s = "1 * \n(2 + y*-3 > sin 30)";
    Input sbegin = s.cbegin();
    auto x = Parser<MP_STR("expression", 10)>::parse(sbegin, s.cend());
    auto x1 = Parser<>::parse(s);

    PassReprFull<> rf(std::cout);
    PassReprFull<> rf1(std::cout, true);
    PassReprSimple<> rf2(std::cout);
    PassReprText<> rf3(std::cout);
    PassReprJSON<> rf4(std::cout);

    x->runPass(&rf);
    std::cout << std::endl << std::endl;
    x->runPass(&rf1);
    std::cout << std::endl << std::endl;
    x->runPass(&rf2);
    std::cout << std::endl << std::endl;
    x->runPass(&rf3);
    std::cout << std::endl << std::endl;
    x->runPass(&rf4);
    std::cout << std::endl << std::endl;
    x1->runPass(&rf);
    std::cout << std::endl << std::endl;
    x1->runPass(&rf1);
    std::cout << std::endl << std::endl;
    x1->runPass(&rf2);
    std::cout << std::endl << std::endl;
    x1->runPass(&rf3);
    std::cout << std::endl << std::endl;
    x1->runPass(&rf4);
    std::cout << std::endl << std::endl;

    delete x;
    delete x1;
}

int main() {
    test();

    return 0;
}
