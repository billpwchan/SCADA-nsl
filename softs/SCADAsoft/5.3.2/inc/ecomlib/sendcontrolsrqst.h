/******************************************************************************/
/*                                                                            */
/*  FILE                : sendcontrolsrqst.h                                  */
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

#ifndef __SCS_ecomlib_SENDCONTROLSRQST_H__
#define __SCS_ecomlib_SENDCONTROLSRQST_H__

#include <ecomlib/physicallinkrqst.h>

class DacComCommandVector;

namespace ecomlib {

/**
 * @class SendControlsRqst
 *
 * @brief Require the physical link to send controls to
 *        the concentrator.
 */
class ECOMLIBIF_EXPORT SendControlsRqst : public PhysicalLinkRqst {
  
 public:
  
  /**
   * Default constructor.
   */
  SendControlsRqst(DacComCommandVector* controls);
  
  /**
   * Destructor.
   */
  virtual ~SendControlsRqst();
  
  /**
   * Downcast automatically this request into its 
   * most derivated class.
   *
   * @param visitor A visitor looking for this request
   *                most derivated class.
   */
  void accept(PhysicalLinkRqstVisitorIF& visitor);

  /**
   * The controls read accessor.
   *
   * @return The controls. 
   */
  const DacComCommandVector& getControls() const { return (*_controls); }
  
 private:

  /** 
   * The controls list.
   */
  DacComCommandVector* _controls;
  
  /**
   * Copy constructor is private and not implemented.
   */
  SendControlsRqst(const SendControlsRqst&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  SendControlsRqst& operator=(const SendControlsRqst&);
  
};

};

#endif
