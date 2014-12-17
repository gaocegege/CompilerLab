#ifndef MYLANG_SYNTAX_SPEC_HPP
#define MYLANG_SYNTAX_SPEC_HPP

#include <set>

#include "parser/myparser.hpp"

namespace myparser {

using ErrorId = MP_STR("Illegal identifier", 18);
using ErrorLiteral = MP_STR("Illegal literal", 15);

template <class E>
class NodeId: public NodeTextOrError<E> {
private:
    /* const */ bool succeed;

public:
    inline NodeId(
        const Input &input, std::string &&value
    ): NodeTextOrError<E>(input, std::move(value)) {
        static const std::set<std::string> keywords = {
            "program", "function", "class", "end",
            "is", "begin", "in", "out",
            "type", "extends", "enclose",
            "var", "const", "static", "fast", "receive", "return",
            "default", "auto", "of", "pause",
            "if", "then", "for", "do", "foreach", "while",
            "elif", "else", "to", "downto", "repeat", "until",
            "or", "xor", "div", "mod", "and", "shl", "shr", "rol", "ror", "not"
        };

        succeed = keywords.find(NodeTextOrError<E>::getText()) == keywords.cend();
    }

    // virtual ~NodeId() {}

    virtual bool accepted() const {
        return succeed;
    }
};

template <size_t I>
class NodeBaseList<BuiltinSpace, I> {
public:
    using Type = NodeSpace<I>;
};

template <>
class NodeBaseText<BuiltinKeyword> {
public:
    using Type = NodeKeyword<>;
};

template <>
class NodeBaseText<MP_STR("id", 2)> {
public:
    using Type = NodeId<ErrorId>;
};

template <>
class NodeBaseText<MP_STR("real", 4)> {
public:
    using Type = NodeData<double, ErrorLiteral>;
};

template <>
class NodeBaseText<MP_STR("integer", 7)> {
public:
    using Type = NodeData<long, ErrorLiteral>;
};

template <>
class NodeBaseText<MP_STR("byte", 4)> {
public:
    using Type = NodeString<1, 1, '\\', ErrorLiteral>;
};

template <>
class NodeBaseText<MP_STR("string", 6)> {
public:
    using Type = NodeString<1, 1, '\\', ErrorLiteral>;
};

}

#endif
