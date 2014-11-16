#if 0
python gen_parser.py
# g++ -std=c++11 -Wall -Wextra -pedantic -O1 ml.cpp -o ml_gcc && ./ml_gcc
# clang++ -std=c++11 -Wall -Wextra -pedantic -O1 ml.cpp -o ml_clang && ./ml_clang
clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -pedantic -O1 ml.cpp -o ml_clang && ./ml_clang
exit
#endif

#include <iostream>

#include "mylang_syntax.hpp"

using namespace mylang;


void test() {
    std::string s = "1 * (2 + y*-3 > sin 30)";
    //std::string s = "1 +y";
    Input sbegin = s.cbegin();
    auto x = RuleDef<MP_STR("expression", 10)>::parse(sbegin, s.cend());
    auto x1 = RuleDef<MP_STR("root", 4)>::parse(sbegin, s.cend());

    // std::string s = ":=";
    // Input sbegin = s.cbegin();
    // auto x = RuleDef<MP_STR("keyword", 7)>::parse(sbegin, s.cend());

    std::cout << x->getTree() << std::endl;
    std::cout << x1->getTree() << std::endl;

    std::cout << StaticStr<'a', 'b', 'c'>::getStr() << std::endl;
    std::cout << MP_STR("hello", 5)::getStr() << std::endl;
}

int main() {
    test();

    return 0;
}
