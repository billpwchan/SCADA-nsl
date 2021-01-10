#ifndef _DAC_DACCOMOUTVARIABLE_H_
#define _DAC_DACCOMOUTVARIABLE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomoutvariable.h                                    */
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


#include "dacoutvariable.h"

class DacComDevice ;
class DacVariableBlock ;

class DACCOM_API DacComOutVariable : public DacOutVariable
{
 public:
  DacComOutVariable( DacComDevice* device,
		     DacVariableBlock* variableBloc );
  inline DacComOutVariable( const ScsCString& name );
  virtual ~DacComOutVariable() {}

  DacComOutVariable( const DacComOutVariable& arg ); //. copy constructor
  DacComOutVariable& operator=( const DacComOutVariable& arg ); //. affectation

  int operator==( const DacComOutVariable& arg ) const ; //. equality
  int operator<(const DacComOutVariable& arg ) const ; //. less than

  inline DacComDevice* getDevice() const ;
  inline void setDevice( DacComDevice* device );
  inline const ScsCString& getAddress() const ;

  inline int getInhibited() const ;
  inline void setInhibited( const int indic );

  inline int getSubscribed() const ;
  inline void setSubscribed( const int indic );

  void debugTrace( int level, int inhibTrace = 0 );

 private:
  DacComDevice*  _device ;  
  ScsCString     _address ;
  int            _inhibited ;
  int            _subscribed ;
};


/////////// INLINE METHODS
DacComOutVariable::DacComOutVariable( const ScsCString& name )
  : DacOutVariable( name ),
    _address( "" )
{
  _device = 0 ;
  _inhibited = 0 ;
  _subscribed = 0 ;
}

DacComDevice* DacComOutVariable::getDevice() const
{
  return( _device );
}

void DacComOutVariable::setDevice( DacComDevice* device )
{
  _device = device ;
}

const ScsCString& DacComOutVariable::getAddress() const
{
  return( _address );
}

int DacComOutVariable::getInhibited() const
{
  return( _inhibited );
}

void DacComOutVariable::setInhibited( const int indic )
{
  _inhibited = indic ;
}

int DacComOutVariable::getSubscribed() const
{
  return( _subscribed );
}

void DacComOutVariable::setSubscribed( const int indic )
{
  _subscribed = indic ;
}

#endif // _DAC_DACOUTVARIABLE_H_
