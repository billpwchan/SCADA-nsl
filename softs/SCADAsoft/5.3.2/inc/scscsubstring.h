//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scscsubstring.h                                        */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : D. LAYES                                               */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Mon Apr 25 11:32:06 2005                               */
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


#ifndef _SCS_SCSCSUBSTRING_H_
#define _SCS_SCSCSUBSTRING_H_

#include <scsdefs.h>

class SCS_API ScsCSubString
{
 public:
  ScsCSubString(const ScsCSubString& sp);

  ~ScsCSubString(void);

  ScsCSubString& operator =(const ScsCSubString& ss);

  const char* startData(void) const;

  const char* data(void) const;

  private :
    friend class ScsCString;

  ScsCSubString(void* ss);

  void* _subString;
};

#endif

