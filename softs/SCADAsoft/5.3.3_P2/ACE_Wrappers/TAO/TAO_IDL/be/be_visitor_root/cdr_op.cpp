//
// $Id: cdr_op.cpp 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    cdr_op.cpp
//
// = DESCRIPTION
//    Visitor generating code for the CDR operators for types defined
//    in Root's scope.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_root, 
           cdr_op, 
           "$Id: cdr_op.cpp 14 2007-02-01 15:49:12Z mitza $")

// ***************************************************************************
// Root visitor for generating CDR operator declarations in the client header
// and stub
// ***************************************************************************

be_visitor_root_cdr_op::be_visitor_root_cdr_op (be_visitor_context *ctx)
  : be_visitor_root (ctx)
{
}

be_visitor_root_cdr_op::~be_visitor_root_cdr_op (void)
{
}

int
be_visitor_root_cdr_op::visit_root (be_root *node)
{
  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_root_cdr_op::visit_root - "
                         "codegen for scope failed\n"), 
                        -1);
    }

  return 0;
}