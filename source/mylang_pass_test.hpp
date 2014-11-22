#ifndef MYLANG_PASS_TEST_HPP
#define MYLANG_PASS_TEST_HPP

#include "mylang_syntax.hpp"

namespace myparser {

template <>
class Pass<1>: public PassProto<1> {
public:
    inline Pass(): PassProto() {}

    // virtual ~Pass() {}

    void run(const Node *node) {
        std::cout << node->getFullText() << "aaaaaaaaaaaaaaaa";
    }
};

}

#endif
