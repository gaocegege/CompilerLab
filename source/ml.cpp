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
