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

    using NodeIter = std::vector<Node<> *>::const_iterator;

    inline NodeIter scanBegin(const NodeList<> *node) {
        return node->getChildren().cbegin();
    }

    template <class T>
    inline void scanFill(NodeIter &iter, T &target) {
        for (; !target; ++iter) {
            (*iter)->runPass(this);
        }
    }

    template <class T>
    static inline libblock::Code *makeCall(
        T name,
        libblock::Code *arg
    ) {
        libblock::Code *func =
            new libblock::CodeGet(
                libblock::name_t(std::forward<T>(name))
            );

        return new libblock::CodeCall(func, arg);
    }

    template <class T>
    static inline libblock::Code *makeCall(
        T name,
        libblock::Code *left,
        libblock::Code *right
    ) {
        // TODO: if (!left || !right)

        libblock::Code *func =
            new libblock::CodeGet(
                libblock::name_t(std::forward<T>(name))
            );

        if (left->getNext() || right->getNext()) {
            // TODO: anonymous struct (tuple)
            return nullptr;
        } else {
            return makeCall(
                std::forward<T>(name),
                libblock::Code::pack(left, right)
            );
        }
    }

public:
    // inline Pass(libblock::Block *base): in_block{base} {} // TODO

    // virtual ~Pass() {}

    using ExpressionCall = mylang::DelayedCall<libblock::Code * ()>;
    using OperationCall = mylang::DelayedCall<libblock::Code * (ExpressionCall &)>;
    using IdCall = mylang::DelayedCall<libblock::name_t ()>;

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
        ExpressionCall::put([=]() -> libblock::Code * {
            if (I == 0) {
                // member:
                ExpressionCall left;

                node->getChildren().front()->runPass(this);

                // next:
                ExpressionCall right;

                node->getChildren().back()->runPass(this);

                return libblock::Code::pack(left(), right());
            } else {
                return nullptr;
            }
        });
    }

    MYLANG_ANALYSIS_LIST("statement", 9) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("receive", 7) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall left;

            go(node);

            return makeCall(
                mylang::name_assign,
                left(),
                new libblock::CodeGet(
                    libblock::name_t(mylang::name_input)
                )
            );
        });
    }

    MYLANG_ANALYSIS_LIST("return", 6) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall right;

            go(node);

            // TODO: exit current function?

            return makeCall(
                mylang::name_assign,
                new libblock::CodeGet(
                    libblock::name_t(mylang::name_result)
                ),
                right()
            );
        });
    }

    MYLANG_ANALYSIS_LIST("structure", 9) {
        go(node);
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
        ExpressionCall::put([=]() -> libblock::Code * {
            NodeIter iter = scanBegin(node);

            ExpressionCall body;
            scanFill(iter, body);

            ExpressionCall cond;
            scanFill(iter, cond);

            libblock::CodeLabel *begin = new libblock::CodeLabel();
            libblock::CodeLabel *end = new libblock::CodeLabel();

            libblock::Code *gobegin = new libblock::CodeGoto(begin);
            libblock::Code *goend = new libblock::CodeGoto(end);

            libblock::Code *jump = makeCall(
                mylang::name_if,
                libblock::Code::pack(
                    cond(),
                    libblock::Code::pack(
                        goend,
                        gobegin
                    )
                )
            );

            return libblock::Code::pack(
                begin,
                libblock::Code::pack(
                    body(),
                    libblock::Code::pack(
                        jump,
                        end
                    )
                )
            );
            // TODO: return ???
            // goto(?) / branch(cond, ?, ?)
            // CodeLabel()
        });
    }

    MYLANG_ANALYSIS_LIST("expression list", 15) {
        ExpressionCall::put([=]() -> libblock::Code * {
            if (I == 0) {
                // member:
                ExpressionCall left;

                node->getChildren().front()->runPass(this);

                // next:
                ExpressionCall right;

                node->getChildren().back()->runPass(this);

                return libblock::Code::pack(left(), right());
            } else if (I == 1) {
                // member:
                ExpressionCall left;

                node->getChildren().front()->runPass(this);

                return left();
            } else {
                return nullptr;
            }
        });
    }

    MYLANG_ANALYSIS_LIST("expression", 10) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("assign expression", 17) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall left;
            OperationCall root;

            go(node);

            return root(left);
        });
    }

    MYLANG_ANALYSIS_LIST("assign operation", 16) {
        OperationCall::put([=](ExpressionCall &left) -> libblock::Code * {
            if (I == 0) {
                IdCall op;
                ExpressionCall right;

                go(node);

                return makeCall(
                    op(),
                    left(),
                    right()
                );
            } else {
                return left();
            }
        });
    }

    MYLANG_ANALYSIS_LIST("relative expression", 19) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall left;
            OperationCall root;

            go(node);

            return root(left);
        });
    }

    MYLANG_ANALYSIS_LIST("relative operation", 18) {
        OperationCall::put([=](ExpressionCall &left) -> libblock::Code * {
            if (I == 0) {
                IdCall op;
                ExpressionCall right;

                go(node);

                return makeCall(
                    op(),
                    left(),
                    right()
                );
            } else {
                return left();
            }
        });
    }

    MYLANG_ANALYSIS_LIST("additive expression", 19) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall left;
            OperationCall root;

            go(node);

            return root(left);
        });
    }

    MYLANG_ANALYSIS_LIST("additive operation", 18) {
        OperationCall::put([=](ExpressionCall &left) -> libblock::Code * {
            if (I == 0) {
                IdCall op;
                ExpressionCall right;

                go(node);

                return makeCall(
                    op(),
                    left(),
                    right()
                );
            } else {
                return left();
            }
        });
    }

    MYLANG_ANALYSIS_LIST("multiplicative expression", 25) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall left;
            OperationCall root;

            go(node);

            return root(left);
        });
    }

    MYLANG_ANALYSIS_LIST("multiplicative operation", 24) {
        OperationCall::put([=](ExpressionCall &left) -> libblock::Code * {
            if (I == 0) {
                IdCall op;
                ExpressionCall right;

                go(node);

                return makeCall(
                    op(),
                    left(),
                    right()
                );
            } else {
                return left();
            }
        });
    }

    MYLANG_ANALYSIS_LIST("unary expression", 16) {
        ExpressionCall::put([=]() -> libblock::Code * {
            IdCall op;
            ExpressionCall right;

            go(node);

            return makeCall(
                op(),
                right()
            );
        });
    }

    MYLANG_ANALYSIS_LIST("call expression", 15) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall left;
            OperationCall root;

            go(node);

            return root(left);
        });
    }

    MYLANG_ANALYSIS_LIST("call operation", 14) {
        OperationCall::put([=](ExpressionCall &left) -> libblock::Code * {
            if (I == 0) {
                ExpressionCall right;

                go(node);

                return new libblock::CodeCall(left(), right());
            } else {
                return left();
            }
        });
    }

    MYLANG_ANALYSIS_LIST("access expression", 17) {
        ExpressionCall::put([=]() -> libblock::Code * {
            ExpressionCall left;
            OperationCall root;

            go(node);

            return root(left);
        });
    }

    MYLANG_ANALYSIS_LIST("access operation", 16) {
        OperationCall::put([=](ExpressionCall &left) -> libblock::Code * {
            if (I == 0) {
                ExpressionCall right;

                go(node);

                return new libblock::CodeWith(left(), right());
            } else {
                return left();
            }
        });
    }

    MYLANG_ANALYSIS_LIST("assignment", 10) {
        IdCall::put([=]() {
            static const std::map<const std::string, const std::string> table = {
                {":=", mylang::name_assign},
                {"+=", mylang::name_assign_add},
                {"-=", mylang::name_assign_sub},
                {"*=", mylang::name_assign_mul},
                {"/=", mylang::name_assign_div}
            };

            return libblock::name_t(table.find(node->getFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("relation", 8) {
        IdCall::put([=]() {
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

            return libblock::name_t(table.find(node->getFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("addition", 8) {
        IdCall::put([=]() {
            static const std::map<const std::string, const std::string> table = {
                {"+", mylang::name_add},
                {"-", mylang::name_sub},
                {"or", mylang::name_or},
                {"xor", mylang::name_xor}
            };

            return libblock::name_t(table.find(node->getFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("multiplication", 14) {
        IdCall::put([=]() {
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

            return libblock::name_t(table.find(node->getFullText())->second);
        });
    }

    MYLANG_ANALYSIS_LIST("unary operator", 14) {
        IdCall::put([=]() {
            static const std::map<const std::string, const std::string> table = {
                {"+", mylang::name_pos},
                {"-", mylang::name_neg},
                {"not", mylang::name_not}
            };

            return libblock::name_t(table.find(node->getFullText())->second);
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
        ExpressionCall::put([=]() -> libblock::Code * {
            switch (I) {
            case 0:
                // <id>
                {
                    IdCall value;

                    go(node);

                    return new libblock::CodeGet(value());
                }
            case 1:
                // <real>
                {
                    mylang::DelayedCall<mylang::ml_real ()> value;

                    go(node);

                    return new libblock::CodeLiteral<mylang::ml_real>(value());
                }
            case 2:
                // <integer>
                {
                    mylang::DelayedCall<mylang::ml_integer ()> value;

                    go(node);

                    return new libblock::CodeLiteral<mylang::ml_integer>(value());
                }
            case 3:
                // <byte>
                {
                    mylang::DelayedCall<mylang::ml_byte ()> value;

                    go(node);

                    return new libblock::CodeLiteral<mylang::ml_byte>(value());
                }
            case 4:
                // <string>
                {
                    mylang::DelayedCall<std::string ()> value;

                    go(node);

                    libblock::Code *arg = nullptr;
                    const std::string data = value();

                    for (auto iter = data.rbegin(); iter != data.rend(); ++iter) {
                        libblock::Code *prev =
                            new libblock::CodeLiteral<mylang::ml_byte>(
                                mylang::ml_byte(*iter)
                            );

                        arg = libblock::Code::pack(prev, arg);
                    }

                    return makeCall(
                        mylang::name_array,
                        arg
                    );
                }
            case 5:
                // <tuple>
                {
                    ExpressionCall tuple;

                    go(node);

                    // tuple is always inline
                    return tuple();
                }
            case 6:
                // <array>
                {
                    ExpressionCall tuple;

                    go(node);

                    return makeCall(
                        mylang::name_array,
                        tuple()
                    );
                }
            default:
                // never reach
                return nullptr;
            }
        });
    }

    MYLANG_ANALYSIS_TEXT("real", 4) {
        mylang::DelayedCall<mylang::ml_real ()>::put([=]() {
            return node->getData();
        });
    }

    MYLANG_ANALYSIS_TEXT("integer", 7) {
        mylang::DelayedCall<mylang::ml_integer ()>::put([=]() {
            return node->getData();
        });
    }

    MYLANG_ANALYSIS_TEXT("byte", 4) {
        mylang::DelayedCall<mylang::ml_byte ()>::put([=]() {
            return node->getRaw()[0];
        });
    }

    MYLANG_ANALYSIS_TEXT("string", 6) {
        mylang::DelayedCall<std::string ()>::put([=]() {
            return node->getRaw();
        });
    }

    MYLANG_ANALYSIS_LIST("tuple", 5) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("array", 5) {
        go(node);
    }

    MYLANG_ANALYSIS_LIST("space", 5) {
        // skip
        (void) node;
    }

    MYLANG_ANALYSIS_LIST("keyword", 7) {
        // skip
        (void) node;
    }

    MYLANG_ANALYSIS_TEXT("id", 2) {
        IdCall::put([=]() {
            return libblock::name_t(node->getFullText());
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
