//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : dactimerobjectlist.h                                   */
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


#ifndef _SCS_DACTIMEROBJECTLIST_H_
#define _SCS_DACTIMEROBJECTLIST_H_


class DacTimerObject;

class DacTimerObjectList
{
 public:
  DacTimerObjectList(void);

  DacTimerObjectList(DacTimerObject* a);

  DacTimerObjectList(const DacTimerObjectList& list);

  virtual ~DacTimerObjectList(void);

  void operator = (const DacTimerObjectList& list);

  virtual DacTimerObject* get(void);

  virtual DacTimerObject* append(DacTimerObject* a);

  virtual bool isEmpty(void);

  virtual DacTimerObject* removeReference(const DacTimerObject* e);

  virtual unsigned int entries(void);

private:
  friend class DacTimerObjectIterator;

  void* getList(void) const
    { return _list; }

  void* _list;
};


class DacTimerObjectIterator
{
 public:
  DacTimerObjectIterator(DacTimerObjectList& list);

  ~DacTimerObjectIterator(void);

  DacTimerObject* operator()();

 private:
  void* _it;
};


#endif
