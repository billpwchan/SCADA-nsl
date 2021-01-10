//
// $Id: be_union_label.cpp 935 2008-12-10 21:47:27Z mitza $
//

#include "be_union_label.h"
#include "be_visitor.h"

ACE_RCSID (be,
           be_union_label,
           "$Id: be_union_label.cpp 935 2008-12-10 21:47:27Z mitza $")

be_union_label::be_union_label (void)
  : AST_UnionLabel ()
{
}

be_union_label::be_union_label (AST_UnionLabel::UnionLabel ul,
                                AST_Expression *v)
  : AST_UnionLabel (ul, v)
{
}

int
be_union_label::accept (be_visitor *visitor)
{
  return visitor->visit_union_label (this);
}

void
be_union_label::destroy (void)
{
  this->AST_UnionLabel::destroy ();
}

