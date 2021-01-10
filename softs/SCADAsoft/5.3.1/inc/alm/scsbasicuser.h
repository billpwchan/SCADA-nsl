/******************************************************************************/
/* The information contained in this document is proprietary to Thales IS     */
/*  and shall not be disclosed by the recipient to third persons without      */
/*  the written consent of Thales IS.                                         */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  FILE             : scsbasicuser.h                                         */
/*  FULL NAME        : ScsBasicUser                                           */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Thu Feb  7 11:58:36 2002                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*  ScsBasicUser represents an user automaton.                                */
/*............................................................................*/
/*  COMMENT                                                                   */
/*  ScsBasicAutomaton is an abstract class                                    */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*  This file describes ScsBasicUser's interface.                             */
/******************************************************************************/

#ifndef _SCSSCSBASICUSER_H_
#define _SCSSCSBASICUSER_H_

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scs.h"

class ScsBasicUser 
{
  //** FIELDS **************************************************************/ 
 private:
  //-- user's userId
  long  _userId;

  //** METHODS *************************************************************/
 public:
  //-- constructors
  ScsBasicUser ();
  ScsBasicUser (const long                  inUserId);
  //-- recopy function
  ScsBasicUser (const ScsBasicUser&         inBasicUser);
  //-- destructor
  virtual ~ScsBasicUser ();

  //-- set/get _userId attribut
  inline void setUserId (const long         inUserId)
    {
      if (_userId == 0) 
	_userId = inUserId; 
    };
  inline long getUserId () const 
    {
      return (_userId);
    };
  //-- verify the thresholds's lists between the user automaton and the value automaton
  virtual int verifyNewThreshold (void*     inNewThresholdTab, 
				  const int inNewThersholdNb, 
				  void*     inThresholdTab,
				  const int inThresholdNb) = 0;
  //-- Redondancy
  //--  safeguard
  virtual ScsStatus save (SCS_SL_STD(ostream) &outStream) = 0;
  // restoration
  virtual ScsStatus restore (SCS_SL_STD(istream) &inStream) = 0;
  
 protected:
  // user value automaton instance pointer
  inline void * getPointerUser () const 
    {
      return (void *) this;
    };

 private:
  ScsBasicUser& operator= (const ScsBasicUser& inBasicUser);
};

#endif

//** END of file scsbasicuser.h ********************************************/                        
