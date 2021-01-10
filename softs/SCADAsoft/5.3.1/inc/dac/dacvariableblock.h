#ifndef _DAC_DACVARIABLEBLOCK_H_
#define _DAC_DACVARIABLEBLOCK_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : dacvariableblock.h                                     */
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
// disable warning C4786: symbol greater than 255 character
#pragma warning(disable: 4786)
// disable warning C4251: 'table_' : class 'RWSlistCollectablesPRWGVector' needs to have dll-interface to be used by clients of class 'RWHashTable'
#pragma warning(disable: 4251)
#endif


#include "scscstring.h"

#include "dacvariable.h"

#define MAX_INHIB_DEIV 3

#include "variableblocklist.h"


class DacVariableBlock
{
 public:
  enum EvType
  {
    UNDEFINED_TYPE = 0,
    DEIV,
    AEIV,
    SEIV,
    DEOV,
    AEOV,
    SEOV
  };

  inline DacVariableBlock() ;
  DacVariableBlock( const DacVariableBlock& arg );
  inline ~DacVariableBlock() ;

  inline EvType getType() const ;
  inline void setType( const EvType type );
  inline const ScsCString& getAddress() const ;
  inline void setAddress( const ScsCString& addr );
  inline const ScsCString& getName() const ;
  inline void setName( const ScsCString& name );
  
  inline const ScsCString& getChatterFilterDesc() const ;
  inline void setChatterFilterDesc( const ScsCString& f );
  
  inline unsigned int getSize() const ;
  inline void setSize( const unsigned int size );
  inline AppliFunction* getTransFunction() ;
  inline void setTransFunction( const ScsCString& name,
				const int i1, const int i2,
				const float f1, const float f2 );
  inline AppliFunction* getCheckFunction() ;
  inline void setCheckFunction( const ScsCString& name, const float f1, const float f2 );
  inline float getDeadband() const ;
  inline void setDeadband( const float deadband );
  inline ScsCString getInhib( const unsigned int i) const ;
  inline void setInhib( const unsigned int i, const ScsCString& inhibName );

  void debugTrace( int level );
  void reset() ;

 private:
  EvType        _type ;
  ScsCString     _address ;
  ScsCString     _name ;
  ScsCString     _chatterFilterDesc;
  unsigned int  _size ;
  AppliFunction _transFunction ;
  AppliFunction _checkFunction ;
  float         _deadband ;
  ScsCString     _inhib[MAX_INHIB_DEIV] ;
} ;

DacVariableBlock::DacVariableBlock()
{
}

DacVariableBlock::~DacVariableBlock()
{
}

DacVariableBlock::EvType DacVariableBlock::getType() const
{
  return( _type );
}

void DacVariableBlock::setType( const DacVariableBlock::EvType type )
{
  _type = type ;
}

const ScsCString& DacVariableBlock::getAddress() const
{
  return( _address );
}

void DacVariableBlock::setAddress( const ScsCString& addr )
{
  _address = addr ;
}

const ScsCString& DacVariableBlock::getName() const
{
  return( _name );
}

void DacVariableBlock::setName( const ScsCString& name )
{
  _name = name ;
}

const ScsCString& DacVariableBlock::getChatterFilterDesc() const
{
  return( _chatterFilterDesc );
}

void DacVariableBlock::setChatterFilterDesc( const ScsCString& f )
{
  _chatterFilterDesc = f ;
}

unsigned int DacVariableBlock::getSize() const
{
  return( _size );
}

void DacVariableBlock::setSize( const unsigned int size )
{
  _size = size ;
}

AppliFunction* DacVariableBlock::getTransFunction()
{
  return( &_transFunction );
}

void DacVariableBlock::setTransFunction( const ScsCString& name,
					 const int i1, const int i2,
					 const float f1, const float f2 )
{
  _transFunction.functionName = name ;
  _transFunction.intParam1 = i1 ;
  _transFunction.intParam2 = i2 ;
  _transFunction.floatParam1 = f1 ;
  _transFunction.floatParam2 = f2 ;
}

AppliFunction* DacVariableBlock::getCheckFunction()
{
  return( &_checkFunction );
}

void DacVariableBlock::setCheckFunction( const ScsCString& name,
					 const float f1,
					 const float f2 )
{
  _checkFunction.functionName = name ;
  _checkFunction.floatParam1 = f1 ;
  _checkFunction.floatParam2 = f2 ;
}

float DacVariableBlock::getDeadband() const 
{
  return( _deadband );
}

void DacVariableBlock::setDeadband( const float deadband )
{
  _deadband = deadband ;
}

ScsCString DacVariableBlock::getInhib( const unsigned int i ) const 
{
  if( i < MAX_INHIB_DEIV )
    {
      return( _inhib[i] );
    }
  else
    {
      return( ScsCString ("") );
    }
}

void DacVariableBlock::setInhib( const unsigned int i, const ScsCString& inhibName )
{
  if( i < MAX_INHIB_DEIV )
    {
      _inhib[i] = inhibName ;
    }
}

int debugTrace( int level, VariableBlockList& list );

#endif // _DAC_DACVARIABLEBLOCK_H_
