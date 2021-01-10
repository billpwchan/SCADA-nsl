/******************************************************************************/
/*									      */
/*  FILE		: scswdg.h                                            */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 2003/09/05					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Definition of C++ class ScsWdg providing ORB client access to         */
/*	the SCADAsoft watchdog component.                                     */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
// IDENTIFICATION:
// $Id$
//
// HISTORY:
// $Log$
/******************************************************************************/
#ifndef _SCSWDG_H
#define _SCSWDG_H

/** \file
    \brief Access to the the SCADAsoft watchdog component.
*/

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#ifdef WIN32
#include <time.h>
#include <windows.h>
#else
#include <sys/time.h>
#endif
#include "scs.h"
#include "manager.h"

// Definition of ScsWdg module trace function
#define ScsWdgTrace	ScsTraceFunction(SCSWDG_SCSMODULE)

class ShmPage2;

/**
   \brief This class is the interface class for the exported services of the <em>ScsWdg</em> component (SCADAsoft watch-dog).

 it allows the application to add specific information for the AscManager switch algorithm.
\code#include "scswdg.h"\endcode
*/
class ScsWdg {

public:
  /**@name Typedefs / defines*/
  //@{
  /**
      \par Description:
     enum corresponding to the possible values for network synthesis given by the application.
      \code
      enum WorkingStatus { 
         NETWORK_OK = 1,
         NETWORK_NOT_OK
      }; \endcode
      \par Values:
      \li \c NETWORK_OK : the local network can communicate.
      \li \c NETWORK_NOT_OK : the local network cannot communicate.
  */
  enum NetworkStatus { 
    NETWORK_OK = 1,
    NETWORK_NOT_OK
  };

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates the connection with the SCADAsoft watchdog.
     \par Parameters:
     none.
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  ScsWdg();
  
  /**
     \par Description:
     destructor. This function closes the connection with the SCADAsoft watchdog.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~ScsWdg();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the ScsWdg object.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : in other cases.
  */
  ScsStatus getStatus() const { return _status;};
  
  /**
     \par Description:
     this function set the network status.
     \param netStatus  [in]: network status.
     \return
     \li \c ScsValid : success,
     \li \c ScsError : in other cases.
  */
  ScsStatus updateInfo(NetworkStatus netStatus);

   /**
     \par Description:
     this function retrieves the last network status written.
     \par Parameters:
     none.
     \par Return value:
     \li \c NETWORK_OK : no network failure,
     \li \c NETWORK_NOT_OK : network failure,
  */
  NetworkStatus getNetworkStatus();
  
  /**
     \par Description:
     this function retrieves the last time the network status has been update.
     \par Parameters:
     none.
     \par Return value:
     \li \c timeval : time as a timeval structure,
  */
  timeval getLastUpdateTime();

  //@}

private:

  ScsStatus      _status;
  ScsShmPage2   *_pInfo;
};

#endif
