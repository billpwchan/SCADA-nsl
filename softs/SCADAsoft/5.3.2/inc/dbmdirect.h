//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : dbmdirect.h                                            */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                                 */
/*  CREATION DATE    : Fri Jun  4 12:45:10 1999                               */
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
// $Id: dbmdirect.h,v 1.2 1999/11/25 09:11:37 scadaref Exp $
//
// HISTORY:
// $Log: dbmdirect.h,v $
// Revision 1.2  1999/11/25 09:11:37  scadaref
// Port on MSVC6
//
// Revision 1.1  1999/06/04 16:45:13  ylo
// Initial revision
//


#ifndef _SCS_DBMDIRECT_H_
#define _SCS_DBMDIRECT_H_

/**
   \file
   \brief Encapsulate direct access to database points
*/

#include "scs.h"
#include "dbk/dbkaddressid.h"

struct DBK_API DbkDirectAccess {
  void* _shmPtr;
  unsigned short _dbkType;
  unsigned short _dbkSize;	// Only useful for DBK_VECTOR, DBK_CHARN, DBK_BITFIELD

  int isVector() const;
  int getValueType() const;
};

/**
   \brief This class is used to store the address of a database point attribute, and, eventually, its value and its type and, if you are on a local machine, DbmDataDirect have a pointer on share memory allowing direct read in memory.

   The <em>DbmDirectData</em> class is used to store address and value of a database point attribute. The point address is a symbolic description and is stored in an <em>DbkAddressId</em> object. The value is stored in an <em>ScsData</em> object with its associated type. You don't have to know the rest of this class because it is only used only for private usage.
\code#include "dbmdirect.h"\endcode
*/
class DBK_API DbmDirectData {
 public:
  DbmDirectData();
  DbmDirectData(const DbmDirectData& data);
  DbmDirectData(unsigned int plin, unsigned int ain);
  DbmDirectData(unsigned int plin, unsigned int ain, int value);
  DbmDirectData(unsigned int plin, unsigned int ain, float value);
  DbmDirectData(unsigned int plin, unsigned int ain, const char *value);
  DbmDirectData(unsigned int plin, unsigned int ain, timeval value);
  DbmDirectData(unsigned int plin, unsigned int ain, const ScsData& value);
  DbmDirectData(const DbkAddressId &address);
  DbmDirectData(const DbkAddressId &address, int value);
  DbmDirectData(const DbkAddressId &address, ScsINT64 value);
  DbmDirectData(const DbkAddressId &address, float value);
  DbmDirectData(const DbkAddressId &address, double value);
  DbmDirectData(const DbkAddressId &address, const char *value);
  DbmDirectData(const DbkAddressId &address, timeval value);
  DbmDirectData(const DbkAddressId &address, const unsigned char *value, unsigned int size);
  DbmDirectData(const DbkAddressId &address, const ScsData& value);
  DbmDirectData(const DbkAddressId &address, const ScsData& value, char* shmPtr, const int valueType);

 
  ~DbmDirectData() {}
    
  /**@name General member functions*/
  //@{   
 /**
     \par Description:
     returns the object containing the value of the point attribute.
     \par Parameters:
     none.
     \par Return values:
     the <em>ScsData</em> object of the <em>DbmDirectData</em> object.
  */
  inline const ScsData& getData() const { return _data;};

  /**
     \par Description:
     set the buffer of the <em>ScsData</em> object of vector and table type.
     \param buffer [in]: buffer to set to the instance
     \param size [in]: size of the buffer in bytes
     \return
     \li \c ScsValid : success
     \li \c ScsError : the object is not of vector or table type or the size of buffer does not fit object size
  */
  ScsStatus setBuffer(const ScsAny buffer,unsigned int size);

 /**
     \par Description:
     returns the buffer of the object containing the value of the point attribute. 
     \par Parameters:
     none.
     \par Return values:
     the buffer of the <em>ScsData</em> object of the <em>DbmDirectData</em> object.
  */
  inline ScsAny getBuffer() const { return _data.getBuffer();};

  /**
     \par Description:
     returns the type of the <em>DbmDirectData</em>. The type returned is the type of the data for a scalar or vector.
     \par Parameters:
     none.
     \par Return values:
     the type of the <em>DbmDirectData</em> object.
  */
  inline ScsType getType() const { return _data.getType(); }
  inline unsigned int getPart_1() const { return _plin;}
  inline unsigned int getPart_2() const { return _ain;}

  /**
     \par Description:
     returns the <em>DbkAddressId</em> of the <em>DbmDirectData</em>. 
     \par Parameters:
     none.
     \par Return values:
     the type of the <em>DbmDirectData</em> object.
  */
  inline DbkAddressId getDbkAddressId() const { return DbkAddressId(_plin, _ain); }

 /**
     \par Description:
     set contextId and subContextId of data
     \param contextId  [in]: new context id
     \param subContextId  [in] : new sub context id
     \return
     \li \c ScsValid : success.
  */
  ScsStatus setContext (int contextId, int subContextId);
  //@}

  inline void* getShmPtr() const { return _shmPtr; }
  inline void setShmPtr(void* p_shmPtr) { _shmPtr = p_shmPtr;}
  int getValueType() const;
  inline void setValueType(int valueType ) {_valueType = valueType;}
  int isVector() const;
  unsigned int getSizeToCopy() const;

  /**@name Operator / cast*/
  //@{
  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmDirectData</em> casted to an int value.
     \par Parameters:
     none.
     \par Return values:
     the casted int value.
  */
  inline operator int() { return *(int *)_data.getBuffer();}

  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmDirectData</em> casted to an INT64 value.
     \par Parameters:
     none.
     \par Return values:
     the casted INT64 value.
  */
  inline operator ScsINT64() { return *(ScsINT64 *)_data.getBuffer();}
  
  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmDirectData</em> casted to a float value.
     \par Parameters:
     none.
     \par Return values:
     the casted float value.
  */
  inline operator float() { return *(float *)_data.getBuffer();}

  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmDirectData</em> casted to an double value.
     \par Parameters:
     none.
     \par Return values:
     the casted double value.
  */
  inline operator double() { return *(double *)_data.getBuffer();}
  
  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmDirectData</em> casted to a string value.
     \par Parameters:
     none.
     \par Return values:
     the casted string value.
  */
  inline operator char*() { return (char *)_data.getBuffer();}

  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmDirectData</em> casted to a timeval structure value.
     \par Parameters:
     none.
     \par Return values:
     the casted timeval structure value.
  */
  inline operator timeval() { return *(timeval *)_data.getBuffer();}
  
  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmDirectData</em> casted to a bit field value.
     \par Parameters:
     none.
     \par Return values:
     the casted bit field value.
  */
  inline operator unsigned char *() { return (unsigned char *)_data.getBuffer();}
  
  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmDirectData</em> to the specified int value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmDirectData</em>.
  */
  DbmDirectData& operator=(int value);

  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmDirectData</em> to the specified int64 value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmDirectData</em>.
  */
  DbmDirectData& operator=(ScsINT64 value);
  
  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmDirectData</em> to the specified float value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmDirectData</em>.
  */
  DbmDirectData& operator=(float value);

  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmDirectData</em> to the specified double value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmDirectData</em>.
  */
  DbmDirectData& operator=(double value);
  
  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmDirectData</em> to the specified string value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmDirectData</em>.
  */
  DbmDirectData& operator=(const char* value);

 /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmDirectData</em> to the specified timeval structure value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmDirectData</em>.
  */
  DbmDirectData& operator=(timeval value);

  /**
     \par Description:
     assignment operator. This operator set the <em>ScsData</em> of the <em>DbmDirectData</em> to the specified value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmDirectData</em>.
  */
  DbmDirectData& operator=(const ScsData& value);

  DbmDirectData& operator=(const DbmDirectData& data);
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     save the <em>DbmDirectData</em> object into an <em>ostream</em>.
     \param stream  [in]: output stream. 
     \par Return values:
     none.
  */
  void save(SCS_SL_STD(ostream)& stream) const;

  /**
     \par Description:
     restore the <em>DbmDirectData</em> object from an <em>istream</em>. This operation do not connect DbmData to share memory even on a local machine.
     \param stream  [in]: input stream. 
     \par Return values:
     none.
  */
  void restore(SCS_SL_STD(istream)& stream);
  //@}

  void read();			// fulfil the _data member from the _shmPtr and _valueType args

  int getRowIndex() const { return _rowIndex; }
  short getColumnIndex() const { return _colIndex; }
  void setCellIndex(int rowIndex, short colIndex);
  
 private:
  unsigned int _plin; // DbkAddressId.ValuePart_1
  unsigned int _ain;// DbkAddressId.ValuePart_2
  int _rowIndex;
  short _colIndex;
  void* _shmPtr;
  ScsData _data;
  unsigned short _valueType;
};

class DbmDirectDataList;
class DbmDirectDataListInternalIt;
/**
   \brief This class is used as iterator on <em>DbmDirectDataList</em> .

\code#include "dbmdirect.h"\endcode
*/
class DBK_API DbmDirectDataListIterator {
 public:
  /**
     \par Description:
     constructor for the iterator
     \param p_directDataList  [in]: The list, we want to iterate.
  */
  DbmDirectDataListIterator(const DbmDirectDataList &p_directDataList);
  ~DbmDirectDataListIterator();

  /**
     \par Description:
     give the next element in the list.
     \par Parameters:
    none.
     \return
     \li \c DbmDirectData : the next <em>DbmDirectData</em>.
     \li \c NULL : if we are at the end of the list.
  */
  DbmDirectData* operator()();

  void reset(void);

private:
  DbmDirectDataListInternalIt* _it;
};

/**
   \brief This class is used to store the info for reading, writing point attributes in database or subscribing to database point attributes.

   This class is used to store the description of database point attributes, and, eventually, an associated value and its type, and if you are on a local machine a pointeur on shareMemory in <em>DbmDirectData</em> objects using an <em>DbkAddressId</em> object and an <em>ScsData</em> object. It is essentially to make fast reading directly in share memory.
   The better way to create a <em>DbmDirectDataSet</em> is to use the method convertDbmDataSet_In_DbmDirectDataSet of <em>DbmServer</em>
\code#include "dbmdirect.h"\endcode
*/
class DBK_API DbmDirectDataSet {
 public:
  DbmDirectDataSet();
  DbmDirectDataSet(unsigned long length);
  DbmDirectDataSet(const DbmDirectDataSet &dataSet);
  ~DbmDirectDataSet();

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     add a data to the directdataset. Do not make connection with share memory
     \param data  [in]: contains the description of a database point using an <em>DbkAddressId</em> object and, eventually, a value and its type.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus add(const DbmDirectData& data);

  /**
     \par Description:
     remove a data from the directdataset.
     \param data  [in]: pointer to the data to remove from the dataset.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the data was not found in the dataset.
  */
  ScsStatus remove(DbmDirectData* data);

  /**
     \par Description:
     remove the data at position <em>index</em> from the directdataset.
     \param index  [in]: index of the data to remove from the dataset.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : the position of the data is not correct.
  */
  ScsStatus remove(int index);
  
  /**
     \par Description:
     Returns and removes the first data of the dataset.
     \par Return values:
     the first of data of the dataset.     
  */  
  DbmDirectData* get();
  
  /**
     \par Description:
     removes every data of the dataset.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus clearData();

  DbmDirectData * const *getData(short& count) const;

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
  DbmDirectData* operator[](int pos) const;

 /**
     \par Description:
     return a pointer on the DbmDirectData list.This list is a roguewave list, so if you want make an operation on all element, you should use an iterator.
     \par Parameters:
     none.
     \par Return values:
     the number of data in the dataset.
  */
  DbmDirectDataList *getDataList() const {return _dataList;}
 
  /**
     \par Description:
     set contextId and subContextId of all the data contained in the dataset
     \param contextId  [in]: new context id of data
     \param subContextId  [in] : new sub context id of data
     \return
     \li \c ScsValid : success.
  */
  ScsStatus setContext (int contextId, int subContextId);
  //@}
  ScsStatus convertToArray();

 private:
  DbmDirectDataList *_dataList;
  DbmDirectData* _dataArray;
  unsigned long _length;
};

class DbkReadWrite;
class DbkReadWriteControl;
class DbkHierarchy;
class DbkLibDatabaseAccess;
class DbmDataSet;
    
#include "dbk/scsshmem.h"

struct DBK_API DbkAccess {
  // Poller group management
  DbkReadWrite**        _attrInfo;
  int                   _numGroup;
  ScsData**             _data;
  int*                  _numElements;

  // Database memory management
  ScsSharedMemory_t     _mem;
  DbkReadWriteControl*  _RWControl;

  //Hierarchy Part
  ScsSharedMemory_t     _hierarchyMem;
  DbkReadWriteControl*  _hierarchyControl;
  DbkHierarchy*         _hierarchy;
  DbkLibDatabaseAccess* _accessDatabase;

  // DPL - 07/10/02 - FFT SRC-360 : Cannot do 2 "new DbmServer" in a process
  static DbkAccess* _Instance;
  static int _InstanceNumber;

  ScsStatus read(DbmDataSet& dataSet);
  ScsStatus directRead(DbmDirectDataSet& dataSet);
};

extern DBK_API void DbmDeref(DbkAccess* kernelAccess, ScsAddress& address);
#endif
