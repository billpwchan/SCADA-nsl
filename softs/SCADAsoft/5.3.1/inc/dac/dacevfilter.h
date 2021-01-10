/******************************************************************************/
/*                                                                            */
/*  FILE             : dacevfilter.h                                          */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : 2011-09-16                                             */
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
/*                                                                            */
/******************************************************************************/

#ifndef _DAC_DACEVFILTER_H_
#define _DAC_DACEVFILTER_H_

#include "dacevfilteralgo.h"

class DacEIV;
class DacComInVariable;
class DacComDevice;
class DacComClientIdl;

const int DacEVFilterTickInMS = 100;

class DACCOM_API DacEVFilter {
public:
  DacEVFilter(DacComDevice* dev);
  virtual ~DacEVFilter();
  
  void reserveSize(int size);
  void setDacComClient(DacComClientIdl* client);
  
  DacEVFilterAlgo::FilterState checkChattering(DacEIV* currEiv);

  void addVariable(DacComInVariable* currVar, const char* algodesc);

  void addToCountDownList(DacEVFilterAlgo* algo);

private:
  // forbidden
  DacEVFilter();
  DacEVFilter(const DacEVFilter&);
  DacEVFilter& operator=(const DacEVFilter&);

  // Implementation class
  class DacEVFilterImpl;
  
  DacEVFilterImpl* m_impl;
};

#endif