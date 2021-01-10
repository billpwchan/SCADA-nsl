#ifndef _DAC_DACCOMEXCHANGEBLOCK_H_
#define _DAC_DACCOMEXCHANGEBLOCK_H_


/******************************************************************************/
/*                                                                            */
/*  FILE             : daccomexchangeblock.h                                  */
/*  FULL NAME        : Dac Exchange Block                                     */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : M. Promonet                                            */
/*  COMPANY          : THALES                                                 */
/*  CREATION DATE    :                                                        */
/*  LANGUAGE         : C++                                                    */
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

#include "daccomdevice.h"

class DacComExchangeBlock
{  
 public:
  DacComExchangeBlock(DacComDevice* device): _device(device), _currentLine(NULL) {} ;
  virtual ~DacComExchangeBlock() {};

  DacDevice* getDevice() const { return _device; };
  DacStateLine* getLine(const char *address) { 
    if (_device) {
      return _device->getStateLine(address); 
    } else {
      return NULL;
    }
  };
  DacStateLine* getCurrLine() { return _currentLine; };
  void setCurrLine(DacStateLine* currentLine) { _currentLine = currentLine; };

 private:
  DacComExchangeBlock& operator=( DacComExchangeBlock& arg ) { return *this; };

 protected:
  DacComDevice*    _device;
  DacStateLine*    _currentLine;
};

#endif // _DAC_DACCOMEXCHANGEBLOCK_H_
