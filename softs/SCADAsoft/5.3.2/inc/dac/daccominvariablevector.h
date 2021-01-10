#ifndef _DAC_DACCOMINVARIABLEVECTOR_H_
#define _DAC_DACCOMINVARIABLEVECTOR_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : daccominvariablevector.h                               */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Wed Mar  8 11:52:29 2000                               */
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
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $

#include "scsdefs.h"

class DacComInVariable ;

class DACCOM_API DacComInVariableVector
{
 public:
  DacComInVariableVector();
  ~DacComInVariableVector();

  void insert( DacComInVariable* var );
  unsigned int entries() ;
  DacComInVariable* at( unsigned int index );
  void clearAndDestroy() ;
  DacComInVariable* find( const DacComInVariable* toFind );
  int isEmpty() const ;
  DacComInVariable* removeFirst() ;

  int debugTrace( int level );

 private:
  void* _vector ;
};

#endif //. _DAC_DACCOMINVARIABLEVECTOR_H_
