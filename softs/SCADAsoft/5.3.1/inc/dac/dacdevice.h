#ifndef _DAC_DACDEVICE_H_
#define _DAC_DACDEVICE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : dacdevice.h                                            */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Wed Dec 29 15:09:04 1999                               */
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


//. error management
#include "scs.h" //. ScsStatus

#include "scscstring.h"

class DacDevice
{
 public:
  inline DacDevice();
  inline DacDevice( const ScsCString& name, const unsigned int id );
  inline virtual ~DacDevice() ;

  inline DacDevice& operator=( const DacDevice& arg );

  inline unsigned int getId() const ;
  inline void setId( unsigned int id );

  inline const ScsCString& getName() const ;
  inline void setName( const ScsCString& name );

  inline ScsStatus getStatus() const ;
  inline void setStatus( ScsStatus status );

  virtual void debugTrace( int level, int inhibTrace = 0 ) = 0 ;

 protected:
  unsigned int         _id ;
  ScsCString            _name ;
  ScsStatus            _dacDeviceStatus ;
} ;

DacDevice::DacDevice()
{
  _id = 0 ;
  _name = ScsCString( "" );
  _dacDeviceStatus = ScsValid ;
}

DacDevice::DacDevice( const ScsCString& name, const unsigned int id )
{
  _id = id ;
  _name = name ;
  _dacDeviceStatus = ScsValid ;
}

DacDevice::~DacDevice()
{
}

DacDevice& DacDevice::operator=( const DacDevice& arg )
{
  _id = arg._id ;
  _name = arg._name ;
  _dacDeviceStatus = arg._dacDeviceStatus ;

  return *this ;
}

unsigned int DacDevice::getId() const
{
  return( _id );
}

void DacDevice::setId( unsigned int id )
{
  _id = id ;
}

const ScsCString& DacDevice::getName() const
{
  return( _name );
}

void DacDevice::setName( const ScsCString& name )
{
  _name = name ;
}

ScsStatus DacDevice::getStatus() const
{
  return( _dacDeviceStatus );
}

void DacDevice::setStatus( ScsStatus status )
{
  _dacDeviceStatus = status ;
}

#endif // _DAC_DACDEVICE_H_
