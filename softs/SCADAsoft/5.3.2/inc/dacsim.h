/******************************************************************************/
/*									      */
/*  FILE		: dacsim.h                                            */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 2000/07/25					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Definition of C++ class DacSimulator providing ORB client access to */
/*	the DACSIM component server (daccomsim process)                       */
/*	An object of such a class must be built by the client process in      */
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
#ifndef _DACSIM_H
#define _DACSIM_H

/** \file
    \brief DacSimulator definition, providing ORB client access to 
 	the DACSIM component server (daccomsim process)

     An object of such a class must be built by the client process in 
     order to access services to this component
 */

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"

// -----------------------------------------------------------------
// Type of callback called by the DacSim server for EOV notification
// -----------------------------------------------------------------
/**
   Prototype of the external output variables (EOV) notification callback function.
\code#include "dacsim.h"\endcode
   \par Description:
     This function may be written by the client application for external output variables (EOV) notification. The server will call this callback function to asynchronously notify the client about commands sent with the EOVs it subscribed to.
   \param varCount  [in]: number of EOVs.
   \param varNameTab  [in]: table containing the EOVs names.
   \param dataTab  [in]: table containing the values of the EOVs (stored in <em>ScsData</em> objects).
   \par Return values:
     none.
*/
typedef void (*DacSimCallback)
  (int varCount,                  // Variables count
   const char* const* varNameTab, // Table containing the variable names
   const ScsData* dataTab);       // Table containing the values of the variables

class DacSimServerIdl;
class DacSimClientIdl_i;
class SimEVList;

/**
   \brief Interface class for the exported services of the <em>DACSIM</em> component.

   This class is the interface class for the services exported by the <em>DACSIM</em> server. It is principally used to read and modify the values of external variables (EIV or EOV) and to subscribe to any command sent with external output variables (EOV).
\code#include "dacsim.h"\endcode
*/
class DACSIM_API DacSimulator
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the DACSIM server.
     \param serverEnv  [in]: name of the physical SCADAsoft environment in which the required <em>DACSIM</em> server is running.
     \param serverName  [in]: name of the <em>DACSIM</em> server (the use of the default name is recommended).
     \param notifCallback  [in]: address of the notification callback function which will be used to notify a client of any command sent with external output variables (EOV) it subscribed to. If <em>NULL</em> is given, then no subscriptions will be possible.
     \par Return values:
     none. The result of the connection could be obtained by calling the <em>getStatus()</em> function.
  */
  // serverEnv: physical environment of DacComSim process (ex: ComEnv_cactus)
  // serverName: name of DacComSim process (ex: DacCom_sim)
  // notifCallback: address of the notification callback function
  DacSimulator(const char* serverEnv,
               const char* serverName,
               const DacSimCallback notifCallback = 0);

  /**
     \par Description:
     destructor. This function closes the connection with the <em>DACSIM</em> server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~DacSimulator();
  //@}

  /**@name Public methods*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the <em>DACSIM</em> server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c DacHostServerError : cannot connect with the <em>ASCMANAGER</em> server.
     \li \c DacORBError : cannot connect with the required <em>DACSIM</em> server.
  */
  // Return the status of the connection to the DacSim server
  ScsStatus getStatus() const;

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
  
  // Return the address of the notification callback function
  DacSimCallback getCallback() const;

  /**
     \par Description:
     this function reconfigures online the reaction specifications by reading the modified file <em>$SCSPATH/DacSim/ReacSpec.cfg</em> (file describing which simulation script to execute for which external output variable).
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
  */
  // Configure: re-read the reaction configuration file
  ScsStatus configure() const;

  /**
     \par Description:
     this function reads the values of external variables (EIV or EOV).
     \param varSpec  [in]: external variables name specification (with wilcards).
     \param varCount  [out]: number of matching EIVs or EOVs.
     \param varNameTab  [out]: table containing the matching EIVs or EOVs names.
     \param dataTab  [out]: table containing the values of the matching EIVs or EOVs (stored in <em>ScsData</em> objects).
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
  */
  // Read external variables
  // varSpec: variable name specification (with wildcards)
  // varCount: matching variables count
  // varNameTab: table containing the variable names matching the specification
  // dataTab: table containing the values of the variables 
  ScsStatus readEV(const char* varSpec,
                   int& varCount,
                   char**& varNameTab,
                   ScsData*& dataTab) const;

  /**
     \par Description:
     this function modifies the value of external variables (EIV or EOV).
     \param varSpec  [in]: external variables name specification (with wilcards).
     \param data  [in]: value to be set to the matching EIVs or EOVs (stored in an <em>ScsData</em> object with the correct type, depending on the external variables type: <em>ScsINTEGER</em> for DEIVs or DEOVs, <em>ScsFLOAT</em> for AEIVs or AEOVs, <em>ScsBIT</em> for SEIVs or SEOVs).
     \param sec  [in]: modification time in seconds.
     \param usec  [in]: modification time in milliseconds.
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
  */
  // Write external variables
  // varSpec: variable name specification (with wildcards)
  // data: value to be set to the variables 
  ScsStatus writeEV(const char* varSpec,
                    const ScsData& data,
		    const unsigned long sec,
		    const unsigned long usec) const;

  ScsStatus writeGroupOfEV(SimEVList* evs);
  /**
     \par Description:
     this function subscribes (or unsubscribes) to commands sent with external output variables (EOV). Before using this function, in order to make possible further EOVs notifications, the caller must have specified in the constructor a non-<em>NULL</em> address for the notification callback function.
     The client can successively subscribe with several EOV name specifications.
     Only one client can subscribe to EOVs at a time. The current subscriber can't be changed until it unsubscribes with the EOV name specification <em>"*"</em> (wildcard for all EOVs).
     \param varSpec  [in]: external output variables name specification (with wilcards).
     \param subscrState  [in]: new subscription state to be set to the matching EOVs (<em>1</em> for subscribed, <em>0</em> for no longer subscribed).
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
     \li \c DacSimNoNotifCbError : no non-<em>NULL</em> address for the notification callback function was specified in the constructor.
  */
  // Subscribe to external output variables
  // varSpec: output variable name specification (with wildcards)
  // subscrState: new subscription state (true/false)
  ScsStatus subscribeEOV(const char* varSpec,
                         int subscrState) const;

  /**
     \par Description:
     this function freezes (or not freezes any more) the value of external input variables (EIV), this means the value changes will or not be notified to the <em>DACCONTROL</em> server.
     \param varSpec  [in]: external input variables name specification (with wilcards).
     \param freezeState  [in]: new freeze state to be set to the matching EIVs (<em>1</em> for frozen, <em>0</em> for no longer frozen).
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
  */
  // Freeze external input variables
  // varSpec: input variable name specification (with wildcards)
  // freezeState: new freeze state (true/false)
  ScsStatus freezeEIV(const char* varSpec,
                      int freezeState) const;

  /**
     \par Description:
     this function gets the freeze state of external input variables (EIV).
     \param varSpec  [in]: external input variables name specification (with wilcards).
     \param varCount  [out]: number of matching EIVs.
     \param varNameTab  [out]: table containing the matching EIVs names.
     \param freezeStateTab  [out]: table containing the freeze states of the matching EIVs (<em>1</em> for frozen, <em>0</em> for not frozen).
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
  */
  // Get frozen external input variables
  // varSpec: input variable name specification (with wildcards)
  // varCount: matching variables count
  // varNameTab: table containing the variable names matching the specification
  // freezeStateTab: table containing the freeze states (true/false) of the variables 
  ScsStatus getFrozenEIV(const char* varSpec,
                         int& varCount,
                         char**& varNameTab,
                         int*& freezeStateTab) const;

  /**
     \par Description:
     this function inhibits (or not inhibits any more) the reactions on external output variables (EOV), this means the reaction scripts for the commands will or not be executed by the <em>DACSIM</em> server.
     \param varSpec  [in]: external output variables name specification (with wilcards).
     \param inhibitState  [in]: new inhibition state to be set to the matching EOVs (<em>1</em> for inhibited, <em>0</em> for no longer inhibited).
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
  */
  // Inhibit external output variables
  // varSpec: output variable name specification (with wildcards)
  // inhibitState: new inhibition state (true/false)
  ScsStatus inhibitEOV(const char* varSpec,
                       int inhibitState) const;

  /**
     \par Description:
     this function gets the inhibition state of external output variables (EOV).
     \param varSpec  [in]: external output variables name specification (with wilcards).
     \param varCount  [out]: number of matching EOVs.
     \param varNameTab  [out]: table containing the matching EOVs names.
     \param inhibitStateTab  [out]: table containing the inhibition states of the matching EOVs (<em>1</em> for inhibited, <em>0</em> for not inhibited).
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
     \li \c DacSimServerError : an error was detected by the <em>DACSIM</em> server.
  */
  // Get inhibited external output variables
  // varSpec: output variable name specification (with wildcards)
  // varCount: matching variables count
  // varNameTab: table containing the variable names matching the specification
  // inhibitStateTab: table containing the inhibition states (true/false) of the variables 
  ScsStatus getInhibitedEOV(const char* varSpec,
                            int& varCount,
                            char**& varNameTab,
                            int*& inhibitStateTab) const;
  //@}

private:

  ScsStatus          _status;
  DacSimServerIdl   *_server;
  DacSimClientIdl_i *_client;
  DacSimCallback     _notifCallback;

};

#endif
