#ifndef MYLANG_ANALYSIS_PASS_HPP
#define MYLANG_ANALYSIS_PASS_HPP

#include "mylang_const.hpp"
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
    inline void go(const NodeList<> *node) {
        for (const Node<> *child: node->getChildren()) {
            child->runPass(this);
        }
    }

public:
    // inline Pass(libblock::Block *base): in_block{base} {} // TODO

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
        //mylang::putCall([=]() {
            //mylang::DelayedCall<Proto *()> proto;
        //    return (libblock::Block *) nullptr;
        //});
    }

    MYLANG_ANALYSIS_LIST("function", 8) {
        // TODO: proto?
        //enterBlock();
        go(node);
        //exitBlock();
        // TODO: end?
    }

    MYLANG_ANALYSIS_LIST("class", 5) {
        //enterBlock();
        go(node);
        //exitBlock();
    }

    MYLANG_ANALYSIS_LIST("end program", 11) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("end function", 12) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("main body", 9) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("public block", 12) {
        //auto visibility = libblock::Name::V_PUBLIC;

        //in_visibility = &visibility;
        // TODO: pass1 - create name; pass2 - compile
        go(node);
        //in_visibility = nullptr;
    }

    MYLANG_ANALYSIS_LIST("private block", 13) {
        //auto visibility = libblock::Name::V_PRIVATE;

        //in_visibility = &visibility;
        // TODO: pass1 - create name; pass2 - compile
        go(node);
        //in_visibility = nullptr;
    }

    MYLANG_ANALYSIS_LIST("code block", 10) {
        // TODO: entry = code_main
        go(node);
    }

    MYLANG_ANALYSIS_LIST("function proto", 14) {
        // TODO: get name & arg list
        go(node);
    }

    MYLANG_ANALYSIS_LIST("argument list", 13) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("argument", 8) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("definition list", 15) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("definition", 10) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("type definition", 15) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("field definition", 16) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("field deletion", 14) {
        // TODO: get id, delete
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("field type", 10) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("id bind", 7) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("default", 7) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("type", 4) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("type of", 7) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("statement list", 14) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("statement", 9) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("assignment", 10) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("assign sign", 11) {
        mylang::DelayedCall<
            libblock::NameRange (libblock::Block *)
        >::put([=](libblock::Block *block) {
            static const std::map<const std::string, const std::string> table = {
                {":=", mylang::name_assign},
                {"+=", mylang::name_assign_add},
                {"-=", mylang::name_assign_sub},
                {"*=", mylang::name_assign_mul},
                {"/=", mylang::name_assign_div}
            };

            return block->getMember(table.find(node->asFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("receive", 7) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("return", 6) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("structure", 9) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("if structure", 12) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("for structure", 13) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("foreach structure", 17) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("while structure", 15) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("condition chain", 15) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("to range", 8) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("repeat", 6) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("expression list", 15) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("expression", 10) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("relative expression", 19) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("relative operation", 18) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("additive expression", 19) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("additive operation", 18) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("multiplicative expression", 25) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("multiplicative operation", 24) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("unary expression", 16) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("access operation", 16) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("relation", 8) {
        mylang::DelayedCall<
            libblock::NameRange (libblock::Block *)
        >::put([=](libblock::Block *block) {
            static const std::map<const std::string, const std::string> table = {
                {"==", mylang::name_equal},
                {"<=", mylang::name_less_equal},
                {"=<", mylang::name_less_equal},
                {">=", mylang::name_greater_equal},
                {"=>", mylang::name_greater_equal},
                {"!=", mylang::name_not_equal},
                {"<", mylang::name_less},
                {">", mylang::name_greater},
                {"in", mylang::name_in}
            };

            return block->getMember(table.find(node->asFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("addition", 8) {
        mylang::DelayedCall<
            libblock::NameRange (libblock::Block *)
        >::put([=](libblock::Block *block) {
            static const std::map<const std::string, const std::string> table = {
                {"+", mylang::name_add},
                {"-", mylang::name_sub},
                {"or", mylang::name_or},
                {"xor", mylang::name_xor}
            };

            return block->getMember(table.find(node->asFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("multiplication", 14) {
        mylang::DelayedCall<
            libblock::NameRange (libblock::Block *)
        >::put([=](libblock::Block *block) {
            static const std::map<const std::string, const std::string> table = {
                {"*", mylang::name_mul},
                {"/", mylang::name_div},
                {"%", mylang::name_mod},
                {"div", mylang::name_div},
                {"mod", mylang::name_mod},
                {"and", mylang::name_and},
                {"shl", mylang::name_shl},
                {"shr", mylang::name_shr},
                {"rol", mylang::name_rol},
                {"ror", mylang::name_ror}
            };

            return block->getMember(table.find(node->asFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("unary operator", 14) {
        mylang::DelayedCall<
            libblock::NameRange (libblock::Block *)
        >::put([=](libblock::Block *block) {
            static const std::map<const std::string, const std::string> table = {
                {"+", mylang::name_pos},
                {"-", mylang::name_neg},
                {"not", mylang::name_not}
            };

            return block->getMember(table.find(node->asFullText())->second);
        });
    }

    MYLANG_ANALYSIS_TEXT("comparison", 10) {
        (void) node; // see parent list
    }

    MYLANG_ANALYSIS_TEXT("addsub", 6) {
        (void) node; // see parent list
    }

    MYLANG_ANALYSIS_TEXT("muldivmod", 9) {
        (void) node; // see parent list
    }

    MYLANG_ANALYSIS_LIST("value", 5) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("literal", 7) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_TEXT("real", 4) {
        mylang::DelayedCall<double ()>::put([=]() {
            return node->getData();
        });
    }

    MYLANG_ANALYSIS_TEXT("integer", 7) {
        mylang::DelayedCall<long ()>::put([=]() {
            return node->getData();
        });
    }

    MYLANG_ANALYSIS_TEXT("byte", 4) {
        mylang::DelayedCall<char ()>::put([=]() {
            return node->getRaw()[0];
        });
    }

    MYLANG_ANALYSIS_TEXT("string", 6) {
        mylang::DelayedCall<std::string ()>::put([=]() {
            return node->getRaw();
        });
    }

    MYLANG_ANALYSIS_LIST("instant array", 13) {
        // TODO
        (void) node; // TODO
    }

    MYLANG_ANALYSIS_LIST("space", 5) {
        // skip
        (void) node;
    }

    MYLANG_ANALYSIS_LIST("keyword", 7) {
        // notice:
        //     "keyword" can be both list (parsing) and text (parsed)

        // never reach
        (void) node;
    }

    MYLANG_ANALYSIS_TEXT("keyword", 7) {
        // skip
        (void) node;
    }

    MYLANG_ANALYSIS_TEXT("id", 2) {
        mylang::DelayedCall<
            libblock::NameRange (libblock::Block *)
        >::put([=](libblock::Block *block) {
            return block->getMember(node->getText());
        });
    }

    MYLANG_ANALYSIS_TEXT("reserved id", 11) {
        // skip
        (void) node;
    }

    MYLANG_ANALYSIS_TEXT("sign", 4) {
        // skip
        (void) node;
    }

    MYLANG_ANALYSIS_TEXT("ignored", 7) {
        // skip
        (void) node;
    }

    #undef MYLANG_ANALYSIS_LIST
    #undef MYLANG_ANALYSIS_TEXT

    // ignored nodes

    template <class N, class E>
    void run(const NodeTyped<N, NodeError<E>> *node) {
        // TODO: never reach if no parsing error
        (void) node;
    }
};

}

#endif
