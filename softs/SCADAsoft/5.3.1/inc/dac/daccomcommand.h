//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomcommand.h                                        */
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


#ifndef _DAC_DACCOMCOMMAND_H_
#define _DAC_DACCOMCOMMAND_H_

#include "scsdefs.h"

#include <vector>
#include <list>

class DacComOutVariable;

class DACCOM_API DacComCommand
{
 public:
  DacComCommand(const DacComOutVariable* var, const unsigned char* buffer = NULL, const unsigned int size = 0);
  DacComCommand(const DacComCommand &);
  DacComCommand& operator=(const DacComCommand &);
  virtual ~DacComCommand();  

  const DacComOutVariable* getVariable() { return _var; };
  const unsigned char* getBuffer() const { return _buffer; };
  unsigned int getSize() const { return _size; };
  void setBuffer(const unsigned char* buffer, const unsigned int size );

  virtual void debugTrace( int level, int inhibTrace = 0 );

 protected:
  const DacComOutVariable* _var;
  unsigned int _size ;
  unsigned char* _buffer ;
};

int debugTrace( int level, DacComCommand&);

typedef SCS_SL_STD(list)<DacComCommand *>  DacComCommandList;

#endif // _DAC_DACCOMCOMMAND_H_
