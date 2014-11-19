#ifndef MYLANG_PASS_TEST_HPP
#define MYLANG_PASS_TEST_HPP

#include "mylang_syntax.hpp"

namespace myparser {

template <>
class Pass<0>: public PassProto {
public:
    MYPARSER_INLINE Pass(): PassProto(0) {}

    MYPARSER_INLINE void run(const Node *node) {
        std::cout << node->getFullText() << "aaaaaaaaaaaaaaaa";
    }
};

}

#endif
