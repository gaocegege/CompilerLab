#ifndef ML_SYNTAX_H
#define ML_SYNTAX_H

#include <limits>
#include <string>
#include <regex>

#include "ml_util.h"
#include "ml_ast.h"

namespace mylang {

using InputType = std::string::iterator;

using BuiltinRoot = ML_STR("root", 4);
using BuiltinSpace = ML_STR("space", 5);
using BuiltinKeyword = ML_STR("keyword", 7);

template <size_t L, size_t M>
class Tag {
public:
    static const size_t least = L;
    static const size_t most = M;
};
using TagNormal = Tag<1, 1>;
using TagMaybe = Tag<0, 1>;
using TagAny0 = Tag<0, std::numeric_limits<size_t>::max()>;
using TagAny1 = Tag<1, std::numeric_limits<size_t>::max()>;

class Rule {
protected:
    inline Rule() {} // force singleton

    // virtual ~Rule() {}

public:
    virtual const std::string &getName() const = 0;
};

template <class N>
class RuleNamed: public Rule {
public:
    virtual const std::string &getName() const {
        static const std::string name = N::getStr();

        return name;
    }
};

// need specialization
template <class N, class TX = void>
class RuleDef: public RuleNamed<N> {
public:
    static const Node *parse(InputType &input, const InputType &end) {
        return TX::need_specialization();
    }
};

//////// Named ////////

template <class N, class... RL>
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

    template <std::nullptr_t P = nullptr> // iteration finished
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

template <class N, class... RL>
using RuleBuiltin = RuleList<N, RL...>;

template <class N, class RX>
class RuleRegex: public RuleNamed<N> {
public:
    static const RuleRegex<N, RX> instance;

    using ResultType = NodeTextTyped<RuleRegex<N, RX>>;

private:
    static inline const ResultType *runRegex(
        InputType &input, const InputType &end
    ) {
        static const std::regex regex(
            RX::getStr(),
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

template <class TAG = TagNormal>
class RuleItemSpace: public TAG {
public:
    static const Node *parse(InputType &input, const InputType &end) {
        return RuleDef<BuiltinSpace>::parse(input, end);
    }
};

template <class KW, class TAG = TagNormal>
class RuleItemKeyword: public TAG {
public:
    static const Node *parse(InputType &input, const InputType &end) {
        static const std::string keyword = KW::getStr();

        const Node *result = RuleDef<BuiltinKeyword>::parse(input, end);

        if (result->getFullText() == keyword) {
            return result;
        } else {
            delete result;

            return nullptr;
        }
    }
};

template <class N, class TAG = TagNormal>
class RuleItemRef: public TAG {
public:
    static const Node *parse(InputType &input, const InputType &end) {
        return RuleDef<N>::parse(input, end);
    }
};

template <class E, class TAG = TagNormal>
class RuleItemError: public TAG {
public:
    static const Node *parse(InputType &input, const InputType &end) {
        static const std::string error = E::getStr();

        // throw E; // TODO: exception class

        return nullptr;
    }
};

template <class... RL>
class RuleLine {
public:
    template <class LST>
    class Helper {
    public:
        using ResultType = NodeListTyped<LST>;

    private:
        template <class R, class... Rx>
        static inline bool runRule(
            ResultType *&result, InputType &input, const InputType &end
        ) {
            for (size_t i = 0; i < R::most; ++i) {
                Node *current = R::parse(input, end);

                if (current) {
                    result->putChild(current);
                } else {
                    if (i < R::least) {
                        return false;
                    } else {
                        break;
                    }
                }
            }

            return runRule<Rx...>(result, input, end);
        }

        template <std::nullptr_t P = nullptr> // iteration finished
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
