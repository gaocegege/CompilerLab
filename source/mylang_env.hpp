#ifndef MYLANG_ENV_HPP
#define MYLANG_ENV_HPP

#include "semantic/block.hpp"
#include "mylang_const.hpp"

namespace mylang {

libblock::Block *makeEnv() {
    // root block
    libblock::Block *block = new libblock::Block();

    // empty proto
    libblock::Proto *proto = new libblock::Proto();

    // TODO: add builtin

    block->setProto(proto);

    block->finish();

    return block;
}

}

#endif
