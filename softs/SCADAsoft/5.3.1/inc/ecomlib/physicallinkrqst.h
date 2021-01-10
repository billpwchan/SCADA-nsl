/******************************************************************************/
/*                                                                            */
/*  FILE                : physicallinkrqst.h                                  */
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

#ifndef __SCS_ecomlib_PHYSICALLINKRQST_H__
#define __SCS_ecomlib_PHYSICALLINKRQST_H__

#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

class PhysicalLinkRqstVisitorIF;

/**
 * @class PhysicalLinkRqst
 *
 * @brief Root class of the physical link requests classes.
 */
class ECOMLIBIF_EXPORT PhysicalLinkRqst {
  
 public:
  
  /**
   * Destructor.
   */
  virtual ~PhysicalLinkRqst() {}

  /**
   * Downcast automatically this request into its 
   * most derivated class.
   *
   * @param visitor A visitor looking for this request
   *                most derivated class.
   */
  virtual void accept(PhysicalLinkRqstVisitorIF& visitor) =0;
  
 protected:
  
  /**
   * Default constructor.
   */
  PhysicalLinkRqst() {}
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  PhysicalLinkRqst(const PhysicalLinkRqst&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  PhysicalLinkRqst& operator=(const PhysicalLinkRqst&);
  
};

};

#endif
