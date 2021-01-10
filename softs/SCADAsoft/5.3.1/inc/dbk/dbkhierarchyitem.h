//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and  */
/*  shall not be disclosed by the recipient to third persons without the     */
/*  written consent of SYSECA.                                               */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : dbkhierarchyitem.h modif CAR                           */
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
/*  The class DbkHierarchyItem is described in the file dbkhierarchyItem.h   */
/*  and implemented in the file dbkhierarchyItem.cpp.   	             */
/*  DbkHierarchyItem is used to describe a point in the hierarchy	     */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef _SCS_DBKHIERARCHYITEM_H_
#define _SCS_DBKHIERARCHYITEM_H_

#ifdef _WIN32
#pragma warning( disable : 4786 4251 )
#endif

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "dbk/dbkaddressid.h"
#include "dbk/dbkdefine.h"

// ATTENTION : the size below must be changed every time 
// this class or compenent of this class is changed
#define SIZE_DBKHIERARCHYITEM_HP  136


class DbkHierarchyChildrenHashTable;   
class DbkHierarchy;

class DBK_API DbkHierarchyItem {

public:
  friend class DbkHierarchy; 
  friend class DbkHierarchyChildrenHashTable; 
 
 // Copy constructor
  DbkHierarchyItem (const DbkHierarchyItem& item); 

  // Constructor with parameters 
  DbkHierarchyItem (const DbkAddressId& address,
					const RWCString& name,
					const RWCString& alias,
					int p_fatherOffset);//= 0 should be initialize ?
		   

  static int _SizeOfDbkHierarchyItemOnHP;

  // Default constructor
protected:
  // protected constructor pseudo absract class
  DbkHierarchyItem(); 

public:

 
  // Destuctor
  virtual ~DbkHierarchyItem(); 

  // Operators
  bool operator==(const DbkHierarchyItem& item) const;
  void operator delete (void* address); 
  void* operator new (size_t size) throw (); 

  // Save and Restore
  void restore (RWvistream& rRWvistream, char* p_reference); 
  void restoreForRestitution(RWvistream& p_stream, char* p_reference);
  void save(RWvostream&, char* p_reference)const; 
	
  // Print function
  void prettyPrint();

  // Get methods
  inline const char* getAlias() {return _alias;}
  inline const DbkAddressId getAddressId() {return _addressId;}
  inline const char* getName() {return _name;}
  const DbkHierarchyItem* getFather();

  inline int getFatherOffset() {return (_fatherOffset);}

  // Set method
  inline void setAddressId(DbkAddressId p_addressId) {_addressId = p_addressId;}

protected:
  
 
private: 

  char _name[DBK_HIERARCHY_NAME_LENGTH]; 
  char _alias[DBK_HIERARCHY_ALIAS_LENGTH]; 
  int _fatherOffset;
  int _childrenHashTableIndex; 
  int _nextAliasOffset;
  int _nextChildOffset;
  DbkAddressId      _addressId; 
};


#endif 
 

