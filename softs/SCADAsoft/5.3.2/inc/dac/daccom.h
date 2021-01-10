#ifndef _DAC_DACCOM_H_
#define _DAC_DACCOM_H_

/******************************************************************************/
/*                                                                            */
/*  FILE             : daccom.h                                               */
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
#include "scstimer.h" //. ScsTimer
#include "daccomdevice.h"
#include "dactimerobject.h"
#include "dacdeviceblock.h"
#include "dacvariableblock.h"
#include "daccomserver_i.h"

#include "dac.h"

#define DACCOM_SERVERNAMEPREFIX "DacCom_"

class DacComClientIdl ;

class DACCOM_API DacCom
{
 public:
  DacCom();
  virtual ~DacCom() ;

  void setGroup( char * group );
  void setProtocol( char * protocol );
  void setStatus( ScsStatus status );
  ScsStatus getStatus() const ;
  DacComClientIdl* getComClient() const ;

  void hdleTimer( void* arg );
  virtual void armBasicTimer() = 0;
  void setFirstWakeUpTime(timeval &wakeUpTime);
  void getWakeUpTime(timeval &wakeUpTime);

  void armTimer( unsigned int base, TimerCallbackFunction fct, void* arg );
  void armTimer( unsigned int base, unsigned long delay, unsigned int oneShot,
		 TimerCallbackFunction fct, void* arg ); 

  virtual DacComDevice* configure( const ScsCString& name,
				   const unsigned int id ) = 0;

  virtual ScsStatus sendEiv( unsigned int deviceId,
			     unsigned int eivCount,
			     DacEIV* eiVariables );
				   				   
  virtual ScsStatus sendEov( unsigned int deviceId,
			     unsigned int eovCount,
			     DacEOV* eoVariables );
			     
  virtual ScsStatus shutdown();
			     
  virtual void debugTrace( int level, int inhibTrace = 0 );

  // method to read configuration files
  ScsStatus readVariableList( const ScsCString& name,
			      const unsigned int id,
			      DacDeviceBlock*&    deviceBlock,
			      VariableBlockList*& variableList);

  DeviceBlockList* readConcentrFile() ;
  VariableBlockList* readVariableFile( DacDeviceBlock *deviceBlock );

  // management of daccomdevice list
  DacComDevice* appendToDacComDeviceList(DacComDevice* device);
  DacComDevice* findInDacComDeviceList(unsigned int id);

  
  static ScsStatus getEovFromDacControl(const DacCom* daccom, unsigned int eovCount, const char * const eovNames[], DacEOV *&eovList );


 protected:
  char      *_group ;
  char      *_protocol ;
  DacTimerObjectList _timerList ;
  ScsTimer* _globalTimer ;
  ScsStatus _dacComStatus ;
  DacComServerIdl_i* _comServer ;
  timeval   _firstWakeUpTime;
  DacComDeviceList  _dacComDeviceList;
} ;

#endif // _DAC_DACCOM_H_
