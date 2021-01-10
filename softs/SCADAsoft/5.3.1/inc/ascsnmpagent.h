/******************************************************************************/
/*									      */
/*  FILE		: ascsnmpagent.h                                      */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES-IS					      */
/*  CREATION DATE	: 2001/11/29					      */
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
#ifndef _ASCSNMPAGENT_H_
#define _ASCSNMPAGENT_H_

/** \file
 * \brief Handling external parameters in SNMP Agent.
 */

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/

class AscExtIdl;

/**
   \brief This class is one of the interface classes for the exported services of the <em>SNMP</em> SCADAsoft component.

   This class is used for fix SNMP external parameters in SNMP Agent.
\code#include "ascext.h"\endcode
*/
class SCSSNMP_API AscSNMPAgent
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface <em>AscExt</em> object connected to the <em>scssnmpd</em> process of current physical environment.
     \par Parameters:
     none.
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  AscSNMPAgent(const char* agentName = "SNMPAgent");
  //@}

  ~AscSNMPAgent();

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the <em>scssnmpd</em> process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c AscORBError : cannot connect with the local <em>scssnmpd</em>.
  */
  ScsStatus getStatus() const { return _status;};
  /**
     \par Description:
     this function changes the <em>value</em> of external SNMP parameter for index <em>index</em>.
     \param index  [in]: index of parameter,
     \param value  [in]: value of parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus setParameter(int index, const char *value);
  /**
     \par Description:
     this function return the <em>value</em> of external SNMP parameter for index <em>index</em>.
     \param index  [in]: index of parameter,
     \param value  [out]: value of parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getParameter(int index, char *&value);
  /**
     \par Description:
     this function changes the <em>value</em> of external SNMP parameter for name <em>name</em>.
     \param name  [in]: name of parameter,
     \param value  [in]: value of parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus setParameterName(const char *name, const char *value);
  /**
     \par Description:
     this function return the <em>value</em> of external SNMP parameter for name <em>name</em>.
     \param name  [in]: name of parameter,
     \param value  [out]: value of parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getParameterName(const char *name, char *&value);
  /**
     \par Description:
     this function changes the <em>name</em> of <em>index</em> of external SNMP parameter.
     \param name  [in]: name of parameter,
     \param index  [in]: index of parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
    */
  ScsStatus setNameAtIndex(const char *name, int index);
  /**
     \par Description:
     this function return the <em>name</em> of external SNMP parameter with <em>index</em>.
     \param index  [in]: index of parameter,
     \param name  [out]: name of parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
    */
  ScsStatus getNameOfIndex(int index, char *&name);
  /**
     \par Description:
     this function return the <em>index</em> of external SNMP parameter with <em>name</em>.
     \param name  [in]: name of parameter,
     \param index  [out]: index of parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
    */
  ScsStatus getIndexOfName(const char* name, int &index);

  //@}

private:
   
  ScsStatus             _status;
  AscExtIdl            *_ascext;
 
};

#endif
