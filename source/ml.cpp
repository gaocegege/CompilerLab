#if 0
python gen_parser.py
g++ -std=c++11 ml.cpp -o ml_gcc && ./ml_gcc
clang++ -std=c++11 ml.cpp -o ml_clang && ./ml_clang
exit
#endif

#include <iostream>

#include "mylang_syntax.hpp"

using namespace mylang;


void test() {
    std::string s = "hello_123";
    auto sbegin = s.begin();

    auto x = RuleDef<MP_STR("type id", 7)>::parse(sbegin, s.end());
    std::cout << x->getTree() << std::endl;

    // RuleDef<MP_STR("root", 4)>::parse(sbegin, s.end());

    std::cout << StaticStr<*("abc" + sizeof("abc") - 2)>::getStr() << std::endl;
    std::cout << StaticStr<'a', 'b', 'c'>::getStr() << std::endl;
    std::cout << MP_STR("hello", 5)::getStr() << std::endl;
}

int main() {
    test();

    return 0;
}
