//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : daceovlist.h                                           */
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


#ifndef _SCS_DACEOVLIST_H_
#define _SCS_DACEOVLIST_H_

#include "scsdefs.h"

class DacEOV;

class DACCOM_API DacEovList
{
 public:
  DacEovList(void);

  DacEovList(DacEOV* a);

  DacEovList(const DacEovList& list);

  virtual ~DacEovList(void);

  void operator = (const DacEovList& list);

  virtual DacEOV* get(void);

  virtual DacEOV* append(DacEOV* a);

  virtual bool isEmpty(void);

  virtual unsigned int entries(void);

private:
  friend class DacEovIterator;

  void* getList(void) const
    { return _list; }

  void* _list;
};


class DACCOM_API DacEovIterator
{
 public:
  DacEovIterator(DacEovList& list);

  ~DacEovIterator(void);

  DacEOV* operator()();

 private:
  void* _it;
};


#endif
