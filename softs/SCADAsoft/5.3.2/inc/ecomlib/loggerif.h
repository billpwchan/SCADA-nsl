/******************************************************************************/
/*                                                                            */
/*  FILE                : logger.h                                            */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 04-13-10                                            */
/*  LANGUAGE            : C++                                                 */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*............................................................................*/
/*  CONTENTS                                                                  */
/******************************************************************************/
/* IDENTIFICATION:
 *
 * HISTORY:
 */
/******************************************************************************/

#ifndef __SCS_ecomlib_LOGGERIF_H__
#define __SCS_ecomlib_LOGGERIF_H__

#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

/**
 * @class LoggerIF
 *
 * @brief The incoming/outgoing data logger interface.
 */
class ECOMLIBIF_EXPORT LoggerIF {
  
 public:
  
  /**
   * Destructor.
   */
  virtual ~LoggerIF();

  /**
   * To be invoked when a buffer has been received from the RTU.
   * 
   *
   * @param buffer The buffer received from the RTU.
   * @param size   The buffer size.
   * @param offset The buffer offset.
   */
  virtual void  fromRtuTrace(const unsigned char* buffer,unsigned long size,unsigned long offset) = 0;
  
  /**
   * To be invoked when a buffer has been written to the RTU.
   *
   * @param buffer The buffer written to the RTU;
   * @param size   The buffer size.
   */
  virtual void  toRtuTrace(const unsigned char* buffer,unsigned long size) = 0;
  
  /**
   * To be invoked when a full msg comes from/to the RTU.
   *
   * @param msg The string message (ended with 0)
   * @param fromRtu   true if the message comes from the RTU, false if sent to the RTU
   * @param rawMode  true if the message has to be printed as-this (no additional info)   
   */
  virtual void rtuTrace(const char* msg, bool fromRtu, bool rawMode) = 0;
  
  // just say if Spy mode is active or not
  virtual bool isSpyOn() = 0;
  
 protected:
  
  /**
   * Default constructor.
   */
  LoggerIF();
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  LoggerIF(const LoggerIF&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  LoggerIF& operator=(const LoggerIF&);
  
};

};

#endif
