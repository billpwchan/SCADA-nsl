/******************************************************************************/
/*                                                                            */
/*  FILE                : allstatusesloadingrqst.h                            */
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

#ifndef __SCS_ecomlib_ALLSTATUSESLOADINGRQST_H__
#define __SCS_ecomlib_ALLSTATUSESLOADINGRQST_H__

#include <ecomlib/physicallinkrqst.h>

namespace ecomlib {

/**
 * @class AllStatusesLoadingRqst
 *
 * @brief Require the physical link to send all statuses loading
 *        request to the concentrator.
 */
class ECOMLIBIF_EXPORT AllStatusesLoadingRqst 
  : public PhysicalLinkRqst {
  
 public:
  
  /**
   * Default constructor.
   */
  AllStatusesLoadingRqst() {}
  
  /**
   * Destructor.
   */
  virtual ~AllStatusesLoadingRqst() {}
  
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
  AllStatusesLoadingRqst(const AllStatusesLoadingRqst&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  AllStatusesLoadingRqst& operator=(const AllStatusesLoadingRqst&);
  
};

};

#endif
