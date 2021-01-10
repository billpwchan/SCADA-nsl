/******************************************************************************/
/*                                                                            */
/*  FILE                : physicallinkif.h                                    */
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

#ifndef __SCS_ecomlib_PHYSICALLINKIF_H__
#define __SCS_ecomlib_PHYSICALLINKIF_H__

#include <list>
#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

class LineIF;
class PhysicalLinkRqst;

/**
 * @class PhysicalLinkIF
 *
 * @brief A physical link between a daccom and its concentrator. The run
 *        method has to be override to process the connection/disconnection 
 *        submitted requests and wait for connected concentrator incoming 
 *        data. When incoming data are received or a connection (resp. 
 *        disconnection) event occured, the line interface has to be 
 *        notified.
 */
class ECOMLIBIF_EXPORT PhysicalLinkIF {
  
 public:
  
  //
  // Some useful type definitions.
  // 
  typedef std::list<PhysicalLinkRqst*>           Rqsts;
  typedef std::list<PhysicalLinkRqst*>::iterator RqstsIter;
  
  /**
   * Destructor.
   */
  virtual ~PhysicalLinkIF();

  /**
   * Add a request at the end of the pending request queue. The
   * physical link becomes the owner of the provided request,
   * the caller shall not released the request once this method
   * has returned.
   *
   * @param rqst A valid heap allocated request. 
   */
  void append(PhysicalLinkRqst* rqst);
  
  /**
   * Add a request to the front of the pending request queue. The
   * physical link becomes the owner of the provided request,
   * the caller shall not released the request once this method
   * has returned.
   *
   * @param rqst A valid heap allocated request. 
   */
  void preprend(PhysicalLinkRqst* rqst);

  /**
   * Automatically invoked when the daccom is ready to connect 
   * to the concentrator physically. The extended com library
   * assures this method will be invoked into its own thread 
   * of control. 
   * 
   * @param line The line to be notified with connection, disconnection
   *             and incoming data events.
   */
  virtual void run(LineIF& line) = 0;

  /**
   * Automatically invoked when a request is going to be added 
   * into the pending request list. The implementation shall 
   * assure that there will no concurent acces on th pending 
   * request list between the thread invoking the append/prepend 
   * method and the run method own thread.
   */
  virtual void lock() const = 0;
  
  /**
   * Automatically invoked when a request has been be added 
   * into the pending request list. The implementation shall 
   * assure that lock previously grabbed is released.
   */
  virtual void unlock() const = 0;
  
  /**
   * Automatically invoked by append and prepend method when the
   * pending request queue size increases to one. The invocation
   * is protected under lock/unlock invocations.
   *
   * @param wasEmpty True when the queue whas empty before insertion,
   *                 false otherwise.
   */
  virtual void signal(bool wasEmpty) = 0;

 protected:
  
  /**
   * Default constructor.
   */
  PhysicalLinkIF();
  
  /** 
   * Pending requests queue read accessor for sub-classes.
   *
   * @return The pending requests queue read.
   */
  Rqsts& getPendingRqst() { return _pendingRqsts; }
  
 private:
  
  /**
   * The list of pending requests.
   */
  Rqsts _pendingRqsts;
  
  /**
   * Copy constructor is private and not implemented.
   */
  PhysicalLinkIF(const PhysicalLinkIF&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  PhysicalLinkIF& operator=(const PhysicalLinkIF&);
  
};

};

#endif
