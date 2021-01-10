//-----------------------------------------------------------------------------------
//
//   SYSECA S.A.
//
//-----------------------------------------------------------------------------------
//
//   File : Test.cpp
//   Description : ScsVisu header file test
//
//-----------------------------------------------------------------------------------
//
//   Author : Patrick C. CHABLE
//   Date : 03/02/99
//   Modification :
//
//-----------------------------------------------------------------------------------
// IDENTIFICATION:
// $Id: Main.cpp,v 1.26 2000/02/28 12:13:49 gendreau Exp $
//
// HISTORY:
// $Log: Main.cpp,v $
// Revision 1.26  2000/02/28 12:13:49  gendreau
// MultiBase.
//
// Revision 1.25  2000/01/28 09:49:15  ylo
// Add traces
//
// Revision 1.24  2000/01/27 12:37:13  ylo
// Add traces
//
// Revision 1.23  1999/12/01 14:32:09  scadaref
// Port on MSVC6
//
// Revision 1.22  1999/11/04 17:11:01  ylo
// Moves Scsdasoft::initialize before the new ScsVisu to allow use of SCADAsoft traces.
//
// Revision 1.21  1999/09/20 15:19:14  scadaref
// include directive for unistd.h.
//
// Revision 1.20  1999/09/17 15:18:32  pierre
// -f option.
//
// Revision 1.19  1999/08/27 17:37:22  ylo
// Fix infinite fatal error loop.
//
// Revision 1.18  1999/08/26 12:18:25  jmb
// Add #include <unistd.h>
//
//
//-----------------------------------------------------------------------------------

// --- SCADAsoft headers
#ifndef WIN32
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>

#include <an/workspace.h>

#include "ggetopt.h"
#include "scs.h"

#include "scsversion.h"
#include "ScsVisu.h"
#include "visuerror.h"






extern "C" {
#ifdef WIN32
  extern __declspec(dllimport) void SetWindowsLook (int xpLook);
  extern __declspec(dllimport) void SetDoubleBuferChildContainer (bool  value);
#else
  void SetWindowsLook (int xp);
  void SetDoubleBuferChildContainer (bool  value);    
#endif
}

int Mode = 8;
int Time = 0;
bool isXPThemeAvailable = false;

ScsVisu* Visu;

int Tcl_MyCalculator( ClientData data,
		      Tcl_Interp *pInterpret,
		      int argc,
		      Tcl_Obj* CONST argv[] )
{
  int Value;
  char Buffer[ 80 ];

  //
  // ---- Multiply argument by 2
  //
  Value = atoi( Tcl_GetString(argv[ 1 ]) );
  Value *= 2;

  sprintf( Buffer, "%d", Value );
  Tcl_SetResult( pInterpret, Buffer, TCL_VOLATILE );

  return( TCL_OK );
}


//-----------------------------------------------------------------------------------
//
//   Method : AddUserCommands
//   Returns : Nothing
//   Description : Adds new instructions to the TCL interpreter
//
//-----------------------------------------------------------------------------------
//
//   Author : Patrick C. CHABLE
//   Date : 17/03/99
//   Modification :
//
//-----------------------------------------------------------------------------------



void
AddUserCommands( ScsVisu* pVisu )
{
  Tcl_Interp* Engine;

  Engine = pVisu->GetTCLInterpreter();

  Tcl_CreateObjCommand( Engine,			// Interpreter
			"MyCalculator",		// New Tcl instruction name
			Tcl_MyCalculator,	// Corresponding method
			(ClientData)0,		// Client Data
			NULL );			// Destruction method
}


//-----------------------------------------------------------------------------------
//
//   Method : AddUserCommands
//   Returns : Nothing
//   Description : Adds new instructions to the TCL interpreter of the DSS thread
//
//-----------------------------------------------------------------------------------
//
//   Author : Patrick C. CHABLE
//   Date : 17/03/99
//   Modification :
//
//-----------------------------------------------------------------------------------

void
AddDssUserCommands(Tcl_Interp* tclInterpreter)
{
  Tcl_CreateObjCommand(tclInterpreter,		// Interpreter
		       "MyCalculator",		// New Tcl instruction name
		       Tcl_MyCalculator,	// Corresponding method
		       (ClientData)0,		// Client Data
		       NULL );			// Destruction method
}


//-----------------------------------------------------------------------------------
//
//   Method : PrintUsage
//   Returns : Nothing
//   Description : Help
//
//-----------------------------------------------------------------------------------
//
//   Author : Patrick C. CHABLE
//   Date : 25/03/99
//   Modification :
//
//-----------------------------------------------------------------------------------

void PrintUsage()
{
  SCS_SL_STD(cerr) << "\n"
		   << "Usage:    ScsVisu [-e env] [-n name] [-r db env] [-p path] [-A polling mode] [-f startup file] [-g configuration file]\n"
		   << "                  [-c with memory cache] [-S DbmServer] [-P DbmPoller] [-m module traces] [-l global traces]\n"
		   << "                  [-t timeout] [-R DbmReader] [-I number of images] [-K number of permanent images]\n"
		   << "                  [-u] [-z Double buffer of sub container (true or false)]"
                   << " [-T max number of measure] [-x] [-h]\n\n" 
		   << "Options:  -e  name of the SCADAsoft/operator environment (SCSENV)" << SCS_SL_STD(endl)
		   << "\t  -n  name of the ScsVisu process" << SCS_SL_STD(endl)
		   << "\t  -r  name of the database environment (SCSDBENV)" << SCS_SL_STD(endl)
		   << "\t  -p  path to the resources (SCSPATH)" << SCS_SL_STD(endl)
		   << "\t  -A  <polling mode> where mode is among:"  << SCS_SL_STD(endl)
		   << "\t      8: OPTIMIZED_MODE. This is the default mode: Group is sharable." << SCS_SL_STD(endl)
		   << "\t      4: UNSHARED_GROUP_MODE. Always creates group and subscribes to poller: the group is unshared." << SCS_SL_STD(endl)
		   << "\t      [4] neither database cache (-c option) nor image cache (-I and -K options)" << SCS_SL_STD(endl)
         	   << "\t      [0,2] Obsolete: replace by default mode 8 OPTIMIZED_MODE" << SCS_SL_STD(endl)    
		   << "\t  -f  name of the TCL startup file (without its .tcl extension)" << SCS_SL_STD(endl)
		   << "\t  -g  name of the configuration file (without its .cfg extension)" << SCS_SL_STD(endl)
		   << "\t  -c  database memory cache: only with -A 2 or -A 8 mode" << SCS_SL_STD(endl)
		   << "\t  -S  name of the DbmServer (default is 'DbmServer')" << SCS_SL_STD(endl)
		   << "\t  -P  name of the DbmPoller  (default is 'DbmPoller')" << SCS_SL_STD(endl)
		   << "\t  -R  name of the DbmReader  (default: no DbmReader used)" << SCS_SL_STD(endl)
		   << "\t  -m  trace module(0-31)" << SCS_SL_STD(endl)
		   << "\t  -l  trace level (0-31)" << SCS_SL_STD(endl)
		   << "\t  -t  CORBA timeout (default is 10s)" << SCS_SL_STD(endl)
		   << "\t  -I  size of the temporary images cache(default is 0):  only with -A 2 or -A 8 mode" << SCS_SL_STD(endl)
		   << "\t  -K  size of the permanent images in cache(default is 0): only with -A 2 or -A 8 mode" << SCS_SL_STD(endl)
		   << "\t  -u  user actions have priority (deprecated since SCADAsoft V5)" << SCS_SL_STD(endl)
		   << "\t  -T  max number of measure per Trend display (default is 16)" << SCS_SL_STD(endl)
		   << "\t  -z  activation of double buffer of sub container. Values are true or false. Default value is false" << SCS_SL_STD(endl);
                   
  if (isXPThemeAvailable)
    SCS_SL_STD(cerr) << "\t  -x  force XP look & feel when running Windows XP (DLL only)" << SCS_SL_STD(endl);
  
  SCS_SL_STD(cerr) << "\t  -h  displays usage help\n" << SCS_SL_STD(endl)
		   << "This version is " << (const char*)SCADASoftVersion << SCS_SL_STD(endl) << SCS_SL_STD(endl);
	exit(-1);
}






//-----------------------------------------------------------------------------------
//
//   Method : Main
//   Returns : Nothing
//   Description : Main procedure
//
//-----------------------------------------------------------------------------------
//
//   Author : Patrick C. CHABLE
//   Date : 05/02/99
//   Modification :
//
//-----------------------------------------------------------------------------------

#ifdef WIN32
#undef main
#endif

static void
InitFunction(void* arg)
{
}


int main( int argc, char* argv[] )
{

  char* Path = NULL;
  char* ModeTest = NULL;
  char* StartupFile = NULL;
  char* ConfigFile = NULL;
  char* ServerName = NULL;
  char* EnvName = NULL;
  char* DBEnv = NULL;
  char* DbmServerName = NULL;
  char* DbmPollerName = NULL;
  char* DBReaderName = NULL;
  char* doublebuffer = NULL;


#ifdef WIN32
  #ifdef SCS_DLL
  // get windows version
  DWORD dwVersion = GetVersion();
  DWORD dwWindowsMajorVersion =  (DWORD)(LOBYTE(LOWORD(dwVersion)));
  DWORD dwWindowsMinorVersion =  (DWORD)(HIBYTE(LOWORD(dwVersion)));

  if (dwWindowsMajorVersion >= 5 && dwWindowsMinorVersion >= 1) {
    isXPThemeAvailable = true;
  }
  #endif
#endif
  
  int optChar = 0;
  int nbFlag = 0;

  int level = 0;
  int levelMask = 1;

  int module = 0;
  int moduleMask = (1 << VIS_SCSMODULE);

  int flagTraces = 0;
  int dbcache = 0;
  int SizeImageCache = -1;
  int PermanentImage = -1;
  int userActionsHavePriority = 0;
  
  
  
  bool childContainerDoubleBuffer = false;

  int xpLook = 0;

#ifdef SIGNAL
  int i;
  for (i=0; i>255; i++) {
    signalFcts[i] = SIG_DFL;
  }
  /*
  signalFcts[SIGKILL] = signal(SIGKILL, fatalErrorSignal);
  signalFcts[SIGHUP]  = signal(SIGHUP,  fatalErrorSignal);
  signalFcts[SIGQUIT] = signal(SIGQUIT, fatalErrorSignal);
  signalFcts[SIGILL]  = signal(SIGILL,  fatalErrorSignal);
  signalFcts[SIGTRAP] = signal(SIGTRAP, fatalErrorSignal);
  signalFcts[SIGABRT] = signal(SIGABRT, fatalErrorSignal);
  signalFcts[SIGIOT]  = signal(SIGIOT,  fatalErrorSignal);
  signalFcts[SIGEMT]  = signal(SIGEMT,  fatalErrorSignal);
  signalFcts[SIGFPE]  = signal(SIGFPE,  fatalErrorSignal);
  signalFcts[SIGBUS]  = signal(SIGBUS,  fatalErrorSignal);
  signalFcts[SIGSEGV] = signal(SIGSEGV, fatalErrorSignal);
  signalFcts[SIGSYS]  = signal(SIGSYS,  fatalErrorSignal);
  signalFcts[SIGPIPE] = signal(SIGPIPE, fatalErrorSignal);
  */
  signalFcts[SIGTERM] = signal(SIGTERM, fatalErrorSignal);
  /*
  signalFcts[SIGXCPU] = signal(SIGXCPU, fatalErrorSignal);
  signalFcts[SIGXFSZ] = signal(SIGXFSZ, fatalErrorSignal);
  signalFcts[SIGLOST] = signal(SIGLOST, fatalErrorSignal);
  signalFcts[SIGUSR1] = signal(SIGUSR1, fatalErrorSignal);
  signalFcts[SIGUSR2] = signal(SIGUSR2, fatalErrorSignal);
  */
#endif

  Mode = -1;
  //
  // ---- Retrieve Options
  //
  
  GetOpt getopt(argc, argv, ":hf:g:n:e:r:p:A:S:P:R:t:l:m:I:K:cuT:xz:");
  
  while ((optChar = getopt()) != EOF)
    {
      switch (optChar)
	{
	case 'h':
	  PrintUsage();
	  break;
    
	case 'z':
	  nbFlag++;
	  doublebuffer = new char[strlen(getopt.optarg) + 1];
	  strcpy( doublebuffer, getopt.optarg);
      if (strcmp(doublebuffer,"true") == 0) {
          childContainerDoubleBuffer = true;
      }
        
	  break;

	case 'x':
	  nbFlag++;
          if (isXPThemeAvailable)
            xpLook = 1;
	  break;

	case 'f':
	  nbFlag++;
	  StartupFile = new char[strlen(getopt.optarg) + 1];
	  strcpy( StartupFile, getopt.optarg);
	  break;

	case 'g':
	  nbFlag++;
	  ConfigFile = new char[strlen(getopt.optarg) + 1];
	  strcpy( ConfigFile, getopt.optarg);
	  break;

	case 'n':
	  nbFlag++;
	  ServerName = new char[strlen(getopt.optarg) + 1];
	  strcpy( ServerName, getopt.optarg);
	  break;

	case 'e':
	  nbFlag++;
	  EnvName = new char[strlen(getopt.optarg) + 1];
	  strcpy( EnvName, getopt.optarg);
	  break;

	case 'r':
	  nbFlag++;
	  DBEnv = new char[ strlen( getopt.optarg) + 1 ];
	  strcpy( DBEnv, getopt.optarg );
	  break;

	case 'p':
	  nbFlag++;
	  Path = new char[strlen(getopt.optarg) + 1];
	  strcpy( Path, getopt.optarg);
	  break;

	case 'A':
	  nbFlag++;
	  Mode = atoi(getopt.optarg);
	  break;

	case 'I':
	  nbFlag++;
	  SizeImageCache = atoi(getopt.optarg);
	  break;
	  
	case 'K':
	  nbFlag++;
	  PermanentImage = atoi(getopt.optarg);
	  break;

	case 'c':
	  nbFlag++;
	  dbcache = 1;  // add database cache
	  break;

	case 't':
	  nbFlag++;
	  Time = atoi(getopt.optarg);
	  break;

	case 'S':
	  // FFT Scada 16 on sept 5th 2001 : adding server and poller names as parameters (by jma)
	  nbFlag++;
	  DbmServerName = new char[strlen(getopt.optarg) + 1];
	  strcpy( DbmServerName, getopt.optarg);
	  break;

	case 'P':
	  // FFT Scada 16 on sept 5th 2001 : adding server and poller names as parameters (by jma)
	  nbFlag++;
	  DbmPollerName = new char[strlen(getopt.optarg) + 1];
	  strcpy( DbmPollerName, getopt.optarg);
	  break;
	case 'R':
	  // FFT SRC 770 DBReader 
	  nbFlag++;
	  if (strlen(getopt.optarg)>0) {
	    DBReaderName = new char[strlen(getopt.optarg) + 1];
	    strcpy( DBReaderName, getopt.optarg);
	  }
	  break;
	case 'm':
	  nbFlag++;
	  module = atoi(getopt.optarg);
	  if ((module < 0) || (module > 31))
	    {
	      SCS_SL_STD(cerr) << argv[0] << ": traces module should be between 0 and 31..."
			       << SCS_SL_STD(endl);
	      exit(1);
	    }
	  moduleMask |= (1 << module);
	  flagTraces++;
	  break;
	case 'l':
	  nbFlag++;
	  level = atoi(getopt.optarg);
	  if ((level < 0) || (level > 31))
	    {
	      SCS_SL_STD(cerr) << argv[0] << ": traces level should be between 0 and 31..."
			       << SCS_SL_STD(endl);
	      exit(1);
	    }
	  levelMask |= (1 << level);
	  flagTraces++;
	  break;

        case 'u':
#ifndef _SCS_TAO_    
	  userActionsHavePriority = 1;
#endif
	  break;

	case 'T':
	  {
	    nbFlag++;
	    int displayers  = atoi(getopt.optarg);
	    if (displayers>0) {
	      ScsVisu::SetTrendMaxDisplayers(displayers);
	    }
	  }
	  break;
	case ':':
	  break;

	case '?':
	  PrintUsage();
	  break;
	}
    }
  
  // EnvName must be the Physical Environment and not the logical Environment .
  //if( !EnvName && getenv ("SCSENV") ) { EnvName = strdup(getenv( "SCSENV" )); }
  if( !Path && getenv ("SCSPATH") ) { Path = strdup(getenv( "SCSPATH" )); }
  if( !ServerName ) { ServerName = "ScsVisu"; }
  
  // FFT Scada 16 on sept 5th 2001 : adding server and poller names as parameters (by jma)
  if( !DbmServerName)
	  DbmServerName = "DbmServer";
  if( !DbmPollerName)
	  DbmPollerName = "DbmPoller";

  if( !DBEnv &&  getenv( "SCSDBENV" ))
    { 
      DBEnv = strdup(getenv( "SCSDBENV" ));
    }

  //
  // ---- Are Variables set
  //
  if( !EnvName )
    {
      printf( "Physical envName is not defined: option -e \n" );
      exit( 0 );
    }

  if( !Path )
    {
      printf( "SCSPATH is not defined\n" );
      exit( 0 );
    }
    
  // register ilog license
  AnWorkSpace::init();
  ScsVisu::InitSCADAsoft(argc, argv, ServerName);
  
  ScsStatus status = Scadasoft::Initialize(EnvName, ServerName);
    SCS_REGISTER_END_PROCESS
  Scadasoft::SetTrace(moduleMask, levelMask);


  if( status.isError() ) {
    SCS_SL_STD(cerr) <<"SCADAsoft Communication Initialisation Failure" << SCS_SL_STD(endl);
    exit(0);
  }

#ifdef SCS_SMOL
  if (Time <= 0) {
    Scadasoft::SetORBTimeout(10000);
  } else {
    Scadasoft::SetORBTimeout(Time*1000);
  }
#endif


  //
  // ---- Run
  //
  Visu = ScsVisu::CreateVisu(EnvName,	          // SCADAsoft logical environment
			     Path,	          // Resources
			     ServerName
#if 0
			     ,
			     AddUserCommands,     // TCL users commands
			     AddDssUserCommands   // TCL users commands for DSS thread
#endif
			     );
  // size if images memory caches
  if (SizeImageCache > 0 || PermanentImage > 0) {
    Visu->setImageCardinal(SizeImageCache, PermanentImage);
  }
  // set database cache
  if (dbcache) {
    Visu->setDatabaseCache(dbcache);
  }

  if (userActionsHavePriority) {
    Visu->setPriorityForUserActions();
  }

  // You may set high message priority for some servers
  //Visu->setPriority(ScsVisu::VISU_DBM, SCS_PRIORITY_HIGH);


  // visu polling behavior 
  if (Mode >=0 ) {
    Visu->setVisuPollingMode(Mode);  
  }

  Visu->createThreadORB();
  Visu->startSCADAsoft(EnvName); //Physical environment

  if (DBEnv || DbmServerName || DbmPollerName) {
    if (DBEnv) {
      Visu->WatchServers(DBEnv, "default", DbmServerName, DbmPollerName,DBReaderName);
    } else {
      Visu->WatchServers(NULL,NULL, DbmServerName, DbmPollerName,DBReaderName);
    }
  }

  if( StartupFile ) {
    Visu->setStartupFile(StartupFile);
    delete [] StartupFile;
  }

  if (ConfigFile) {
    Visu->readConfigFile(ConfigFile);
    delete [] ConfigFile;
  }
  
#if (VIEWS_VERSION >= 500)
#  ifdef WIN32
#      ifdef SCS_DLL
  // Force XP look for XP platforms
  SetDoubleBuferChildContainer(childContainerDoubleBuffer);
  SetWindowsLook(xpLook);
#      endif
#  endif
#endif

  Visu->StartUp(Visu->getStartupFile());

  ScsVisu::MainLoop();

  //
  // CBE : ToDo join the ORB created thread (see above 
  //       Visu->createThreadORB()).
  // 

  return 0;
}
