#ifndef _DAC_SCSTCPSOCKET_H_
#define _DAC_SCSTCPSOCKET_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : scstcpsocket.h	                                      */
/*  FULL NAME        : SCADAsoft Tcp Socket Header File                       */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : A. Ng                                                  */
/*  COMPANY          : THALES                                                 */
/*  CREATION DATE    : March 2007                                             */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*  WINSOCK VERSION 2.2 is used                                               */
/******************************************************************************/
// SCADAsoft Header Files
#include "scs.h"
#include "scscstring.h"
#include "scsdefs.h"
#include <fcntl.h>

#ifdef WIN32
  #if _MSC_VER > 1200
    #include <winsock2.h>
  #endif

  #include <windows.h>

  typedef SOCKET 	ScsSock;
#else
  #include <netinet/tcp.h>
  #include <sys/types.h>
  #include <sys/socket.h> // socket
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <unistd.h> //. read
  #include <stdlib.h> // exit
  #include <netdb.h>
  #include <errno.h>
  const int 	INVALID_SOCKET = -1 ;
  const int 	SOCKET_ERROR   = -1 ;
  typedef int 	ScsSock ;
#endif

#ifdef WIN32
  #ifdef SCSSOCKET_EXPORTS
    #define SCSSOCKET_API __declspec(dllexport)
  #else
    #define SCSSOCKET_API __declspec(dllimport)
  #endif
#else
  #define SCSSOCKET_API
#endif

#define   SocTrace ScsTraceFunction(DAC_SCSMODULE)

class SCSSOCKET_API ScsTcpSocket 
{
  public:
        // Enum Block Mode
        typedef enum ESocBlockMode {
          BLOCKING,
          NONBLOCKING
        } ESockBlockMode;
        
        typedef enum ESocSelectSet {
          READSET,
          WRITESET	        
        } ESocSelectSet;
        
        typedef enum ESocReadMode {
          READ_ONCE,
          READ_ALL	        
        } ESocReadMode;

        // Constructor
   	ScsTcpSocket(const char*, int, int);
   	
	// Destructor
	virtual 	~ScsTcpSocket();
  
	// Public Methods
	int             isConnected();	
	ScsStatus 	doConnect();	   	   
	void     	doDisconnect();
	ScsStatus 	doSelect(int, int timeout = 6000);
	ScsStatus 	doSend(char*, int);
	ScsStatus 	doReceive(char*, int, int, int mode, int&rcvlen);
	
	const char *getHost() { return _host.data(); };
  	void setHost(const char* host) { _host = host; setAddrByHost( host ); };
	
	int getPort() const { return _port; };
	void setPort( const int port ) { _port = port; };
	
	long getTimeout() const { return _timeout; };
	void setTimeout( const int timeout ) { _timeout = timeout; };

        ScsSock getSocket() { return _commsock; };
	void setSocket( ScsSock sock ) { _commsock = sock; };

  	ScsSock getServSocket() { return _servsock; };
	void setServSocket( ScsSock sock ) { _servsock = sock; };
  
	int getRole() { return _role; };
	void setRole( int role ) { _role = role; };
	
  protected:	
        void            setSockBlock(ScsSock, int);
        ScsStatus       tcpClientConnect();
        ScsStatus       tcpServerConnect();
        
  private:
        void            setAddrByHost(const char*);
        ScsCString      _host;		
        int		_port; 
        int	 	_role;
        long 		_timeout;
        ScsSock         _commsock;
        ScsSock         _servsock;
        struct in_addr  _inaddr;
} ;

#endif // _DAC_SCSTCPSOCKET_H_
