//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : lst.h                                                  */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : C. LAYES                                               */
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : 10/15/2001                                             */
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
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $

#ifndef _SCS_LST_H_
#define _SCS_LST_H_

/**
  \file
  \brief Access to the LstServer component
*/

#include "scs.h"
#include "scsdefs.h"

// Definition of LST module trace function
#define LstTrace	ScsTraceFunction(LST_SCSMODULE)
#define LstTraceLevel(level, message)  BaseTraceLevel(LST_SCSMODULE, level, message)

// trace levels
#define CRITICAL_LEVEL			SCS_LEVEL(0)
#define LAUNCH_LEVEL			SCS_LEVEL(1)
#define UPDATE_LEVEL			SCS_LEVEL(2)
#define GARBAGE_LEVEL   		SCS_LEVEL(3)
#define CRITERIA_LEVEL  		SCS_LEVEL(4)
#define WARNING_LEVEL			SCS_LEVEL(5)
#define XML_LEVEL			SCS_LEVEL(6)
#define SNAPSHOT_LEVEL			SCS_LEVEL(7)
#define PERF_LEVEL			SCS_LEVEL(8)
#define NOTIFIER_LEVEL                  SCS_LEVEL(9)
#define CLIENT_LEVEL			SCS_LEVEL(12)

// Request Id max (can't be < 1)
#define REQUEST_ID_MAX 1024

class AscManager;
class LstServerProxy;
class OlsDataIndex;
class LstDbmStateListCreationCallback_i;


struct LstListInfo
{
  char* name;
  char* description;
  char* type;
  char* creationMode;
  unsigned short creatorId;
};

struct LstListInfos
{
  struct LstListInfo info;
  struct LstListInfos* next;
};

/**
   Prototype of the callback function called at the end of a StateList creation job.

\code#include "dbm.h"\endcode
   \param listName  [in]: name of the list,
   \param creatorId [in]: id of the list creator,
   \param status [in]: operation status,
   \param arg  [in]: optional user argument passed as parameter of the <em>createStateListWithNotification()</em> method and returned back to the callback function when called.
   \par Return values:
     none.
*/

typedef void (*LstDbmStateListCreationCallback)(const char* listName,
						const unsigned short creatorId,
						int status,
						ScsAny arg);


struct LstCallbackInfos
{
  int requestId;
  void* arg;
  LstDbmStateListCreationCallback callback; 
};


/**
   \brief This class is the interface class of services exported by the list server.

\code#include "lst.h"\endcode
*/
class LST_API LstServer
{
public:
  /******************************************************************************/
  /* General LstServer Methods                                                  */
  /******************************************************************************/
  
  /**@name Constructors / Destructor*/
  //@{
  /**
     \par Description:
     Constructor. This method creates a connection with the list server.
     \param environment  [in]: The Scadasoft environment where the LstServer program resideson.
     \param name  [in]: The name of the LstServer process.
     \param priority  [in]: priority of the messages to the LstServer (only useful with redudancy).
     \par Return values:
     None. The result of the connection
     can be obtained by calling the <em>getStatus()</em> method.
  */
  LstServer(const char* environment = 0,
	    const char* name = "LstServer",
	    ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);
  
  /**
     \par Description:
     Destructor.  This method closes the connection with the list server.
     \par Parameters:
     None.
     \par Return values:
     None.
  */
  ~LstServer();

  //@}

  /**@name General LstServer methods*/
  //@{

  /**
     \par Description:
     Return the status of the connection to the list server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid: Success.
     \li \c LstHostServerError: Cannot connect with the list server process.
     \li \c LstORBError: Cannot connect with the remote list server process.
  */
  ScsStatus getStatus() const { return _status;}

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
  
  //@}

/******************************************************************************/
/* General List Methods                                                  */
/******************************************************************************/

  /**@name General list methods*/
  //@{

  /**
     \par Description:
     Activate the specified list.
     \param listName [in]: The name of the list to activate.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: Impossible to find the list.
  */
  ScsStatus activate(const char* listName);

  /**
     \par Description:
     Deactivate the specified list.
     \param listName [in]: The name of the list to deactivate.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: Impossible to find the list.
  */
  ScsStatus deactivate(const char* listName);

  /**
     \par Description:
     Asks if a list is activated or not.
     \param listName [in]: The name of the list to be asked about.
     \param activated [out]: The result of the question &quot;is the list <em>listName</em> activated?&quot;. If it is worth 0, the list is not activated, otherwise the list is activated.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: Impossible to find the list.
  */
  ScsStatus isActivated(const char* listName, int& activated);

  /**
     \par Description:
     Asks the percentage of a list creation job carried out.
     \param listName [in]: The name of the list to be asked about.
     \param percentage [out]: The percentage of a list creation job carried out.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: Impossible to find the list.
  */
  ScsStatus getListCreationPercentage(const char* listName, int& percentage) const;

  /**
     \par Description:
     List all the lists contained in a LstServer,
     that includes the state lists AND the user lists.
     The structure returned has several values for each list: name, type, mode, creator identificator...
     \param lists [out]: The structure array where where infos are stored in.
     \param listNumber [out]: The number of structures in the array.
     \return
     \li \c ScsValid: Success.
     \li \c LstError: There is a problem.
  */
  ScsStatus listLists(LstListInfos*& lists, int& listNumber) const;

  /**
     \par Description:
     Get information about a list.
     \param listName [in]: The name of the wished list.
     \param info [out]:
     \return
     \li \c ScsValid: Success.
     \li \c LstError: There is a problem.
  */
  ScsStatus getInfo(const char* listName, LstListInfo*& info) const;
  
  /**
     \par Description:
     Get the creator identification number of a list.
     \param listName [in]: The name of the wished list.
     \param creatorId [out]: The creator identification number of the list.
     \return
     \li \c ScsValid: Success.
     \li \c LstError: There is a problem.
  */
  ScsStatus getCreator(const char* listName, unsigned short& creatorId) const;
  
  /**
     \par Description:
     Get the description of a list.
     \param listName [in]: The name of the wished list.
     \param description [out]: The description of the list.
     \return
     \li \c ScsValid: Success.
     \li \c LstError: There is a problem.
  */
  ScsStatus getDescription(const char* listName, char*& description) const;

  /**
     \par Description:
     Set the description of a list.
     \param listName [in]: The name of the wished list.
     \param creatorId [in]: The identificator of the list creator.
     \param description [in]: The description of the list.
     \return
     \li \c ScsValid: Success.
     \li \c LstError: There is a problem.
  */
  ScsStatus setDescription(const char* listName, const unsigned short creatorId,
			   const char* description);

  /**
     \par Description:
     Get the mode of a list.
     \param listName [in]: The name of the wished list.
     \param mode [out]: The mode of the list.
     \return
     \li \c ScsValid: Success.
     \li \c LstError: There is a problem.
  */
  ScsStatus getMode(const char* listName, int& mode) const;

  /**
     \par Description:
     Save the desired list.
     \param listName [in]: The name of the list to save.
     \param creatorId [out]: The indentificator of the list creator.
     \return
     \li \c ScsValid: Success.
     \li \c LstSaveError: There is a problem.
  */
  ScsStatus save(const char* listName, const unsigned short creatorId);

  //@}

  /******************************************************************************/
  /* State List Control Methods                                                 */
  /******************************************************************************/

  /**@name State list control methods*/
  //@{
  
  /**
     \par Description:
     Create a new state list in the list server.
     \param listName [in]: The name of the state list to create.
     \param creatorId [in]: The identification number of the list creator.
     \param description [in]: The description of the list.
     \param attributes [in]: The list of the concerned attribute names.
     \param attributeNumber [in]: The number of attribute names in the list <em>attributes</em>.
     \param conditionClause [in]: The condition the attributes must verified.
     \param comment [in]: A text which can be associated with the state list.
     \return
     \li \c ScsValid: Success.
     \li \c LstCreatorIdError: The creator identificator given is not valid (< 1).
     \li \c LstNameAlreadyExistsError: The List name already exists.
     \li \c LstListNameError: The list name is not valid [a-zA-z0-9]+.
     \li \c LstMaxListError: The maximum number of list in a server has been reached.

     \li \c LstClassError: Cannot find the impacted class in database.
     \li \c LstAttributeError: Cannot find one of the attributes in database.
     \li \c LstConditionFormError: The condition specified is not well written.
     \li \c LstConditionAttrError: One of the condition attributes can't be found.
  */
  ScsStatus createStateList(const char* listName,
			    const unsigned short creatorId,
			    const char* description,
			    const char* attributes[],
			    const int attributeNumber,
			    const char* conditionClause,
			    const char* comment);


  /**
     \par Description:
     Create a new state list in the list server, with a notification a the end of the job.
     \param listName [in]: The name of the state list to create.
     \param creatorId [in]: The identification number of the list creator.
     \param description [in]: The description of the list.
     \param attributes [in]: The list of the concerned attribute names.
     \param attributeNumber [in]: The number of attribute names in the list <em>attributes</em>.
     \param conditionClause [in]: The condition the attributes must verified.
     \param comment [in]: A text which can be associated with the state list.
     \param notificationCB [in]: The function reference to be called at the end of the creation job.
     \param arg [in]: parameters of the callback function.
     \return
     \li \c ScsValid: Success.
     \li \c LstCreatorIdError: The creator identificator given is not valid (< 1).
     \li \c LstNameAlreadyExistsError: The List name already exists.
     \li \c LstListNameError: The list name is not valid [a-zA-z0-9]+.
     \li \c LstMaxListError: The maximum number of list in a server has been reached.

     \li \c LstClassError: Cannot find the impacted class in database.
     \li \c LstAttributeError: Cannot find one of the attributes in database.
     \li \c LstConditionFormError: The condition specified is not well written.
     \li \c LstConditionAttrError: One of the condition attributes can't be found.
  */
  ScsStatus createStateListWithNotification(const char* listName,
					    const unsigned short creatorId,
					    const char* description,
					    const char* attributes[],
					    const int attributeNumber,
					    const char* conditionClause,
					    const char* comment,
					    LstDbmStateListCreationCallback notificationCB,
					    void* arg);

  /**
     \par Description:
     Create a multi state list.
     \param listName [in]: The name of the multi state list to create.
     \param creatorId [in]: The identification number of the list creator.
     \param description [in]: The description of the list.
     \param attributes [in]: The list of lists of concerned attributes names for each query.
     \param attributeNumbers [in]: The list of attribute name numbers for each entries in <em>attributes</em>.
     \param conditionClauses [in]: The list of conditions of each query.
     \param comment [in]: The list of comments for each query.
     \param columnNames [in]: The list of column names
     \param queryNumber [in]: The number of queries given to create the multi state list.
     \return
     \li \c ScsValid: Success.
     \li \c LstCreatorIdError: The creator identificator given is not valid (< 1).
     \li \c LstNameAlreadyExistsError: The List name already exists.
     \li \c LstListNameError: The list name is not valid [a-zA-z0-9]+.
     \li \c LstMaxListError: The maximum number of list in a server has been reached.
     \li \c LstError: There is a problem.
  */
  ScsStatus createMultiStateList(const char* listName,
				 const unsigned short creatorId,
				 const char* description,
				 const char** attributes[],
				 const int attributeNumbers[],
				 const char* conditionClauses[],
				 const char* comment,
				 const char* columnNames[],
				 const int queryNumber);

  /**
     \par Description:
     Create a multi state list, with a notification at the end of the job.
     \param listName [in]: The name of the multi state list to create.
     \param creatorId [in]: The identification number of the list creator.
     \param description [in]: The description of the list.
     \param attributes [in]: The list of lists of concerned attributes names for each query.
     \param attributeNumbers [in]: The list of attribute name numbers for each entries in <em>attributes</em>.
     \param conditionClauses [in]: The list of conditions of each query.
     \param comment [in]: The list of comments for each query.
     \param columnNames [in]: The list of column names
     \param queryNumber [in]: The number of queries given to create the multi state list.
     \param notificationCB [in]: The function reference to be called at the end of the creation job.
     \param arg [in]: parameters of the callback function.
     \return
     \li \c ScsValid: Success.
     \li \c LstCreatorIdError: The creator identificator given is not valid (< 1).
     \li \c LstNameAlreadyExistsError: The List name already exists.
     \li \c LstListNameError: The list name is not valid [a-zA-z0-9]+.
     \li \c LstMaxListError: The maximum number of list in a server has been reached.

     \li \c LstError: There is a problem.
  */
  ScsStatus createMultiStateListWithNotification(const char* listName,
						 const unsigned short creatorId,
						 const char* description,
						 const char** attributes[],
						 const int attributeNumbers[],
						 const char* conditionClauses[],
						 const char* comment,
						 const char* columnNames[],
						 const int queryNumber,
						 LstDbmStateListCreationCallback notificationCB,
						 void* arg);
  
  /**
     \par Description:
     Dynamically create an operator UserList or StateList from a Xml file.
     \param fileName [in]: The XML file name to load (must have .xml as its extension).
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: The list to modify has not been found in the list server.
     \li \c LstListNotModifiableError: The list to modify cannot be modified because of its creation mode.
     \li \c LstConditionFormError: The condition specified is not well written.
     \li \c LstConditionAttrError: One of the condition attributes can't be found.
  */
  ScsStatus createListFromXmlFile(const char* fileName);

  /**
     \par Description:
     Modify the condition of an existing state list.
     \param listName [in]: The name of the state list to modify.
     \param creatorId [in]: The identification number of the list creator.
     \param newConditionClause [in]: The condition which will replace the old one.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: The list to modify has not been found in the list server.
     \li \c LstListNotModifiableError: The list to modify cannot be modified because of its creation mode.
     \li \c LstConditionFormError: The condition specified is not well written.
     \li \c LstConditionAttrError: One of the condition attributes can't be found.
  */
  ScsStatus modifyStateListCondition(const char* listName,
				     const unsigned short creatorId,
				     const char* newConditionClause);

  /**
     \par Description:
     Modify an existent state list in the list server.
     \param listName [in]: The name of the state list to be modified.
     \param creatorId [in]: The identification number of the list creator.
     \param description [in]: The description of the list.
     \param attributes [in]: The list of the concerned attribute names.
     \param attributeNumber [in]: The number of attribute names in the <em>attributes</em> list .
     \param conditionClause [in]: The condition the attributes must verified.
     \param comment [in]: A text which is associated with the state list (the human readable query for example).
     \return
     \li \c ScsValid: Success.
     \li \c LstNameError: List name already exists.
     \li \c LstClassError: Cannot find the impacted class in database.
     \li \c LstAttributeError: Cannot find one of the attributes in database.
     \li \c LstConditionFormError: The condition specified is not well written.
     \li \c LstConditionAttrError: One of the condition attributes can't be found.
  */
  ScsStatus modifyStateList(const char* listName,
			    const unsigned short creatorId,
			    const char* description,
			    const char* attributes[],
			    const int attributeNumber,
			    const char* conditionClause,
			    const char* comment);

  /**
     \par Description:
     Delete a state list.
     \param listName [in]: The name of the state list to delete.
     \param creatorId [in]: The identification number of the list creator.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: The list to delete has not been found in the list server.
     \li \c LstListNotDeletableError: The list to delete cannot be deleted because of its creation mode.
  */
  ScsStatus deleteStateList(const char* listName,
			    const unsigned short creatorId);

  /**
     \par Description:
     Get the comment of a state list.
     \param listName [in]: The name of the wished state list.
     \param comment [out]: The comment of the state list.
     \return
     \li \c ScsValid : Success.
     \li \c LstListTypeError: The wished list is not a state list.
  */
  ScsStatus getComment(const char* listName, char*& comment) const;

  //@}

  /******************************************************************************/
  /* User List Control Methods                                                  */
  /******************************************************************************/

  /**@name User list control methods*/
  //@{
 
  /**
     \par Description:
     Create a new empty user list.
     \param listName [in]: The name of the user list to create.
     \param creatorId [in]: The identification number of the list creator.
     \param description [in]: The description of the list.
     \return
     \li \c ScsValid: Success.
     \li \c LstError: The user list has not been created.
  */
  ScsStatus createUserList(const char* listName,
			   const unsigned short creatorId,
			   const char* description);

  /**
     \par Description:
     Add an entry in a LstServer user list.
     \param listName [in]: The name of the user list where to add the new entry.
     \param  creatorId [in]: The identification number of the list creator.
     \param index [out]: The index of the data added.
     \param addresses [in]: The list of attribute addresses where to find each value of the new data.
     \param addressNumber [in]: The number of entries in <em>addresses</em>.
     \return
     \li \c ScsValid: Success.
     \li \c LstUserListAddEntryError: User List new entry not added.
  */
  ScsStatus addUserListEntry(const char* listName,
			     const unsigned short creatorId,
			     int& index,
			     const char* addresses[],
			     const int addressNumber);

  /**
     \par Description:
     None.
     \param listName [in]: The name of the list where to delete an entry.
     \param creatorId [in]: The identification number of the list creator.
     \param index [in]: The index of the data to delete.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: The list where to delete an entry has not been found in the list server.
     \li \c LstUserListEntryNotFoundError: The entry specified has not been found in the user list.
  */
  ScsStatus deleteUserListEntry(const char* listName,
				const unsigned short creatorId,
				const int index);

  /**
     \par Description:
     None.
     \param listName [in]: The name of the list where to delete entries.
     \param creatorId [in]: The identification number of the list creator.
     \param addresses [in]: Array of database addresses. All entries holding at least one of these addresses will be deleted.
     \param addressNumber [in]: The number of entries in <em>addresses</em>.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: The list where to delete an entry has not been found in the list server.
  */
  ScsStatus deleteUserListEntries(const char* listName,
				  const unsigned short creatorId,
				  const char*addresses[],
				  const int addressNumber);
  
  /**
     \par Description:
     Delete a user list.
     \param listName [in]: The name of the user list to delete.
     \param creatorId [in]: The identification number of the list creator.
     \return
     \li \c ScsValid: Success.
     \li \c LstListNotFoundError: The list to delete has not been found in the list server.
     \li \c LstListNotModifiableError: The list to delete cannot be deleted because of its creation mode.
  */
  ScsStatus deleteUserList(const char* listName,
			   const unsigned short creatorId);

  //@}

protected:

private:
  int     _requestId;
  LstServerProxy* _proxy;
  ScsStatus       _status;
  char*           _userName;

  LstDbmStateListCreationCallback_i* _orbClient;
};

#endif
