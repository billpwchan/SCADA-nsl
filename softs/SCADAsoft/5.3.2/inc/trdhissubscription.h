//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : trdhissubscription.h                                   */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon May 05 16:43:32 2003                               */
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


#ifndef _TRDHISSUBSCRPTION_H_
#define _TRDHISSUBSCRPTION_H_

/** \file
    \brief Management of archives of the Trend server (TRD)
*/

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif


#include "trddataset.h"

class TrdSubscriberList;


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
class TrdSubscriber
{
 public:

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.  This function creates an interface object connected to the HIS server named <em>serverName</em> and running in logical environment <em>logicalEnv</em>.
     \param trdSubscriptionId  [in]: 
     \param archive  [in]: 
     \param attr  [in]: 
     \par Return values:
     none.
  */
  TrdSubscriber (int trdSubscriptionId, const char* archive = NULL, const char* attr = NULL);
  /**
     \par Description:
     destructor.  This function closes the connection
     with the HisServer.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~TrdSubscriber();
  //@}
  
  const char* getAttributeName () { return _attributeName; }
  const char* getArchiveName () { return _archiveName; }
  unsigned long  getLastTime() { return _lastTime; }
  void setLastTime(unsigned long lastTime) { _lastTime = lastTime; }

  int getId() const { return _trdSubscriptionId;};

  friend SCS_SL_STD(ostream)& operator <<(SCS_SL_STD(ostream)& ostr, TrdSubscriber& trdSubscriber);

 private:
  int _trdSubscriptionId;
  char* _archiveName;
  char* _attributeName;
  unsigned long _lastTime;
};


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
class TrdHisSubscription
{
 public:


  typedef enum TRD_ACTION_TYPE {
    TRD_NEW_SUBSCRIPTION = 0,
    TRD_UPDATE_SUBSCRIPTION,
    TRD_NOTHING_TODO
  } TRD_ACTION_TYPE;

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.  This function creates an interface object connected to the HIS server named <em>serverName</em> and running in logical environment <em>logicalEnv</em>.
     \param archiveName [in]: 
     \param attributeName [in]: 
     \param period [in]: 
     \param subscriptionId [in]: 
     \param oldSubscriptionId [in]: 
     \param trdSubscriptionId [in]:
     \param arg [in]:
     \par Return values:
     none.
  */
  TrdHisSubscription (const char* archiveName,
		      const char* attributeName,
		      int         period,
		      int         subscriptionId,
		      int         oldSubscriptionId,
		      int         trdSubscriptionId,
		      ScsAny      arg);
  ~TrdHisSubscription ();
  //@}
  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     this function returns the subscription
     identifier.
     \par Parameters:
     none.
     \par Return values:
     the subscription identifier.
  */
  const char*        getArchiveName();

  int                getActionToDo () const { return _actionToDo;};
  void               setActionToDo (int actionToDo ) { _actionToDo = actionToDo;};

  int                getSubscriptionId () const { return _subscriptionId;};
  void               setSubscriptionId (int id ) { _subscriptionId = id;};


  int                attributeCount(const char* attributeName);

  int                getOldSubscriptionId () const { return _oldSubscriptionId;};
  void               setOldSubscriptionId (int id) { _oldSubscriptionId = id;};

  TrdDataSetList*    getDataSetList () const { return _dataSetList; };
  TrdDataSet*        getDataSet () const { return _dataSet; };

  int                getPeriod () const { return _period;};

  int                hasSubscriber (int id);
  TrdSubscriber*     getFirstSubscriber ();
  int                removeSubscriber (int id);
  int                append(TrdSubscriber* sub);
  void               moveSubscribers(TrdHisSubscription* oldHisSubscription);

  void               forward(TrdDataSetListList& subscriptions, TrdDataSetList& newData);
  OlsFilter*         getFilter() { return _filter; }
  void               setFilter(OlsFilter* filter) { _filter = filter; }

  friend SCS_SL_STD(ostream)& operator <<(SCS_SL_STD(ostream)& ostr, TrdHisSubscription& hisSupscrition);
  //@}

 private:

  int                _subscriptionId;    // Associated HisServer subscription id
  int                _oldSubscriptionId; // Id of the subscription that this one
  // is to replace
  int                _period;            // Period for subscription and time for
  // which data is to be retained in dataset
  TrdDataSet*        _dataSet;
  TrdDataSetList*    _dataSetList;
  TrdSubscriberList* _subscriberList;
  OlsFilter*         _filter;
  int                _actionToDo;
  ScsString*         _archiveName;
};


#endif
