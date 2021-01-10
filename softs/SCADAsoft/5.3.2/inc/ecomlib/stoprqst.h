/******************************************************************************/
/*                                                                            */
/*  FILE                : stoprqst.h                                          */
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

#ifndef __SCS_ecomlib_STOPRQST_H__
#define __SCS_ecomlib_STOPRQST_H__

#include <ecomlib/physicallinkrqst.h>

namespace ecomlib {

/**
 * @class StopRqst
 *
 * @brief A technical request which requires the physical 
 *        main loop to stop as soon as possible.
 */
class ECOMLIBIF_EXPORT StopRqst : public PhysicalLinkRqst {
  
 public:
  
  /**
   * Default constructor.
   */
  StopRqst() {}
  
  /**
   * Destructor.
   */
  virtual ~StopRqst() {}
  
  /**
   * Downcast automatically this request into its 
   * most derivated class.
   *
   * @param visitor A visitor looking for this request
   *                most derivated class.
   */
  void accept(PhysicalLinkRqstVisitorIF& visitor);
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  StopRqst(const StopRqst&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  StopRqst& operator=(const StopRqst&);
  
};

};

#endif
