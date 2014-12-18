#ifndef MYLANG_ANALYSIS_CALL_HPP
#define MYLANG_ANALYSIS_CALL_HPP

#include "mylang_syntax_spec.hpp"
#include "semantic/block.hpp"

namespace mylang {

// need specialization
// see the implementation of std::function
template <class>
class DelayedCall;

template <class OUT, class... IN>
class DelayedCall<OUT(IN...)> {
private:
    using Proto = OUT(IN...);

    std::function<Proto> exec;

    // instance chain: getInstance() -> holding -> ... -> nullptr
    DelayedCall<Proto> *parent;

    static inline DelayedCall<Proto> *accessInstance(
        DelayedCall<Proto> *value = nullptr
    ) {
        // WARNING: thread_local
        static thread_local DelayedCall<Proto> *instance = nullptr;

        if (value) {
            std::swap(instance, value);
            return value;
        } else {
            return instance;
        }
    }

    // no dynamic allocation
    inline void *operator new(size_t) = delete;
    inline void operator delete(void *) = delete;

public:
    inline DelayedCall(): exec(nullptr), parent(accessInstance(this)) {}

    // notice: delete by pointer is not allowed
    ~DelayedCall() {
        //accessInstance(parent);
    }

    static inline void put(std::function<Proto> &&func) {
        accessInstance()->exec = std::move(func);
    }

    inline operator bool() const {
        return accessInstance();
    }

    inline OUT operator()(IN... arg) const {
        // TODO: if exec == nullptr, error
        return exec(std::forward<IN>(arg)...);
    }
};

}

#endif
