#ifndef MYLANG_CONST_HPP
#define MYLANG_CONST_HPP

#include <string>

namespace mylang {

// type

using ml_real = double;
using ml_integer = long;
using ml_byte = char;

// operators

const auto name_assign = "__assign";
const auto name_assign_add = "__assign_add";
const auto name_assign_sub = "__assign_sub";
const auto name_assign_mul = "__assign_mul";
const auto name_assign_div = "__assign_div";

const auto name_equal = "__equal";
const auto name_less_equal = "__less_equal";
const auto name_greater_equal = "__greater_equal";
const auto name_not_equal = "__not_equal";
const auto name_less = "__less";
const auto name_greater = "__greater";
const auto name_in = "__in";

const auto name_add = "__add";
const auto name_sub = "__sub";
const auto name_or = "__or";
const auto name_xor = "__xor";

const auto name_mul = "__mul";
const auto name_div = "__div";
const auto name_mod = "__mod";
const auto name_and = "__and";
const auto name_shl = "__shl";
const auto name_shr = "__shr";
const auto name_rol = "__rol";
const auto name_ror = "__ror";

const auto name_pos = "__pos";
const auto name_neg = "__neg";
const auto name_not = "__not";

const auto name_prev = "__prev"; // TODO
const auto name_next = "__next"; // TODO

// builtin interfaces

const auto name_array = "__array"; // arg: (...)
// jump in the same block
const auto name_goto = "__goto"; // arg: (tag)
const auto name_branch = "__branch"; // arg: (tag, cond) // if !cond then goto(tag)
// jump with block switch
const auto name_call = "__call"; // arg: (obj)

// values

const auto name_self = "__self"; // TODO
const auto name_parent = "__parent"; // TODO
const auto name_input = "__input"; // receive
const auto name_result = "__result"; // return

}

#endif
