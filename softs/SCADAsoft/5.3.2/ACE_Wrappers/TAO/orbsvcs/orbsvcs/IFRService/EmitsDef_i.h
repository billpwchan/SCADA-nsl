// -*- C++ -*-


//=============================================================================
/**
 *  @file    EmitsDef_i.h
 *
 *  $Id: EmitsDef_i.h 935 2008-12-10 21:47:27Z mitza $
 *
 *  EmitsDef servant class.
 *
 *
 *  @author Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_EMITSDEF_I_H
#define TAO_EMITSDEF_I_H

#include "orbsvcs/IFRService/EventPortDef_i.h"
#include "orbsvcs/IFRService/ifr_service_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_IFRService_Export TAO_EmitsDef_i
  : public virtual TAO_EventPortDef_i
{
  // = TITLE
  //    TAO_EmitsDef_i
  //
  // = DESCRIPTION
  //    Represents the definition of an event that is emitted
  //    by a component.
  //
public:
  /// Constructor
    TAO_EmitsDef_i (TAO_Repository_i *repo);

  /// Destructor
  virtual ~TAO_EmitsDef_i (void);

  /// Return our definition kind.
  virtual CORBA::DefinitionKind def_kind (
    );
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_EMITSDEF_I_H */
