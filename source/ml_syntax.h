#ifndef ML_SYNTAX_H
#define ML_SYNTAX_H

#include <string>
#include <regex>

#include "ml_ast.h"

namespace mylang {

using InputType = std::string::iterator;

const char rule_root[] = "root";
const char rule_space[] = "space";
const char rule_keyword[] = "keyword";

class Node;

class Rule {
protected:
    inline Rule() {} // force singleton

public:
    virtual const std::string &getName() const = 0;
};

template <const char *N>
class RuleNamed: public Rule {
public:
    virtual const std::string &getName() const {
        static const std::string name(N);

        return name;
    }
};

// need specialization
template <const char *N, class T = void>
class GetRule: public RuleNamed<N> {
public:
    static const Node *parse(InputType &input, const InputType &end) {
        return T::need_specialization();
    }
};

//////// Named ////////

template <const char *N, class... RL>
class RuleList: public RuleNamed<N> {
public:
    static const RuleList<N, RL...> instance;

private:
    template <class R, class... Rx>
    static inline const Node *runRule(
        InputType &input, const InputType &end
    ) {
        InputType input_new = input;

        using Member =
            typename R
            ::template Helper<RuleList<N, RL...>>;

        Node *current = Member::parse(input_new, end);

        if (current) {
            input = input_new;

            return current;
        } else {
            return runRule<Rx...>(input, end);
        }
    }

    template <class T = void> // iteration finished
    static inline const Node *runRule(
        InputType &input, const InputType &end
    ) {
        return nullptr;
    }

public:
    static const Node *parse(InputType &input, const InputType &end) {
        return runRule<RL...>(input, end);
    }
};

template <const char *N, class... RL>
using RuleBuiltin = RuleList<N, RL...>;

template <const char *N, const char *RX>
class RuleRegex: public RuleNamed<N> {
public:
    static const RuleRegex<N, RX> instance;

    using ResultType = NodeTextTyped<instance>;

private:
    static inline const ResultType *runRegex(
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
    static const Node *parse(InputType &input, const InputType &end) {
        return runRegex(input, end);
    }
};

//////// Cell ////////

template <class T = void> // actually not a template
class RuleSpace: public Rule {
public:
    static const RuleSpace<T> instance;

    static const Node *parse(InputType &input, const InputType &end) {
        return GetRule<rule_space>::parse(input, end);
    }
};

template <const char *KW>
class RuleKeyword: public Rule {
public:
    static const RuleKeyword<KW> instance;

    static const Node *parse(InputType &input, const InputType &end) {
        static const std::string keyword = KW;

        return GetRule<rule_keyword>::parse(input, end);
    }
};

template <const char *N>
class RuleRef: public Rule {
public:
    static const RuleRef<N> instance;

    static const Node *parse(InputType &input, const InputType &end) {
        return GetRule<N>::parse(input, end);
    }
};

template <const char *E>
class RuleError: public Rule {
public:
    static const RuleError<E> instance;

    static const Node *parse(InputType &input, const InputType &end) {
        static const std::string error = E;

        throw E; // TODO: exception class
    }
};

template <class... RL>
class RuleLine {
public:
    template <class LST>
    class Helper: public Rule {
    public:
        static const Helper<RL...> instance;

        using ResultType = NodeListTyped<LST::instance>;

    private:
        template <class R, class... Rx>
        static inline bool runRule(
            ResultType *&result, InputType &input, const InputType &end
        ) {
            Node *current = R::instance::parse(input, end);

            result->putChild(current);

            return current && runRule<Rx...>(result, input, end);
        }

        template <class T = void> // iteration finished
        static inline bool runRule(
            ResultType *&result, InputType &input, const InputType &end
        ) {
            return true;
        }

    public:
        static const Node *parse(InputType &input, const InputType &end) {
            ResultType *result = new ResultType();

            if (runRule<RL...>(result, input, end)) {
                return result;
            } else {
                delete result;

                return nullptr;
            }
        }
    };
};

}

#endif
