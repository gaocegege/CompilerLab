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
    std::cout << StaticStr<'a', 'b', 'c'>::getStr() << std::endl;
    std::cout << MP_STR("hello", 5)::getStr() << std::endl;
}

int main() {
    test();

    return 0;
}
