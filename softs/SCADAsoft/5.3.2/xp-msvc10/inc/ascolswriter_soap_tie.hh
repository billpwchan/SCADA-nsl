// ################################################################################
// #
// # File:        G:/bin/p530/src/asc2/idl\ascolswriter_soap_tie.hh (the SOAP TIE Header file)
// # Description: Harmonizes TIE implementation classes in a Multi-ORB environment
// #
// # This file has been generated by the SOAP generator on 06 Jun 2016.
// # Do not delete it or edit it since changes will be 
// # lost when next generation happens.
// #
// ################################################################################

#ifndef _SCS_ASCOLSWRITER_SOAP_TIE_HH_
#define _SCS_ASCOLSWRITER_SOAP_TIE_HH_

#include <ascolswriter_soap.hh>

template<class T_SOAP> class AscOlsWriterSOAP_TIE : public AscOlsWriterSOAP {

 public:

   // ctor
   AscOlsWriterSOAP_TIE(T_SOAP * objp) : AscOlsWriterSOAP(), m_obj(objp), m_rel(1) {
   }

   // dtor
   virtual ~AscOlsWriterSOAP_TIE() {
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

   static AscOlsWriterIdl_ptr _narrow(CORBA::Object_ptr p) {
     return AscOlsWriterIdl::_narrow(p);
   }

   // IDL operations

   virtual void modifyAndNotify(const char * valueList)
     throw(CORBA::SystemException) {
     m_obj->modifyAndNotify(valueList);
   }



 private:

   T_SOAP * m_obj;
   CORBA::Boolean m_rel;

   AscOlsWriterSOAP_TIE(const AscOlsWriterSOAP_TIE<T_SOAP>&){}
   void operator=(const AscOlsWriterSOAP_TIE<T_SOAP>&){}

};


#define DEF_TIE_SOAP_AscOlsWriterIdl(X)\
   typedef AscOlsWriterSOAP_TIE<X> AscOlsWriterSOAP_TIE##X;

#define TIE_SOAP_AscOlsWriterIdl(X) AscOlsWriterSOAP_TIE##X

#endif