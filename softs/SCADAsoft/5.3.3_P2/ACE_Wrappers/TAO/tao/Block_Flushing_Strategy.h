// -*- C++ -*-

//=============================================================================
/**
 *  @file Block_Flushing_Strategy.h
 *
 *  $Id: Block_Flushing_Strategy.h 1219 2009-06-26 20:24:08Z mitza $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef TAO_BLOCK_FLUSHING_STRATEGY_H
#define TAO_BLOCK_FLUSHING_STRATEGY_H
#include /**/ "ace/pre.h"

#include "tao/Flushing_Strategy.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class TAO_Block_Flushing_Strategy
 *
 * @brief Implement a flushing strategy that blocks on write to flush
 */
class TAO_Block_Flushing_Strategy : public TAO_Flushing_Strategy
{
public:
  virtual int schedule_output (TAO_Transport *transport);
  virtual int cancel_output (TAO_Transport *transport);
  virtual int flush_message (TAO_Transport *transport,
                             TAO_Queued_Message *msg,
                             ACE_Time_Value *max_wait_time);
  virtual int flush_transport (TAO_Transport *transport
                               , ACE_Time_Value *max_wait_time);

private:
  int call_handle_output (TAO_Transport *transport, ACE_Time_Value *timeout);
                          
};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif  /* TAO_BLOCK_FLUSHING_STRATEGY_H */
