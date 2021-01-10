// -*- C++ -*-
//
// $Id: CSD_TP_Corba_Request.inl 14 2007-02-01 15:49:12Z mitza $

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
TAO::CSD::TP_Corba_Request::TP_Corba_Request
                             (const PortableServer::ObjectId& object_id,
                              PortableServer::POA_ptr         poa,
                              const char*                     operation,
                              PortableServer::Servant         servant,
                              TP_Servant_State*               servant_state,
                              TAO_ServerRequest&              server_request)
  : TP_Request(servant,servant_state),
    object_id_(object_id),
    operation_(operation),
    server_request_(server_request)
{
  this->poa_ = PortableServer::POA::_duplicate(poa);
}

ACE_INLINE
void
TAO::CSD::TP_Corba_Request::do_clone()
{
  this->server_request_.clone();
}

ACE_INLINE
void
TAO::CSD::TP_Corba_Request::do_dispatch(void)
{
  this->server_request_.dispatch(this->servant());
}

ACE_INLINE
void
TAO::CSD::TP_Corba_Request::do_cancel()
{
  this->server_request_.cancel();
}

TAO_END_VERSIONED_NAMESPACE_DECL