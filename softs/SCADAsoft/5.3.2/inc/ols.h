/******************************************************************************/
/*									      */
/*  FILE		: ols.h                                               */
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
// $Id: ols.h,v 1.5 1999/11/30 17:10:21 scadaref Exp $
//
// HISTORY:
// $Log: ols.h,v $
// Revision 1.5  1999/11/30 17:10:21  scadaref
// Port on MSVC6
//
// Revision 1.4  1999/09/17 12:43:43  scadaref
// Fix SPR ??? for Manchester (remote acknowledge on AlmServer)
//
// Revision 1.3  1998/12/15 16:18:07  ylo
// Create ols/libinternal for ascManager needs.
//
// Revision 1.2  1998/12/15 14:33:48  ylo
// Create ols/libinternal for ascManager needs.
//
// Revision 1.1  1998/12/07 13:38:47  ylo
// Initial revision
//
//
/******************************************************************************/
#ifndef _OLS_H
#define _OLS_H

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/

#include "scs.h"
#include "scstimer.h"
#include "olstypes.h"

class ScsString;


#define SCSTIME_FIELD_NAME "SCSTime"

/**
  \file
  \brief Remote access to OlsList objects
*/

class OlsClient_i;
class OlsProxy;
class OlsManagerProxy;
class OlsClientSubscription;

/**
   \brief This class provides a remote access to <em>OlsList</em> objects.

   This class is used to remotely access the services of <em>OlsList</em> objects managed by a distant server process (except the modification service). The methods of this class are exactly the same than thoses of <em>OlsList</em> class, except than they have in first parameter the name of the list.
\code#include "ols.h"\endcode
*/

class OLS_API OlsServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object for remote <em>OlsList</em> objects. It creates a connection to the server which manages the remote list objects. This server is identified by the <em>logicalEnv</em> and <em>serverName</em> parameters. For example, to access the services of an alarm list managed by an alarm server &quot;<em>AlmServer</em>&quot; running in the physical environment &quot;<em>ENV1_cactus</em>&quot;, call the current constructor like this :
\code OlsServer *olsServer = new OlsServer("ENV1", "AlmServer"); \endcode
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the server managing the remote <em>OlsList</em> objects is running,
     \param serverName  [in]: name of the server which manages the <em>OlsList</em> objects.
     \param priority  [in]: priority of the messages to the OlsServer (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  OlsServer(const char *logicalEnv = 0,
	    const char *serverName = "OlsServer",
	    ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the remote server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~OlsServer();
  //@}


  OlsServer& operator=(const OlsServer&);
  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the status of the connection to the remote server which manages the <em>OlsList</em> objects.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c OlsHostServerError : cannot connect to the ascmanager process.
     \li \c OlsORBError : cannot connect with the remote server managing the list objects.
  */
  ScsStatus getStatus() const { return _status;};
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
     this function reads the memory and/or disk data matching the filter and between the start and end times. If a name is specified in the filter, then the readDisk method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param listName  [in]: name of the remote list,
     \param filter  [in]: filter object,
     \param startTime  [in]: start time,
     \param endTime  [in]: end time,
     \param result  [out]: set of <em>OlsData</em> objects containing the read values.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus readDisk(const char *     listName,
		     const OlsFilter& filter,
		     int              startTime,
		     int              endTime,
		     OlsDataSet*&     result) const;
  
  /**
     \par Description:
     read in the remote list all the data matching the filter. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param listName  [in]: name of the remote list,
     \param filter  [in]: filter object,
     \param result  [out]: set of <em>OlsData</em> objects containing the read values.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus read(const char *     listName,
		 const OlsFilter& filter,
		 OlsDataSet*&     result) const;

  /**
     \par Description:
     returns the number of data in the remote list matching the filter. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param listName  [in]: name of the remote list,
     \param filter  [in]: filter object,
     \param count  [out]: number of data matching the filter.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus getFilteredCount(const char *     listName,
			     const OlsFilter& filter,
			     int&             count) const;
  /**
     \par Description:
     read in the remote list all the data matching the filter. The search starts from the data which key is <em>startId</em> and ends either if the end of the list is reached, or if <em>max</em> data have been found in the list. If <em>startId</em> equals -1, then the search starts at the begining of the list. If <em>max</em> equals -1, then the search ends at the end of the list. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param listName  [in]: name of the remote list,
     \param filter  [in]: filter object,
     \param startId  [in]: key of starting element,
     \param max  [in]: maximum number of elements to read,
     \param result  [out]: set of <em>OlsData</em> objects containing the read values.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsBadKeyError : in case an unknown key is given in startId.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus readAscending(const char *     listName,
			  const OlsFilter& filter,
			  int              startId,
			  int              max,
			  OlsDataSet*&     result) const;
  /**
     \par Description:
     read in the remote list all the data matching the filter. The search starts from the data which key is <em>startId</em> and ends either if the beginning of the list is reached, or if <em>max</em> data have been found in the list. If <em>startId</em> equals -1, then the search starts at the end of the list. If <em>max</em> equals -1, then the search ends at the beginning of the list. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param listName  [in]: name of the remote list,
     \param filter  [in]: filter object,
     \param startId  [in]: key of starting element,
     \param max  [in]: maximum number of elements to read,
     \param result  [out]: set of <em>OlsData</em> objects containing the read values.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsBadKeyError : in case an unknown key is given in startId.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus readDescending(const char *     listName,
			   const OlsFilter& filter,
			   int              startId,
			   int              max,
			   OlsDataSet*&     result) const;
  /**
     \par Description:
     this function subscribes the caller to the modifications on the data matching the filter. All the matching data which are added to the list, modified or removed from the list are notified to the subscribed client using the notification callback. If a name is specified in the filter, then the subscribe method will try to retrieve a registered filter. Otherwise, the subscribe method will apply the filter as is.
     \param listName  [in]: name of the remote list,
     \param filter  [in]: filter,
     \param subscriptionId  [out]: subscription identifier,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback when called.
     \param notifMode  [in]: user optional argument used to overload the default behaviour of notification.
     \param firstNotficationSize [in]: first notification data count (-1 for all data).
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus subscribe(const char *         listName,
		      const OlsFilter&     filter,
		      int&                 subscriptionId,
		      const OlsCallback    notificationCallback,
		      void *               arg = 0,
		      OlsNotificationMode  notifMode = OLS_DEFAULT_NOTIFY,
		      long                 firstNotficationSize = -1);
  /**
     \par Description:
     this function subscribes the caller to the modifications on the data matching the filter. Except the first notification, all the matching data which are added to the list, modified or removed from the list are notified to the subscribed client using the notification callback. If a name is specified in the filter, then the subscribe method will try to retrieve a registered filter. Otherwise, the subscribe method will apply the filter as is. As first notification, the caller will receive data count defined by firstNotificationSize parameter.
     \param listName  [in]: name of the remote list,
     \param filter  [in]: filter,
     \param subscriptionId  [out]: subscription identifier,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback when called.
     \param notifMode  [in]: user optional argument used to overload the default behaviour of notification.
     \param firstNotificationSize [in]: size of the first notification.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus subscribeWithFirstNotificationSize(const char *         listName,
					       const OlsFilter&     filter,
					       int&                 subscriptionId,
					       const OlsCallback    notificationCallback,
					       void *               arg = 0,
					       OlsNotificationMode  notifMode = OLS_DEFAULT_NOTIFY,
					       long                 firstNotificationSize = -1);
  /**
     this function add bad sequence order callback. This function is called if lost notification is detected.
     \param listName  [in]: name of the remote list,
     \param subscriptionId  [in]: subscription identifier,
     \param badSequenceCallback  [in]: user bad sequence  callback function,
     \param arg  [in]: user optional argument passed to the notification callback when called.
     \param supervisionPeriod [in]: period of supervison: default is 60 seconds,
     \return
     \li \c ScsValid : success.
     \li \c ScsError : bad list name or subscription Id.
  */
  ScsStatus addBadSequenceOrderCallback(const char* listName,
					int subscriptionId,
					const OlsCallback badSequenceCallback,
					void * arg,
					int supervisionPeriod = 60000);
  /**
     \par Description:
     this function removes the specified subscription. 
     \param listName  [in]: name of the remote list,
     \param subscriptionId  [in]: subscription identifier returned by <em>subscribe()</em> method.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsBadSubscriptionIdError : in case of a bad subscription id.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus unsubscribe(const char *listName, int subscriptionId);
  /**
     \par Description:
     this function returns all the List subscribers
     \param listName  [in]: name of the remote list,
     \param count  [out]: subscription count returned by <em>getSubscriber()</em> method.
     \param client  [out]: list of subscribers.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsBadSubscriptionIdError : in case of a bad subscription id.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsOrbixError : communication failure with the remote server.
  */
  ScsStatus getSubscriber(const char *listName, int &count, char **&client);
  //@}

  ScsStatus refreshSubscription(  OlsClientSubscription* sub );

  static void RefreshSubscriptionCallback(void* arg);

  void refreshSubscriptionCallback();
  
protected:

  ScsStatus       _status;
  OlsClient_i    *_client;
  OlsProxy       *_proxy;
  char           *_physicalEnvironment;
  char           *_envName;
  ScsTimer       *_refreshTimer;
};


/**
   \brief This class provides a remote access to <em>OlsList</em> objects.

   This class is used to remotely access the services of <em>OlsList</em> objects managed by a distant server process. It inherits from the methods of the <em>OlsServer</em> class and has an additional list modification method. The methods of this class are exactly the same than thoses of <em>OlsList</em> class, except than they have in first parameter the name of the list.
\code#include "ols.h"\endcode
*/
class OLS_API OlsManager
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object for remote <em>OlsList</em> objects. It creates a connection to the server which manages the remote list objects. This server is identified by the <em>logicalEnv</em> and <em>serverName</em> parameters. For example, to access the services of an alarm list managed by an alarm server &quot;<em>AlmServer</em>&quot; running in the physical environment &quot;<em>ENV1_cactus</em>&quot;, call the current constructor like this :
\code OlsManager *olsManager = new OlsManager("ENV1", "AlmServer"); \endcode
     \param environment  [in]: name of the logical SCADAsoft environment in which the server managing the remote <em>OlsList</em> objects is running,
     \param name  [in]: name of the server which manages the <em>OlsList</em> objects.
     \param priority  [in]: priority of the messages to the OlsManager (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  OlsManager(const char *environment = 0,
	     const char *name = "OlsManager",
	     ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the remote server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~OlsManager();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the status of the connection to the remote server which manages the <em>OlsList</em> objects.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c OlsHostServerError : cannot connect to the ascmanager process.
     \li \c OlsORBError : cannot connect with the remote server managing the list objects.
  */
  ScsStatus getStatus();

  /**
     \par Description:
     this function modifies the remote list according to the data contained in the dataset.
     \param listName  [in]: name of the remote list,
     \param dataSet  [in]: dataset containing the data to add, modify or delete.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadListNameError : the remote server does not export the specified list.
     \li \c OlsBadDataKeyError : if one key in the dataset is not does not correspond to a data of the list.
     \li \c OlsDataModeUndefinedError : if one data in the dataset has an <em>OlsData::UNKNOWN</em> type.
     \li \c OlsErrHostServer : cannot connect to the ascmanager process.
     \li \c OlsORBError : communication failure with the remote server.
  */
  ScsStatus modify(const char *listName, const OlsDataSet &dataSet);
  //@}

protected:
  OlsManagerProxy *_proxy;
  ScsStatus       _status;
};

/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store data elements. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsList</em> class) groups a set of objects containing the same kind of information. An object of <em>OlsList</em> class contains a dataset containing the fields of the elements of the list, a list of filters, a list of subscribers and the data elements list.
\code#include "olstypes.h"\endcode
*/
class OLS_API OlsList
{
public:

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. A list contains a set of data. Each data have the same fields called the fields of the list. The list manages subscriptions. The <em>period</em> is the period between two subscription refresh timeouts. The period is in milliseconds. The <em>withHash</em> parameter specifies if the list use (value set to 1) or not (value set to 0) a hash table for the searchs into the data elements list.  
     \param name  [in]: name of the list,
     \param period  [in]: period between two subscription refresh timeouts,
     \param withHash  [in]: use a hash table (if set to 1) or not,
     \param withLock  [in]: use a lock for the modifications (if set to 1) or not,
     \param withThreadHandle  [in]: if set to 1, notifications are done in a separate thread,
     \param startPeriodicUpdate  [in]: if set to 0, the periodical timer for the notifications is not started at the creation of the list. It could be started using the <em>startPeriodicUpdate()</em> method.
     \par Return values:
     none.
  */
  OlsList(const char *name,
	  short       period = 1000,
	  int         withHash = 0,
	  int         withLock = 0,
	  int         withThreadHandle = 0,
	  int         startPeriodicUpdate = 1);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsList();
  //@}

   /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function returns the index of the specified field. If the field does not exist, returns -1.
     \param name  [in]: the name of the field.
     \par Return values:
     the field index.
  */
  virtual int getFieldIndex(const char* name) const;
  /**
     \par Description:
     this function returns the number of data in the list.
     \par Parameters:
     none.
     \par Return values:
     the number of data.
  */
  virtual int getDataCount() const;
  /**
     \par Description:
     this function returns and removes the first data of the list. If the list is empty, returns NULL.
     \par Parameters:
     none.
     \par Return values:
     the first data.
  */
  virtual OlsData* pop();
  /**
     \par Description:
     this function adds a field in the list. The value of the field is the default one.
     \param field  [in]: the field to add,
     \param isKey  [in]: if non null value, the field is a key for the hash table, if any.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if a data has already been inserted in the dataset.
  */
  virtual ScsStatus addField(const OlsField& field, int isKey = 0);
  /**
     \par Description:
     this function adds a set of fields in the list. The fields are pointed by the <em>fieldList</em> parameter. The number of fields is specified by the <em>count</em> parameter. The value of the fields is the default one.
     \param fieldList  [in]: the fields to add,
     \param count  [in]: the number of fields,
     \param isKey  [in]: list of flag specifying if the field is a key for the hash table (set to non null value), if any.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if a data has already been inserted in the dataset.
  */
  virtual ScsStatus addFields(const OlsField* const fieldList, int count, int* isKey = 0);
  /**
     \par Description:
     this function returns the number of fields.
     \par Parameters:
     none.
     \par Return values:
     the number of fields.
  */
  virtual int getFieldCount() const;
  /**
     \par Description:
     this function returns the field at position <em>pos</em>. It returns NULL if there are less fields than <em>pos</em> in the list.
     \param pos  [in]: the field position.
     \par Return values:
     the <em>pos</em>th field.
  */
  virtual const OlsField* getField(int pos) const;
  /**
     \par Description:
     this function returns every data in the list that match filter. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param filter  [in]: the filter to apply,
     \param result  [out]: the dataset containing the data resulting of the read.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
  */
  virtual ScsStatus read(const OlsFilter& filter, OlsDataSet*& result) const;
  /**
     \par Description:
     this function returns every data in the list that match filter from the disk. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param filter  [in]: the filter to apply,
     \param startTime  [in]: the time of the first element to read,
     \param endTime  [in]: the time of the last element to read,
     \param result  [out]: the dataset containing the data resulting of the read.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
  */
  virtual ScsStatus readd (const OlsFilter& filter,
                           int              startTime,
                           int              endTime,
                           OlsDataSet*&     result) const;
  /**
     \par Description:
     this function returns the number of data in the list that match filter. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param filter  [in]: the filter to apply,
     \param count  [out]: the number of data matching the filter.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
  */
  virtual ScsStatus getFilteredCount(const OlsFilter& filter, int& count) const;
  /**
     \par Description:
     this function returns data in the list that match filter. The search starts from the data which key is <em>startId</em> and ends either if the end of the list is reached, or if <em>max</em> data have been found in the list. If <em>startId</em> equals -1, then the search starts at the begining of the list. If <em>max</em> equals -1, then the search ends at the end of the list. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param filter  [in]: the filter to apply,
     \param startId  [in]: the key of first data to read,
     \param max  [in]: the maximum of data to read,
     \param result  [out]: the data resulting of the read.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsBadKeyError : in case an unknown key is given in <em>startId</em>.
  */
  virtual ScsStatus readAscending(const OlsFilter& filter,
			  int              startId,
			  int              max,
			  OlsDataSet*&     result) const;
  /**
     \par Description:
     this function returns data in the list that match filter. The search starts from the data which key is <em>startId</em> and ends either if the beginning of the list is reached, or if <em>max</em> data have been found in the list. If <em>startId</em> equals -1, then the search starts at the end of the list. If <em>max</em> equals -1, then the search ends at the beginning of the list. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param filter  [in]: the filter to apply,
     \param startId  [in]: the key of first data to read,
     \param max  [in]: the maximum of data to read,
     \param result  [out]: the data resulting of the read.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
     \li \c OlsBadKeyError : in case an unknown key is given in <em>startId</em>.
  */
  virtual ScsStatus readDescending(const OlsFilter& filter,
			   int              startId,
			   int              max,
			   OlsDataSet*&     result) const;
  /**
     \par Description:
     this function subscribes the caller to the modifications on the data matching the filter. All the matching data which are added to the list, modified or removed from the list are notified to the subscribed client using the notification callback. If a name is specified in the filter, then the subscribe method will try to retrieve a registered filter. Otherwise, the subscribe method will apply the filter as is.
     \param filter  [in]: filter,
     \param subscriptionId  [out]: subscription identifier,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback when called.
     \param firstNotficationSize [in]: first notification data count (-1 for all data).
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
  */

  virtual ScsStatus subscribe(const OlsFilter&   filter,
			      int &              subscriptionId,
			      const OlsCallback  notificationCallback,
			      void *             arg = 0,
			      long               firstNotficationSize = -1);
  /**
     \par Description:
     this function removes the specified subscription. 
     \param subscriptionId  [in]: subscription identifier returned by <em>subscribe()</em> method.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadSubscriptionIdError : in case of a bad subscription id.
  */
  virtual ScsStatus unsubscribe(int subscriptionId);  
  /**
     \par Description:
     this function modifies the list according to the data contained in the dataset.
     \param dataSet  [in]: dataset containing the data to add, modify or delete.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadDataKeyError : if one key in the dataset is not does not correspond to a data of the list.
     \li \c OlsDataModeUndefinedError : if one data in the dataset has an <em>OlsData::UNKNOWN</em> type.
  */
  virtual ScsStatus modify(const OlsDataSet& dataSet);
  /**
     \par Description:
     this function returns the name of the list.
     \par Parameters:
     none.
     \par Return values:
     the name of the list.
  */
  virtual const char* getName() const;
  /**
     \par Description:
     this function returns the data which key is <em>key</em>, if any, NULL otherwise.
     \param key  [in]: key to compare.
     \par Return values:
     the data which key is <em>key</em>.
  */
  virtual OlsData* getData(int key) const;
  /**
     \par Description:
     this function returns the data which external key on field <em>fieldName</em> is <em>key</em>, if any, NULL otherwise.
     \param fieldName  [in]: field name, 
     \param key  [in]: key to compare.
     \par Return values:
     the matching data.
  */
  virtual OlsData* getData(const char* fieldName, ScsData key) const;
  /**
     \par Description:
     this function remove the passed data from the list.
     \param data  [in]: data to remove
  */

 //@}

  virtual void removeData(OlsData*& data);
  virtual OlsData* getData(int pos, ScsData key) const;
  virtual void handleTimeout();
  int isLockExist() { return _lockExist; }
  ScsLock* getLock() { return _listLock; }
  int getPeriod() { return _period; }
  ScsLock* getThreadLock() { return _threadLock; }


  long getThreadId () { return _threadId; }
  void setThreadId (long id) {  _threadId = id; }
  void threadTemporisation(int count);
  int isThreadHandleLaunched() { return _threadHandleIsLaunched; }
  void setThreadHandleLaunched(int state = 1) { _threadHandleIsLaunched = state; }
  int isThreadHandleExist() { return _withThreadHandle; }
  int getGlobalNotifyCount() { return _globalNotifyCount; }
  void setGlobalNotifyCount(int globalNotifyCount) { _globalNotifyCount = globalNotifyCount; }


  void prepareNotification(ScsMessageTag *tag = NULL);


  void prepareSyncNotification(OlsDataList*& newList, 
			       OlsDataList*& oldList,
			       OlsDataList*& toBeDeletedList);
  

  void updateClient(OlsSubscription* sub, OlsDataSet* dataset, ScsMessageTag* tag);

  void matchData(OlsDataSet*& result,
		 OlsData*& newData,
		 OlsData*& oldData,
		 OlsData*& deletedData, 
		 const OlsFilter*& filter);

  void olsListNotification(OlsDataList*& newList,
			OlsDataList*& oldList,
			OlsDataList*& toBeDeletedList,
			ScsMessageTag* tag);


  //----------------- threaded olslist 

  void prepareAsyncNotification(OlsDataList*& newList, 
				OlsDataList*& oldList,
				OlsDataList*& toBeDeletedList,
				OlsDataSet*& worDataSet,
				OlsDataSet*& newClientDataSet,
				OlsSubscription*& newClient,
				ScsMessageTag* tag);


  void threadedOlsListNotification(int notificationType,
				OlsDataList*& newList,
				OlsDataList*& oldList,
				OlsDataList*& toBeDeletedList,
				OlsDataSet*& worDataSet,
				OlsDataSet*& newClientDataSet,
				OlsSubscription*& newClient,
				ScsMessageTag* tag);

  void synchronousNotification(OlsDataList*& newList,
			       OlsDataList*& oldList,
			       OlsDataList*& toBeDeletedList,
			       OlsDataSet*& worDataSet,
			       OlsDataSet*& newClientDataSet,
			       OlsSubscription*& newClient,
			       ScsMessageTag* tag);

  void asynchronousNotification(OlsDataList*& newList,
				OlsDataList*& oldList,
				OlsDataList*& toBeDeletedList,
				OlsDataSet*& worDataSet,
				OlsDataSet*& newClientDataSet,
				OlsSubscription*& newClient,
				ScsMessageTag* tag);


  OlsThreadArgList* getOlsThreadArgList() { return _olsThreadArgList; }
  //----------------- end threaded olslist 



  OlsUnsubscribeToDo* getOlsUnsubscribeToDo() { return _olsUnsubscribeToDo; }


  // tempory used by ols_i.cpp for external client
  int getTypeCallbackArg() { return _typeCallbackArg; }
  void setTypeCallbackArg(int typeCallbackArg) { _typeCallbackArg = typeCallbackArg; }

  void lock();
  void unlock();
  static OlsListList* getList();
  void printItems();
  int getFirstToDump() { return _firstToDump;};
  timeval getNextTime() const { return _nextTime;};
  OlsDataSet* getDataSet() const { return _dataSet;};
  OlsDataList* getModificationList() const { return _modificationList;};
  OlsSubscriptionList* getSubscriptionList() const { return _subscriptionList;};
  OlsSubscriptionList* getLocalList() const { return _localClientList;};
  OlsSubscription* getOlsSubscription( long id );
  virtual ScsStatus modify(OlsData* currentData, const OlsData* newData);
  virtual OlsData* newData(const OlsData* data = 0);

  int getNewClientCount() { return _newClientCount; }
  void decrNewClientCount() { _newClientCount--; }
  void incrNewClientCount() { _newClientCount++; }

  virtual ScsStatus foregroundSnapshot(const char *pathname, const int ascii = 1);
  virtual ScsStatus restoreFromSnapshot(const char *pathname, const int ascii = 1);

  virtual ScsStatus foregroundSnapshotWithoutData(const char *pathname, const int ascii = 1);

  virtual ScsStatus foregroundSnapshotWithoutData(SCS_SL_STD(ostream)& os, const int ascii = 1);
  virtual ScsStatus restoreFromSnapshotWithoutData(SCS_SL_STD(istream)& is, const int ascii = 1);

  virtual void clearAndModify();
  virtual ScsStatus reloadAndModify(SCS_SL_STD(istream)& is);


  virtual ScsStatus subscribeAgain(const OlsFilter& filter,
				   int   id,
				   const OlsCallback callback,
				   void *arg = 0,
				   int   isNew=1,
				   long  firstNotficationSize = -1);
  static void setSubId(int subId);
  static int  getSubId();
  static void HandleTimeout(void *arg);  
  /**
     \par Description:
     this function starts the periodical timer for the notifications.
     \par Parameters:
     none.
     \par Return values:
     \li \c ScsValid : success.
  */
  virtual ScsStatus startPeriodicUpdate();

  /**@name Operators / cast*/
  //@{
  /**
     \par Description:
     this operator returns the data at position <em>pos</em> in the list.
     \param pos  [in]: the data position.
     \par Return values:
     the <em>pos</em>th data.
  */
  virtual const OlsData* operator[](int pos) const;
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsList</em> object into an output stream. The list is saved into a string in order to be passed over the network or dumped into disk file.
     \param os  [in]: the output stream,
     \param first  [in]: the first data element to save,
     \param count  [in]: the number of data elements to save.
     \par Return values:
     none.
  */
  virtual void save(SCS_SL_STD(ostream)& os, int first = 0, int count = -1) const;
  /**
     \par Description:
     this function is used to restore an <em>OlsList</em> object from an input stream. The list is restored from a string after having been passed over the network or from a disk file.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);
  /**
     \par Description:
     this function is used to reload an <em>OlsList</em> object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void reload(SCS_SL_STD(istream)& is);
  /**
     \par Description:
     this function is used to reload an <em>OlsList</em> object from an input stream with a limited number of elements
     \param is  [in]: the input stream.
     \param nbMaxElmtsToReload [in]: maximum number of elements to reload
     \par Return values:
     none.
    */
  virtual void reload(SCS_SL_STD(istream) & is, int nbMaxElmtsToReload);
  /**
     \par Description:
     this function start the record facility of all the lists.
     \param period  [in]: period of the snapshots
     \par Return values:
     \li \c ScsValid : success.
     \li \c ScsError : the record facility has already be created.
    */
  static ScsStatus startRecord(int period);
  //@}

  static ScsStatus startRecordBuffering();
  static ScsStatus stopRecordBuffering();

   enum NotificationType {
     SYNCHRONOUS_UPDATE = 0,
     ASYNCHRONOUS_UPDATE
   };

protected:
  virtual void saveProperties(SCS_SL_STD(ostream)&) const;
  virtual void restoreProperties(SCS_SL_STD(istream)&);
  virtual void reloadProperties(SCS_SL_STD(istream)&);
  virtual void updateVisibility(int subId, const OlsDataSet& set);
  
  virtual void snapshot(SCS_SL_STD(ostream)& os, int first, int count, const int ascii = 1) const;
  virtual void saveBinary(SCS_SL_STD(ostream)& os, int first = 0, int count = -1) const;

  virtual void olsCompileCriteria(const OlsCriteria* criteria) const;
  virtual ScsStatus olsCheckFilter(const OlsFilter& filter) const;

  char        *_name;
  int          _nextKey;
  OlsDataSet  *_dataSet;
  OlsDataList *_modificationList;
  OlsDataList *_oldList;
  OlsSubscriptionList *_subscriptionList;
  // only used for threaded list
  OlsSubscriptionList *_localClientList;

  int                  _firstToDump;
  long                 _threadId;
  int                  _withThreadHandle;
  int                  _unsubscribeToDo;
  int                  _threadHandleIsLaunched;
  ScsLock              *_threadLock;


  int                  _newClientCount;
  
  OlsThreadArgList     *_olsThreadArgList;
  OlsUnsubscribeToDo   *_olsUnsubscribeToDo;



  int                  _globalNotifyCount;
  int                  _lockExist;
  ScsLock              *_listLock;
  timeval              _nextTime;
  int                  _period;
  OlsData             *_popData; 

  ImgMsgTag           *_tagProvider;
  static ScsTimer        *_timer;
  static unsigned int     _basedPeriod;

private:
  int                     _typeCallbackArg;
  static OlsListList      _instanceList;
  OlsHashTable           *_hashTable;
  RWCString              *_filterFileName;
  static OlsRplRecordMgr *OlsRecordMgrInst;
};


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store data elements. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsList</em> class) groups a set of objects containing the same kind of information. The <em>OlsLimitedList</em> class behaves as <em>OlsList</em> except the number of <em>OlsData</em> within the list is limited. If the limit is reached, the oldest data is removed from the list and every client are notified.
\code#include "olstypes.h"\endcode
*/
class OLS_API OlsLimitedList : public OlsList
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. A list contains a set of data. Each data have the same fields called the fields of the list. The list manages subscriptions. The <em>period</em> is the period between two subscription refresh timeouts. The period is in milliseconds.
     \param name  [in]: name of the list,
     \param size  [in]: size of the data element list,
     \param period  [in]: period between two subscription refresh timeouts.
     \par Return values:
     none.
  */
   OlsLimitedList(const char *name, int  size, short period = 1000)
    : OlsList(name, period), _size(size) {;};
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function modifies the list according to the data contained in the dataset.
     \param dataSet  [in]: dataset containing the data to add, modify or delete.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadDataKeyError : if one key in the dataset is not does not correspond to a data of the list.
     \li \c OlsDataModeUndefinedError : if one data in the dataset has an <em>OlsData::UNKNOWN</em> type.
  */
  virtual ScsStatus modify(const OlsDataSet& dataSet);
  virtual ScsStatus modify(OlsData* currentData, const OlsData* newData);
  //@}

private:
  int  _size;
};
  
class OlsFileRecList;

/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store data elements. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsList</em> class) groups a set of objects containing the same kind of information. The <em>OlsCollectableList</em> class behaves as <em>OlsList</em> except the number of <em>OlsData</em> within the list is limited and circular, and the list is periodically dumped into files on disk. The <em>pathname</em> parameter defines the directory on disk in which files are created. The maximum number of disk files for the list is defined by the <em>maxFiles</em> parameter and the maximum number of data in each file by the <em>capacity</em> parameter. When the number of elements inserted in the data list reaches <em>capacity</em>, these elements are dumped into a new file on disk. The list is circular: if the limit <em>size</em> is reached, new data overwrite the oldest data. The list should have a time field.
\code#include "olstypes.h"\endcode
*/
class OLS_API OlsCollectableList : public OlsList
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. A list contains a set of data. Each data have the same fields called the fields of the list. The list manages subscriptions. The <em>period</em> is the period between two subscription refresh timeouts. The period is in milliseconds. The <em>daily</em> parameter specifies if all the data corresponding to the last day should be grouped into one global daily file. This concatenation happens at midnight and the daily files are located under a "Daily" subdirectory of the <em>pathname</em> directory. A non null value of <em>daily</em> validates this option and specifies the maximum of daily files on disk. When this maximum is reached and a new file is created, the oldest is removed. 
     \param name  [in]: name of the list,
     \param pathname  [in]: pathname to the directory on disk in which dump files are created,
     \param size  [in]: size of the data element list,
     \param capacity  [in]: maximum number of data in each dump file,
     \param maxFiles  [in]: maximum number of dump files on disk for current list,
     \param period  [in]: period between two subscription refresh timeouts,
     \param daily  [in]: specify if the ,
     \param withLock [in]: use a lock for the modifications (if set to 1) or not,
     \param withThreadHandle  [in]: if set to 1, notifications are done in a separate thread.
     \param startPeriodicUpdate  [in]: if set to 0, the periodical timer for the notifications is not started at the creation of the list. It could be started using the <em>startPeriodicUpdate()</em> method.
     \param timeFieldName [in]: field name for SCADAsoft time (default is <em>SCSTime</em>).
     \par Return values:
     none.
  */
  OlsCollectableList(const char *name,
		     const char *pathname,
		     int         size = 1000,
		     int         capacity = 500,
		     int         maxFiles = 100,
		     short       period = 1000,
		     short       daily = 0,
                     int         withLock = 0,
		     int         withThreadHandle = 0,
		     int         startPeriodicUpdate = 1,
		     const char *timeFieldName = SCSTIME_FIELD_NAME);
   /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
   */
  virtual ~OlsCollectableList();  
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     returns the status of creation of the collectable list.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadPathnameError : pathname is incorrect.
     \li \c OlsCreateDirectoryError : the list can not create the subdirectory under <em>pathname</em> directory or the daily subdirectory.
  */
  virtual ScsStatus getStatus() { return _status;};
  /**
     \par Description:
     writes the data into new disk file.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */
  virtual ScsStatus dumpData();
  /**
     \par Description:
     writes the specified number of data into new disk file.
     \param nbDataToDump  [in]: number of data to dump.
     \return
     \li \c ScsValid : success.
     \li \c OlsDeleteFileError : the oldest disk file cannot be removed.
  */
  virtual ScsStatus dumpToDiskFile(int nbDataToDump);
  /**
     \par Description:
     this function concatenates all the archive files corresponding to one day into a global daily file.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c OlsCreateFileError : the daily file cannot be created.
     \li \c OlsOpenFileError : a disk file cannot be opened.
     \li \c OlsDeleteFileError : the oldest disk file cannot be removed.
  */
  virtual ScsStatus concatenateFiles();
  /**
     \par Description:
     this function inserts all data of the dataset in the list. The mode of the data in the dataset should absolutely be <em>OlsData::CREATION</em>. When the number of inserted data reaches the capacity of the list, these data are dumped into file on disk.
     \param dataSet  [in]: dataset containing the data to add.
     \return
     \li \c ScsValid : success.
     \li \c OlsNoTimeFieldError : the list has no time field.
     \li \c OlsBadDataModeError : the mode of one of a data of the dataset is not <em>OlsData::CREATION</em>.
  */
  virtual ScsStatus modify(const OlsDataSet& dataSet);
  virtual ScsStatus modify(OlsData* currentData, const OlsData* newData);
  /**
     \par Description:
     this function reads data from disk between start and end time. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param filter  [in]: the filter to apply,
     \param startTime  [in]: the time of the first element to read,
     \param endTime  [in]: the time of the last element to read,
     \param dataSet  [out]: the dataset containing the data resulting of the read.
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
  */
  virtual ScsStatus readd (const OlsFilter& filter,
			   int              startTime,
			   int              endTime,
			   OlsDataSet*&     dataSet) const;
  //@}

  virtual ScsStatus foregroundSnapshot(const char *pathname, const int ascii = 1);
  virtual ScsStatus restoreFromSnapshot(const char *pathname, const int ascii = 1);
  OlsFileRecList *getFileRecList() { return _fileRecList;};

  void waitLock();
  void releaseLock();
  static void timerCallback(void *olsCollectableList);
  timeval getRefTime() { return _refTime;};
  void setRefTime(timeval refTime) { _refTime = refTime;};

  ScsStatus reloadFiles(const char *pathname);

protected:
  ScsString      *_timeFieldName;
  ScsStatus       _status;
  ScsString      *_pathname;
  int             _size;
  int             _capacity;
  int             _maxFiles;
  short           _daily;
  timeval         _refTime;
  OlsFileRecList *_fileRecList;
  OlsFileRecList *_dailyList;
  ScsLock        *_timerLock;
  ScsTimer       *_dailyTimer;
};

/***************** TEST new OLSSimpleList ***********************************/
class OLS_API OlsSimpleList : public OlsList
{

public:

  OlsSimpleList(const char *name, short period = 1000, int withHash = 0, int withLock=0);
  virtual ~OlsSimpleList();

  virtual void handleTimeout();

protected:
  ScsStatus selectNewMatch( const OlsFilter   *filter,
                            OlsDataSet*& result) const;

  ScsStatus selectModMatch( const OlsFilter   *filter,
                            int         *initModes,
                            OlsDataSet*& result) const;

  void      updInitialModes ( int         *ptrModes, 
                              OlsDataList &toBeDeletedList);
private:
};

/***************** END TEST new OLSSimpleList ***********************************/

/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store data elements. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsList</em> class) groups a set of objects containing the same kind of information. The <em>OlsQuickList</em> class behaves as <em>OlsList</em> except there is no Timer and no handleTimeout.
\code#include "olstypes.h"\endcode
*/
class OLS_API OlsQuickList : public OlsList
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. A list contains a set of data. Each data have the same fields called the fields of the list. The list manages subscriptions. The <em>withHash</em> parameter specifies if the list use (value set to 1) or not (value set to 0) a hash table for the searchs into the data elements list.
     \param name  [in]: name of the list,
     \param withHash  [in]: use a hash table or not,
     \param updateNewClient  [in]: update new client 250 ms later,
     \param updateOnSubscribe [in]: if it is worth zero, the client won't be notified as he subscribes to the list, otherwise he will be notified,
     \param withLock [in]: use a lock for the modifications (if set to 1) or not,
     \param withThreadHandle  [in]: if set to 1, notifications are done in a separate thread.
     \par Return values:
     none.
  */
  OlsQuickList(const char *name, int withHash = 0, int withLock=0, int updateNewClient = 0, const int updateOnSubscribe = 0, int withThreadHandle = 0);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~OlsQuickList();

  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
      call the notification of modification
     \param tag  [in]: tag to be used for notification (it must be allocated by the called, it will be destroy by the method).
     \return
     \li \c ScsValid : success.
  */
  virtual void notifyModif(ScsMessageTag *tag = NULL);

  /**
     \par Description:
     this function subscribes the caller to the modifications on the data matching the filter. All the matching data which are added to the list, modified or removed from the list are notified to the subscribed client using the notification callback. If a name is specified in the filter, then the subscribe method will try to retrieve a registered filter. Otherwise, the subscribe method will apply the filter as is.
     \param filter  [in]: filter,
     \param subscriptionId  [out]: subscription identifier,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback when called.
     \param firstNotficationSize  [in]: .
     \return
     \li \c ScsValid : success.
     \li \c OlsBadFilterError : in case an unregistered name is specified for the filter.
  */
  virtual ScsStatus subscribe(const OlsFilter&   filter,
			      int &              subscriptionId,
			      const OlsCallback  notificationCallback,
			      void *             arg = 0,
			      long               firstNotficationSize = -1);

  //@}


  int updateNewClient() { return _updateNewClient; }

  virtual ScsStatus foregroundSnapshot(const char *pathname, const int ascii = 1);
  virtual ScsStatus restoreFromSnapshot(const char *pathname, const int ascii = 1);

  virtual ScsStatus foregroundSnapshotWithoutData(const char *pathname, const int ascii = 1);

  virtual ScsStatus foregroundSnapshotWithoutData(SCS_SL_STD(ostream)& os, const int ascii = 1);
  virtual ScsStatus restoreFromSnapshotWithoutData(SCS_SL_STD(istream)& is, const int ascii = 1);


private:
  int _updateNewClient;
  int _updateOnSubscribe;

};

#define SCS_OLS_MAXCLIENTS 32
typedef unsigned int OlsVisibility;

class OlsVisibilityTable;


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store data elements. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsListWithClientVisibility</em> class) groups a set of objects containing the same kind of information. An object of <em>OlsListWithClientVisibility</em> class contains a dataset containing the fields of the elements of the list, a list of filters, a list of subscribers and the data elements list.
  A Visbility field of type ScsINTEGER is automatically added to the list. It maintains wether or not a particuler OlsData has been sent to a client. It is restricted to 32 clients.
\code#include "olstypes.h"\endcode
*/
class OLS_API OlsListWithClientVisibility : public OlsList
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. A list contains a set of data. Each data have the same fields called the fields of the list. The list manages subscriptions. The <em>period</em> is the period between two subscription refresh timeouts. The period is in milliseconds. The <em>withHash</em> parameter specifies if the list use (value set to 1) or not (value set to 0) a hash table for the searchs into the data elements list.  
     \param name  [in]: name of the list,
     \param period  [in]: period between two subscription refresh timeouts,
     \param withHash  [in]: use a hash table or not,
     \param withLock [in]: use a lock for the modifications (if set to 1) or not.
     \par Return values:
     none.
  */
  OlsListWithClientVisibility(const char *name, short period = 1000, int withHash = 0, int withLock=0);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsListWithClientVisibility();
  //@}

  ScsStatus setVisibilityRank(int subscriptionId, int inUserId);
  ScsStatus unsetVisibilityRank(int subscriptionId);
  ScsStatus isVisible(int key, int subscriptionId, int& visible);
  ScsStatus getVisibility(int key, OlsVisibility& visibility);
  ScsStatus getRank(int subscriptionId, int& rank);
  ScsStatus getUserIdWithRank (int rank, long& userId);

  virtual void save(SCS_SL_STD(ostream)& os, int first = 0, int count = -1) const;
  virtual void restore(SCS_SL_STD(istream)& is);  
  virtual void reload(SCS_SL_STD(istream)& is);
  virtual void reload(SCS_SL_STD(istream) & is, int nbMaxElmtsToReload);

  virtual ScsStatus foregroundSnapshot(const char *pathname, const int ascii = 1);
  virtual ScsStatus restoreFromSnapshot(const char *pathname, const int ascii = 1);

protected:
  int isVisible(int key, unsigned short rank);
  OlsVisibility getVisibility(int key);
  void setVisible(int key, unsigned short rank);
  void setInvisible(int key, unsigned short rank);
  short getRank(int subscriptionId);
  int getUserId(int subscriptionId);
  virtual void updateVisibility(int subId, const OlsDataSet& set);

private:
  void load(SCS_SL_STD(istream)& is);

  // rank of each subscriptionId
  int _ranks[SCS_OLS_MAXCLIENTS];
  // userId's list
  int _userIdRank[SCS_OLS_MAXCLIENTS];
  OlsVisibilityTable* _visibilityTable;
};


/**
\code#include "olstypes.h"\endcode
   This function creates one object of each implementation class of <em>OlsServer</em> and <em>OlsManager</em>, if they are not already created. This function should be called in a server which manages and exports data lists. 
*/
OLS_API ScsStatus OlsExportList();
/**
\code#include "olstypes.h"\endcode
   This function returns pointer to data list object corresponding to <em>name</em> parameter. This function should be called in a server which manages and exports data lists. 
*/
OLS_API OlsList *OlsFindList(const char *name);
/**
\code#include "olstypes.h"\endcode
   This function save in File the <em>OlsList</em> lists manager by Server . This function should be called in a server which manages and exports data lists.
*/
OLS_API ScsStatus OlsSnapshot(const char *path);
/**
\code#include "olstypes.h"\endcode
   This function load from snapshot files the data list that the server manages and exporst . This function should be called in a server which manages and exports data lists.
*/
OLS_API ScsStatus OlsInitFromSnapshot(const char *path);

class OlsServerIdl_i;
class OlsManagerIdl_i;

/**
\code#include "olstypes.h"\endcode
   This function returns a pointer to the created object of the implementation class of <em>OlsServer</em>, or creates and returns it, if it is not already created. This function could be called in a server which manages and exports data lists. 
*/
OLS_API OlsServerIdl_i *OlsGetServer();

/**
\code#include "olstypes.h"\endcode
   This function returns a pointer to the created object of the implementation class of <em>OlsManager</em>, or creates and returns it, if it is not already created. This function could be called in a server which manages and exports data lists. 
*/
OLS_API OlsManagerIdl_i *OlsGetManager();

#endif
