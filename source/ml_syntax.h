#ifndef ML_SYNTAX_H
#define ML_SYNTAX_H

#include <string>
#include <regex>

#include "ml_ast.h"

namespace mylang {

using InputType = std::string::iterator;

class Node;

class Rule {
protected:
    inline Rule() {} // force singleton

public:
    virtual const std::string &getName() const = 0;
};

//////// Named ////////

template <char *N>
class RuleNamed: public Rule {
public:
    virtual const std::string &getName() const {
        static const std::string name(N);

        return name;
    }
};

template <char *N, class... RL>
class RuleList: public RuleNamed<N> {
public:
    static const RuleList<N, RL...> instance;

private:
    template <class R, class... Rx>
    inline const Node *runRule(
        InputType &input, const InputType &end
    ) {
        Node *current = R::instance::parse(input, end);

        return current ? current : runRule<Rx...>(input, end);
    }

    template <std::nullptr_t helper = nullptr> // iteration finished
    inline const Node *runRule(
        InputType &input, const InputType &end
    ) {
        return nullptr;
    }

public:
    const Node *parse(InputType &input, const InputType &end) const {
        return runRule<RL...>(input, end);
    }
};

template <char *N, class... RL>
using RuleBuiltin = RuleList<N, RL...>;

template <char *N, char *RX>
class RuleRegex: public RuleNamed<N> {
public:
    static const RuleRegex<N, RX> instance;

    using ResultType = NodeTextTyped<instance>;

private:
    inline ResultType *runRegex(
        InputType &input, const InputType &end
    ) {
        static const std::regex regex(
            RX,
            std::regex_constants::extended
        );

        std::match_results<InputType> mdata;

        if (
            regex_search(
                input, end, mdata, regex,
                std::regex_constants::match_continuous
            )
        ) {
            auto str = mdata.str();
            input += str.size();

            return new ResultType(str);
        } else {
            return nullptr;
        }
    }

public:
    const Node *parse(InputType &input, const InputType &end) const {
        return runRegex(input, end);
    }
};

//////// Cell ////////

template <class R>
using RuleRef = R;

template <char *KW>
class RuleKeyword: public Rule {
public:
    static const RuleKeyword<KW> instance;

    const Node *parse(InputType &input, const InputType &end) const {
        //
    }
};

template <char *E>
class RuleError: public Rule {
public:
    static const RuleError<E> instance;

    const Node *parse(InputType &input, const InputType &end) const {
        //
    }
};

template <class... RL>
class RuleLine: public Rule {
public:
    static const RuleLine<RL...> instance;

    using ResultType = NodeListTyped<instance>;

private:
    template <class R, class... Rx>
    inline bool runRule(
        ResultType *&result, InputType &input, const InputType &end
    ) {
        Node *current = R::instance::parse(input, end);

        result->putChild(current);

        return current && runRule<Rx...>(result, input, end);
    }

    template <std::nullptr_t helper = nullptr> // iteration finished
    inline bool runRule(
        ResultType *&result, InputType &input, const InputType &end
    ) {
        return true;
    }

public:
    const Node *parse(InputType &input, const InputType &end) const {
        ResultType *result = new ResultType();

        if (runRule<RL...>(result, input, end)) {
            return result;
        } else {
            delete result;

            return nullptr;
        }
    }
};

}

#endif
