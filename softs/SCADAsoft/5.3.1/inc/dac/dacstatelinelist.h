//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : dacstatelinelist.h                                     */
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


#ifndef _SCS_DACSTATELINELIST_H_
#define _SCS_DACSTATELINELIST_H_

#include "scsdefs.h"

class DacStateLine;

typedef int (*yourTesterDacStateLine)(const DacStateLine*, const void*);

class DACCOM_API DacStateLineList
{
 public:
  DacStateLineList(void);

  DacStateLineList(DacStateLine* a);

  DacStateLineList(const DacStateLineList& list);

  virtual ~DacStateLineList(void);

  void operator = (const DacStateLineList& list);

  virtual DacStateLine*& at(unsigned int i);

  virtual DacStateLine* get(void);

  virtual DacStateLine* append(DacStateLine* a);

  virtual DacStateLine* find(yourTesterDacStateLine t, const void* d);

  virtual bool isEmpty(void);

  virtual unsigned int entries(void);

private:
  friend class DacStateLineIterator;

  void* getList(void) const
    { return _list; }

  void* _list;
};


class DACCOM_API DacStateLineIterator
{
 public:
  DacStateLineIterator(DacStateLineList& list);

  ~DacStateLineIterator(void);

  DacStateLine* operator()();

 private:
  void* _it;
};


#endif
