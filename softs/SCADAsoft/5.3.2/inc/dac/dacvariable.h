#ifndef _DAC_DACVARIABLE_H_
#define _DAC_DACVARIABLE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : dacvariable.h                                          */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon Dec 27 10:45:01 1999                               */
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


#include "dac.h"
#include "scs.h"
#include "scsdefs.h"
#include "scscstring.h"


class DacVariableBlock ;

enum EvDeviceLink
{
  UNDEFINED_LINK = 0,
  STATE,
  SPY,
  LINK
};

enum EvValue
{
  UNDEFINED = 0,
  OUT_OF_SERVICE,
  OUT_OF_SERVICE_OPERATOR,
  IN_SERVICE,
  IN_SIMUL,
  WITH_TRACES,
  WITHOUT_TRACES,
  INIT
};

struct AppliFunction
{
  ScsCString functionName ;
  int intParam1 ;
  int intParam2 ;
  float floatParam1 ;
  float floatParam2 ;
} ;

class DacVariable
{
 public:
  inline DacVariable();
  virtual ~DacVariable() {}

  inline DacVariable( const DacVariable& arg ); // copy constructeur

  inline void setDeviceLink( EvDeviceLink link );
  inline EvDeviceLink getDeviceLink() const ;
  inline void setStatus( ScsStatus status );
  inline ScsStatus getStatus() const ;

 protected:
  EvDeviceLink    _deviceLink ;
  ScsStatus       _dacVariableStatus ;
};

/////////// INLINE METHODS
DacVariable::DacVariable()
{
  _deviceLink = UNDEFINED_LINK ;
  _dacVariableStatus = ScsValid ;
}

DacVariable::DacVariable( const DacVariable& arg )
{
  _deviceLink = arg._deviceLink ;
  _dacVariableStatus = arg._dacVariableStatus ;
}

void DacVariable::setDeviceLink( EvDeviceLink link )
{
  _deviceLink = link ;
}

EvDeviceLink DacVariable::getDeviceLink() const
{
  return( _deviceLink );
}

void DacVariable::setStatus( ScsStatus status )
{
  _dacVariableStatus = status ;
}

ScsStatus DacVariable::getStatus() const
{
  return( _dacVariableStatus );
}

#endif // _DAC_DACVARIABLE_H_
