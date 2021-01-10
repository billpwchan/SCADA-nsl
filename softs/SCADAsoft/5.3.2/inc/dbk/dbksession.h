//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and  */
/*  shall not be disclosed by the recipient to third persons without the     */
/*  written consent of SYSECA.                                               */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : dbksession.h                                           */
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
/*  The class DbkSession is described in the file dbksession.h and           */
/*  implemented in the file dbksession.cpp.                                  */
/*  DbkSession is used to access the database kernel			     */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
// Revision 3.9.0  18/12/2002 KLL
// FFT SRC-426 - Effacer toutes les alarmes des autoId entrés en paramètre

// Revision 3.12.1  2002/03/14 KLL
// FFT SRC-494 - Ajout de la méthode updExtAlm permettant la création 
//               d'une alarme externe

// Revision 3.14.0  2003/05/20 KLL
// FFT SRC-531 - Pb lorsque cette méthode est
//               appelée par DbkSession::removeAutoId donc 
//               Effacer toutes les alarmes à partir de l'automate

#ifndef _SCS_DBKSESSION_H
#define _SCS_DBKSESSION_H

/**
   \file
   \brief Access to the Calculation Engine interface module (part of DBM module).
*/

#include "scs.h"
#include "tools.h"
#include "dbkconfig.h"

#include "dbkhierarchy.h"

class ScsData;
class ScsAddress;
class DbmData;
class DbmDataSet;
class DbkAddressId;
class DbkAttrDef;
class DbkClassDef;
class DbkGenFiles;
class DbkAddressId;
class DbkDatabase;
class DbkDatabase;
//class DbkHierarchy;
class DbkHierarchyItem;
class DbkFormula;

#define	DBK_FALSE 0
#define	DBK_TRUE  1

/**
   \brief Interface class for Calculation Engine functions.

   This class is the interface class for the services exported by the DbmServer for the implementation of Calculation Engine functions.
**/
class DBKI_API DbkSession {
  
public:
  enum UserGroup{
    SuperUser
  };
  
  friend class DbkGenFiles;
  
  /* Default constructor */
  DbkSession();

  /* Copy constructor */
  DbkSession(const DbkSession& p_item); 

  DbkSession(DbkDatabase *, 
	     DbkHierarchy *);

  /* Constructor with parameters */
  DbkSession(const UserGroup& p_userId);

  /* Destructor */
  virtual ~DbkSession();

  /***************************************************/
  /* Construction of the database kernel             */
  /***************************************************/
	
  /* declaration of the number of class, attributes, instances and instances with children */
  ScsStatus declareClassNb(int p_nbClass, 
			   int p_nbAttributes = 0, 
			   int p_nbItems = 0, 
			   int p_nbItemsWithChildren = 0,
			   int p_nbTableAttributes = 0, 
			   int p_nbFieldNames = 0);

  /* create class */
  ScsStatus createClass(const char*  p_className,
			int          p_instanceNb,
			int          p_attributeNb,
			DbkAttrDef** p_attribute,
			timeval      periodicite_ST,
			int          NbHisto_ST,
			timeval      periodicite_MT,
			int          NbHisto_MT);

  ScsStatus createClass(const char*  p_className,
			int          p_instanceNb,
			int          p_attributeNb,
			DbkAttrDef** p_attribute);

  /* create instance */
  ScsStatus createInstance(const char* p_className,
			   const char* p_fatherPath,
			   const char* p_instanceName,
			   char*       p_alias = NULL);

  /* create formula */
  ScsStatus createFormula(const char* p_attributeFullPath,
			  const char* p_formula,
			  int p_fromXML = 1,
			  int p_mustEvalOrder = 1);
  
  ScsStatus reComputeOrderEvaluations(const char* p_attributeFullPath);
  
  void startComputationFormula(DbkAddressId& p_addrId,
			  DbkFormula* p_formula);
  
  ScsStatus createFormula(DbkAddressId& p_addrId,
			  DbkFormula* p_formula);


  /* construct an adressId with the parameter max (never reached) */ 
  DbkAddressId paramaterLimitForAdressId(const DbkDatabase& l_db, 
					 int                classId);

  /***************************************************/
  /* Online configuration                            */
  /***************************************************/
  /* add class                                       */
  ScsStatus addClass(const char*  p_className,
		     unsigned int p_instanceNb,
		     unsigned int p_attributeNb,
		     DbkAttrDef** p_attribute,
		     unsigned int periodiciteST = 0,
		     unsigned int nbHistoST     = 0,
		     unsigned int periodiciteMT = 0,
		     unsigned int nbHistoMT     = 0);

  /* add instance */
  ScsStatus addInstance(const char* p_className,
			const char* p_fatherPath,
			const char* p_instanceName,
			char*       p_alias       = NULL,
			int *       topOfCpBranch = NULL);

  /* add attribute */
  ScsStatus addAttribute(const char* p_className,
			 DbkAttrDef* p_attribute);

  /* make a copy of a branch to an other place in the hierarchy */
  ScsStatus copyBranch(const char* p_branchPath, 
		       const char* p_newPointBranchPath, 
		       int*        topOfCpBranch = NULL);

  /* delete class */
  ScsStatus deleteClass(const char* p_className);

  /* delete instance */
  ScsStatus deleteTree(const char* p_instancePath);

  /* delete attribute */
  ScsStatus deleteAttribute(const char* p_className,
			    const char* p_attributeName);

  /* delete formula */
  ScsStatus deleteFormula(const char* p_attributeFullPath);

  /* disable formula */
  ScsStatus changeFormulaQuality(const char* p_attributeFullPath, 
				 int         p_quality,
				 int         p_tobeeval);
  ScsStatus changeFormulaQuality(ScsAddress& p_addresses, 
				 int         p_quality,
				 int         p_tobeeval);
  ScsStatus changeFormulaQuality(DbkAddressId p_addr_id, 
				 int          p_quality,
				 int          p_tobeeval);

  ScsStatus getFormulaQuality(ScsAddress& pAddress, 
				 int&          pQuality);

  /* modify formula */
  ScsStatus modifyFormula(const char* p_attributeFullPath,
			  const char* p_formula);


  /**@name Read/Write functions*/
  //@{ 
  /* read                                            */ 
  /**
     \par Description:
     read an attribute in database.
     \param addressId [in]: address of the attribute to read
     \param value     [in]: pointer to the memory block where read value is stored
     \param type     [out]: type of the read value
     \par Return values:
     none.
  **/
  void getValue(const DbkAddressId& addressId, 
		char*               value, 
		int&                type);
  /**
     \par Description:
     read a part of attribute vector in database.
     \param addressId   [in]: address of the attribute to read
     \param value       [in]: pointer to the memory block where read value is stored
     \param type       [out]: type of the read value
     \param recordStart [in]: index of first record to read
     \param recordEnd   [in]: index of last record to read
     \par Return values:
     none.
  **/
  void getValue(const DbkAddressId& addressId, 
		char*               value, 
		int&                type, 
		int                 recordStart, 
		int                 recordEnd);
  /**
     \par Description:
     read a part of attribute table in database.
     \param addressId   [in]: address of the attribute to read
     \param value       [in]: pointer to the memory block where read value is stored
     \param recordStart [in]: index of first record to read
     \param recordEnd   [in]: index of last record to read
     \param fieldStart  [in]: index of first field to read
     \param fieldEnd    [in]: index of last field to read
     \par Return values:
     none.
  **/
  void getValue(const DbkAddressId& addressId, 
		char*               value, 
		int                 recordStart, 
		int                 recordEnd, 
		int                 fieldStart, 
		int                 fieldEnd);

  /* multi Read */
  ScsStatus multiRead(unsigned int            p_dataNb,
		      DbkAddressId*           p_dataAddressId,
		      ScsData*                p_datas,
		      DbkHierarchy::TVector** vector = NULL);
  ScsStatus multiRead(DbmDataSet*& p_dataset);
  ScsStatus multiRead(unsigned int p_dataNb,
		      ScsAddress*  p_dataAddress,
		      ScsData*     p_datas,
		      int          contextId = -1);

  /* write */
  /**
     \par Description:
     write an attribute in database.
     \param addressId [in]: address of the attribute to write
     \param value     [in]: pointer to the memory block of the value to write
     \param type      [in]: type of the written value
     \par Return values:
     none.
  **/
  void setValue(const DbkAddressId& addressId, 
		const char*         value, 
		int                 type);
  /**
     \par Description:
     write a part of attribute vector in database.
     \param addressId   [in]: address of the attribute to write
     \param value       [in]: pointer to the memory block of the value to write
     \param type        [in]: type of the written value
     \param recordStart [in]: index of first record to write
     \param recordEnd   [in]: index of last record to write
     \par Return values:
     none.
  **/
  void setValue(const DbkAddressId& addressId, 
		const char*         value, 
		int                 type, 
		int                 recordStart, 
		int                 recordEnd);
  /**
     \par Description:
     write a part of attribute table in database.
     \param addressId   [in]: address of the attribute to write
     \param value       [in]: pointer to the memory block of the value to write
     \param recordStart [in]: index of first record to write
     \param recordEnd   [in]: index of last record to write
     \param fieldStart  [in]: index of first field to write
     \param fieldEnd    [in]: index of last field to write
     \par Return values:
     none.
  **/
  void setValue(const DbkAddressId& addressId, 
		const char*         value, 
		int                 recordStart, 
		int                 recordEnd, 
		int                 fieldStart, 
		int                 fieldEnd);

  /**
     \par Description:
     set lock to do a consistent write in database.
     This method should be only used outside of a CE function (for instance in a timer callback). 
     \par Parameters:
     None.
     \par Return values:
     none.
  **/
  void startWrite();
  /**
     \par Description:
     release lock.
     \par Parameters:
     None.
     \par Return values:
     none.
  **/
  void endWrite();

  /**
     \par Description:
     Updates the alarm and list servers if needed. That method may be called after several setValue to trigger the dependent servers of the environments. It has the same effect than the endCECycle at the end of a write. That method <b>must not</b> be used inside a CE function. It <b>must</b> be used after the endWrite.
     \par Parameters:
     None.
     \par Return values:
     None.
  **/
  void endOfUpdate();

  //@}

  /* multi Write */
  // Write multiple datas and launch the ce evaluation
  ScsStatus multiWrite(unsigned int  p_dataNb,
		       DbkAddressId* p_dataAddressId,
		       ScsData*      p_datas,
		       DbkHierarchy::TVector** pListVector = NULL);
  // Write multiple datas 
  ScsStatus multiWriteWithoutComputation(unsigned int  p_dataNb,
					 DbkAddressId* p_dataAddressId,
					 ScsData*      p_datas,
					 DbkHierarchy::TVector** pListVector = NULL);
  // Write multiple datas and launch the ce evalutation
  ScsStatus multiWrite(DbmDataSet* p_dataset);

  /* unit multi Write (all the value are written if all are correct, else no values are written)*/
  ScsStatus unitMultiWrite(unsigned int  p_dataNb,
			   DbkAddressId* p_dataAddressId,
			   ScsData*      p_datas);
  ScsStatus unitMultiWrite(DbmDataSet* p_dataset);

  ScsStatus unitMultiWrite(unsigned int p_dataNb,
			   const char** p_dataAddresses,
			   ScsData* p_datas,
			   int contextId);

  /* get Quality */
  ScsStatus getQuality(ScsAddress p_address, 
		       char&      p_quality);

  // Loading userlibs directory
  ScsStatus loadDirectoryDll();

  /* XML */

  static int LoadXML(const char * directory = NULL, 
		     const char * filename  = NULL);
  ScsStatus SaveXML(const char * filename);
  ScsStatus saveXMLBranch(const ScsAddress p_address);
  ScsStatus saveXMLSubBranch(DbkHierarchyItem* p_father, 
			     SCS_SL_STD(ostream)& ofs);


  /***************************************************/
  /* Queries to the database through the hierarchy   */
  /***************************************************/
  ScsStatus getAttributeFormulas(const ScsAddress& p_point,
				 int&              p_nbAttributes,
				 const char**&     p_formulas,
				 long*&            p_positionOrder,
				 short*&           p_quality);
  ScsStatus getAttributesDescription(const char*   className,
				     const char**& attrNames,
				     ScsType*&     valueType,
				     int*&         attrTypes,
				     int*&         replicated,
				     ScsData*&     defaultValues,
				     short&        count);
  ScsStatus getAttributeFormula(const DbkAddressId& attribute,
				const char*& formulaText,
				long& positionOrder,
				short& quality);

  /***************************************************/
  /* Attribute Management                            */
  /***************************************************/
  /* return the type (DBK_BOOLEAN, DBK_UINT8, ...) of an attribute */
  /**
     \par Description:
     get the type of an attribute from an address identifier.
     \param addressId [in]: address identifier
     \par Return values:
     \li DBK_BOOLEAN, DBK_UINT8, ...
  **/
  int getType(const DbkAddressId& addressId);

  /* return the size (used by memory) of an attribute */
  /**
     \par Description:
     get the size (used in memory) of an attribute.
     \param addressId [in]: address identifier
     \par Return values:
     \li size in bytes
  **/
  int getSize(const DbkAddressId& addressId);


  /***************************************************/
  /* Hierarchy Management                            */
  /***************************************************/
  /**@name Hierarchy Management functions*/
  //@{
  /**
     \par Description:
     get the father address of the given instance.
     \param addressId [in]: address of the instance.
     \par Return values:
     a pointer to the DbkAddressId of the father. The pointer is allocated and should be freed.
  **/
  DbkAddressId* getFather(const DbkAddressId& addressId);

  /* get children */
  /**
     \par Description: 
     get the children of an instance
     \param father    [in]: address of the instance
     \param children [out]: pointer of the resulting array. The pointer is allocated and should be freed.
     \param count    [out]: number of children
     \par Return values:
     none.
  **/
  void getChildren(const DbkAddressId& father, 
		   DbkAddressId*&      children, 
		   int&                count);

  /* get addressId */
  /**
     \par Description:
     translate an address identifier to a symbolic address     
     \param address [in]: symbolic address
     \par Return values:
     address identifier if symbolic address is found. If not found, returns 0. The pointer is allocated and should be freed.
  **/
  DbkAddressId* getAddressId(const ScsAddress& address);

  /* get address */
  /**
     \par Description:
     get the symbolic address corresponding to an address identifier
     \param addressId [in]: address identifier
     \par Return values:
     found symbolic address. Empty address if not found (A CONFIRMER).
  **/
  ScsAddress getAddress(const DbkAddressId& addressId);

  /* get addressId */
  /**
     \par Description:
     translate an address identifier to a symbolic address     
     \param address    [out]: address identifier
     \param symbAddress [in]: symbolic address to translate
     \par Return values:
     \li ScsValid if found
     \li DbmBadReferenceError if not found
  **/
  ScsStatus getAddressId(DbkAddressId& address, const ScsAddress& symbAddress);

  /* get attributeId */
  /**
     \par Description:
     get the address identifier of an attribute given by is name
     \param address    [inout]: address of the instance of the attribute. It is updated to the attribute address.
     \param attributeName [in]: name of the attribute
     \par Return values:
     \li ScsValid : success
     \li ScsError : address is null
     \li DbmBadReferenceError : attributeName is not an attribute of address instance.
  **/
  ScsStatus getAddressId(DbkAddressId& address, const char* attributeName);

  /* get attribute id from the address id of a point or an attribute*/
  /**
     \par Description:
     get the address identifier of an attribute given by is name
     \param pointAddressId [in]: address of the instance of the attribute.
     \param attributeName [in]: name of the attribute
     \par Return values:
     pointer to the address identifier of the attribute. The pointer is allocated and should be freed.
  **/
  DbkAddressId* getAttribute(const DbkAddressId& pointAddressId, 
			     const char *        attributeName);
  //@}

  /* get alias */
  //ScsStatus getAlias(const char* p_path, char*& p_alias);
  int findClassId(const char* p_className, 
		  int&        p_classId);

  /* get attribute structure */
  ScsStatus getAttributeStructure(ScsAddress     p_address,
				  int&           p_type,
				  short&         p_fieldCount,
				  short&         p_recordCount,
				  short&         p_recordUsed,
				  long&          p_recordSize,
				  const char** & p_fieldNames);
  DbkClassDef* getClassDef (const char* p_className);

  /* get address of an argument */
  /**
     \par Description:
     get the address identifier of the nth argument of the current CE function.
     \param address      [out]: address identifier
     \param argumentIndex [in]: agument index
     \par Return values:
     \li ScsValid : success
     \li ScsError : argument not found
  **/
  ScsStatus getArgumentAddressId(DbkAddressId& address, unsigned int argumentIndex);

  /***************************************************/
  /* Formula functions                               */
  /***************************************************/
  /**
     \par Description:
     get the address identifier of the attribute being computed.
     \par Parameters:
     None.
     \par Return values:
     Pointer to current address. Should not be modified nor freed.
  **/
  DbkAddressId* getCurrentAddressId();

  ScsStatus getUserFormulasNames(int&    nbUserFormulas,
				 char**& formulasNames,
				 int*&   nbArgument);

  ScsStatus triggerInstance(const DbkAddressId& addr, bool dependentsOnly = false);

  /***************************************************/
  /* Communication with external processes           */
  /***************************************************/

  ScsStatus sendEvent(const char* process, const char* message);

  ScsStatus sendAsyncEvent(const char* process, const char* message);
  ScsStatus sendAsyncEvent(const char* process, const char* message, DbkAddressId* addrId);

  /**
     \par Description:
     create an external alarm.
     \param extAlmId           [inout]: alarm identifier (should absolutely be a negative value for an external alarm or a null value for an event),
     \param state              [in]: alarm state ("A" for alarm, "N" for normal or "T" for transitory),
     \param valueAutomatonName [in]: name of the value automaton,
     \param ackAutomatonName   [in]: name of the ack automaton,
     \param equipmentDate      [in]: equipement date (applicative value)
     \param acquisitionDate    [in]: acquisition date (applicative value)
     \param severity           [in]: alarm severity,
     \param functionalCat      [in]: functional category (applicative value), used for alarm synthesis,
     \param geographicalCat    [in]: geographical category (applicative value), used for alarm synthesis,
     \param equipmentName      [in]: equipment name,
     \param message            [in]: textual description of the alarm,
     \param group1             [in]: group number one (optional parameter, its default value is ""),
     \param group2             [in]: group number two (optional parameter, its default value is ""),
     \param thresholdLow       [in]: low threshold of the range, should be a negative value if used (optional parameter, its default value is 0),
     \param thresholdHigh      [in]: high threshold of the range, should be a negative value if used (optional parameter, its default value is 0).
     \par Return values:
     \li ScsValid : sucess
  **/
  // ESA - 05/12/2006 - PCR SRC 1204 - add two new optional parameters
  ScsStatus updtExtAlm (DbkInteger64 &extAlmId,
			char*	     state,
			char*	     valueAutomatonName,
			char*	     ackAutomatonName,
			timeval      equipmentDate,
			timeval      acquisitionDate,
			int	     severity,
			int	     functionalCat,
			int	     geographicalCat,
			char*	     equipmentName,
			char*	     message,
			const char*  group1 = "",
			const char*  group2 = "",
			DbkInteger64 thresholdLow = 0,
			DbkInteger64 thresholdHigh = 0); 

    // JMA -08/01/2004- Add method setOptimizedMode to know if an instance is optimized or not
    ScsStatus setOptimizedMode(const char* p_instancePath, int p_mode);

protected:
  /* construction of an instance index (need for the direct access to the database) */
  ScsStatus constructInstanceId(unsigned int  p_classId, 
				unsigned int& p_instanceId);
  /* creation of a data of type ScsData */
  DbmData* createDbmData(const ScsAddress& p_address, 
			 char*             p_value, 
			 int               p_type);
	

  int setValue(ScsAddress  p_address,
	       const char* p_value,
	       int         p_valueType,
	       int         p_startRow    = 0,
	       int         p_endRow      = -1,
	       int         p_startColumn = 0,
	       int         p_endColumn   = -1);

  // DPL - 24/07/02 - FFT SRC-308 : Bug with DEREF
  int getClosingParen(const char* expr);  
  void deref(ScsAddress&);
  RWCString deref(const RWCString&);


private:
  int _userId;
  DbkDatabase *_currentDatabase;
  DbkHierarchy *_currentHierarchy;

};

#endif
