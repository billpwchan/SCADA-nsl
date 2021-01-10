#ifndef _DAC_DACCOMOUTVARIABLEVECTOR_H_
#define _DAC_DACCOMOUTVARIABLEVECTOR_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomoutvariablevector.h                              */
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

class DacComOutVariable ;

class DACCOM_API DacComOutVariableVector
{
 public:
  DacComOutVariableVector();
  ~DacComOutVariableVector();

  void insert( DacComOutVariable* var );
  unsigned int entries() ;
  DacComOutVariable* at( unsigned int index );
  void clearAndDestroy() ;
  DacComOutVariable* find( const DacComOutVariable* toFind );
  int isEmpty() const ;
  DacComOutVariable* removeFirst() ;

  int debugTrace( int level );

 private:
  void* _vector ;
};

#endif //. _DAC_DACCTLOUTVARIABLEVECTOR_H_
