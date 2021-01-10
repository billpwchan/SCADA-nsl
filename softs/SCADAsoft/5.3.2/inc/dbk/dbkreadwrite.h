//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and  */
/*  shall not be disclosed by the recipient to third persons without the     */
/*  written consent of SYSECA.                                               */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : dbkreadwrite.h                                         */
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
/*  The class DbkReadWrite is described in the file dbkreadwrite.h and       */
/*  implemented in the file dbkreadwrite.cpp.                                */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*****************************************************************************/

#ifndef _SCS_DBKREADWRITE_H_
#define _SCS_DBKREADWRITE_H_

#include "dbk/dbkaddressid.h"
#include "dbkconfig.h"

class DbkAttrInfo;
class DbmGroupDesc;
class DbmServer;

class DBK_API DbkReadWrite 
{
public:
  friend class DbmGroupDesc;
  friend class DbmServer;
  DbkReadWrite();
  ~DbkReadWrite();

  void setBuffer(char * buffer) {_buffer = buffer;}
  char * getBuffer(void) {return _buffer;}
  void setBufferQuality(char * bufferQuality) {_bufferQuality = bufferQuality;}
  char * getBufferQuality(void) {return _bufferQuality;}
  void setOffset(int offset) {_offset = offset;}
  int getOffset(void) {return _offset;}
  void setOffsetQuality(int offsetQuality) {_offsetQuality = offsetQuality;}
  int getOffsetQuality(void) {return _offsetQuality;}
  void setType(unsigned int type) {_type = type;}
  unsigned int getType(void) {return _type;}
  void setNumElements(unsigned int numElements) {_numElements = numElements;}
  unsigned int getNumElements(void) {return _numElements;}
  void setSize(unsigned int size) {_size = size;}
  unsigned int getSize(void) {return _size;}
  void setValue(const char   * value,
		int pos1 = 0,
		int pos2 = -1);
  void getValue(char         * value,
		int pos1 = 0,
		int pos2 = -1);
  void getValueBool(char * value);
  void getValueUnsignedInt8(unsigned char * value);
  void getValueInt16(short * value);
  void getValueUnsignedInt16(unsigned short * value);
  void getValueInt32(int * value);
  void getValueUnsignedInt32(unsigned int * value);
  void getValueInt64(long * value);
  void getValueUnsignedInt64(unsigned long * value);
  void getValueFloat(float * value);
  void getValueDouble(double * value);
  void setQuality(char quality);
  char getQuality(void);
  void setAttrInfo(DbkAttrInfo & attrInfo);
  int isEquivalent(const DbkAttrInfo& attrInfo) const;
  const DbkAddressId& getAddressId(void) const {return _dbkAddressId;}

protected:
  char * _buffer;
  char * _bufferQuality;
  int           _offset;
  int           _offsetQuality;
  int           _remQuality;
  unsigned int  _type;
  int           _numElements;
  int           _size;
  int		_recordNumber;	// -1 means all records
  DbkAddressId  _dbkAddressId;
};

#endif
