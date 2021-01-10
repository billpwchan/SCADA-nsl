// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6a_p10 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union FtRtecEventChannelAdmin::ProxyPushConsumerConnectionParamter
// *************************************************************

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:165



// Accessor to set the discriminant.
ACE_INLINE
void
FtRtecEventChannelAdmin::ProxyPushConsumerConnectionParamter::_d ( ::CORBA::Boolean discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
::CORBA::Boolean
FtRtecEventChannelAdmin::ProxyPushConsumerConnectionParamter::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
FtRtecEventChannelAdmin::ProxyPushConsumerConnectionParamter::info (const FtRtecEventChannelAdmin::ProxyPushConsumerConnectionInfo &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = false;
  ACE_NEW (
      this->u_.info_,
      FtRtecEventChannelAdmin::ProxyPushConsumerConnectionInfo (val)
    );
}

// Readonly get method.
ACE_INLINE
const FtRtecEventChannelAdmin::ProxyPushConsumerConnectionInfo &
FtRtecEventChannelAdmin::ProxyPushConsumerConnectionParamter::info (void) const
{
  return *this->u_.info_;
}

// Read/write get method.
ACE_INLINE
FtRtecEventChannelAdmin::ProxyPushConsumerConnectionInfo &
FtRtecEventChannelAdmin::ProxyPushConsumerConnectionParamter::info (void)
{
  return *this->u_.info_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union FtRtecEventChannelAdmin::ProxyPushSupplierConnectionParamter
// *************************************************************

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:165



// Accessor to set the discriminant.
ACE_INLINE
void
FtRtecEventChannelAdmin::ProxyPushSupplierConnectionParamter::_d ( ::CORBA::Boolean discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
::CORBA::Boolean
FtRtecEventChannelAdmin::ProxyPushSupplierConnectionParamter::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
FtRtecEventChannelAdmin::ProxyPushSupplierConnectionParamter::info (const FtRtecEventChannelAdmin::ProxyPushSupplierConnectionInfo &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = false;
  ACE_NEW (
      this->u_.info_,
      FtRtecEventChannelAdmin::ProxyPushSupplierConnectionInfo (val)
    );
}

// Readonly get method.
ACE_INLINE
const FtRtecEventChannelAdmin::ProxyPushSupplierConnectionInfo &
FtRtecEventChannelAdmin::ProxyPushSupplierConnectionParamter::info (void) const
{
  return *this->u_.info_;
}

// Read/write get method.
ACE_INLINE
FtRtecEventChannelAdmin::ProxyPushSupplierConnectionInfo &
FtRtecEventChannelAdmin::ProxyPushSupplierConnectionParamter::info (void)
{
  return *this->u_.info_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union FtRtecEventChannelAdmin::OperationParam
// *************************************************************

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:71

ACE_INLINE
void 
FtRtecEventChannelAdmin::OperationParam::_default ()
{
  this->_reset ();
  this->disc_ = FtRtecEventChannelAdmin::OBTAIN_PUSH_SUPPLIER;
}

// Accessor to set the discriminant.
ACE_INLINE
void
FtRtecEventChannelAdmin::OperationParam::_d (FtRtecEventChannelAdmin::OperationType discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
FtRtecEventChannelAdmin::OperationType
FtRtecEventChannelAdmin::OperationParam::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
FtRtecEventChannelAdmin::OperationParam::connect_supplier_param (const FtRtecEventChannelAdmin::Connect_push_supplier_param &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = FtRtecEventChannelAdmin::CONNECT_PUSH_SUPPLIER;
  ACE_NEW (
      this->u_.connect_supplier_param_,
      FtRtecEventChannelAdmin::Connect_push_supplier_param (val)
    );
}

// Readonly get method.
ACE_INLINE
const FtRtecEventChannelAdmin::Connect_push_supplier_param &
FtRtecEventChannelAdmin::OperationParam::connect_supplier_param (void) const
{
  return *this->u_.connect_supplier_param_;
}

// Read/write get method.
ACE_INLINE
FtRtecEventChannelAdmin::Connect_push_supplier_param &
FtRtecEventChannelAdmin::OperationParam::connect_supplier_param (void)
{
  return *this->u_.connect_supplier_param_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
FtRtecEventChannelAdmin::OperationParam::connect_consumer_param (const FtRtecEventChannelAdmin::Connect_push_consumer_param &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = FtRtecEventChannelAdmin::CONNECT_PUSH_CONSUMER;
  ACE_NEW (
      this->u_.connect_consumer_param_,
      FtRtecEventChannelAdmin::Connect_push_consumer_param (val)
    );
}

// Readonly get method.
ACE_INLINE
const FtRtecEventChannelAdmin::Connect_push_consumer_param &
FtRtecEventChannelAdmin::OperationParam::connect_consumer_param (void) const
{
  return *this->u_.connect_consumer_param_;
}

// Read/write get method.
ACE_INLINE
FtRtecEventChannelAdmin::Connect_push_consumer_param &
FtRtecEventChannelAdmin::OperationParam::connect_consumer_param (void)
{
  return *this->u_.connect_consumer_param_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_FTRTECEVENTCHANNELADMIN_EVENTCHANNELFACADE___CI_)
#define _FTRTECEVENTCHANNELADMIN_EVENTCHANNELFACADE___CI_

ACE_INLINE
FtRtecEventChannelAdmin::EventChannelFacade::EventChannelFacade (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_EventChannelFacade_Proxy_Broker_ (0)
{
  this->FtRtecEventChannelAdmin_EventChannelFacade_setup_collocation ();
}

ACE_INLINE
FtRtecEventChannelAdmin::EventChannelFacade::EventChannelFacade (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc)
    , the_TAO_EventChannelFacade_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_FTRTECEVENTCHANNELADMIN_EVENTCHANNEL___CI_)
#define _FTRTECEVENTCHANNELADMIN_EVENTCHANNEL___CI_

ACE_INLINE
FtRtecEventChannelAdmin::EventChannel::EventChannel (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_EventChannel_Proxy_Broker_ (0)
{
  this->FtRtecEventChannelAdmin_EventChannel_setup_collocation ();
}

ACE_INLINE
FtRtecEventChannelAdmin::EventChannel::EventChannel (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc)
    , the_TAO_EventChannel_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */


TAO_END_VERSIONED_NAMESPACE_DECL


