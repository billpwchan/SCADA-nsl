// ################################################################################
// #
// # File:        G:/bin/p530/src/scs/idl\scsprocess_soap.hh (the SOAP header file)
// # Description: Harmonizes implementation code in a Multi-Object Adapter environment
// #
// # This file has been generated by the SOAP generator on 16 Apr 2014.
// # Do not delete it or edit it since changes will be 
// # lost when next generation happens.
// #
// ################################################################################

#ifndef _SCS_SCSPROCESS_SOAP_H_
#define _SCS_SCSPROCESS_SOAP_H_

#include <scadaorb.h>
#include <scsprocess_skel.hh>


#include <scsprocess_types.hh>

class ScsProcessSOAP : virtual public CORBA_INHERIT(ScsProcessIdl)
#ifdef _SCS_ORBACUS_
   , public virtual PortableServer::RefCountServantBase
#endif
{
 public:

   // The first instance of this class will be registerd in naming service as 'ScsProcessIdl'
   //   Next objects will have a marker composed of numeric characters
   // The argument isMultithreaded is used to indicate whether the CORBA object is multithreaded or serialized
   ScsProcessSOAP(CORBA::Boolean isMultithreaded = 0);


   // The argument marker is used to distinguish serveral instances of this class
   //   Each object will be registred in naming service as 'marker:ScsProcessIdl'
   // The argument isMultithreaded is used to indicate whether the CORBA object is multithreaded or serialized
   ScsProcessSOAP(const char* marker, CORBA::Boolean isMultithreaded = 0);


   ScsProcessSOAP(PortableServer::POA_var & poa);

   ~ScsProcessSOAP();

   CORBA::Boolean scs_is_multithreaded() {
     return _isMultithreaded;
   }

   virtual PortableServer::POA_ptr _default_POA() {
     PortableServer::POA_var foo=_myPoa;
     return foo._retn();
   }

   void _activate_servant();
   void _deactivate_servant();

 private:

   CORBA::Boolean          _isMultithreaded;
   PortableServer::POA_var _myPoa;
   char*                   _myName;
   CORBA::String_var       _objName;

};

#endif
