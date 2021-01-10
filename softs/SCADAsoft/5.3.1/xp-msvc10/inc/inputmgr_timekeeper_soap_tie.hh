// ################################################################################
// #
// # File:        G:/bin/p530/src/img/idl\inputmgr_timekeeper_soap_tie.hh (the SOAP TIE Header file)
// # Description: Harmonizes TIE implementation classes in a Multi-ORB environment
// #
// # This file has been generated by the SOAP generator on 15 Nov 2013.
// # Do not delete it or edit it since changes will be 
// # lost when next generation happens.
// #
// ################################################################################

#ifndef _SCS_INPUTMGR_TIMEKEEPER_SOAP_TIE_HH_
#define _SCS_INPUTMGR_TIMEKEEPER_SOAP_TIE_HH_

#include <inputmgr_timekeeper_soap.hh>

template<class T_SOAP> class InputMgr_TimeKeeperSOAP_TIE : public InputMgr_TimeKeeperSOAP {

 public:

   // ctor
   InputMgr_TimeKeeperSOAP_TIE(T_SOAP * objp) : InputMgr_TimeKeeperSOAP(), m_obj(objp), m_rel(1) {
   }

   // dtor
   virtual ~InputMgr_TimeKeeperSOAP_TIE() {
     if(m_rel) delete m_obj;
   }

   char * scs_implementation(void)
     throw(CORBA::SystemException) {
     return m_obj->scs_implementation();
   }
   char * scs_host(void)
     throw(CORBA::SystemException) {
     return m_obj->scs_host();
   }
   void   isAlive(void)
     throw(CORBA::SystemException) {
     m_obj->isAlive();
   }

   static InputMgr_TimeKeeperIdl_ptr _narrow(CORBA::Object_ptr p) {
     return InputMgr_TimeKeeperIdl::_narrow(p);
   }

   // IDL operations

   virtual void wakeupEveryShared(TimeClientIdl_ptr  client, 
                                  CORBA::UShort priority, 
                                  CORBA::ULong period, 
                                  CORBA::UShort delay, 
                                  CORBA::ULong minToNext, 
                                  CORBA::ULong maxToPrevious)
     throw(CORBA::SystemException) {
     m_obj->wakeupEveryShared(client, 
                              priority, 
                              period, 
                              delay, 
                              minToNext, 
                              maxToPrevious);
   }



 private:

   T_SOAP * m_obj;
   CORBA::Boolean m_rel;

   InputMgr_TimeKeeperSOAP_TIE(const InputMgr_TimeKeeperSOAP_TIE<T_SOAP>&){}
   void operator=(const InputMgr_TimeKeeperSOAP_TIE<T_SOAP>&){}

};


#define DEF_TIE_SOAP_InputMgr_TimeKeeperIdl(X)\
   typedef InputMgr_TimeKeeperSOAP_TIE<X> InputMgr_TimeKeeperSOAP_TIE##X;

#define TIE_SOAP_InputMgr_TimeKeeperIdl(X) InputMgr_TimeKeeperSOAP_TIE##X

#endif
