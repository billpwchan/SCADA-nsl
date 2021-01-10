//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomcommandvector.h                                  */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : M. Promonet                                            */
/*  COMPANY          : THALES                                                 */
/*  CREATION DATE    :                                                        */
/*  LANGUAGE         : C++                                                    */
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


#ifndef _DAC_DACCOMCOMMANDVECTOR_H_
#define _DAC_DACCOMCOMMANDVECTOR_H_

#include "scsdefs.h"
#include "daccomcommand.h"

class DACCOM_API DacComCommandVector : public SCS_SL_STD(vector)<DacComCommand*> {
 public:
  DacComCommandVector(DacComCommandList& );
  DacComCommandVector(const DacComCommandVector& );
  DacComCommandVector& operator=(const DacComCommandVector& );
  virtual ~DacComCommandVector();
  virtual void debugTrace( int level, int inhibTrace = 0 );
};

extern DACCOM_API int debugTrace( int level, DacComCommandVector&);

#endif // _DAC_DACCOMCOMMANDVECTOR_H_
