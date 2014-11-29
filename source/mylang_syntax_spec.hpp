#ifndef MYLANG_SYNTAX_SPEC_HPP
#define MYLANG_SYNTAX_SPEC_HPP

#include <set>

#include "parser/myparser.hpp"

namespace myparser {

using RuleId = MP_STR("id", 2);

using ErrorId = MP_STR("Illegal identifier", 18);

template <class TX = void> // actually not a template
class NodeId: public NodeTextOrError<ErrorId> {
private:
    /* const */ bool ok;

public:
    inline NodeId(
        const Input &input, std::string &&value
    ): NodeTextOrError(input, std::move(value)) {
        static const std::set<std::string> keywords = {
            "program", "function", "class", "end",
            "is", "begin", "in", "out",
            "type", "extends", "enclose",
            "var", "const", "static", "register", "return",
            "default", "auto", "of",
            "if", "then", "for", "do", "foreach", "while",
            "elif", "else", "to", "downto", "repeat", "until",
            "or", "xor", "div", "mod", "and", "shl", "shr", "rol", "ror", "not"
        };

        ok = keywords.find(getText()) == keywords.cend();
    }

    // virtual ~NodeId() {}

    virtual bool accepted() const {
        return ok;
    }
};

template <size_t I>
class NodeTyped<BuiltinSpace, NodeListIndexed<I>>:
public NodeTypedProto<BuiltinSpace, NodeSpace<I>> {
public:
    using NodeTypedProto<BuiltinSpace, NodeSpace<I>>::NodeTypedProto;
};

template <>
class NodeTyped<RuleId, NodeText<>>:
public NodeTypedProto<RuleId, NodeId<>> {
public:
    using NodeTypedProto<RuleId, NodeId<>>::NodeTypedProto;
};

}

#endif
