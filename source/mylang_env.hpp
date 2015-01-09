#ifndef MYLANG_ENV_HPP
#define MYLANG_ENV_HPP

#include "semantic/block.hpp"
#include "mylang_const.hpp"

namespace mylang {

libblock::Block *makeEnv() {
    // root block
    libblock::Block *block = new libblock::Block();

    // TODO: add builtin

    block->finish();

    return block;
}

}

#endif
