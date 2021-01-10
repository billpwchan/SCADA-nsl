/* -*- c++ -*- */
//
// $Id: root_ch.h 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    root_ch.h
//
// = DESCRIPTION
//    Concrete visitor for the Root class
//    This one provides code generation for elements of the Root node in the
//    client header.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#ifndef _BE_VISITOR_ROOT_ROOT_CH_H_
#define _BE_VISITOR_ROOT_ROOT_CH_H_

class be_visitor_root_ch : public be_visitor_root
{
  //
  // = TITLE
  //   be_visitor_root_ch
  //
  // = DESCRIPTION
  //   This is a concrete visitor to generate the client header for root
  //
  //
public:
  be_visitor_root_ch (be_visitor_context *ctx);
  // constructor

  ~be_visitor_root_ch (void);
  // destructor

  virtual int init (void);
  // set the right context and make a visitor
};

#endif /* _BE_VISITOR_ROOT_ROOT_CH_H_ */