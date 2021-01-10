//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : olstypes.h                                             */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Tue Dec 15 14:20:32 1998                               */
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
// $Id: olstypes.h,v 1.18 2000/02/01 15:12:20 jmb Exp $
//
// HISTORY:
// $Log: olstypes.h,v $
// Revision 1.18  2000/02/01 15:12:20  jmb
// Add subscribeAgain, setSubId and getSubId methods
//
// Revision 1.17  1999/11/24 10:01:40  scadaref
// Port on MSVC6
//
// Revision 1.16  1999/11/17 08:52:11  ylo
// FFT Norweb 233
//
// Revision 1.15  1999/09/17 15:09:45  ylo
// Integrate reading of the disk archive data for trends
//
// Revision 1.14  1999/09/17 09:38:55  jmb
// Add dumpData method for OlsCollectableList class
//
// Revision 1.13  1999/09/06 09:14:33  jmb
// Add reloadFiles method in OlsCollectableList class
//
// Revision 1.12  1999/06/23 14:50:40  scadaref
// Keeps ScsLock internal.
//
// Revision 1.11  1999/06/22 13:31:38  jmb
// transform ScsLock pointer to variable
//
// Revision 1.10  1999/06/21 09:51:04  jmb
// Add ScsLock in OlsCollectableList class
//
// Revision 1.9  1999/06/03 14:57:08  scadaref
// Add setCriteria method to derive OlsFilter.
//
// Revision 1.8  1999/04/16 15:16:06  scadaref
// propagate list optimization to limited and collectable list.
//
// Revision 1.7  1999/04/15 17:14:23  scadaref
// modification for alarm server enhencement.
//
// Revision 1.6  1999/03/29 17:09:37  jpu
// Move timerCallback(), getRefTime() and setRefTime() in public part
//
// Revision 1.5  1999/02/25 17:44:17  jpu
// Modification of OlsCollectableList class related to daily option
//
// Revision 1.4  1999/01/27 16:06:17  ylo
// Integration of queries.
//
// Revision 1.3  1999/01/20 10:14:38  ylo
// Add snapshot feature.
//
// Revision 1.2  1998/12/15 16:18:45  ylo
// Create ols/libinternal for ascManager needs.
//
// Revision 1.1  1998/12/15 14:34:00  ylo
// Initial revision
//


#ifndef _SCS_OLSTYPES_H_
#define _SCS_OLSTYPES_H_

/**
  \file
  \brief Various classes, typedefs and functions used in OlsList context
*/

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scs.h"
#include "scstimer.h"
#include <vector>

#define OlsTrace	ScsTraceFunction(OLS_SCSMODULE)
#define OlsTraceLevel(level, message)  BaseTraceLevel(OLS_SCSMODULE, level, message)

/**
\code#include "olstypes.h"\endcode
    \par Description:
    enum corresponding to the notification mode used by an Ols server to notify a subscriber which is inside its environment (see <em>OlsServer::subscribe()</em>). 
                            (an Ols server notify asynchronously subscribers which are outside its environment). 
    \code
    enum  OlsNotificationMode {
      OLS_DEFAULT_NOTIFY = 0,
      OLS_SYNCHRONOUS_NOTIFY,
      OLS_ASYNCHRONOUS_NOTIFY
    }; \endcode
    \par Values:
    \li \c OLS_DEFAULT_NOTIFY:             If the environment variable SCSSYNCNOTIFY is set, the Ols server will notify the local subscriber synchrounously,
                                           Otherwise the Ols server will notify the local subscriber asynchronously. 
    \li \c OLS_SYNCHRONOUS_NOTIFY:         The Ols server will notify the local subscriber synchrounously. 
    \li \c OLS_ASYNCHRONOUS_NOTIFY:        The Ols server will notify the local subscriber asynchronously.
*/
enum  OlsNotificationMode {
  OLS_DEFAULT_NOTIFY = 0,
  OLS_SYNCHRONOUS_NOTIFY,
  OLS_ASYNCHRONOUS_NOTIFY
};


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store a value into an element of a list. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsList</em> class) groups a set of objects containing the same kind of information. An object of <em>OlsField</em> class contains a name and a data contained in an <em>ScsData</em> object.
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsField
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It initializes an empty <em>OlsField</em> object.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  OlsField();
  /**
     \par Description:
     copy constructor.
     \param field  [in]: <em>OlsField</em> object to copy.
     \par Return values:
     none.
  */
  OlsField(const OlsField& field);
  /**
     \par Description:
     constructor used for adding field to a filter.
     \param fieldName  [in]: name of the field.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName);
  /**
     \par Description:
     constructor used to store an int value.
     \param fieldName  [in]: name of the field,
     \param value  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, int value);
  /**
     \par Description:
     constructor used to store an int64 value.
     \param fieldName  [in]: name of the field,
     \param value  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, ScsINT64 value);
  /**
     \par Description:
     constructor used to store a float value.
     \param fieldName  [in]: name of the field,
     \param value  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, float value);
  /**
     \par Description:
     constructor used to store a double value.
     \param fieldName  [in]: name of the field,
     \param value  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, double value);
  /**
     \par Description:
     constructor used to store a string value.
     \param fieldName  [in]: name of the field,
     \param value  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, const char *value);
  /**
     \par Description:
     constructor used to store a wide string value.
     \param fieldName}  [in]: name of the field,
     \param value}  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, const wchar_t *value);
  /**
     \par Description:
     constructor used to store a timeval value.
     \param fieldName  [in]: name of the field,
     \param value  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, timeval value);
  /**
     \par Description:
     constructor used to store a pointer value.
     \param fieldName  [in]: name of the field,
     \param value  [in]: data value.
     \par Return values:
     none.
  */
  OlsField(const char *fieldName, void* value);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
 virtual ~OlsField();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function returns the field name (i.e. the column where the field is located) in the list.
     \par Parameters:
     none.
     \par Return values:
     the field name.
  */
  const char* getFieldName() const;
  /**
     \par Description:
     this function returns the <em>ScsData</em> object containing the value of the field.
     \par Parameters:
     none.
     \par Return values:
     the <em>ScsData</em> object of the field.
  */
  const ScsData& getData() const { return _data;}
  /**
     \par Description:
     this function returns the value contained in the <em>ScsData</em> object of the field.
     \par Parameters:
     none.
     \par Return values:
     the field value.
  */
  ScsAny getBuffer() const { return _data.getBuffer();};
  /**
     \par Description:
     this function returns the type of the field.
     \par Parameters:
     none.
     \par Return values:
     the field type.
  */
  ScsType getType() const { return _data.getType();};
  //@}

  /**@name Operators / cast*/
  //@{
  /**
     \par Description:
     assignment operator. This operator is used to assign an <em>OlsField</em> object to current object.
     \param field  [in]: the field object to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(const OlsField& field);
  /**
     \par Description:
     assignment operator. This operator is used to assign an int value to current object.
     \param value  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(int value);
  /**
     \par Description:
     assignment operator. This operator is used to assign an int64 value to current object.
     \param value  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(ScsINT64 value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a float value to current object.
     \param value  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(float value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a double value to current object.
     \param value  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(double value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a string value to current object.
     \param value  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(const char* value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a wide string value to current object.
     \param value}  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(const wchar_t* value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a timeval value to current object.
     \param value  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(timeval value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a pointer value to current object.
     \param value  [in]: the value to assign.
     \par Return values:
     current object.
    */
  OlsField& operator=(void* value);
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsField</em> object into an output stream. The field is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore the <em>OlsField</em> object from an input stream. The field is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);
  //@}

private:
  char* _fieldName;
  ScsData    _data;
};


extern OLSI_API SCS_SL_STD(ostream)& operator<<(SCS_SL_STD(ostream)& os, const OlsField& field);

class OlsList;
class OlsSimpleList;
class OlsCollectableList;
class OlsFieldCriteria;
class OlsFieldList;
class OlsDataSet;

/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store a value into an element of a list. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsList</em> class) groups a set of objects containing the same kind of information. An object of <em>OlsData</em> class contains a set of <em>OlsField</em> objects.
\code#include "olstypes.h"\endcode
*/

class ScsOlsData;

class OLSI_API OlsData
{
public:
  friend class OlsList;
  friend class OlsSimpleList;
  friend class OlsCollectableList;
  friend class OlsFieldCriteria;
  /**@name Typedefs / enums*/
  //@{
  /**
      \par Description:
     this enum defines the values indicating if the data is created, modified od deleted when modifying a list.
      \code
      enum Mode {
        UNKNOWN = 0,
        CREATION,
        UPDATE,
        DELETION
      }; \endcode
      \par Values:
      \li \c UNKNOWN:  the data is unknown,
      \li \c CREATION:  the data has been inserted in the list,
      \li \c UPDATE:  the data has been modified in the list,
      \li \c DELETION:  the data has been removed from the list.
  */
  enum Mode {
    UNKNOWN = 0,
    CREATION,
    UPDATE,
    DELETION
  };
  //@}

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This constructor is a SCADAsoft internal method. Do not use it, use <em>OlsDataSet::newData()</em> instead.
  */
  OlsData(int key, Mode mode, OlsDataSet* dataSet);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsData();
  //@}

  /**@name General member functions*/
  //@{

  
  /**
     \par Description:
     this function returns the key of the data in the list.
     \par Parameters:
     none.
     \par Return values:
     the data key.
  */
  OlsDataSet * getDataSet();
  int getKey() const;
  /**
     \par Description:
     this function sets the key of the data in the list.
     \param key  [in]: the data key.
     \par Return values:
     none.
  */
  void setKey(const int key);
  /**
     \par Description:
     this function returns the mode of the table object. The mode is used when modifying a list.
     \par Parameters:
     none.
     \par Return values:
     the data mode.
  */
  Mode getMode() const;
  /**
     \par Description:
     this function sets the mode of the data. The mode is used when modifying a list.
     \param mode  [in]: the mode.
     \par Return values:
     none.
  */
  void setMode(const Mode mode);
  /**
     \par Description:
     this function returns the data field number.
     \par Parameters:
     none.
     \par Return values:
     the field number.
  */
  int getFieldCount() const;
  /**
     \par Description:
     this function copie the field corresponding to the specified position.
     \param pos  [in]: the index of the wished field,
     \param field  [out]: object receiving the resulting field,
     \par Return values:
     the parameter <em>field</em> is filled with the specified field. 
  */
  void getField(int pos, OlsField& field);
  /**
     \par Description:
     this function returns a copy of the field corresponding to the specified name.
     \param name  [in]: the name of the field.
     \par Return values:
     a copy field object.
  */
  OlsField getField(const char* name) const;
  /**
     \par Description:
     this function sets the value of the specified field of the data. The field is specified by the <em>name</em> parameter.
     \param name  [in]: the field name,
     \param data  [in]: an <em>ScsData</em> object containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if no field was found matching the name or if the found field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const char* name, const ScsData& data);
  /**
     \par Description:
     this function sets the value of the field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: an <em>ScsData</em> object containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(int pos, const ScsData& data);
  /**
     \par Description:
     this function sets the value of an integer field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: an <em>integer</em> containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const int & pos, const int & data);
  /**
     \par Description:
     this function sets the value of an integer field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: an <em>integer64</em> containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const int & pos, ScsINT64 data);

  /**
     \par Description:
     this function sets the value of a float field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: a <em>float</em> containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const int & pos, const float & data);
  /**
     \par Description:
     this function sets the value of a float field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: a <em>double</em> containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const int & pos, double data);

  /**
     \par Description:
     this function sets the value of a string field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: a <em>string</em> containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const int & pos, const char * data);

  /**
     \par Description:
     this function sets the value of a wide string field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: a <em>string</em> containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const int & pos, const wchar_t * data);

  /**
     \par Description:
     this function sets the value of a timeval field at position <em>pos</em> in the data.
     \param pos  [in]: the field position,
     \param data  [in]: a <em>timeval</em> containing the value to set.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if the position of the field is not correct or if the <em>pos</em>th field type is not the same as the <em>data</em> type.
  */
  ScsStatus setValue(const int & pos, const timeval & data);
  //@}

  /**@name Operators / cast*/
  //@{
  /**
     \par Description:
     assignment operator. This operator is used to assign an <em>OlsData</em> object to current object.
     \param data  [in]: the data object to assign.
     \par Return values:
     current object.
    */
  OlsData& operator=(const OlsData& data);
  /**
     \par Description:
     this operator returns a temporary copy of the field at position <em>pos</em>. Copy it if you want to keep it.
     \param pos  [in]: the field position.
     \par Return values:
     a temporary copy of the field object.
    */
  OlsField* operator[](int pos) const;
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsFields</em> objects of the data into an output stream. The data is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore the <em>OlsField</em> objects of a data from an input stream. The data is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);
//@}

  int compareTo(OlsData* olsdata, int pos);
  ScsOlsData* getScsOlsData() const;
  bool isModified();
  void setModified(bool modified);

private:
    ScsOlsData* _scsOlsData;
};


extern OLSI_API SCS_SL_STD(ostream)& operator<<(SCS_SL_STD(ostream)& os, const OlsData& data);

class OlsDataList;

/**
\code#include "olstypes.h"\endcode
   Prototype of the function which is called by an Ols server to notify a client subscribed on a list (see <em>OlsServer::subscribe()</em>), about the changes which occurred on this list.
   \param listName  [in]: name of the list,
   \param id  [in]: subscription id,
   \param dataSet  [in]: dataset containing the data created, modified or deleted,
   \param arg  [in]: user optional argument passed as parameter of the callback when called.
   \par Return values:
     none.
*/
typedef void (*OlsCallback)(const char *      listName,
			    int               id,
			    const OlsDataSet& dataSet,
			    void *            arg);

/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to store a value into an element of a list. An object (object of <em>OlsData</em> class) represents a set of basic data (object of <em>OlsField</em> class). An object list (object of <em>OlsList</em> class) groups a set of objects containing the same kind of information. An object of <em>OlsDataSet</em> class contains a set of <em>OlsField</em> objects.
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsDataSet
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates an empty data set on the server side. If the <em>release</em> parameter is set to 0, all data inserted in the dataset are not duplicated.
     \param nbFields  [in]: the number of fields,
     \param fieldList  [in]: list of field objects,
     \param release  [in]: flag specifying if the data inserted are duplicated or not.
     \par Return values:
     none.
  */
  OlsDataSet(int nbFields = 0, OlsField* fieldList = 0, int release = 1);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsDataSet();
  //@}
  
  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function adds a field in the dataset. The value of the field is the default one. This function does nothing if a data has already been inserted in the dataset.
     \param field  [in]: the field to insert.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if a data has already been inserted in the dataset.
  */
  ScsStatus addField(const OlsField& field);
  /**
     \par Description:
     this function adds a set of fields in the dataset. The fields are pointed by the <em>fieldList</em> parameter. The number of fields is specified by the <em>count</em> parameter. The value of the fields is the default one. This method does nothing if a data has already been inserted in the dataset.
     \param fieldList  [in]: the list of fields to insert.
     \param count  [in]: the number of fields.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : if a data has already been inserted in the dataset.
  */
  ScsStatus addFields(const OlsField* const fieldList, int count);
  /**
     \par Description:
     this function returns the number of fields.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */
  int getFieldCount() const;
  /**
     \par Description:
     this function returns the position in the dataset of the field specified by the <em>name</em> parameter.
     \param name  [in]: the field name.
     \par Return values:
     the field index.
  */
  int getFieldIndex(const char* name) const;
  const OlsField* getFieldList() const { return _fieldList;};  
  /**
     \par Description:
     this function returns the field at position <em>pos</em>. It returns NULL if <em>pos</em> is superior to the number of fields of the list.
     \param pos  [in]: the field position.
     \par Return values:
     the field object at position <em>pos</em>.
  */
   const OlsField* getField(int pos) const;
  /**
     \par Description:
     this function adds a data to the data set and returns it.
     \param key  [in]: the key of the data,
     \param mode  [in]: the modification mode of the data.
     \par Return values:
     the field object at position <em>pos</em>.
  */
  OlsData* newData(int key = 0, OlsData::Mode mode = OlsData::CREATION);
  /**
     \par Description:
     this function returns the number of data in the dataset.
     \par Parameters:
     none.
     \par Return values:
     the number of data.
  */
  int getDataCount() const;
  OlsDataList* getDataList() const { return _dataList;};  
  /**
     \par Description:
     this function removes and deletes all data of the dataset.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus clearData();
  //@}
  
  /**@name Operators / cast*/
  //@{
  /**
     \par Description:
     this operator returns the data at position <em>pos</em> in the dataset.
     \param pos  [in]: the data position.
     \par Return values:
     the <em>pos</em>th data.
  */
  OlsData* operator[](int pos) const;
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsData</em> objects of the dataset into an output stream. The dataset is saved into a string in order to be passed over the network. If <em>first</em> parameter is set to a value different from its default value, the data objects are saved starting at <em>first</em> position. If the <em>count</em> parameter is set to a value different from its default value, only <em>count</em> data are saved.
     \param os  [in]: the output stream,
     \param first  [in]: starting position,
     \param count  [in]: number of data to save.
     \par Return values:
     none.
    */
  virtual void save(SCS_SL_STD(ostream)& os, int first = 0, int count = -1) const;
  /**
     \par Description:
     this function is used to restore the <em>OlsData</em> objects of a dataset from an input stream. The dataset is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);
  /**
     \par Description:
     this function is used to reload a dataset from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void reload(SCS_SL_STD(istream)& is);
  /**
     \par Description:
     this function is used to reload a dataset from an input stream with a limited number of elements
     \param is  [in]: the input stream.
     \param nbMaxElmtsToReload [in]: maximum number of elements to reload
     \par Return values:
     none.
    */
  virtual void reload(SCS_SL_STD(istream)& is, int nbMaxElmtsToReload);
  /**
     \par Description:
     this function is used to check if a dataset has same fields than another.
     \param dataSet  [in]: the dataset to test
     \par Return values:
     none.
    */
  int          sameFields(OlsDataSet *dataSet);
  //@}

  int extendFieldList(unsigned int size = 1);
  void emptyFieldList();
  
private:
  void saveFieldList(SCS_SL_STD(ostream)&) const;
  void restoreFieldList(SCS_SL_STD(istream)&);
  ScsStatus reloadFieldList(SCS_SL_STD(istream)&);
  
  int          _release;
  OlsDataList *_dataList;
  int          _nbField;
  OlsField    *_fieldList;
  int          _capacity;
  static int   _ExtendCapacity;

  friend class OlsList;
  friend class OlsSimpleList;
  friend class OlsCollectableList;
};



class OlsDataListIterator;

/**
   \brief This class allows sequential access to all elements of a OlsDataSet.

The <em>OlsDataSetIterator</em> class is useful to get the values after reading when the OlsDataSet is quite large.
\code#include "dbm.h"\endcode
*/
class OLSI_API OlsDataSetIterator
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an iterator. Immediately after construction, the position of the iterator is undefined.
     \param dataSet  [in]: the OlsDataSet you want to iterate to. 
  */
  OlsDataSetIterator(OlsDataSet& dataSet);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~OlsDataSetIterator();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     Move the iterator to the next item and return it.
     \par Return values:
     Returns 0 if it is at the end of the collection, else returns the next item.
  */
  OlsData* operator()();

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
  OlsData* key() const;

  /**
     \par Description:
     Resets the iterator to its initial state. The current item is undefined.
  */
  void reset();

  //@}

 private:
  OlsDataListIterator* _it;
};


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to filter the data in case of reading or subscribing request on a data list. For each such request, the client can specify a filter. A filter is composed of a field list and contains also a criteria (see <em>OlsFilter</em> class). A criteria is a logical combination (NOT, AND or OR) of elementary conditions than the data must fulfill for it to be part of the request result. An elementary condition is made of a field name, an operation and a comparison value. The <em>OlsCriteria</em> class is the mother class of <em>OlsAndCriteria</em>, <em>OlsOrCriteria</em>, <em>OlsNotCriteria</em> and <em>OlsFieldCriteria</em> classes. An <em>OlsCriteria</em> represents SQL like WHERE clause. For example: &quot;<em>(Color == red OR Color == blue) AND Size > 10</em>&quot;
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsCriteria
{
public:
  /**@name Typedefs / enums*/
  //@{
  /**
      \par Description:
     this enum specifies the type of the criteria.
      \code
      enum Type {
        UNKNOWN = 0,
        AND,
        OR,
        FIELD,
        NOT
      }; \endcode
      \par Values:
      \li \c UNKNOWN:  the criteria is unknown,
      \li \c AND:  the criteria is an <em>OlsAndCriteria</em>,
      \li \c OR:  the criteria is an <em>OlsOrCriteria</em>,
      \li \c FIELD:  the criteria is an <em>OlsFieldCriteria</em>.
      \li \c NOT:  the criteria is an <em>OlsNotCriteria</em>.
  */
  enum Type {
    UNKNOWN = 0,
    AND,
    OR,
    FIELD,
    NOT
  };
  //@}

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsCriteria() {}
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function tests if the data matches the criteria.
     \param data  [in]: the data to examine.
     \par Return values:
     1 if the data matches the criteria, 0 otherwise.
  */
  virtual int match(const OlsData& data) const = 0;
  /**
     \par Description:
     this function returns the type of the criteria.
     \par Parameters:
     none.
     \par Return values:
     the criteria type.
  */
  virtual Type getType() const { return UNKNOWN;};
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsCriteria</em> object into an output stream. The criteria is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore an <em>OlsCriteria</em> object from an input stream. The criteria is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);
  /**
     \par Description:
     this function is used to restore an <em>OlsCriteria</em> object from an input stream. The criteria is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  static OlsCriteria* restoreCriteria(SCS_SL_STD(istream)& is);  
  //@}

  /**@name Static methods*/
  //@{
  /**
     \par Description:
     this function parses the string argument and produces a criteria tree. The string grammar is a simplified SQL WHERE clause.
<PRE>
criteria ::= field_name operation value
           | criteria <b>AND</b> criteria
           | criteria <b>OR</b> criteria
           | <b>NOT</b> criteria
           | <b>(</b> criteria <b>)</b>
operation ::= <b>\>=</b> | <b>\></b> | <b>\<=</b> | <b>\<</b> | <b>==</b> | <b>!=</b> | <b>\&</b> | <b>|</b> | <b>LIKE</b>
field_name ::= identifier
value ::= numerical_constant | string_constant
</PRE>
The LIKE operator allows to match a string field whith a reguler expression.
     \param criteria  [in]: the input string criteria.
     \par Return values:
     The criteria object.
    */
  static OlsCriteria* Parse(const char* criteria);
  //@}
};


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to filter the data in case of reading or subscribing request on a data list. For each such request, the client can specify a filter. A filter is composed of a field list and contains also a criteria (see <em>OlsFilter</em> class). A criteria is a logical combination (NOT, AND or OR) of elementary conditions than the data must fulfill for it to be part of the request result. An elementary condition is made of a field name, an operation and a comparison value. The <em>OlsAndCriteria</em> inherits from the <em>OlsCriteria</em> class. An <em>OlsCriteria</em> represents SQL like WHERE clause. For example: &quot;<em>(Color == red OR Color == blue) AND Size > 10</em>&quot;
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsAndCriteria : public OlsCriteria
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates an empty AND criteria.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  OlsAndCriteria();
  /**
     \par Description:
     constructor. It creates an AND criteria with two operand criterias. The <em>left</em> and <em>right</em> parameters are copied.
     \param left  [in]: left operand criteria,
     \param right  [in]: right operand criteria.
     \par Return values:
     none.
  */
  OlsAndCriteria(const OlsCriteria& left, const OlsCriteria& right);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsAndCriteria() { delete _left; delete _right;}
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function returns the left operand of the AND criteria.
     \par Parameters:
     none.
     \par Return values:
     the left operand criteria.
  */
  const OlsCriteria* getLeft() const {return _left;};
  /**
     \par Description:
     this function returns the right operand of the AND criteria.
     \par Parameters:
     none.
     \par Return values:
     the right operand criteria.
  */
  const OlsCriteria* getRight() const {return _right;};
  /**
     \par Description:
     this function tests if the data matches the criteria.
     \param data  [in]: the data to examine.
     \par Return values:
     1 if the data matches the criteria, 0 otherwise.
  */
  virtual int match(const OlsData& data) const 
    { return _left->match(data) && _right->match(data);};
  /**
     \par Description:
     this function returns the type of the criteria.
     \par Parameters:
     none.
     \par Return values:
     the criteria type.
  */
  virtual Type getType() const { return AND;};
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsAndCriteria</em> object into an output stream. The criteria is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
  */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore an <em>OlsAndCriteria</em> object from an input stream. The criteria is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);  
  //@}

private:
  OlsCriteria *_left;
  OlsCriteria *_right;
};

/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to filter the data in case of reading or subscribing request on a data list. For each such request, the client can specify a filter. A filter is composed of a field list and contains also a criteria (see <em>OlsFilter</em> class). A criteria is a logical combination (NOT, AND or OR) of elementary conditions than the data must fulfill for it to be part of the request result. An elementary condition is made of a field name, an operation and a comparison value. The <em>OlsNotCriteria</em> inherits from the <em>OlsCriteria</em> class. An <em>OlsCriteria</em> represents SQL like WHERE clause. For example: &quot;<em>(Color == red OR Color == blue) AND Size > 10</em>&quot;
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsNotCriteria : public OlsCriteria
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates an empty NOT criteria.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  OlsNotCriteria();
  /**
     \par Description:
     constructor. It creates an NOT criteria with one operand criteria. The <em>pCriteria</em> parameter are copied.
     \param pCriteria  [in]: operand criteria,
     \par Return values:
     none.
  */
  OlsNotCriteria(const OlsCriteria& pCriteria);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsNotCriteria() { delete _criteria;}
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function returns the operand of the NOT criteria.
     \par Parameters:
     none.
     \par Return values:
     the operand criteria.
  */
  const OlsCriteria* getCriteria() const {return _criteria;};
  /**
     \par Description:
     this function tests if the data matches the criteria.
     \param data  [in]: the data to examine.
     \par Return values:
     1 if the data matches the criteria, 0 otherwise.
  */
  virtual int match(const OlsData& data) const 
    { return !(_criteria->match(data));};
  /**
     \par Description:
     this function returns the type of the criteria.
     \par Parameters:
     none.
     \par Return values:
     the criteria type.
  */
  virtual Type getType() const { return NOT;};
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsNotCriteria</em> object into an output stream. The criteria is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
  */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore an <em>OlsNotCriteria</em> object from an input stream. The criteria is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);  
  //@}

private:
  OlsCriteria *_criteria;
};


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to filter the data in case of reading or subscribing request on a data list. For each such request, the client can specify a filter. A filter is composed of a field list and contains also a criteria (see <em>OlsFilter</em> class). A criteria is a logical combination (NOT, AND or OR) of elementary conditions than the data must fulfill for it to be part of the request result. An elementary condition is made of a field name, an operation and a comparison value. The <em>OlsOrCriteria</em> inherits from the <em>OlsCriteria</em> class. An <em>OlsCriteria</em> represents SQL like WHERE clause. For example: &quot;<em>(Color == red OR Color == blue) AND Size > 10</em>&quot;
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsOrCriteria : public OlsCriteria
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates an empty OR criteria.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  OlsOrCriteria();
  /**
     \par Description:
     constructor. It creates an OR criteria with two operand criterias. The <em>left</em> and <em>right</em> parameters are copied.
     \param left  [in]: left operand criteria,
     \param right  [in]: right operand criteria.
     \par Return values:
     none.
  */
  OlsOrCriteria(const OlsCriteria& left, const OlsCriteria& right);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsOrCriteria() {delete _left; delete _right;}
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function returns the left operand of the OR criteria.
     \par Parameters:
     none.
     \par Return values:
     the left operand criteria.
  */
  const OlsCriteria* getLeft() const { return _left;};
  /**
     \par Description:
     this function returns the right operand of the OR criteria.
     \par Parameters:
     none.
     \par Return values:
     the right operand criteria.
  */
  const OlsCriteria* getRight() const { return _right;};
  /**
     \par Description:
     this function tests if the data matches the criteria.
     \param data  [in]: the data to examine.
     \par Return values:
     1 if the data matches the criteria, 0 otherwise.
  */
  virtual int match(const OlsData& data) const 
    { return _left->match(data) || _right->match(data);};
  /**
     \par Description:
     this function returns the type of the criteria.
     \par Parameters:
     none.
     \par Return values:
     the criteria type.
  */
  virtual Type getType() const {return OR;};
  //@}
  
  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsOrCriteria</em> object into an output stream. The criteria is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
  */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore an <em>OlsOrCriteria</em> object from an input stream. The criteria is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);  
  //@}

private:
  OlsCriteria *_left;
  OlsCriteria *_right;
};


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to filter the data in case of reading or subscribing request on a data list. For each such request, the client can specify a filter. A filter is composed of a field list and contains also a criteria (see <em>OlsFilter</em> class). A criteria is a logical combination (NOT, AND or OR) of elementary conditions than the data must fulfill for it to be part of the request result. An elementary condition is made of a field name, an operation and a comparison value. The <em>OlsFieldCriteria</em> inherits from the <em>OlsCriteria</em> class. An <em>OlsCriteria</em> represents SQL like WHERE clause. For example: &quot;<em>(Color == red OR Color == blue) AND Size > 10</em>&quot;
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsFieldCriteria : public OlsCriteria
{
public:
  /**@name Typedefs / enums*/
  //@{
  /**
      \par Description:
     this enum specifies the comparison to be made between the value of the field in the <em>OlsFieldCriteria</em> and the value of a field in the list.
      \code
      enum Operation {
        UNKNOWN = 0,
        EQUAL, 
        LESS_OR_EQUAL, 
        LESS, 
        GREATER, 
        GREATER_OR_EQUAL, 
        NOT_EQUAL,
        LOGICAL_AND,
        LOGICAL_OR,
        STRING_MATCH
      }; \endcode
  */
  enum Operation {
    UNKNOWN = 0,
    EQUAL, 
    LESS_OR_EQUAL, 
    LESS, 
    GREATER, 
    GREATER_OR_EQUAL, 
    NOT_EQUAL,
    LOGICAL_AND,
    LOGICAL_OR,
    STRING_MATCH
  };
  //@}

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates an empty FIELD criteria.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  OlsFieldCriteria();
  /**
     \par Description:
     constructor.  The value of the field is the value to be compared to.
     \param field  [in]: field containing the value to be compared to,
     \param operation  [in]: comparison operation.
     \par Return values:
     none.
  */
  OlsFieldCriteria(const OlsField& field, Operation operation);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsFieldCriteria();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function returns the field to be compared to.
     \par Parameters:
     none.
     \par Return values:
     the field to be compared to.
  */
  const OlsField* getField() const { return _field;};
  /**
     \par Description:
     this function returns the comparison operation of the criteria.
     \par Parameters:
     none.
     \par Return values:
     the comparison operation.
  */
  Operation getOperation() const { return _operation;};
  /**
     \par Description:
     this function tests if the data matches the criteria.
     \param data  [in]: the data to examine.
     \par Return values:
     1 if the data matches the criteria, 0 otherwise.
  */
  virtual int match(const OlsData& data) const;
  /**
     \par Description:
     this function returns the type of the criteria.
     \par Parameters:
     none.
     \par Return values:
     the criteria type.
  */
  virtual Type getType() const {return FIELD;};
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsFieldCriteria</em> object into an output stream. The criteria is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
  */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore an <em>OlsFieldCriteria</em> object from an input stream. The criteria is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);  
  //@}

  void setIndex(int index) { _index = index;};

private:
  void*      _regexp;
  OlsField  *_field;
  Operation  _operation;
  int        _index;
};


/**
   \brief This class is one of the class of the <em>OLS</em> (Object List Server) SCADAsoft component.

   This class is used to filter the data in case of reading or subscribing request on a data list. For each such request, the client can specify a filter. A filter is composed of a field list and contains also a criteria (see <em>OlsCriteria</em>, <em>OlsAndCriteria</em>, <em>OlsOrCriteria</em> or <em>OlsFieldCriteria</em> classes). A criteria is a logical combination (NOT, AND or OR) of elementary conditions than the data must fulfill for it to be part of the request result. An elementary condition is made of a field name, an operation and a comparison value.
\code#include "olstypes.h"\endcode
*/
class OLSI_API OlsFilter
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates a filter object used to read or subscribe to a list. It contains a criteria to be applied to the list data and a set of fields of interest. If the data matches the filter, all fields in filter set of fields are sent back to the caller. A filter can have a name to be registered within the list server (to be eventually reused later).
     \param name  [in]: optional name of the filter,
     \param criteria  [in]: optional criteria.
     \par Return values:
     none.
  */
  OlsFilter(const char *name = "", const OlsCriteria *criteria = 0);
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~OlsFilter();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function adds field in the list of fields to be sent back.
     \param field  [in]: the field to add.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus add(const OlsField& field);
  /**
     \par Description:
     this function returns the name of the filter if any, NULL otherwise.
     \par Parameters:
     none.
     \par Return values:
     the name of the filter, if any.
  */
   const char* getName() const;
  /**
     \par Description:
     this function returns the criteria of the filter.
     \par Parameters:
     none.
     \par Return values:
     the criteria of the filter.
  */
  const OlsCriteria* getCriteria() const { return _criteria;};
  /**
     \par Description:
     this function modifies the criteria of the filter.
     \param criteria  [in]: the new value of the criteria.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus setCriteria(const OlsCriteria *criteria);
  /**
     \par Description:
     this function returns the number of fields in the filter.
     \par Parameters:
     none.
     \par Return values:
     the number of fields.
  */
  int getFieldCount() const;
  OlsFieldList* getFieldList() const { return _fieldList;};
  //@}
  
  /**@name Operators / cast*/
  //@{
  /**
     \par Description:
     assignment operator. This operator is used to assign an <em>OlsFilter</em> object to current object.
     \param filter  [in]: the filter object to assign.
     \par Return values:
     current object.
    */
  OlsFilter& operator=(const OlsFilter& filter);
  /**
     \par Description:
     Test the logical equivalence between the current filter and the passed one.
     \param filter  [in]: filter object to compare with current one
     \par Return values:
     logical result of the comparison
  */
  int operator==(const OlsFilter& filter) const;
  /**
     \par Description:
     this operator returns the field at position <em>pos</em> in the filter.
     \param pos  [in]: the field position.
     \par Return values:
     the <em>pos</em>th field.
  */
  const OlsField* operator[](int pos) const;
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>OlsFilter</em> object into an output stream. The filter is saved into a string in order to be passed over the network.
     \param os  [in]: the output stream.
     \par Return values:
     none.
  */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore an <em>OlsFilter</em> object from an input stream. The filter is restored from a string after having been passed over the network.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual void restore(SCS_SL_STD(istream)& is);
  //@}
  
private:
  char         *_name;
  OlsCriteria  *_criteria;
  OlsFieldList *_fieldList;    
};


class RWCString;
class OlsFilterList;
class OlsSubscriptionList;
class OlsSubscription;
class OlsListList;
class OlsHashTable;
class ScsLock;
class OlsThreadArgList;
class OlsUnsubscribeToDo;
struct ScsMessageTag;
class ImgMsgTag;
class OlsRplRecordMgr;
    


typedef SCS_SL_STD(vector)<OlsData*> OlsDataVector;
class OLSI_API OlsDataList
{
 public:
  OlsDataList (size_t initialSize = 10000, size_t allocationSize = 1000);
  OlsDataList ( const OlsDataList& list);
  ~OlsDataList ();

  OlsData* append(OlsData* data);
  void  apply( void (*ap)(OlsData*, void*), void* x);
  OlsData* at(size_t i);
  OlsData* at(size_t i) const;
  void clear();  
  bool contains ( bool (*t) ( const OlsData*, const void*), const void* a) const;
  bool containsReference(  const OlsData* data ) const;
  size_t entries();
  OlsData* find(bool (*t)(const OlsData*, const void*), const void* a) const;
  OlsData* findReference(const OlsData* a) const;
  OlsData* first() const;
  OlsData* get();
  OlsData* insert(OlsData* a);
  OlsData* insertAt(size_t i, OlsData* a);
  bool isEmpty ();
  OlsData* last() const;
  size_t occurrencesOf(bool (*t)(const OlsData*, const void*), const void* a) const;
  size_t occurrencesOfReference(const OlsData* a) const;
  OlsDataList& operator=(const OlsDataList& s);
  OlsData* prepend(OlsData* a);
  OlsData* remove(bool(*t)(const OlsData*, const void*), const void* a);
  OlsData* removeReference(const OlsData* a);
  void checkCapacity();
 public:
  OlsDataVector _vector;
  size_t _allocatedSize;
  size_t _initialSize;
};


class  OLSI_API OlsDataListIt
{
 public:	
  OlsDataListIt (OlsDataList& s);
  ~OlsDataListIt ();

  void operator++();
  void operator+=(size_t n);
  OlsData* operator()();


  bool atFirst();
  bool atLast();

  OlsData* findNext(bool(*t)(const OlsData*, const void*), const void* a);
  OlsData* findNextReference(const OlsData* a);
  OlsData* insertAfterPoint(OlsData* a);

  OlsData* key();

  OlsData* remove(); 
  OlsData* removeNext(bool (*t)(const OlsData*, const void*), const void* a);
  OlsData* removeNextReference(const OlsData* a);

  void reset();
  
  void toFirst();
  void toLast();
public:

  OlsDataList* _list;
  OlsDataVector::iterator _it;
  size_t _pos;
  
};


class OLSI_API OlsDataListIterator : public OlsDataListIt
{
 public:
  OlsDataListIterator(OlsDataList& list) : OlsDataListIt (list) {}
 
  ~OlsDataListIterator() {}
};




#endif
