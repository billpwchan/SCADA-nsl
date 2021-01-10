//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsimgmodule.h                                         */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Wed Aug 12 13:07:16 1998                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: scsimgmodule.h,v 1.6 1999/12/23 07:03:28 jmb Exp $
//
// HISTORY:
// $Log: scsimgmodule.h,v $
// Revision 1.6  1999/12/23 07:03:28  jmb
// Add ScsCreateFunction definition and rename ScsTryBindFunction to ScsBindFunction
//
// Revision 1.5  1999/12/15 08:33:56  jmb
// Add addTryBind static method
//
// Revision 1.4  1999/08/19 12:22:46  jmb
// Modify setStandByUp interface
//
// Revision 1.3  1999/08/19 08:54:18  jmb
// Add _inputMgr declaration
//
// Revision 1.2  1999/08/18 17:13:51  scadaref
// Port on aCC
//
// Revision 1.1  1999/08/17 08:24:56  jmb
// Initial revision
//
//
#ifndef _SCS_IMG_MODULE_H_
#define _SCS_IMG_MODULE_H_

#include "scadaorb.h"
#include "scs.h"
#include "inputmgrbindings.hh"
#include "scsredtype.hh"

#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef IMGBIN_EXPORTS
        #define IMGBIN_API __declspec(dllexport)
        #else
        #define IMGBIN_API __declspec(dllimport)
        #endif
        
    #else
        #define IMGBIN_API
    #endif
#else
    #define IMGBIN_API
#endif

class DestinationContainer;
class InputMgr_i;
class ScsImgModule;
class ImgMessage;

typedef void (*ScsCreateFunction)(void);
typedef ScsImgModule* (*ScsBindFunction)(const char*);

//------------------ Useful macros -------------------------
#define ADDTRYBIND(obj) ScsImgModule::addTryBind(#obj , &InputMgr_ ## obj ## _i::createFunction, &InputMgr_ ## obj ## _i::tryBind)  

class IMGBIN_API ScsImgModule {

public:

  // try to connect to local server (return true if connection done)
  virtual int setServerUp(const unsigned int & timeout) = 0;

  // try to connect to remote equivalent module (return true if connection done)
  virtual int setStandByUp(const char *remoteService, const char *remoteHost) = 0;

  int isConnectedToServer(const unsigned int & timeout);
  int isConnectedToStandby();

  ScsProcessIdl_ptr getDestination(const unsigned int & timeout);
  ScsProcessIdl_ptr getRemoteImgModule() { return _remoteImgModule;}
  void clearDestinations();
  void clearDestination(const unsigned int & timeout);
  void clearRemoteImgModule() { if(_remoteImgModule) CORBA::release(_remoteImgModule); _remoteImgModule = NULL;}  
  void lockDestinations();
  void unlockDestinations();

  void setMyModuleIdl(ScsProcessIdl_ptr myModuleIdl) { _myModuleIdl = myModuleIdl; }
  ScsProcessIdl_ptr getMyModuleIdl() { return _myModuleIdl; }

  static ScsStatus addTryBind(const char  *serviceName,
			      ScsCreateFunction createFunction,
			      ScsBindFunction bindFunction);

  static InputMgrBindingsIdl_ptr getRemoteBindings();

  void addDestination(ScsProcessIdl_ptr destination,
		      const unsigned int & timeout);

  const char *getServerName() { return _serverName; };

  char* scs_implementation()                      { return CORBA::string_dup(ScadaORB::inst->GetContextName()); }
  char* scs_host() throw (CORBA::SystemException) { return CORBA::string_dup(ScadaORB::inst->MyHost()); }
  void  isAlive() throw (CORBA::SystemException)  {}

  void setPriority(unsigned short priority);
  void setRemotePriority(unsigned short priority);
  unsigned short getPriority() { return _priority; };

  void  insertMsg(ImgMessage *msg, const ScsMessageTag& tag, const ScsTimeValIdl& onlineTime, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);
  int   needStandbyArgs();


protected:

  ScsImgModule(const char* serverName);
  virtual ~ScsImgModule();
  
  char*                   _serverName;           // name of server
  InputMgr_i*             _inputMgr;             // pointer to local inputMgr
  ScsProcessIdl_ptr       _remoteImgModule;      // equivalent module on remote host
  DestinationContainer *  _destinationContainer; // collection of destination (according to timeout)
  ScsProcessIdl_ptr       _myModuleIdl;          // TIE object corresponding to this module
  unsigned short          _priority;             // priority of messages
};

#endif
