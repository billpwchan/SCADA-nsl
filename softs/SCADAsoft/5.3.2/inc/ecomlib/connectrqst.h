/******************************************************************************/
/*                                                                            */
/*  FILE                : connectrqst.h                                       */
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

#ifndef __SCS_ecomlib_CONNECTRQST_H__
#define __SCS_ecomlib_CONNECTRQST_H__

#include <ecomlib/physicallinkrqst.h>

namespace ecomlib {

/**
 * @class ConnectRqst
 *
 * @brief Require the physical link to establish the connection
 *        with the concentrator.*
 */
class ECOMLIBIF_EXPORT ConnectRqst 
  : public PhysicalLinkRqst {
  
 public:
  
  /**
   * Default constructor.
   */
  ConnectRqst(bool becomingOnline = false) { 
    _becomingOnline = becomingOnline; 
  }
  
  /**
   * Destructor.
   */
  virtual ~ConnectRqst() {}
  
  /**
   * Downcast automatically this request into its 
   * most derivated class.
   *
   * @param visitor A visitor looking for this request
   *                most derivated class.
   */
  void accept(PhysicalLinkRqstVisitorIF& visitor);
  
  bool becomingOnline() {
    return _becomingOnline;
  }
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  ConnectRqst(const ConnectRqst&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  ConnectRqst& operator=(const ConnectRqst&);
  
  bool _becomingOnline;
  
};

};

#endif
