//
// $Id: valuetype_init.cpp 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuetype_init.cpp
//
// = DESCRIPTION
//    Coomon visitor for valuetypes factory construct
//    (see IDL to C++ mapping). Based on ptc/00-01-02.
//
// = AUTHOR
//   Boris Kolpackov <bosk@ipmce.ru>
//
//
// ============================================================================

ACE_RCSID (be_visitor_valuetype, 
           valuetype_init, 
           "$Id: valuetype_init.cpp 14 2007-02-01 15:49:12Z mitza $")

be_visitor_valuetype_init::be_visitor_valuetype_init (
    be_visitor_context *ctx
  )
  : be_visitor_valuetype (ctx)
{
}

be_visitor_valuetype_init::~be_visitor_valuetype_init (void)
{
}

void
be_visitor_valuetype_init::begin_public (void)
{
}

void
be_visitor_valuetype_init::begin_private (void)
{
}
