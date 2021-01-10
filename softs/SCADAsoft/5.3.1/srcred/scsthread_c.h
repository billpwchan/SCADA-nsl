/******************************************************************************/
/*                                                                            */
/*  FILE             : scsthread_c.h                                          */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : Y. Lozinguez                                           */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Mon Mar  8 08:57:24 1999                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
/* IDENTIFICATION:
// $Id: scsthread_c.h,v 1.1 1999/03/10 09:31:03 ylo Exp $
//
// HISTORY:
// $Log: scsthread_c.h,v $
// Revision 1.1  1999/03/10 09:31:03  ylo
// Initial revision
//
*/

#ifndef _SCS_SCSTHREAD_C_H_
#define _SCS_SCSTHREAD_C_H_

#ifdef WIN32
typedef struct {
  HANDLE _semHandle;
} ScsSemaphore_t;

#elif defined(HPUX)

typedef struct {
  int _semid;
  char *_name;
  int _creator;
} ScsSemaphore_t;

#else

#ifdef POSIXDEC
#include <semaphore.h>
#else
#include <sys/sem.h>
#endif

typedef struct {
#ifdef POSIXDEC
  sem_t _semid;
  sem_t *_semPtr;
#else
  int _semid;
#endif
  char *_name;
  int _creator;
} ScsSemaphore_t;

#endif

  void scsNamedSemInit(ScsSemaphore_t *sem, const char *name, unsigned int count);
  void scsSemInit(ScsSemaphore_t *sem, unsigned int count);
  void scsSemDestroy(ScsSemaphore_t *sem);
  int scsSemWait(ScsSemaphore_t *sem);
  void scsSemRelease(ScsSemaphore_t *sem, int nRelease);
  int scsSemGetValue(ScsSemaphore_t *sem);

#endif
