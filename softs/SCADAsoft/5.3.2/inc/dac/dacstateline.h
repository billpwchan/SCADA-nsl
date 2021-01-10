#ifndef _DAC_DACSTATELINE_H_
#define _DAC_DACSTATELINE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : dacstateline.h                                         */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Wed Dec 29 15:09:04 1999                               */
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
// $Id: $
//
// HISTORY:
// $Log: $

#include "scscstring.h"

#include "daccomcommandvector.h" 
#include "daccominvariable.h" // EvValue

#define LINE_BASETRACELEVEL 	10

class DacComDevice ;
class DacStateLineList;
class DacComCommand;
class DacComThread;

class DACCOM_API DacStateLine
{
 public:
  DacStateLine();
  DacStateLine(const ScsCString& address);
  DacStateLine(const ScsCString& address, DacComDevice* device);
  virtual ~DacStateLine() ;

  inline const ScsCString& getAddress() const ;
  inline int getFd() const;
  inline void setFd( int fd );

  inline DacComInVariable* getVariableLinkState() const ;
  inline void setVariableLinkState( DacComInVariable* variableState );
  inline const DacEIV& getLinkDacEiv() const ;
  
  EvValue       getState() const ;
  ScsStatus     setState( EvValue state );
  DacComDevice* getDevice() { return _device; };
  int           getId() { return _id; };
  unsigned int  getTimeout() { return _timeout; };
  void          setTimeout(unsigned int timeout) { _timeout = timeout; };

  virtual ScsStatus createFd();
  virtual ScsStatus deleteFd() { return ScsValid; };

  // manaagement of connections
  // --------------------------  
  virtual ScsStatus connectLine( DacComDevice* device ) = 0 ;
  virtual ScsStatus disconnect() = 0 ;
  virtual void resetConnectionFailure();  
  virtual int getConnectionPeriod() { return _connectionPeriod; };
  virtual void setConnectionPeriod(int connectionPeriod) { _connectionPeriod = connectionPeriod; };
  virtual int getConnectionMaxRetries() { return _connectionMaxRetries; };
  virtual void setConnectionMaxRetries(int connectionMaxRetries) { _connectionMaxRetries = connectionMaxRetries; };
  virtual int getConnectionDelayAfterFailure() { return _connectionDelayAfterFailure; };
  virtual void setConnectionDelayAfterFailure(int connectionDelayAfterFailure) { _connectionDelayAfterFailure = connectionDelayAfterFailure; };
    
  // management of the to RTU thread
  // -------------------------------
  ScsStatus startToRtuThread();
  ScsStatus stopToRtuThread();
  ScsStatus postToRtuThread(DacComCommandVector* cmds);
  ScsStatus clearToRtuMessages();
  static void ProcessCommand(void* arg, void *msg);
  virtual ScsStatus processCommand(const DacComCommandVector* cmds);
  
  // management of trace
  // -------------------
  virtual int getTraceLevel() { return LINE_BASETRACELEVEL + getId(); };  
  virtual void debugTrace( int level, int inhibTrace = 0 );
  
  virtual DacComOutVariable* getVariableLinkCommand() const { return _variableLnkCommand; };
  virtual void setVariableLinkCommand( DacComOutVariable* variable ) { _variableLnkCommand = variable; } ;
  
 protected:
  ScsCString          _address ; //. read in concentrator file
  DacComInVariable*   _variableLinkState ; //. read in variable file
  int                 _fileDescriptor ; //. defined by initCom()
  int                 _tryConnect ; //. 1 only while trying connection in another thread

  DacComDevice*       _device;
  DacComThread*       _toRtuThread;
  unsigned int        _timeout;
  int                 _id;
  static int          _Id;
  
  DacComOutVariable*  _variableLnkCommand;
  
  // Connection Variables
  int                 _connectionPeriod;	    
  int                 _connectionMaxRetries;
  int                 _connectionDelayAfterFailure;
  int                 _nbConnectionFailure;
  timeval             _connectTime;
 
} ;


const ScsCString& DacStateLine::getAddress() const
{
  return( _address );
}

void DacStateLine::setFd( int fd )
{
  _fileDescriptor = fd ;
}

int DacStateLine::getFd() const
{
  return( _fileDescriptor );
}

DacComInVariable* DacStateLine::getVariableLinkState() const
{
  return( _variableLinkState );
}

void DacStateLine::setVariableLinkState( DacComInVariable* var )
{
  _variableLinkState = var ;
}

const DacEIV& DacStateLine::getLinkDacEiv() const
{
  return( _variableLinkState->getDacEiv() );
}

int debugTrace( int level, DacStateLineList& list );

#endif // _DAC_DACSTATELINE_H_
