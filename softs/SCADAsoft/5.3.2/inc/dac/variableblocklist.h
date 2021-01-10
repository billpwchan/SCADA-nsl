//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : variableblocklist.h                                    */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : C. LAYES                                               */
/*  COMPANY          : THALES-IS                                              */
/*  CREATION DATE    : Mon Apr 18 17:24:18 2005                               */
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


#ifndef _SCS_VARIABLEBLOCKLIST_H_
#define _SCS_VARIABLEBLOCKLIST_H_

#include "scsdefs.h"

class DacVariableBlock;

class DACCOM_API VariableBlockList
{
 public:
  VariableBlockList(void);

  VariableBlockList(DacVariableBlock* a);

  VariableBlockList(const VariableBlockList& list);

  virtual ~VariableBlockList(void);

  void operator = (const VariableBlockList& list);

  virtual DacVariableBlock* get(void);

  virtual DacVariableBlock* append(DacVariableBlock* a);

  virtual bool isEmpty(void);

  virtual unsigned int entries(void);

private:
  friend class VariableBlockIterator;

  void* getList(void) const
    { return _list; }

  void* _list;
};


class DACCOM_API VariableBlockIterator
{
 public:
  VariableBlockIterator(VariableBlockList& list);

  ~VariableBlockIterator(void);

  DacVariableBlock* operator()();

 private:
  void* _it;
};


#endif
