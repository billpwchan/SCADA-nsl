// $Id: module_ih.cpp 14 2007-02-01 15:49:12Z mitza $

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    module_ih.cpp
//
// = DESCRIPTION
//    Visitor generating code for Module in the implementation header
//
// = AUTHOR
//    Yamuna Krishnamurthy (yamuna@cs.wustl.edu)
//
// ============================================================================

ACE_RCSID (be_visitor_module, 
           module_ih, 
           "$Id: module_ih.cpp 14 2007-02-01 15:49:12Z mitza $")

// ************************************************************
// Module visitor for server header
// ************************************************************

be_visitor_module_ih::be_visitor_module_ih (be_visitor_context *ctx)
  : be_visitor_module (ctx)
{
}

be_visitor_module_ih::~be_visitor_module_ih (void)
{
}

int
be_visitor_module_ih::visit_module (be_module *node)
{
  if (!node->impl_hdr_gen () && !node->imported ())
    {
      if (this->visit_scope (node) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_module_ih::"
                             "visit_module - "
                             "codegen for scope failed\n"), 
                            -1);
        }
    }

  return 0;
}
