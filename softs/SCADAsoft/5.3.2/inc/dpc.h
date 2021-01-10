/******************************************************************************/
/*									      */
/*  FILE		: dpc.h                                               */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1999/11/29					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Definition of C++ class DpcServer providing ORB client access to    */
/*	the DPC component servers (dpceqpmgr and dpcvarmgr processes)         */
/*	An object of such a class must be built be the client process in      */
/*	order to access services to this component                            */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
// IDENTIFICATION:
// $Id$
//
// HISTORY:
// $Log$
/******************************************************************************/
#ifndef _DPC_H
#define _DPC_H

/**
   \file
   \brief ORB client access to the DPC component servers
*/

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"
#include "manager.h"

// Definition of DPC module trace function
#define DpcTrace	ScsTraceFunction(DPC_SCSMODULE)


/**
   Max length for the value of a structured internal input variable (SIIV).
\code#include "dpc.h"\endcode
\code#define DPC_K_MAX_SIIV_VALUE_SIZE   512\endcode
   A structured internal input variable is stored as a buffer of bytes. The current define is the maximum size of this buffer. Contents of such a buffer may be miscellaneous and is not checked: the structure is conventionnal between the field device and the concerned application program.
*/
#define DPC_K_MAX_SIIV_VALUE_SIZE	512

/**
   Name of the inhibited equipment and variables list.
\code#include "dpc.h"\endcode
\code#define DPC_K_EQP_VAR_LIST_NAME  "DpcInhibList"\endcode
   This define corresponds to the name of the inhibited equipment and variables list managed by the DPCEQP server. This name is used by a client process to remotely subscribe to the modifications of the list.
*/
#define DPC_K_EQP_VAR_LIST_NAME		"DpcInhibList"

/**
   Name of source variable when DpcVarServer call DpcEqpServer.
\code#include "dpc.h"\endcode
\code#define DPCVAR_SOURCE_FOR_HOOK  "__DpcVarServer__"\endcode
   This define corresponds to the name of the source variable when DpcVarServer call DpcEqpServer. This is usefull to write hooks.
*/
#define DPCVAR_SOURCE_FOR_HOOK "__DpcVarServer__"

class DpcEqpServerProxy;


/**
   \brief This class is the interface class for the exported services of the <em>DPC</em> component (Data Processing and Calculation): it allows to change an equipment status or an internal variable status.

   This class is the interface class for the services exported by the DPCEQP server. It is used to change an equipment status or an internal input variable (IIV) status. 
\code#include "dpc.h"\endcode
*/
class DPCE_API DpcEqpServer
{
public:
  /**@name Typedefs / defines*/
  //@{
  /**
      \par Description:
     enum corresponding to the possible values for the new working status to be given to an equipment (see <em>changeEqpStatus()</em> function).
      \code
      enum WorkingStatus { 
         OUT_OF_SERVICE = 0,
         CONTROL_INHIBITED,
         IN_SERVICE,
         ALARM_INHIBIT_EQP,
         NO_ALARM_INHIBIT_EQP
      }; \endcode
      \par Values:
      \li \c OUT_OF_SERVICE :  the working status of the equipment is &quot;<em>out of service</em>&quot; (full inhibited). All the monitoring and control functions are inhibited.
      \li \c CONTROL_INHIBITED :  the working status of the equipment is &quot;<em>control inhibited</em>&quot;. Control functions are inhibited, but monitoring functions remains unaffected.
      \li \c IN_SERVICE :  the working status of the equipment is &quot;<em>in service</em>&quot;. All the monitoring and control functions are normal.
      \li \c ALARM_INHIBIT_EQP :  the working status of the equipment is &quot;<em>valid - alarm inhibit</em>&quot;. An alarm inhibition is set on the equipment. The monitoring and control functions are not changed.
      \li \c NO_ALARM_INHIBIT_EQP :  the alarm inhibition is removed on the equipment. The monitoring and control functions are not changed.
  */
  enum WorkingStatus { 
    OUT_OF_SERVICE = 0,
    CONTROL_INHIBITED,
    IN_SERVICE,
    ALARM_INHIBIT_EQP,
    NO_ALARM_INHIBIT_EQP
  };

  /**
      \par Description:
     enum corresponding to the possible values for the new tagging status to be given to an equipment (see <em>changeEqpTag()</em> function).
      \code
      enum TaggingStatus { 
         ALL_TAGGING = 0,
         TAGGING_1,
         TAGGING_2,
         NO_TAGGING
      }; \endcode
      \par Values:
      \li \c ALL_TAGGING :  the tagging status of the equipment is &quot;<em>Tag 1 and tag 2</em>&quot;.
      \li \c TAGGING_1 :  the tagging status of the equipment is &quot;<em>Tag 1</em>&quot;.
      \li \c TAGGING_2 :  the tagging status of the equipment is &quot;<em>Tag 2</em>&quot;.
      \li \c NO_TAGGING :  the tagging status of the equipment is &quot;<em>Normal - no tagging</em>&quot;.
  */
  enum TaggingStatus { 
    ALL_TAGGING = 0,
    TAGGING_1,
    TAGGING_2,
    NO_TAGGING
  };

  /**
      \par Description:
     enum corresponding to the possible values for the new validity status to be given to an internal input or output variable (see <em>changeVarStatus()</em> function).
      \code
      enum ValidityStatus { 
         OPERATOR_INHIBIT = 0,
         VALID,
         ALARM_INHIBIT_VAR,
         NO_ALARM_INHIBIT_VAR,
         CHATTER_INHIBIT_VAR,
         NO_CHATTER_INHIBIT_VAR
      }; \endcode
      \par Values:
      \li \c OPERATOR_INHIBIT :  the variable is invalided with state &quot;<em>Invalid - Variable inhibited</em>&quot;,
      \li \c VALID :  this value suppress the states of invalidity &quot;<em>Invalid - Variable inhibited</em>&quot;.
      \li \c ALARM_INHIBIT_VAR :  an alarm inhibition is set on the variable (the operator invalidation state is not changed),
      \li \c NO_ALARM_INHIBIT_VAR :  the alarm inhibition is removed (the operator invalidation state is not changed).
      \li \c CHATTER_INHIBIT_VAR :  the variable is invalided due to IO chattering detection.
      \li \c NO_CHATTER_INHIBIT_VAR : the chattering detection is off, suppress the inhibition due to chattering.
  */
  enum ValidityStatus { 
    OPERATOR_INHIBIT = 0,
    VALID,
    ALARM_INHIBIT_VAR,
    NO_ALARM_INHIBIT_VAR,
    CHATTER_INHIBIT_VAR,
    NO_CHATTER_INHIBIT_VAR
  };

  /**
      \par Description:
     enum corresponding to the possible values for the new forced status to be given to an internal input variable (see <em>changeVarForce()</em> functions).
      \code
      enum ForcedStatus { 
         NOT_FORCED = 0,
         FORCED
      }; \endcode
      \par Values:
      \li \c NOT_FORCED :  the value of the internal input variable takes back the field value and the state &quot;<em>Valid - Forced value</em>&quot; is annulated for the status,
      \li \c FORCED :  the value of the internal input variable is forced and the status is changed to &quot;<em>Valid - Forced value</em>&quot;, only if the variable is valid.
  */
  enum ForcedStatus { 
    NOT_FORCED = 0,
    FORCED
  };
  //@}

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the DPCEQP server. Only one connection is made to the DPCEQP server for all the exported services of the DPC component.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required DPCEQP server is running.
     \param priority  [in]: priority of the messages to the DpcEqpServer (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  DpcEqpServer(const char *logicalEnv, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);
  
  /**
     \par Description:
     destructor. This function closes the connection with the DPCEQP server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~DpcEqpServer();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the DPCEQP server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c DpcHostServerError : cannot connect with the ascmanager process.
     \li \c DpcORBError : cannot connect with the remote DPCEQP server.
  */
  ScsStatus getStatus() const { return _status;};
  
  /**
     \par Description:
     this function deactivates the embedded CORBA services.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
  */
  ScsStatus deactivate();
  
  /**
     \par Description:
     this function changes the working status of an equipment.
     <em>IN_SERVICE</em>: suppress for the IIV and IOV variables the state of invalidity &quot;<em>Invalid - Equipment inhibited</em>&quot;; no effect on the other states of invalidity.
     <em>CONTROL_INHIBITED</em>: invalidate only the IOV variables with the state &quot;<em>Invalid - Equipment inhibited</em>&quot;.
     <em>OUT_OF_SERVICE</em>: invalidate all the IOV and IIV variables with the state &quot;<em>Invalid - Equipment inhibited</em>&quot;.
     \param equipmentName  [in]: name of the equipment (Rtap alias or symbolic address).
     \param newStatus  [in]: new working status to be assigned.
     \param source  [in]: source of the request. This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \return
     \li \c ScsValid : success.
     \li \c DpcDBAccessError : database access error.
     \li \c DpcEquipmentStatusError : equipment status error.
     \li \c DpcORBError : ORB communication error (exception raised).
     \li \c DpcScadasoftFunctionError : SCADAsoft function error.
  */
  ScsStatus changeEqpStatus(const char    *equipmentName,
			    WorkingStatus  newStatus,
			    const char    *source = NULL);
  
  /**
     \par Description:
     this function is used for the tagging of an equipment.
     <em>NO_TAGGING</em>: suppress all the tagging on the equipment.
     <em>TAGGING_1</em>: set the tagging 1 on the equipment.
     <em>TAGGING_2</em>: set the tagging 2 on the equipment.
     <em>ALL_TAGGING</em>: set the tagging 1 and 2 on the equipment.
     \param equipmentName  [in]: name of the equipment (Rtap alias or symbolic address).
     \param newStatus  [in]: new tagging status to be assigned.
     \param source  [in]: source of the request. This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \param taggingLabel1  [in]: description of the tagging 1.
     \param taggingLabel2  [in]: description of the tagging 2.
     \return
     \li \c ScsValid : success.
     \li \c DpcDBAccessError : database access error.
     \li \c DpcEquipmentStatusError : equipment status error.
     \li \c DpcORBError : ORB communication error (exception raised).
     \li \c DpcScadasoftFunctionError : SCADAsoft function error.
  */
  ScsStatus changeEqpTag(const char    *equipmentName,
			 TaggingStatus  newStatus,
			 const char    *source = NULL,
			 const char    *taggingLabel1 = NULL,
			 const char    *taggingLabel2 = NULL);

  /**
     \par Description:
     this function changes the validity status of an internal input or output variable (IIV or IOV).
     \param variableName  [in]: name of the internal variable (Rtap alias).
     \param newStatus  [in]: new validity status to be assigned.
     \param source  [in]: source of the request. This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \return
     \li \c ScsValid : success.
     \li \c DpcDBAccessError : database access error.
     \li \c DpcORBError : ORB communication error (exception raised).
     \li \c DpcScadasoftFunctionError : SCADAsoft function error.
     \li \c DpcVariableStatusError : variable status error.
  */
  ScsStatus changeVarStatus(const char     *variableName,
			    ValidityStatus  newStatus,
			    const char     *source = NULL);

  /**
     \par Description:
     this function changes the forced status and value of a discrete internal input variable (DIIV).
     \param variableName  [in]: name of the discrete internal input variable (Rtap alias).
     \param newStatus  [in]: new forced status to be assigned.
     \param newValue  [in]: new discrete value to be assigned (if forced).
     \param source  [in]: source of the request. This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \return
     \li \c ScsValid : success.
     \li \c DpcDBAccessError : database access error.
     \li \c DpcORBError : ORB communication error (exception raised).
     \li \c DpcScadasoftFunctionError : SCADAsoft function error.
     \li \c DpcVariableStatusError : variable status error.
  */
  ScsStatus changeVarForce(const char   *variableName,
			   ForcedStatus  newStatus,
			   int           newValue,
			   const char   *source = NULL);

  /**
     \par Description:
     this function changes the forced status and value of an analogic internal input variable (AIIV).
     \param variableName  [in]: name of the analogic internal input variable (Rtap alias).
     \param newStatus  [in]: new forced status to be assigned.
     \param newValue  [in]: new analogic value to be assigned (if forced).
     \param source  [in]: source of the request. This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \return
     \li \c ScsValid : success.
     \li \c DpcDBAccessError : database access error.
     \li \c DpcORBError : ORB communication error (exception raised).
     \li \c DpcScadasoftFunctionError : SCADAsoft function error.
     \li \c DpcVariableStatusError : variable status error.
  */
  ScsStatus changeVarForce(const char   *variableName,
			   ForcedStatus  newStatus,
			   float         newValue,
			   const char   *source = NULL);
  /**
     \par Description:
     this function changes the forced status and value of a structured internal input variable (SIIV).
     \param variableName  [in]: name of the structured internal input variable (Rtap alias).
     \param newStatus  [in]: new forced status to be assigned.
     \param newValue  [in]: new structured value to be assigned (if forced).
     \param valueSize  [in]: size of new value to be assigned (maximum 512 bytes).
     \param source  [in]: source of the request. This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \return
     \li \c ScsValid : success.
     \li \c DpcDBAccessError : database access error.
     \li \c DpcORBError : ORB communication error (exception raised).
     \li \c DpcScadasoftFunctionError : SCADAsoft function error.
     \li \c DpcVariableStatusError : variable status error.
  */
  ScsStatus changeVarForce(const char    *variableName,
			   ForcedStatus   newStatus,
			   unsigned char *newValue,
			   int            valueSize,
			   const char    *source = NULL);

  /**
     \par Description:
     return the name of the DPCEQP server to which the interface object is connected.
     \par Parameters:
     none.
     \par Return values:
     the name of the server.
  */
  const char *getServerName() { return _serverName;};
  
  /**
     \par Description:
     return the logical SCADAsoft environment name of the DPCEQP server to which the interface object is connected.
     \par Parameters:
     none.
     \par Return values:
     the name of the environment.
  */
  const char *getServerEnv() { return _envName;};

  /**
     \par Description:
     this function checks the status of an internal variable (see ValidityStatus).
     \param VarStatus  [in]: internal variable status.
     \par Return values:
     1 if status is set to valid, 0 otherwise.
  */
  int isVarStatusValid(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable (see ForcedStatus).
     \param VarStatus  [in]: internal variable status.
     \par Return values:
     1 when variable status is forced, 0 otherwise.
  */
  int isVarStatusForced(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable (see WorkingStatus).
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when alarm inhibition is set on the equipment, 0 otherwise.
  */
  int isVarStatusAlaInhEqp(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable (see WorkingStatus).
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when alarm inhibition is set on the variable, 0 otherwise.
  */
  int isVarStatusAlaInh(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable (see WorkingStatus).
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is invalid by equipment, 0 otherwise.
  */
  int isVarStatusInvEqp(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable (see ValidityStatus).
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is invalid by operator, 0 otherwise.
  */
  int isVarStatusInvOperator(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable (see WorkingStatus).
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is invalid by equipment, 0 otherwise.
  */
  int isVarStatusInvCom(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable.
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is invalid due to concentrator, 0 otherwise.
  */
  int isVarStatusInvConc(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable.
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is invalid due a bad operand, 0 otherwise.
  */
  int isVarStatusInvOperand(const int    VarStatus);
  
  /**
     \par Description:
     this function checks the status of an internal variable.
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is invalid due IO chattering detection, 0 otherwise.
  */
  int isVarStatusInvChattering(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an internal variable.
     \param VarStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is invalid due to the application, 0 otherwise.
  */
  int isVarStatusInvApplication(const int    VarStatus);

  /**
     \par Description:
     this function checks the status of an equipment (see WorkingStatus).
     \param EqpStatus  [in]: internal input variable status.
     \par Return values:
     1 when status is normal, 0 otherwise.
  */  
  int isEqpStatusNormal(const int    EqpStatus);

  /**
     \par Description:
     this function checks the status of an equipment (see WorkingStatus).
     \param EqpStatus  [in]: internal input variable status.
     \par Return values:
     1 when status has been set to ALARM_INHIBIT_EQP, 0 otherwise.
  */  
   int isEqpStatusAlarm(const int    EqpStatus);

  /**
     \par Description:
     this function checks the status of an equipment (see WorkingStatus).
     \param EqpStatus  [in]: internal input variable status.
     \par Return values:
     1 when status has been set to CONTROL_INHIBITED, 0 otherwise.
  */  
  int isEqpStatusCtrlInh(const int    EqpStatus);

  /**
     \par Description:
     this function checks the status of an equipment (see WorkingStatus).
     \param EqpStatus  [in]: internal input variable status.
     \par Return values:
     1 when status has been set to OUT_OF_SERVICE, 0 otherwise.
  */  
  int isEqpStatusMonInh(const int    EqpStatus);
  
  /**
     \par Description:
     this function checks the tagging status of an equipment (see TaggingStatus).
     \param EqpTagStatus  [in]: internal input variable status.
     \par Return values:
     1 when tagging status is normal, 0 otherwise.
  */  
  int isEqpTagStatusNormal(const int    EqpTagStatus);

  /**
     \par Description:
     this function checks the tagging status of an equipment (see TaggingStatus).
     \param EqpTagStatus  [in]: internal input variable status.
     \par Return values:
     1 when the equipment has been tagged with tag1, 0 otherwise.
  */  
  int isEqpTagStatusTag1(const int    EqpTagStatus);

  /**
     \par Description:
     this function checks the tagging status of an equipment (see TaggingStatus).
     \param EqpTagStatus  [in]: internal input variable status.
     \par Return values:
     1 when the equipment has been tagged with tag2, 0 otherwise.
  */  
  int isEqpTagStatusTag2(const int    EqpTagStatus);
  //@}

private:

  DpcEqpServerProxy *_proxy;
  ScsStatus          _status;
  char              *_envName;
  char              *_serverName;            
};

#endif
