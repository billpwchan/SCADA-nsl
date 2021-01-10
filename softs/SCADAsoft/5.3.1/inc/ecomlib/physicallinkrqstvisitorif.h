/******************************************************************************/
/*                                                                            */
/*  FILE                : physicallinkrqstvisitorif.h                         */
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

#ifndef __SCS_ecomlib_PHYSICALLINKRQSTVISITORIF_H__
#define __SCS_ecomlib_PHYSICALLINKRQSTVISITORIF_H__

#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

class AllStatusesLoadingRqst;
class ConnectRqst;
class DisconnectRqst;
class SendControlsRqst;
class StopRqst;

/**
 * @class PhysicalLinkRqstVisitorIF
 *
 * @brief Physical link requests hierarchy visitor.
 */
class ECOMLIBIF_EXPORT PhysicalLinkRqstVisitorIF {
  
 public:
  
  /**
   * Destructor.
   */
  virtual ~PhysicalLinkRqstVisitorIF() {}

  /**
   * Visit a AllStatusesLoadingRqst instance.
   *
   * @param rqst The request to be visited.
   */
  virtual void visit(AllStatusesLoadingRqst& rqst) = 0;
  
  /**
   * Visit ConnectRqst a instance.
   *
   * @param rqst The request to be visited.
   */
  virtual void visit(ConnectRqst& rqst) = 0;
  
  /**
   * Visit DisconnectRqst a instance.
   *
   * @param rqst The request to be visited.
   */
  virtual void visit(DisconnectRqst& rqst) = 0;
  
  /**
   * Visit SendControlsRqst a instance.
   *
   * @param rqst The request to be visited.
   */
  virtual void visit(SendControlsRqst& rqst) = 0;
  
  /**
   * Visit StopRqst a instance.
   *
   * @param rqst The request to be visited.
   */
  virtual void visit(StopRqst& rqst) = 0;

 protected:
  
  /**
   * Default constructor.
   */
  PhysicalLinkRqstVisitorIF() {}
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  PhysicalLinkRqstVisitorIF(const PhysicalLinkRqstVisitorIF&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  PhysicalLinkRqstVisitorIF& operator=(const PhysicalLinkRqstVisitorIF&);
  
};

};

#endif
