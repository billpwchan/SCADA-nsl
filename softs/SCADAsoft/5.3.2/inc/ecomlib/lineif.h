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
  
  virtual ~LineIF() {}  

  /** 
   * Set to true if you want a 'ConnectionRequest' to follow every 'gotDisconnected' call.
   * This is true by default.
   */
  virtual void setAutoReconnect(bool autoReconnect)  { _autoReconnect = autoReconnect; }

  /**
    * @returns true if a 'ConnectionRequest' will follow a call t 'gotDisconnected'.
    */
  bool autoReconnect() const { return _autoReconnect; }

  /**
    * Set to true if you want the 'All Status Loading Requests' to be sent by ecomlib.
    * True by default.
    */
  virtual void setSendAllStatusesLoadingRequests(bool send) { _sendAllStatusesLoadingRequests = send; }

  /**
    * @returns true if the 'All Status Loading Requests' are sent by ecomlib.
    */
  virtual bool sendAllStatusesLoadingRequests() const { return _sendAllStatusesLoadingRequests; }

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

  LineIF() : _autoReconnect(true), _sendAllStatusesLoadingRequests(true) {}
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  LineIF(const LineIF&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  LineIF& operator=(const LineIF&);
  
  bool _autoReconnect;
  bool _sendAllStatusesLoadingRequests;
};

}

#endif
