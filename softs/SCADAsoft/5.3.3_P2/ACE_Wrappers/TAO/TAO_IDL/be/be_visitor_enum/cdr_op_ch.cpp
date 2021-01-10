//
// $Id: cdr_op_ch.cpp 935 2008-12-10 21:47:27Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    cdr_op_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for Enums for the CDR operators
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_enum,
           cdr_op_ch,
           "$Id: cdr_op_ch.cpp 935 2008-12-10 21:47:27Z mitza $")


// ***************************************************************************
// Enum visitor for generating Cdr operator declarations in the client header
// ***************************************************************************

be_visitor_enum_cdr_op_ch::be_visitor_enum_cdr_op_ch (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_enum_cdr_op_ch::~be_visitor_enum_cdr_op_ch (void)
{
}

int
be_visitor_enum_cdr_op_ch::visit_enum (be_enum *node)
{
  if (node->cli_hdr_cdr_op_gen () || node->imported ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  *os << be_global->core_versioning_begin () << be_nl;

  // Generate the CDR << and >> operators.
  *os << be_global->stub_export_macro () << " ::CORBA::Boolean"
      << " operator<< (TAO_OutputCDR &strm, " << node->name ()
      << " _tao_enumerator);" << be_nl;
  *os << be_global->stub_export_macro () << " ::CORBA::Boolean"
      << " operator>> (TAO_InputCDR &strm, " << node->name ()
      << " &_tao_enumerator);" << be_nl;
      
  if (be_global->gen_ostream_operators ())
    {
      *os << be_nl
          << be_global->stub_export_macro () << " std::ostream&"
          << " operator<< (std::ostream &strm, const " << node->name ()
          << " _tao_enumerator);" << be_nl;
    }

  *os << be_global->core_versioning_end () << be_nl;

  node->cli_hdr_cdr_op_gen (true);
  return 0;
}