//
// $Id: ami_interface_ch.cpp 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    ami_interface_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for AMI Interfaces in the client header
//
// = AUTHOR
//    Aniruddha Gokhale,
//    Michael Kircher
//
// ============================================================================

ACE_RCSID (be_visitor_interface, 
           ami_interface_ch, 
           "$Id: ami_interface_ch.cpp 14 2007-02-01 15:49:12Z mitza $")

// ******************************************************
// Interface visitor for client header
// ******************************************************

be_visitor_ami_interface_ch::be_visitor_ami_interface_ch (
    be_visitor_context *ctx
  )
  : be_visitor_interface (ctx)
{
}

be_visitor_ami_interface_ch::~be_visitor_ami_interface_ch (void)
{
}

int
be_visitor_ami_interface_ch::visit_interface (be_interface *node)
{
  // No need to check for code already having been generated. This
  // is a separate pass through the AST specific to AMI, and will
  // happen only once.
  if (node->imported () || node->is_local ())
    {
      return 0;
    }

  // Grab the stream.
  TAO_OutStream *os = this->ctx_->stream ();
  os->gen_ifdef_macro (node->replacement ()->flat_name (), "_ptr");

  // Forward declaration.
  *os << be_nl << be_nl 
      << "class " << node->replacement ()->local_name () << ";" << be_nl;

  // Generate the _ptr declaration.
  *os << "typedef " << node->replacement ()->local_name ()
      << " *" << node->replacement ()->local_name ()
      << "_ptr;";

  os->gen_endif ();
  return 0;
}
