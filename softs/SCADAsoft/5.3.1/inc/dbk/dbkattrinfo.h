//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to THALES IS   */
/*  and shall not be disclosed by the recipient to third persons without the */
/*  written consent of THALES IS.                                            */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : dbkattrinfo.h                                          */
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
/*  The class DbkAttrInfo is described in the file dbkattrinfo.h and         */
/*  implemented in the file dbkattrinfo.cpp.                                 */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*****************************************************************************/

#ifndef _SCS_DBKATTRINFO_H_
#define _SCS_DBKATTRINFO_H_

#include "scs.h"
#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "dbk/dbkaddressid.h"

class DbkReadWrite;

class DBK_API DbkAttrInfo 
{
public:
  friend class DbkReadWrite;
  DbkAttrInfo() {}

  void save(SCS_SL_STD(ostream) &os);
  void restore(SCS_SL_STD(istream) &is);

  unsigned int	_type;
  int		_offset;
  int		_offsetQuality;
  int		_remQuality;
  int		_numElements; // Number of elements in a vector???????
  int           _startElement;
  int           _endElement;
  int           _fieldStart;
  int           _fieldEnd;
  int		_size; // Size of the attribute
  DbkAddressId  _dbkAddressId;
};

#endif
