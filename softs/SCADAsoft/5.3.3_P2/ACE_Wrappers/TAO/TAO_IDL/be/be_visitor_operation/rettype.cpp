//
// $Id: rettype.cpp 14 2007-02-01 15:49:12Z mitza $
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    rettype.cpp
//
// = DESCRIPTION
//    Visitor generating code for return type of the Operation node
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_operation, 
           rettype, 
           "$Id: rettype.cpp 14 2007-02-01 15:49:12Z mitza $")


// ****************************************************************************
// Operation visitor for return types. This generates the mapping for a return
// type in an operation signature
// ****************************************************************************

be_visitor_operation_rettype::be_visitor_operation_rettype (be_visitor_context
                                                            *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_operation_rettype::~be_visitor_operation_rettype (void)
{
}

int
be_visitor_operation_rettype::visit_array (be_array *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << "_slice *";

  return 0;
}

int
be_visitor_operation_rettype::visit_enum (be_enum *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name ();

  return 0;
}

int
be_visitor_operation_rettype::visit_interface (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << "_ptr";

  return 0;
}

int
be_visitor_operation_rettype::visit_interface_fwd (be_interface_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << "_ptr";

  return 0;
}

int
be_visitor_operation_rettype::visit_native (be_native *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name ();

  return 0;
}

int
be_visitor_operation_rettype::visit_predefined_type (be_predefined_type *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }
  
  AST_PredefinedType::PredefinedType pt = node->pt ();
  
  if (pt != AST_PredefinedType::PT_void)
    {
      *os << "::";
    }

  switch (pt)
    {
    case AST_PredefinedType::PT_pseudo:
    case AST_PredefinedType::PT_object:
    case AST_PredefinedType::PT_abstract:
      *os << bt->name ();

      // If it's not TCKind, it's either Object, TypeCode or ValueBase.
      if (ACE_OS::strcmp (bt->local_name ()->get_string (), "TCKind") != 0)
        {
          *os << "_ptr";
        }

      break;
    case AST_PredefinedType::PT_any:
    case AST_PredefinedType::PT_value:
      {
        *os << bt->name () << " *";

        break;
      }
    default:
      {
        *os << bt->name ();

        break;
      }
    }

  return 0;
}

int
be_visitor_operation_rettype::visit_sequence (be_sequence *node)
{
  // We should never directly be here because anonymous sequence return types
  // are not allowed.
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << " *";

  return 0;
}

int
be_visitor_operation_rettype::visit_string (be_string *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  if (node->width () == (long) sizeof (char))
    {
      *os << "char *";
    }
  else
    {
      *os << "::CORBA::WChar *";
    }

  return 0;
}

int
be_visitor_operation_rettype::visit_structure (be_structure *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name ();

  // Based on whether we are variable or not, we return a pointer or the
  // aggregate type.
  if (node->size_type () == AST_Type::VARIABLE)
    {
      *os << " *";
    }

  return 0;
}

int
be_visitor_operation_rettype::visit_typedef (be_typedef *node)
{
  // Set the alias node.
  this->ctx_->alias (node);

  if (node->primitive_base_type ()->accept (this) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_operation_rettype::"
                         "visit_typedef - "
                         "accept on primitive type failed\n"),
                        -1);
    }

  this->ctx_->alias (0);
  return 0;
}

int
be_visitor_operation_rettype::visit_union (be_union *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name ();

  // Based on whether we are variable or not, we return a pointer or the
  // aggregate type.
  if (node->size_type () == AST_Type::VARIABLE)
    {
      *os << " *";
    }

  return 0;
}

int
be_visitor_operation_rettype::visit_valuetype (be_valuetype *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << " *";

  return 0;
}

int
be_visitor_operation_rettype::visit_valuetype_fwd (be_valuetype_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << " *";

  return 0;
}

int
be_visitor_operation_rettype::visit_component (be_component *node)
{
  return this->visit_interface (node);
}

int
be_visitor_operation_rettype::visit_component_fwd (be_component_fwd *node)
{
  return this->visit_interface_fwd (node);
}

int
be_visitor_operation_rettype::visit_eventtype (be_eventtype *node)
{
  return this->visit_valuetype (node);
}

int
be_visitor_operation_rettype::visit_eventtype_fwd (be_eventtype_fwd *node)
{
  return this->visit_valuetype_fwd (node);
}

int
be_visitor_operation_rettype::visit_home (be_home *node)
{
  return this->visit_interface (node);
}

int
be_visitor_operation_rettype::visit_valuebox (be_valuebox *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << " *";

  return 0;
}