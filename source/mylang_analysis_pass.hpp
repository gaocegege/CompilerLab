#ifndef MYLANG_ANALYSIS_PASS_HPP
#define MYLANG_ANALYSIS_PASS_HPP

#include "mylang_syntax_spec.hpp"
#include "mylang_analysis_node.hpp"
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

    template <class NT, class E>
    void run(const NodeTyped<NT, NodeError<E>> *node) {
        // TODO: never reach if no parsing error
        (void) node;
    }

    /*template <class NT, size_t I>
    void run(const NodeTyped<NT, NodeSpace<I>> *node) {
        // skip
        (void) node;
    }

    template <class NT, class E>
    void run(const NodeTyped<NT, NodeKeyword<E>> *node) {
        // skip
        (void) node;
    }*/ // TODO: necessary?

    // common nodes

    template <class NT, class T>
    void run(const NodeTyped<NT, T> *node) {
        //
    }
};

}

#endif
