//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : imgmsgtag.h                                            */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : Y. Lozinguez                                           */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Fri Nov 27 14:35:14 1998                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: imgmsgtag.h,v 1.3 2000/02/28 12:32:57 jmb Exp $
//
// HISTORY:
// $Log: imgmsgtag.h,v $
// Revision 1.3  2000/02/28 12:32:57  jmb
// _currentTime and _currentIndex are now static
//
// Revision 1.2  1998/12/07 17:14:45  scadaref
// Port on Windows NT.
//
// Revision 1.1  1998/12/07 15:59:04  ylo
// Initial revision
//
#ifndef _SCS_IMGMSGTAG_H_
#define _SCS_IMGMSGTAG_H_

#include "scsredtype.hh"

#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef IMG_EXPORTS
        #define IMG_API __declspec(dllexport)
        #else
        #define IMG_API __declspec(dllimport)
        #endif
        
    #else
        #define IMG_API
    #endif
#else
    #define IMG_API
#endif

class ScsString;

class IMG_API ImgMsgTag {

public:

  ImgMsgTag();
  ImgMsgTag(const char * envName);
  ~ImgMsgTag(void);

  // specifyNbPhysEnv allows you to specify the nbPhysEnvRunning. If specified,
  // no call to GetNbPhysEnvRunning will be made
  void getTag(ScsMessageTag &msgTag, int specifyNbPhysEnv = -1);
  void getDummyTag(ScsMessageTag &msgTag);
  void getTagForWakeUp(ScsMessageTag &msgTag, timeval onlineTime, const char* clientName);

private:

  static CORBA::ULong _currentTime;
  static CORBA::ULong _currentIndex;
  CORBA::ULong        _pid;
  ScsString          *_environment;
  ScsString          *_name;
};

#endif
