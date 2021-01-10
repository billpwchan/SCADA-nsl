/******************************************************************************/
/* 									      */
/*  FILE		: scadaorb.h                                          */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 					              */
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
#ifndef _SCADA_ORB_H_
#define _SCADA_ORB_H_

/** \file
    \brief Various utility macros and class for wrappring ORB access.
*/

#include "scs.h"          // for Scs types
#include "scadaorbdefs.h"
#include <assert.h>

class ScsStringList;

//------------------ Usefull macros -------------------------

// CORBA_INHERIT(class): for inheritance of IDL-defined class

#define CORBA_INHERIT(class) POA_##class

/**
   Prototype of the macro to simplify the call <em>ScadaORB::ORBBind()</em>.
   \code
   cls: class of the object to be bound
   obj: object to be bound
   ctx: context of bind (full name of process)
   hst: host
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define BIND(cls, obj, ctx, hst)  { void * __objVar = 0; if (ScadaORB::inst->ORBBind( __objVar, ctx, #cls, hst) == 1) { obj = cls::_narrow(CORBA::Object_var((CORBA::Object *) __objVar)); } else { obj = (cls##_ptr) __objVar; } }


/**
   Prototype of the macro to simplify the call <em>ScadaORB::ORBBind()</em>.
   \code
   cls: class of the object to be bound
   obj: object to be bound
   name: name of object (with marker. ex: "12:MyIdl")
   ctx: context of bind (full name of process)
   hst: host
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define BIND_WITH_MARKER(cls, obj, name, ctx, hst)  { void * __objVar = 0; if (ScadaORB::inst->ORBBind( __objVar, ctx, name, hst) == 1) { obj = cls::_narrow(CORBA::Object_var((CORBA::Object *) __objVar)); } else { obj = (cls##_ptr) __objVar; } }


/**
   Prototype of the macro to simplify the call <em>ScadaORB::ORBFixTimeout()</em>.
   \code
   timeout: timeout in milliseconds per method for specific remote call
   cls: class of the method's proxy object
   obj: method's proxy object
   robj: other object which can be used
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define FIXTIMEOUT(timeout, cls, obj, robj) { void * __objVar = 0; if (ScadaORB::inst->ORBFixTimeout(timeout, obj, __objVar) == 1) { robj = cls::_narrow(CORBA::Object_var((CORBA::Object *) __objVar)); } else { robj = __objVar; } }

/**
   Prototype of the macro to simplify the call <em>ScadaORB::GetObjectId()</em>.
   These macro can be put in a trace command without memory leak (SCS_SL_STD(cout) << SCS_OBJECT_ID(myObj) << SCS_SL_STD(endl);).
   \code
   obj: CORBA::Object 
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define SCS_OBJECT_ID(obj)      (const char*) CORBA::String_var(ScadaORB::inst->GetObjectId(obj))

/**
   Prototype of the macro to simplify the call <em>ScadaORB::GetHost()</em>.
   These macro can be put in a trace command without memory leak (SCS_SL_STD(cout) << SCS_HOST(myObj) << SCS_SL_STD(endl);).
   \code
   obj: CORBA::Object 
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define SCS_HOST(obj)           (const char*) CORBA::String_var(ScadaORB::inst->GetHost(obj))

/**
   Prototype of the macro to simplify the call <em>ScadaORB::GetImplementation()</em>.
   These macro can be put in a trace command without memory leak (SCS_SL_STD(cout) << SCS_IMPLEMENTATION(myObj) << SCS_SL_STD(endl);).
   \code
   obj: CORBA::Object 
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define SCS_IMPLEMENTATION(obj) (const char*) CORBA::String_var(ScadaORB::inst->GetImplementation(obj))

/**
   Prototype of the macro to simplify the call <em>ScadaORB::GetInterfaceName()</em>.
   These macro can be put in a trace command without memory leak (SCS_SL_STD(cout) << SCS_INTERFACE_NAME(myObj) << SCS_SL_STD(endl);).
   \code
   obj: CORBA::Object 
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define SCS_INTERFACE_NAME(obj) (const char*) CORBA::String_var(ScadaORB::inst->GetInterfaceName(obj))

/**
   Prototype of the macro to simplify the call <em>ScadaORB::GetObjectName()</em>.
   These macro can be put in a trace command without memory leak (SCS_SL_STD(cout) << SCS_OBJECT_NAME(myObj) << SCS_SL_STD(endl);).
   \code
   obj: CORBA::Object 
   \endcode
\code#include "scadaorb.h"\endcode
*/
#define SCS_OBJECT_NAME(obj)    (const char*) CORBA::String_var(ScadaORB::inst->GetObjectName(obj))

  


//------------------ Local includes --------------------------


/**
   \brief This class is the interface class which must be inherited if the current process want to use portable code CORBA. 

Only ORB specific functions have been defined here. This class must be used in conjunction with <em>SOAP</em> generator.
\code#include "scadaorb.h"\endcode
*/
class ScadaORB 
{
 public:

  virtual PortableServer::POA_ptr GetPOA(CORBA::Boolean multithread)=0;

  virtual CORBA::ORB_ptr GetORB(void) = 0;

  ScadaORB(int argc, char ** argv)
    {
      assert(! instIsInitialized);
      if (! instIsInitialized) {
	inst = this;
	instIsInitialized = 1;
      }
    };

  virtual ~ScadaORB() {};

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     global instance.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
    SCSORB_API static ScadaORB * inst;
  //@}
  
 private:
   SCSORB_API static int instIsInitialized;


 public:
 
  /**@name General member functions*/
  //@{ 


  /**
     \par Description:
     this static function initialize the static instance ScadaORB::inst. By default, this is called by Scadasoft::Initialize() or ScadaORB::Init() with no arguments. But, if necessary this method could be called without Scadasoft::Initialize (ScadaORB::Init) or before it with arguments for ORB.
     \param argc  [in]: number of arguments to be passed to ORB initialization.
     \param argv  [in]: arguments to be passed to ORB initialization. (see ORB doc)
     \param serverName  [in]: the name of the server.
     \param bindToDaemon  [in]: indicates if a connection to daemon must be done (true by default)
     \par Return values:
     none.
  */
  // The implementation of this method is done in the appropriate 
  // implementation file of ScadaORB (ScadaTAO or ScadaOrbacus or ScadaOrbix).
  SCSORB_API static void CreateInst(int argc, char** argv, const char* serverName=0, const int bindToDaemon = 1);
#ifdef _SCS_ORBACUS_
  SCSORB_API static void CreateInst(int argc, char** argv, OB::Reactor_var reactor, const char* serverName=0, const int bindToDaemon = 1);
#endif
  /**
     \par Description:
     this static function releases all the resource hold by the ScadaORB unique instance : it includes the CORBA ORB, the naming service entries and the ScadaORB unique instance. It shall be invoked at the end of the main procedure just after the SCADAsoft mainloop if one has been launched.
     \par Return values:
     none.
  */
  SCSORB_API static void DestroyInst();
  /**
     \par Description:
     this function initialize ORB and registers context name <em>contextName</em> into ORB's.
     \param contextName  [in]: context name.
  */
  virtual void Init(const char * contextName) = 0;
  /**
     \par Description:
     this function bind to a server and returns a server proxy <em>objectVar</em>. The server is identified by a <em>contextName</em>, a <em>className</em> and a <em>hostName</em>. this function return 1 if <em>className</em>::narrow is required.
     \param objectVar  [out]: server proxy,
     \param contextName  [in]: context name,
     \param className  [in]: className,
     \param hostName  [in]: host name.
     \return
     \li \c narrow : 1 if narrow is needed, 0 also.
  */
  virtual int ORBBind(void *& objectVar, const char * contextName, const char * className, const char * hostName) = 0;
  /**
     \par Description:
     this function return a list of active servers on local host.
     \param serverList  [out]: server list on local host,
  */
  virtual void ListActiveServers(ScsStringList & serverList) = 0;
  /**
     \par Description:
     this function return the current server host.
     \par Parameters
     None.
     \return
     current server host.
  */
  virtual const char* MyHost() = 0;
 /**
     \par Description:
     this function return the current server name.
     \par Parameters:
     None.
     \return
     current server name.
  */
  virtual const char* MyServer() = 0;
  /**
     \par Description:
     this method return the local context name.
     \par Parameters:
     none.
     \par Return values:
     the local context name.
  */ 
  virtual const char * GetContextName() = 0;
  /**
     \par Description:
     this method return the explain text of orb error.
     \param sysEx  [in]: orb system exeception.
     \par Return values:
     orb explain text.
  */ 
  virtual SCS_SL_STD(string) GetOrbExceptionText(CORBA::SystemException& sysEx) = 0;
  /**
     \par Description:
     this function allocates space for an empty NVList <em>new_list</em> of size <em>count</em> to contain NamedValue objects. A NamedValue struct can be used as a parameter type or as a way to describe arguments to a request when using the Dynamic Invocation Interface.
     \param count  [in]: list size,
     \param new_list  [out]: empty NVList to contain NamedValue objects.
  */
  virtual void CreateList(CORBA::Long count, CORBA::NVList_ptr& new_list) = 0;
 /**
     \par Description:
     this function allocates space for an empty NamedValue object.
     \param namedValue  [out]: a pointer to the NamedValue. The caller must release the reference when it is no longer needed.
  */
  virtual void CreateNamedValue(CORBA::NamedValue_ptr& namedValue) = 0;
  /**
     \par Description:
     if an operation call cannot be made on the first attempt because the transport connection cannot be established, ORB will retry the attemp every two seconds until either the call can be made or until there have been too many retries. The function sets the maximum number of retries <em> retries</em>. The default number of retries is ten. 
     \param retries  [in]: number of retries.
     \return
     \li \c retries : the previous setting.
  */
  virtual CORBA::ULong MaxConnectRetries(CORBA::ULong retries) = 0;
  /**
     \par Description:
     sets the time limit <em>timeout</em>, in seconds, for establishing that a connection from a client to a server is fully operational. The default is 30 seconds.
     \param timeout  [in]: timeout.
     \return
     \li \c timeout : the previous setting.
  */
  virtual CORBA::ULong ConnectionTimeout(CORBA::ULong timeout) = 0;
  /**
     \par Description:
     sets the timeout <em>timeout</em> for all remote calls and returns the previous setting.
     \param timeout  [in]: timeout.
     \return
     \li \c timeout : the previous setting.
  */
  virtual CORBA::ULong DefaultTxTimeout(CORBA::ULong timeout) = 0;

  /**
     \par Description:
     Returns the value in milliseconds of the default ORB timeout
     \return
     \li \c timeout : the value in milliseconds of the default ORB timeout
  */
  virtual CORBA::ULong GetORBDefaultTimeout(void) const = 0;

  /**
     \par Description:
     in cases where a node is known to the local node, but down or unreachable, a TCP/IP connect can block for a considerable time. If <em>value</em> is set to true, this function aborts TCP/IP connection attempts which exceed the timeout specified in <em>connectionTimeout()</em>.
     \param value  [in]: true or false.
     \return
     \li \c value : the previous setting.
  */
  virtual CORBA::Boolean AbortSlowConnects(CORBA::Boolean value) = 0;
  /**
     \par Description:
     by default, <em>bind()</em> raises an exception if the object on which the <em>bind()</em> is attempted is unknown to ORB deamon. Doing so requires ORB deamon to ping the desired object. The pinging will cause the target server process to be activated if necessary, and will confirm that this server recognises the target object. Pinging can be disabled using this function, passing false to the parameter <em>pingOn</em>.
     \param pingOn  [in]: true or false.
     \return
     \li \c pingOn : the previous setting.
  */
  virtual CORBA::Boolean PingDuringBind(CORBA::Boolean pingOn) = 0;
  /**
     \par Description:
     controls the level of diagnostic messages output to the cout stream. <em> level</em> 0 -> No diagnostic , <em> level</em> 1 -> Simple diagnostics (this is the default) , <em> level</em> 2 -> Full diagnostics.  
     \param level  [in]: diagnostics level.
     \return
     \li \c level : the previous setting.
  */
  virtual CORBA::Short SetDiagnostics(CORBA::Short level) = 0;
  /**
     \par Description:
     this method return the ORB infinite timeout constant.
     \par Parameters:
     none.
     \par Return values:
     ORB infinite timeout constant.
  */ 
  virtual unsigned int INFINITE_TIMEOUT() = 0;
  /**
     \par Description:
     this function activate an object and register the corresponding new reference (<em>className</em>,<em>objPtr</em>) in local ORB deamon repository on local host. This function is called in each SOAP constructors.
     \param className  [in]: name of the object,
     \param object  [in]: pointer to object to be registred (as PortableServer::ServantBase* for CORBA 2.3),
     \param isMultithreaded  [in]: true if servant has to be multithreaded, false if servant has to be serialized.
     \return 
     \li \c servantName : a new string which is the name the object has been registred (a marker could be added to given name if the reference already exist).
  */
  virtual char* RegisterRef(const char* className, void* object, CORBA::Boolean isMultithreaded) = 0;
 /**
     \par Description:
     this function remove a reference <em>className</em> to current server in ORB deamon repository on local host. This function is called in each SOAP destructors.
     \param className  [in]: class name,
     \param isMultithreaded  [in]: true if servant is multithreaded, false if servant is serialized.
  */
  virtual void UnRegisterRef(const char * className, CORBA::Boolean isMultithreaded) = 0;
  /**
     \par Description:
     this function return the pid of process registered in the ORB deamon of the local host.
     \param serverName  [in]: server name,
     \return
     \li \c  : the process pid or zero.
  */
  virtual unsigned long  GetPidFromNameServ(const char* serverName) = 0;
  /**
     \par Description:
     this function remove all references defined by <em>serverName</em> in ORB deamon repository on local host.  
     \param serverName  [in]: server name,
     \return
     \li \c ScsValid : success.
     \li \c ScsError : orb error.
  */
  virtual ScsStatus KillRef(const char* serverName) = 0;
  /**
     \par Description:
     this function test if a reference defined by <em>serverName</em> exist in ORB deamon repository on local host.  
     \param serverName  [in]: server name,
     \return
     \li \c ScsValid : success.
     \li \c ScsError : orb error.
  */
  virtual ScsStatus ExistRef(const char* serverName) = 0;
  /**
     \par Description:
     this method try to bind to orb daemon on host name <em>hostName</em>. If <em>hostName</em> is omited, the local host is considered.   
     \param hostName  [in]: host name (optional).
     \par Return values:
     none.
  */ 
  virtual void BindToDaemon(const char* hostName) = 0;
  virtual void BindToDaemon(void) = 0;
  /**
     \par Description:
     this function test the connection state with the local daemon.  
     \par Parameters:
     none.
     \return
     \li \c state : 0 if the local deamon has crashed or isn't launched, 1 also.
  */
  virtual int IsBindedToDaemon(void) = 0;
  /**
     \par Description:
     this method is ORBacus specific. It start internal mainloops which accept incoming requests. Unlike MainLoop() or Run() this method is not blocking. This method is called in MainLoop() and Run()
     \par Parameters:
     none.
     \par Return values:
     none.
  */ 
  virtual void AcceptIncomingRequests() = 0; 
  /**
     \par Description:
     this method run the server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */ 
  virtual void Run() = 0; 
  /**
     \par Description:
     this method stop the server and exit with <em>exitCode</em>.
     \param exitCode  [in]: exit code.
     \par Return values:
     none.
  */ 
  virtual void ExitProcess(int exitCode) = 0;
  /**
     \par Description:
     this method destroy the server <em>serverName</em> on host <em>hostName</em> and free these resources (method equivalent to scskillit system call). If the boolean <em>killProcess</em> is true, the server process is killed. 
     \param serverName  [in]: server name.
     \param hostName  [in]: host name.
     \param killProcess  [in]: flag to determine if the server process will be killed.
     \return 
     \li \c boolean : true or false to success or error.
  */ 
  virtual CORBA::Boolean Killit(const char* serverName, const char* hostName, CORBA::Boolean killProcess = TRUE) = 0;
  /**
     \par Description:
     this function fix a timeout <em>timeout</em> in milliseconds per method for specific remote call. According to ORB, the method's proxy <em>objectVar</em> or object <em>returnObject</em> can be used. this function return 1 if <em>className</em>::narrow is required.
     \param timeout  [in]: timeout in milliseconds.
     \param objectVar  [in]: method's proxy object.
     \param returnObject  [in]: other object which can be used.
     \return
     \li \c narrow : 1 if narrow is needed, 0 also.
  */
  virtual int ORBFixTimeout(CORBA::ULong timeout, CORBA::Object * objectVar, void *& returnObject) = 0;


  /**
     \par Description:
     this function return the object id of a CORBA::Object with format: "implementation/marker:interfaceName".
     \param obj  [in]: the CORBA::Object
     \return
     \li \c char* : new CORBA allocated char* with ObjectId. Warning: this result must be deallocated with CORBA::string_free or set in a CORBA::String_var !
  */
  virtual char* GetObjectId(const CORBA::Object_ptr obj) = 0;

  /**
     \par Description:
     this function return the host of a CORBA::Object. Note: this function must be used instead of scs_host() which is deprecated. 
     \param obj  [in]: the CORBA::Object
     \return
     \li \c char* : new CORBA allocated char* with hostname. Warning: this result must be deallocated with CORBA::string_free or set in a CORBA::String_var !
  */
  virtual char* GetHost(const CORBA::Object_ptr obj) = 0;

  /**
     \par Description:
     this function return the implementation of a CORBA::Object. Note: this function must be used instead of scs_implementation() which is deprecated. 
     \param obj  [in]: the CORBA::Object
     \return
     \li \c char* : new CORBA allocated char* with implementation. Warning: this result must be deallocated with CORBA::string_free or set in a CORBA::String_var !
  */
  virtual char* GetImplementation(const CORBA::Object_ptr obj) = 0;

  /**
     \par Description:
     this function return the interface name of a CORBA::Object.
     \param obj [in]: the CORBA::Object
     \return
     \li \c char* : new CORBA allocated char* with interface name. Warning: this result must be deallocated with CORBA::string_free or set in a CORBA::String_var !
  */
  virtual char* GetInterfaceName(const CORBA::Object_ptr obj) = 0;

  /**
     \par Description:
     this function return the object name of a CORBA::Object.
     \param obj  [in]: the CORBA::Object
     \return
     \li \c char* : new CORBA allocated char* with object name. Warning: this result must be deallocated with CORBA::string_free or set in a CORBA::String_var !
  */
  virtual char* GetObjectName(const CORBA::Object_ptr obj) = 0;


  //@}

  /* No more documented...
     \par Description:
     single main loop to specific cases.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ScsStatus SingleMainLoop(void) = 0;

  /* No more documented...
     \par Description:
     this method convert CORBA exception in ScsStatus.
     \param sysEx  [in]: Exception.
     \return
     \li \c ScsValid : .
  */ 
  virtual ScsStatus GetScsStatusFromException(CORBA::SystemException& sysEx) = 0;
  /* No more documented...
     \par Description:
     throw an CORBA exception specified by an ScsStatus.
     \param status  [in]: Status.
     \par Return values:
     none.
  */ 
  virtual void      ThrowExceptionFromScsStatus(ScsStatus& status) = 0;

 private:
  /* No more documented...
     \par Description:
     this function initialize ORB and registers context name <em>contextName</em> into ORB's. <em>defaultTimeout</em> define  the timeout, in milliseconds, for all remote calls.
     \param contextName  [in]: context name.
     \param defaultTimeout  [in]: remote calls timeout in milliseconds.
  */
  virtual void Initialize(const char * contextName, const int defaultTimeout) throw (CORBA::SystemException) = 0;
  /* No more documented...
     \par Description:
     this method must be called after process initialization. It calls asynchronously the callbacks specified in the initialization phase and starts an infinite orb event loop.
     \param function  [in]: applicative init function called just before entering the infinite event loop,
     \param arg  [in]: optional argument passed to the init function.
     \return
     \li \c ScsValid : success.
     \li \c ScsOrbError : an error occurred calling an Orb function.
  */
  virtual ScsStatus MainLoop(ScsApplicativeInitFunction function = 0, ScsAny arg = 0) = 0;
  /* No more documented...
     \par Description:
     this method exit of the main loop but not the current process.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual void Exit() = 0;
  /* No more documented...
     \par Description:
     this method adds the <em>fd</em> file descriptor to the set of file descriptors to be looked at. If some data arrives on this file descriptor, the function specified by the <em>function</em> parameter is called with argument <em>arg</em> (argument is optional). {\bfThis method should absolutely be called before calling <em>Scadasoft::MainLoop()</em>}.
     \param fd  [in]: file descriptor to add,
     \param function  [in]: function to call,
     \param arg  [in]: function argument.
     \return
     \li \c ScsValid : success.
  */
  virtual ScsStatus AddFDFunction(int fd, ScsFDFunction function, ScsAny arg = 0) = 0;
 /* No more documented...
     \par Description:
     this method inserts the <em>fd</em> file descriptor to the set of file descriptors to be looked at after the process has entered the SCADAsoft mainloop. If some data arrives on this file descriptor, the function specified by the <em>function</em> parameter is called with argument <em>arg</em> (argument is optional).
     \param fd  [in]: file descriptor to insert,
     \param function  [in]: function to call,
     \param arg  [in]: function argument.
     \return
     \li \c ScsValid : success.
  */
  virtual ScsStatus InsertFDFunction(int fd, ScsFDFunction function, ScsAny arg = 0) = 0;
 /* No more documented...
     \par Description:
     this method removes the <em>fd</em> file descriptor from the set of file descriptors to be looked at.
     \param fd  [in]: file descriptor to remove.
     \return
     \li \c ScsValid : success.
  */
  virtual ScsStatus RemoveFDFunction(int fd ) = 0;
  /* No more documented...
     \par Description:
     this method returns the current ORB timeout, in milliseconds, for all remote calls.
     \par Parameters:
     none.
     \par Return values:
     ORB timeout.
  */
  virtual unsigned int GetORBTimeout() = 0;
  /* No more documented...
     \par Description:
     this method change the ORB timeout, in milliseconds, for all remote calls.
     \param timeout  [in]: ORB timeout in milliseconds.
     \return
     \li \c ScsValid : success.
  */ 
  virtual ScsStatus SetORBTimeout(unsigned int timeout) = 0;
 /* No more documented...
     \par Description:
     this method unset the ORB timeout to the default ORB timeout for all remote calls.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */ 
  virtual ScsStatus UnSetORBTimeout() = 0;
  /* No more documented...
     \par Description:
     this method set the default ORB timeout for all remote calls.
     \param timeout  [in]: ORB timeout in milliseconds.
     \return
     \li \c ScsValid : success.
  */ 
  virtual ScsStatus SetORBDefaultTimeout(unsigned int timeout) = 0;

  friend class Scadasoft;
   
};

/**
   \par Description:
   this function initializes a CORBA smart pointer (either a 
   CORBA servant ptr or var) with a SOAP CORBA servant instance
   and activates the servant. When this method returns, the
   servant is then able to process incoming CORBA request.
   
   Notice that the servant must have been created in the heap.
   
   \param ptr    [out]: a smart pointer to be initialized with the
                        servant address.
   \param servant [in]: a heap allocated SOAP CORBA servant that 
                        shall be activated.
 */
template<typename SMART_PTR,class SERVANT_CLS>
void activate(SMART_PTR& ptr,SERVANT_CLS* servant) {
  
  ptr = servant;
  ptr->_activate_servant();
}

/**
   \par Description:
   this function deactivates a SOAP CORBA servant, decreases
   its ref count and reset the smart pointer.
   
   \param ptr    [out]: a smart pointer initialized with a SOAP
                        CORBA servant.
 */
template<class SERVANT_CLS>
void deactivatePtr(SERVANT_CLS*& ptr) {

  ptr->_deactivate_servant();
  ptr->_remove_ref();
  ptr = 0;
}

/**
   \par Description:
   this function deactivates a SOAP CORBA servant and decreases
   its ref count.
   
   \param ptr    [out]: a CORBA servant var initialized with a SOAP
                        CORBA servant.
 */
template<class SERVANT_VAR,class SERVANT_CLS>
void deactivateVar(SERVANT_VAR& ptr) {
  SERVANT_CLS* servant=ptr->retn();
  
  ptr->_deactivate_servant();
  ptr->_remove_ref();
}

#ifdef _SCS_ORBACUS_
//
// ORBACUS
//
SCS_SL_STD(ostream)& operator<<(SCS_SL_STD(ostream)& os, const CORBA::Exception& ex);
#endif

#endif
