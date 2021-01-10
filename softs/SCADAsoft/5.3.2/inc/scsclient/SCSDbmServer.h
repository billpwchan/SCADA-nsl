// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright � THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDbmServer.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDBMSERVER_H
#define SCSCLIENT_SCSDBMSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class DbmServer;
class DbmPoller;
class DbmDataSet;
class DbmDirectDataSet;
// ----------------------------------------------------------------------------
/// \class SCSDbmServer
/// \brief Dbm server services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDbmServer : public SCSServer {
public:
	/// \enum Type
	/// \par Description:
	/// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
	enum Type { scs_type = 2 };
	/// \par Description:
	/// Creates a new Scadasoft server services.
	/// \param[in] envname The Scadasoft server environment name.
	/// \param[in] servername The Scadasoft service name.
	SCSDbmServer(const char* envname, const char* servername);
	virtual ~SCSDbmServer();
	/// \par Description:
	/// Tries to establish a connection to the Scadasoft server.
	/// \param[in] direct Indicates whether or not the connection must be direct.
	/// \return The operation result (true means a success, false otherwise).
	virtual bool connect(bool direct = false);
	/// \par Description:
	/// Tries to close the connection to the Scadasoft server.
	/// \return The operation result (true means a success, false otherwise).
	virtual bool disconnect();
	/// \par Description:
	/// Reads Dbm points (addresses) from Scadasoft server.
	/// \param[in] addressList The Dbm addresses table to read.
	/// \param[in] nbaddress The size of the Dbm addresses table.
	/// \return A Dbm dataset.
	DbmDataSet* read(const char** addressList, int nbaddress);
	/// \par Description:
	/// Modifies a set of Scadasoft Dbm point using a Dbm dataset.
	/// \param[in] dataset The Dbm dataset.
	/// \return True if the operation succeed, false otherwise.
	bool write(const DbmDataSet* dataset);
	/// \par Description:
	/// Conversion of a DbmDataSet to a DbmDirectDataSet.
	/// \param[in] dataset The Dbm dataset source.
	/// \return If conversion succeed, a (not owned) DbmDirectDataSet, null otherwise.
	DbmDirectDataSet* directWrite(const DbmDataSet* dataset);

	// method to manipulate DB Classes
	int getClasses(char** &classNames, int& count);

	int getClassName(const char* dbpoint, char*& className);

	int getClassId(const char* dbpoint, int& classId);

	int getUserClassId(const char* dbpoint, int& userClassId);

	int getClassInfo(const char* className, int& nbinstances, int& classid, int& stPeriod, int& mtPeriod, int& nbST, int& nbMT);

	//-------------------- API for instances management

	//   /**
	//        \par Description:
	//        return the alias of a database point. The address returned contains the point alias beginning with the <em>\<alias\></em> view specifier.
	//        \param address  [inout]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getAlias(ScsAddress &address) const;
	int getAlias(const char* dbaddress, char*& dbalias);

	//     /**
	//        \par Description:
	//        return the full path of a point. The address returned is a symbolic address equivalent which is the absolute path to the given addres, and to the same level.
	//        \param address  [inout]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getFullPath(ScsAddress &address) const;
	int getFullPath(const char* dbaddress, char*& fullpath);

	//     /**
	//        \par Description:
	//        return the children addresses of a database point. The memory of the output arrays is caller responsibility.
	//        \param parent  [in]: <em>ScsAddress</em> object containing a symbolic description of the parent point address in database.
	//        \param children  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a child point. The symbolic description contains the parent point alias and the name of the child point (&quot;<em>\<alias\>parent_alias:child_point_name</em>&quot;).
	//        \param count  [out]: the number of child points the queried point has.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getChildren(const ScsAddress  &parent,
	//   			ScsAddress       *&children,
	//   			short             &count) const;

	int getChildren(const char* dbaddress, char** &children, int& count);
    
    int getChildrenAliases(const char* dbaddress, char** &children, int& count);

	//     /**
	//        \par Description:
	//        return the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
	//        \param className  [in]: name of the class.
	//        \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
	//        \param count  [out]: the number of instances of the specified class.
	//        \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getInstances(const char  *className,
	//   			 ScsAddress *&instances,
	//   			 unsigned int &count,
	//   			 const char  *subTree = NULL) const;

	int getInstancesByClassName(const char* className, char** &instances, int& count, const char* subTree);

	//
	//     /**
	//        \par Description:
	//        return the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
	//        \param classId  [in]: id of the class.
	//        \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
	//        \param count  [out]: the number of instances of the specified class.
	//        \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getInstances(unsigned short   classId,
	//   			 ScsAddress     *&instances,
	//   			 unsigned int    &count,
	//   			 const char      *subTree = NULL) const;
	//
	//

	int getInstancesByClassId(int classId, char** &instances, int& count, const char* subTree);

	//     /**
	//        \par Description:
	//        return the address of all the instances of specified class in the database. The <em>subTree</em> parameter is an optional parameter which specifies a subtree of the database which is to be searched for points matching specified class.
	//        \param classId  [in]: id of the class.
	//        \param instances  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of an instance of the specified class.
	//        \param count  [out]: the number of instances of the specified class.
	//        \param subTree  [in]: symbolic address (hierarchical or alias) of the point specifying a subtree of the database which is to be searched for matching points. If <em>subTree</em> is a null pointer, all points in the database are examined, else only points contained in the subtree under the specified point are examined.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getInstancesByUserClassId(unsigned short   classId,
	//   			 ScsAddress     *&instances,
	//   			 unsigned int &count,
	//   			 const char      *subTree = NULL) const;

	int getInstancesByUserClassId(int classId, char** &instances, int& count, const char* subTree);

	//     /**
	//        \par Description:
	//        return the points whose name matches regular expression in the point subtree.
	//        \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
	//        \param regexpr  [in]: regular expression the name must match.
	//        \param adresses  [out]: list of the addresses of the matching points.
	//        \param count  [out]: number of adresses.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus queryByName(const ScsAddress  &point,
	//   			const char*	       regexpr,
	//   			ScsAddress       *&adresses,
	//   			unsigned long     &count) const;

	int queryByName(const char* subTree, const char* regexpr, char** &instances, int& count);

	//-------------------- API for attribute management

	//
	//     /**
	//        \par Description:
	//        return the structure of a point attribute (its type, <em>SCS_SCALAR</em>, <em>SCS_VECTOR</em> or <em>SCS_TABLE</em>, its number of fields, its number of records and the size of a record).
	//        \param address  [in]: <em>ScsAddress</em> object containing a symbolic description of the point attribute address in database.
	//        \param type  [out]: attribute type, <em>ScsData::SCS_SCALAR</em>, <em>ScsData::SCS_VECTOR</em> or <em>ScsData::SCS_TABLE</em> (see <em>ScsData::AttributeType</em> enumeration).
	//        \param fieldCount  [out]: the number of fields. This is always 1 for scalar or vector attributes (vectors are considered to occupy many records, but only one field).
	//        \param recordCount  [out]: the number of records. This is always 1 for a scalar attribute.
	//        \param recordUsed  [out]: the number of records in use. This is always 1 for a scalar attribute. For a vector attribute, it is equal to <em>recordCount</em>.
	//        \param recordSize  [out]: the size in bytes of a record. For scalar or vector attributes, this is the size of a single data element.
	//        \param fieldNames  [out]: the name of the fields for a table.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getAttributeStructure(const ScsAddress       &address,
	//   				  ScsData::AttributeType &type,
	//   				  short                  &fieldCount,
	//   				  short                  &recordCount,
	//   				  short                  &recordUsed,
	//   				  unsigned int           &recordSize,
	//   				  char**           &fieldNames) const;
	// enum  ScsData::AttributeType { 
	//  SCS_SCALAR = 0,
	//  SCS_VECTOR,
	//  SCS_TABLE
	// };
	//

	int getAttributeStructure(const char* attAddress, int& attType, int& fieldCount, int& recordCount, int& recordSize, char**& fieldNames);

	//     /**
	//        \par Description:
	//        return the attribute names for a database point, in the alphabetical order. Only the attributes of type <em>type</em> are returned if its value is different of <em>ScsUNKNOWN</em>.
	//        \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
	//        \param attribute  [out]: list of <em>ScsAddress</em> objects, each one containing a symbolic description for an attribute of the point. The symbolic description contains the point alias and the name of the attribute.
	//        \param count  [out]: the number of attributes the queried point has.
	//        \param type  [in]: a type of attribute.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getAttributes(const ScsAddress  &point,
	//   			  ScsAddress       *&attribute,
	//   			  short             &count,
	//   			  ScsType            type = ScsUNKNOWN) const;
	//

	int getAttributes(const char* pointAddress, int& count, char**& attributes);

	//     /**
	//        \par Description:
	//        get the definition of all the attributes of a class.
	//        \param className  [in]:  name of the class.
	//        \param attrNames [out]: list of the name for the attributes.
	//        \param valueTypes [out] : list of the value type for the attributes.
	//        \param attrTypes [out] : list of the type (static, dynamic, hictoric) for the attributes.
	//        \param replicated [out] : list of the value for replication for the attributes.
	//        \param defaultValues [out] : list of the default value for the attributes.
	//        \param count [out] : number of elements in the returned list.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getAttributesDescription(const char*   className,
	//   				     char**       &attrNames,
	//   				     ScsType*     &valueTypes,
	//   				     int*         &attrTypes,
	//   				     int*         &replicated,
	//   				     ScsData*     &defaultValues,
	//   				     short        &count) const;

	int getAttributesDescription(const char* className, char**& attrNames, int*& valueTypes, char**& defaultValues, int& count);

	//-------------------- API for CE function management
	//
	//     /**
	//        \par Description:
	//        get the CE operation indicator for one or more database points. The returned operation indicators can be of the <em>CEOperationMode</em> enumerate values: <em>SCS_CE_DISABLED</em>, <em>SCS_CE_ENABLED</em> or <em>SCS_CE_ENABLED_OPT_A</em>. This query will never return the value <em>SCS_DISABLED_NORUN</em> which is only used for <em>controlCE()</em>.
	//        \param points  [in]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a point address in database.
	//        \param operationIndicators  [out]: list of operation indicators.
	//        \param count  [in]: the number of points (and also operation indicators returned).
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getCEOper(const ScsAddress*  points,
	//   		      CEOperationMode*&  operationIndicators,
	//   		      const unsigned int count) const;
	/*
	 * 	      enum CEOperationMode { 
    				SCS_CE_DISABLED = 0,
    				SCS_CE_DISABLED_NORUN,
    				SCS_CE_ENABLED,
    				SCS_CE_ENABLED_OPT_A,
    				SCS_CE_ENABLED_NORUN
    			  };
	 */

	int getCEOper(const char* points[], int*& operationIndicators, int count);

	//
	//     /**
	//        \par Description:
	//        control the CE activation for one or more database points.
	//        \param points  [in]: list of <em>ScsAddress</em> objects, each one containing a symbolic description of a point address in database.
	//        \param operationModes  [in]: list of CE operation mode values. Each value corresponds to the point at the same index int the <em>point</em> list. The possible values are defined in the <em>CEOperationMode</em> enumerate.
	//        \param count  [in]: the number of points (or operation mode values).
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmRtapFunctionError : a database control operation has failed.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus controlCE(const ScsAddress      *points,
	//   		      const CEOperationMode *operationModes,
	//   		      const unsigned int     count) const;

	int controlCE(const char* points[], const int operationIndicators[], int count);

	//     /**
	//        \par Description:
	//        return the attribute formulas definitions for a database point, in the attribute order. 
	//        It is caller responsibility to free the allocated memory.
	//        \param point  [in]: <em>ScsAddress</em> object containing a symbolic description of the point address in database.
	//        \param formulas  [out]: list of formulas definitions. An empty string means no definition.
	//        \param evaluationOrders  [out]: list of evaluation order ranks.
	//        \param activationStates  [out]: list of activation flags. 1 means enable, 0 means disable.
	//        \param count  [out]: the number of attributes the queried point has.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getAttributeFormulas(const ScsAddress  &point,
	//   				 const char*      *&formulas,
	//   				 long*		   &evaluationOrders,
	//   				 short*		   &activationStates,
	//   				 short             &count) const;

	int getAttributeFormulas(const char* pointAddress, char**& formulas, int*& evaluationOrders, int*& activationStates, int& count);

	//
	//     /**
	//        \par Description:
	//        set a formula for an attribute.
	//        \param attribute  [in]: <em>ScsAddress</em> object containing a symbolic description of the attribute address in database.
	//        \param formula  [in]: formula definition.
	//        \param errorMsg [out] : error message.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmBadReferenceError : the address does not correspond to a database entry.
	//        \li \c DbmFormulaSyntaxError : the formula definition is not syntactically correct.
	//        \li \c DbmDependencyCycleError : the formula insertion creates a new dependency cycle that is forbidden in the current mode.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus setAttributeFormula(const ScsAddress &attribute,
	//   				const char*       formula,
	//   				char*            &errorMsg) const;
	//

	int setAttributeFormula(const char* pointAddress, const char* formula);

	//
	//     /**
	//        \par Description:
	//        activate or desactivate formulas for or from an instance path.
	//        \param path  [in]:  path of the instance (start of the tree) where formulas will be activated or desactivated.
	//        \param desactive [in]: if 0, formulas will be activated, if 1, formulas will be desactivated.
	//        \param branch [in]: if 0, formulas of an instance will be activated or desactived, if 1, formulas of an instance and beneath its tree will be activated or desactivated.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus activateFormulasOfInstances(const ScsAddress& path, short desactive = 0, short branch = 0) const;

	int activateFormulasOfInstances(const char* pointAddress, int desactive, int branch);

	//-------------------- API for Database management
	//
	//     /**
	//        \par Description:
	//        snapshot the database.
	//        \param type  [in]:  if 0, the snapshot is done in BINARY, if 1, the snapshot is done in XML.
	//        \param path [in]: if nil, files are written in SCSPATH/Database/binary for BINARY files or SCSPATH/Database/xml for XML files, else, files are written in path.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus forceSnapshot(short type = 0, const char* path = "") const;
	int forceSnapshot(int type, const char* path);

	//
	//     /**
	//        \par Description:
	//        get the information on the database.
	//        \param databaseInfo  [out]:  information on the database.
	//        \return
	//        \li \c ScsValid : success.
	//        \li \c DbmORBError : cannot connect with the remote DbmServer.
	//     */
	//     ScsStatus getDatabaseInfo(DbmDatabaseInfo &databaseInfo) const;

	int getDatabaseInfo(long long& size, int& nbClasses, int& nbInstances, int& nbFormulas, char*& scsPath);

	//
	//     /**
	//        \par Description:
	//        check the user formulas definition.
	//        \param nbUserFormulas  [out]:  number of user formulas.
	//        \param formulasNames [out]: list of names for user formulas.
	//        \param nbArgument [out] : list of number of arguments for user formulas.
	//        \return
	//        \li \c ScsValid : success.
	//     */
	//     ScsStatus getUserFormulasNames(int    &nbUserFormulas,
	//   				 char** &formulasNames,
	//   				 int*   &nbArgument) const;
	//
	int getUserFormulasNames(int& nbUserFormulasunt, char** &formulasNames, int*& nbArgument);

	/// \par Description:
	/// Returns the type of this Scadasoft service.
	/// \return The value of the type.
	virtual int serverType() const { return scs_type; }
	/// \par Description:
	/// Returns the native SCADAsoft server.
	/// \return The SCADAsoft server.
	DbmServer* getDbmServer() const;

protected:
	SCSDbmServer() : m_impl(NULL) {}
	SCSDbmServer(const SCSDbmServer&) : m_impl(NULL)  {}
	virtual void changeState();

private:
	class SCSDbmServerImpl;
	SCSDbmServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDBMSERVER_H
