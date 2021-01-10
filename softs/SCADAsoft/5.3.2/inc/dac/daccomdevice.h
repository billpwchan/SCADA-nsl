#ifndef _DAC_DACCOMDEVICE_H_
#define _DAC_DACCOMDEVICE_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomdevice.h                                         */
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


#include "scsdefs.h"
#include "scadaorb.h"
#include "daccomclient.hh" //. DacComClientIdl to send the new EIV

#include "scscstring.h" //. ScsCString

#include "dac.h" //. DacTrace
#include "dacdevice.h"
#include "daccommon.h" //. EivList
#include "dacvariable.h" //. EvValue
#include "dacvariableblock.h" //. VariableBlockList
#include "daccominvariable.h" 
#include "daccominvariablevector.h" //. DacComInVariableVector
#include "daccomoutvariable.h" 
#include "daccomoutvariablevector.h" //. DacComOutVariableVector
#include "dacdeviceblock.h"
#include "daccomcommand.h"
#include "dacstateline.h" //. DacStateLineList
#include "daccomdevicelist.h"
#include "dacstatelinelist.h"

class DacExchangeBlock ;
class DacEVFilter;

class DACCOM_API DacComDevice : public DacDevice
{
 public:
  union endianness {
    int entier;
    char octet[4];
  };
  
  DacComDevice() ;
  DacComDevice( const ScsCString& name, const unsigned int id );
  DacComDevice( unsigned int id, DacDeviceBlock* deviceBloc );
  virtual ~DacComDevice() ;
 
  inline const ScsCString &getUsrProtocol() const ;
  inline void setUsrProtocol( const ScsCString& usrProtocol );

  inline DacStateLineList* getStateLineList() ;
  inline DacStateLine* getCurrentComLine() const ;
  inline void setCurrentComLine( DacStateLine* line );

  inline DacComInVariable* getStateEiv() const ;
  ScsStatus setStateEiv( DacComInVariable* stateEiv );

  inline DacComOutVariable* getStateEov() const ;
  ScsStatus setStateEov( DacComOutVariable* stateEov );

  inline DacComInVariable* getSpyEiv() const ;
  ScsStatus setSpyEiv( DacComInVariable* spyEiv );

  inline DacComOutVariable* getSpyEov() const ;
  ScsStatus setSpyEov( DacComOutVariable* spyEov );
 
  inline DacComInVariableVector* getInVariableList() ;
  inline void setInVariableList( DacComInVariableVector* inVariableList );
  virtual void setInVariablesStatus();

  void addInVariable( DacComInVariable* var );
  DacComInVariable* findInVariable( const ScsCString& address );

  inline DacComOutVariableVector* getOutVariableList() ;
  inline void setOutVariableList( DacComOutVariableVector* outVariableList );

  void addOutVariable( DacComOutVariable* var );
  DacComOutVariable* findOutVariable( const ScsCString& name );

  ScsStatus createEvList( VariableBlockList* variableList );
  ScsStatus setSpecialEiv( DacDeviceBlock* deviceBloc );
  
  ScsStatus decrNbConnected() ;
  ScsStatus incrNbConnected() ;
  int isConnected() ;

  virtual ScsStatus initCom() ;
  virtual ScsStatus connectLine( DacStateLine* line );
  virtual ScsStatus connectAll() ;
  virtual ScsStatus checkConnect() ;
  virtual ScsStatus disconnect( DacStateLine* currFd, EvValue state );
  virtual ScsStatus closeCom() ;
  
  virtual ScsStatus hdleSpecificEiv( const DacEIV* eiv ) = 0 ;
  virtual ScsStatus hdleSpecificEov( const DacEOV* eov ) = 0 ;
      
  void hdleReception( const int fileDescriptor );
  ScsStatus receive( DacStateLine* line );
  
  ScsStatus notifyComState( EvValue state );
  ScsStatus notifySpyState( EvValue state );
  ScsStatus notifyLinkState( DacStateLine* line, EvValue state );
  ScsStatus notifyLinkState( const ScsCString& address, EvValue state );
  ScsStatus notifyLinkState( int fileDescriptor, EvValue state );

  ScsStatus sendEiv( DacComClientIdl* client );
  
  static int checkSpecificEV( const char* address ) { return (address != NULL && address[0] == '$'); };
  virtual int isSpecificEiv( const ScsCString& address ) { return DacComDevice::checkSpecificEV(address.data()); };
  virtual int isSpecificEov( const ScsCString& address ) { return DacComDevice::checkSpecificEV(address.data()); };
  
  ScsStatus sendEov( unsigned int eovCount, DacEOV* eoVariables );
  ScsStatus sendEiv( unsigned int eivCount, DacEIV* eiVariables );

  virtual ScsStatus addGroupedCommands( const ScsCString& address, 
					const unsigned char* buffer,
					const unsigned int size,
					const DacComOutVariable& var );
  DacComCommandVector* getGroupedCommands() { return new DacComCommandVector(_groupCommandList); };
  virtual ScsStatus sendGroupedCommands();
  
  virtual ScsStatus setLinkState( DacComClientIdl* client, DacStateLine* line, EvValue state);

  virtual ScsStatus send( const ScsCString& address,
			  const unsigned char* buffer,
			  const unsigned int size,
			  const DacComOutVariable& var ) { return ScsValid; };
  virtual ScsStatus poll() { return ScsValid; };
  virtual ScsStatus initExchange() { return ScsValid; };
  virtual ScsStatus hdleConnectionLost() { return ScsValid; };
  virtual ScsStatus getData( DacStateLine* line, ScsCString& address ) { return ScsValid; };
  virtual ScsStatus notify( const ScsCString& address,
			    const unsigned char* buffer,
			    const unsigned int size ) { return ScsValid; }; 
  virtual ScsStatus notifyMore() { return ScsValid; }; 
			  			  
  ScsStatus fromRtuTrace( const DacStateLine* line,
			  const unsigned char* buffer,
			  const unsigned int size );
  ScsStatus toRtuTrace( const DacStateLine* line,
			const unsigned char* buffer,
			const unsigned int size );
  ScsStatus rtuTrace( const DacStateLine* line, const char* stringMsg, bool fromRtu, bool rawMode);
  virtual void rtuTrace(const char* fmt, ...);
  virtual int isSpyOn() { return (_traceIn != 0); };
  virtual void flushRtuTrace() { fflush (_traceFic); };

  virtual void debugTrace( int level, int inhibTrace = 0 );

  DacStateLine* getStateLine(const char* address);
  DacStateLine* getStateLine(int id);
  
  void defineEndianess( void );
  int isBigEndian() { return _endianness; };
  void setEndianness( int endian ) { _endianness = endian; } ;
  
  EvValue getEvState() { return _state; };
  void setEvState( EvValue state ) { _state = state; };
  
  int getSubId() { return _subId; };
  void setSubId( int subId ) { _subId = subId; };

  void          lock();
  void          unlock();

  ScsStatus     appendToEivList(DacEIV* eiv);
  ScsStatus     clearEivList();
  
  // static methods or members
  // -------------------------
  static void ChangeBlockerStateNotification( const char* logicalEnv,
                     		              const char* processName,
                                              const char* state,
                                              void* arg );
  static AscManager* 		  _AscManager;
  static unsigned int             _Relaunch;
  static unsigned int             _MaxTraceLine ;
  static unsigned int             _MaxRtuMsgLines ;
  
  // access to exchange parameters
  // -----------------------------
  virtual int getMultipleInServiceLinks() { return _multipleInServiceLinks; };
  virtual void setMultipleInServiceLinks(int multipleInServiceLinks) { _multipleInServiceLinks = multipleInServiceLinks; };
  
 protected:
  int                             _traceIn ;
  ScsCString                      _usrProtocol ;
  DacStateLineList                _stateLineList ;
  DacComInVariable*               _stateEiv ;
  DacComOutVariable*              _stateEov ;
  DacComInVariable*               _spyEiv ;
  DacComOutVariable*              _spyEov ;
  DacComInVariableVector          _inVariableList ;
  DacComOutVariableVector         _outVariableList ;
  DacEivList                      _eivList ;
  unsigned int                    _nbConnected ;
  DacStateLine*                   _currentComLine ;
  char*                           _traceFileName ;
  unsigned int                    _traceFileLine ;
  FILE*                           _traceFic ;
  DacComCommandList               _groupCommandList;
  ScsLock*                        _lock; 
  int                             _multipleInServiceLinks;
  int		                  _endianness;
  int			          _subId;  
  EvValue                         _state;
  DacEVFilter*               _evFilter;
};

const ScsCString& DacComDevice::getUsrProtocol() const
{
  return( _usrProtocol );
}

void DacComDevice::setUsrProtocol( const ScsCString& usrProtocol )
{
  _usrProtocol = usrProtocol ;
}

DacStateLineList* DacComDevice::getStateLineList()
{
  return( &_stateLineList );
}

DacStateLine* DacComDevice::getCurrentComLine() const
{
  return( _currentComLine );
}

void DacComDevice::setCurrentComLine( DacStateLine* line )
{
  _currentComLine = line ;
}

DacComInVariable* DacComDevice::getStateEiv() const
{
  return( _stateEiv );
}

DacComOutVariable* DacComDevice::getStateEov() const
{
  return( _stateEov );
}

DacComInVariable* DacComDevice::getSpyEiv() const
{
  return( _spyEiv );
}

DacComOutVariable* DacComDevice::getSpyEov() const
{
  return( _spyEov );
}

DacComInVariableVector* DacComDevice::getInVariableList()
{
  return( &_inVariableList );
}

void DacComDevice::setInVariableList( DacComInVariableVector* inVariableList )
{
  _inVariableList = *inVariableList ;
}

DacComOutVariableVector* DacComDevice::getOutVariableList()
{
  return( &_outVariableList );
}

void DacComDevice::setOutVariableList( DacComOutVariableVector* outVariableList )
{
  _outVariableList = *outVariableList ;
}


int debugTrace( int level, DacComDeviceList& list );

#endif // _DAC_DACCOMDEVICE_H_
