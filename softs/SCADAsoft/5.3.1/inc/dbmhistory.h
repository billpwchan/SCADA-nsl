//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : dbmhistory.h                                           */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Fri Mar 21 17:53:27 2003                               */
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


#ifndef _SCS_DBMHISTORY_H_
#define _SCS_DBMHISTORY_H_

/**
   \file
   \brief Callback typedefs related to the History server for DBM access.
*/

class DBM_API DbmHisData : public ScsData
{
 public:
  DbmHisData ();
  DbmHisData (const ScsData& data, unsigned long time);
  DbmHisData (const DbmHisData& dbmhisdata);
  ~DbmHisData ();

  unsigned long getTime() const {return _time;} ; 

  friend DBM_API bool operator<(const DbmHisData& data1, 
			 const DbmHisData& data2);
  friend DBM_API bool operator==(const DbmHisData& data1, 
			  const DbmHisData& data2);
  
  void save(SCS_SL_STD(ostream)& os) const;
  void restore(SCS_SL_STD(istream)& is);
  
 private:
  unsigned long _time;
};

class DbmHisDataRWGSlist;

class DBM_API DbkHisAddressId 
{
 public:
  DbkHisAddressId ();
  DbkHisAddressId (DbkAddressId * inDbkAddressId);
  DbkHisAddressId (const DbkHisAddressId& inDbkHisAddressId);
  virtual ~DbkHisAddressId ();
    
  void setDbkAddressId(DbkAddressId * inDbkAddressId);

  int getCount() const;
  const DbkAddressId * getDbkAddressId() const
    { return _dbkAddress; }

  ScsStatus add(DbmHisData* inDbmHisData);
  ScsStatus remove(DbmHisData* inDbmHisData);
  DbmHisData* at (const int index) const;
  DbmHisDataRWGSlist* getDataList () const { return _dataList;};
  void clear ();

  void save(SCS_SL_STD(ostream)& os) const;
  void restore(SCS_SL_STD(istream)& is);
    
  //-- operator= over definition
  DbkHisAddressId& operator= (const DbkHisAddressId& inDbkHisAddressId);

 private:
  // DbkAddressId pointeur
  DbkAddressId *         _dbkAddress;
  //Listes de valeur du DbkAddressId entre les 2 dates entrées
  DbmHisDataRWGSlist*    _dataList;  
};

class DbkHisAddressIdRWGSlist;
class DbkHisAddressIdRWGSlistIterator;

class DBM_API DbmHisAddressDataSet
{
  friend class DbmHisAddressDataSetIt;
 private:
  int                      _type;
  unsigned long            _startTime;
  unsigned long            _endTime;
  DbkHisAddressIdRWGSlist* _dbkaddressIdList;

 public:
  DbmHisAddressDataSet();
  DbmHisAddressDataSet(int type,unsigned long startTime, unsigned long endTime);
  DbmHisAddressDataSet(const DbmHisAddressDataSet& inDbmHisAddressDataSet);
  ~DbmHisAddressDataSet();

  int getType();
  unsigned long getStartTime();
  unsigned long getEndTime();
  int getCount() const;

  void setStartTime(unsigned long);
  void setEndTime(unsigned long);  

  ScsStatus add(DbkHisAddressId*);
  ScsStatus remove(DbkHisAddressId*);
  DbkHisAddressId* at(int pos) const;
  void clear ();

  void save(SCS_SL_STD(ostream)& os) const;
  void restore(SCS_SL_STD(istream)& is);

  //-- operator= over definition
  DbmHisAddressDataSet& operator= (const DbmHisAddressDataSet& inDbmHisAddressDataSet);
};

class DBM_API DbmHisAddressDataSetIt
{
  DbkHisAddressIdRWGSlistIterator* _dbkaddressIdListIt;

 public:
  DbmHisAddressDataSetIt (DbmHisAddressDataSet* dbkaddressIdList);
  ~DbmHisAddressDataSetIt();
  DbkHisAddressId* operator()();
  DbkHisAddressId* key();
  void reset();
};

struct DbmHisContext {
  int contextId;
  int subContextId;
};

struct DbmHisPeriod {
  short hisType;
  unsigned int period;
};

struct DbkHisAttrInfo {
  DbkAddressId addressId;
  int periodST;
  int periodMT;
  ScsType type;
};

struct HisSubscribeCallback {
  DbmHisPeriod* periodList;
  char* callback;
  ScsAny arg;
};

/**
\code#include "dbm.h"\endcode
   Prototype of the subscription of His in Dbm callback function.
   \param date  [in]: date of the value,
   \param Context [in]: context and subcontext of the return value,
   \param count [in]: number of parameter of the list,
   \param arg  [in]: optional user argument passed as parameter of the <em>notifyPeriodCallback()</em> method and returned back to the callback function when called.
*/

typedef void (*DbmHisSubscribePeriodCallback)(unsigned long date,
					      DbmHisContext* context,
					      unsigned int count,
					      ScsAny arg);

/*struct DbmHisSubscribePeriodCallback {unsigned long date;
  DbmHisContext* context;
  unsigned int count;
  ScsAny arg;};*/
/**
\code#include "dbm.h"\endcode
   Prototype of the subscription of His in Dbm callback function.
   \param dateDebut  [in]: start date of the value,
   \param dateFin  [in]: end date of the value,
   \param arg [in]: optional user argument passed as parameter,
*/

typedef void (*DbmHisSubscribeSnapshotCallback)(unsigned long dateDebut,
						unsigned long dateFin,
						ScsAny arg);
/*struct DbmHisSubscribeSnapshotCallback {unsigned long dateDebut;
  unsigned long dateFin;
  ScsAny arg;};
*/
/**
\code#include "dbm.h"\endcode
   Prototype of the callback to load files from His to Dbm.
   \param arg  [in]: argument of the callback,
   \param returnStatus  [in]: return status of the remote methode,
*/
typedef void (*DbmHisLoadFilesCallback)(ScsAny arg,
					ScsStatus returnStatus) ;
/**
\code#include "dbm.h"\endcode
   Prototype of the historic callback function.
   \param arg  [in]: argument of the callback,
   \param returnStatus  [in]: return status of the remote methode,
*/
typedef void (*DbmHisHistoricCallback) (const DbmHisAddressDataSet &values, ScsAny arg, ScsStatus returnStatus) ;

class DbmHisCallback_i;
class DbmHisManager;
class DbmHisCallbackProxy;

#endif
