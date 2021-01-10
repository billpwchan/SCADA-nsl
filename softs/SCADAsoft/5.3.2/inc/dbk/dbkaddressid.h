//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and  */
/*  shall not be disclosed by the recipient to third persons without the     */
/*  written consent of SYSECA.                                               */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : dbkaddressid.h                                         */
/*  FULL NAME       :                                                        */
/*---------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                              */
/*  CREATION DATE   : Mon May 15 09:00:00 2000                               */
/*  LANGUAGE        : C++                                                    */
/*...........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                        */
/*  All rights reserved.                                                     */
/*                                                                           */
/*  Unauthorized access, use, reproduction or distribution is prohibited.    */
/*...........................................................................*/
/*  OVERVIEW                                                                 */
/*                                                                           */
/*  The class DbkAddressId is described in the file dbkaddressid.h and       */
/*  implemented in the file dbkaddressid.cpp.                                */
/*  DbkAddressId is used to describe attribute address.                      */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*  Attribute address is encrypted on two 32 bits words. On 64 bits OS, it   */
/*  is better to use only one 64 bits word.                                  */
/*                                                                           */
/*****************************************************************************/

#ifndef _SCS_DBKADDRESSID_H_
#define _SCS_DBKADDRESSID_H_

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif


#include "scs.h"
#include "tools.h"
#include "dbkconfig.h"
#include "dbkerror.h"

// cla start : integer64 definition for each system
#ifdef WIN32
//
// ToDo : 
// 
// typedef hyper DbkInteger64;
typedef __int64 DbkInteger64;
#else
typedef long long DbkInteger64;
#endif
// cla end


#define	DBK_FALSE 0
#define	DBK_TRUE  1

class DbkDatabase;

class RWvostream;
class RWvistream;

typedef struct Reference {
#ifdef DBKADDRESSID64
	unsigned long value;
#else
	unsigned int part1;
	unsigned int part2;
#endif
} Reference;

#define SIZE_FOR_CLASSID		16
#define SIZE_FOR_CONTEXTID		6
#define SIZE_FOR_SUBCONTEXTID		10
#define SIZE_FOR_ATTRIBUTEID		14
#define SIZE_FOR_INSTANCEID		18

class DbkAddressId {

public:

	friend class DbkDatabase;
	/* Default constructor */
	inline DbkAddressId();

	/* Copy constructor*/
	inline DbkAddressId(const DbkAddressId& p_addressId);
	inline DbkAddressId(const DbkAddressId* p_addressId);

	/* Constructor with parameters */
	inline DbkAddressId(int classId,
		     int contextId,
		     int subContextId,
		     int attributeId,
		     int instanceId);

#ifdef DBKADDRESSID64
  inline DbkAddressId(	unsigned long inValue);
  inline DbkAddressId(	unsigned int inPart1FromCorbaOnly,
			unsigned int inPart2FromCorbaOnly);

#else
  inline DbkAddressId(	 unsigned int inPart1,
			 unsigned int inPart2);
#endif

	/* Destuctor */
	inline virtual ~DbkAddressId();

	/* Operators */
	inline int operator==(const DbkAddressId& addressId) const;
	inline int operator!=(const DbkAddressId& addressId) const;
	inline DbkAddressId& operator=(const DbkAddressId& addressId);
        inline bool operator<(const DbkAddressId& addressId) const;

  /* Set methods */
	inline void setValue(	const int& classId,
					const int& contextId,
					const int& subContextId,
					const int& attributeId,
					const int& instanceId);

	inline void setClassId(const int& classId);
	inline void setContextId(const int& contextId);
	inline void setSubContextId(const int& subContextId);
	inline void setAttributeId(const int& attributeId);
	inline void setInstanceId(const int& instanceId);

	//inline void setValuePart1(const unsigned int &value) {_address1.value = value;}
	//inline void setValuePart2(const unsigned int &value) {_address2.value = value;}
#ifdef DBKADDRESSID64
	inline void setValue( unsigned long inValue ){ _address.value = inValue;}
        inline void setValue( Reference p_ref) {_address.value = p_ref.value;};
        inline void setValue( unsigned int inPart1, unsigned int inPart2 );
#else
	inline void setValue( unsigned int inPart1, unsigned int inPart2 ){ _address1.value = inPart1; _address2.value = inPart2;}
        inline void setValue( Reference p_ref) { _address1.value = p_ref.part1; _address2.value = p_ref.part2;}
#endif
	inline void write(void *buffer) const;
	inline void read(void *buffer);

	/* Get methods */
	inline void getValue(int& classId,
		      int& contextId,
		      int& subContextId,
		      int& attributeId,
		      int& instanceId);
	inline int getClassId(void) const;
	inline int getContextId(void) const;
	inline int getSubContextId(void) const;
	inline int getAttributeId(void) const;
	inline int getInstanceId(void) const;

	static DBK_API unsigned int GetSizeOfClassId(void);
	static DBK_API unsigned int GetSizeOfContextId(void);
	static DBK_API unsigned int GetSizeOfSubContextId(void);
	static DBK_API unsigned int GetSizeOfAttributeId(void);
	static DBK_API unsigned int GetSizeOfInstanceId(void);

	inline unsigned int getValuePart1ForCorbaOnly(void) const;
	inline unsigned int getValuePart2ForCorbaOnly(void) const;

	friend DBK_API SCS_SL_STD(ostream)& operator<<(SCS_SL_STD(ostream)& s, const DbkAddressId& addressId);

  	void save(RWvostream& p_stream) const;
	void restore(RWvistream& p_stream);
  	inline void save(SCS_SL_STD(ostream)& p_stream) const;
	inline void restore(SCS_SL_STD(istream)& p_stream);
	inline ScsStatus isValid(DbkAddressId paramaterLimitForAdressId);

	static DBK_API DbkInteger64 GetKey(const DbkAddressId* inAddress) {return inAddress->getKey();}
	inline DbkInteger64 getKey() const;

	static DBK_API DbkAddressId* getDbkAddressId(const unsigned int inKey,
		const unsigned int inContextId = 0,
		const unsigned int inSubContextId = 0);

	inline void prettyPrint();
    inline int isNull() const;

private:

#ifdef DBKADDRESSID64
	union {
		struct {
			unsigned int _fClassId:SIZE_FOR_CLASSID;
			unsigned int _fContextId:SIZE_FOR_CONTEXTID;
			unsigned int _fSubContextId:SIZE_FOR_SUBCONTEXTID;
			unsigned int _fAttributeId:SIZE_FOR_ATTRIBUTEID;
			unsigned int _fInstanceId:SIZE_FOR_INSTANCEID;
		} fields;
		unsigned long value;
	} _address;
#else
	union {
		struct {
			unsigned int _fClassId:SIZE_FOR_CLASSID;
			unsigned int _fContextId:SIZE_FOR_CONTEXTID;
			unsigned int _fSubContextId:SIZE_FOR_SUBCONTEXTID;
		} fields;
		unsigned int value;
	} _address1;
	union AddressPart2 {
		struct  {
			unsigned int _fAttributeId:SIZE_FOR_ATTRIBUTEID;
			unsigned int _fInstanceId:SIZE_FOR_INSTANCEID;
		} fields;
		unsigned int value;
	} _address2;
#endif

};
extern DBK_API SCS_SL_STD(ostream)& operator<<(SCS_SL_STD(ostream)& s, const DbkAddressId& addressId);

inline RWvostream& operator<< (RWvostream& p_stream, const DbkAddressId& p_addressId)
{
	p_addressId.save(p_stream);
	return p_stream;
}

inline RWvistream& operator>> (RWvistream& p_stream, DbkAddressId& p_addressId)
{
	p_addressId.restore(p_stream);
	return p_stream;
}

#define _classId fields._fClassId
#define _contextId fields._fContextId
#define _subContextId fields._fSubContextId
#define _attributeId fields._fAttributeId
#define _instanceId fields._fInstanceId

DbkAddressId::DbkAddressId() {

#ifdef DBKADDRESSID64
	_address.value = 0;
#else
	_address1.value = 0;
	_address2.value = 0;
#endif
}

DbkAddressId::DbkAddressId(	 int classId,
				 int contextId,
				 int subContextId,
				 int attributeId,
				 int instanceId) {

#ifdef DBKADDRESSID64
	_address._classId = classId + 1 ;
	_address._contextId = contextId;
	_address._subContextId = subContextId;
	_address._attributeId = attributeId;
	_address._instanceId = instanceId;
#else
	_address1._classId = classId + 1;
	_address1._contextId = contextId;
	_address1._subContextId = subContextId;
	_address2._attributeId = attributeId;
	_address2._instanceId = instanceId;
#endif
}

#ifdef DBKADDRESSID64
DbkAddressId::DbkAddressId(unsigned long inValue)
{
	_address.value = inValue;
}

DbkAddressId::DbkAddressId(unsigned int inPart1FromCorbaOnly,
			   unsigned int inPart2FromCorbaOnly)
{
  _address.value = ((unsigned long)inPart1FromCorbaOnly << 32) | inPart2FromCorbaOnly;
}

#else
DbkAddressId::DbkAddressId(	unsigned int inPart1,
					unsigned int inPart2)
{
	_address1.value = inPart1;
	_address2.value = inPart2;
}
#endif

DbkAddressId::DbkAddressId(const DbkAddressId& p_addressId)
{
#ifdef DBKADDRESSID64
	_address = p_addressId._address;
#else
	_address1 = p_addressId._address1;
	_address2 = p_addressId._address2;
#endif
}

DbkAddressId::DbkAddressId(const DbkAddressId* p_addressId)
{
  if (p_addressId) {
#ifdef DBKADDRESSID64
    _address = p_addressId->_address;
#else
    _address1 = p_addressId->_address1;
    _address2 = p_addressId->_address2;
#endif
  } else {
#ifdef DBKADDRESSID64
    _address.value = 0;
#else
    _address1.value = 0;
    _address2.value = 0;
#endif
  }
}

DbkAddressId::~DbkAddressId() {



}

void
DbkAddressId::read(void *buffer)
{
#ifdef DBKADDRESSID64
	_address.value = *((unsigned long *)buffer);
#else
	_address1.value = *((unsigned int *)buffer);
	_address2.value = *(((unsigned int *)buffer) + 1);
#endif
}

void
DbkAddressId::write(void *buffer) const
{
#ifdef DBKADDRESSID64
	*((unsigned long *)buffer) = _address.value;
#else
	*((unsigned int *)buffer) = _address1.value;
	*(((unsigned int *)buffer) + 1) = _address2.value;
#endif
}

void
DbkAddressId::setValue(	const int& classId,
						const int& contextId,
						const int& subContextId,
						const int& attributeId,
						const int& instanceId) {

#ifdef DBKADDRESSID64
	_address._classId = classId + 1;
	_address._contextId = contextId;
	_address._subContextId = subContextId;
	_address._attributeId = attributeId;
	_address._instanceId = instanceId;
#else
	_address1._classId = classId + 1;
	_address1._contextId = contextId;
	_address1._subContextId = subContextId;
	_address2._attributeId = attributeId;
	_address2._instanceId = instanceId;
#endif
}

void
DbkAddressId::getValue(int& classId,
		       int& contextId,
		       int& subContextId,
		       int& attributeId,
		       int& instanceId)
{
#ifdef DBKADDRESSID64
	classId = _address._classId - 1;
	contextId = _address._contextId;
	subContextId = _address._subContextId;
	attributeId = _address._attributeId;
	instanceId = _address._instanceId;
#else
	classId = _address1._classId - 1;
	contextId = _address1._contextId;
	subContextId = _address1._subContextId;
	attributeId = _address2._attributeId;
	instanceId = _address2._instanceId;
#endif
}

void
DbkAddressId::setClassId(const int& classId) {

#ifdef DBKADDRESSID64
	_address._classId = classId + 1;
#else
	_address1._classId = classId + 1;
#endif

}

void
DbkAddressId::setContextId(const int& contextId) {

#ifdef DBKADDRESSID64
	_address._contextId = contextId;
#else
	_address1._contextId = contextId;
#endif

}

void
DbkAddressId::setSubContextId(const int& subContextId) {

#ifdef DBKADDRESSID64
	_address._subContextId = subContextId;
#else
	_address1._subContextId = subContextId;
#endif

}

void
DbkAddressId::setAttributeId(const int& attributeId) {

#ifdef DBKADDRESSID64
	_address._attributeId = attributeId;
#else
	_address2._attributeId = attributeId;
#endif

}

void
DbkAddressId::setInstanceId(const int& instanceId) {

#ifdef DBKADDRESSID64
	_address._instanceId = instanceId;
#else
	_address2._instanceId = instanceId;
#endif

}

int
DbkAddressId::getClassId(void) const{

#ifdef DBKADDRESSID64
	return (_address._classId - 1);
#else
	return (_address1._classId - 1);
#endif

}

int
DbkAddressId::getContextId(void) const{

#ifdef DBKADDRESSID64
	return _address._contextId;
#else
	return _address1._contextId;
#endif

}

int
DbkAddressId::getSubContextId(void) const{

#ifdef DBKADDRESSID64
	return _address._subContextId;
#else
	return _address1._subContextId;
#endif

}

int
DbkAddressId::getAttributeId(void) const{

#ifdef DBKADDRESSID64
	return _address._attributeId;
#else
	return _address2._attributeId;
#endif

}

int
DbkAddressId::getInstanceId(void) const{

#ifdef DBKADDRESSID64
	return _address._instanceId;
#else
	return _address2._instanceId;
#endif

}
int
DbkAddressId::operator==(const DbkAddressId& addressId) const
{
#ifdef DBKADDRESSID64
	return _address.value == addressId._address.value;
#else
	return _address1.value == addressId._address1.value &&
		   _address2.value == addressId._address2.value;
#endif

}

int
DbkAddressId::operator!=(const DbkAddressId& addressId) const
{
#ifdef DBKADDRESSID64
	return _address.value != addressId._address.value;
#else
	return _address1.value != addressId._address1.value ||
		   _address2.value != addressId._address2.value;
#endif

}

DbkAddressId&
DbkAddressId::operator=(const DbkAddressId& addressId) {

#ifdef DBKADDRESSID64
	_address.value = addressId._address.value;
#else
	_address1.value = addressId._address1.value;
	_address2.value = addressId._address2.value;
#endif

	return *this;
}

bool
DbkAddressId::operator<(const DbkAddressId& addressId) const {

#ifdef DBKADDRESSID64
  return (_address.value < addressId._address.value);
#else
  if(_address1.value < addressId._address1.value) {
    return true;
  } else if (_address1.value > addressId._address1.value) {
    return false;
  } else if (_address2.value < addressId._address2.value) {
    return true;
  } else if (_address2.value > addressId._address2.value) {
    return false;
  } else {
    return false;
  }
#endif
}


void DbkAddressId::save(SCS_SL_STD(ostream)& p_stream) const
{
#ifdef DBKADDRESSID64
	p_stream << _address.value;
#else
	p_stream << _address1.value << " " 
		 << _address2.value;
#endif
}

void DbkAddressId::restore(SCS_SL_STD(istream)& p_stream) 
{
#ifdef DBKADDRESSID64
	p_stream >> _address.value;
#else
	p_stream >> _address1.value >> _address2.value;
#endif
}

ScsStatus DbkAddressId::isValid(DbkAddressId paramaterLimitForAdressId)
{
#ifdef DBKADDRESSID64
  //test if the classId is good
  if (_address.fields._fClassId >= paramaterLimitForAdressId._address.fields._fClassId) 
    return DbkAddressIdError;

  //test if the contextId is good
  if (_address.fields._fContextId > paramaterLimitForAdressId._address.fields._fContextId)
    return DbkAddressIdError;

  //test if the subContextId is good
  if (_address.fields._fSubContextId >= paramaterLimitForAdressId._address.fields._fSubContextId)
    return DbkAddressIdError;

  //test if the attributeId is good
  if (_address.fields._fAttributeId > paramaterLimitForAdressId._address.fields._fAttributeId)
    return DbkAddressIdError;

  //test if the instanceId is good
  if (_address.fields._fInstanceId > paramaterLimitForAdressId._address.fields._fInstanceId)
    return DbkAddressIdError;	 

#else
  //test if the classId is good
  if (_address1.fields._fClassId >= paramaterLimitForAdressId._address1.fields._fClassId) 
    return DbkAddressIdError;

  //test if the contextId is good
  if (_address1.fields._fContextId > paramaterLimitForAdressId._address1.fields._fContextId)
    return DbkAddressIdError;

  //test if the subContextId is good
  if (_address1.fields._fSubContextId >= paramaterLimitForAdressId._address1.fields._fSubContextId)
    return DbkAddressIdError;

  //test if the attributeId is good
  if (_address2.fields._fAttributeId > paramaterLimitForAdressId._address2.fields._fAttributeId)
    return DbkAddressIdError;

  //test if the instanceId is good
  if (_address2.fields._fInstanceId > paramaterLimitForAdressId._address2.fields._fInstanceId)
    return DbkAddressIdError;

#endif
  return ScsValid;
}
#ifdef DBKADDRESSID64
void DbkAddressId::setValue( unsigned int inPart1, unsigned int inPart2 )
{
    _address.value = ((unsigned long)inPart1 << 32) | inPart2;
}
#endif

unsigned int DbkAddressId::getValuePart1ForCorbaOnly(void) const
{
#ifdef DBKADDRESSID64
  return _address.value >> 32;
#else
  return _address1.value;
#endif
}

unsigned int DbkAddressId::getValuePart2ForCorbaOnly(void) const
{
#ifdef DBKADDRESSID64
  return ((unsigned int) _address.value);
#else
  return _address2.value;
#endif
}

// ============================================================
// Function    : isNull
// Author      : Jerome Moulin
// Creation    : 15 04 2002
// Description : test if the AddressId if Null or not
// Comment     : 
// ------------------------------------------------------------
// Output :
// Return Value     : DBK_TRUE or DBK_FALSE
//
// Modif Global Var : 
// Modif Attributes : 
// Global Functions : 
// Called Methods   : 
// ============================================================
// Date     	Modification
// ------------------------------------------------------------
int
DbkAddressId::isNull() const
{
#ifdef DBKADDRESSID64
  if (_address.value == 0)
    return DBK_TRUE;
#else
  if (_address1.value == 0 && _address2.value == 0 )
    return DBK_TRUE;
#endif

  return DBK_FALSE;
}

// ============================================================
// Function    : getKey
// Author      : Andre Tran
// Creation    : 28 09 2000
// Modified    : 31 10 2003 by K.L.L.
// Modified    : 02 12 2003 by cla
// Description : create a 64 bits unique key for a DbkAddressId instance
// Comment     : The key value is constructed as follows
//		 { 0[16] ; classId[16] ; attributeId[14] ; instanceId[18]}
// ------------------------------------------------------------
// Input  :
//	DbkAddressId inAddress	instance to compute
// Output :
// Return Value     :
//	long			key of the instance
// Modif Global Var : 
// Modif Attributes : 
// Global Functions : 
// Called Methods   : 
// ============================================================
// Date     	Modification
// ------------------------------------------------------------
// cla start
DbkInteger64 DbkAddressId::getKey() const
{
#ifdef DBKADDRESSID64
  DbkInteger64 classKey = _address._classId;
#else
  DbkInteger64 classKey = _address1._classId;
#endif

  DbkInteger64 attributeKey = this->getAttributeId();
  DbkInteger64 instanceKey  = this->getInstanceId();

  return ((((classKey)&(0xffff))<<32) | (((attributeKey)&(0x3fff))<<18) | ((instanceKey)&(0x3ffff)));
}
// cla end

//////////////////////////////////////////////////////////////////////
// prettyPrint
//////////////////////////////////////////////////////////////////////
void DbkAddressId::prettyPrint()
{
  SCS_SL_STD(cout) << "*********************" << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "DbkAddressId" << SCS_SL_STD(endl);
#ifdef DBKADDRESSID64
  SCS_SL_STD(cout) << "ClassId : " << _address._classId - 1 << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "InstanceId : " << _address._instanceId << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "Attribute Id : " << _address._attributeId << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "Context Id : " << _address._contextId << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "SubContext Id : " << _address._subContextId << SCS_SL_STD(endl);
#else
  SCS_SL_STD(cout) << "ClassId : " << _address1._classId - 1 << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "InstanceId : " << _address2._instanceId << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "Attribute Id : " << _address2._attributeId << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "Context Id : " << _address1._contextId << SCS_SL_STD(endl);
  SCS_SL_STD(cout) << "SubContext Id : " << _address1._subContextId << SCS_SL_STD(endl);
#endif
}

#undef _classId
#undef _contextId
#undef _subContextId
#undef _attributeId
#undef _instanceId

#endif
