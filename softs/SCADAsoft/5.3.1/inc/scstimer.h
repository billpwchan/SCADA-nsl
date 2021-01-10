/******************************************************************************/
/*									      */
/*  FILE		: scstimer.h                                          */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1997/09/30					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	                                				      */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
// IDENTIFICATION:
// $Id: scstimer.h,v 1.3 1999/11/04 17:09:36 ylo Exp $
//
// HISTORY:
// $Log: scstimer.h,v $
// Revision 1.3  1999/11/04 17:09:36  ylo
// Removes scsthread.h from scstimer.h
//
// Revision 1.2  1999/10/22 08:50:08  ylo
// FFT CA 146
// Makes ScsTimer and AscRecord thread safe
//
// Revision 1.1  1998/12/07 13:47:04  ylo
// Initial revision
//
//
/******************************************************************************/
#ifndef _SCS_TIMER_H
#define _SCS_TIMER_H

/** \file
    \brief Timer management.
*/

#ifdef __osf__
#include <sys/time.h>
#else
#include <time.h>
#endif

#include "scs.h"
class ScsLock;

/**
\code#include "olstypes.h"\endcode
   Prototype of the function called asynchronously using the <em>ScsTimer</em> class. The <em>arg</em> parameter is a user optional argument provided at the <em>ScsTimer</em> object creation and passed as parameter of the callback when called. <b>Warning: if deleted in the expiration callback function, the deletion of a timer object should absolutely be the last instruction.</b>
*/
typedef void (*TimerCallbackFunction)(void *arg);

class TimeClient_i;

/**
   \brief The <em>ScsTimer</em> class provides a mean of calling asynchrounously a callback function.

\code#include "scstimer.h"\endcode
*/

class SCS_API ScsTimer
{
  friend class TimeClient_i;
  // ESA : 11/02/08 : add new friend classes
  friend class ScsIdTimer;
  friend class ScsTimerHandler;

public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It starts a timer with the specified characteristics. After timeout, the SCADAsoft library calls the expiration callback function with the <em>arg</em> argument. If <em>period</em> is not 0 (zero), the timer expires periodically with this value (specified in milliseconds). The first expiration time (<em>tv</em>) is specified as an absolute time, in seconds and microseconds.
     \param tv  [in]: timeval structure defining the first expiration time,
     \param period  [in]: period,
     \param function  [in]: user expiration callback function,
     \param arg  [in]: user optional argument passed as parameter of the callback when called.
     \param reSync  [in]: compute wakeuptime with the current Scadasoft Time (instead of previous wakeuptime).
     \param wakeUpSync  [in]: ask for oneway(0) or twoway(!=0) wakeUp (twoway is active only in redundant mode).
     \param kindOfTime  [in]: Scadasoft Time or OS Time (only in non redundant mode).
     \par Return values:
     none.
  */
  ScsTimer(const struct timeval       & tv, 
	   const unsigned int         & period, 
	   TimerCallbackFunction        function, 
	   void                       * arg = 0,
	   int                          reSync = NO_RESYNC,
           int                          wakeUpSync = SYNC,
	   int                          kindOfTime = SIMULATED_TIME);
 /**
     \par Description:
     constructor. It starts a timer with the specified characteristics. After timeout, the SCADAsoft library calls the expiration callback function with the <em>arg</em> argument. If <em>period</em> is not 0 (zero), the timer expires periodically with this value (specified in milliseconds). The first expiration time (<em>tv</em>) is specified as an absolute time, in seconds and microseconds. <em>delta</em> parameter defined an anticipation time in milliseconds to fit time to load processor.
     \param tv  [in]: timeval structure defining the first expiration time,
     \param period  [in]: period,
     \param delta  [in]: anticipation time, 
     \param function  [in]: user expiration callback function,
     \param arg  [in]: user optional argument passed as parameter of the callback when called.
     \param reSync  [in]: compute wakeuptime with the current Scadasoft Time (instead of previous wakeuptime).
     \param wakeUpSync  [in]: ask for oneway(0) or twoway(!=0) wakeUp (twoway is active only in redundant mode).
     \param kindOfTime  [in]: Scadasoft Time or OS Time (only in non redundant mode).
     \par Return values:
     none.
  */
  ScsTimer(const struct timeval        & tv, 
	   const unsigned int          & period,
	   const unsigned int          & delta,
	   TimerCallbackFunction         function, 
	   void *                        arg = 0,
	   int                           reSync = NO_RESYNC,
           int                           wakeUpSync = SYNC,
	   int                           kindOfTime = SIMULATED_TIME);

  /**
     \par Description:
     constructor. It starts a timer with the specified characteristics. After timeout, the SCADAsoft library calls the expiration callback function with the <em>arg</em> argument. If <em>period</em> is not 0 (zero), the timer expires periodically with this value (specified in milliseconds). The first expiration time (<em>delay</em>) is specified as a relative time, in milliseconds.
     \param delay  [in]: delay defining the first expiration time,
     \param period  [in]: period,
     \param function  [in]: user expiration callback function,
     \param arg  [in]: user optional argument passed as parameter of the callback when called.
     \param reSync  [in]: compute wakeuptime with the current Scadasoft Time (instead of previous wakeuptime).
     \param wakeUpSync  [in]: ask for oneway(0) or twoway(!=0) wakeUp (twoway is active only in redundant mode).
     \param kindOfTime  [in]: Scadasoft Time or OS Time (only in non redundant mode).
     \par Return values:
     none.
  */
  ScsTimer(const unsigned int          & delay,
	   const unsigned int          & period, 
	   TimerCallbackFunction         function,
	   void                        * arg = 0,
	   int                           reSync = NO_RESYNC,
           int                           wakeUpSync = SYNC,
	   int                           kindOfTime = SIMULATED_TIME);

  /**
     \par Description:
     constructor. It starts a timer with the specified characteristics. After timeout, the SCADAsoft library calls the expiration callback function with the <em>arg</em> argument. If <em>period</em> is not 0 (zero), the timer expires periodically with this value (specified in milliseconds). The first expiration time (<em>delay</em>) is specified as a relative time, in milliseconds. <em>delta</em> parameter defined an anticipation time in milliseconds to fit time to load processor.  
     \param delay  [in]: delay defining the first expiration time,
     \param period  [in]: period,
     \param delta  [in]: anticipation time,   
     \param function  [in]: user expiration callback function,
     \param arg  [in]: user optional argument passed as parameter of the callback when called.
     \param reSync  [in]: compute wakeuptime with the current Scadasoft Time (instead of previous wakeuptime).
     \param wakeUpSync  [in]: ask for oneway(0) or twoway(!=0) wakeUp (twoway is active only in redundant mode).
     \param kindOfTime  [in]: Scadasoft Time or OS Time (only in non redundant mode).
     \par Return values:
     none.
  */
  ScsTimer(const unsigned int           & delay, 
	   const unsigned int           & period, 
	   const unsigned int           & delta,
	   TimerCallbackFunction          function, 
	   void                         * arg = 0,
	   int                            reSync = NO_RESYNC,
           int                            wakeUpSync = SYNC,
	   int                            kindOfTime = SIMULATED_TIME);

  /**
     \par Description:
     destructor. It cancels the timer. <b>Warning: if called in the expiration callback function, this destructor should absolutely be the last instruction.</b>
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~ScsTimer();
  //@}

  /**@name General member functions*/
  //@{  
  /**
     \par Description:
     this function returns the status of the created timer.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsORBError : in case of error in the communication with the local <em>scstimekeeper</em> process.
  */
  ScsStatus getStatus() const { return _status;};
  /**
     \par Description:
     this function returns the next expiration time of the timer.
     \par Parameters:
     none.
     \par Return values:
     next expiration time.
  */
  timeval getWakeUpTime() const { return _wakeUpTime;};
  /**
     \par Description:
     this function returns the period of the timer.
     \par Parameters:
     none.
     \par Return values:
     period of the timer.
  */
  unsigned int getPeriod() const { return _period;};
 /**
     \par Description:
     this function returns the first next expiration time of the timer.
     \par Parameters:
     none.
     \par Return values:
     first next expiration time.
  */
  timeval getFirstWakeUpTime() const {return _firstWakeUpTime;};
  /**
     \par Description:
     this function returns the anticipation time of the timer.
     \par Parameters:
     none.
     \par Return values:
     anticipation time.
  */
  unsigned int getDelta() const {return _delta;};
  /**
     \par Description:
     this function returns the type of call for wakeUp.
     \par Parameters:
     none.
     \par Return values:
     type of call for wakeUp (ONEWAY/SYNC).
  */
  int          getWakeUpSync() { return _wakeUpSync; };
  /**
     \par Description:
     this function returns the mode use to compute the next wakeUpTime.
     \par Parameters:
     none.
     \par Return values:
     mode (NO_RESYNC/RESYNC).
  */
  int          getReSyncMode() { return _reSync; };
  /**
     \par Description:
     this function returns the kind of time to use.
     \par Parameters:
     none.
     \par Return values:
     mode (SIMULATED_TIME/OS_TIME).
  */
  int          getKindOfTime() { return _kindOfTime; };
  /**
     \par Description:
     set user information in order to identify the callback clearly.
     \par Parameters:
     user information has string.
     \par Return values:
     none.
  */
  void setInfo(char *);
  /**
     \par Description:
     cancel and delete a timer. <b>Warning: if called in the expiration callback function, this function should absolutely be the last instruction.</b>
     \par Parameters:
     the timer to cancel and delete.
     \par Return values:
     user optional argument (parameter of the callback when called) if passed to the constructor. Return NULL otherwise.
  */
  static void *cancelTimer(ScsTimer *timer);
  //@}
  /**@name Typedefs / defines*/
  /*@{*/
  /**
      \par Description:
     enum corresponding to the computation type of the next wakeUp time.
      \code
      enum ReSyncMode {
         NO_RESYNC = 0,
         RESYNC
      }; \endcode
      \par Values:
      \li \c NO_RESYNC:  the next wakeUp time will be current one increased by one period 
      \li \c RESYNC:     the next wakeUp time will be current scadasoft time increased by one period.
  */
  typedef enum  ReSyncMode {
    NO_RESYNC = 0,
    RESYNC
  } ReSyncMode;
  /**
      \par Description:
     enum corresponding to the calling type of wakeUp .
      \code
      enum wakeUpMode {
         ONEWAY = 0,
         SYNC
      }; \endcode
      \par Values:
      \li \c ONEWAY:  the wakeUp calls will be oneway (asynchronous)
      \li \c SYNC:    the wakeUp calls will be twoway (synchonous).
  */
  typedef enum WakeUpMode {
    ONEWAY = 0,
    SYNC
  } WakeUpMode;
  /**
      \par Description:
     enum corresponding to the kind of time used by the timer.
      \code
      enum KindOfTime {
         SIMULATED_TIME = 0,
         OS_TIME
      }; \endcode
      \par Values:
      \li \c SIMULATED_TIME :  the timer will expired according to simulated time 
      \li \c OS_TIME        :  the timer will expired according to os time 
  */
  typedef enum KindOfTime {
    SIMULATED_TIME = 0,
    OS_TIME
  } KindOfTime;
  /*}@*/

  unsigned long getTimerId() const { return _id; }
  
  
  // internal methods
  timeval computeInitialWakeUp(timeval tv);
  int getTimekeeperFrequency();

private:
  void initialize();

  // ESA : 11/02/08 : following functions must be private
  void wakeUp();
  void setTimerId( unsigned long id) { _id = id; }

  ScsStatus              _status;
  timeval                _wakeUpTime;
  timeval                _firstWakeUpTime;   
  unsigned int           _period;
  TimerCallbackFunction  _function;
  void                  *_arg;
  unsigned int           _delta;
  unsigned long          _id;
  int                    _reSync;
  int                    _wakeUpSync;
  char                  *_timerInfo;
  int                    _kindOfTime;
  int                    _frequency;

  static unsigned long  _ID;  
  static TimeClient_i *TheTimeClient;
};

#endif
