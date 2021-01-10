/******************************************************************************/
/*                                                                            */
/*  FILE                : trddataset.h                                        */
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
// $Id: trddataset.h,v 1.14 2000/02/01 15:35:22 scadaref Exp $
//
// HISTORY:
// $Log: trd.h,v $

#ifndef _TRDDATASET_H_
#define _TRDDATASET_H_

/** \file
    \brief Data used in Trend server context
*/

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "trddata.h"

//#define TRACE
#ifdef TRACE
#include "trace.h"
#endif


class TrdSubscriber;
class OlsDataSet;
class TrdDataRWGSlist;
class ScsString;    

/**
   \brief This class is one of the class of the <em>TRD</em> SCADAsoft component.

   This class is a collection of <em>TrdData</em> objects which represents the 
   different values of a specific attribute in the database. The archive to
   which this <em>TrdDataSet</em> belongs specifies the way the attribute is stored
   (periodically or change-based). This class inherits from the <em>OlsList</em>
   class.
\code#include "trd.h"\endcode
*/

class TRD_API TrdDataSet
{
 public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates an object to 
     hold data for the designated attribute extracted from the designated 
     archive.  <em>notificationCallback</em> is called when new data is added to 
     the <em>TrdDataSet</em>.
     \param archiveName  [in]: the name of the archive containing the
     attribute,
     \param attributeName  [in]: the attribute name,
     \par Return values:
     none.
  */
  TrdDataSet (const char        *archiveName,
	      const char        *attributeName);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~TrdDataSet ();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function returns the name of the
     archive corresponding to the dataset.
     \par Parameters:
     none.
     \par Return values:
     the archive name.
  */
  const char *getArchiveName() const;
  /**
     \par Description:
     this function returns the source of the
     <em>TrdDataSet</em>, i.e. the database attribute which is archived.
     \par Parameters:
     none.
     \par Return values:
     the attribute name.
  */
  const char *getAttributeName () const;
#ifdef COMMENT_OUT
  /**
     \par Description:
     this function returns the subscription
     identifier.
     \par Parameters:
     none.
     \par Return values:
     the subscription identifier.
  */
  int getSubscriptionId () const { return _subscriptionId;};
#endif
  /**
     \par Description:
     this function returns the first
     <em>TrdData</em> object of the <em>TrdDataSet</em> and removes it from the
     dataset.
     \par Parameters:
     none.
     \par Return values:
     the first <em>TrdData</em> object.
  */
  TrdData *popData ();
  /**
     \par Description:
     this function returns the number of data
     in the dataset.
     \par Parameters:
     none.
     \par Return values:
     the number of data.
  */
  int getDataCount () const;

  /**
     \par Description:
     this function adds a data in the dataset
     \param data : data to add.
     \par Return values:
     ScsValid
  */
  ScsStatus addData(const TrdData& data);
  //@}

  /**@name Operators / cast*/
  //@{
  /**
     \par Description:
     this operator returns the data at 
     position <em>pos</em> in the dataset.
     \param pos  [in]: the data position.
     \par Return values:
     the <em>pos</em>th data.
  */
  const TrdData* operator[](int pos) const;
  //@}

  void insert(const OlsDataSet& olsDataSet);
  void append(TrdDataSet& trdDataSet,  TrdSubscriber* sub = NULL);
  void clear();

  void incr() {_refCount++;}
  int  decr() {_refCount--; return _refCount;}
  TrdDataSet(TrdDataSet* trdDataSet, TrdSubscriber* sub = NULL);
  TrdDataSet(const TrdDataSet& trdDataSet, TrdSubscriber* sub = NULL);
  TrdDataSet(const TrdDataSet& trdDataSet, int storage);

  friend SCS_SL_STD(ostream)& operator <<(SCS_SL_STD(ostream)& ostr, TrdDataSet& dataSet);

 private:
  ScsString*		_archiveName;      // Name of the associated archive
  ScsString*		_attributeName;    // Name of the attribute of the point
  TrdDataRWGSlist *	_trdDataList;
  int _refCount;
};


class TrdDataSetRWList;
class TrdDataSetListList;
class TrdDataSetList;
/**
\code#include "trddataset.h"\endcode
   Prototype of the TRD component notification callback. The <em>dataSetList</em>
   is a list of datasets, each one of which is associated with an attribute and 
   contains the values from the creation of the archive containing the 
   attribute.  Each data of a dataset can be retrieved and removed from the dataset 
   using the <em>TrdDataSet::popData ()</em> function.
   \param dataSet  [in]: dataset containing the list of the attribute
   values,
   \param arg  [in]: user optional argument passed as parameter of the
   <em>subscribe()</em> method.
   \par Return values:
     none.
*/
typedef void (*TrdUpdateCallback)(TrdDataSetList& dataSetList, void *arg);

class TRD_API TrdDataSetList
{
 public:
  TrdDataSetList (int subscriptionId = -1, ScsAny arg = NULL, TrdUpdateCallback notificationCallback = 0);
  TrdDataSetList (const TrdDataSetList& trdDataSetList);  
  virtual ~TrdDataSetList();
  int getSubscriptionId() const {return _subscriptionId;}
  ScsAny getArg() {return _arg;}
  TrdUpdateCallback getCallback() const {return _notificationCallback;};
  void setCallback(TrdUpdateCallback notificationCallback) {_notificationCallback = notificationCallback;};
  void forward(TrdDataSetList& newData, TrdSubscriber* sub = NULL);
  void forwardAndClassify(TrdDataSetList& newData);
  void clean();
  TrdDataSet* append(TrdDataSet* dataSet);
  
  TrdDataSet* get();
  int entries() const;
  TrdDataSet * at(int index);
  void clear();

  friend SCS_SL_STD(ostream)& operator <<(SCS_SL_STD(ostream)& ostr, TrdDataSetList& trdDataSetList);  
  friend  bool	operator<(const TrdDataSetList& list1, 
			  const TrdDataSetList& list2);
  friend  bool	operator==(const TrdDataSetList& list1, 
			   const TrdDataSetList& list2);
 private:
  TrdDataSetRWList*	_dataSetList;
  int			_subscriptionId;
  ScsAny		_arg;
  TrdUpdateCallback     _notificationCallback;
#ifdef TRACE
  Trace _t;
#endif
};

#endif
