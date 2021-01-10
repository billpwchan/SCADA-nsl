/******************************************************************************/
/*                                                                            */
/*  FILE                : lineif.h                                            */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 02-01-10                                            */
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

#ifndef __SCS_ecomlib_LINEIF_H__
#define __SCS_ecomlib_LINEIF_H__

#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

class IncomingDataIF;

/**
 * @class LineIF
 *
 * @brief LineIF interface provides method to notify extended com library
 *        generic daccom with concentrator connection/disconnection events
 *        and incoming data.
 */
class ECOMLIBIF_EXPORT LineIF {
  
 public:
  
  /**
   * Destructor.
   */
  virtual ~LineIF() {}

  /**
   * Concentrator disconnection notification event.
   */
  virtual void gotDisconnected() = 0;

  /**
   * Concentrator connection notification event.
   */
  virtual void gotConnected() = 0;
  
  /**
   * Concentrator acquired incoming data notification.
   *
   * @param data The acquired incoming data.
   */
  virtual void gotData(IncomingDataIF* data) = 0;
  
 protected:

  /**
   * Default constructor.
   */
  LineIF() {}
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  LineIF(const LineIF&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  LineIF& operator=(const LineIF&);
  
};

};

#endif
