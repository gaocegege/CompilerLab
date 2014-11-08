#ifndef ML_SYNTAX_H
#define ML_SYNTAX_H

#include <string>

#include "ml_ast.h"

namespace mylang {

class Node;

class Rule {
protected:
    inline Rule() {} // force singleton

public:
    virtual std::string &getName() = 0;
};

//////// Named ////////

template <char *N>
class RuleNamed: public Rule {
public:
    virtual std::string &getName() {
        static std::string name(N);

        return name;
    }
};

template <char *N, class... RL>
class RuleList: public RuleNamed<N> {
public:
    static RuleList<N, RL...> instance;

    Node *parse(std::string::iterator &input) {
        //
    }
};

template <char *N, char *RX>
class RuleRegex: public RuleNamed<N> {
public:
    static RuleRegex<N, RX> instance;

    Node *parse(std::string::iterator &input) {
        //
    }
};

//////// Cell ////////

template <char *KW>
class RuleKeyword: public Rule {
public:
    static RuleKeyword<KW> instance;

    Node *parse(std::string::iterator &input) {
        //
    }
};

template <class R>
using RuleRef = R;

template <char *E>
class RuleError: public Rule {
public:
    static RuleError<E> instance;

    Node *parse(std::string::iterator &input) {
        //
    }
};

template <class... R>
class RuleLine: public Rule {
public:
    static RuleLine<R...> instance;

    Node *parse(std::string::iterator &input) {
        //
    }
};

}

#endif
