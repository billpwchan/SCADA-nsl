//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : daceivlist.h                                           */
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


#ifndef _SCS_DACEIVLIST_H_
#define _SCS_DACEIVLIST_H_

#include "scsdefs.h"

class DacEIV;
class ScsLock;

class DACCOM_API DacEivList
{
 public:
  DacEivList(void);

  DacEivList(DacEIV* a);

  DacEivList(const DacEivList& list);

  virtual ~DacEivList(void);

  void operator = (const DacEivList& list);

  virtual DacEIV* get(void);

  virtual DacEIV* append(DacEIV* a);

  virtual bool isEmpty(void);

  virtual unsigned int entries(void);

  virtual void lock(void);
  virtual void unlock(void);

private:
  friend class DacEivIterator;

  void* getList(void) const
    { return _list; }

  void* _list;
  ScsLock* _lock; 
};


class DACCOM_API DacEivIterator
{
 public:
  DacEivIterator(DacEivList& list);

  ~DacEivIterator(void);

  DacEIV* operator()();

 private:
  void* _it;
};


#endif
