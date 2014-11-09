#include <iostream>

#include "ml_ast.h"
#include "ml_syntax.h"

namespace mylang {

const char name[] = "id";
const char regex[] = "[A-Za-z][A-Za-z0-9_]*";

template <>
class RuleDef<ML_STR("id", 2)>: public RuleRegex<
    ML_STR("id", 2),
    ML_STR("[A-Za-z][A-Za-z0-9_]*", 22)
> {};

template <char C>
class tobj {
public:
    static const char c = C;
};

}

using namespace mylang;

void test() {
    // StaticStr<'a', 'b', 'c'> a;

    std::cout << StaticStr<'a', 'b', 'c'>::getStr() << std::endl;
    std::cout << ssSize("adsfs") << std::endl;

    #define xx(str, len) x##len(str, 0)

    #define x6(str, index) str[index], x5(str, index + 1)
    #define x5(str, index) str[index], x4(str, index + 1)
    #define x4(str, index) str[index], x3(str, index + 1)
    // #define x3(str, index) str[index], x2(str, index + 1)
    #define x2(str, index) str[index], x1(str, index + 1)
    #define x1(str, index) str[index]
    std::cout << tobj<"hello"[1]>::c << std::endl;
    std::cout << ML_STR("hello", 5)::getStr() << std::endl;
}

int main() {
    test();

    return 0;
}
