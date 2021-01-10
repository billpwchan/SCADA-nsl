// -*- C++ -*-

// ===================================================================
/**
 *  @file   Service_Context_Handler.h
 *
 *  $Id: Service_Context_Handler.h 979 2008-12-31 20:22:32Z mitza $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
// ===================================================================

#ifndef TAO_SERVICE_CONTEXT_HANDLER_H
#define TAO_SERVICE_CONTEXT_HANDLER_H

#include /**/ "ace/pre.h"

#include "tao/IOPC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_Transport;

/**
 * This is the base of handler classes that each can process a certain
 * service context. This way optional libraries can plugin handlers to the
 * core of TAO. Each handler has to be registered in the Service Context
 * Handler registry
 */
class TAO_Export TAO_Service_Context_Handler
{
  public:
    TAO_Service_Context_Handler (void);
    virtual int process_service_context (TAO_Transport& transport,
                                         const IOP::ServiceContext& context) = 0;
    virtual ~TAO_Service_Context_Handler (void);
};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif  /* TAO_SERVICE_CONTEXT_HANDLER_H */
