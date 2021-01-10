//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomdevicelist.h                                     */
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


#ifndef _SCS_DACCOMDEVICELIST_H_
#define _SCS_DACCOMDEVICELIST_H_

#include "scsdefs.h"

class DacComDevice;

typedef int (*yourTesterDacComDevice)(const DacComDevice*, const void*);

class DACCOM_API DacComDeviceList
{
 public:
  DacComDeviceList(void);

  DacComDeviceList(DacComDevice* a);

  DacComDeviceList(const DacComDeviceList& list);

  virtual ~DacComDeviceList(void);

  void operator = (const DacComDeviceList& list);

  virtual DacComDevice* get(void);

  virtual DacComDevice* append(DacComDevice* a);

  virtual DacComDevice* find(yourTesterDacComDevice t, const void* d);

  virtual bool isEmpty(void);

  virtual unsigned int entries(void);

private:
  friend class DacComDeviceIterator;

  void* getList(void) const
    { return _list; }

  void* _list;
};


class DACCOM_API DacComDeviceIterator
{
 public:
  DacComDeviceIterator(DacComDeviceList& list);

  ~DacComDeviceIterator(void);

  DacComDevice* operator()();

 private:
  void* _it;
};


#endif
