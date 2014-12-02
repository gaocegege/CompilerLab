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
            "var", "const", "static", "fast", "receive", "return",
            "default", "auto", "of", "pause",
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
class NodeBaseList<BuiltinSpace, I> {
public:
    using Type = NodeSpace<I>;
};

template <>
class NodeBaseText<RuleId> {
public:
    using Type = NodeId<>;
};

}

#endif
