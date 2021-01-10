/* -*- c++ -*- */
//
// $Id: sequence_cs.h 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    sequence_cs.h
//
// = DESCRIPTION
//    Concrete visitor for the Sequence class
//    This one provides code generation for the Sequence node in the client
//    stubs.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#ifndef _BE_VISITOR_SEQUENCE_SEQUENCE_CS_H_
#define _BE_VISITOR_SEQUENCE_SEQUENCE_CS_H_

class TAO_OutStream;
class be_visitor_sequence_cs : public be_visitor_decl
{
  //
  // = TITLE
  //    be_visitor_sequence_cs
  //
  // = DESCRIPTION
  //   This is a concrete visitor to generate the client stubs for
  //   sequences
  //
public:
  be_visitor_sequence_cs (be_visitor_context *ctx);
  // constructor

  ~be_visitor_sequence_cs (void);
  // destructor

  virtual int visit_sequence (be_sequence *node);
  // visit sequence node
};

#endif /* _BE_VISITOR_SEQUENCE_SEQUENCE_CS_H_ */
