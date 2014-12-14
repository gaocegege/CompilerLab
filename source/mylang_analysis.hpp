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

    void go(const NodeList<> *node) {
        for (const Node<> *child: node->getChildren()) {
            child->runPass(this);
        }
    }

public:
    inline Pass(libblock::Block &base): blocks{&base} {}

    // virtual ~Pass() {}

    #define MYLANG_ANALYSIS_LIST(name, namelen) \
        template <size_t I>\
        void run(const NodeTypedList<MP_STR(name, namelen), I> *node)

    #define MYLANG_ANALYSIS_TEXT(name, namelen) \
        template <class TX = void> /* actually not a template */\
        void run(const NodeTypedText<MP_STR(name, namelen)> *node)

    MYLANG_ANALYSIS_LIST("root", 4) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("main structure", 14) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("program", 7) {
        // TODO
    }

    MYLANG_ANALYSIS_LIST("function", 8) {
        // TODO
    }

    MYLANG_ANALYSIS_LIST("class", 5) {
        // TODO
    }

    MYLANG_ANALYSIS_LIST("end program", 11) {
        if (I == 0) {
            // TODO: check ID
        }
    }

    MYLANG_ANALYSIS_LIST("end function", 12) {
        if (I == 0) {
            // TODO: check ID
        }
    }

    MYLANG_ANALYSIS_LIST("main body", 9) {
        // rule = public
        go(node);
    }

    MYLANG_ANALYSIS_LIST("interface block", 15) {}

    MYLANG_ANALYSIS_LIST("is block", 8) {}

    MYLANG_ANALYSIS_LIST("code block", 10) {}

    MYLANG_ANALYSIS_LIST("function proto", 14) {}

    MYLANG_ANALYSIS_LIST("argument list", 13) {}

    MYLANG_ANALYSIS_LIST("argument", 8) {}

    MYLANG_ANALYSIS_LIST("definition", 10) {}

    MYLANG_ANALYSIS_LIST("type definition", 15) {}

    MYLANG_ANALYSIS_LIST("field definition", 16) {}

    MYLANG_ANALYSIS_LIST("field deletion", 14) {}

    MYLANG_ANALYSIS_LIST("field type", 10) {}

    MYLANG_ANALYSIS_LIST("id bind", 7) {}

    MYLANG_ANALYSIS_LIST("default", 7) {}

    MYLANG_ANALYSIS_LIST("type", 4) {}

    MYLANG_ANALYSIS_LIST("type of", 7) {}

    MYLANG_ANALYSIS_LIST("statement list", 14) {}

    MYLANG_ANALYSIS_LIST("statement", 9) {}

    MYLANG_ANALYSIS_LIST("assignment", 10) {}

    MYLANG_ANALYSIS_TEXT("assign sign", 11) {}

    MYLANG_ANALYSIS_LIST("receive", 7) {}

    MYLANG_ANALYSIS_LIST("pause", 5) {}

    MYLANG_ANALYSIS_LIST("return", 6) {}

    MYLANG_ANALYSIS_LIST("structure", 9) {}

    MYLANG_ANALYSIS_LIST("if structure", 12) {}

    MYLANG_ANALYSIS_LIST("for structure", 13) {}

    MYLANG_ANALYSIS_LIST("foreach structure", 17) {}

    MYLANG_ANALYSIS_LIST("while structure", 15) {}

    MYLANG_ANALYSIS_LIST("condition chain", 15) {}

    MYLANG_ANALYSIS_LIST("to range", 8) {}

    MYLANG_ANALYSIS_LIST("repeat", 6) {}

    MYLANG_ANALYSIS_LIST("expression list", 15) {}

    MYLANG_ANALYSIS_LIST("expression", 10) {}

    MYLANG_ANALYSIS_LIST("relative expression", 19) {}

    MYLANG_ANALYSIS_LIST("relative operation", 18) {}

    MYLANG_ANALYSIS_LIST("additive expression", 19) {}

    MYLANG_ANALYSIS_LIST("additive operation", 18) {}

    MYLANG_ANALYSIS_LIST("multiplicative expression", 25) {}

    MYLANG_ANALYSIS_LIST("multiplicative operation", 24) {}

    MYLANG_ANALYSIS_LIST("unary expression", 16) {}

    MYLANG_ANALYSIS_LIST("access operation", 16) {}

    MYLANG_ANALYSIS_LIST("relation", 8) {}

    MYLANG_ANALYSIS_LIST("addition", 8) {}

    MYLANG_ANALYSIS_LIST("multiplication", 14) {}

    MYLANG_ANALYSIS_LIST("unary operator", 14) {}

    MYLANG_ANALYSIS_TEXT("comparison", 10) {}

    MYLANG_ANALYSIS_TEXT("addsub", 6) {}

    MYLANG_ANALYSIS_TEXT("muldivmod", 9) {}

    MYLANG_ANALYSIS_LIST("value list", 10) {}

    MYLANG_ANALYSIS_LIST("value", 5) {}

    MYLANG_ANALYSIS_LIST("literal", 7) {}

    MYLANG_ANALYSIS_TEXT("real", 4) {}

    MYLANG_ANALYSIS_TEXT("integer", 7) {}

    MYLANG_ANALYSIS_TEXT("byte", 4) {}

    MYLANG_ANALYSIS_TEXT("string", 6) {}

    MYLANG_ANALYSIS_LIST("instant array", 13) {}

    MYLANG_ANALYSIS_LIST("space", 5) {}

    MYLANG_ANALYSIS_LIST("keyword", 7) {}

    MYLANG_ANALYSIS_TEXT("id", 2) {}

    MYLANG_ANALYSIS_TEXT("reserved id", 11) {}

    MYLANG_ANALYSIS_TEXT("sign", 4) {}

    MYLANG_ANALYSIS_TEXT("ignored", 7) {}

    #undef MYLANG_ANALYSIS_LIST
    #undef MYLANG_ANALYSIS_TEXT

    // misc

    template <class NT, class KW>
    void run(const NodeTypedKeyword<NT, KW> *node) {
        // TODO: never reach
    }

    template <class NT, class E>
    void run(const NodeTypedError<NT, E> *node) {
        // TODO: never reach
    }

    void run(const Node<> *node) {
        // TODO: ???
    }
};

}

#endif
