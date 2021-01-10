/******************************************************************************/
/*									      */
/*  FILE		: sec.h                                               */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1998/02/18					      */
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
// $Id: sec.h,v 1.2 1999/06/30 16:34:37 ylo Exp $
//
// HISTORY:
// $Log: sec.h,v $
// Revision 1.2  1999/06/30 16:34:37  ylo
// Add Mux/Demux for secserver.
//
// Revision 1.1  1998/12/14 14:02:47  ylo
// Initial revision
//
// Revision 1.4  1998/05/28 18:16:28  jpu
// Change all long parameters to int for port on DEC OSF1 v4.0
//
// Revision 1.3  1998/04/16 12:58:05  jpu
// Add checkApplicationAccess() method
//
// Revision 1.2  1998/03/13 13:39:57  bertrand
// add define SecTrace.
//
// Revision 1.1  1998/02/23 21:02:24  jpu
// Initial revision
//
//
/******************************************************************************/
#ifndef _SEC_H
#define _SEC_H

/** \file
    \brief Access to the the SCADAsoft security server.
*/

#include "scs.h"
#define SecTrace	ScsTraceFunction(SEC_SCSMODULE)
#define SecTraceLevel(level, message) BaseTraceLevel(SEC_SCSMODULE, level, message)


class SecProxy;

/**
   \brief This class is the interface class for the exported services of the SCADAsoft security server.

   This server is in charge of managing the security user profiles (group mask, read and write categories masks, application list).
\code#include "sec.h"\endcode
*/
class SEC_API SecServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the security server (<em>SecServer</em>).
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required <em>SecServer</em> is running,
     \param serverName  [in]: name of the server (the use of the default name is recommended),
     \param priority  [in]: priority of the messages to the security server (only useful with redundancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  SecServer(const char*        logicalEnv = 0,
	    const char*        serverName = "SecServer",
	    ScsPriorityLevels  priority = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the security server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
 ~SecServer();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the SecServer.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c SecHostServerError : cannot connect with the ascmanager process.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus getStatus() const { return _status;};
  /**
     \par Description:
     returns the result of test of security activation. The <em>result</em> parameter is set to 1 if security is activated, 0 otherwise.
     \param result  [out]: result of the test.
     \return
     \li \c ScsValid : success.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus isSecurityActivated(unsigned short &result);
  /**
     \par Description:
     this function loads the profile associated with the specified user. A new user profile object is created in the security server, containing the security informations read into database (group mask, read and write categories masks, application list).
     \param userName  [in]: user name.
     \return
     \li \c ScsValid : success.
     \li \c SecORBError : cannot connect with the remote SecServer.
     \li \c SecUserFileOpenError: an error occurred opening file corresponding to user.
     \li \c SecUserFileIOError: an I/O error occurred for the user file. 
  */
  ScsStatus loadUserProfile(const char *userName);
  /**
     \par Description:
     this function unloads the user profile. The corresponding user profile object is removed from the security server.
     \param userName  [in]: user name.
     \return
     \li \c ScsValid : success.
     \li \c SecProfileNotFoundError: no profile was found for the specified user.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus unloadUserProfile(const char *userName);
  /**
     \par Description:
     this function tests if the specified user profile is loaded or not. The <em>result</em> parameter is set to 1 if user profile is loaded, 0 otherwise.
     \param userName  [in]: user name,
     \param result  [out]: result of the test.
     \return
     \li \c ScsValid : success.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus isUserProfileLoaded(const char *userName, unsigned short &result);
  /**
     \par Description:
     this function returns the group mask for the specified user.
     \param userName  [in]: user name,
     \param groupMask  [out]: group mask.
     \return
     \li \c ScsValid : success.
     \li \c SecProfileNotFoundError: no profile was found for the specified user.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus getGroupMask(const char *userName, unsigned short &groupMask);
  /**
     \par Description:
     this function returns the read categories mask for the specified user.
     \param userName  [in]: user name,
     \param readMask  [out]: read categories mask.
     \return
     \li \c ScsValid : success.
     \li \c SecProfileNotFoundError: no profile was found for the specified user.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus getReadCategoriesMask(const char *userName, unsigned int &readMask);
  /**
     \par Description:
     this function returns the write categories mask for the specified user.
     \param userName  [in]: user name,
     \param writeMask  [out]: write categories mask.
     \return
     \li \c ScsValid : success.
     \li \c SecProfileNotFoundError: no profile was found for the specified user.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus getWriteCategoriesMask(const char *userName, unsigned int &writeMask);
  /**
     \par Description:
     this function returns the list of applications the specified user may run.
     \param userName  [in]: user name,
     \param applicationList  [out]: application name list,
     \param count  [out]: number of application names.
     \return
     \li \c ScsValid : success.
     \li \c SecProfileNotFoundError: no profile was found for the specified user.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus getApplicationList(const char   *userName,
			       char       **&applicationList,
			       short        &count);
  /**
     \par Description:
     this function tests if the specified user may run the specified application. The <em>access</em> parameter is set to 1 if user has access to specified application, 0 otherwise.
     \param userName  [in]: user name,
     \param applicationName  [in]: application name,
     \param access  [out]: result of the test.
     \return
     \li \c ScsValid : success.
     \li \c SecProfileNotFoundError: no profile was found for the specified user.
     \li \c SecORBError : cannot connect with the remote SecServer.
  */
  ScsStatus checkApplicationAccess(const char *userName,
				   const char *applicationName,
				   short      &access);
  //@}

private:
  ScsStatus       _status;
  SecProxy       *_proxy;
};

#endif
