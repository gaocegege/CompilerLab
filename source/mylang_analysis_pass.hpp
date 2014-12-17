#ifndef MYLANG_ANALYSIS_PASS_HPP
#define MYLANG_ANALYSIS_PASS_HPP

#include "mylang_syntax_spec.hpp"
#include "mylang_analysis_call.hpp"
#include "semantic/block.hpp"

namespace myparser {

enum {
    PASS_ANALYSIS = PASS_USER
};

template <>
class Pass<PASS_ANALYSIS>: public PassProto<PASS_ANALYSIS> {
private:
    // in status
    // libblock::Block *in_block; // TODO

public:
    // inline Pass(libblock::Block *base): in_block{base} {} // TODO

    // virtual ~Pass() {}

    // ignored nodes

    template <class N, class E>
    void run(const NodeTyped<N, NodeError<E>> *node) {
        // TODO: never reach if no parsing error
        (void) node;
    }

    // common nodes

    template <class N, class T>
    void run(const NodeTyped<N, T> *node) {
        // mylang::InfoFrame<N, T>::run()
    }
};

}

#endif
