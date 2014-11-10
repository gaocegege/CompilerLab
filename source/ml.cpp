#include <iostream>

#include "parser/myparser_rule.hpp"

using namespace myparser;

template <>
class myparser::RuleDef<MP_STR("id", 2)>: public RuleRegex<
    MP_STR("id", 2),
    MP_STR("[A-Za-z][A-Za-z0-9_]*", 22)
> {};

void test() {
    std::cout << StaticStr<'a', 'b', 'c'>::getStr() << std::endl;
    std::cout << MP_STR("hello", 5)::getStr() << std::endl;
}

int main() {
    test();

    return 0;
}
