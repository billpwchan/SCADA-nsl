/*-*-c++-*-*/
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsshmem.h                                             */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon Jan 18 17:59:33 1999                               */
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
/* IDENTIFICATION:
// $Id: scsshmem.h,v 1.3 1999/02/26 17:13:03 ylo Exp $
//
// HISTORY:
// $Log: scsshmem.h,v $
// Revision 1.3  1999/02/26 17:13:03  ylo
// Add error code in shared memory init functions.
//
// Revision 1.2  1999/01/20 11:45:07  ylo
// Add the opn function to attach an already existing segment of shared memory.
//
// Revision 1.1  1999/01/19 15:55:24  ylo
// Initial revision
//
*/

#ifndef _SCS_SCSSHMEM_H_
#define _SCS_SCSSHMEM_H_

#ifdef WIN32
#include <windows.h>

#else
#include <sys/shm.h>
#endif

#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef PTH_EXPORTS
        #define PTH_API __declspec(dllexport)
        #else
        #define PTH_API __declspec(dllimport)
        #endif
    #else
        #define PTH_API
    #endif
#else
    #define PTH_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

  /* C API */
  typedef enum {ScsShmReadWrite, ScsShmReadOnly} ScsShmProtection;
  typedef enum {ScsShmAccessAny, ScsShm64Only} ScsShmAccessMode;

#ifdef WIN32
typedef struct {
  HANDLE _shmHandle;
  void *_page;
} ScsSharedMemory_t;

#else

typedef struct {
  int _shmid;
  char *_name;
  void *_page;
} ScsSharedMemory_t;

#endif

  extern PTH_API int scsNamedShmInit(ScsSharedMemory_t *shm, const char *name, unsigned long size, ScsShmProtection protection, ScsShmAccessMode mode);
  extern PTH_API int scsNamedShmInit2(ScsSharedMemory_t *shm, const char *name, unsigned long size, ScsShmProtection protection);
  extern PTH_API int scsNamedShmOpen(ScsSharedMemory_t *shm, const char *name, ScsShmProtection protection);
  extern PTH_API int scsNamedShmOpen2(ScsSharedMemory_t *shm, const char *name, ScsShmProtection protection);
  extern PTH_API int scsShmInit(ScsSharedMemory_t *shm, unsigned long size, ScsShmProtection protection);
  extern PTH_API void scsShmDestroy(ScsSharedMemory_t *shm);
  extern PTH_API void scsShmDetach(ScsSharedMemory_t *shm);
  extern PTH_API int scsShmLock(const void* addr, unsigned long size);
  extern PTH_API int scsShmUnlock(const void* addr, unsigned long size);

#ifdef __cplusplus
}
#endif

#endif
