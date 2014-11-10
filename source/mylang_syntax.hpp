#ifndef MYLANG_SYNTAX_HPP
#define MYLANG_SYNTAX_HPP

#include "parser/myparser_rule.hpp"

namespace mylang{

using namespace myparser;
// need specialization
template <class N>
class RuleDef: public RuleNamed<N> {
public:
    static const Node *parse(InputType &input, const InputType &end) {
        return N::need_specialization();
    }
};

template <class TAG = TagNormal>
using RuleItemSpace = RuleItemSpace<RuleDef, TAG>;

template <class KW, class TAG = TagNormal>
using RuleItemKeyword = RuleItemKeyword<RuleDef, KW, TAG>;

template <class N, class TAG = TagNormal>
using RuleItemRef = RuleItemRef<RuleDef, N, TAG>;

// generated by MyParser C++ Code Generator: begin

template<>
class RuleDef<MP_STR("root", 4)>:
public RuleList<MP_STR("root", 4),
    RuleLine<
        RuleItemSpace<>,
        RuleItemRef<MP_STR("program", 7)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>,
        RuleItemSpace<>
    >,
    RuleLine<
        RuleItemSpace<>,
        RuleItemRef<MP_STR("program", 7)>,
        RuleItemSpace<>
    >
> {};

template<>
class RuleDef<MP_STR("program", 7)>:
public RuleList<MP_STR("program", 7),
    RuleLine<
        RuleItemKeyword<MP_STR("program", 7)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("function proto", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("main body", 9)>
    >
> {};

template<>
class RuleDef<MP_STR("function", 8)>:
public RuleList<MP_STR("function", 8),
    RuleLine<
        RuleItemKeyword<MP_STR("function", 8)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("function proto", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("main body", 9)>
    >
> {};

template<>
class RuleDef<MP_STR("class", 5)>:
public RuleList<MP_STR("class", 5),
    RuleLine<
        RuleItemKeyword<MP_STR("class", 5)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("main body", 9)>
    >
> {};

template<>
class RuleDef<MP_STR("main body", 9)>:
public RuleList<MP_STR("main body", 9),
    RuleLine<
        RuleItemRef<MP_STR("extend", 6)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("interface block", 15)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("code block", 10)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("main end", 8)>
    >
> {};

template<>
class RuleDef<MP_STR("extend", 6)>:
public RuleList<MP_STR("extend", 6),
    RuleLine<
        RuleItemKeyword<MP_STR("extends", 7)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("typename id", 11)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("interface block", 15)>:
public RuleList<MP_STR("interface block", 15),
    RuleLine<
        RuleItemRef<MP_STR("definition", 10)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("interface block", 15)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("is block", 8)>:
public RuleList<MP_STR("is block", 8),
    RuleLine<
        RuleItemKeyword<MP_STR("is", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("value block", 11)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("value block", 11)>:
public RuleList<MP_STR("value block", 11),
    RuleLine<
        RuleItemRef<MP_STR("value definition", 16)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("value block", 11)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("code block", 10)>:
public RuleList<MP_STR("code block", 10),
    RuleLine<
        RuleItemKeyword<MP_STR("begin", 5)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("main end", 8)>:
public RuleList<MP_STR("main end", 8),
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("program", 7)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("function id", 11)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("function", 8)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("function id", 11)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("class", 5)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>
    >
> {};

template<>
class RuleDef<MP_STR("function proto", 14)>:
public RuleList<MP_STR("function proto", 14),
    RuleLine<
        RuleItemRef<MP_STR("function id", 11)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("(", 1)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("argument list", 13)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(")", 1)>
    >
> {};

template<>
class RuleDef<MP_STR("argument list", 13)>:
public RuleList<MP_STR("argument list", 13),
    RuleLine<
        RuleItemRef<MP_STR("value id", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(",", 1)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("argument list", 13)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("value id", 8)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("definition", 10)>:
public RuleList<MP_STR("definition", 10),
    RuleLine<
        RuleItemRef<MP_STR("type definition", 15)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("value definition", 16)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("return definition", 17)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("program", 7)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("function", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR(";", 1)>
    >
> {};

template<>
class RuleDef<MP_STR("type definition", 15)>:
public RuleList<MP_STR("type definition", 15),
    RuleLine<
        RuleItemKeyword<MP_STR("type", 4)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("typename id", 11)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("is", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("type id", 7)>
    >
> {};

template<>
class RuleDef<MP_STR("value definition", 16)>:
public RuleList<MP_STR("value definition", 16),
    RuleLine<
        RuleItemRef<MP_STR("var definition", 14)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("const definition", 16)>
    >
> {};

template<>
class RuleDef<MP_STR("var definition", 14)>:
public RuleList<MP_STR("var definition", 14),
    RuleLine<
        RuleItemKeyword<MP_STR("var", 3)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("value id", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("is", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("type id", 7)>
    >
> {};

template<>
class RuleDef<MP_STR("const definition", 16)>:
public RuleList<MP_STR("const definition", 16),
    RuleLine<
        RuleItemKeyword<MP_STR("const", 5)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("value id", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("is", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("type id", 7)>
    >
> {};

template<>
class RuleDef<MP_STR("return definition", 17)>:
public RuleList<MP_STR("return definition", 17),
    RuleLine<
        RuleItemKeyword<MP_STR("return", 6)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("type id", 7)>
    >
> {};

template<>
class RuleDef<MP_STR("statement", 9)>:
public RuleList<MP_STR("statement", 9),
    RuleLine<
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("assignment", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("inherit", 7)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("return", 6)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("structure", 9)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("repeat", 6)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(";", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR(";", 1)>
    >
> {};

template<>
class RuleDef<MP_STR("assignment", 10)>:
public RuleList<MP_STR("assignment", 10),
    RuleLine<
        RuleItemRef<MP_STR("variable", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(":=", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>
    >
> {};

template<>
class RuleDef<MP_STR("inherit", 7)>:
public RuleList<MP_STR("inherit", 7),
    RuleLine<
        RuleItemKeyword<MP_STR("inherit", 7)>
    >
> {};

template<>
class RuleDef<MP_STR("return", 6)>:
public RuleList<MP_STR("return", 6),
    RuleLine<
        RuleItemKeyword<MP_STR("return", 6)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>
    >
> {};

template<>
class RuleDef<MP_STR("statement list", 14)>:
public RuleList<MP_STR("statement list", 14),
    RuleLine<
        RuleItemRef<MP_STR("statement", 9)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("structure", 9)>:
public RuleList<MP_STR("structure", 9),
    RuleLine<
        RuleItemKeyword<MP_STR("if", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("then", 4)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("condition chain", 15)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("structure end", 13)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("for", 3)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("variable", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(":=", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("for range", 9)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("do", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("structure end", 13)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("foreach", 7)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("variable", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("in", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("do", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("structure end", 13)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("while", 5)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("do", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("structure end", 13)>
    >
> {};

template<>
class RuleDef<MP_STR("condition chain", 15)>:
public RuleList<MP_STR("condition chain", 15),
    RuleLine<
        RuleItemKeyword<MP_STR("elif", 4)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("then", 4)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("condition chain", 15)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("else", 4)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("for range", 9)>:
public RuleList<MP_STR("for range", 9),
    RuleLine<
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("to", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("downto", 6)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>
    >
> {};

template<>
class RuleDef<MP_STR("structure end", 13)>:
public RuleList<MP_STR("structure end", 13),
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("if", 2)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("for", 3)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("foreach", 7)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("while", 5)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("end", 3)>
    >
> {};

template<>
class RuleDef<MP_STR("repeat", 6)>:
public RuleList<MP_STR("repeat", 6),
    RuleLine<
        RuleItemKeyword<MP_STR("repeat", 6)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("statement list", 14)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("until", 5)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>
    >
> {};

template<>
class RuleDef<MP_STR("variable", 8)>:
public RuleList<MP_STR("variable", 8),
    RuleLine<
        RuleItemRef<MP_STR("value id", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(".", 1)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("variable", 8)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("value id", 8)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("[", 1)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("]", 1)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("value id", 8)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("expression", 10)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("relation", 8)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("additive expression", 19)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("additive expression", 19)>
    >
> {};

template<>
class RuleDef<MP_STR("expression", 10)>:
public RuleList<MP_STR("expression", 10),
    RuleLine<
        RuleItemRef<MP_STR("relative expression", 19)>
    >
> {};

template<>
class RuleDef<MP_STR("relative expression", 19)>:
public RuleList<MP_STR("relative expression", 19),
    RuleLine<
        RuleItemRef<MP_STR("additive expression", 19)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("relation operation", 18)>
    >
> {};

template<>
class RuleDef<MP_STR("relative operation", 18)>:
public RuleList<MP_STR("relative operation", 18),
    RuleLine<
        RuleItemRef<MP_STR("relation", 8)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("relative expression", 19)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("additive expression", 19)>:
public RuleList<MP_STR("additive expression", 19),
    RuleLine<
        RuleItemRef<MP_STR("multiplicative expression", 25)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("additive operation", 18)>
    >
> {};

template<>
class RuleDef<MP_STR("additive operation", 18)>:
public RuleList<MP_STR("additive operation", 18),
    RuleLine<
        RuleItemRef<MP_STR("addition", 8)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("additive expression", 19)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("multiplicative expression", 25)>:
public RuleList<MP_STR("multiplicative expression", 25),
    RuleLine<
        RuleItemRef<MP_STR("unary expression", 16)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("multiplicative operation", 24)>
    >
> {};

template<>
class RuleDef<MP_STR("multiplicative operation", 24)>:
public RuleList<MP_STR("multiplicative operation", 24),
    RuleLine<
        RuleItemRef<MP_STR("multiplication", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("multiplicative expression", 25)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("unary expression", 16)>:
public RuleList<MP_STR("unary expression", 16),
    RuleLine<
        RuleItemRef<MP_STR("unary operator", 14)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("unary expression", 16)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("literal", 7)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("variable", 8)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("argument expression", 19)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("variable", 8)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("[", 1)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression list", 15)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("]", 1)>
    >
> {};

template<>
class RuleDef<MP_STR("argument expression", 19)>:
public RuleList<MP_STR("argument expression", 19),
    RuleLine<
        RuleItemRef<MP_STR("unary expression", 16)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("(", 1)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression list", 15)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(")", 1)>
    >
> {};

template<>
class RuleDef<MP_STR("expression list", 15)>:
public RuleList<MP_STR("expression list", 15),
    RuleLine<
        RuleItemRef<MP_STR("expression", 10)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR(",", 1)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("expression list", 15)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("expression", 10)>
    >,
    RuleLine<
        
    >
> {};

template<>
class RuleDef<MP_STR("type id", 7)>:
public RuleList<MP_STR("type id", 7),
    RuleLine<
        RuleItemRef<MP_STR("class", 5)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("array", 5)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("native type", 11)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("typename id", 11)>
    >
> {};

template<>
class RuleDef<MP_STR("typename id", 11)>:
public RuleList<MP_STR("typename id", 11),
    RuleLine<
        RuleItemRef<MP_STR("id", 2)>
    >
> {};

template<>
class RuleDef<MP_STR("function id", 11)>:
public RuleList<MP_STR("function id", 11),
    RuleLine<
        RuleItemRef<MP_STR("id", 2)>
    >
> {};

template<>
class RuleDef<MP_STR("value id", 8)>:
public RuleList<MP_STR("value id", 8),
    RuleLine<
        RuleItemRef<MP_STR("id", 2)>
    >
> {};

template<>
class RuleDef<MP_STR("id", 2)>:
public RuleRegex<MP_STR("id", 2),
    MP_STR("[A-Za-z_][A-Za-z0-9_]*", 22)
> {};

template<>
class RuleDef<MP_STR("array", 5)>:
public RuleList<MP_STR("array", 5),
    RuleLine<
        RuleItemKeyword<MP_STR("array", 5)>,
        RuleItemSpace<>,
        RuleItemKeyword<MP_STR("of", 2)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("integer", 7)>,
        RuleItemSpace<>,
        RuleItemRef<MP_STR("type id", 7)>
    >
> {};

template<>
class RuleDef<MP_STR("native type", 11)>:
public RuleList<MP_STR("native type", 11),
    RuleLine<
        RuleItemKeyword<MP_STR("boolean", 7)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("integer", 7)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("real", 4)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("string", 6)>
    >
> {};

template<>
class RuleDef<MP_STR("relation", 8)>:
public RuleList<MP_STR("relation", 8),
    RuleLine<
        RuleItemKeyword<MP_STR("in", 2)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("comparison", 10)>
    >
> {};

template<>
class RuleDef<MP_STR("comparison", 10)>:
public RuleRegex<MP_STR("comparison", 10),
    MP_STR("<|=|>|<=|=<|<>|><|>=|=>", 23)
> {};

template<>
class RuleDef<MP_STR("addition", 8)>:
public RuleList<MP_STR("addition", 8),
    RuleLine<
        RuleItemKeyword<MP_STR("+", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("-", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("or", 2)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("xor", 3)>
    >
> {};

template<>
class RuleDef<MP_STR("multiplication", 14)>:
public RuleList<MP_STR("multiplication", 14),
    RuleLine<
        RuleItemKeyword<MP_STR("*", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("/", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("div", 3)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("mod", 3)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("and", 3)>
    >
> {};

template<>
class RuleDef<MP_STR("unary operator", 14)>:
public RuleList<MP_STR("unary operator", 14),
    RuleLine<
        RuleItemKeyword<MP_STR("+", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("-", 1)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("not", 3)>
    >
> {};

template<>
class RuleDef<MP_STR("literal", 7)>:
public RuleList<MP_STR("literal", 7),
    RuleLine<
        RuleItemRef<MP_STR("boolean", 7)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("integer", 7)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("real", 4)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("string", 6)>
    >
> {};

template<>
class RuleDef<MP_STR("boolean", 7)>:
public RuleList<MP_STR("boolean", 7),
    RuleLine<
        RuleItemKeyword<MP_STR("yes", 3)>
    >,
    RuleLine<
        RuleItemKeyword<MP_STR("no", 2)>
    >
> {};

template<>
class RuleDef<MP_STR("integer", 7)>:
public RuleRegex<MP_STR("integer", 7),
    MP_STR("[0-9]+", 6)
> {};

template<>
class RuleDef<MP_STR("real", 4)>:
public RuleRegex<MP_STR("real", 4),
    MP_STR("[0-9]*\\.[0-9]+([Ee][\\+-]?[0-9]+)?", 33)
> {};

template<>
class RuleDef<MP_STR("string", 6)>:
public RuleRegex<MP_STR("string", 6),
    MP_STR("\"([^\\\\]|\\\\.)*\"", 14)
> {};

template<>
class RuleDef<MP_STR("space", 5)>:
public RuleList<MP_STR("space", 5),
    RuleLine<
        RuleItemRef<MP_STR("ignored", 7)>
    >
> {};

template<>
class RuleDef<MP_STR("keyword", 7)>:
public RuleList<MP_STR("keyword", 7),
    RuleLine<
        RuleItemRef<MP_STR("id", 2)>
    >,
    RuleLine<
        RuleItemRef<MP_STR("sign", 4)>
    >
> {};

template<>
class RuleDef<MP_STR("sign", 4)>:
public RuleRegex<MP_STR("sign", 4),
    MP_STR("[\\(\\)\\[\\],.+\\-*\\/;]|:=", 22)
> {};

template<>
class RuleDef<MP_STR("ignored", 7)>:
public RuleRegex<MP_STR("ignored", 7),
    MP_STR("([ \\t\\n]|\\/\\/.*$)*", 18)
> {};

}

// generated by MyParser C++ Code Generator: end

#endif
