//-*-c++-*-
/******************************************************************************/
/*									      */
/*  FILE		: dbm.h                                               */
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
// $Id: dbm.h,v 1.8 1999/11/25 09:11:02 scadaref Exp $
//
// HISTORY:
// $Log: dbm.h,v $
// Revision 1.8  1999/11/25 09:11:02  scadaref
// Port on MSVC6
//
// Revision 1.7  1999/08/23 09:14:58  jmb
// Add controlCE
//
// Revision 1.6  1999/06/04 16:44:32  ylo
// Add directWrite to dbmserver.
//
// Revision 1.5  1999/01/29 09:44:57  ylo
// Snapshot integration for dbmpoller.
//
// Revision 1.4  1999/01/20 15:46:50  ylo
// Add Mux/Demux for dbmpoller.
//
// Revision 1.3  1999/01/11 14:29:56  ylo
// remove imgmsgtag.h include.
//
// Revision 1.2  1998/12/14 13:50:49  ylo
// Add proxy management to support Y sending.
//
// Revision 1.1  1998/12/07 13:38:10  ylo
// Initial revision
//
//
/******************************************************************************/
#ifndef _DBM_H
#define _DBM_H

/**
   \file
   \brief Access to the Database Manager (DBM) module.
*/
#include "scsdata.h"
#include "dbmdirect.h"
#include "dbminfo.h"
#include "dbmhistory.h"
#include "dbmtypes.h"

// Definition of DBM module trace function
#define DbmTrace	ScsTraceFunction(DBM_SCSMODULE)
#define DbmTraceLevel(level, message)  BaseTraceLevel(DBM_SCSMODULE, level, message)

class AscServer;

class DbmCountList;
class DbmStringList;
class DbkAddressId;
class DbmDataSet;
class ScsString;    

/**
   Prototype of the DbmPoller notification callback function.
\code#include "dbm.h"\endcode
   \par Description:
     this function is a client application function called by the DbmPoller to asynchronously notify the client of value changes of polling group points. This callback function is first called as return of the subscription request to notify of the current value of all the polling group points and then, at each expiration of the notification period, to notify of the changes which occurred since the last notification.
   \param dataSet  [in]: dataset containing the value changes. Each value, its type and its associated user id are contained in a DbmData object of the dataset.
   \param arg  [in]: user optional argument (not used by DBM component). This argument is given by the client in a dataset when it calls the subscription function and returned to it when the current callback function is called by the DbmPoller. This parameter is optional, but, if set, could be used to give back information to the client.
   \par Return values:
     none.
*/
typedef void (*DbmCallback)(const DbmDataSet &dataSet, ScsAny arg);


class DbmDataList;
class DbmDataListIterator;

/**
   \brief This class is used to store the info for reading, writing point attributes in database or subscribing to database point attributes.

   This class is used to store the description of database point attributes, and, eventually, an associated value and its type, in <em>DbmData</em> objects using an <em>ScsAddress</em> object and an <em>ScsData</em> object. It is also used to specify the info to create polling groups and to subscribe to theses groups.
\code#include "dbm.h"\endcode
*/
class DBK_API DbmDataSet
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an empty dataset if no argument are given. The <em>groupName</em>, <em>period</em> and <em>notificationCallback</em> parameters must be given for polling groups subscription purpose (see <em>DbmPoller::subscribe()</em>). The <em>notificationArg</em>, <em>cancelCallback</em> and <em>cancelArg</em> parameters are also used for subscription purpose but are optional.
     \param groupName  [in]: polling group name (only used for the creation or subscription to polling groups). 
     \param periodInSeconds  [in]: notification period (only used for the subscription to polling groups). This value of this notification period should be a multiple of the global polling period of the DbmPoller (which is 1 second). 
     \param notificationCallback  [in]: address of the notification callback function (only used for the subscription to polling groups). See <em>DbmCallback</em> prototype.
     \param notificationArg  [in]: user optional argument used by the notification callback function (only used for the subscription to polling groups). See <em>DbmCallback</em> prototype.
     \param cancelCallback  [in]: address of the optional cancel callback function (only used for the subscription to polling groups). See <em>DbmCallback</em> prototype.
     \param cancelArg  [in]: user optional argument used by the cancel callback function (only used for the subscription to polling groups). See <em>DbmCallback</em> prototype.
     \param contextId  [in]: optional context identifier, by default, it is the real-time context (not used with RTAP database).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  DbmDataSet(const char        *groupName = 0,
	     short              periodInSeconds = 0,
	     const DbmCallback  notificationCallback = 0,
	     ScsAny             notificationArg = 0,
	     const DbmCallback  cancelCallback = 0,
	     ScsAny             cancelArg = 0,
	     int                contextId = -1);

  /**
     \par Description:
     destructor. This function deletes the dataset.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~DbmDataSet();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     add a data to the dataset.
     \param data  [in]: contains the description of a database point using an <em>ScsAddress</em> object and, eventually, a value and its type.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus add(const DbmData &data);

  /**
     \par Description:
     remove a data from the dataset.
     \param data  [in]: pointer to the data to remove from the dataset.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the data was not found in the dataset.
  */
  ScsStatus remove(DbmData *data);

  /**
     \par Description:
     Returns and removes the first data of the dataset.
     \par Return values:
     the first of data of the dataset.     
  */  
  DbmData* get();  
  
  /**
     \par Description:
     modify the context identifier.
     \param contextId  [in]: new context identifier.
     \par Return values:
     none.
  */
  void setContext(int contextId)  {_contextId = contextId;};

  /**
     \par Description:
     get the context identifier.
     \par Parameters:
     none
     \par Return values:
     the context identifier.
  */
  int getContext() const {return _contextId;};

  /**
     \par Description:
     remove the data at position <em>index</em> from the dataset.
     \param index  [in]: index of the data to remove from the dataset.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the position of the data is not correct.
  */
  ScsStatus remove(int index);

  /**
     \par Description:
     return the number of data in the dataset.
     \par Parameters:
     none.
     \par Return values:
     the number of data in the dataset.
  */
  int getDataCount() const;

  /**
     \par Description:
     return the <em>pos</em>th data of the dataset.
     \param pos  [in]: position of the queried data in the dataset.
     \par Return values:
     the <em>pos</em>th data.
  */
  DbmData *operator[](int pos) const;

  /**
     \par Description:
     return the group name.
     \par Parameters:
     none.
     \par Return values:
     the polling group name.
  */
  const char *getGroupName() const;

  /**
     \par Description:
     set the group name.
     \param groupName  [in]: group name.
     \par Return values:
     none.
  */
  void setGroupName(const char *groupName);

  /**
     \par Description:
     return the notification period in milliseconds.
     \par Parameters:
     none.
     \par Return values:
     the notification period value.
  */
  int getPeriodInMS() const { return _periodInMS;};

  /**
     \par Description:
     set notification period value in milliseconds.
     \param period  [in]: period value.
     \par Return values:
     none.
  */
  void setPeriodInMS(int periodInMS) { _periodInMS = periodInMS;};
  
  /**
     \par Description:
     return the notification callback function.
     \par Parameters:
     none.
     \par Return values:
     the notification callback function.
  */
  DbmCallback getUpdateCallback() const { return _updateCallback;};

  /**
     \par Description:
     set notification callback function.
     \param updateCallback  [in]: address of the notification callback function. See <em>DbmCallback</em> prototype.
     \par Return values:
     none.
  */
  void setUpdateCallback(const DbmCallback updateCallback)
  { _updateCallback = updateCallback;};

  /**
     \par Description:
     return the notification callback user argument.
     \par Parameters:
     none.
     \par Return values:
     the notification callback user argument.
  */
  ScsAny getUpdateArg() const { return _updateArg;};

  /**
     \par Description:
     set notification callback user argument.
     \param updateArg  [in]: user optional argument used by the notification callback function. See <em>DbmCallback</em> prototype.

     \par Return values:
     none.
  */
  void setUpdateArg(ScsAny updateArg) { _updateArg = updateArg;};

  /**
     \par Description:
     return the cancel callback function.
     \par Parameters:
     none.
     \par Return values:
     the cancel callback function.
  */
  DbmCallback getCancelCallback() const { return _cancelCallback;};

  /**
     \par Description:
     set cancel callback function.
     \param cancelCallback  [in]: address of the optional cancel callback function. See <em>DbmCallback</em> prototype.
     \par Return values:
     none.
  */
  void setCancelCallback(const DbmCallback cancelCallback)
  { _cancelCallback = cancelCallback;};

  /**
     \par Description:
     return the cancel callback user argument.
     \par Parameters:
     none.
     \par Return values:
     the cancel callback user argument.
  */
  ScsAny getCancelArg() const { return _cancelArg;};

  /**
     \par Description:
     set cancel callback user argument.
     \param cancelArg  [in]: user optional argument used by the cancel callback function. See <em>DbmCallback</em> prototype.
     \par Return values:
     none.
  */
  void setCancelArg(ScsAny cancelArg) { _cancelArg = cancelArg;};

  /**
     \par Description:
     removes every data of the dataset.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus clearData();

  DbmData * const *getData(short &count) const;
  DbmDataList *getDataList() const { return _dataList;};
  //@}

private:
  DbmDataList *_dataList;
  int         _periodInMS;
  ScsString   *_groupName;
  DbmCallback  _updateCallback;
  ScsAny       _updateArg;
  DbmCallback  _cancelCallback;
  ScsAny       _cancelArg;
  int          _contextId;

  friend class DbmDataSetIterator;
};


/**
   \brief This class allows sequential access to all elements of a DbmDataSet.

The <em>DbmDataSetIterator</em> class is useful to get the values after reading when the DbmDataSet is quite large.
\code#include "dbm.h"\endcode
*/
class DBM_API DbmDataSetIterator
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an iterator. Immediately after construction, the position of the iterator is undefined.
     \param dataSet  [in]: the DbmDataSet you want to iterate to. 
  */
  DbmDataSetIterator(const DbmDataSet& dataSet);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~DbmDataSetIterator();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     Move the iterator to the next item and return it.
     \par Return values:
     Returns 0 if it is at the end of the collection, else returns the next item.
  */
  DbmData* operator()();

  /**
     \par Description:
     Move the iterator to the next item.
  */
  void operator++();

  /**
     \par Description:
     Move the iterator n items forward.
  */
  void operator+=(size_t n);

  /**
     \par Description:
     Returns the item at the current iterator position.
     \par Return values:
     the current item.
  */
  DbmData* key() const;

  /**
     \par Description:
     Resets the iterator to its initial state. The current item is undefined.
  */
  void reset();

  //@}

 private:
  DbmDataListIterator* _it;
};

class DbmClient_i;
class DbmReaderProxy;
class DbmWriterProxy;
class DbmConfigProxy;

class DbkAttrInfo;
struct DbkAccess;

/**
   Prototype of the DbmServer end snapshot callback function.
\code#include "dbm.h"\endcode
   \par Description:
     this function is a client application function called by the DbmServer to asynchronously notify the client when a snapshot is ended.
   \param arg  [in]: user optional argument (not used by DBM component). This argument is given by the client when it calls the setEndSnapshotCallback function and returned to it when the current callback function is called by the DbmServer. This parameter is optional, but, if set, could be used to give back information to the client.
   \par Return values:
     none.
*/
typedef void (*EndSnapshotCallback)(ScsAny arg);

class DbmClientSnapshotCallback_i;

/**
   \brief This class is one of the interface classes for the exported services of the <em>DBM</em> component (DataBase Manager): it allows to access to the database for reading/writing or configuring.

   This class is the interface class for the services exported by the DbmServer. It is used to read/write sets of data values into database, to interrogate the database for configuration information, and to create or delete points in database. 
\code#include "dbm.h"\endcode
*/
class DBM_API DbmServer
{
public:
  friend class ScsBasicAutomaton;

  /**@name Typedefs / defines*/
  //@{
  /**
     \par Description:
     enum corresponding to the possible values of operation modes for CE control (see <em>controlCE()</em> or <em>getCEOper()</em>).
     \code
     enum CEOperationMode { 
         SCS_CE_DISABLED = 0,
         SCS_CE_DISABLED_NORUN,
         SCS_CE_ENABLED,
         SCS_CE_ENABLED_OPT_A,
         SCS_CE_ENABLED_NORUN
     }; \endcode
     \par Values:
     \li \c SCS_CE_DISABLED:  disable the CE, running it one more time to update attribute qualities,
     \li \c SCS_CE_DISABLED_NORUN:  disable the CE, without running it,
     \li \c SCS_CE_ENABLED:  enable the CE, running it immediately (target point and all dependencies triggered on every write),
     \li \c SCS_CE_ENABLED_OPT_A:  enable the CE, running it immediately. DB write triggers target point only if other attributes in the target depend on it. All other points which depend on the attribute written are triggered.
     \li \c SCS_CE_ENABLED_NORUN:  enable CE, without running it.
  */
  enum CEOperationMode { 
    SCS_CE_DISABLED = 0,
    SCS_CE_DISABLED_NORUN,
    SCS_CE_ENABLED,
    SCS_CE_ENABLED_OPT_A,
    SCS_CE_ENABLED_NORUN
  };

  /**
     \par Description:
     enum corresponding to the possible values for the category of an attribute (see <em>addAttribute()</em>).
     \code
     enum AttributeCategory { 
         Static = 0,
         Dynamic,
         HistoricST,
         HistoricMT
     }; \endcode
     \par Values:
     \li \c Static:  the value of a static attribute is stored only in a real-time context,
     \li \c Dynamic:  the value of a dynamic attribute is stored in several context including the real-time context,
     \li \c HistoricST:  the value of a historic short-term attribute is stored like a volatile attribute and is stored every short-term period in a short-term historisation buffer,
     \li \c HistoricMT:  the value of a historic medium-term attribute is stored like historic the short-term attribute and is also stored every medium-term period in a medium-term historisation buffer.
  */
  enum AttributeCategory{
    Static = 0,
    Dynamic,
    HistoricST,
    HistorocMT
  };
  //@}

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the database server (DbmServer).
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required DbmServer is running,
     \param serverName  [in]: name of the server (the use of the default name is recommended).
     \param priority  [in]: priority of the messages to the DbmServer (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  DbmServer(const char *logicalEnv = 0,
	    const char *serverName = "DbmServer",
	    ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);

  /**
     \par Description:
     destructor. This function closes the connection with the DbmServer.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~DbmServer();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the DbmServer.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c DbmHostServerError : cannot connect with the ascmanager process.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  virtual ScsStatus getStatus() const;
  
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
     read value of point attributes in database.
     \param dataSet  [inout]: as input parameter, the dataset contains the description of the point attributes to read. Each attribute is described in a <em>DbmData</em> object using an <em>ScsAddress</em> object. As output parameter, the dataset contains the values read in database. Each value and its type are contained in a <em>DbmData</em> object of the dataset.
     \return
     \li \c ScsValid : success.
     \li \c DbmDataBaseConnectionError : the DbmServer is not connected to the database.
     \li \c DbmBadReferenceError : one of the addresses in the DbmDataSet do not correspond to a database entry.
     \li \c DbmReadError : error during database reading.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus read(DbmDataSet &dataSet) const;

  /**
     \par Description:
     write value of point attributes in database.
     \param dataSet  [in]: the dataset contains the description of the point attributes and the associated value to write. Each point is described in a <em>DbmData</em> object using an <em>ScsAddress</em> object.
     \return
     \li \c ScsValid : success.
     \li \c DbmDataBaseConnectionError : the DbmServer is not connected to the database.
     \li \c DbmBadReferenceError : one of the addresses in the dataset do not correspond to a database entry.
     \li \c DbmDataConversionError : the type specified in one data cannot be converted to the type of the corresponding database entry.
     \li \c DbmWriteError : error during database writing.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus write(const DbmDataSet &dataSet) const;

  /**
     \par Description:
     write value of point attributes in database.
     \param dataSet  [in]: the dataset contains the description of the point attributes and the associated value to write. Each point is described in a <em>DbmData</em> object using an <em>ScsAddress</em> object.
     \return
     \li \c No status is returned. The write is non blocking
  */
  void uncheckedWrite(const DbmDataSet &dataSet) const;

  /**
     \par Description:
     return the alias of a database point. The address returned contains the point alias beginning with the <em>\<alias\></em> view specifier.
     \param address  [inout]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getAlias(ScsAddress &address) const;

  /**
     \par Description:
     return the structure of a point attribute (its type, <em>SCS_SCALAR</em>, <em>SCS_VECTOR</em> or <em>SCS_TABLE</em>, its number of fields, its number of records and the size of a record).
     \param address  [in]: <em>ScsAddress</em> object containing a symbolic description of the point attribute address in database.
     \param type  [out]: attribute type, <em>ScsData::SCS_SCALAR</em>, <em>ScsData::SCS_VECTOR</em> or <em>ScsData::SCS_TABLE</em> (see <em>ScsData::AttributeType</em> enumeration).
     \param fieldCount  [out]: the number of fields. This is always 1 for scalar or vector attributes (vectors are considered to occupy many records, but only one field).
     \param recordCount  [out]: the number of records. This is always 1 for a scalar attribute.
     \param recordUsed  [out]: the number of records in use. This is always 1 for a scalar attribute. For a vector attribute, it is equal to <em>recordCount</em>.
     \param recordSize  [out]: the size in bytes of a record. For scalar or vector attributes, this is the size of a single data element.
     \param fieldNames  [out]: the name of the fields for a table.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getAttributeStructure(const ScsAddress       &address,
				  ScsData::AttributeType &type,
				  short                  &fieldCount,
				  short                  &recordCount,
				  short                  &recordUsed,
				  unsigned int           &recordSize,
				  char**           &fieldNames) const;

  /**
     \par Description:
     return the full path of a point. The address returned is a symbolic address equivalent which is the absolute path to the given addres, and to the same level.
     \param address  [inout]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getFullPath(ScsAddress &address) const;

  /**
     \par Description:
     return the children addresses of a database point. The memory of the output arrays is caller responsibility.
     \param parent  [in]: <em>ScsAddress</em> object containing a symbolic description of the parent point address in database.
     \param children  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a child point. The symbolic description contains the parent point alias and the name of the child point (&quot;<em>\<alias\>parent_alias:child_point_name</em>&quot;).
     \param count  [out]: the number of child points the queried point has.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getChildren(const ScsAddress  &parent, 
			ScsAddress       *&children,
			short             &count) const;

  /**
     \par Description:
     return the attribute names for a database point, in the alphabetical order. Only the attributes of type <em>type</em> are returned if its value is different of <em>ScsUNKNOWN</em>.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \param attribute  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description for an attribute of the point. The symbolic description contains the point alias and the name of the attribute.
     \param count  [out]: the number of attributes the queried point has.
     \param type  [in]: a type of attribute.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getAttributes(const ScsAddress  &point, 
			  ScsAddress       *&attribute,
			  short             &count,
			  ScsType            type = ScsUNKNOWN) const;

  /**
     \par Description:
     return the class name of a database point.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \param className  [out]: class name of the queried point.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getClassName(const ScsAddress  &point,
			 char             *&className) const;

  /**
     \par Description:
     return the class id of a database point.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \param classId  [out]: class id of the queried point.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getClassId(const ScsAddress &point,
		       unsigned short   &classId) const;

  /**
     \par Description:
     return the user class id of a database point.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \param classId  [out]: class id of the queried point.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getUserClassId(const ScsAddress &point,
		       unsigned short   &classId) const;

  /**
     \par Description:
     return the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
     \param className  [in]: name of the class.
     \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
     \param count  [out]: the number of instances of the specified class.
     \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getInstances(const char  *className,
			 ScsAddress *&instances,
			 unsigned int &count,
			 const char  *subTree = NULL) const;
  /**
     \par Description:
     return the address of all the instances of specified user class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
     \param className  [in]: name of the class.
     \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
     \param count  [out]: the number of instances of the specified class.
     \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getInstances(const char  *className,
			 ScsAddress *&instances,
			 short &count,
			 const char  *subTree = NULL) const;
  /**
     \par Description:
     return the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
     \param classId  [in]: id of the class.
     \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
     \param count  [out]: the number of instances of the specified class.
     \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getInstances(unsigned short   classId,
			 ScsAddress     *&instances,
			 unsigned int    &count,
			 const char      *subTree = NULL) const;
  /**
     \par Description:
     This API is obsolete. It returns the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
     \param classId  [in]: id of the class.
     \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
     \param count  [out]: the number of instances of the specified class.
     \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getInstances(unsigned short   classId,
			 ScsAddress     *&instances,
			 short          &count,
			 const char      *subTree = NULL) const;

  /**
     \par Description:
     return the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
     \param classId  [in]: id of the class.
     \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
     \param count  [out]: the number of instances of the specified class.
     \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getInstancesByUserClassId(unsigned short   classId,
			 ScsAddress     *&instances,
			 unsigned int &count,
			 const char      *subTree = NULL) const;

 /**
     \par Description:
     This API is obsolete. It returns the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
     \param classId  [in]: id of the class.
     \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
     \param count  [out]: the number of instances of the specified class.
     \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getInstancesByUserClassId(unsigned short   classId,
			 ScsAddress     *&instances,
			 short        &count,
			 const char      *subTree = NULL) const;
                         
  // cla : This method returns an alias list, ordered by instanceIds, correspondant to the given classId
  ScsStatus getInstancesOrderedByIds(unsigned short  classId,
				     DbmStringList *&aliasOrderedByIds) const;

  /**
     \par Description:
     get the CE operation indicator for one or more database points. The returned operation indicators can be of the <em>CEOperationMode</em> enumerate values: <em>SCS_CE_DISABLED</em>, <em>SCS_CE_ENABLED</em> or <em>SCS_CE_ENABLED_OPT_A</em>. This query will never return the value <em>SCS_DISABLED_NORUN</em> which is only used for <em>controlCE()</em>.
     \param points  [in]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a point address in database.
     \param operationIndicators  [out]: list of operation indicators.
     \param count  [in]: the number of points (and also operation indicators returned).
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getCEOper(const ScsAddress*  points,
		      CEOperationMode*&  operationIndicators,
		      const unsigned int count) const;

  /**
     \par Description:
     control the CE activation for one or more database points.
     \param points  [in]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a point address in database.
     \param operationModes  [in]: list of CE operation mode values. Each value corresponds to the point at the same index int the <em>point</em> list. The possible values are defined in the <em>CEOperationMode</em> enumerate.
     \param count  [in]: the number of points (or operation mode values).
     \return
     \li \c ScsValid : success.
     \li \c DbmRtapFunctionError : a database control operation has failed.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus controlCE(const ScsAddress      *points,
		      const CEOperationMode *operationModes,
		      const unsigned int     count) const;

  /**
     \par Description:
     change the calculation mode of the database instance designated by address.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \param optimized  [in]: true turns on the optimised mode of the calculation engine for the specified instance.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus setInstanceCEMode(const ScsAddress& point, bool optimized) const;

  /**
     \par Description:
     copy a point from a given class.
     \param className  [in]: name of the class to be copied. This name is the name of point which is a child of a point named &quot;<em>\<alias\>pointTemplates</em>&quot;.
     \param parent  [in]: <em>ScsAddress</em> object containing a symbolic description of the parent point under which the new point will be copied.
     \param name  [in]: name of the point to create.
     \param alias  [in]: alias of the point to create.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry or the point named &quot;<em>\<alias\>pointTemplates</em>&quot; does not exist.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus instanciatePoint(const char       *className,
			     const ScsAddress &parent,
			     const char       *name,
			     const char       *alias) const;

  /**
     \par Description:
     delete a point from the database.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point to be deleted.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus deletePoint(const ScsAddress &point) const;

  // New database kernel
  /**
     \par Description:
     return the children addresses and children aliases of a database point. The memory of the output arrays is caller responsibility.
     \param parent  [in]: <em>ScsAddress</em> object containing a symbolic description of the parent point address in database.
     \param children  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a child point. The symbolic description contains the parent point alias and the name of the child point (&quot;<em>\<alias\>parent_alias:child_point_name</em>&quot;).
     \param aliases  [out]: list of the children aliases.
     \param count  [out]: the number of child points the queried point has.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getChildrenAndAliases(const ScsAddress  &parent, 
				  ScsAddress       *&children,
				  const char*      *&aliases,
				  short             &count) const;

  /**
     \par Description:
     return the children addresses, aliases and optimisation properties of a database point. The memory of the output arrays is caller responsibility.
     \param parent  [in]: <em>ScsAddress</em> object containing a symbolic description of the parent point address in database.
     \param children  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a child point. The symbolic description contains the parent point alias and the name of the child point (&quot;<em>\<alias\>parent_alias:child_point_name</em>&quot;).
     \param aliases  [out]: list of the children aliases.
     \param optimisations  [out]: list of the optimised flags. 1 means that the child instance is optimised in the dependency graph of the calculation engine.
     \param count  [out]: the number of child points the queried point has.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getChildrenProperties(const ScsAddress& parent, 
				  ScsAddress*&      children,
				  const char**&     aliases,
				  int*&             optimisations,
				  short&   count) const;

  /**
     \par Description:
     return the class names of the database.
     \param classNames  [out]: list of class names.
     \param count  [out]: the number of classes.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getClasses(const char** &classNames, int &count) const;

  /**
     \par Description:
     return the attribute formulas definitions for a database point, in the attribute order. It is caller responsibility to free the allocated memory.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \param formulas  [out]: list of formulas definitions. An empty string means no definition.
     \param evaluationOrders  [out]: list of evaluation order ranks.
     \param activationStates  [out]: list of activation flags. 1 means enable, 0 means disable.
     \param count  [out]: the number of attributes the queried point has.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getAttributeFormulas(const ScsAddress  &point, 
				 const char*      *&formulas,
				 long*		   &evaluationOrders,
				 short*		   &activationStates,
				 short             &count) const;

  /**
     \par Description:
     set a formula for an attribute.
     \param attribute  [in]: <em>ScsAddress</em> object containing a symbolic description of the attribute address in database.
     \param formula  [in]: formula definition.
     \param errorMsg [out] : error message.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmFormulaSyntaxError : the formula definition is not syntactically correct.
     \li \c DbmDependencyCycleError : the formula insertion creates a new dependency cycle that is forbidden in the current mode.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus setAttributeFormula(const ScsAddress &attribute, 
				const char*       formula,
				char*            &errorMsg) const;

  /**
     \par Description:
     create a group of values. This method can be used only with local client. It uses shared memory instead of orb to read values.
     \param dataSet [in]: list of addresses to put in the group.
     \param numGroup [out]: number of created group.
     \param listScsData [out]: list of ScsData containing values to read.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : this method can not be used because client is not local.
  */
  ScsStatus createGroup(DbmDataSet & dataSet, int & numGroup, ScsData * & listScsData);
  
  /**
     \par Description:
     delete a group of values. This method can be used only with local client. It uses shared memory instead of orb to read values
     \param numGroup [in]: group number between 0 and number of group - 1 created or -1 for all.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : this method can not be used because client is not local or the group doesn't exist.
  */
  ScsStatus deleteGroup(int numGroup = -1);

  /**
     \par Description:
     read values of a group. This method can be used only with local client. It uses shared memory instead of orb to read values
     \param numGroup [in]: group number between 0 and number of group - 1 created or -1 for all.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : this method can not be used because client is not local.
  */
  ScsStatus read(int numGroup = -1);

  /**
     \par Description:
     return the points whose name matches regular expression in the point subtree.
     \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
     \param regexpr  [in]: regular expression the name must match.
     \param adresses  [out]: list of the addresses of the matching points.
     \param count  [out]: number of adresses.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReferenceError : the address does not correspond to a database entry.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus queryByName(const ScsAddress  &point,
			const char*	       regexpr,
			ScsAddress       *&adresses,
			unsigned long     &count) const;

  /**
     \par Description:
     snapshot the database.
     \param type  [in]:  if 0, the snapshot is done in BINARY, if 1, the snapshot is done in XML.
     \param path [in]: if nil, files are written in SCSPATH/Database/binary for BINARY files or SCSPATH/Database/xml for XML files, else, files are written in path.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus forceSnapshot(short type = 0, const char* path = "") const;

  /**
     \par Description:
     load Ascii files for a context.
     \param contextId  [in]:  if -1, all context will be loaded, else only the corresponding context will be loaded.
     \param path [in]: if 0, files are read from SCSPATH/Database/binary, else, files are read from path.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus readSnapshot(short contextId = -1, const char* path = 0) const;

  /**
     \par Description:
     add a class in the database.
     \param name  [in]:  name of the class to be added.
     \param periodiciteST  [in]: period in seconds for the short term historisation.
     \param nbHistoST  [in]: number of values that will be kept in the short term historisation buffer.
     \param periodiciteMT [in]: period in seconds for the medium term historisation.
     \param nbHistoMT [in]: number of values that will be kept in the medium term historisation buffer.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
     \li \c DbmDtdAbsentError : DTD for saving in XML don't exist.
  */
  ScsStatus addClass(const char* name,
		     long periodiciteST,
		     long nbHistoST,
		     long periodiciteMT,
		     long nbHistoMT) const;

  /**
     \par Description:
     delete a class in the database.
     \param name  [in]:  name of the class to be deleted.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus deleteClass(const char* name) const;

  /**
     \par Description:
     activate formulas for attributes of a class.
     \param name  [in]:  name of the class.
     \param desactive  [in]: if 0, formulas will activated, if 1, formulas will be desactivated.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus activateFormulasOfClass(const char* name, short desactive = 0) const;

  /**
     \par Description:
     add an instance in the database.
     \param className  [in]:  name of the class.
     \param path  [in]: path of the instance (contains its name).
     \param alias [inout] : alias of the instance (if Null, an alias is generated automatically and is returned)
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus addInstance(const char* className, const ScsAddress& path, char*& alias) const;

  /**
     \par Description:
     delete instances from a branch.
     \param path  [in]:  path of the instance (start of the tree) to be deleted.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus deleteTree(const ScsAddress& path) const;

  /**
     \par Description:
     activate or desactivate formulas for or from an instance path.
     \param path  [in]:  path of the instance (start of the tree) where formulas will be activated or desactivated.
     \param desactive [in]: if 0, formulas will be activated, if 1, formulas will be desactivated.
     \param branch [in]: if 0, formulas of an instance will be activated or desactived, if 1, formulas of an instance and beneath its tree will be activated or desactivated.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus activateFormulasOfInstances(const ScsAddress& path, short desactive = 0, short branch = 0) const;

  /**
     \par Description:
     copy a branch from an address to another one.
     \param fromAddress  [in]:  address of an instance (start of the tree) to be copied.
     \param toAddress [in]: address of an instance to be pasted.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus copyBranch(const ScsAddress& fromAddress, const ScsAddress& toAddress) const;

  /**
     \par Description:
     add an attribute in a defined class.
     \param className  [in]:  name of the class where an attribute will be added.
     \param attrName [in]: name of the attribute to be added.
     \param valueType [in]: value type of the attribute (i.e : DBK_BOOLEAN, DBK_INT8,...).
     \param attrType [in]: if Static, the attribute will have a static behavior (i.e : the attribute will exist only in a real-time context),
     if Dynamic, the attribute will exist in several context including real-time context,
     if HistoricST, the attribute will exist in the same context as a volatile attribute and will be historised every short term period,
     if HistoricMT, same as a historic short term attribute, except that the attribute will be  also historised every medium term period.
     \param replicated [in]: if 0, the attribute will be non-replicated, if 1, the attribute will be replicated.
     \param stringLength [in]: the stringLength will be taken into account only if the value type of the attribute is a DBK_CHARN or a DBK_BITFIELD type, it indicates the number of char, or bits, needs for the storage of the attribute value.
     \param defaultValue [in]: default value for the attribute.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus addAttribute(const char* className, 
			 const char* attrName,
			 short valueType,
			 short attrType = Static,
			 short replicated = 0,
			 short stringLength = 0,
			 const char* defaultValue = 0) const;

  /**
     \par Description:
     add an attribute of type vector in a defined class.
     \param className  [in]:  name of the class where an attribute will be added.
     \param attrName [in]: name of the attribute to be added.
     \param valueType [in]: value type of the value record in the attribute (i.e : DBK_BOOLEAN, DBK_INT8,...).
     \param attrType [in]: if Static, the attribute will have a static behavior (i.e : the attribute will exist only in a real-time context). If Dynamic, the attribute will exist in several context including real-time context. If HistoricST, the attribute will exist in the same context as a volatile attribute and will be historised every short term period. If HistoricMT, same as a historic short term attribute, except that the attribute will be  also historised every medium term period.
     \param numRecord [in]: number of records.
     \param replicated [in]: if 0, the attribute will be non-replicated, if 1, the attribute will be replicated.
     \param stringLength [in]: the stringLength will be taken into account only if the value type of the attribute is a DBK_CHARN or a DBK_BITFIELD type, it indicates the number of char, or bits, needed for the storage of the attribute value.
     \param defaultValue [in]: default value for the attribute.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus addVectorAttribute(const char* className, 
			       const char* attrName,
			       short valueType,
			       short attrType,
			       short numRecord,
			       short replicated = 0,
			       short stringLength = 0,
			       const char* defaultValue = NULL) const;


  /**
     \par Description:
     add an attribute of type table in a defined class.
     \param className  [in]:  name of the class where an attribute will be added.
     \param attrName [in]: name of the attribute to be added.
     \param fieldName [in] : name of the fields of the table.
     \param valueType [in]: value type of the fields of the attribute (i.e : DBK_BOOLEAN, DBK_INT8,...).
     \param attrType [in]: if Static, the attribute will have a static behavior (i.e : the attribute will exist only in a real-time context). If Dynamic, the attribute will exist in several context including real-time context. If HistoricST, the attribute will exist in the same context as a volatile attribute and will be historised every short term period. If HistoricMT, same as a historic short term attribute, except that the attribute will be  also historised every medium term period.
     \param numRecord [in]: number of records.
     \param numField [in]: number of fields.
     \param replicated [in]: if 0, the attribute will be non-replicated, if 1, the attribute will be replicated.
     \param stringLength [in]: the stringLength will be taken into account only if the value type of the attribute is a DBK_CHARN or a DBK_BITFIELD type, it indicates the number of char, or bits, needed for the storage of the attribute value.
     \param defaultValue [in]: default value for the attribute.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus addTableAttribute(const char* className, 
			      const char* attrName,
			      const char** fieldName,
			      int* valueType,
			      short attrType,
			      short numRecord,
			      short numField,
			      short replicated = 0,
			      unsigned int* stringLength = 0,
			      const char* defaultValue = 0) const;

  /**
     \par Description:
     delete an attribute of a defined class.
     \param className  [in]:  name of the class where an attribute will be deleted.
     \param attrName [in]: name of the attribute to be deleted.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus deleteAttribute(const char* className, const char* attrName) const;	

  /**
     \par Description:
     get the definition of all the attributes of a class.
     \param className  [in]:  name of the class.
     \param attrNames [out]: list of the name for the attributes.
     \param valueTypes [out] : list of the value type for the attributes.
     \param attrTypes [out] : list of the type (static, dynamic, hictoric) for the attributes.
     \param replicated [out] : list of the value for replication for the attributes.
     \param defaultValues [out] : list of the default value for the attributes.
     \param count [out] : number of elements in the returned list.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getAttributesDescription(const char*   className,
				     char**       &attrNames,
				     ScsType*     &valueTypes,
				     int*         &attrTypes,
				     int*         &replicated,
				     ScsData*     &defaultValues,
				     short        &count) const;
  /**
     \par Description:
     get the information on a class.
     \param className  [in]:  name of the class.
     \param classInfo [out]: information on the class.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getClassInfo(const char   *className,
			 DbmClassInfo &classInfo) const;
  /**
     \par Description:
     get the information on the database.
     \param databaseInfo  [out]:  information on the database.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
  */
  ScsStatus getDatabaseInfo(DbmDatabaseInfo &databaseInfo) const;

  // New database kernel
  /**
     \par Description:
     get the information on several attributes.
     \param count  [in]:  number of attributes.
     \param addresses [in]: list of the address for the attributes.
     \param info [out] : list of the information for the attributes.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
     \li \c DbmBadReferenceError : at least one address is wrong.
  */
  ScsStatus getAttrInfo(int count, const ScsAddress * addresses, DbkAttrInfo *& info) const;

  /**
     \par Description:
     get the information on several attributes.
     \param count  [in]:  number of attributes.
     \param addresses [in]: list of the address for the attributes.
     \param info [out] : list of the information for the attributes.
     \return
     \li \c ScsValid : success.
     \li \c DbmORBError : cannot connect with the remote DbmServer.
     \li \c DbmBadReferenceError : at least one address is wrong.
  */
  ScsStatus getAttrInfo(int count, const char** addresses, DbkAttrInfo *& info) const;

/**
     \par Description:
     check the syntax of a value.
     \param value  [in]:  syntax of the value.
     \param valueType [in]: type of the value.
     \param numChar [in] : number of char or bit (when the type is respectively a DBK_CHARN or a DBK_BITFIELD).
     \return
     \li \c ScsValid : success.
     \li \c DbmValueSyntaxError : syntax error.
  */
  ScsStatus checkSyntaxValue(const char* value,
			     const short valueType, 
			     int numChar = 0) const;
  
  ScsStatus getSymbolicAddress (const DbkAddressId& reference,
  				char *& symbolicAddress) const;
  ScsStatus getDirectAddress(DbkAddressId& address,
			     const char* attributeName) const;


  /**
     \par Description:
     return the direct address of the father instance.
     \param child  [in]: Direct address of the child istance.
     \param father [out]: Direct address of the father instance. If the father doesn't exists a null address is returned.
     \return
     \li \c ScsValid : success.
     \li \c DbmBadReference : the child address is invalid or root.
  */
  ScsStatus getFather(const DbkAddressId& child, DbkAddressId& father);

  /**
     \par Description:
     check the user formulas definition.
     \param nbUserFormulas  [out]:  number of user formulas.
     \param formulasNames [out]: list of names for user formulas.
     \param nbArgument [out] : list of number of arguments for user formulas.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus getUserFormulasNames(int    &nbUserFormulas,
				 char** &formulasNames,
				 int*   &nbArgument) const;

  ScsStatus setContextName(const short id, const char* name) const;

  /**
     \par Description:
     get the user context identifier.
     \param name  [in]:  name of the user context identifier.
     \param id [out]: id of the user context.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus getUserContextId(const char* name, short& id) const;

  /**
     \par Description:
     get names of user context.
     \param names  [out]:  names of user context.
     \param count [out]: number of user context.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus getUserContextNames(char**& names, short& count) const;

  /**
     \par Description:
     set the end of snapshot callback.
     \param callback  [in]:  callback function.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus setEndSnapshotCallback(EndSnapshotCallback callback);

  /**
     \par Description:
     snapshot dynamic attributes for a given context.
     \param contextId [in]: context identifier, or -1 to denote all contexts
     \param synchronous [in]: if 0, the callback defined by setEndSnapshotCallback is called at the end of the snapshot; if 1, the snapshot have priority.
     \param arg  [in]: optional parameter to the callback defined by setEndSnapshotCallback.
     \param path [in]:  if NULL, snapshots are written in the path $SCSPATH/Database/Context_\<contextId\>.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus snapshotNonStaticAttributes(int contextId, 
					int synchronous = 0,
					ScsAny arg = 0, 
					const char* path = "") const;

  /**
     \par Description:
     snapshot replicated attributes for a given context.
     \param contextId  [in]:  context identifier, if -1 all the context are snapshoted.
     \param synchronous  [in]:  if 0, the callback defined by setEndSnapshotCallback is called at the end of the snapshot, if 1, the snapshot have priority.
     \param arg  [in]: optional parameter to the callback defined by setEndSnapshotCallback.
     \param path [in]:  if NULL, snapshots are written in the path $SCSPATH/Database/Context_\<contextId\>.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus snapshotReplicatedAttributes(int contextId, 
					 int synchronous = 0,
					 ScsAny arg = 0, 
					 const char* path = "") const;

  /**
     \par Description:
     load non static attributes for a given context.
     \param contextId  [in]:  context identifier, if -1 all the context are loaded.
     \param path [in]:  if NULL, snapshots are read in the path $SCSPATH/Database/Context_\<contextId\>.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus loadNonStaticAttributes(int contextId, 
				    const char* path = "") const;

  /**
     \par Description:
     load replicated attributes for a given context.
     \param contextId  [in]:  context identifier, if -1 all the context are loaded.
     \param path [in]:  if NULL, snapshots are read in the path $SCSPATH/Database/Context_\<contextId\>.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus loadReplicatedAttributes(int contextId, 
				     const char* path = "") const;

  /**
     \par Description:
     duplicate non static values of a context into another one.
     \param destContextId  [in]:  context identifier for the destination context.
     \param sourceContextId  [in]:  context identifier for the source context (by default, the real-time context is snapshoted).
     \return
     \li \c ScsValid : success.
  */
  ScsStatus duplicateContext(int destContextId,
			     int sourceContextId = 0) const;
  
  
  // get shared memory
  void* getShareMem();

  // Attributes marking
  ScsStatus markAttributesForLstServer(DbkAddressId** addrId, int count) const;
  ScsStatus unmarkAttributesForLstServer(DbkAddressId** addrId, int count) const;

  //@}

  // Write method using direct addresses (not exported...)
  ScsStatus directRead(const DbmDataSet &symbAddresses, DbmDirectDataSet &values) const;

  /**
     \par Description:
     Change attribute type in runtime, mainly used for "historic change base".
     \param pClassName [in]:  the class name to treat
     \param pAttrName  [in]:  the attribute name to treat
     \param pNewType   [in]:  the new type of the attribute
     \return
     \li \c ScsValid : success.
  */
  ScsStatus changeAttrType(const char* pClassName, const char* pAttrName, short pNewType) const;


  /**
     \par Description:
     Change attribute type in runtime, mainly used for "historic change base".
     \param addrId   [in]:  an array of DbkAddressId to treat
     \param count    [in]:  the number of elements in the array
     \param pNewType [in]:  the new type of the attributes
     \return
     \li \c ScsValid : success.
  */
  ScsStatus changeAttrType(DbkAddressId** addrId, int count, short pNewType) const;

  /**
     \par Description:
     read via dbkaddressId when pointer on shared memory cannot be used because of a distant machine, the value are written in the DbmDirectData's buffer
     \param values  [in-out]:  The DbmDataSet having all point to read. The new value are in the buffer of the DbmDirectData
     \return
     \li \c ScsValid : success.
  */
  ScsStatus directRead(DbmDirectDataSet& values) const;

  /**
     \par Description:
     read directly in shared memory, the value are write in the DbmDirectData's buffer
     \param values  [in-out]:  The DbmDataSet having all point to read. The new value are in the buffer of the DbmDirectData
     \return
     \li \c ScsValid : success.
  */
  ScsStatus directReadInShareMem(DbmDirectDataSet& values) const;

  /**
     \par Description:
      write the DbmDirectData's buffer in shared memory via the DbkAddressId
     \param dataSet  [in]:  The DbmDataSet to write
     \return
     \li \c ScsValid : success.
  */
  ScsStatus directWrite(const DbmDirectDataSet &dataSet) const;

  /**
     \par Description:
      write the DbmDirectData's buffer in shared memory via the DbkAddressId
     \param dataSet  [in]:  The DbmDataSet to write
     \return
     \li \c No status is returned. The write is non blocking
  */
  void uncheckedDirectWrite(const DbmDirectDataSet &dataSet) const;

  /**
     \par Description:
     convert a DbmDataSet in DbmDirectDataSet, if you are on local machine, connect DbmDirectData to the shared memory.
     \param symbAddresses  [in]:  The DbmDataSet having all the point you want to convert
     \param dataSet  [out]:  The DbmDirectDataSet having all the point converted with the connection to shared memory if you are in a local machine
     \return
     \li \c ScsValid : success.
  */
  ScsStatus convertDbmDataSet_In_DbmDirectDataSet(const DbmDataSet &symbAddresses, DbmDirectDataSet &dataSet) const;

  /**
     \par Description:
     save the DbmDirectDataSet in the file specified.
     \param filename  [in]:  path name  where DbmDirectDataSet are saved 
     \param dataset  [in]:  The DbmDirectDataSet to save
     \return
     \li \c ScsValid : success.
  */
  ScsStatus saveDbmDirectDataSet(const char *filename, DbmDirectDataSet &dataset);

  /**
     \par Description:
     restore the DbmDirectDataSet from the file specified. If you are on a local machine, connect DbmDirectData to the shared memory
     \param filename  [in]:  path name where DbmDirectDataSet have been saved  
     \param dataSet  [in]:  The DbmDirectDataSet build
     \return
     \li \c ScsValid : success.
  */
  ScsStatus restore_DbmDirectDataSet(const char*       filename,
				     DbmDirectDataSet &dataSet) const;


/**
   \par Description:
     Subscribe to the history snapshot with the specified period and callback.
   \param subId [out]: subscription identifier,
   \param hisType  [in]: historisation type  (0 means ST, 1 means MT),
   \param period [in]: historisation period in second,
   \param callback [in]: name of the callback,
   \param arg  [in]: optional user argument passed as parameter of the <em>notifyPeriodCallback()</em> method and returned back to the callback function when called.
   \par Return values:
     Status of the command.
*/
  ScsStatus subscribeHisSnapshot(int                             &subId,
				 short                            hisType, 
				 unsigned int                     period, 
				 DbmHisSubscribeSnapshotCallback  callback,
				 ScsAny                           arg = 0) const;


  ScsStatus unSubscribeHisSnapshot(int subId) const;

  /**
     \par Description:
     subscribe a list of type and period to the Dbm server, and start callback at each period
     \param items  [in]:  list of items which contain Scstype and period  
     \param count  [in]:  number of element in the list
     \param callback  [in]:  name of the callback  
     \param arg  [in]: optional user argument passed as parameter
     \return
     \li \c ScsValid : success.
  */
  ScsStatus subscribeHisPeriod(DbmHisPeriod*                 items,
			       unsigned int                  count,
			       DbmHisSubscribePeriodCallback callback,
			       ScsAny                        arg = 0);
  
  /**
     \par Description:
     unsubscribe to the value write notification.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus unSubscribeHisPeriod() const;

  /**
    \par Description:
     get a list of static attribute
    \param synchronous  [in]: if set to 1, then the system is blocked during the operation (synchronous behaviour), else the systeme wait for a callback
    \param arg  [in]:  argument of the callback
    \param path  [in]:  path of the file
    \return
    \li \c ScsValid : success.
  */
  ScsStatus snapshotStaticAttributes(int         synchronous = 0,
				     ScsAny      arg = 0,
				     const char* path = "") const;
  /**
     \par Description:
     load a list of static attribute
     \param path  [in]:  path of the file
     \return
     \li \c ScsValid : success.
  */   
  ScsStatus loadStaticAttributes(const char* path= "") const;
  
  /**
    \par Description:
     snapshot the structure of the database (including static attribute values)
    \param synchronous  [in]:  if 1 the synchronous block the système else the systeme wait for a callback
    \param arg  [in]:  argument of the callback
    \param path  [in]:  path of the file
    \return
    \li \c ScsValid : success.
  */
  ScsStatus snapshotDatabaseStructure(int synchronous = 0,
				      ScsAny arg = 0,
				      const char* path = "") const;
  /**
     \par Description:
     load a new structure of database
     \param path  [in]:  path of the file
     \return
     \li \c ScsValid : success.
  */   
  ScsStatus reloadDatabaseStructure(const char* path= "") const;
  
  /**
     \par Description:
     load a list of static attribute
     \param hisType [in]: the archive type
     \param period [in]: the archive period
     \param date [in]: the date
     \param bufferId [in]: the buffer number
     \param path  [in]:  path of the file
     \param callback [in]: the callback
     \param arg [in]: the callback parameter if necessary
     \return
     \li \c ScsValid : success.
  */   
  ScsStatus loadHisFiles(short                   hisType, 
			 unsigned int            period,
			 unsigned long           date,
			 unsigned short          bufferId,
			 const char*             path,
			 DbmHisLoadFilesCallback callback,
			 ScsAny                  arg = 0) const;

  
 /**
     \par Description:
     load a list of static attribute
     \param values  [in]:  the values
     \return
     \li \c ScsValid : success.
  */   

  ScsStatus directReadHistoricQuality(const DbmDataSet &values) const;
  
 /**
     \par Description:
     read historic value from the historic buffer
     \param addrIdList  [inout]:  list of historic value addresses and of their correcpondent values
     \return
     \li \c ScsValid : success.
  */   
  ScsStatus readHistoric(DbmHisAddressDataSet &addrIdList);

/**
     \par Description:
     extract historic value from the historic file
     \param addrIdList  [in]:  list of historic value addresses
     \param callback  [in]:  name of the callback function called when read has ended
     \param arg  [in]:  argument of the callback function
     \return
     \li \c ScsValid : success.
  */

  ScsStatus extractHistoric(const DbmHisAddressDataSet &addrIdList,
			    DbmHisHistoricCallback      callback,
			    ScsAny                      arg = 0);
  
 /**
     \par Description:
     read historic quality value from the historic buffer
     \param values  [in]:  list of address and historic value read
     \param callback  [in]:  name of the callback when read has ended
     \param arg  [in]:  argument of the callback
     \return
     \li \c ScsValid : success.
  */ 
  
  ScsStatus readHistoricQuality(const DbmHisAddressDataSet &values,
				DbmHisHistoricCallback      callback,
				ScsAny                      arg = 0);


/**
     \par Description:
     extract historic quality value from the historic file
     \param values  [in]:  list of address and historic value read
     \param callback  [in]:  name of the callback when read ending
     \param arg  [in]:  argument of the callback
     \return
     \li \c ScsValid : success.
  */

  ScsStatus extractHistoricQuality(const DbmHisAddressDataSet &values,
				   DbmHisHistoricCallback      callback,
				   ScsAny                      arg = 0) const;


/**
     \par Description:
     get the number of restitution context
     \param hisType  [in]:  type of value (Short term = 0 , Middle Term = 1)
     \param numContext  [out]:  number of context
     \return
     \li \c ScsValid : success.
  */
  ScsStatus getNumRestitutionContext(short hisType, int& numContext) const;

/**
     \par Description:
     Get the context and subcontext id of 
     \param hisType  [in]: type of value (Short term = 0 , Middle Term = 1)
     \param periodicity  [in]:   historisation period in second,
     \param date [in]: date in second of reading information
     \param contextId  [out]:  contextId of the historisation
     \param subContextId  [out]:  subcontextId of the historisation
     \return
     \li \c ScsValid : success.
  */
  ScsStatus isHistInfo(int            hisType, 
		       int            periodicity,
		       unsigned long  date, 
		       int           &contextId, 
		       int           &subContextId) const;

/**
     \par Description:
     Get the historisation information from attributes
     \param count  [in]: number of attribute in the list
     \param dbkAttInfo  [in]:   list of attribute, type and periodicity
     \return
     \li \c ScsValid : success.
  */

  ScsStatus getAttrInfo(int count, DbkHisAttrInfo* dbkAttInfo) const;

/**
     \par Description:
     Callback from the server to the client at each period, with the supplied arguments.
     \param date  [in]: date of the triggering
     \param hiscontext  [in]: list of history context
     \param count  [in]: number of history context entries
     \param arg  [in]: arg supplied to the callback
     \return
     \li \c ScsValid : success.
  */
  //ScsStatus periodCallback(DbmHisSubscribePeriodCallback retour);

  ScsStatus callbackHisPeriod(unsigned long  date,
			      DbmHisContext* hiscontext,
			      unsigned long  count,
			      ScsAny         arg);

/**
     \par Description:
     Changes the timeout for CORBA requests
     \param timeoutInMs [in]: timeout in milliseconds.
  */
  void changeTimeout(const unsigned int &timeoutInMs);

/**
     \par Description:
     Send a message to request a service (private use only)
     \param serviceId [in]: identifier of the requested service
     \param requestMsg [in]: in data to get the service
     \param responseMsg [out]: response data
     \return
     \li \c ScsValid : sucess
  */
  ScsStatus sendMessage(int serviceId,
			char* requestMsg,
			char*& responseMsg);

protected:

  friend class AlmServerIdl_i;

  virtual ScsStatus readFrom(const void * nameList, 
			     void *& valueList, 
			     int contextId, 
			     const char * userName) const;

  virtual ScsStatus writeFrom(const void * namelist, 
			      const void * valueList, 
			      void *& badIdList, 
			      int contextId, 
			      const char * userName) const;

  virtual void uncheckedWriteFrom(const void * namelist, 
				  const void * valueList, 
				  int contextId, 
				  const char * userName) const;

  virtual ScsStatus directConvertFrom(const void * nameList, 
				      int contextId, 
				      void *& idList, 
				      void *& valueList, 
				      const char * userName) const;

  virtual ScsStatus directConvertAndReadFrom(const void * nameList, 
					     int contextId, 
					     void *& idList, 
					     void *& valueList, 
					     const char * userName) const;

  virtual ScsStatus directReadFrom(const void * idList, 
				   void *& valueList, 
				   const char * userName) const;

  virtual ScsStatus directWriteFrom(const void * idList, 
				    const void * valueList, 
				    void *& badIdList, 
				    const char * userName) const;

  virtual void uncheckedDirectWriteFrom(const void * idList, 
					const void * valueList, 
					const char * userName) const;

  virtual ScsStatus getAliasFrom(const char * path, 
				 char *& alias, 
				 const char * userName) const;

  virtual ScsStatus getAttributeStructureFrom(const char * address, 
					      short & type, 
					      short & fieldCount, 
					      short & recordCount, 
					      short & recordUsed, 
					      unsigned int & recordSize, 
					      void *& fieldName, 
					      const char * userName) const;

  virtual ScsStatus getFullPathFrom(const char * alias, 
				    char *& path, 
				    const char * userName) const;

  virtual ScsStatus getChildrenFrom(const char * father, 
				    void *& childrenList, 
				    const char * userName) const;

  virtual ScsStatus getChildrenAndAliasesFrom(const char * father, 
					      void *& childrenList, 
					      void *& aliasList, 
					      const char * userName) const;

  virtual ScsStatus getChildrenPropertiesFrom(const char* parent, 
					      void*&      children,
					      void*&      aliases,
					      void*&      modes,
					      const char* userName) const;

  virtual ScsStatus getAttributesFrom(const char * point, 
				      void *& attributeList, 
				      int type, 
				      const char * userName) const;

  virtual ScsStatus getAttributeFormulasFrom(const char * point, 
					     void *& formulas, 
					     void *& evaluationOrders, 
					     void *& activationStates) const;

  virtual ScsStatus setAttributeFormulaFrom(const char * attr, 
					    const char * formula, 
					    char *& errorMsg) const;

  virtual ScsStatus queryByNameFrom(const char * point, 
				    const char * regexp, 
				    void *& adresses) const;

  virtual ScsStatus instanciatePointFrom(const char * className, 
					 const char * location, 
					 const char * name, 
					 const char * alias, 
					 const char * userName) const;

  virtual ScsStatus deletePointFrom(const char * point, 
				    const char * userName) const;

  virtual ScsStatus getCEOperFrom(const void * aliasList, 
				  void *& indicatorList, 
				  const char * userName) const;

  virtual ScsStatus controlCEFrom(const void * aliasList, 
				  const void * controlList, 
				  const char * userName) const;

  virtual ScsStatus setInstanceCEModeFrom(const char* point,
					  bool optimized,
					  const char* userName) const;

  virtual ScsStatus getClassNameFrom(const char * path, 
				     char *& className, 
				     const char * userName) const;

  virtual ScsStatus getClassIdFrom(const char * path, 
				   unsigned short & classId, 
				   const char * userName) const;

  virtual ScsStatus getUserClassIdFrom(const char * path, 
				   unsigned short & classId, 
				   const char * userName) const;

  virtual ScsStatus getClassesFrom(void *& classNames) const;

  virtual ScsStatus getInstancesFrom(const char * className, 
				     const char * subTree, 
				     void *& instances, 
				     const char * userName) const;

   virtual ScsStatus getInstancesByIdFrom(unsigned int classId,  
 					 const char * subTree,  
 					 void *& instances,  
 					 const char * userName) const; 

  virtual ScsStatus getInstancesByUserClassIdFrom(unsigned int classId, 
					 const char * subTree, 
					 void *& instances, 
					 const char * userName) const;

  virtual ScsStatus getAttrInfoFrom(long count, 
				    const void * addresses, 
				    void *& attrInfo) const;

  virtual ScsStatus addClassFrom(const char * name, 
				 long periodiciteST, 
				 long nbHistoST, 
				 long periodiciteMT, 
				 long nbHistoMT) const;

  virtual ScsStatus deleteClassFrom(const char * name) const;

  virtual ScsStatus activateFormulasOfClassFrom(const char * name, 
						int desactive) const;

  virtual ScsStatus addInstanceFrom(const char * className, 
				    const char * path, 
				    char *&  alias) const;

  virtual ScsStatus deleteTreeFrom(const char * path) const;

  virtual ScsStatus activateFormulasOfInstancesFrom(const char * path, 
						    int desactive, 
						    int branch) const;

  virtual ScsStatus copyBranchFrom(const char * fromAddress, 
				   const char * toAddress) const;

  virtual ScsStatus addAttributeFrom(const char * className, 
				     const char * attrName, 
				     int dbmValueType, 
				     int attrType, 
				     int replicated, 
				     int stringLength, 
				     const char * defaultValue) const;

  virtual ScsStatus addVectorAttributeFrom(const char * className, 
					   const char * attrName, 
					   int dbmValueType, 
					   int attrType, 
					   int numRecord, 
					   int replicated, 
					   int stringLength, 
					   const char * defaultValue) const;

  virtual ScsStatus addTableAttributeFrom(const char * className, 
					  const char * attrName, 
					  const void * fieldName, 
					  const void * dbmValueType, 
					  int attrType, 
					  int numRecord, 
					  int numField, 
					  int replicated, 
					  const void * stringLength, 
					  const char * defaultValue) const;

  virtual ScsStatus deleteAttributeFrom(const char * className, 
					const char * attrName) const;

  virtual ScsStatus forceSnapshotFrom(ScsAny       clientSnapshot, 
				      int          type, 
				      const char * path) const;

  virtual ScsStatus readSnapshotFrom(int contextId, 
				     const char * path) const;

  virtual ScsStatus getAttributesDescriptionFrom(const char * className, 
						 void *& attrNames, 
						 void *& dbmValueTypes, 
						 void *& attrTypes, 
						 void *& replicated, 
						 void *& defaultValues) const;

  virtual ScsStatus getClassInfoFrom(const char * className, 
				     char *& classInfo) const;

  virtual ScsStatus getDatabaseInfoFrom(char *& databaseInfo) const;

  virtual ScsStatus checkSyntaxValueFrom(const char * value, 
					 int dbmValueType, 
					 int numChar) const;

  virtual ScsStatus getSymbolicAddressFrom(int addrIdPart1, 
					   int addrIdPart2, 
					   char *& symbolicAddress) const;

  virtual ScsStatus getDirectAddressFrom(int addrIdPart1, 
					 int addrIdPart2, 
					 const char* attributeName,
					 int& resAddrPart1,
					 int& resAddrPart2) const;

  virtual ScsStatus getUserFormulasNamesFrom(void *& formulasNames, 
					     void *& nbArguments) const;

  virtual ScsStatus setContextNameFrom(int id, 
				       const char * name) const;

  virtual ScsStatus getUserContextIdFrom(const char * name, 
					 short & id) const;

  virtual ScsStatus getUserContextNamesFrom(void *& names) const;

  virtual ScsStatus snapshotNonStaticAttributesFrom(ScsAny clientSnapshot, 
						    int contextId, 
						    int synchronous, 
						    ScsAny arg, 
						    const char * path) const;

  virtual ScsStatus snapshotReplicatedAttributesFrom(ScsAny clientSnapshot, 
						     int contextId, 
						     int synchronous, 
						     ScsAny arg, 
						     const char * path) const;

  virtual ScsStatus loadNonStaticAttributesFrom(int contextId, 
						const char * path) const;

  virtual ScsStatus loadReplicatedAttributesFrom(int contextId, 
						 const char * path) const;

  virtual ScsStatus snapshotDatabaseStructureFrom(ScsAny clientSnapshot,
						  int synchronous,
						  ScsAny arg,
						  const char* path) const;
  
  virtual ScsStatus reloadDatabaseStructureFrom(const char* path) const;

  virtual ScsStatus snapshotStaticAttributesFrom(ScsAny clientSnapshot,
						 int synchronous,
						 ScsAny arg,
						 const char* path) const;

  virtual ScsStatus loadStaticAttributesFrom(const char* path) const;

  virtual ScsStatus duplicateContextFrom(int destContextId, 
					 int sourceContextId) const;

  virtual ScsStatus markAttributesForLstServerFrom(const ScsAny addrIdList) const;

  virtual ScsStatus unmarkAttributesForLstServerFrom(const ScsAny addrIdList) const;

  virtual ScsStatus changeAttrTypeFrom(const char* pClassName, const char* pAttrName, short pNewType) const;
  virtual ScsStatus changeAttrTypeFrom(const ScsAny addrIdList, short pNewType) const;

  inline DbmWriterProxy* getWriterProxy(){return _writerProxy;}

protected:

  DbmReaderProxy                * _readerProxy;
  DbmWriterProxy                * _writerProxy;
  DbmConfigProxy                * _configProxy;
  ScsStatus                       _readerProxyStatus;
  ScsStatus                       _writerProxyStatus;
  ScsStatus                       _configProxyStatus;
  char                          * _userName;
  char	     	  	          _localConnection;
  DbkAccess                     * _kernelAccess;
  DbmDatabaseInfo::DatabaseType   _databaseUsed;
  DbmClientSnapshotCallback_i   * _clientSnapshotCallback;
  DbmHisCallbackProxy           * _callbackProxy;

  DbmHisManager*		_hisManager;

  public :

  DbmHisCallback_i *_callback;
};


class DbmPollerProxy;

/**
   \brief This class is one of the interface classes for the exported services of the <em>DBM</em> component (DataBase Manager): it allows to poll the database.

   This class is the interface class for the services exported by the DbmPoller. It is used to subscribe to database point attributes and to be notified about the value changes of these attributess. 
\code#include "dbm.h"\endcode
*/
class DBM_API DbmPoller
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the database poller (DbmPoller).
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required DbmPoller is running.
     \param serverName  [in]: name of the server (the use of the default name is recommended).
     \param priority  [in]: priority of the messages to the DbmPoller (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  DbmPoller(const char *logicalEnv = 0,
	    const char *serverName = "DbmPoller",
	    ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);

  /**
     \par Description:
     destructor. This function closes the connection with the DbmPoller.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~DbmPoller();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the DbmPoller.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c DbmHostServerError : cannot connect with the ascmanager process.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
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
     create a new polling group. The DbmDataSet contains the name of the group and all the point attributes composing the group (each attribute is described in a <em>DbmData</em> object using an <em>ScsAddress</em>). If the description of the group is not correct, the group is not created.
     When a polling group is created, its decription is saved by the <em>dbmpoller</em> process into a file under the <em>$SCSPATH/Database/DbmPoller/groups</em> directory. <b>WARNING:</b> when this server is started, it automatically creates the polling groups corresponding to the description files found in the above directory.
     \param dataSet  [in]: the dataset containing the name of the group and the description of the point attributes.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is not valid.
     \li \c DbmGroupDescriptionError : the description of the group is not valid.
     \li \c DbmGroupAlreadyExistError : the specified group already exist.
     \li \c DbmFileCreationError : the file corresponding to the group description could not be created on disk. 
     \li \c DbmProfileNotFoundError : no profile was found for the specified user on the security server.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus createGroup(const DbmDataSet &dataSet);

  /**
     \par Description:
     Same as <em>createGroup()</em> but creates the polling group even if some addresses in the dataset are invalid.
  */
  ScsStatus createGroupAnyway(DbmDataSet &dataSet);

  /**
     \par Description:
     delete a polling group.
     \param groupName  [in]: the group name.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is not valid.
     \li \c DbmGroupDeletionError : the group could not be removed, there is still some subscriptions on it.
     \li \c DbmFileDeletionError : the corresponding file could not be removed from disk.
     \li \c DbmProfileNotFoundError : no profile was found for the specified user on the security server.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus deleteGroup(const char *groupName);

  /**
     \par Description:
     test the creation of a group.
     \param groupName  [in]: name of the group.
     \param result  [out]: result of the test, set to 1 if the group is already created, 0 otherwise.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is not valid.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus isGroupCreated(const char *groupName, unsigned short &result);

  /**
     \par Description:
     subscribe to a polling group. The client is notified of any modification of points of the group through the <em>updateCallback</em> function specified in the <em>dataSet</em> parameter. It receives the current value of all the group point attributes at first expiration of the notification period (through the notification callback) and then, at each expiration of the period, the changes which occurred since the last notification. The subscriptions are grouped by notification period value: when several clients are subscribed to the same group with the same notification period, they are all successively notified at each expiration of the period. They share the values of the group points. For several subscriptions with the same period value, the period expiration cycle is started by the first subscription request with the given period value.
     \param dataSet  [in]: dataset containing the info for the subscription, i.e. the group name, the notification period and the address of the notification callback function.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is unknown from the poller.
     \li \c DbmFileNotFoundError : the group was not created using the <em>createGroup()</em> function and no corresponding file containing the description of the group was found in the directory specified at starting of the DbmPoller process.
     \li \c DbmGroupSubscriptionError : the subscription has not been taken into account.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus subscribe(const DbmDataSet &dataSet);

  /**
     \par Description:
     subscribe to multiple polling groups. The client is notified through the <em>updateCallback</em> function specified in the <em>dataSet</em> parameter. It receives the current value of all the groups point attributes at first expiration of the notification callback (through the notification callback) and then, at each expiration of the period, the changes which occurred since the last notification. The subscriptions are grouped by notification period value: when several clients are subscribed to the same group with the same notification period, they are all successively notified at each expiration of the period. They share the values of the group points. For several subscriptions with the same period value, the period expiration cycle is started by the first subscription request with the given period value. If the info of one group are not correct, the subscription for this group is not taken into account.
     \param dataSet  [in]: list of dataset containing the info for the subscriptions, i.e. the group name, the notification period and the address of the notification callback function.
     \param count  [in]: number of dataset.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : at least one group name is unknown from the poller.
     \li \c DbmFileNotFoundError : one group was not created using the <em>createGroup()</em> function and no corresponding file containing the description of the group was found in the directory specified at starting of the DbmPoller process.
     \li \c DbmGroupSubscriptionError : one subscription has not been taken into account.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus subscribeMultiGroups(const DbmDataSet *dataSet, unsigned short count);

  /**
     \par Description:
     create, subscribe and read groups then receive the current database values in the <em>pollDataSet</em> parameter. The client is notified of any modification of points of the group through the <em>updateCallback()</em> function specified in the <em>pollDataSet</em>.
     \param pollDataSet  [in]: dataset containing in input the info for the subscription, i.e. the group name, the notification period and the address of the notification callback function, and in output the current values. It receives, at each expiration of the notification period, the changes which occurred since the last notification. The subscriptions are grouped by notification period value: when several clients are subscribed to the same group with the same notification period, they are all successively notified at each expiration of the period. They share the values of the group points. For several subscriptions with the same period value, the period expiration cycle is started by the first subscription request with the given period value.
     \param readDataSet  [in]: dataset containing in input the info to read in database, i.e. the group name and the address of the notification callback function, and in output the current values.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is unknown from the poller.
     \li \c DbmFileNotFoundError : the group was not created using the <em>createGroup()</em> function and no corresponding file containing the description of the group was found in the directory specified at starting of the DbmPoller process.
     \li \c DbmGroupSubscriptionError : the subscription has not been taken into account.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus createGroupSubscribeAndUpdate(DbmDataSet &pollDataSet, DbmDataSet &readDataSet);

  /**
     \par Description:
     subscribe and read groups then receive the current database values in the <em>dataSet</em> parameter. The client is notified of any modification of points of the group through the <em>updateCallback()</em> function specified in the <em>dataSet</em>.
     \param dataSet  [in]: dataset containing in input the info for the subscription, i.e. the group name, the notification period and the address of the notification callback function, and in output the current values. It receives, at each expiration of the notification period, the changes which occurred since the last notification. The subscriptions are grouped by notification period value: when several clients are subscribed to the same group with the same notification period, they are all successively notified at each expiration of the period. They share the values of the group points. For several subscriptions with the same period value, the period expiration cycle is started by the first subscription request with the given period value.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is unknown from the poller.
     \li \c DbmFileNotFoundError : the group was not created using the <em>createGroup()</em> function and no corresponding file containing the description of the group was found in the directory specified at starting of the DbmPoller process.
     \li \c DbmGroupSubscriptionError : the subscription has not been taken into account.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus readSubscribeAndUpdate(DbmDataSet &dataSet);
 
  /**
     \par Description:
     subscribe to a polling group and receive the current database values in the <em>dataSet</em> parameter. The client is notified of any modification of points of the group through the <em>updateCallback</em> function specified in the <em>dataSet</em>.
     \li \c dataSet  [in]: dataset containing in input the info for the subscription, i.e. the group name, the notification period and the address of the notification callback function, and in output the current values. It receives, at each expiration of the notification period, the changes which occurred since the last notification. The subscriptions are grouped by notification period value: when several clients are subscribed to the same group with the same notification period, they are all successively notified at each expiration of the period. They share the values of the group points. For several subscriptions with the same period value, the period expiration cycle is started by the first subscription request with the given period value.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is unknown from the poller.
     \li \c DbmFileNotFoundError : the group was not created using the <em>createGroup()</em> function and no corresponding file containing the description of the group was found in the directory specified at starting of the DbmPoller process.
     \li \c DbmGroupSubscriptionError : the subscription has not been taken into account.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus subscribeAndUpdate(DbmDataSet &dataSet);

  /**
     \par Description:
     get all subscribers to one group or several groups
     \li \c groupName  [in]: name of the group on which we want the subscribers.
     \li \c groupList  [in]: list of groups names when all subscribers are asked.
     \li \c countlist  [in]: list of clients count for each group.
     \li \c clientlist  [in]: list of all clients.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is unknown from the poller.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus getSubscriber(char           *groupName,
			  DbmStringList *&groupList,
			  DbmCountList  *&countList,
			  DbmStringList *&clientList);

  /**
     \par Description:
     cancel a subscription on a polling group. The client is notified that the cancellation has effectively occurred through the <em>cancelCallback</em> function given at subscription time (if any).
     \li \c groupName  [in]: the group name.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is unknown from the DbmPoller.
     \li \c DbmSubscriptionNotFoundError : no subscription on the specified group was found for the current client.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus unsubscribe(const char *groupName);

  /**
     \par Description:
     for a group with a long polling period, force an update so the client does not have to wait until the next expiration of the polling period. A call to this method does not change the time when the next periodic polling occurs. The client is notified through the <em>updateCallback</em> function given at subscription in the <em>dataSet</em> parameter.
     \li \c groupName  [in]: the group name.
     \return
     \li \c ScsValid : success.
     \li \c DbmGroupUnknownError : the name of the group is unknown from the DbmPoller.
     \li \c DbmSubscriptionNotFoundError : no subscription on the specified group was found for the current client.
     \li \c DbmORBError : cannot connect with the remote DbmPoller.
  */
  ScsStatus forceSubscriptionUpdate(const char *groupName) const;
  //@}

private:
  ScsStatus       _status;
  DbmClient_i    *_client;
  DbmPollerProxy *_proxy;
  char           *_userName;
  ScsString      *_envName;
};

/**
   \par Description:
     Prototype of the event callback function.
   \param addressId  [in]: addressId of the point where the formula SEND_EVENT is applied,
   \param scsAddress [in]: scsAddress of the point,
   \param msg  [in]: parameter message of the formula SEND_EVENT,
   \param serverName [in]: name of the server,
   \param arg  [in]: optional user argument passed as parameter of the <em>registerEventCallback()</em> method and returned back to the callback function when called.
   \par Return values:
     none.
*/
typedef ScsStatus (*EventCallback)(DbkAddressId addressId,
				   const ScsAddress& scsAddress, 
				   const char *msg, 
				   const char* serverName,
				   ScsAny arg);

/**
     \par Description:
     this function registers the user routine function to be called by the <em>AscServer</em> when an event occurs.
     \li \c ptrAscServer  [in]: denotes the AscServer used for callback registration
     \li \c ptrClient  [in]: unused
     \li \c eventCallback  [in]: event callback function,
     \li \c arg  [in]: optional user argument returned back to the event callback function when called.
     \return
     \li \c ScsValid : success.
*/
ScsStatus registerEventCallback(AscServer* ptrAscServer, void* ptrClient, EventCallback eventCallback, ScsAny arg);



#endif
