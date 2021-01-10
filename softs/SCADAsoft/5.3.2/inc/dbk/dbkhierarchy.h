//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and  */
/*  shall not be disclosed by the recipient to third persons without the     */
/*  written consent of SYSECA.                                               */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : dbkhierarchy.h                                         */
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
/*  The class DbkHierarchy is described in the file dbkhierarchy.h and       */
/*  implemented in the file dbkhierarchy.cpp.                                */
/*  DbkHierarchy is used to manage a hierarchy for the database kernel       */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef _SCS_DBKHIERARCHY_H_
#define _SCS_DBKHIERARCHY_H_

#include "scs.h"
#include "dbkconfig.h" 

#include "dbk/dbkdefine.h" 
#include "dbk/dbkhierarchyitem.h"

#include "dbk/scsshmem.h"

class RWvostream;
class RWvistream;

#define MAXATTRIBUTELENGTH 1024
typedef int HierarchyOffset;

class RWScsAddressList;
class DbmStringList;

class DbkXMLHierarchyParser ;
class DbkAttrDef;
  
class DbkAttrDefInterf {
public:
  virtual int getValueType() =0;
  virtual int getSubValueType(int i=0) =0;
  virtual RWCString* getRWName() = 0;
  virtual int getFieldNumber(char const *) = 0;
};

class DbkClassDefInterf {
public:
  virtual DbkAttrDefInterf* getAttrDefIPtr(int p_index) = 0;
  virtual int itrAttributeId(int p_attrId) = 0;
  virtual char const * getClassName(void) = 0;
};

class DbkDatabaseInterf {
public:
  virtual ScsShmAccessMode getShmAccessMode(void) = 0;
  virtual DbkClassDefInterf* getClassDefI(int classId) const = 0;
};

class DBK_API DbkHierarchy {

public:
  friend class DbkHierarchyItem; 
  friend class DbkHierarchyChildrenHashTable;
// JMO 17/05/2002 - FFT287 add To know the memory used for each database part
  friend class DbkXMLHierarchyParser;

  struct TVector{
    int rowStart;
    int rowEnd;
    int fieldStart;
    int fieldEnd;
  };

  enum Detail {
    ATTRIBUTE_DETAIL,
    INSTANCE_DETAIL
  };
        
  static DbkHierarchy* _current;
  static DbkHierarchy* getCurrent() {return _current;}; 

  // Default constructor
  DbkHierarchy();
  DbkHierarchy(DbkDatabaseInterf *database);
  DbkHierarchy(ScsSharedMemory_t* p_mem);
  DbkHierarchy(DbkDatabaseInterf *database,
               int nbItems, 
               int nbItemsWithChildren, 
               int nbAttribut, 
               int nbClass,
               int nbTableAttributes,
               int nbFieldNames);
  DbkHierarchy(DbkDatabaseInterf *database, unsigned int size);
  // Copy constructor
  DbkHierarchy(const DbkHierarchy& p_hierarchy);

  // Destuctor
  virtual ~DbkHierarchy();

  // Operators

  // Set methods
  static void SetNbClassForEmptyDatabase(int p_nbClasses) {_NbClassForEmptyDatabase = p_nbClasses;}
  static void SetNbAttributesForEmptyDatabase(int p_nbAttr) {_NbAttributesForEmptyDatabase = p_nbAttr;}
  static void SetNbItemsForEmptyAttribute(int p_nbItems) {_NbItemsForEmptyDatabase = p_nbItems;}
  static void SetNbChildrenForEmptyDatabase(int p_nbChildren) {_NbChildrenForEmptyDatabase = p_nbChildren;}
  static void SetDbkAliasHashtableCapacity(unsigned int dbkAliasHashtableCapacity) {_DbkAliasHashtableCapacity = dbkAliasHashtableCapacity;}
  static unsigned int GetDbkAliasHashtableCapacity() {return _DbkAliasHashtableCapacity;}
        
  // Methods
  void free();
  void init();

  // DbkHierarchy Initialisation 
  void initialize(DbkDatabaseInterf *database,int nbItems, int nbItemsWithChildren, int nbAttribut, int nbClass,int nbTableAttributes,int nbFieldNames);
  void initialize(DbkDatabaseInterf *database, unsigned int size);

  // Generate an alias automatically
  void generateAlias(const RWCString& p_name, RWCString& p_alias);

  // Insert a new point in the hierarchy
  ScsStatus insert(const DbkAddressId& p_addressId, const ScsAddress& p_father, RWCString& p_alias, const RWCString& p_name);
  ScsStatus insert(const ScsAddress& p_father, RWCString& p_alias, const RWCString& p_name);
        
  // Delete a point in the hierarchy
  ScsStatus remove(const RWCString& p_alias);	
  ScsStatus remove(const ScsAddress& p_address);
  ScsStatus remove(DbkHierarchyItem& p_item);
  ScsStatus removeChild(DbkHierarchyItem* p_father, const char* p_nameChild);
        
  // Return the address identifier DbkAddressId of the specified point
  ScsStatus getAddressId(const ScsAddress& p_address, 
                         DbkAddressId& p_addressId,
                         int p_contexte=DBK_CONTEXT_0, 
                         int p_subContexteId=0,
                         TVector* p_vector=NULL);

  // Return the address identifier DbkAddressId of the attribute 'attributeName' in the same point
  ScsStatus getAddressId(DbkAddressId& p_addressId,
                         const char* attributeName);

  // Return the full path of the specified point
  ScsStatus getFullPath(const ScsAddress& p_address, ScsAddress& p_fullPath);
  ScsStatus getFullPath(const DbkAddressId& p_addressId, ScsAddress& p_fullPath, const Detail& p_detail = INSTANCE_DETAIL);
  ScsStatus getFullPath(const DbkAddressId& p_addressId, RWCString& p_fullPath, const Detail& p_detail = INSTANCE_DETAIL);

  // Return the alias of the specified address
  ScsStatus getAliasFromAddress(const DbkAddressId& p_addressId, RWCString& alias);
        
  // Return the alias of the specified point
  ScsStatus getAlias(const ScsAddress& p_address, RWCString& p_alias);
  ScsStatus getAlias(const DbkAddressId& p_addressId, RWCString& p_alias);
        
  // Return the father of the specified point
  ScsStatus getFather(const ScsAddress& p_point, ScsAddress& p_father);
  DbkHierarchyItem* getFather(const ScsAddress& p_point);
  DbkAddressId* getFather(const DbkAddressId& child);

  // Return the children of the specified point
  //ScsStatus getChildren(const ScsAddress& p_point, RWGSlist (ScsAddress)& p_children);
  ScsStatus getChildren(const ScsAddress& p_point, RWScsAddressList& p_children);
  ScsStatus getChildren(const DbkHierarchyItem*& father, DbkHierarchyItem**& children, int& count);
        
  // Return the siblings of the specified point
  //ScsStatus getSiblings(const ScsAddress& p_point, RWGSlist(ScsAddress)& p_siblings);
  ScsStatus getSiblings(const ScsAddress& p_point, RWScsAddressList& p_siblings);

  // Return the attribute id
  int getAttributeId(const int& p_classId, const char *p_attributeName, int& p_attributeId);

  // Return the attribute name
  ScsStatus getAttributeName(const DbkAddressId& p_addressId, RWCString& p_attributeName);

  // Return the attributes name that have a value type equals to p_valueType of a specified point 
  ScsStatus getAttributeNames(const ScsAddress& p_address,
                              DbmStringList& p_attributeNames,
                              int p_scsType);

  int getFieldNumber(const DbkAddressId& addressId, const char* fieldName);


  // Return the alias of the instances of a class
  ScsStatus getInstances(const int& p_classId, DbmStringList& p_instances, const char* subTree = NULL);

  // Return the DbkAddressId of a point from its path (absolute or relative)
  // and its start point if its path is relative
  ScsStatus getAddressId( const RWCString& p_path,
                          DbkAddressId& p_addressId,
                          DbkAddressId* p_startPoint = NULL,
                          TVector* p_vector=NULL);

  // Return the class name of a specified point
  ScsStatus getClassName(const char* p_path, const char*& p_className);

  // Return a list of possible addresses for an instance
  int queryInstanceByName(const ScsAddress& p_startPoint,
                          const char* p_regexpr,
                          RWScsAddressList& p_address);

  // Add an attribute
  ScsStatus addAttribute(unsigned int classId, const RWCString& attrName);
  ScsStatus updateWithNewAttribute(unsigned int classId, unsigned int attributIndex, const RWCString& attribName);
  ScsStatus addTableAttribute(unsigned int classId, unsigned int attributeId, char** fieldNames, unsigned int fieldCount);

  // Save and Restore
  void save(RWvostream& p_stream);
  /*static*/ void restore(RWvistream& p_stream,DbkDatabaseInterf *database);

  static void RestoreForRestitution(RWvistream& p_stream, DbkDatabaseInterf* database);

  // Print function
  void prettyPrint(SCS_SL_STD(ostream)& os = SCS_SL_STD(cout));
  void prettyPrintTableAttribute();

  // XML
  int saveHierarchy(SCS_SL_STD(ostream)&);

  // Get hierarchy Item
  DbkHierarchyItem* getItem(const ScsAddress& p_address);

  // Find hierarchy Item
  const DbkHierarchyItem* find(const RWCString& alias);
  // update data
  void updateSizeItemArea(int nbItem);
  void updateSizeChildrenHashTableArea (int nbItemsWithChildren); 
  void updateSizeClassArea (int nbClasses) ;
  void updateSizeAttributeNameArea (int nbAttribute);
  void updateSizeBackPointerArea(int nbClasses, int nbItems);
  void updateSizeFieldNameAreas(int nbTableAttributes, int nbFieldNames);
  void createSharedMemory(int nbClass, int nbAttributes, int nbTableAttributes, int nbFieldNames, int nbItems, int nbItemsWithChildren, ScsShmAccessMode mode);
  void initialiseSharedMemory();

  // Boolean that tells if the hierarchy is loaded (while loading XML)
  int isHierarchyLoad(); // 0, hierarchy not loaded, 1, hierarchy loaded
  int setAddressId(DbkHierarchyItem* p_item, const DbkAddressId& p_addressId);
  int setAddressId(unsigned int count, DbkHierarchyItem** p_item, unsigned int p_classId);  
  DbkHierarchyItem* getItem(unsigned int classId, unsigned int instanceId);
  inline void incrementNbClass() { _nbClass++; };
  inline void decrementNbClass() { if (_nbClass > 0) { _nbClass--; }; };

  // Hash function
  static unsigned Hash(const RWCString& str);
 
  TVector* getVectorPart(const char* attributePart, DbkAddressId& p_addressId);

  // Private Member
private: 
  // cla start : FFT SRC-411
  void isInstanceOf(const DbkHierarchyItem*& itemToBeTested, const int classId, DbmStringList& instances);
  // cla end : FFT SRC-411

  // Return the item, or null if it doesn't exist
  DbkHierarchyItem* aliasAlreadyExist(const RWCString&);
  DbkHierarchyItem* nameAlreadyExist(DbkHierarchyItem* father, const RWCString&); 
  DbkHierarchyItem* getItem(const DbkAddressId& addr);


  // fonction pour l'analyse des erreurs
  void SeeAliasHashTable(); 
  void SeeChildrenHashTable();
  
  // Attributes
  void saveItem(SCS_SL_STD(ostream)& os, DbkHierarchyItem * item, int & level, int & maxLevel);
  RWCString spaceMachine(int level);
  
  // Recursive call for query InstanceByName
  int queryInstanceByNameRec(const ScsAddress& p_startPoint,
                             const char* p_regexpr,
                             RWScsAddressList& p_address);

  int updateBackPointerArea(const DbkAddressId& p_addressId, unsigned int p_itemOffset);

protected:
  // Methods
  DbkAddressId checkAddressId(const DbkAddressId& p_addressId);

  static unsigned int GetHeaderSize();
  static unsigned int GetHeaderInfoSize();

  inline void* getItemArea() {return  (void*) _itemsArea;}
  inline void* getChildrenHashTableArea() {return (void*) _childrenHashTableArea;}
  // JMO 17/05/2002 - FFT287 add To know the memory used for each database part
  inline unsigned int getSHMSize() {return  _size;}

  DbkHierarchyItem* _root;

private: 
  DbkDatabaseInterf *_currentDatabase;

  ScsSharedMemory_t* _shMem;
  int _shMemOwner;

  static unsigned int _DbkAliasHashtableCapacity;
  DbkHierarchyItem* _itemsArea;
  int* _aliasHashTableOffset;
  DbkHierarchyChildrenHashTable* _childrenHashTableArea;
  // array of offset on the first attribute of class
  unsigned int* _classArea;
  // list of attribute names order by class
  char* _attributeNameArea;

  // array of offset on field names of table type attributes
  unsigned int* _fieldNameOffsetArea;

  // list of field names order by attribute
  char* _fieldNameArea;
  unsigned int _nbFieldNames;

  // array of offset on the first backPointer of class
  int* _firstBackPointerArea;
  unsigned int* _backPointerArea;
  
  unsigned int _nbItems; 
  unsigned int _nbChildrenHashTable; 
  unsigned int _nbClass;
  unsigned int _nbAttributes;
  
  unsigned int _itemAreaSize;
  unsigned int _childrenHashTableAreaSize;
  unsigned int _attributeNameAreaSize;
  unsigned int _classAreaSize;
  unsigned int _fieldNameOffsetAreaSize;
  unsigned int _fieldNameAreaSize;
  unsigned int _backPointerAreaSize;
  unsigned int _size;

  static int _NbClassForEmptyDatabase;
  static int _NbAttributesForEmptyDatabase;
  static int _NbItemsForEmptyDatabase;
  static int _NbChildrenForEmptyDatabase;

};

#endif
