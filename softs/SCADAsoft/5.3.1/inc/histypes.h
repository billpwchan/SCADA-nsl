/******************************************************************************/
/*                                                                            */
/*  FILE                : histypes.h                                          */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY             : THALES IS                                           */
/*  CREATION DATE       : 2000/08/16                                          */
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
// $Id: histypes.h,v 1.1 2000/08/16 15:09:32 sjs Exp $
//
// HISTORY:
// $Log: his.h,v $
// Revision 1.1  2000/08/16 15:09:32  sjs
// Initial Version
//
// KLL - 08 09 2003 - FFT SRC 582 - 
//                    Get eventListHis elements with the start time and end time
//
// Revision 4.3.0  18/08/2004 KLL 
// FFT SCS 509 - Traitement de données suite à un changement de VDC
//
// Revision 4.4.0  2004/10/13 kll
// FFT SRC 860 - EventListHis Files Management  on change of VDC
//
/******************************************************************************/
#ifndef _HISTYPES_H
#define _HISTYPES_H

/**
  \file
  \brief Various utility classes used in the History server context.
*/

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT                                                               */
/*----------------------------------------------------------------------------*/

#ifdef WIN32
#pragma warning(disable: 4786)
#pragma warning(disable: 4251)
#endif



#include "scs.h"
#include "ols.h"

#define HisTrace    ScsTraceFunction(HIS_SCSMODULE)
#define HisTraceLevel(level, message) BaseTraceLevel(HIS_SCSMODULE, level, message)

#define EVENT_LIST_ARCHIVE_NAME "EventListHis"

#define ERROR_TYPE        -1
#define ST_TYPE           0
#define MT_TYPE           1
#define EVENTLIST_TYPE    2
#define CBASED_TYPE       3

class HisArchive;
class HisProxy;
class HisQuery;
class HisServer;

enum HisTraceLevel {
  HIS_ADM_LEVEL,
  HIS_ERR_LEVEL,
  HIS_OUT_LEVEL,
  HIS_IN_LEVEL,
  HIS_SOFT_LEVEL,
  HIS_TEST_LEVEL,
  HIS_REQ_LEVEL,
  HIS_FILE_LEVEL,
  HIS_DBV_LEVEL,
  HIS_SNAPSHOT_LEVEL,
  HIS_LIST_LEVEL,
  HIS_LT_LEVEL
};

enum HisArchiveType
{
    RTAP_ARCHIVE = 0,
    EXTERNAL_ARCHIVE,
    EVENT_ARCHIVE,
    CBASED_ARCHIVE
};

enum HisListType
{
    LIMITED = 0,
    UNLIMITED,
    CIRCULAR
};

enum HisQualityType
{
    NO_QUALITY = -1,
    ATTR_QUALITY,
    RTAP_QUALITY
};

enum HisTimestampType
{
    NO_TIMESTAMP = -1,
    ATTR_TIMESTAMP
};

enum HisRequestType
{
  SAVE,
  LOAD,
  READ,
  READ_EVENT,
  QUERY,
  QUERY_EVENT,
  SUBSCRIBE,
  MOUNT,
  SNAPSHOT,
  CHANGE_DBV
};
enum HisAccessType
{
  NO_ACCESS=-1,
  MEMORY,
  DISK,
  LT
};
enum HisServerType
{
  RTAP_HISSERVER,
  NEW_HISSERVER
};

/******************************************************************************/

/**
  \brief A HisDataAddress represents a single query for data to be retrieved from 
  hisserver.
  */
class HIS_API HisDataAddress
{
public:
    /**@name Constructors / destructor*/
    //@{
    /**
      create a HisDataAddress object with the specified archive and filter
      names.
      */
    HisDataAddress (const char* archiveName,
                    OlsFilter*  filter);
    /**
      create an empty HisDataAddress object
      */
    HisDataAddress ();
    /**
      copy constructor
      */
    HisDataAddress (const HisDataAddress& sourceDataAddress);
    /**
      delete a HisDataAddress object
      */
    virtual ~HisDataAddress ();
    //@}

    /**@name General Usage member functions*/
    //@{
    /**
     \par Description:
     get the name of the archive associated with the
      HisDataAddress.
     \par Parameters:
     none
     \par Return values:
     the archive name.
      */
    const char* getArchiveName () const;
    /**
     \par Description:
     get a pointer to the filter associated with
      the HisDataAddress.
     \par Parameters:
     none
     \par Return values:
     pointer to the filter.
      */
    const OlsFilter* getFilter () const;
    
    virtual void save (SCS_SL_STD(ostream) &os) const;
    virtual void restore (SCS_SL_STD(istream) &is);
    //@}
private:
    char*              _archiveName;
    OlsFilter*         _filter;
};

class HisDataAddressRWGSlist;
class HIS_API HisDataAddressList
{
public:
  HisDataAddressList();
  HisDataAddressList(const HisDataAddressList& HisDataAddressList);
  ~HisDataAddressList();

  size_t entries() const;
  const HisDataAddress* at(int index) const;
  HisDataAddress* at(int index);
  HisDataAddress* get();
  void clear();
  HisDataAddress* append (HisDataAddress* address);
  void save(SCS_SL_STD (ostream) &os) const;
  void restore (SCS_SL_STD (istream) &is);

private:
  friend class HisDataAddressListIt;
  HisDataAddressRWGSlist* _hisDataAddressList;
};

class HIS_API HisDataAddressListIt
{
public:
  HisDataAddressListIt (const HisDataAddressList& hisDataAddressList);
  ~HisDataAddressListIt();
  HisDataAddress* operator() ();
  void reset();

private:
  void *_it;
};

/******************************************************************************/


class HIS_API HisDataSet
{
public:
    HisDataSet (OlsDataSet *olsDataSet, long id, const char* archiveName);
    HisDataSet ();
    ~HisDataSet ();

    OlsDataSet* getDataSet () {return _olsDataSet;};
    long        getId () {return _id;}
    const char* getArchiveName () { return _archiveName; }

    void save (SCS_SL_STD(ostream)& os) const;
    void restore (SCS_SL_STD(istream)& is);

private:
    OlsDataSet* _olsDataSet;
    long        _id;
    char*       _archiveName;
}; 

class HisDataSetRWGSlist;

class HIS_API HisDataSetList
{
public:
  HisDataSetList();
  HisDataSetList(const HisDataSetList& hisDataSetList);
  ~HisDataSetList();

  size_t entries() const;
  const HisDataSet* at(int index) const;
  HisDataSet* at(int index);
  HisDataSet* get();
  HisDataSet* append (HisDataSet* hisDataSet);
  void clear();

  void save (SCS_SL_STD(ostream) &os) const;
  void restore (SCS_SL_STD(istream) &is);

private:
  friend class HisDataSetListIt;
  HisDataSetRWGSlist* _hisDataSetList;
};


class HIS_API HisDataSetListIt
{
public:
  HisDataSetListIt (const HisDataSetList& hisDataSetList);
  ~HisDataSetListIt();
  HisDataSet* operator() ();
  void reset();

private:
  void *_it;
};


/******************************************************************************/

class HIS_API HisAttrib
{
public:
    HisAttrib (const char* name, ScsType type);

    HisAttrib ();

    const char*   getName ();
    ScsType getType ();

    void save (SCS_SL_STD(ostream)& os) const;

    void restore (SCS_SL_STD(istream)& is);

private:
    char*       _name;
    ScsType     _type;
}; 

class HisAttribRWGSlist;

class HIS_API HisAttribList
{
public:
  HisAttribList();
  HisAttribList(const HisAttribList& hisAttribList);
  ~HisAttribList();

  int entries() const;
  const HisAttrib* at(int index) const;
  HisAttrib* at(int index);
  HisAttrib* get();
  void clear();
  HisAttrib* append (HisAttrib* hisAttrib);
  void save (SCS_SL_STD(ostream) &os) const;
  void restore (SCS_SL_STD(istream) &is);
private:
  HisAttribRWGSlist* _hisAttribList;
};
/******************************************************************************/

class ScsString;
class HisPointList;

/**
   \brief This class is used to store the name of an archive point, and, eventually, its quality type.

\code#include "histypes.h"\endcode
*/
class HIS_API HisPoint
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.
     \param name  [in]: the name of the archive point,
     \param indQuality  [in]: indicates if the quality of the point if needed.,
     \param id  [in] : id of point
     \par Return values:
     none.
  */
  HisPoint(const char* name, HisQualityType indQuality, unsigned int id);

  /**
     \par Description:
     copy constructor.
     \param point  [in]: the <em>HisPoint</em> object to copy.
     \par Return values:
     none.
  */
  HisPoint(const HisPoint& point);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~HisPoint();
  /**
     \par Description:
     return point's name.
     \par Parameters:
     none.
     \par Return values:
     point's name.
  */
  const char* getName() const;
  /**
     \par Description:
     return if point's quality is needed.
     \par Parameters:
     none.
     \par Return values:
     point's quality indicator.
  */
  HisQualityType getIndQuality() const;
  /**
     \par Description:
     return  point's id.
     \par Parameters:
     none.
     \par Return values:
     point's id.
  */
  unsigned int  getId() const;
  /**
     \par Description:
     set if point's quality is needed..
     \par Parameters:
     point's quality indicator.
     \par Return values:
     none.
  */
  void  setIndQuality(HisQualityType qualityInd);
  //@}
  virtual void save (SCS_SL_STD(ostream) &os) const;
  virtual void restore (SCS_SL_STD(istream) &is);

  friend HIS_API bool	operator<(const HisPoint& point1, const HisPoint& point2);
  friend HIS_API bool	operator==(const HisPoint& point1, const HisPoint& point2);

private:
  ScsString *_name;
  unsigned int _id;
  HisQualityType _indQuality;
};

extern HIS_API bool	operator<(const HisPoint& point1, const HisPoint& point2);
extern HIS_API bool	operator==(const HisPoint& point1, const HisPoint& point2);

/**
   \brief This class is used to store the info for reading archive points or subscribing to archive points.

   This class is used to store the name of archive points, and, eventually, its quality types, in <em>HisPoint</em> objects.
\code#include "his.h"\endcode
*/
class HIS_API HisPointSet
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an empty point set if no argument are given. 
     \param archiveName  [in]: archive name. 
     \par Return values:
     none.
  */
  HisPointSet (const char *archiveName=0);
  /**
     \par Description:
     copy constructor.
     \param pointSet  [in]: point set to copy. 
     \par Return values:
     none.
  */
  HisPointSet (const HisPointSet& pointSet);
  /**
     \par Description:
     destructor. This function deletes the pointset.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~HisPointSet();
   //@}
   /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     add a point to the point set.
     \param point  [in]: contains the description of an archive point.
     \return
     \li \c ScsValid : success or error if point id already exists
  */
  ScsStatus add(const HisPoint &point);
  
  /**
     \par Description:
     add a point to the point set.
     \param point  [in]: contains the description of an archive point.
     \return
     \li \c ScsValid : success or error if point id already exists
  */
  ScsStatus add(HisPoint* point);

  /**
     \par Description:
     find a point from the point set based on its name.
     \param name  [in]: point name
     \return NULL if point does not exists
  */
  HisPoint* find(const char* name) const;
  
  /**
     \par Description:
     remove all points for which MatchFunc is true (points are deleted)
     \param MatchFunc  [in]: test function
     \param arg [in]: argument of match function
     \param doDelete [in]: delete matching points if true
     \return number of matching points
  */
  int removeMatchingPoint(bool (*MatchFunc)(const HisPoint* point, void* arg), void* arg, bool doDelete = false);
  
   /**
     \par Description:
     apply function ApplyFunc on all points
     \param ApplyFunc  [in]: function to be applied
     \param arg [in]: argument of applied function
  */
  void apply(void (*ApplyFunc)(const HisPoint* point, void* arg), void* arg);

  /**
     \par Description:
     remove a point from the point set.
     \param point  [in]: pointer to the point to remove from the point set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the point was not found in the point set.
  */
  ScsStatus remove(HisPoint *point);

  /**
     \par Description:
     remove the point with id "id"
     \param id  [in]: id of point to remove from the point set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : id of the point is not correct.
  */
  ScsStatus remove(int id);

  /**
     \par Description:
     return the number of point in the point set.
     \par Parameters:
     none.
     \par Return values:
     the number of point in the point set.
  */
  int getPointCount() const;

  /**
     \par Description:
     return the archive name.
     \par Parameters:
     none.
     \par Return values:
     the archive name.
  */
  const char* getArchiveName() const;
  /* NOT DOCUMENTED
     \par Description:
     set id of point set.
     \par Parameters:
     the point set id.
     \par Return values:
     none.
  */
  void setId(unsigned int newId);
  /**
     \par Description:
     return the id of point set.
     \par Parameters:
     none.
     \par Return values:
     the point set id.
  */
  unsigned int getId() const;
  //@}

  virtual void save (SCS_SL_STD(ostream) &os) const;
  virtual void restore (SCS_SL_STD(istream) &is);

  friend class HisPointSetIt;
  friend class HisDbPointSet;
      
private:
  HisPointList *_points;
  ScsString *_archiveName;
  unsigned int _id;
};

class HisPointListIt;
/**
   \brief This class provides an iterator on <em>HisPoint</em> collection of <em>HisPointSet</em> class.

\code#include "his.h"\endcode
*/
class HIS_API HisPointSetIt
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.The iterator begins in an undefined state and must 
     be advanced before the first element will be accessible
     \par Parameters:
     none
     \par Return values:
     none.
  */
  HisPointSetIt (const HisPointSet& pointSet);
  /**
     \par Description:
     destructor..
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~HisPointSetIt();
  //@}
  /**@name General member functions*/
  //@{
  /**
     \par Description:
     Advances self to the next element, dereferences the resulting iterator and returns its value. If the iterator has advanced past the last item in the container, the
     element returned will be a nil pointer equivalent to boolean false.
     \par Parameters:
     none
     \par Return values:
     next element or nil
  */
  HisPoint* operator() ();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     Returns the stored value pointed to by self. Undefined if self is not referencing a value within the set.
     \par Parameters:
     none
     \par Return values:
     stored value pointed to by self.
  */
  HisPoint* key() const;
  /**
     \par Description:
     Resets the iterator so that after being advanced it will point to the first element of the collection.
     \par Parameters:
     none
     \par Return values:
     none
  */
  void reset();
  //@}
 
private:
  HisPointListIt *_it;
};

class HisPointSetRWGSlist;
/**
   \brief This class is used to store a list of <em>HisPointSet</em> objects.

\code#include "his.h"\endcode
*/
class HIS_API HisPointSetList
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an empty list; 
     \par Parameters:
     none
     \par Return values:
     none.
  */
  HisPointSetList ();
  /**
     \par Description:
     copy constructor. This function copies the list; 
     \par Parameters:
     \param pointSets [in]: object to copy.
     \par Return values:
     none.
  */
  HisPointSetList (const HisPointSetList& pointSets);
  /**
     \par Description:
     destructor. This function deletes the list.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~HisPointSetList();
   //@}
   /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     add a <em>HisPointSet</em> object to the list.
     \param pointSet  [in]: contains the description of an point set.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus add(const HisPointSet &pointSet);

  /**
     \par Description:
     remove a point set from the list.
     \param pointSet  [in]: pointer to the point set to remove.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the point set was not found in the list.
  */
  ScsStatus remove(HisPointSet *pointSet);

  /**
     \par Description:
     remove the point set  at position <em>index</em> from the list.
     \param index  [in]: index of the point set to remove.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the position of the point set is not correct.
  */
  ScsStatus remove(int index);

  /**
     \par Description:
     return the number of point set in list.
     \par Parameters:
     none.
     \par Return values:
     the number of point set in the list.
  */
  int getPointSetCount() const;

  /**
     \par Description:
     return the _pointSets attribute.
     \par Parameters:
     none.
     \par Return values:
     the _pointSets attribute.
  */
  HisPointSetRWGSlist * getPointSetList();

  /**
     \par Description:
     return the <em>pos</em>th point set of the list.
     \param pos  [in]: position of the queried point set in the list.
     \par Return values:
     the <em>pos</em>th data.
  */
  HisPointSet *operator[](int pos) const;

  //@}
  
  virtual void save (SCS_SL_STD(ostream)& os) const;
  virtual void restore (SCS_SL_STD(istream)& is);
  
protected:
  HisPointSetRWGSlist *_pointSets;
};
  
class ScsString;
class HisValueRWGSlist;
class HisDbDataList;
class HisDbDataListIt;
/**
   \brief This class is used to store the value of an archive point, and, eventually, its quality at a specific date.

   The <em>HisValue</em> class is used to store value and quality of an archive point at a specific date.
\code#include "histypes.h"\endcode
*/
class HIS_API HisValue
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     Default constructor.
     \par Return values:
     none.
  */
  HisValue();
  /**
     \par Description:
     constructor.
     \param time  [in]: time the archive point was stored,
     \param value  [in]: value of archive point,
     \param quality  [in]: quality of archive point.
     \par Return values:
     none.
  */
  HisValue(unsigned long time, int  value, unsigned int quality);
  HisValue(unsigned long time, float value, unsigned int quality);
  HisValue(unsigned long time, ScsINT64  value, unsigned int quality);
  HisValue(unsigned long time, double value, unsigned int quality);
  
  /**
     \par Description:
     copy constructor.
     \param value  [in]: the <em>HisValue</em> object to copy.
     \par Return values:
     none.
  */
  HisValue(const HisValue& value);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~HisValue();
  
     /**
     \par Description:
     this function returns the value stored 
     in the current object.
     \par Parameters:
     none.
     \par Return values:
     the value of the data.
  */
  ScsAny getValue() const;
  /**
     \par Description:
     this function returns the type of the 
     current object.
     \par Parameters:
     none.
     \par Return values:
     the value type.
  */
  ScsType getType() const;
  /**
     \par Description:
     this function returns the time the value 
     was stored in the archive.
     \par Parameters:
     none.
     \par Return values:
     the time associated with the value.
  */
  unsigned long getTime() const;
  /**
     \par Description:
     this function returns the timestamp of the value.
     \par Parameters:
     none.
     \par Return values:
     the timestamp associated with the value.
  */
  timeval getTimestamp() const;
  /**
     \par Description:
     this function returns the quality of the
     data.
     \par Parameters:
     none.
     \par Return values:
     the data quality.
  */
  unsigned int getQuality() const;  

  /**
     \par Description:
     This function set the value of the obbject.
     \param value  [in]: value of the object.
     \par Return values:
     none.
  */
  void setValue(int value);
  void setValue(float value);
  void setValue(ScsINT64 value);
  void setValue(double value);
  
  /**
     \par Description:
     this function set the type of the 
     current object.
     \param inType  [in]: the value of the object.
     \par Return values:
     none.
  */
  void setType(ScsType inType);

  /**
     \par Description:
     this function set the time of the 
     current object.
     \param inTime  [in]: the time of the object.
     \par Return values:
     none.
  */
  void setTime(unsigned long inTime) { _time = inTime;};
  /**
     \par Description:
     this function set the timestamp of the current object.
     \param inTime  [in]: the timestamp of the object.
     \par Return values:
     none.
  */
  void setTimestamp(timeval inTime);

  /**
     \par Description:
     this function set the quality of the 
     current object.
     \param inQuality  [in]: the quality of the object.
     \par Return values:
     none.
  */
  void setQuality(unsigned int inQuality) { _quality = inQuality;};  
  /**
     \par Description:
     assignment operator, copy values in object.
     \param value  [in]: <em>HisValue</em> object to copy.
     \par Return values:
     the value.
  */
  HisValue &operator=(const HisValue& value);

  //@}
  virtual void save (SCS_SL_STD(ostream) &os) const;
  virtual void restore (SCS_SL_STD(istream) &is);
  
protected:
  int sizeofValue(ScsType t);
  unsigned long _time;
  timeval       _timestamp;
  unsigned int  _quality;	/* 0 means correct */
  unsigned char* _buffer;
  ScsType _type;
};

/**
   \brief This class is used to store the values of an archive point, and, eventually, its qualities.

   The <em>HisDbData</em> class is used to store values and qualities of an archive point.
\code#include "histypes.h"\endcode
*/
class HIS_API HisDbData
{
public:
  /**@name Constructors / destructor*/
  //@{
 
  /**
     \par Description:
     constructor.
     \param id  [in]: id of point (corresponding to the <em>HisPoint</em> id)
     \par Return values:
     none.
  */
  HisDbData(unsigned int id=0);

  /**
     \par Description:
     copy constructor.
     \param data  [in]: the <em>HisDbData</em> object to copy.
     \par Return values:
     none.
  */
  HisDbData(const HisDbData& data);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~HisDbData();
  //@}
   /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return  point's id.
     \par Parameters:
     none.
     \par Return values:
     point's id.
  */
  unsigned int  getId() const;
  /**
     \par Description:
     add a value to the data.
     \param value  [in]: contains the value at a specific date of an archive point.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus add(const HisValue &value);

  /**
     \par Description:
     remove a value from the value list.
     \param value  [in]: pointer to the value to remove from the list
     \return
     \li \c ScsValid : success.
     \li \c ScsError : value was not found in the list.
  */
  ScsStatus remove(HisValue *value);

  /**
     \par Description:
     remove the value at position <em>index</em> from the list.
     \param index  [in]: index of the value to remove from the list.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : position of value is not correct.
  */
  ScsStatus remove (int index);

  /**
     \par Description:
     return the number of value in the list.
     \par Parameters:
     none.
     \par Return values:
     the number of value in the list.
  */
  int getValueCount() const;

  /**
     \par Description:
     return the hisValue list.
     \par Parameters:
     none.
     \par Return values:
     hisValue list.
  */
   HisValueRWGSlist * getHisValueList () const { return (_values);};

  /**
     \par Description:
     find the HisValue with its time <em>inTime</em> from the list.
     \param inTime  [in]: time of the HisValue to find.
     \return
     \li \c HisValue* : the pointer of the HisValue.
     \li \c NULL      : NULL if the HisValue is not find.
  */
  HisValue*  find(unsigned long inTime);

  /**
     \par Description:
     return the <em>pos</em>th value of the list.
     \param pos  [in]: position of the queried value in the list.
     \par Return values:
     the <em>pos</em>th value.
  */
  HisValue *operator[](int pos) const;
  /**
     \par Description:
     assignment operator, copy values in object.
     \param dbData  [in]: <em>HisDbData</em> object to copy.
     \par Return values:
     the data.
  */
  HisDbData &operator=(const HisDbData& dbData);
  //@}
  virtual void save (SCS_SL_STD(ostream) &os) const;
  virtual void restore (SCS_SL_STD(istream) &is);

  friend HIS_API bool	operator<(const HisDbData& data1, const HisDbData& data2);
  friend HIS_API bool	operator==(const HisDbData& data1, const HisDbData& data2);
private:
  unsigned int _id;
  HisValueRWGSlist *_values;
};


/**
   \brief This class is used to store data of reading archive points or subscribing to archive points.

   This class is used to store the values of archive points, and, eventually, its qualities, in <em>HisDbData</em> objects.
\code#include "his.h"\endcode
*/
class HIS_API HisDbDataSet
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an empty data set
     \param id  [in]: id of data set. It is equal of the id of the corresponding <em>HisPointSet</em> object.
     \par Return values:
     none.
  */
  HisDbDataSet (unsigned int id=0);
  /**
     \par Description:
     constructor. This function creates an empty data set
     \par Parameters:
     none
     \par Return values:
     none.
  */
  
  HisDbDataSet (const HisDbDataSet& dataSet);

  /**
     \par Description:
     destructor. This function deletes the data set.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~HisDbDataSet();
   //@}
   /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     add a data to the data set.
     \param data  [in]: contains the data of an archive point.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus add(const HisDbData &data);

  /**
     \par Description:
     remove a data from the data set.
     \param data  [in]: pointer to the data to remove from the data set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : data was not found in the data set.
  */
  ScsStatus remove(HisDbData *data);

  /**
     \par Description:
     remove the data with specified id from the data set.
     \param id  [in]: id of the data to remove from the data set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : id of data is not correct.
  */
  ScsStatus remove (unsigned int id);

  /**
     \par Description:
     return the number of data in the data set.
     \par Parameters:
     none.
     \par Return values:
     the number of data in the data set.
  */
  int getDataCount() const;

  /* NOT DOCUMENTED
     \par Description:
     set id of data set.
     \par Parameters:
     the data set id.
     \par Return values:
     none.
  */
  //void setId(unsigned int newId);
  /**
     \par Description:
     return the id of data set.
     \par Parameters:
     none.
     \par Return values:
     the data set id.
  */
  unsigned int getId() const;
  /**
     \par Description:
     assignment operator, copy values in object.
     \param dbDataSet  [in]: <em>HisDbDataSet</em> object to copy.
     \par Return values:
     the data set.
  */
  HisDbDataSet &operator=(const HisDbDataSet& dbDataSet);
  //@}

  virtual void save (SCS_SL_STD(ostream) &os) const;
  virtual void restore (SCS_SL_STD(istream) &is);
  friend class HisDbDataSetIt;
protected:
  HisDbDataList *_dataList;
private:
  unsigned int _id;
};

/**
   \brief This class provides an iterator on <em>HisDbData</em> collection of <em>HisDbDataSet</em> class.

   This class provides an iterator on <em>HisDbData</em>  collection of <em>HisDbDataSet</em> class.
\code#include "his.h"\endcode
*/
class HIS_API HisDbDataSetIt
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.The iterator begins in an undefined state and must 
     be advanced before the first element will be accessible
     \par Parameters:
     none
     \par Return values:
     none.
  */
  HisDbDataSetIt (const HisDbDataSet& dataSet);
  /**
     \par Description:
     destructor..
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~HisDbDataSetIt();
  //@}
  /**@name General member functions*/
  //@{
  /**
     \par Description:
     Advances self to the next element, dereferences the resulting iterator and returns its value. If the iterator has advanced past the last item in the container, the
     element returned will be a nil pointer equivalent to boolean false.
     \par Parameters:
     none
     \par Return values:
     next element or nil
  */
  HisDbData* operator() ();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     Returns the stored value pointed to by self. Undefined if self is not referencing a value within the set.
     \par Parameters:
     none
     \par Return values:
     stored value pointed to by self.
  */
  HisDbData* key() const;
  //@}
 
private:
  HisDbDataListIt *_it;
};




class HisDbDataSetRWGSlist;
/**
   \brief This class is used to store a list of <em>HisDbDataSet</em> objects.

\code#include "his.h"\endcode
*/
class HIS_API HisDbDataSetList
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an empty list; 
     \par Parameters:
     none
     \par Return values:
     none.
  */
  HisDbDataSetList ();
  /**
     \par Description:
     copy constructor.
     \param dbDataSetList  [in]: the <em>HisDbDataSetList</em> object to copy.
     \par Return values:
     none.
  */
  HisDbDataSetList (const HisDbDataSetList& dbDataSetList);
  /**
     \par Description:
     destructor. This function deletes the list.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~HisDbDataSetList();
   //@}
   /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     add a <em>HisDbDataSet</em> object to the list.
     \param dataSet  [in]: contains the description of an data set.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus add(const HisDbDataSet &dataSet);

  /**
     \par Description:
     remove a data set from the list.
     \param dataSet  [in]: pointer to the data set to remove.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the data set was not found in the list.
  */
  ScsStatus remove(HisDbDataSet *dataSet);

  /**
     \par Description:
     remove the data set  at position <em>index</em> from the list.
     \param index  [in]: index of the data set to remove.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the position of the data set is not correct.
  */
  ScsStatus remove(int index);

  /**
     \par Description:
     find the data set with its id <em>id</em> from the list.
     \param id  [in]: id of the data set to find.
     \return
     \li \c HisDbDataSet* : the pointer of the data set.
     \li \c NULL          : NULL if the data set is not find.
  */
  HisDbDataSet*  find(unsigned int id);

  /**
     \par Description:
     return the number of data set in list.
     \par Parameters:
     none.
     \par Return values:
     the number of point set in the list.
  */
  int getDataSetCount() const;

  /**
     \par Description:
     return the <em>pos</em>th data set of the list.
     \param pos  [in]: position of the queried data set in the list.
     \par Return values:
     the <em>pos</em>th data.
  */
  HisDbDataSet *operator[](int pos) const;
  /**
     \par Description:
     assignment operator, copy values in object.
     \param dbDataSetList  [in]: <em>HisDbDataSetList</em> object to copy.
     \par Return values:
     the data set list.
  */
  HisDbDataSetList &operator=(const HisDbDataSetList& dbDataSetList);
  //@}
  
  virtual void save (SCS_SL_STD(ostream)& os) const;
  virtual void restore (SCS_SL_STD(istream)& is);
  
private:
  HisDbDataSetRWGSlist *_dataSets;
};

/******************************************************************************/
typedef void (*HisCallback)(const HisDataSetList& dataSetList,
                       	    void *               arg);
typedef void (*HisDbCallback) (const HisDbDataSetList& dataSetList, 
			       ScsStatus returnStatus, 
			       void *arg);
typedef void (*HisNotifCallback)(ScsStatus returnStatus, void *arg);
typedef void (*HisMountCallback)(const char* serverName, const char* physEnv,
				 int contextId, int subContextId, ScsStatus returnStatus,void *arg);
typedef void (*HisSnapshotCallback)(ScsStatus returnStatus,void *arg);

#endif

