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

#ifndef _DBMTYPES_H
#define _DBMTYPES_H

#include "scs.h"
#include "scsdata.h"

// The RTAP quality of Attribute data (determined by
// calculation engine as a result of a definition)
#define SCS_ATTR_OK		0 // No known errors in data
#define SCS_ATTR_SUSPECT	1 // Depends on a suspect, error or disabled value
#define SCS_ATTR_ERROR		2 // Calculation engine got math error
#define SCS_ATTR_DISABLED	3 // scan point disabled or CE operation indicator
				  // disabled
                  
/**
   \brief This class is used to store the address of a database point attribute, and, eventually, its value and its type.

   The <em>DbmData</em> class is used to store address and value of a database point attribute. The point address is a symbolic description and is stored in an <em>ScsAddress</em> object. The value is stored in an <em>ScsData</em> object with its associated type.
\code#include "dbm.h"\endcode
*/
class DBK_API DbmData
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     copy constructor.
     \param data  [in]: the <em>DbmData</em> object to copy. 
     \par Return values:
     none.
  */
  DbmData(const DbmData &data);

  /**
     \par Description:
     constructor used to read the value of a database point attribute. the <em>type</em> parameter is used for an attribute of type <em>rtBytesXXX</em> to speciy if the value to read is a string or a bit field (by default, such an attribute is considered to be a string). For example, to read a bit field value, the <em>type</em> parameter should be set to <em>ScsBIT</em>.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to read. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address);
 
  /**
     \par Description:
     constructor used to write the value of a database point attribute of type int.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write, 
     \param value  [in]: the value to write. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address, int value);

  /**
     \par Description:
     constructor used to write the value of a database point attribute of type int64.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write, 
     \param value  [in]: the value to write. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address, ScsINT64 value);
  
  /**
     \par Description:
     constructor used to write the value of a database point attribute of type float.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write,
     \param value  [in]: the value to write. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address, float value);

  /**
     \par Description:
     constructor used to write the value of a database point attribute of type double.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write,
     \param value  [in]: the value to write. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address, double value);
  
  /**
     \par Description:
     constructor used to write the value of a database point attribute of type string.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write,
     \param value  [in]: the value to write. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address, const char *value);

  /**
     \par Description:
     constructor used to write the value of a database point attribute of type timeval structure.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write,
     \param value  [in]: the value to write. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address, timeval value);

  /**
     \par Description:
     constructor used to write the value of a database point attribute of type <em>rtBytesXXX</em> using a bit field data.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write, 
     \param value  [in]: a buffer containing the bit field value. 
     \param size  [in]: the size of the buffer in bytes. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress    &address,
	  const unsigned char *value,
	  const unsigned int   size);

  /**
     \par Description:
     constructor used to write the value of a database point attribute from an <em>ScsData</em> value or to read an attribute of type <em>rtBytesXXX</em>. The <em>value</em> parameter is used to speciy if the value to read is a string or a bit field (by default, such an attribute is considered to be a string). For example, to read a bit field value, an <em>ScsData</em> object with 1 record and 1 field and the type <em>ScsBIT</em> should be given as parameter.
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to write,
     \param value  [in]: the value to write or type of the attribute to read. 
     \par Return values:
     none.
  */
  DbmData(const ScsAddress &address, const ScsData &value);

  /**
     \par Description:
     constructor used to subscribe to a database point attribute. The user id is used to identify a point attribute when a client is notified for the attribute using the notification callback.
     \param id  [in]: the user id associated with the attribute,
     \param address  [in]: an <em>ScsAddress</em> object containing the symbolic description of the point attribute to subscribe. 
     \par Return values:
     none.
  */
  DbmData(int id, const ScsAddress &address);
  DbmData(int id);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~DbmData();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     returns the object containing the symbolic description of the point attribute.
     \par Parameters:
     none.
     \par Return values:
     the <em>ScsAddress</em> object of the <em>DbmData</em> object.
  */
  const ScsAddress *getAddress() const { return _address;};

  /**
     \par Description:
     returns the object containing the value of the point attribute.
     \par Parameters:
     none.
     \par Return values:
     the <em>ScsData</em> object of the <em>DbmData</em> object.
  */
  const ScsData &getData() const { return _data;};

  /**
     \par Description:
     returns the buffer of the object containing the value of the point attribute. If the <em>recordId</em> and <em>fieldId</em> parameters are set, the pointer returned points to the part of the buffer containing the element corresponding to the specified record and field.
     \param recordId  [in]: a record identifier (0 to n-1, n being the number of records of the attribute).
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute). 
     \par Return values:
     the buffer of the <em>ScsData</em> object of the <em>DbmData</em> object.
  */
  ScsAny getBuffer(int recordId = 0, int fieldId = 0) const
  { return _data.getBuffer(recordId, fieldId);};

  /**
     \par Description:
     returns the type of the <em>DbmData</em>. The type returned is the type of the data for a scalar or vector, or the type of the specified field for a table.
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute). 
     \par Return values:
     the type of the <em>DbmData</em> object.
  */
  ScsType getType(int fieldId = 0) const { return _data.getType(fieldId);};

  /**
     \par Description:
     set the type of the <em>DbmData</em>. The type set is the type of the data for a scalar or vector, or the type of the specified field for a table.
     \param p_type  [in]:  the type of the <em>DbmData</em> object. 
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute). 
     \par Return values:
     none.
  */

  void setType(ScsType p_type, int fieldId = 0);

  /**
     \par Description:
     returns the quality of the <em>DbmData</em>.
     \par Parameters:
     none.
     \par Return values:
     the quality of the <em>DbmData</em> object.
  */

  unsigned int getQuality() const { return _quality;};

  /**
     \par Description:
     set the quality of the <em>DbmData</em> to the specified value.
     \param quality  [in]: the quality value to set. 
     \par Return values:
     none.
  */
  void setQuality(unsigned int quality) { _quality = quality;};

  /**
     \par Description:
     returns the user id of the <em>DbmData</em>.
     \par Parameters:
     none.
     \par Return values:
     the user id.
  */
  int getId() const { return _id;};

  /**
     \par Description:
     set the user id of the <em>DbmData</em> to the specified value.
     \param id  [in]: the user id to set. 
     \par Return values:
     none.
  */
  void setId(int id) { _id = id;};
  //@}

  /**@name Operator / cast*/
  //@{
  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmData</em> casted to an int value.
     \par Parameters:
     none.
     \par Return values:
     the casted int value.
  */
  operator int() { return *(int *)_data.getBuffer();};

   /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmData</em> casted to an int64 value.
     \par Parameters:
     none.
     \par Return values:
     the casted int64 value.
  */
  operator ScsINT64() { return *(ScsINT64 *)_data.getBuffer();};

  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmData</em> casted to a float value.
     \par Parameters:
     none.
     \par Return values:
     the casted float value.
  */
  operator float() { return *(float *)_data.getBuffer();};
  
  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmData</em> casted to a double value.
     \par Parameters:
     none.
     \par Return values:
     the casted double value.
  */
  operator double() { return *(double *)_data.getBuffer();};

  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmData</em> casted to a string value.
     \par Parameters:
     none.
     \par Return values:
     the casted string value.
  */
  operator char*() { return (char *)_data.getBuffer();};

  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmData</em> casted to a timeval structure value.
     \par Parameters:
     none.
     \par Return values:
     the casted timeval structure value.
  */
  operator timeval() { return *(timeval *)_data.getBuffer();};

  /**
     \par Description:
     cast operator. This operator returns the buffer of the <em>DbmData</em> casted to a bit field value.
     \par Parameters:
     none.
     \par Return values:
     the casted bit field value.
  */
  operator unsigned char *() { return (unsigned char *)_data.getBuffer();};


  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmData</em> to the specified int value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(int value);

  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmData</em> to the specified int64 value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(ScsINT64 value);

  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmData</em> to the specified float value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(float value);

  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmData</em> to the specified double value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(double value);

  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmData</em> to the specified string value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(const char *value);

  /**
     \par Description:
     assignment operator. This operator set the value of the <em>DbmData</em> to the specified timeval structure value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(timeval value);

  /**
     \par Description:
     assignment operator. This operator set the <em>DbmData</em> to the specified data.
     \param data  [in]: the data to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(const DbmData &data);

  /**
     \par Description:
     assignment operator. This operator set the <em>ScsAddress</em> of the <em>DbmData</em> to the specified address.
     \param address  [in]: the address to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(const ScsAddress &address);

  /**
     \par Description:
     assignment operator. This operator set the <em>ScsData</em> of the <em>DbmData</em> to the specified value.
     \param value  [in]: the value to set. 
     \par Return values:
     the updated <em>DbmData</em>.
  */
  DbmData &operator=(const ScsData &value);
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     save the <em>DbmData</em> object into an <em>ostream</em>.
     \param stream  [in]: output stream. 
     \par Return values:
     none.
  */
  void save(SCS_SL_STD(ostream)& stream) const;

  /**
     \par Description:
     restore the <em>DbmData</em> object from an <em>istream</em>.
     \param stream  [in]: input stream. 
     \par Return values:
     none.
  */
  void restore(SCS_SL_STD(istream)& stream);

  /**
     \par Description:
     test if the <em>DbmData</em> or the value pointed by <em>recordId</em> and <em>fieldId</em> is a NULL reference. 
     \param recordId  [in]:  a record identifier (0 to m-1, m being the number of fields of the attribute). 
     \param fieldId  [in]: a field identifier (0 to m-1, m being the number of fields of the attribute). 
     \par Return values:
     1 if the test is true and 0 if the test is false.
  */

  inline int isNullReference(int recordId = 0, int fieldId = 0) {return _data.isNullReference(recordId, fieldId);};
  //@}

private:
  ScsAddress   *_address;
  ScsData       _data;
  unsigned int  _quality;
  int           _id;
};

#endif
