//
// $Id: exception_ci.cpp 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    exception_ci.cpp
//
// = DESCRIPTION
//    Visitor generating code for Exception in the inline file.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_exception, 
           exception_ci, 
           "$Id: exception_ci.cpp 14 2007-02-01 15:49:12Z mitza $")


// ******************************************************
// for client inline
// ******************************************************

be_visitor_exception_ci::be_visitor_exception_ci (be_visitor_context *ctx)
  : be_visitor_exception (ctx)
{
}

be_visitor_exception_ci::~be_visitor_exception_ci (void)
{
}

// visit the Exception node and its scope
int be_visitor_exception_ci::visit_exception (be_exception *node)
{
  if (node->cli_inline_gen () || node->imported ())
    {
      return 0;
    }

  // Generate inline code  required of any anonymous types of members.
  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_exception::"
                         "visit_exception -"
                         "code for inline failed\n"), 
                        -1);
    }

  node->cli_inline_gen (true);
  return 0;
}