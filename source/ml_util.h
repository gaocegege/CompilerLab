#ifndef ML_UTIL_H
#define ML_UTIL_H

#include <string>

namespace mylang {

template <char... C>
class StaticStr {
public:
    static inline const std::string &getStr() {
        static const std::string stdstr = {C...};

        return stdstr;
    }
};

constexpr size_t ssSize(const char *str) {
    return str[0] ? (ssSize(str + 1) + 1) : 0;
}

}

#endif
