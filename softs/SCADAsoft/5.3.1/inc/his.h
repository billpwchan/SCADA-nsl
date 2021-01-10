/******************************************************************************/
/*                                                                            */
/*  FILE                : his.h                                               */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY             : THALES IS                                           */
/*  CREATION DATE       : 1997/09/30                                          */
/*  LANGUAGE            : C++                                                 */
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
/******************************************************************************/
// IDENTIFICATION:
// $Id: his.h,v 1.16 1999/09/17 15:09:32 ylo Exp $
//
// HISTORY:
// $Log: his.h,v $
// Revision 1.16  1999/09/17 15:09:32  ylo
// Integrate reading of the disk archive data for trends
//
// Revision 1.15  1999/01/27 16:10:25  ylo
// Integration of queries.
//
// Revision 1.14  1999/01/20 10:13:42  ylo
// Add Mux/Demux for hisserver.
//
// Revision 1.13  1999/01/15 10:18:58  jpu
// Add isAttributeInArchive() method and change the meaning of the securityFlag
// parameter
//
// Revision 1.12  1998/07/24 16:31:15  jpu
// Add period parameter in HisServer::createArchive() for periodical archive creation
//
// Revision 1.11  1998/06/30 15:32:15  jpu
// Add name of quality field
//
// Revision 1.10  1998/05/28 18:15:10  jpu
// Change all long parameters to int for port on DEC OSF1 v4.0
//
// Revision 1.9  1998/04/06 09:49:54  jpu
// Modifications related to security
//
// Revision 1.8  1998/03/13 13:38:47  bertrand
// add define HisTrace
//
// Revision 1.7  1998/02/04 10:52:40  jpu
// Add getPointNames()
//
// Revision 1.6  1997/12/05 15:37:59  bertrand
// incorporate comments for doc++
//
// Revision 1.5  1997/11/18 15:50:06  jpu
// Add default value for environment and serverName parameters of HisServer()
//
// Revision 1.4  1997/11/18 13:48:07  jpu
// Modify HisServer() to include environment
//
// Revision 3.16.0 31/10/2003 kll 
// FFT SRC 582 - Ajout de la méthode unreadArchive
//
// Revision 4.3.0  11/08/2004 KLL
// FFT SRC-773 - Pb de retour lors d'un queryArchive
//
/******************************************************************************/
#ifndef _HIS_H
#define _HIS_H

/**
  \file
  \brief Access to the History server for archive management.
*/

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT                                                               */
/*----------------------------------------------------------------------------*/
#include "scs.h"
#include "ols.h"
#include "histypes.h"

class HisClient_i;
class HisDbClient_i;
class HisProxyRWGSlist;
class HisDbvInfos;
class HisOptInfos;
class HisAttribList;
class ScsString;
    
/**
   \brief This class allows the use of the management of archive services exported 
   by the Historian Server.

   This class is the interface class for the services exported by the HIS
   server.  It is used for the management of archives.  Archives are used to
   store the values of points as they change with time.  One example of an
   application using archives is the graphical representation of variables in
   trends.
\code#include "his.h"\endcode
*/
class HIS_API HisServer : public OlsServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.  This function creates an interface object connected to the HIS server named <em>serverName</em> and running in logical environment <em>logicalEnv</em>.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required HIS server is running,
     \param serverName  [in]: name of the server (the use of the default name is recommended),
     \param priority  [in]: priority of the messages to the HIS server (only useful with redundancy).
     \par Return values:
     none.  The result of the connection can be obtained by calling the <em>getStatus()</em> function.
  */
  HisServer (const char*        logicalEnv = 0,
	     const char*        serverName = "HisServer",
	     ScsPriorityLevels  priority = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor.  This function closes the connection
     with the HisServer.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~HisServer ();
  //@}

    /**@name General member functions*/
    //@{ 
    /**
       \par Description:
     return the status of the connection to the HisServer.
       \par Parameters:
     none.
       \return
       \li \c ScsValid : success.
       \li \c HisHostServerError : cannot connect with the ascmanager
        process.
       \li \c HisORBError : cannot connect with the remote HisServer.
    */
    ScsStatus getStatus () const { return _status;};
  
    /**
       \par Description:
       this function deactivates the embedded CORBA services.
       \par Parameters:
       none.
       \return
       \li \c ScsValid : success.
       \li \c ScsError : error.
    */
    ScsStatus deactivate();

    /**
       \par Description:
     this function creates an archive with the
        specified <em>name</em>.  The created archive is composed of the attributes
        whose names are specified in the list <em>attributeNameList</em>.  <em>count</em>
        is the number of attribute names in the list.  The <em>period</em> parameter
        is set to 0 to create a non-periodical archive (default value) or to a
        non-null value to create a periodical archive (the units of the period
        are seconds).  Non-periodical archives are updated each time the value
        of any of the attributes composing the archive changes, while
        periodical archives are updated at each expiration of the period.
       \param name  [in]: archive name,
       \param size  [in]: size of the data element list stored in the
        archive,
       \param attributeNameList  [in]: list of attribute names composing the
        archive,
       \param count  [in]: number of attributes in the archive,
       \param period  [in]: period of the archive (0 for a non-periodical
        archive, non-zero value for a periodical archive).
       \param listType [in]: type of list used to store data for the archive,
        "LIMITED", "UNLIMITED" or "CIRCULAR".
       \param maxFiles [in]: maximum number of disc files used to store data
        for the archive (0 for a non-collectable archive)
       \param capacity  [in]: number of entries per disc file.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveCreationError : if an archive already exists with
        the same name,
       \li \c HisRtapFunctionError : if an Rtap function has returned an
        error,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus createArchive (const char      *name,
                             short            size,
                             const char     **attributeNameList,
                             short            count,
                             unsigned short   period = 0,
                             HisListType      listType = CIRCULAR,
                             unsigned short   maxFiles = 0,
                             unsigned short   capacity = 100);
    /**
       \par Description:
     this function creates an archive with the
        specified <em>name</em>.  The created archive is composed of the attributes
        whose names are specified in the list <em>attributeNameList</em>.  <em>count</em>
        is the number of attribute names in the list.  The <em>period</em> parameter
        is set to 0 to create a non-periodical archive (default value) or to a
        non-null value to create a periodical archive (the units of the period
        are seconds).  Non-periodical archives are updated each time the value
        of any of the attributes composing the archive changes, whilst
        periodical archives are updated at each expiration of the period.
       \param name  [in]: archive name,
       \param size  [in]: size of the data element list stored in the
        archive,
       \param attributeList  [in]: list of attribute names composing the
        archive,
       \param count  [in]: number of attributes in the archive,
       \param period  [in]: period of the archive (0 for a non-periodical
        archive, non-zero value for a periodical archive).
       \param listType [in]: type of list used to store data for the archive,
        "LIMITED", "UNLIMITED" or "CIRCULAR".
       \param maxFiles [in]: maximum number of disc files used to store data
        for the archive (0 for a non-collectable archive)
       \param capacity  [in]: number of entries per disc file.
       \param type  [in]: type of the archive, RTAP_ARCHIVE for an archive
        of values from the RTAP database, EXTERNAL_ARCHIVE for an archive
        updated by an external program.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveCreationError : if an archive already exists with
        the same name,
       \li \c HisRtapFunctionError : if an Rtap function has returned an
        error,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus createArchive (const char            *name,
                             short                  size,
                             const HisAttribList    attributeList,
                             short                  count,
                             unsigned short         period = 0,
                             HisListType            listType = CIRCULAR,
                             unsigned short         maxFiles = 0,
                             unsigned short         capacity = 100, 
                             HisArchiveType         type = RTAP_ARCHIVE);
    /**
       \par Description:
     this function deletes the archive corresponding to
        <em>name</em>.
       \param name  [in]: archive name.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus deleteArchive (const char *name);
    /**
       \par Description:
     this function clears the archive corresponding
        to <em>name</em>; that is, it removes all the attributes composing the
        archive.
       \param name  [in]: archive name.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus clearArchive (const char *name);
    /**
       \par Description:
     this function returns the names of all the
        attributes composing the archive specified by the <em>nameList</em>
        parameter.  The <em>count</em> parameter is set to the number of
        attributes.  If the <em>securityFlag</em> optional input parameter is set
        to 0 (default value), the security conditions for the current user
        are ignored and the names of all attributes composing the archive
        are returned.  If the <em>securityFlag</em> parameter is set to 1, only
        the names of attributes whose point categories (PC) match with
        current user read categories (URC) and whose attribute read groups
        (ARG) match with current user groups (UG) are returned. 
       \param archiveName  [in]: archive name,
       \param nameList  [out]: list of attribute names,
       \param count  [out]: number of attributes,
       \param securityFlag  [in]: security flag.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus getAttributeNames (const char   *archiveName,
                                 const char **&nameList,
                                 short        &count,
                                 short         securityFlag = 0);
    /**
       \par Description:
     this function returns the names of the
        archives managed by the hisserver in the <em>nameList</em> parameter.  The
        <em>count</em> parameter is set to the number of archives.  If the
        <em>securityFlag</em> optional input parameter is set to 0 (default value),
        the security conditions for the current user are ignored and all
        archive names are returned.  If the <em>securityFlag</em> parameter is set
        to 1, only the names of archives containing at least one attribute
        with read access are returned.
       \param nameList  [out]: list of attribute names,
       \param count  [out]: number of attributes,
       \param securityFlag  [in]: security flag.
       \return
       \li \c ScsValid : success.
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus getArchiveNames (const char **&nameList,
                               short        &count,
                               short         securityFlag = 0);
    /**  
       \par Description:
     this function returns in <em>result</em> 1
        if the specified attribute exists in the archive and the names of the
        associated fields (a NULL string if the field is not present) or 0
        otherwise.  If the <em>securityFlag</em> optional input parameter is set to
        0 (default value), the security conditions for the current user are
        ignored.  If the <em>securityFlag</em> parameter is set to 1, the
        information concerning an attribute is returned only if the point
        categories (PC) match with current user read categories (URC) and
        attribute read groups (ARG) match with current user groups (UG).
       \param attributeName  [in]: attribute name,
       \param archiveName  [in]: archive name,
       \param result  [out]: result of the test,
       \param qualityFieldName  [out]: name of the quality field associated
        with the attribute, if any,
       \param timestampFieldName  [out]: name of the timestamp field
        associated with the attribute, if any,
       \param securityFlag  [in]: security flag.
       \return
       \li \c ScsValid : success.
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus isAttributeInArchive (const char  *attributeName,
                                    const char  *archiveName,
                                    int         &result,
                                    const char *&qualityFieldName,
                                    const char *&timestampFieldName,
                                    short        securityFlag = 0);
    /**
       \par Description:
     this function forces a sampling for the attributes
        of the specified archive (<em>name</em>).
       \param archiveName  [in]: archive name.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus doSampling (const char *archiveName);
    /**
       \par Description:
     this function returns the <em>HisServer</em> time
            in milliseconds.
       \param time  [out]: the <em>HisServer</em> time.
       \return
       \li \c ScsValid : success.
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus getTime (int& time);
    /**
       \par Description:
     this function reads the values of attributes
        of the specified archive in memory (<em>archiveName</em>), matching
        the specified filter.
       \param addressList  [in]: specification of data items to be
        retrieved,
       \param result  [out]: dataset containing the matching values.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with
        the specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus read (const HisDataAddressList addressList,
                    HisDataSetList           *&result) const;
    /**
       \par Description:
     this function reads the values of attributes
        of the specified archive in memory and/or disc (<em>archiveName</em>),
        matching the specified filter and between the start and end times.
       \param addressList  [in]: specification of data items to be
        retrieved,
       \param startTime  [in]: start time,
       \param endTime  [in]: end time,
       \param result  [out]: dataset containing the matching values.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus readd (const HisDataAddressList   addressList,
                     int                        startTime,
                     int                        endTime,
                     HisDataSetList           *&result) const;
    /**
       \par Description:
     this function writes the values of attributes
        to the specified external archives in memory and/or disc
        (<em>archiveName</em>).
       \param dataSetList  [out]: dataset list containing the values
        to be written.
    */
    void write (HisDataSetList *dataSetList);
    /** 
       \par Description:
     this function subscribes the caller to the
        modifications on the data matching the filter. All the matching data which are added to 
        the archive are notified to the subscribed client using the notification callback previously set
        using <em>setCallback()</em> method. If a name is specified in the filter,
        then the subscribe method will try to retrieve a registered filter.
        Otherwise, the subscribe method will apply the filter as is.
       \param addressList  [in]: specification of data items to be
        retrieved,
       \param subscriptionId  [out]: subscription identifier,
       \param arg  [in]: user optional argument passed to the notification
         callback when called.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
       \sa setCallback()
    */

     ScsStatus subscribe (const HisDataAddressList  addressList,
                         int                      &subscriptionId,
                         void                     *arg = 0);
    /** 
       \par Description:
     Set the callback used for various replies to the clients by other methods.
       \param notificationCallback  [in]: user notification callback to be used
       \sa subscribe(), subscribeArchive()
    */
    void setCallback (HisCallback notificationCallback);
    /*! @copydoc HisServer::setCallback(HisCallback) */
    void setCallback (HisDbCallback notificationCallback);

   /**
       \par Description:
     this function cancels the subscription
        identified by id.
       \param subscriptionId  [out]: subscription identifier,
       \return
       \li \c ScsValid : success.
       \li \c HisSubsIdNotFound : if no subscription corresponding to
        the id was found.
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus unsubscribe (const int subscriptionId);
    /**
       \par Description:
     this function writes the values of attributes
        to the specified external archives in memory (<em>archiveName</em>), matching
        the specified filters.
       \param addressList  [in]: specification of data items to be
        written,
       \param valueList  [out]: dataset containing the matching values.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with
        the specified name,
       \li \c HisMatchError : if the data list elements do not match the
        address list
        the specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus write (const HisDataAddressList   addressList,
                     HisDataSetList            *valueList) const;
    /**
       \par Description:
     this function starts a query request for
            the specified archive and time interval.  A new query object is
            created and returned in the query parameter.  This query object
            contains the list of names and times of the disc files whose
            elements match the required time interval.
       \param archiveName  [in]: name of the remote archive,
       \param timeMin  [in]: start of the time range for the query,
       \param timeMax  [in]: end of the time range for the query,
       \param query  [out]: created query object.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus newQuery (const char  *archiveName,
                        int          timeMin,
                        int          timeMax,
                        HisQuery   *&query) const;
    
    /* ------------------------------------------------------------ */
    /* API for the new HisServer				    */
    /* -------------------------------------------------------------*/
     /**
       \par Description:
     this function saves the specified archive for
            the specified time interval.
       \param archiveName  [in]: name of the remote archive,
       \param startTime  [in]: start of the time range,
       \param endTime  [in]: end of the time range,
       \param path  [in]: path where the archive is saved,
       \param accessType  [out]: needed access type to save archive,
       \param callback  [in]: function callback,
       \param arg  [in]: optional parameter to the callback.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus saveArchive (const char		*archiveName,
			   unsigned long	startTime,
			   unsigned long	endTime,
			   const char		*path,
			   HisAccessType         &accessType,
			   HisNotifCallback	callback=0,
			   ScsAny		arg=0);
    
     /**
       \par Description:
     this function loads the specified archive stored
            in the specified path.
       \param archiveName  [in]: name of the remote archive,
       \param path  [in]: path where the archive is stored,
       \param id  [out]: id of the subscription,
       \param callback  [in]: function callback,
       \param arg  [in]: optional parameter to the callback.
       \return
       \li \c ScsValid : execution in progress, a callback will be send,
       \li \c HisErrNoProxy : no HisServer proxy was found,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus loadArchive (const char		*archiveName,
			   const char		*path,
			   unsigned int		&id,
			   HisNotifCallback	callback=0,
			   ScsAny		arg=0);
    /**
       \par Description:
     this function cancels the load identified by id
       \param loadId  [in]: load identifier.
       \return
       \li \c ScsValid : success.
       \li \c HisErrNoProxy : no HisServer proxy was found,
       \li \c HisErrLoadNotFound : No loading archive known
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus unloadArchive (unsigned int loadId);
    
     /**
       \par Description:
     this function reads the specified points of archive
              in the specified time range.
       \param startTime  [in]: start of the time range,
       \param endTime  [in]: end of the time range,
       \param pointSets  [in]: list of points sets to read,
       \param accessType  [out]: needed access type to read archive,
       \param callback  [in]: function callback,
       \param arg  [in]: optional parameter to the callback,
       \param loadId [in] : identifier returned by loadArchive API.
       \return
       \li \c ScsValid : execution in progress, a callback will be send,
       \li \c HisErrNoProxy : no HisServer proxy was found,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus readArchive (unsigned long		startTime,
			   unsigned long		endTime,
			   const HisPointSetList	&pointSets,   
			   HisAccessType		&accessType,
			   HisDbCallback		callback=0,
			   ScsAny			arg=0,
			   unsigned int			loadId = 0);

     /**
       \par Description:
     This function delete all elements got by HisServer::readArchive between startTime and EndTime
       \param archiveName  [in]: archive name,
       \param startTime  [in]: start of the time range,
       \param endTime  [in]: end of the time range.
       \param loadId [in] : identifier returned by loadArchive API.
       \return
       \li \c ScsValid : OK,
       \li \c HisErrNoProxy : no HisServer proxy was found,
       \li \c HisErrUnReadArchive : Can't execute unreadArchive for archive archiveName 
       in the interval [timeMin - timeMax],
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus unreadArchive (const char		*archiveName,
			     unsigned long	 startTime,
			     unsigned long	 endTime,
			     unsigned int        loadId=0);
    

     /**
       \par Description:
     this function queries the specified archive
              in the specified time range.
       \param archiveName  [in]: name of the remote archive,
       \param startTime  [in]: start of the time range,
       \param endTime  [in]: end of the time range,
       \param request  [in]: request,
       \param path  [in]: path to save the result of the query,
       \param accessType  [out]: needed access type to query archive,
       \param callback  [in]: function callback,
       \param arg  [in]: optional parameter to the callback,
       \param loadId [in] : identifier returned by loadArchive API.
       \return
       \li \c ScsValid : execution in progress, a callback will be send,
       \li \c HisErrNoProxy : no HisServer proxy was found,
       \li \c HisErrBadParam : one or more of parameters entered were incorrects,
       \li \c HisErrNoDBV : no DBV was found for the interval,
       \li \c HisErrArchiveNotFound : no archive was found,
       \li \c HisErrParseQuery : the request is incorrect,
       \li \c HisErrNoElementsToRead : no elements to read in the memory, in the disk and in the LT,
       \li \c HisInvalidColumnInList : if the archiveName is the eventList, 
       we verify if the all columns in the request are corrects 
       \li \c HisErrTypeFieldCriteria : type of the fields in the criteria are incorrects,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus queryArchive (const char		*archiveName,
			    unsigned long	startTime,
			    unsigned long	endTime,
			    const char		*request,
			    const char		*path,
			    HisAccessType	&accessType,
			    HisNotifCallback	callback=0,
			    ScsAny		arg=0,
			    unsigned int	loadId = 0);
     /**
       \par Description:
     this function subscribe points of the
			specified archives
       \param pointSets  [in-out]: sets of points of the subscription
       \param arg  [in]: optional parameter to the callback.
       \return
       \li \c ScsValid : success.
       \li \c HisErrNoSubscriptionDefined : No subscription defined,
       \li \c HisErrPointSet : Error Creation HisDbPointSet,
       \li \c HisORBError : if an ORB exception was caught.
       \sa setCallback()
    */
    ScsStatus subscribeArchive (HisPointSetList		&pointSets,
				ScsAny			arg=0);



     /**
       \par Description:
       this function subscribe points of the
			specified archives and read if necessary in the past
       \param startTimeList  [in]: start's list of the time range,
       \param pointSetsToRead  [in-out]: sets of points of the subscription,
       \param callback  [in]: function callback if reading was called,
       \param readArg  [in]: optional parameter to the callback of the reading,
       \param subscribeArg  [in]: optional parameter to the callback of the subscirption.
       \return
       \li \c ScsValid : success.
       \li \c HisErrNoSubscriptionDefined : No subscription defined,
       \li \c HisErrPointSet : Error Creation HisDbPointSet,
       \li \c HisORBError : if an ORB exception was caught.
       \sa setCallback()
    */
    ScsStatus subscribeAndReadArchive (unsigned long*	startTimeList,
				       HisPointSetList	&pointSetsToRead,
				       HisDbCallback	callback=0,
				       ScsAny		readArg=0,
				       ScsAny           subscribeArg=0);

    /**
       \par Description:
     this function mount in a database context 
			   the archive at the specified date
       \param archiveName  [in]: name of the remote archive,
       \param date  [in]: date,
       \param id  [out]: id of the mount,
       \param accessType  [out]: needed access type to mount archive,
       \param callback  [in]: function callback,
       \param arg  [in]: optional parameter to the callback,
       \param mountId [in] : identifier returned by mountArchive API.
       \return
       \li \c ScsValid : execution in progress, a callback will be send,
       \li \c HisErrNoProxy : no HisServer proxy was found,
       \li \c HisErrArchiveNotFound : no archive was found,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus mountArchive (const char		*archiveName,
			    unsigned long	date,
			    unsigned int	&id,
			    HisAccessType	&accessType,
			    HisMountCallback	callback=0,
			    ScsAny		arg=0,
			    unsigned int	mountId = 0);
     /**
       \par Description:
     this function umount  a database context
       \param mountId  [in]: id of the mount request
       \return
       \li \c ScsValid : success.
       \li \c error : 
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus umountArchive (unsigned int mountId);

    /**
       \par Description:
     this function snapshots on disk the archive at the specified date 
     as a binary snapshot of non static attributes.
       \param archiveName  [in]: name of the remote archive,
       \param path [in] : directory where the snapshot is saved,
       \param date  [in]: date,
       \param id  [out]: id of the mount,
       \param accessType  [out]: needed access type to mount archive,
       \param callback  [in]: function callback,
       \param arg  [in]: optional parameter to the callback,
       \param snapshotId [in] : identifier returned by snapshotArchive API.
       \return
       \li \c ScsValid : execution in progress, a callback will be send,
       \li \c HisErrNoProxy : no HisServer proxy was found,
       \li \c HisErrArchiveNotFound : no archive was found,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus snapshotArchive (const char	*archiveName,
			       unsigned long	date,
			       const char	*path,
			       unsigned int	&id,
			       HisAccessType	&accessType,
			       HisSnapshotCallback callback=0,
			       ScsAny		arg=0,
			       unsigned int	snapshotId = 0);

     /**
       \par Description:
     this function returns the specified archive list and contents.
       \param archiveName  [in]: name of the archive,
       \param archiLines  [out]: number of items returned in <em>archives</em>,
       \param histoLines  [out]: number of items returned in <em>histories</em>,
       \param archives  [out]: list of names and types of archives
       \param histories  [out]: characteristic of returned archives, such as the number of period, the list of disk files with start and end time, and so on.
       \return
       \li \c ScsValid : success.
       \li \c HisArchiveNotFoundError : if no archive was found with the
        specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus showArchives (const char		*archiveName,
			    unsigned long	&archiLines,
			    unsigned long       &histoLines,
			    char **             &archives,
			    char **             &histories);
    /**
       \par Description:
       Set the list of local HIS servers
       \param optServerNames  [in]: list of local HIS servers
       \param optServerCount  [in]: number of local HIS servers
       \par Return values:
       None.
    */
    void setOptServer(char** optServerNames,
		      short  optServerCount);
    /**
       \par Description:
       Reset the list of local HIS servers
       \par Parameters:
       None.
       \par Return values:
       None.
    */
    void resetOptServer();
    //@}
protected:
    HisProxy* getProxy (const char     *archiveName, 
			unsigned int    loadId,
			unsigned long	startTime,
			unsigned long	endTime,
			int            *idxProxy);

private:
    void getDbvInfos();
    HisClient_i    *_client;
    HisDbClient_i  *_dbClient;
    HisProxy       *_proxy;
    HisProxyRWGSlist   *_optProxies;// list of optional HisServer for restitution
    HisOptInfos    *_optInfos;
    char           *_userName;
    unsigned int    _requestId;	// id of the next request
    char          **_archNames; // temp array for archive names
    int             _archCount; // Nb of archive names in temp array
    HisDbvInfos    *_dbvInfos;     // Dbv Infos
};

/******************************************************************************/


/**
     \brief This class allows queries on data from the historic past on elements of
     archives for specified time periods.  

     It is the interface class for the
     services exported by the HIS server providing queries on historic past
     values.  It is used to get the list of disc files containing the subset of
     elements of an archive corresponding to a time period either still in
     memory, or saved on disc, using a filter on the attributes associated with
     the archive.
\code#include "his.h"\endcode
*/
class HIS_API HisQuery
{
public:
    /**@name Constructors / destructor*/
    //@{ 
    /**
       \par Description:
     destructor.  This function ends the corresponding
        request.
       \par Parameters:
     none.
       \par Return values:
     none.
    */
   ~HisQuery ();
    //@}

    /**@name General member functions*/
    //@{ 
    /**
       \par Description:
     returns the name of the archive accessed by the
        request.
       \par Parameters:
     none.
       \par Return values:
     the archive name.
    */
    const char *getArchiveName () const;
    /**
       \par Description:
     returns the identifier of the request.
       \par Parameters:
     none.
       \par Return values:
     the request identifier.
    */
    const char *getId () const;
    /**
       \par Description:
     returns the start time of the request.
       \par Parameters:
     none.
       \par Return values:
     the start time.
    */
    int getTimeMin () const { return _timeMin;};
    /**
       \par Description:
     returns the end time of the request.
       \par Parameters:
     none.
       \par Return values:
     the end time.
    */
    int getTimeMax () const { return _timeMax;};
    /**
       \par Description:
     returns the list of disc files containing the
        elements matching the request.
       \par Parameters:
     none.
       \par Return values:
     the list of disc files.
    */
    OlsList *getList () { return _list;};
    //@}

protected:
    HisQuery (HisProxy     *server,
              const char   *archiveName,
              int           timeMin,
              int           timeMax);

    ScsStatus getStatus() const { return _status;};
    

private:
    ScsStatus       _status;       // Internal status
    HisProxy       *_server;       // Historian server accessed by the query
    ScsString      *_archiveName;  // Name of the archive accessed by the query
    int             _timeMin;      // Min of the time interval
    int             _timeMax;      // Max of the time interval
    ScsString      *_id;           // Query request identifier
    OlsList        *_list;         // List of elements matching the time
                                   // requirements
    

    friend ScsStatus HisServer::newQuery (const char *, int, int,
                                          HisQuery *&) const;
};

#endif

