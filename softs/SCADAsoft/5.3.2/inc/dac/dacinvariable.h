#ifndef _DAC_DACINVARIABLE_H_
#define _DAC_DACINVARIABLE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : dacinvariable.h                                        */
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

#include "dacvariable.h"

#include "scscstring.h"

class DacVariableBlock ;

class DACCOM_API DacInVariable : public DacVariable
{
 public:
  DacInVariable() ; //. default constructor
  DacInVariable( DacVariableBlock* variableBloc,
		 const int currentIdf ,
		 const int globalIdf );
  inline DacInVariable( const ScsCString& name );
  inline virtual ~DacInVariable();

  DacInVariable( const DacInVariable& arg ); //. copy constructor

  DacInVariable& operator=( const DacInVariable& arg ); //. affectation

  inline const ScsCString& getName() const ;
  inline const ScsCString& getAddress() const ;
  inline unsigned int getIdfInDevice() const ;

  inline const DacEIV& getDacEiv() const ;
  void setNewDacEiv( const DacEIV& var );

  inline DacEIV::EivType getEivType() const ;
  inline void setEivStatus( const DacEIV::Status status ) ;
  inline DacEIV::Status getEivStatus() const ;

  inline void setValue( const int val );
  inline void setValue( const float val );
  inline void setValue( const unsigned char* val, const unsigned int size );
  inline void setValue( const ScsData& val );
  inline void setAcqTime( unsigned long, unsigned long );

  inline void getAcqTime( unsigned long* sec, unsigned long* msec);
  inline ScsData getValue() const ;
  inline int getIntValue() const ;
  inline float getFloatValue() const ;
  inline unsigned char* getBitValue() const ;
  inline unsigned int getDataLength() const ;

 protected:
  ScsCString     _name ;
  ScsCString     _address ;
  unsigned int  _idfInDevice ;
  DacEIV        _value ;
};

/////////// INLINE METHODS

DacInVariable::DacInVariable( const ScsCString& name )
  : _name(name), _address("")
{
  _idfInDevice = 0 ;
}

DacInVariable::~DacInVariable()
{
}

const ScsCString& DacInVariable::getName() const
{
 return( _name );
}

const ScsCString& DacInVariable::getAddress() const
{
 return( _address );
}

unsigned int DacInVariable::getIdfInDevice() const
{
  return( _idfInDevice );
}

const DacEIV& DacInVariable::getDacEiv() const
{
  return( _value );
}

void DacInVariable::setEivStatus( const DacEIV::Status status )
{
  _value.setStatus( status );
}

inline DacEIV::Status DacInVariable::getEivStatus() const
{
  return( _value.getStatus() );
}

inline DacEIV::EivType DacInVariable::getEivType() const
{
  return( _value.getType() );
}

void DacInVariable::setValue( const int val )
{
  _value.setValue( val );
}

void DacInVariable::setValue( const float val )
{
  _value.setValue( val );
}

void DacInVariable::setValue( const unsigned char* val, const unsigned int size )
{
  _value.setValue( val, size );
}

void DacInVariable::setValue( const ScsData& val )
{
  _value.setValue( val );
}

void DacInVariable::setAcqTime( unsigned long sec, unsigned long msec)
{
  _value.setAcqTime( sec, msec );
}

void DacInVariable::getAcqTime( unsigned long* sec, unsigned long* msec)
{
  _value.getAcqTime( sec, msec );
}

ScsData DacInVariable::getValue() const
{
  return( _value.getData() );
}

int DacInVariable::getIntValue() const 
{
  return( ( int ) _value.getData() );
}

float DacInVariable::getFloatValue() const
{
  return( ( float ) _value.getData() );
}

unsigned char* DacInVariable::getBitValue() const
{
  return( ( unsigned char* ) _value.getData() );
}

unsigned int DacInVariable::getDataLength() const
{
  return( _value.getData().length() );
}

#endif // _DAC_DACINVARIABLE_H_
