#ifndef _DAC_DACCOMINVARIABLE_H_
#define _DAC_DACCOMINVARIABLE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : daccominvariable.h                                     */
/*  FULL NAME        :                                                        */
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

#include "scscstring.h"

#include "dacinvariable.h"

class DacVariableBlock ;
class DacComDevice ;

class DACCOM_API DacComInVariable : public DacInVariable
{
 public:
  DacComInVariable() ; //. default constructor
  DacComInVariable( DacComDevice* device,
		    DacVariableBlock* variableBloc,
		    const int currentIdf ,
		    const int globalIdf );
  inline DacComInVariable( const ScsCString& name, DacComDevice* device );
  inline DacComInVariable( const ScsCString& address );
  ~DacComInVariable();

  DacComInVariable( const DacComInVariable& arg ); //. copy constructor

  DacComInVariable& operator=( const DacComInVariable& arg ); //. affectation

  int operator==( const DacComInVariable& arg ) const ; //. equality
  int operator<(const DacComInVariable& arg ) const ; //. less than

  inline DacComDevice* getDevice() const ;
  inline void setDevice( DacComDevice* device );
  inline const ScsCString& getAddress() const ;
  inline unsigned int getId() const ;
  inline void setId( unsigned int id );
  inline int getIndicChange() const ;
  inline void setIndicChange( const int state ) ;

  inline int getFrozen() const ;
  inline void setFrozen( const int state ) ;

  virtual void debugTrace( int level, int inhibTrace = 0 );

 private:
  DacComDevice*    _device ;
  ScsCString        _address ;
  int              _indicChange ;
  int              _frozen ; //. used by DacComSim
};

/////////// INLINE METHODS

DacComInVariable::DacComInVariable( const ScsCString& name, DacComDevice* device ) :
  DacInVariable( name ),
  _address( "" )
{
  _device = device ;
  _indicChange = 0 ;
  _frozen = 0 ;
}

DacComInVariable::DacComInVariable( const ScsCString& address ) :
  DacInVariable()
{
  _address = address ;
  _device = 0 ;
  _indicChange = 0 ;
  _frozen = 0 ;
}

DacComDevice* DacComInVariable::getDevice() const
{
  return( _device );
}

void DacComInVariable::setDevice( DacComDevice* device )
{
  _device = device ;
}

const ScsCString& DacComInVariable::getAddress() const
{
  return( _address );
}

unsigned int DacComInVariable::getId() const
{
  return( _value.getId() );
}

void DacComInVariable::setId( unsigned int id )
{
  _value.setId( id );
}

int DacComInVariable::getIndicChange() const
{
  return( _indicChange );
}

void DacComInVariable::setIndicChange( const int indic )
{
  _indicChange = indic ;
}

int DacComInVariable::getFrozen() const
{
  return( _frozen );
}

void DacComInVariable::setFrozen( const int indic )
{
  _frozen = indic ;
}

#endif // _DAC_DACCOMINVARIABLE_H_
