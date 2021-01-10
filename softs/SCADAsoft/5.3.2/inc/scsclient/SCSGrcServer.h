// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSGrcServer.h
// Date     : 2015/10/12
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCS_SCSGRCSERVER_H
#define SCS_SCSGRCSERVER_H

#include <vector>
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class CtlGrcServer;
class SCSGrcEventListener;


#define GRCEXECMODE_Auto 1
#define GRCEXECMODE_StopOnFailed 2
#define GRCEXECMODE_StopOnFirstBRCExecuted 3
  
#define GRCSTATE_NotExisting 0
#define GRCSTATE_Ready 1
#define GRCSTATE_Running 2
#define GRCSTATE_Inhibited 3
#define GRCSTATE_WaitForInitConf 4
#define GRCSTATE_Suspended 8

// ----------------------------------------------------------------------------
/// \class SCSGrcServer
///  \brief CTL Grouped Remote Control Server structure for the <em>CTLGRC</em> component.
///
///   This class is used to describe a command to send to an equipment. A command corresponds to an internal output variable (IOV). 
/// \code#include <scsclient/SCSGrcServer.h>\endcode
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSGrcServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of SCADAsoft service. Its value is unique and identifies this service among all others SCADAsoft services.
  enum Type { scs_type = 11 };
  /// \par Description:
  /// Creates a new SCADAsoft server services.
  /// \param[in] envname The SCADAsoft server environment name.
  /// \param[in] servername The SCADAsoft service name.
  SCSGrcServer(const char* envname, const char* servername);
  virtual ~SCSGrcServer();
  /// \par Description:
  /// Tries to establish a connection to the SCADAsoft server.
  /// \param[in] direct Indicates whether or not the connection must be direct.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool connect(bool direct = false);
  /// \par Description:
  /// Tries to close the connection to the SCADAsoft server.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool disconnect();
  
  /**
     \par Description:
     Return a list of all GRC defined in the RTDB. List may be empty.
     
     \return: list of existing GRC
    
  */
  std::vector<std::string>& getGrcList();
  
  /**
     \par Description:
     Get current status of GRC.
     /// \param[in]: GRC name.
     \return: current status
        \li \c GRCSTATE_NotExisting 0
        \li \c GRCSTATE_Ready 1
        \li \c GRCSTATE_Running 2
        \li \c GRCSTATE_Inhibited 3
        \li \c GRCSTATE_WaitForInitConf 4
        \li \c GRCSTATE_Suspended 8
    
  */
  int getGrcState(const char* in_grcName) const;
  
   /**
     \par Description:
     this function allows to trigger a preparation hook in the ctlgrcserver. It does nothing by default.
     \param in_grcName  [in]: GRC name.
     \param source      [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  int prepareGrc(const char* in_grcName, const char* source) const;

  /**
     \par Description:
     this function allows to trigger a hook in the ctlgrcserver to abort the preparation actions. It does nothing by default.
     \param in_grcName  [in]: GRC name.
     \param source      [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  int abortGrcPreparation(const char* in_grcName, const char* source) const;
  
  /**
     \par Description:
     this function launches a GRC starting a specified step and skips some steps.
     \param name   [in]: GRC name.
     \param mode   [in]: GRC mode.
     \param firstStep   [in]: index of the first step to execute.
     \param grcStepsToSkip  [in]: Array of GRC steps to skipp.
     \param nbGrcStepsToSkip     [in]: Array size.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  int launchGrc(const char* name, int grcExecMode, int firstStep, 
		        const int* grcStepsToSkip, int nbGrcStepsToSkip, const char* source,
				SCSGrcEventListener* listener) const;

  /**
     \par Description:
     this function aborts a GRC.
     \param in_grcName   [in]: GRC name.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  int abortGrc(const char* in_grcName, const char* source);

  /**
     \par Description:
     this function suspends a GRC.
     \param in_grcName   [in]: GRC name.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  int suspendGrc(const char* in_grcName, const char* source);
  
  /**
     \par Description:
     this function resumes a suspended GRC.
     \param in_grcName   [in]: GRC name.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  int resumeGrc(const char* in_grcName, const char* source);
  
  /// \par Description:
  /// Returns the type of this SCADAsoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }

protected:
  SCSGrcServer() {}
  SCSGrcServer(const SCSGrcServer&) {}
  virtual void changeState();

private:
  class SCSGrcServerImpl;
  SCSGrcServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCS_SCSGRCSERVER_H
