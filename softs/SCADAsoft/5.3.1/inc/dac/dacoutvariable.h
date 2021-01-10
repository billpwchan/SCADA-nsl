#ifndef _DAC_DACOUTVARIABLE_H_
#define _DAC_DACOUTVARIABLE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : dacoutvariable.h                                       */
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

class DacCtlDevice ;
class DacVariableBlock ;

class DACCOM_API DacOutVariable : public DacVariable
{
 public:
  inline DacOutVariable( const ScsCString& name );
  DacOutVariable( DacVariableBlock* variableBloc );
  virtual ~DacOutVariable() {}

  inline const char * getName() const ;
  inline DacEOV::EovType getEovType() const ;
  //inline const DacEOV& getDacEov() const ;
  inline DacEOV& getDacEov() ; //. const ;

  inline void setValue( const int val );
  inline void setValue( const float val );
  inline void setValue( const unsigned char* val, const unsigned int size );
  inline void setValue( const ScsData& val );

  inline ScsData getValue() const ;
  inline int getIntValue() const ;
  inline float getFloatValue() const ;
  inline unsigned char* getBitValue() const ;
  inline unsigned int getDataLength() const ;

 protected:
  DacEOV _value ;
};


/////////// INLINE METHODS
DacOutVariable::DacOutVariable( const ScsCString& name )
{
  int val = 0 ;
  _value = DacEOV( name.data(), val );
}

const char * DacOutVariable::getName() const
{
  return( _value.getName() );
}

inline DacEOV::EovType DacOutVariable::getEovType() const
{
  return( _value.getType() );
}

//const
DacEOV& DacOutVariable::getDacEov() // const
{
  return( _value );
}

void DacOutVariable::setValue( const int val )
{
  _value.setValue( val );
}

void DacOutVariable::setValue( const float val )
{
  _value.setValue( val );
}

void DacOutVariable::setValue( const unsigned char* val, const unsigned int size )
{
  _value.setValue( val, size );
}

void DacOutVariable::setValue( const ScsData& val )
{
  _value.setValue( val );
}

ScsData DacOutVariable::getValue() const
{
  return( _value.getData() );
}

int DacOutVariable::getIntValue() const 
{
  return( ( int ) _value.getData() );
}

float DacOutVariable::getFloatValue() const
{
  return( ( float ) _value.getData() );
}

unsigned char* DacOutVariable::getBitValue() const
{
  return( ( unsigned char* ) _value.getData() );
}

unsigned int DacOutVariable::getDataLength() const
{
  return( _value.getData().length() );
}

#endif // _DAC_DACOUTVARIABLE_H_
