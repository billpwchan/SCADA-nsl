//
// $Id: valuebox.cpp 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuebox.cpp
//
// = DESCRIPTION
//    Visitor for generation of code for valuebox
//
// = AUTHOR
//    Gary Maxey
//
// ============================================================================

ACE_RCSID (be_visitor_valuebox,
           valuebox,
           "$Id: valuebox.cpp 14 2007-02-01 15:49:12Z mitza $")

be_visitor_valuebox::be_visitor_valuebox (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_valuebox::~be_visitor_valuebox (void)
{
}

// This method must be overridden by the derived valuebox visitors.
int
be_visitor_valuebox::visit_valuebox (be_valuebox *)
{
  return -1;
}

