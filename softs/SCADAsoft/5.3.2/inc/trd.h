/******************************************************************************/
/*                                                                            */
/*  FILE                : trd.h                                               */
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
// $Id: trd.h,v 1.14 2000/02/01 15:35:22 scadaref Exp $
//
// HISTORY:
// $Log: trd.h,v $
// Revision 1.14  2000/02/01 15:35:22  scadaref
// SJS modification
// Following reintroduction of security functionality, I found a problem with
// trends - all my subscribes were failing.  On investigation, I found that when
// I do a subscribe, hisserver calls HisSecServerIdl_i::isAttributeInArchive
// with a null user name, and HisSecServerIdl_I::isAttributeInArchive then
// returns an error.  I traced this to the fact that each of the three calls to
// the function isAttributeInArchive in the file trdserver.cpp (i.e. to
// HisServer::isAttributeInArchive) do not specify the parameter securityFlag.
// This parameter defaults to 0, and is passed to
// ShisServerProxy::isAttributeInArchive, which then calls the server
// isAttributeInArchive with a user name of NULL.
//
// Revision 1.13  1999/09/17 15:09:26  ylo
// Integrate reading of the disk archive data for trends
//
// Revision 1.12  1999/01/27 10:47:38  jpu
// Modifications related to Quality and Timestamp fields
//
// Revision 1.11  1998/06/30 15:35:11  jpu
// Change the type of value returned by getQuality() method
//
// Revision 1.10  1998/05/28 18:17:01  jpu
// Change all long parameters to int for port on DEC OSF1 v4.0
//
// Revision 1.9  1998/03/13 13:39:21  bertrand
// add define TrdTrace.
//
// Revision 1.8  1998/01/02 14:05:16  bertrand
// modification of the TrdUpdateCallback signature
//
// Revision 1.7  1997/12/05 15:37:59  bertrand
// incorporate comments for doc++
//
// Revision 1.6  1997/12/02 15:54:32  jpu
// Modification of subscribe() and unsubscribe() for the subscription id
//
// Revision 1.5  1997/11/18 17:49:39  jpu
// Change the default value of serverName parameter of TrdServer()
//
// Revision 1.4  1997/11/18 15:48:54  jpu
// Add default value for environment and serverName parameters of TrdServer()
//
// Revision 1.3  1997/11/18 14:30:18  jpu
// Modify TrdServer() to include environment
//
/******************************************************************************/
#ifndef _TRD_H
#define _TRD_H

/** \file
    \brief Access to the the Trend server (TRD)
*/

#include "scs.h"
#include "his.h"

#define TrdTrace        ScsTraceFunction(TRD_SCSMODULE)
#define TrdTraceLevel(level, message) BaseTraceLevel(TRD_SCSMODULE, level, message)

enum TrdTraceLevel {
  TRD_ADM_LEVEL,
  TRD_ERR_LEVEL,
  TRD_OUT_LEVEL,
  TRD_IN_LEVEL,
  TRD_SOFT_LEVEL,
  TRD_TEST_LEVEL
};

#include "trddataset.h"
#include "trdhissubscription.h"
#include "trddataaddress.h"

class TrdHisSubscriptionList;
class TrdDataSetListList;
class TrdPointSetList;

/**
   \brief This class allows the use of attribute values stored in archives managed by 
   the Historian Server.

   This class is the interface class for the services exported by the TRD 
   component. It is used to retrieve the attribute values stored into archives.  
   The archives are used to store the values of attributes as they change with
   time and are managed by the historian server (<em>HisServer</em>). This class
   inherits from the <em>HisServer</em> class.
\code#include "trd.h"\endcode
*/

class TRD_API TrdServer : public HisServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     Factory.  This function creates an
     interface object connected to the HIS server named <em>serverName</em> and
     running in logical environment <em>logicalEnv</em>.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required HIS server is running,
     \param serverName  [in]: name of the server (the use of the default name is recommended),
     \param optServerNames  [in]: list of local HIS servers (not useful with RTAP database),
     \param optServerCount  [in]: number of local HIS servers (not useful with RTAP database),
     \param priority  [in]: priority of the messages to the HIS server (only useful with redundancy).
     \par Return values:
     A TrdServer instance.
  */
  static TrdServer* GetTrdServer (const char*        logicalEnv = 0,
				  const char*        serverName = "HisServer",
				  char**             optServerNames = 0,
				  short              optServerCount = 0,
				  ScsPriorityLevels  priority = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     Destructor.  This function closes the
     connection with the HisServer.
     \param trdServer [in]: instance pointer to delete.
     \par Return values:
     none.
  */
  static void DeleteTrdServer(TrdServer* trdServer);
  //@}
  
    /**@name General member functions*/
    //@{ 
  
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
     this function returns every data item in
       the archive whose timestamp is within the specified time interval 
       (delimited by <em>startTime</em> and <em>endTime</em> expressed in milliseconds).
       \param addressList  [in]: couples (archive name,attribute name)
       \param dataSetList  [out]: datasetlist containing the resulting values (not used 
       for the new HisServer because reading is not synchronous),
       \param startTime  [in]: start of time interval,
       \param endTime  [in]: end of time interval,
       \param arg  [in] : user optional argument passed to the notification
       callback when called (used only for the new HisServer).
       \return
       \li \c ScsValid : success.
       \li \c TrdBadAttributeError : if the attribute does not exist in the 
       specified archive,
       \li \c HisArchiveNotFoundError : if no archive was found with the
       specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus read (const TrdDataAddressList&   addressList,
                    TrdDataSetList           *&dataSetList,
                    int                        startTime,
                    int                        endTime,
		    ScsAny                    arg = 0);
    /**
       \par Description:
     this function returns every data of the
       archive which timestamp is within the specified time interval (delimited
       by <em>startTime</em> and <em>endTime</em> expressed in milliseconds).
       \param addressList  [in]: couples (archive name,attribute name)
       \param dataSetList  [out]: datasetlist containing the resulting values, (not used 
       for the new HisServer because reading is not synchron),
       \param startTime  [in]: start of time interval,
       \param endTime  [in]: end of time interval.
       \param arg  [in] : user optional argument passed to the notification
       callback when called (used only for the new HisServer).
       \return
       \li \c ScsValid : success.
       \li \c TrdBadAttributeError : if the attribute does not exist in the 
       specified archive,
       \li \c HisArchiveNotFoundError : if no archive was found with the 
       specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus readd (const TrdDataAddressList&   addressList,
                     TrdDataSetList           *&dataSetList,
                     int                        startTime,
                     int                        endTime,
		     ScsAny                    arg = 0);
    /**
       \par Description:
     this function creates a subscription to 
       the attribute contained in the archive. Each update of the attribute is 
       received in the <em>notificationCallback</em> callback function. This 
       callback is a user defined function.
       If <em>period</em> is set to -1, all the data of the archive are sent in the
       first callback. If it is set to a positive number, only the data for 
       which the timestamp is more recent than <em>period</em> parameter (in
       seconds) are sent.
       \param addressList  [in]: names of the couple (archive,attribute)
       \param period  [in]: period value,
       \param subscriptionId  [out]: subscription identifier,
       \param notificationCallback [in]: notification callback funtion
       \param arg  [in]: user optional argument passed to the notification
       callback when called.
       \return
       \li \c ScsValid : success.
       \li \c TrdBadAttributeError : if attribute does not exist in the 
       specified archive,
       \li \c HisArchiveNotFoundError : if no archive was found with the 
       specified name,
       \li \c HisORBError : if an ORB exception was caught.
    */
    ScsStatus subscribe (const TrdDataAddressList&  addressList,
                         int                        period,
                         int                       &subscriptionId,
			 TrdUpdateCallback          notificationCallback,
                         ScsAny                     arg = 0);
    /**
       \par Description:
     this function cancels the subscription 
       identified by <em>subscriptionId</em>. 
       \param subscriptionId  [in]: subscription identifier returned by 
       the <em>subscribe()</em> method.
       \return
       \li \c ScsValid : success.
       \li \c TrdDataSetNotFoundError : if no subscription was found for 
       the specified subscription identifier. 
    */
    ScsStatus unsubscribe (int subscriptionId);
    /**
       \par Description:
     this function activates the security on
       the TRD component while connected to the historian server.
       \par Parameters:
     none.
       \return
       \li \c ScsValid : success.
    */
    ScsStatus setSecurity ();
    //@}

    void incrRefCount() {_refCount++;};
    void decrRefCount() {_refCount--;};
    unsigned int getRefCount() const {return _refCount;};
    const char* getEnvironment() const {return _environment;};

    void executeNewCallback (const HisDbDataSetList& dataSetList, 
			     ScsStatus returnStatus);

    TrdHisSubscriptionList* getHisSubscriptionList () { return _hisSubscriptionList;};
    TrdDataSetListList* getTrdSubscriptionList () { return _trdSubscriptionList;};
    const TrdDataSetList* getTrdDataSetList(int id);

    friend SCS_SL_STD(ostream)& operator <<(SCS_SL_STD(ostream)& ostr, TrdServer& trdServer);

private:
    TrdServer (const char*        logicalEnv = 0,
	       const char*        serverName = "HisServer",
	       ScsPriorityLevels  priority = SCS_PRIORITY_NORMAL);
    ~TrdServer ();
     
     ScsStatus subscribe_new(const TrdDataAddressList&  addressList,
			     int                        period,
			     int                       &subscriptionId,
			     TrdUpdateCallback          notificationCallback,
			     ScsAny                     arg);
     ScsStatus read_new (const TrdDataAddressList&   addressList,
			 TrdDataSetList           *&dataSetList,
			 int                        startTime,
			 int                        endTime,
			 ScsAny                    arg);
     ScsStatus readd_new (const TrdDataAddressList&   addressList,
			  TrdDataSetList           *&dataSetList,
			  int                        startTime,
			  int                        endTime,
			  ScsAny                    arg);

    ScsStatus               _status;              // Internal status
    TrdHisSubscriptionList* _hisSubscriptionList; // List of HisServer subscriptions
    TrdDataSetListList*     _trdSubscriptionList; // List of TrdServer subscriptions
    short                   _securityFlag;

    TrdPointSetList	  * _pointSets;		// list of subscribed point sets

    unsigned int            _refCount;
    char*                   _environment;
};

#endif

