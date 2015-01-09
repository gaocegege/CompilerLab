#ifndef MYLANG_HPP
#define MYLANG_HPP

#include "mylang_tool.hpp"
#include "mylang_syntax_spec.hpp"
#include "mylang_syntax.hpp"
#include "mylang_analysis_pass.hpp"
#include "mylang_env.hpp"

namespace mylang {

using myparser::Input;
using myparser::Pass;
using myparser::PassHighlight;
using myparser::PassReprText;
using myparser::PassReprSimple;
using myparser::PassReprFull;
using myparser::PassReprJSON;
using myparser::Node;
using myparser::Parser;

template <class TX = void> // actually not a template
using PassAnalysis = myparser::Pass<myparser::PASS_ANALYSIS>;

using libblock::CodeVisitorRepr;
using libblock::CodeVisitorInfer;
using libblock::CodeVisitorTranslate;
using libblock::CodeVisitorTranslateLLVM;

}

#endif
