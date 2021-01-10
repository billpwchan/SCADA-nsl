/******************************************************************************/
/*                                                                            */
/*  FILE                : trd.h                                               */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY             : THALES IS                                           */
/*  CREATION DATE       : 1997/09/30                                          */
/*  LANGUAGE            : C++                                                 */
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
/******************************************************************************/
// IDENTIFICATION:
// $Id: trd.h,v 1.14 2000/02/01 15:35:22 scadaref Exp $
//
// HISTORY:
// $Log: trd.h,v $

#ifndef _TRDDATA_H_
#define _TRDDATA_H_

/** \file
    \brief Data used in Trend server context
*/

#include "scs.h"
#include "histypes.h"
class OlsDataSet;

/**
   \brief This class is one of the class of the <em>TRD</em> SCADAsoft component.

   A <em>TrdData</em> object represents a single value that can be displayed as a 
   single point on a trend. The objects of this class are contained in a 
   <em>TrdDataSet</em> object.
\code#include "trd.h"\endcode
*/
class TRD_API TrdData : public HisValue
{
 public:
  /**@name Constructors / destructor*/
  //@{
  TrdData(unsigned long time, int  value, unsigned int quality);
  TrdData(unsigned long time, float value, unsigned int quality);
  TrdData(unsigned long time, ScsINT64  value, unsigned int quality);
  TrdData(unsigned long time, double value, unsigned int quality);
 
  TrdData(const HisValue &value);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~TrdData ();
  //@}


 private:
  friend void trdServerCallback (const char *, int, const OlsDataSet &, void *);
};

#endif
