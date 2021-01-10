/******************************************************************************/
/*                                                                            */
/*  FILE                : thread.h                                            */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 02-01-10                                            */
/*  LANGUAGE            : C++                                                 */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*............................................................................*/
/*  CONTENTS                                                                  */
/******************************************************************************/
/* IDENTIFICATION:
 *
 * HISTORY:
 */
/******************************************************************************/

#ifndef __SCS_ecomlib_THREAD_H__
#define __SCS_ecomlib_THREAD_H__

// system
#include <string>

#include <scsthread.h>
#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

/**
 * @class Thread
 *
 * @brief Base class for all the extended com library thread, mimics java OO 
 *        thread API.
 */
class ECOMLIBIF_EXPORT Thread {
  
 public:
  
  /**
   * Destructor.
   */
  virtual ~Thread();
  
  /**
   * Start the thread run method.
   */
  void start();

  /**
   * Wait for the thread completion.
   */
  void join();

 protected:
  
  /**
   * Constructor.
   * Enable to specify the thread mode (attached, or detached).
   * By default, the thread is created in attached mode.
   *
   * @param detached : 1 stands for a detached thread, 
   * and 0 stands for a attached thread
   */
  Thread( unsigned int detached = 0 );

  /**
   * Constructor.
   *
   * @param name The thread logical name.
   */
  Thread( const char* name, unsigned int detached = 0 );

  /**
   * Return the thread's name assigned with the help
   * of the adapted constructor.
   */
  std::string getName();

  /**
   * The thread mainloop : subclasses of Thread should override this
   * method.
   */
  virtual void run()=0;
  
 private:

  /**
   * Flag to mention if the thread should be created 
   * in attached, or detached mode.
   */
  unsigned int _detached;
 
  /**
   * The thread's name.
   */
  std::string _name;

  /**
   * The underlying SCS thread mainloop.
   *
   * @param arg The corresponding Thread instance.
   */
  static ScsThreadReturnType Run(void* arg);
  
  /**
   * Thread state possible values.
   */
  enum STATE { IDLE, STARTING, RUNNING, STOPPED };
  
  /**
   * The thread state.
   */
  STATE         _state;
  
  /**
   * The underlying SCS thread identifier.
   */
  ScsThread::ID _threadId;
  
  /**
   * Copy constructor is private and not implemented.
   */
  Thread(const Thread&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  Thread& operator=(const Thread&);
  
};

};

#endif
