#ifndef MYLANG_SYNTAX_SPEC_HPP
#define MYLANG_SYNTAX_SPEC_HPP

#include <set>

#include "parser/myparser.hpp"

namespace myparser {

using ErrorId = MP_STR("Illegal identifier", 18);
using ErrorInteger = MP_STR("Illegal integer", 15);

template <class E>
class NodeId: public NodeTextOrError<E> {
private:
    /* const */ bool ok;

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

        ok = keywords.find(NodeTextOrError<E>::getText()) == keywords.cend();
    }

    // virtual ~NodeId() {}

    virtual bool accepted() const {
        return ok;
    }
};

template <size_t I>
class NodeBaseList<BuiltinSpace, I> {
public:
    using Type = NodeSpace<I>;
};

template <>
class NodeBaseText<MP_STR("id", 2)> {
public:
    using Type = NodeId<ErrorId>;
};

template <>
class NodeBaseText<MP_STR("real", 4)> {
public:
    using Type = NodeData<double, ErrorInteger>;
};

template <>
class NodeBaseText<MP_STR("integer", 7)> {
public:
    using Type = NodeData<long, ErrorInteger>;
};

// byte
// string

}

#endif
