//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : ScsVisu.h                                              */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : Patrick C. CHABLE                                      */
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : 28/01/99                                               */
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
// $Id: ScsVisu.h,v 1.17 2000/02/28 12:15:26 gendreau Exp $
//
// HISTORY:
// $Log: ScsVisu.h,v $
// Revision 1.17  2000/02/28 12:15:26  gendreau
// MultiBase
//
// Revision 1.16  2000/01/27 16:16:36  ylo
// Suppress references to animator include.
//


#ifndef __SCSVISU_H__
#define __SCSVISU_H__

#include "tcl.h"
#include "Types.h"

class ScsMedia;
class ScsControler;
class GControler;
class AControler;

class ScsScript;

class ScsServers;
class ScsFrameHandler;

class ScsEnvHandler;

class ScsVisu;
class AscManager;

class AnDisplay;
class IlvDisplay;

class ScsEnvList;
class ScsEnv;
class ScsFrame;

class OpmApi;
class FtsServer;
class HisServer;
class TscServer;
class DssServer;
class LstServer;
class IlvGadgetContainer;

class ScsTimeZone;
class ScsTimeZoneList;
class StateManager;
class ScsLock;

typedef void (*UserInstructions)     (ScsVisu*    pModule);
typedef void (*DssUserInstructions)  (Tcl_Interp* interp);
typedef void (*ScsVisuEventCallback) (void* arg);

class VSU_API ScsVisu
{
public:

  static ScsVisu* GetInstance();
  static ScsVisu* CreateVisu(const char* pBaseName,       // Module Name
			     const char* pDirectory,      // Resource directory
			     const char* pProcessName,
			     UserInstructions    = NULL,  // User Added Instructions
			     DssUserInstructions = NULL); // Ditto for DSS-dedicated thread & interpreter
  static ScsBool DeleteVisu();
  static void SetTrendMaxDisplayers(int value);

  AscManager* getAscMngr() 
  { return _AscManager; }

  ScsStatus unMapEnv();

  //
  // ---- Utilities
  //

  static void InitSCADAsoft(int argc, char* argv[],const char* name=0);
  static void MainLoop(const char* pStartupFile = 0, ScsApplicativeInitFunction initFct = 0, ScsAny arg = 0);
  static void* ORBMainLoop( void* );

  void startSCADAsoft(const char* pBaseName);
  virtual void mainLoop() = 0;
  virtual void postEvent(ScsVisuEventCallback callback, void *arg) =0;

  void WatchServers( const char* pBaseName, 
		     const char* pEnvName = "default", 
		     const char* pDbmServerName = "DbmServer", 
		     const char* pDbmPollerName = "DbmPoller",
		     const char* pDBReaderName = NULL);

  void StopWatching( const char* pBaseName );

  static void DBStateNotify( const char* pBaseName, 
			     const char* pProcessName,
			     const char* pState, 
			     void *pArg);

  void ServerUp( const char* pProcessName,
		 const char* pBaseName,
		 void* pArg );

  void ServerDown( const char* pProcessName,
		   const char* pBaseName,
		   void* pArg );

  virtual void createThreadORB() = 0;

  //
  // ---- Traces and performance
  //

  int  getUpdateTraceFlag() 
  { return _updateTraceFlag; }

  int  getPerfFlagValue() 
  { return _perfFlag; }

  int getPerfFlag();

  void setInitialTime();

  void resetInitialTime();
  
  timeval getInitialTime()
  { return _t0; }

  int stepTime();

  int endTime ();


  virtual void setModalFlag(int flag) = 0;
  virtual int getModalFlag() = 0;

  //
  // ---- Accessors
  //
  
  AnDisplay* GetDisplay();

  ScsControler* GetControler( const char* pControlerName );
  AControler* GetAControler();
  GControler* GetGControler();

  ScsFrameHandler* GetFrames();

  ScsMedia* GetMedia();
  ScsScript* GetInterpreter();
  Tcl_Interp* GetTCLInterpreter();

  OpmApi * GetOpmApi();
  void SetOpmApi(OpmApi *opm);

  FtsServer * GetFtsServer();
  void SetFtsServer(FtsServer *fts);

  HisServer * GetHisServer();
  void SetHisServer(HisServer *his);

  TscServer* GetTsc() const   
  { return _TscServer; };

  void       SetTsc(TscServer* tsc) 
  { _TscServer = tsc;  };

  DssServer* GetDssServer() const
  { return _DssServer; };

  void       SetDssServer(DssServer* dss) 
  { _DssServer = dss;  };

  LstServer* GetLstServer() const
  { return _LstServer; };
  
  void       SetLstServer(LstServer* lst)
  { _LstServer = lst;  };

  DssUserInstructions getDssUserInstructions() const
  { return _dssUserInstructions; };

  static void AddDisplayInMainLoop(IlvDisplay* display);
  virtual void addDisplayInMainLoop(IlvDisplay* display) = 0;
  
  void StartUp( const char* pFileName );

  const char *getCurrentDBEnvironment() {return _currentDBEnvironment;}
  const char *getBaseName() {return _baseName;}

  // FFT Scada 16 on sept 5th 2001 : adding server and poller names as parameters (by jma)
  const char *getDbmServerName() { return _dbmServerName; };
  const char *getDbmPollerName() { return _dbmPollerName; };
  const char *getDBReaderName() { return _dbReaderName; };

  enum EventType {OrbixEvent, TclEvent};

  //
  // --- Env management
  //

  ScsEnv*     getEnv(const char* pBaseName);
  ScsEnvList* getEnvList();
  ScsEnv*     find(const RWCString& envName);
  ScsBool     isEnvAlreadyCreated(const char* pBaseName);
  ScsBool     isEnvExist( ScsEnv* env);
  ScsEnv*     getNthEnv(int index);

  ScsEnv* addEnv(const char* pBaseName, 
		 const char* pEnvName = "default" );

  void addFrameToEnv ( ScsFrame* frame );
  void removeFrameToEnv ( ScsFrame* frame );
  ScsBool isFrameExist(ScsEnv* env, ScsFrame* frame);

  ScsServers* getServers(ScsEnv* env);
  ScsServers* getServers(const char*);

  IlvDisplay* getIlvDisplay();

  // FFT NEL 588
  const char* getUserName();
  void setUserName(const char* newName);

  // Time zone facilities
  ScsTimeZone* getTimeZone(const char* pZoneName);
  void setTimeZone(ScsTimeZone* pZone);

  ScsPriorityLevels getPriority(ScsModules);
  void setPriority(ScsModules module, ScsPriorityLevels priority);

  int isDbCache() { return _dbcache; }
  int getImageCardinal() { return _imageCardinal; }
  int getPermanentImage() {return _permanentImage; }
  void setImageCardinal(int count, int permanent);

  void setPriorityForUserActions();
  int haveUserActionsPriority() {return _userActionsHavePriority;}

  // GZM-49: exit visu
  static int _DeleteInstance;
  static ScsLock* _IlogDisplayInstanceMutex;
  static IlvDisplay* _IlogDisplayInstance;

  int getVisuPollingMode() { return _visuPollingMode; }
  enum PollingMode {
    STRICT_MODE,           // default mode: old API, don't accept bad reference, shared group: mode 0
    SHARED_GROUP_MODE,     // old API, accept bad reference, shared group: mode 2
    UNSHARED_GROUP_MODE,   // old API, accept bad reference, unshared group:  mode 4
    OPTIMIZED_MODE         // only new kernel API, accept bad reference, shared group: mode 8
  };
  
  void readConfigFile(const char* filename);
  void setDatabaseCache(int value) { _dbcache = value; }
  void setVisuPollingMode(int mode);  
  void setStartupFile(char* filename);
  char* getStartupFile();

protected:

  AnDisplay* _Display;

  AControler* _AControler;
  GControler* _GControler;

  ScsFrameHandler* _Frames;

  ScsScript* _Interpreter;
  ScsMedia* _Media;
  AscManager* _AscManager;

  UserInstructions _UserInstructions;

  ScsEnvList* _envList;

  const char* _baseName;
  

  // OPM Services for TCL OPM commands
  OpmApi *_OpmApi;

 // FTS Services for TCL FTS commands
  FtsServer *_FtsServer;

 // HIS Services for TCL HIS commands
  HisServer *_HisServer;

  // TSC services for TCL TSC commands
  TscServer* _TscServer;

  // DSS services for TCL DSS commands
  DssServer* _DssServer;

  // LST services for LST commands
  LstServer* _LstServer;


  // to display update
  int _updateTraceFlag;
  //to display performance
  int _perfFlag;
  timeval _t0;
  timeval _tstep;


  int _initT0;


  // For NEL DSS thread & interpreter
  DssUserInstructions _dssUserInstructions;

  // FFT NEL 588
  const char* _userName;

  static ScsVisu* _VisuInstance;
  static StateManager* _StateManager;

  
  ScsTimeZoneList* _TimeZoneList;

  ScsPriorityLevels _modulePriorities[VISU_NB_MODULES];


protected:
  //
  // ---- Constructor / Destructor
  //
  ScsVisu(const char* pBaseName,        // Module Name
	  const char* pDirectory,       // Resource directory
	  const char* pProcessName,
	  UserInstructions    = NULL,   // User Added Instructions
	  DssUserInstructions = NULL);  // Ditto for DSS-dedicated thread & interpreter

  virtual ~ScsVisu();

protected:

  PollingMode _visuPollingMode;  


  char* _startupfile;

  char* _dbmServerName;
  char* _dbmPollerName;
  char* _dbReaderName;
  char* _currentDBEnvironment;
  int _dbcache;
  int _imageCardinal;
  int _permanentImage;
  int _userActionsHavePriority;
  

};



#ifdef WIN32
class VSU_API ScsWinVisu : public ScsVisu {

public:
  ScsWinVisu(const char*         pBaseName,
	     const char*         pDirectory,
	     const char*         pProcessName,
	     UserInstructions    pUserInstructions,
	     DssUserInstructions pDssInstructions);
  ~ScsWinVisu();

  void createThreadORB();
  void mainLoop();

  void addDisplayInMainLoop(IlvDisplay* display);

  void postEvent(ScsVisuEventCallback callback, void *arg);
  void setModalFlag(int flag);
  int getModalFlag() ;

};

#else
class ScsX11Visu : public ScsVisu {

public:
  ScsX11Visu(const char*         pBaseName,
	     const char*         pDirectory,
	     const char*         pProcessName,
	     UserInstructions    pUserInstructions,
	     DssUserInstructions pDssInstructions);
  ~ScsX11Visu();

  void createThreadORB();
  void mainLoop();

  void addDisplayInMainLoop(IlvDisplay* display);

  void postEvent(ScsVisuEventCallback callback, void *arg);
  void setModalFlag(int flag);
  int getModalFlag() ;
private:

};
#endif


#endif
