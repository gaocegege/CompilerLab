#ifndef ML_SYNTAX_H
#define ML_SYNTAX_H

#include <string>

#include "ml_ast.h"

namespace mylang {

class Node;

class Rule {
public:
    virtual std::string &getName() = delete;

    virtual Node *parse(std::string::iterator &input) = delete;
};

template <char *N>
class RuleNamed: public Rule {
private:
    static std::string name = N;

public:
    virtual std::string &getName() {
        return name;
    }
};

template <char *KW>
class RuleKeyword: public Rule {
public:
    virtual Node *parse(std::string::iterator &input) {
        //
    }
};

/*template <Rule *R>
class RuleRef: public Rule {
public:
    virtual Node *parse(std::string::iterator &input) {
        //
    }
};*/

template <char *E>
class RuleError: public Rule {
public:
    virtual Node *parse(std::string::iterator &input) {
        //
    }
};

template <Rule... *R>
class RuleLine: public Rule {
public:
    virtual Node *parse(std::string::iterator &input) {
        //
    }
};

template <char *N, RuleLine... *RL>
class RuleList: public RuleNamed<N> {
public:
    virtual Node *parse(std::string::iterator &input) {
        //
    }
};

template <char *N, char *RX>
class RuleRegex: public RuleNamed<N> {
public:
    virtual Node *parse(std::string::iterator &input) {
        //
    }
};

}

#endif
