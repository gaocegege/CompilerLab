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
class DelayedCall<OUT(const IN...)> {
private:
    using Proto = OUT(const IN...);

    // instance chain
    // TODO: thread_local ???
    static thread_local DelayedCall<Proto> *instance = nullptr;

    DelayedCall<Proto> *holding;
    std::function<Proto> exec;

    // no dynamic allocation
    void *operator new(size_t) = delete;
    void operator delete(void *) = delete;

public:
    inline DelayedCall(): holding(instance), exec() {
        instance = this;
    }

    // virtual ~InfoFrame() {}

    static void put(std::function<Proto> &&func) {
        instance->exec = std::move(func);
        instance = instance->holding;
    }

    OUT operator()(const IN... arg) {
        return exec(std::forward(arg...));
    }
};

}

#endif
