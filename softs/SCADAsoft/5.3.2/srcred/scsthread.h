/*-*-c++-*-*/
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsthread.h                                            */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : Y. Lozinguez                                           */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Tue Dec  8 13:09:31 1998                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
/* IDENTIFICATION:
// $Id: scsthread.h,v 1.5 1999/04/16 07:39:02 scadaref Exp $
//
// HISTORY:
// $Log: scsthread.h,v $
// Revision 1.5  1999/04/16 07:39:02  scadaref
// port on NT.
//
// Revision 1.4  1999/03/09 13:56:03  ylo
// Add ScsConditionImpl::timedWait return values.
//
// Revision 1.3  1999/03/01 13:09:18  ylo
// Add IPC semaphore on DEC.
//
// Revision 1.2  1999/02/15 13:55:47  ylo
// *** empty log message ***
//
// Revision 1.4  1999/01/19 13:21:57  ylo
// Change // comments to be conform with c89 features.
//
// Revision 1.3  1999/01/19 13:20:04  ylo
// Change // comments to be conform with c89 features.
//
// Revision 1.2  1999/01/13 11:51:39  ylo
// Add semaphore management
//
// Revision 1.1  1998/12/09 17:36:00  ylo
// Initial revision
*/


#ifndef _SCS_SCSTHREAD_H_
#define _SCS_SCSTHREAD_H_

#ifdef WIN32
#if _MSC_VER > 1200
#include <winsock2.h>
#endif
#include <windows.h>
#else
#include <pthread.h>
#endif
#include <stdlib.h>

#define SCS_INFINITE_TIMEOUT 0xFFFFFFFFL
#define SCS_SIGNALED 0
#define SCS_EXPIRED_TIMEOUT 1

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

#ifdef __cplusplus /* C++ API */

class ScsSemaphoreImpl;

class PTH_API ScsSemaphore {
public:
  ScsSemaphore(unsigned int count = 0);
  ScsSemaphore(const char *name, unsigned int count = 0);
  ~ScsSemaphore();

  void wait();
  void release(int nRelease);
  void unlink();
  int value();

private:
  ScsSemaphoreImpl *_semaphore;
};

class ScsLock;
class ScsConditionImpl;

class PTH_API ScsCondition {
public:
  ScsCondition();
  ~ScsCondition();

  void wait(ScsLock &);
  unsigned char timedWait(ScsLock&, unsigned long);
  void signal();
  void broadcast();

private:
  ScsConditionImpl *_condition;
};

class ScsLockImpl;

class PTH_API ScsLock {
public:
  ScsLock(int lightweight = 1);
  ScsLock(const ScsLock& lock);
  ScsLock(const char *name, int lightweight = 1);
  ~ScsLock();

  void	setName(const char *name);
  void	lock();
  void	unlock();
   /*
    * Try to grab the lock, if we fail then return
    * 1 to indicate that the lock is in use. If we succeed
    * then release the lock and return 0.
    */
  int	isLocked();

  int   isLightWeight();

private:
  ScsLockImpl *_lock;

  friend class ScsCondition;
  friend class ScsConditionImpl;
};

class PTH_API ScsScopedLock {
public:
  ScsScopedLock(ScsLock *lock) : _lock(lock)
    { if (_lock) _lock->lock(); }
  ~ScsScopedLock()
    { if (_lock) _lock->unlock(); }
private:
  ScsLock *_lock;
};

class ScsRwLockImpl;

class PTH_API ScsRwLock {
public:
  ScsRwLock();
  ~ScsRwLock();

  void	rdlock ();
  void	wrlock ();
  void	unlock ();

private:
  ScsRwLockImpl *_rwLock;
};

class ScsThreadImpl;

#ifdef WIN32
#define ScsThreadReturnType DWORD WINAPI
#else
typedef void * ScsThreadReturnType;
#endif

class PTH_API ScsThread {
public:
#ifdef WIN32
  typedef HANDLE ID;
  typedef LPTHREAD_START_ROUTINE Routine;
#elif defined(_SUNOS)
  typedef pthread_t ID;
  typedef void *(*Routine)(void *);
#else
  typedef pthread_t ID;
  typedef void *(*Routine)(void *);
#endif
  enum Priority {LOWEST, BELOW_NORMAL, NORMAL, ABOVE_NORMAL, HIGHEST};

  /*
  static inline void IdSetNull(ID &Id) {Id = 0;} 
  static inline int IdIsNull(const ID &Id) {return Id ? 0 : 1;}
  */

  static ID Self();
  static int Create(ID& id, Routine fct, void *arg, unsigned int stackSize = 0, unsigned int detach = 1);
  static int WaitFor(ID threadId, void *&exitCode);
  static void Kill(ID threadId);

  static void Exit(void * status);
  static void Sleep(unsigned int millisec);
  static void SetPriority(Priority prio);
  static unsigned long GetId();
};

extern "C" {
#endif

  /* C API */

#include "scsthread_c.h"

#ifdef __cplusplus
}
#endif

#endif
