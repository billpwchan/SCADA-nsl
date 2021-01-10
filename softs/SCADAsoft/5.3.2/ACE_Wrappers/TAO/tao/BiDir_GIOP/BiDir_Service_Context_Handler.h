// -*- C++ -*-

// ===================================================================
/**
 *  @file BiDir_Service_Context_Handler.h
 *
 *  $Id: BiDir_Service_Context_Handler.h 979 2008-12-31 20:22:32Z mitza $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
// ===================================================================

#ifndef TAO_BIDIR_SERVICE_CONTEXT_HANDLER_H
#define TAO_BIDIR_SERVICE_CONTEXT_HANDLER_H
#include /**/ "ace/pre.h"
#include "tao/BiDir_GIOP/bidirgiop_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Service_Context_Handler.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_BiDIR_Service_Context_Handler :
  public TAO_Service_Context_Handler
{
  virtual int process_service_context (TAO_Transport& transport,
                                       const IOP::ServiceContext& context);
};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* TAO_BIDIR_SERVICE_CONTEXT_HANDLER_H */