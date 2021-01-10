//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : imgmode.h                                              */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : Y. Lozinguez                                           */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Tue Sep  1 10:31:19 1998                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: imgmode.h,v 1.3 1999/01/26 09:29:13 ylo Exp $
//
// HISTORY:
// $Log: imgmode.h,v $
// Revision 1.3  1999/01/26 09:29:13  ylo
// Crash fixing.
//
// Revision 1.3  1999/01/14 15:17:27  ylo
// Only one state for snapshot (background and foreground)
//
// Revision 1.2  1998/12/14 14:12:29  ylo
// *** empty log message ***
//
// Revision 1.1  1998/09/03 14:18:30  ylo
// Initial revision
//


#ifndef _SCS_IMGMODE_H_
#define _SCS_IMGMODE_H_

enum ImgEnvironmentState {
  ImgDown,
  ImgInit,
  ImgOnlineNoStandby,
  ImgOnlineSnapshot,
  ImgOnline,
  ImgStandby,
  ImgStandbySync,
  ImgFailover,
  ImgOnlineIsolated,
  ImgStandbyIsolated,
  ImgOnlineInit,
  ImgStandbyInit,
  ImgStandbyCatchingUp
};

#endif
