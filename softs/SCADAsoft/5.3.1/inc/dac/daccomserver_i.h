#ifndef _DAC_DACCOMSERVER_H_
#define _DAC_DACCOMSERVER_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomserver_i.h                                       */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Tue Jan 22 15:09:04 2000                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $

#include "scadaorb.h"
#include "daccomdevice.h"

//. ORBIX communication with DacControl
#include "daccomserver_soap.hh"
#include "daccomclient.hh"

class DacCom ;

class DacComServerIdl_i : virtual public DacComServerSOAP
{
 public:
  inline DacComServerIdl_i() ;
  inline DacComServerIdl_i( DacCom* _com ) ;
  virtual ~DacComServerIdl_i() ;

  inline DacComClientIdl* getComClient() const ;

  virtual ScsStatusIdl configure(DacComClientIdl* client,
				 const char* deviceName,
				 CORBA::Long deviceId,
				 CORBA::Long nbEiv,
		       		 const char* values)	  
    throw(CORBA::SystemException);

  virtual void sendEov(CORBA::Long deviceId,
		       CORBA::Long nbEov,
		       const char* values)
    throw(CORBA::SystemException);

  virtual ScsStatusIdl askForState(void)
    throw(CORBA::SystemException);

  virtual ScsStatusIdl armTimer(void)
    throw(CORBA::SystemException);

  virtual ScsStatusIdl setFirstWakeUpTime(const ScsTimeValIdl& wakeUpTime)
    throw(CORBA::SystemException);

  virtual ScsStatusIdl getWakeUpTime(ScsTimeValIdl& wakeUpTime)
    throw(CORBA::SystemException);
    
  virtual void shutdown()
    throw(CORBA::SystemException);

 private:
  DacCom* _com ;
  DacComClientIdl_var _client ;
};

DacComServerIdl_i::DacComServerIdl_i() :
  DacComServerSOAP()
{
  _com = 0 ;
  _client = DacComClientIdl::_nil();
}

DacComServerIdl_i::DacComServerIdl_i( DacCom* com ) :
  DacComServerSOAP()
{
  _com = com ;
  _client = DacComClientIdl::_nil();
}

DacComClientIdl* DacComServerIdl_i::getComClient() const
{
  return( _client );
}


#endif // _DAC_DACCOMSERVER_H_
