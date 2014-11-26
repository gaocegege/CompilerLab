#ifndef MYLANG_SYNTAX_SPEC_HPP
#define MYLANG_SYNTAX_SPEC_HPP

#include <set>

#include "parser/myparser_rule.hpp"

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
            "and", "array", "begin", "boolean", "byte",
            "class", "const", "div", "do", "downto",
            "elif", "else", "encloses", "end", "extends",
            "for", "foreach", "function",
            "if", "in", "integer", "is", "mod", "no", "not",
            "of", "or", "out", "pointer", "program",
            "real", "reference", "reg", "repeat", "return",
            "static", "then", "to", "type", "until",
            "var", "void", "while", "xor", "yes"
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
