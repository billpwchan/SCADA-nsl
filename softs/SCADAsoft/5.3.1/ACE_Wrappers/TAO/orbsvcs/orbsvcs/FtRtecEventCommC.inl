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
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_FTRTECEVENTCOMM_PUSHCONSUMER___CI_)
#define _FTRTECEVENTCOMM_PUSHCONSUMER___CI_

ACE_INLINE
FtRtecEventComm::PushConsumer::PushConsumer (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_PushConsumer_Proxy_Broker_ (0)
{
  this->FtRtecEventComm_PushConsumer_setup_collocation ();
}

ACE_INLINE
FtRtecEventComm::PushConsumer::PushConsumer (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc)
    , the_TAO_PushConsumer_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_FTRTECEVENTCOMM_AMI_PUSHCONSUMERHANDLER___CI_)
#define _FTRTECEVENTCOMM_AMI_PUSHCONSUMERHANDLER___CI_

ACE_INLINE
FtRtecEventComm::AMI_PushConsumerHandler::AMI_PushConsumerHandler (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_AMI_PushConsumerHandler_Proxy_Broker_ (0)
{
  this->FtRtecEventComm_AMI_PushConsumerHandler_setup_collocation ();
}

ACE_INLINE
FtRtecEventComm::AMI_PushConsumerHandler::AMI_PushConsumerHandler (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc)
    , the_TAO_AMI_PushConsumerHandler_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */


TAO_END_VERSIONED_NAMESPACE_DECL

