#ifndef _DAC_DACDEVICEBLOCK_H_
#define _DAC_DACDEVICEBLOCK_H_


/******************************************************************************/
/*                                                                            */
/*  FILE             : dacdeviceblock.h                                       */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Fri Dec 29 15:09:04 1999                               */
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

#ifdef WIN32
// disable warning C4251: 'table_' : class 'RWSlistCollectablesPRWGVector' needs to have dll-interface to be used by clients of class 'RWHashTable'
#pragma warning(disable: 4251)
#endif

#ifdef SCS_STD
#include <fstream>
#include <iostream>
#else
#include <fstream.h>
#include <iostream.h>
#endif

#include "scscstring.h"

#include "deviceblocklist.h"

class DacDeviceBlock
{
 public:
  inline DacDeviceBlock() ;
  DacDeviceBlock( const DacDeviceBlock& arg );
  inline ~DacDeviceBlock() ;

  inline const ScsCString& getName() const ;
  inline void setName( const ScsCString& name );
  inline const ScsCString& getLabel() const ;
  inline void setLabel( const ScsCString& label );
  inline const ScsCString& getProtocol() const ;
  inline void setProtocol( const ScsCString& protocol );
  inline const ScsCString& getUsrProtocol() const ;
  inline void setUsrProtocol( const ScsCString& usrProtocol );
  inline const ScsCString& getGroup() const ;
  inline void setGroup( const ScsCString& group );
  inline const ScsCString& getBlocker() const ;
  inline void setBlocker( const ScsCString& blocker );
  inline const ScsCString& getLinksAddress() const ;
  inline void setLinksAddress( const ScsCString& addr );
  inline const ScsCString& getIniState() const ;
  inline void setIniState( const ScsCString& state );
  inline const ScsCString& getIniSpy() const ;
  inline void setIniSpy( const ScsCString& spy );
  inline const ScsCString& getVariableFile() const ;
  inline void setVariableFile( const ScsCString& fileName );
  inline const ScsCString& getExchangeFile() const ;
  inline void setExchangeFile( const ScsCString& fileName );

  void debugTrace( int level ) ;
  void reset() ;

 private:
  ScsCString    _name ;
  ScsCString    _label ;
  ScsCString    _protocol ;
  ScsCString    _usrProtocol ;
  ScsCString    _group ;
  ScsCString    _blocker ;
  ScsCString    _linksAddr ;
  ScsCString    _iniState ;
  ScsCString    _iniSpy ;
  ScsCString    _evFile ;
  ScsCString    _exchFile ;
} ;

DacDeviceBlock::DacDeviceBlock()
  : _name( "" ),
    _label( "" ),
    _protocol( "" ),
    _usrProtocol( "" ),
    _group( "" ),
    _linksAddr( "" ),
    _iniState( "" ),
    _iniSpy( "" ),
    _evFile( "" ),
    _exchFile( "" )
{
}

DacDeviceBlock::~DacDeviceBlock()
{
}

const ScsCString& DacDeviceBlock::getName() const
{
  return( _name );
}

void DacDeviceBlock::setName( const ScsCString& name )
{
  _name = name ;
}

const ScsCString& DacDeviceBlock::getLabel() const 
{
  return( _label );
}

void DacDeviceBlock::setLabel( const ScsCString& label )
{
  _label = label ;
}

const ScsCString& DacDeviceBlock::getProtocol() const
{
  return( _protocol );
}

void DacDeviceBlock::setProtocol( const ScsCString& protocol )
{
  _protocol = protocol ;
}

const ScsCString& DacDeviceBlock::getUsrProtocol() const
{
  return( _usrProtocol );
}

void DacDeviceBlock::setUsrProtocol( const ScsCString& usrProtocol )
{
  _usrProtocol = usrProtocol ;
}

const ScsCString& DacDeviceBlock::getGroup() const
{
  return( _group );
}

void DacDeviceBlock::setGroup( const ScsCString& group )
{
  _group = group ;
}

const ScsCString& DacDeviceBlock::getBlocker() const
{
  return( _blocker );
}

void DacDeviceBlock::setBlocker( const ScsCString& blocker )
{
  _blocker = blocker ;
}

const ScsCString& DacDeviceBlock::getLinksAddress() const
{
  return( _linksAddr );
}

void DacDeviceBlock::setLinksAddress( const ScsCString& addr )
{
  _linksAddr = addr ;
}

const ScsCString& DacDeviceBlock::getIniState() const
{
  return( _iniState );
}

void DacDeviceBlock::setIniState( const ScsCString& state )
{
  _iniState = state ;
}

const ScsCString& DacDeviceBlock::getIniSpy() const
{
  return( _iniSpy );
}

void DacDeviceBlock::setIniSpy( const ScsCString& spy )
{
  _iniSpy = spy ;
}

const ScsCString& DacDeviceBlock::getVariableFile() const
{
  return( _evFile );
}

void DacDeviceBlock::setVariableFile( const ScsCString& fileName )
{
  _evFile = fileName ;
}

const ScsCString& DacDeviceBlock::getExchangeFile() const
{
  return( _exchFile );
}

void DacDeviceBlock::setExchangeFile( const ScsCString& fileName )
{
  _exchFile = fileName ;
}

int debugTrace( int level, DeviceBlockList& list );

#endif // _DAC_DACDEVICEBLOCK_H_
