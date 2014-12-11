#ifndef MYLANG_ANALYSIS_HPP
#define MYLANG_ANALYSIS_HPP

#include "mylang_syntax_spec.hpp"
#include "semantic/block.hpp"

namespace myparser {

enum {
    PASS_ANALYSIS = PASS_USER
};

template <>
class Pass<PASS_ANALYSIS>: public PassProto<PASS_ANALYSIS> {
private:
    std::vector<libblock::Block *> blocks;

public:
    inline Pass(libblock::Block &base): blocks{&base} {}

    // virtual ~Pass() {}

    void run(const Node *node) {
        // TODO
        (void) node;
    }
};

}

#endif
