/******************************************************************************/
/*                                                                            */
/*  FILE             : dacevfilteralgofactory.h                               */
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

#ifndef _DAC_DACEVFILTERALGOFACTORY_H_
#define _DAC_DACEVFILTERALGOFACTORY_H_

#include <dac.h>

class DacEVFilter;
class DacEVFilterAlgo;
class DacComInVariable;

class DACCOM_API DacEVFilterAlgoFactory {
public:
  DacEVFilterAlgo* createAlgo(const char* algodesc, DacComInVariable* currVar, DacEVFilter* filter);
  
  static DacEVFilterAlgoFactory* Instance();
  virtual ~DacEVFilterAlgoFactory();

protected:
  DacEVFilterAlgoFactory();

private:
  // forbidden
  DacEVFilterAlgoFactory(const DacEVFilterAlgoFactory&);
  DacEVFilterAlgoFactory& operator=(const DacEVFilterAlgoFactory&);

  class DacEVFilterAlgoFactoryImpl;

  DacEVFilterAlgoFactoryImpl* m_impl;
};

#endif