//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsdata.h                                              */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Fri Aug  4 14:43:41 2000                               */
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


#ifndef _SCS_SCSDATA_H_
#define _SCS_SCSDATA_H_

/** \file
    \brief General Purpose Scadasoft datatype definitions.
*/

//{begin internal}
// error handling
#define ScsStatus	AntStatus
#define ScsError	AntError
#define ScsValid	AntValid
#define SCS_INFO	ANT_INFO
#define SCS_WARNING	ANT_WARNING
#define SCS_FATAL	ANT_FATAL
#define ScsDetection	AntDetection
#define ScsPropagation	AntPropagation

#ifdef _SCSTRACE_
#define _ANTRACE_
#endif

#ifdef WIN32
// include winsock
#if _MSC_VER > 1200
#include <winsock2.h>
#endif
#include <windows.h>
#pragma warning(push)
#pragma warning(disable: 4275)
#include <complex>
#pragma warning(pop)
#else
#include <time.h>
#include <sys/time.h>
#include <wchar.h>
#endif

#include "ant/trace.h"
#include "ant/status.h"
#include "scsdefs.h"
//{end internal}

typedef void * ScsAny;

#ifdef WIN32
typedef _int64 ScsINT64;
#else
#if defined(HPUX11) && defined(__LP64__)
typedef long ScsINT64;
#else
typedef long long ScsINT64;
#endif
#endif

class ScsAddress;

/**
   \code#include "scs.h"\endcode
   This enum represents the type of the data stored in an <em>ScsData</em> object.
   The possible values are the following :
   \code
   enum ScsType {
     ScsUNKNOWN = 0,
     ScsINTEGER,
     ScsFLOAT,
     ScsSTRING,
     ScsWSTRING,
     ScsTIME,
     ScsPOINTER,
     ScsBIT,
     ScsCOMPLEX,
     ScsREFERENCE,
     ScsVECTOR,
     ScsTABLE,
     ScsLONGLONG,
     ScsDOUBLE,
     ScsUNAUTHORIZED
   }; \endcode
*/
enum ScsType {
  ScsUNKNOWN = 0,
  ScsINTEGER,
  ScsFLOAT,
  ScsSTRING,
  ScsWSTRING,
  ScsTIME,
  ScsPOINTER,
  ScsBIT,
  ScsCOMPLEX,
  ScsREFERENCE,
  ScsVECTOR,
  ScsTABLE,
  ScsLONGLONG,
  ScsDOUBLE,
  ScsUNAUTHORIZED
};

/**
   \brief This class represents a database value.

   The class <em>ScsData</em> represents a database value, which can be of type scalar, vector or table. It is composed of a type and a buffer. For a scalar or vector value, there is only one type; for a table value, there is one type for each field. The database values are stored in the buffer under the form of records and fields. For a scalar attribute, there is only 1 record with 1 field. For a vector attribute, there is <em>n</em> records (n > 1) with only 1 field. All the records are of the same type. For a table attribute, there is <em>n</em> records (n > 1) with <em>m</em> fields (m > 1), and one proper type for each field.
\code#include "scs.h"\endcode
*/
class SCS_API ScsData
{
public:
  /**@name Typedefs / defines*/
  /*@{*/
  /**
      \par Description:
     enum corresponding to the possible values for the type of an attribute.
      \code
      enum AttributeType {
         SCS_SCALAR = 0,
	 SCS_VECTOR,
	 SCS_TABLE
      }; \endcode
      \par Values:
      \li \c SCS_SCALAR:  the attribute type is scalar,
      \li \c SCS_VECTOR:  the attribute type is vector,
      \li \c SCS_TABLE:  the attribute type is table.
  */
  enum AttributeType { 
    SCS_SCALAR = 0,
    SCS_VECTOR,
    SCS_TABLE
  };
  //@}

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It initializes an empty <em>ScsData</em> of scalar type. Its type is set to <em>ScsUNKNOWN</em> and its buffer to NULL.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ScsData();

  /**
     \par Description:
     copy constructor.
     \param data  [in]: the <em>ScsData</em> object to copy. 
     \par Return values:
     none.
  */
  ScsData(const ScsData &data);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for an integer value. Its type is set to <em>ScsINTEGER</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: an integer value. 
     \par Return values:
     none.
  */
  ScsData(int value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for an integer 64 value. Its type is set to <em>ScsINTEGER</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: an integer value. 
     \par Return values:
     none.
  */
  ScsData(ScsINT64 value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a float value. Its type is set to <em>ScsFLOAT</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a float value. 
     \par Return values:
     none.
  */
  ScsData(float value);
  
  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a double value. Its type is set to <em>ScsFLOAT</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a float value. 
     \par Return values:
     none.
  */
  ScsData(double value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a string value. Its type is set to <em>ScsSTRING</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a string value. 
     \par Return values:
     none.
  */
  ScsData(const char *value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a wide string value. Its type is set to <em>ScsWSTRING</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a wide string value. 
     \par Return values:
     none.
  */
  ScsData(const wchar_t *value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a timeval structure value. Its type is set to <em>ScsTIME</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a timeval structure value. 
     \par Return values:
     none.
  */
  ScsData(timeval value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a pointer value. Its type is set to <em>ScsPOINTER</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a pointer value. 
     \par Return values:
     none.
  */
  ScsData(void *value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a bit field value. Its type is set to <em>ScsBIT</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a buffer containing the bit field value. 
     \param size  [in]: the size of the buffer in bytes. 
     \par Return values:
     none.
  */
  ScsData(const unsigned char *value, const unsigned int size);

#ifdef WIN32
  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a complex value. Its type is set to <em>ScsCOMPLEX</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a complex value. 
     \par Return values:
     none.
  */
  ScsData(std::complex<float> value);
#endif

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of scalar type for a reference value. Its type is set to <em>ScsREFERENCE</em> and its buffer to the <em>value</em> parameter.
     \param value  [in]: a reference value. 
     \par Return values:
     none.
  */
  ScsData(ScsAddress value);

  /**
     \par Description:
     constructor. It initializes an <em>ScsData</em> of vector or table type. Its type is set to <em>ScsBIT</em> and its buffer to the <em>value</em> parameter.
     \param nbRecords  [in]: the number of records. 
     \param nbFields  [in]: the number of fields (always 1 for a vector). 
     \param fieldTypes  [in]: the list of field types. 
     \param fieldSizes  [in]: the list of field sizes (only the size for an ScsSTRING, ScsWSTRING or ScsBIT element is useful). 
     \par Return values:
     none.
  */
  ScsData(const int           nbRecords,
	  const int           nbFields,
	  const ScsType      *fieldTypes,
	  const unsigned int *fieldSizes);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~ScsData();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the data structure (its type, <em>SCS_SCALAR</em>, <em>SCS_VECTOR</em> or <em>SCS_TABLE</em>, its number of fields and its number of records).
     \param type  [out]: attribute type, <em>ScsData::SCS_SCALAR</em>, <em>ScsData::SCS_VECTOR</em> or <em>ScsData::SCS_TABLE</em> (see <em>ScsData::AttributeType</em> enumerate).
     \param fieldCount  [out]: the number of fields. This is always 1 for scalar and vector attributes (vectors are considered to occupy many records, but only one field).
     \param recordCount  [out]: the number of records. This is always 1 for a scalar attribute.
     \return
     \li \c ScsValid : success.
  */
  ScsStatus getDataStructure(AttributeType &type,
			     short         &fieldCount,
			     short         &recordCount) const;

  /**
     \par Description:
     returns the buffer containing the value(s) of the data. If the <em>recordId</em> and <em>fieldId</em> parameters are set, the pointer returned points to the part of the buffer containing the element corresponding to the specified record and field.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute). 
     \par Return values:
     a pointer to the buffer.
  */
   ScsAny getBuffer(int recordId = 0, int fieldId = 0) const;

  /**
     \par Description:
     returns the type of the data for a scalar or vector, or the type of the specified field for a table.
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute). 
     \par Return values:
     the type of the data.
  */
  ScsType getType(int fieldId = 0) const;

  /**
     \par Description:
     returns the number of records of the data (always 1 for a scalar).
     \par Parameters:
     none.
     \par Return values:
     the number of records.
  */
  int getNbRecords() const;

  /**
     \par Description:
     returns the number of fields of the data (always 1 for a scalar or a vector).
     \par Parameters:
     none.
     \par Return values:
     the number of fields.
  */
  int getNbFields() const;

  /**
     \par Description:
     returns the length (in bytes) of the element of the data corresponding to the specified field. For a scalar element, it corresponds to the length of the value of the element. For a vector element, it corresponds to the length of one record of the vector (a vector is considered to have only one field and many records, all of the same type). For a table element, it corresponds to the length of one element of the specified field.
     \param fieldId  [in]: a field identifier (0 to n-1, n being the number of fields of the attribute). For a scalar or vector element, the function can be called with the default value (0).
     \par Return values:
     the length of the element.
  */
  unsigned int length(int fieldId = 0) const;

  /**
     \par Description:
     set the value of an element of a vector or table to the specified integer value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
   void setValue(int recordId, int fieldId, int value);
   
  /**
     \par Description:
     set the value of an element of a vector or table to the specified integer64 value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
   void setValue(int recordId, int fieldId, ScsINT64 value);

  /**
     \par Description:
     set the value of an element of a vector or table to the specified float value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, float value);
  
  /**
     \par Description:
     set the value of an element of a vector or table to the specified double value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, double value);

  /**
     \par Description:
     set the value of an element of a vector or table to the specified string value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, const char *value);

  /**
     \par Description:
     set the value of an element of a vector or table to the specified wide string value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, const wchar_t *value);

  /**
     \par Description:
     set the value of an element of a vector or table to the specified timeval structure value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, timeval value);

  /**
     \par Description:
     set the value of an element of a vector or table to the specified pointer value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, void *value);

  /**
     \par Description:
     set the value of an element of a vector or table to the specified bit field value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the buffer containing the value to set. 
     \param size  [in]: the size of the value. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId,
		const unsigned char *value, const unsigned int size);

#ifdef WIN32
  /**
     \par Description:
     set the value of an element of a vector or table to the specified complex value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, std::complex<float> value);
#endif

  /**
     \par Description:
     set the value of an element of a vector or table to the specified reference value.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \param value  [in]: the value to set. 
     \par Return values:
     none.
  */
  void setValue(int recordId, int fieldId, ScsAddress value);

  /**
     \par Description:
     get the value of an element of a vector or table as an <em>ScsData</em>.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute).
     \par Return values:
     An <em>ScsData</em> containing the value of the element.
  */
  ScsData getValue(int recordId, int fieldId);

  /**
     \par Description:
     set the type of the data to <em>ScsUNAUTHORIZED</em> (useful only when the security is used).
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  void setUnauthorized();
  /**
     \par Description:
     test if the <em>ScsData</em> or the value pointed by <em>recordId</em> and <em>fieldId</em> is a null reference. 
     \param recordId  [in]:  a record identifier (0 to m-1, m being the number of fields of the attribute). 
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute). 
     \par Return values:
     1 if the test is true and 0 if the test is false.
  */
  int isNullReference(int recordId = 0, int fieldId = 0);
  //@}

  /**@name Operator / cast*/
  //@{
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar integer value to an int.
     \par Parameters:
     none.
     \par Return values:
     the integer value contained in the object.
    */
  operator int() const;
   /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar integer value to an int64.
     \par Parameters:
     none.
     \par Return values:
     the integer64 value contained in the object.
    */
  operator ScsINT64() const;
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar float value to a float.
     \par Parameters:
     none.
     \par Return values:
     the float value contained in the object.
    */
  operator float() const;
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar float value to a float.
     \par Parameters:
     none.
     \par Return values:
     the double value contained in the object.
    */
  operator double() const;
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar string value to a string.
     \par Parameters:
     none.
     \par Return values:
     the string value contained in the object.
    */
  operator const char *() const;
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar wide string value to a wide string.
     \par Parameters:
     none.
     \par Return values:
     the wide string value contained in the object.
    */
  operator const wchar_t *() const;
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar timeval value to a timeval.
     \par Parameters:
     none.
     \par Return values:
     the timeval value contained in the object.
    */
  operator timeval() const;
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar bit field value to a string not terminated by a NULL character. The size of the buffer is given by the <em>length</em> method.
     \par Parameters:
     none.
     \par Return values:
     the value contained in the object.
    */
  operator unsigned char *() const;

#ifdef WIN32
  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar complex value to a complex.
     \par Parameters:
     none.
     \par Return values:
     the value contained in the object.
    */
  operator std::complex<float>() const;
#endif

  /**
     \par Description:
     cast operator. This operator is used to cast an <em>ScsData</em> object containing a scalar reference value to a reference.
     \par Parameters:
     none.
     \par Return values:
     the value contained in the object.
    */
  operator ScsAddress() const;
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar int value to an <em>ScsData</em> object.
     \param value  [in]: int value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(int value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar int64 value to an <em>ScsData</em> object.
     \param value  [in]: int64 value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(ScsINT64 value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar float value to an <em>ScsData</em> object.
     \param value  [in]: float value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(float value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar double value to an <em>ScsData</em> object.
     \param value  [in]: double value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(double value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar string value to an <em>ScsData</em> object.
     \param value  [in]: string value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(const char *value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar wide string value to an <em>ScsData</em> object.
     \param value  [in]: wide string value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(const wchar_t *value);
   /**
     \par Description:
     assignment operator. This operator is used to assign a scalar timeval value to an <em>ScsData</em> object.
     \param value  [in]: timeval value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(timeval value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar pointer value to an <em>ScsData</em> object.
     \param value  [in]: pointer value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(void *value);
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar bit field value to an <em>ScsData</em> object. The <em>value</em> is considered to be a pointer to a <em>BitField</em> structure object.
     \param value  [in]: bit field value to assign.
     \par Return values:
     current object.
    */
  ScsData& operator=(unsigned char *value);

#ifdef WIN32
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar complex value to an <em>ScsData</em> object.
     \param value  [in]: complex value to assign.
     \par Return values:
     current object.
  */
  ScsData& operator=(std::complex<float> value);
#endif
  
  /**
     \par Description:
     assignment operator. This operator is used to assign a scalar reference value to an <em>ScsData</em> object.
     \param value  [in]: reference value to assign.
     \par Return values:
     current object.
  */
  ScsData& operator=(ScsAddress value);
  /**
     \par Description:
     assignment operator. This operator is used to assign the value of an <em>ScsData</em> object to another <em>ScsData</em> object.
     \param data  [in]: the data to assign.
     \par Return values:
     current object.
  */
  ScsData& operator=(const ScsData& data);
  /**
     \par Description:
     this method is used to force Vector ScsData.
     \param data  [in]: the data to assign.
     \par Return values:
     none.
  */
  void forceVector(const ScsData& data);
  /**
     \par Description:
     this method compares two ScsData objects and returns 1 if the value are equals. No type conversion is done. Data must be the same type.
     \param data  [in]: the data to compare.
     \par Return values:
     1 if equal, 0 otherwise.
  */
  int operator==(const ScsData& data) const;
  /**
     \par Description:
     this method compares two ScsData objects and returns 1 if the left value is less than the right value.  No type conversion is done. Data must be the same type.
     \param data  [in]: the data to compare.
     \par Return values:
     1 if less, 0 otherwise.
  */
  int operator<(const ScsData& data) const;
  /**
     \par Description:
     this method compares two ScsData objects and returns 1 if the left value is less or equal to the right value.  No type conversion is done. Data must be the same type.
     \param data  [in]: the data to compare.
     \par Return values:
     1 if less or equal, 0 otherwise.
  */
  int operator<=(const ScsData& data) const;
  /**
     \par Description:
     this method compares two ScsData objects and returns 1 if the left value is greater than the right value.  No type conversion is done. Data must be the same type.
     \param data  [in]: the data to compare.
     \par Return values:
     1 if greater, 0 otherwise.
  */
  int operator>(const ScsData& data) const;
  /**
     \par Description:
     this method compares two ScsData objects and returns 1 if the left value is greater or equal to the right value.  No type conversion is done. Data must be the same type.
     \param data  [in]: the data to compare.
     \par Return values:
     1 if greater or equal, 0 otherwise.
  */
  int operator>=(const ScsData& data) const;
  /**
     \par Description:
     this method compares two ScsData objects and returns 1 if they are different. No type conversion is done. Data must be the same type.
     \param data  [in]: the data to compare.
     \par Return values:
     1 if different, 0 otherwise.
  */
  int operator!=(const ScsData& data) const;
  /**
     \par Description:
     this method returns 1 if the value matches the regular expression.
     \param data  [in]: the regular expression to match.
     \par Return values:
     1 if matches, 0 otherwise.
  */
  int stringMatch(const ScsData& data) const;
  /**
     \par Description:
     this method compares the value with the argument. No type conversion is done. Data must be the same type.
     \param data}  [in]: the data to compare.
     \par Return values:
     -1 if less than, 0 if equal and 1 if greater than.
  */
  int compareTo(const ScsData& data) const;
  /**
     \par Description:
     this method performs a binary and between two ScsData objects. Data must be the same size.
     \param data  [in]: the data to compare.
     \par Return values:
     The ScsData resulting from the binary and is returned.
  */
  const ScsData operator&(const ScsData& data) const;
  /**
     \par Description:
     this method performs a binary or between two ScsData objects. Data must be the same size.
     \param data  [in]: the data to compare.
     \par Return values:
     The ScsData resulting from the binary or is returned.
  */
  const ScsData operator|(const ScsData& data) const;
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>ScsData</em> object into an output stream.
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore the <em>ScsData</em> object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
   void restore(SCS_SL_STD(istream)& is);
  //@}

  /**@name Print method*/
  //@{
  /**
     \par Description:
     this function is used to print an <em>ScsData</em> containing a scalar value into an output stream, using an optional format string (same conventions as for the C standard library <em>printf()</em> function).
     \param os  [out]: the output stream,
     \param format  [in]: the format string.
     \par Return values:
     none.
  */
  void print(SCS_SL_STD(ostream) &os, const char *format = 0);
  /**
     \par Description:
     this function is used to print an <em>ScsData</em> containing a scalar value into an output stream, using an optional format wide string (same conventions as for the C standard library <em>wsprintf()</em> function).
     \param os}  [out]: the output stream,
     \param format}  [in]: the format wide string.
     \par Return values:
     none.
  */
  void wprint(SCS_SL_STD(ostream) &os, const wchar_t *format = 0);
 
  /* Used to cast in the case of a pointer type */
  ScsAny toScsAny() const;

  void setType(ScsType type, int fieldId = 0);

  //@}

private:
  friend class DbmData;
  friend class DbmDirectData;

  struct BitField
  {
    unsigned int  length;
    unsigned char bitField;
  };
  
  void coerceBitFieldToString(const ScsData &);
  void freeBuffer();
  unsigned int getBufSize() const;
  unsigned int getRecordSize() const;
  unsigned int getFieldSize(int fieldId=0) const;
  ScsStatus setBuffer(const ScsAny buffer,unsigned int size);

  ScsType        _type;
  int            _nbRecords;
  int            _nbFields;
  unsigned char *_buffer;
};


extern SCS_API int operator==(const timeval& t1, const timeval& t2);
extern SCS_API int operator>=(const timeval& t1, const timeval& t2);
extern SCS_API int operator<=(const timeval& t1, const timeval& t2);
extern SCS_API int operator!=(const timeval& t1, const timeval& t2);
extern SCS_API int operator>(const timeval& t1, const timeval& t2);
extern SCS_API int operator<(const timeval& t1, const timeval& t2);
extern SCS_API timeval operator+(const timeval& t, unsigned int period);
extern SCS_API unsigned int operator-(const timeval& t1, const timeval& t2);
extern SCS_API timeval& operator+=(timeval& t, unsigned int period);
extern SCS_API SCS_SL_STD(ostream)& operator<<(SCS_SL_STD(ostream)& os, const timeval& t);
extern SCS_API SCS_SL_STD(istream)& operator>>(SCS_SL_STD(istream)& is, timeval& t);

#endif
