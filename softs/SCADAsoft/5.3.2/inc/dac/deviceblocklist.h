//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : deviceblocklist.h                                      */
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


#ifndef _SCS_DEVICEBLOCKLIST_H_
#define _SCS_DEVICEBLOCKLIST_H_

#include "scsdefs.h"

class DacDeviceBlock;

class DACCOM_API DeviceBlockList
{
 public:
  DeviceBlockList(void);

  DeviceBlockList(DacDeviceBlock* a);

  DeviceBlockList(const DeviceBlockList& list);

  virtual ~DeviceBlockList(void);

  void operator = (const DeviceBlockList& list);

  virtual DacDeviceBlock* get(void);

  virtual DacDeviceBlock* append(DacDeviceBlock* a);

  virtual bool isEmpty(void);

  virtual unsigned int entries(void);

private:
  friend class DeviceBlockIterator;

  void* getList(void) const
    { return _list; }

  void* _list;
};


class DACCOM_API DeviceBlockIterator
{
 public:
  DeviceBlockIterator(DeviceBlockList& list);

  ~DeviceBlockIterator(void);

  DacDeviceBlock* operator()();

 private:
  void* _it;
};


#endif
