/******************************************************************************/
/*                                                                            */
/*  FILE                : confmanagerh                                    */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 06-29-10                                            */
/*  LANGUAGE            : C++                                                 */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*............................................................................*/
/*  CONTENTS                                                                  */
/******************************************************************************/
/* IDENTIFICATION:
 *
 * HISTORY:
 */
/******************************************************************************/

#ifndef __SCS_ecomlib_ConfManager_H__
#define __SCS_ecomlib_ConfManager_H__

#include <ecomlib/ecomlib_exports.h>

#include <exception>
#include <string>
#include <vector>

// Forward declaration of Private implementation class (PIMPL)
class ConfManagerParserImpl;

namespace ecomlib {

// Exception class that ConfManager may raise
class ECOMLIBIF_EXPORT ConfManagerException: public std::exception
{
public:
    ConfManagerException(const std::string& what="") throw()
         :_what(what)  {}
    virtual ~ConfManagerException() throw() {}
    virtual const char* what() const throw()  { return _what.c_str();}
private:
    std::string _what;  
};

    
/**
 * @class ConfManager
 *
 * @brief A simple singleton class that read an XML file containing SCOPE and CONF key
 *            elements. All key/value pairs are stored into a map and can be accessed with
 *            typed accessors. Example:
 *  <root>
 *     <SCOPE name= "SCS">   
 *         <CONF key = "ConnectStandbyDacCom">on</CONF>
 *         <CONF key = "List"> 1, 2, 3</CONF>
 *     </SCOPE>
 *  </root>
 *
 * A scope must contain at least one key, otherwise it is not taken into account by the ConfManager.
 *
 * To retrieve the values : 
 *      bool value = ConfManager::instance()->getBoolKey("SCS.ConnectStandbyDacCom")  =>  returns true
 *      vector<int> values = ConfManager::instance()->getIntListKey("SCS.List")    =>  returns [1, 2, 3]
 * 
 * To retrieve the sub-elements of a node : 
 *      bool value = ConfManager::instance()->getSubKeys("SCS")    =>  returns ["ConnectStandbyDacCom", "List"]
 */
class ECOMLIBIF_EXPORT ConfManager {
  
public:

    /**
    * singleton access
    */ 
    static ConfManager* instance();

    /**
    * read an XML file - clear previous conf keys if clearOldKeys is true
    */
    bool readfile(const std::string& xmlFile, const bool& clearOldKeys = true);

    /**
    * debug purpose - print all keys in the Trace file or return a COPY of all the keys
    */
    void printAllKeys();
    std::vector<std::string> allKeys();
    

    /**
    * typed accessors for any key
    * Note: a boolean may be "on" "yes" "1" "true" and "off" "no" "0" "false"
    * These methods can raise a ConfManagerException exception: key not found or value is not a boolean
    */
    std::string getStringKey(const std::string& keyName) ;
    int getIntKey(const std::string& keyName) ;
    bool getBoolKey(const std::string& keyName) ;
    float getFloatKey(const std::string& keyName) ;
    
    /** 
     * The following functions do not throw an exception in case of error, but 
     * print a level-0 trace and return false.
     * @{
     */
    
    bool getStringKeyNE(const std::string& keyName, std::string& result);
    bool getShortKeyNE(const std::string& keyName, short& result);
    bool getUnsignedShortKeyNE(const std::string& keyName, unsigned short& result);
    bool getIntKeyNE(const std::string& keyName, int& result);    
    bool getUnsignedKeyNE(const std::string& keyName, unsigned& result);
    bool getLongKeyNE(const std::string& keyName, long& result);
    bool getUnsignedLongKeyNE(const std::string& keyName, unsigned long& result);
    bool getFloatKeyNE(const std::string& keyName, float& result);    
    bool getBoolKeyNE(const std::string& keyName, bool& result);


     /** @} */

    std::vector<std::string> getStringListKey(const std::string& keyName) ;
    std::vector<int> getIntListKey(const std::string& keyName) ;
    std::vector<bool> getBoolListKey(const std::string& keyName) ;
    std::vector<float> getFloatListKey(const std::string& keyName) ;
    
    /**
    * return all sub-elements for a given node (both scopes and keys). 
    * This method raises no exception, but return may be empty.
    */
    std::vector<std::string> getSubKeys(const std::string& keyName) ;
    
    /**
    * Just tell me if a given key exists or not
    */
    bool exists(const std::string& keyName);
    
    /**
    * Utils
    */
    std::string strip(const std::string& str, const char * sepSet);
    
    void tokenize
    (
      const std::string& str, 
      std::vector<std::string>& tokens, 
      const std::string& delimiters, 
      bool removeToken = true
    );


private:
    ConfManager();
    virtual ~ConfManager();

    /**
    * init 
    */
    void initialize();

    /**
    * Copy constructor is private and not implemented.
    */
    ConfManager(const ConfManager&);

    /**
    * Assigment operator is private and not implemented.
    */
    ConfManager& operator=(const ConfManager&);
    
    /**
    * Read a value in _keyValues dictionary. Raise an error if not found
    */
    std::string getValue(const std::string& keyName);

    /**
    * Reads a value in _keyValues dictionary. Returns false if not found.
    * Does not throw an exception.
    */
    bool getValueNE(const std::string& keyName, std::string& result);
    
    // utils
    bool string2bool(const std::string& value); // may Raise an error 
    bool string2boolNE(const std::string& value, bool& boolval);

    // Common processing between the different `get<integer-type>KeyNE` functions.

    template <typename Signed_Integer_Type, typename Convert_Function_Type>
    bool getNumericKeyNE(const std::string& keyName, 
        Signed_Integer_Type& result, 
        Convert_Function_Type convert,
        const char* type_str);
    
private:
    bool m_initialized;
    
    ConfManagerParserImpl*  m_parserImpl;
};

}; // ecomlib namespace

#endif // define __SCS_ecomlib_ConfManager_H__

