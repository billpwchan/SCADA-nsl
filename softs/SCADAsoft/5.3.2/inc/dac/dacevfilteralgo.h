/******************************************************************************/
/*                                                                            */
/*  FILE             : dacevfilteralgo.h                                      */
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

#ifndef _DAC_DACEVFILTERALGO_H_
#define _DAC_DACEVFILTERALGO_H_

#include <dac.h>

class DacEVFilter;

class DACCOM_API DacEVFilterAlgo {
public:
  DacEVFilterAlgo(DacEVFilter* f) : m_filter(f), m_tickCounter(0) {}

  enum FilterState {
    NoChangeFilterState,
    ChangeFilterState,
    NoSendFilterState
  };
  
  virtual FilterState run(DacEIV* currEiv) = 0;
  virtual DacEIV* wakeUp() = 0;
    
  inline void setTickCounter(int t) { m_tickCounter = t; }
  inline int getTickCounter() const { return m_tickCounter; }
  
protected:
  DacEVFilter* m_filter;
  int m_tickCounter;

private:
  DacEVFilterAlgo();
  DacEVFilterAlgo(const DacEVFilterAlgo&);
  DacEVFilterAlgo& operator=(const DacEVFilterAlgo&);
};

#endif