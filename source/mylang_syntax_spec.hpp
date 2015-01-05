#ifndef MYLANG_SYNTAX_SPEC_HPP
#define MYLANG_SYNTAX_SPEC_HPP

#include <set>

#include "parser/myparser.hpp"
#include "mylang_const.hpp"

namespace myparser {

using ErrorId = MP_STR("Illegal identifier", 18);
using ErrorLiteral = MP_STR("Illegal literal", 15);

template <class E>
class NodeId: public NodeTextOrError<E> {
private:
    /* const */ bool succeed;

public:
    inline NodeId(
        const Input &input, const Input &end
    ): NodeTextOrError<E>(input, end) {
        static const std::set<std::string> keywords = {
            "program", "function", "class", "end",
            "is", "begin", "in", "out", // "var", "type",
            "type", "expr", "var", "static", "fast",
            "extends", "refers", "receive", "return", "imports", // "is",
            "if", "then", "for", "do", "foreach", "while",
            "elif", "else", "to", "downto", "repeat", "until", "of",
            "or", "xor", "div", "mod", "and", "shl", "shr", "rol", "ror", "not"
        };

        succeed = keywords.find(std::string(input, end)) == keywords.cend();
    }

    // virtual ~NodeId() {}

    virtual bool accepted() const {
        return succeed;
    }
};

// specialization

template <>
class NodeBaseText<MP_STR("id", 2)> {
public:
    template <class TX = void> // actually not a template
    using Type = NodeId<ErrorId>;
};

template <>
class NodeBaseText<MP_STR("real", 4)> {
public:
    template <class TX = void> // actually not a template
    using Type = NodeData<mylang::LangSpec::real, ErrorLiteral>;
};

template <>
class NodeBaseText<MP_STR("integer", 7)> {
public:
    template <class TX = void> // actually not a template
    using Type = NodeData<mylang::LangSpec::integer, ErrorLiteral>;
};

template <>
class NodeBaseText<MP_STR("byte", 4)> {
public:
    template <class TX = void> // actually not a template
    using Type = NodeString<1, 1, '\\', ErrorLiteral>;
};

template <>
class NodeBaseText<MP_STR("string", 6)> {
public:
    template <class TX = void> // actually not a template
    using Type = NodeString<1, 1, '\\', ErrorLiteral>;
};

}

#endif
