/******************************************************************************/
/*                                                                            */
/*  FILE                : disconnectrqst.h                                    */
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

#ifndef __SCS_ecomlib_DISCONNECTRQST_H__
#define __SCS_ecomlib_DISCONNECTRQST_H__

#include <ecomlib/physicallinkrqst.h>

namespace ecomlib {

/**
 * @class DisconnectRqst
 *
 * @brief Require the physical link to disconnect from
 *        the concentrator.
 */
class ECOMLIBIF_EXPORT DisconnectRqst 
  : public PhysicalLinkRqst {
  
 public:
  
  /**
   * Default constructor.
   */
  DisconnectRqst() {}
  
  /**
   * Destructor.
   */
  virtual ~DisconnectRqst() {}
  
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
  DisconnectRqst(const DisconnectRqst&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  DisconnectRqst& operator=(const DisconnectRqst&);
  
};

};

#endif
