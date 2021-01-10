/* -*- c++ -*- */
// $Id: be_util.h 14 2007-02-01 15:49:12Z mitza $

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_util.h
//
// = DESCRIPTION
//    Static helper methods used by multiple visitors.
//
// = AUTHOR
//    Gary Maxey
//
// ============================================================================

#ifndef TAO_BE_UTIL_H
#define TAO_BE_UTIL_H

#include "be_helper.h"
#include "be_module.h"

class be_util
{
 public:
  static void gen_nested_namespace_begin (TAO_OutStream *os, be_module *node);

  static void gen_nested_namespace_end (TAO_OutStream *os, be_module *node);

};


#endif // if !defined

