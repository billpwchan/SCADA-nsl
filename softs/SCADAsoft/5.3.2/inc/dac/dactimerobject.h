#ifndef _DAC_DACTIMEROBJECT_H_
#define _DAC_DACTIMEROBJECT_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : dactimerobject.h                                       */
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

#ifdef WIN32
// disable warning C4251: 'table_' : class 'RWSlistCollectablesPRWGVector' needs to have dll-interface to be used by clients of class 'RWHashTable'
#pragma warning(disable: 4251)
#endif

#include "scscstring.h"

#include "scstimer.h"
#include "dactimerobjectlist.h"

union VarType
{
  int digital ;
  float analog ;
  unsigned char* structure[3192] ;
};

class DacTimerObject
{
 public:
  inline DacTimerObject();
  inline DacTimerObject( const unsigned int base,
			 TimerCallbackFunction timerFunction,
			 void* args );
  inline DacTimerObject( const unsigned int base,
			 const unsigned int delay,
			 const unsigned int oneShot,
			 TimerCallbackFunction timerFunction,
			 void* args );
  inline ~DacTimerObject() ;

  inline unsigned int getBase() const ;
  inline unsigned int isOneShot() const ;
  inline int expire() ;
  inline TimerCallbackFunction getFunction() const ;
  inline void* getArgsFunction() const ;

  virtual void debugTrace( int level, int inhibTrace = 0 );

 private:
  unsigned int _base ;
  unsigned int _cptr ;
  unsigned int _oneShot ;
  TimerCallbackFunction _function ;
  void* _args ;
} ;

DacTimerObject::DacTimerObject()
{
  _base = 0 ;
  _cptr = 0 ;
  _oneShot = 0 ;
  _function = 0 ;
  _args = 0 ;
}

DacTimerObject::DacTimerObject( const unsigned int base,
				TimerCallbackFunction timerFunction,
				void* args )
{
  _base = base ;
  _cptr = base ;
  _oneShot = 0 ;
  _function = timerFunction ;
  _args = args ;
}

DacTimerObject::DacTimerObject( const unsigned int base,
				const unsigned int delay,
				const unsigned int oneShot,
				TimerCallbackFunction timerFunction,
				void* args )
{
  _base = base ;
  delay > base ? _cptr = delay + base : _cptr = delay ;
  _oneShot = oneShot ;
  _function = timerFunction ;
  _args = args ;
}

DacTimerObject::~DacTimerObject()
{
}

unsigned int DacTimerObject::getBase() const
{
  return( _base );
}

unsigned int DacTimerObject::isOneShot() const
{
  return( _oneShot );
}

int DacTimerObject::expire()
{
  if (_cptr > 0) _cptr-- ;
  if (_cptr <= 0) _cptr = _base ;
  return( _cptr == _base );
}

TimerCallbackFunction DacTimerObject::getFunction() const
{
  return( _function );
}

void* DacTimerObject::getArgsFunction() const
{
  return( _args );
}

int debugTrace( int level, DacTimerObjectList& list );

#endif // _DAC_DACTIMEROBJECT_H_
