/******************************************************************************/
/*                                                                            */
/*  FILE                : constants.h                                         */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 04-14-10                                            */
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

#ifndef __SCS_ecomlib_CONSTANTS_H__
#define __SCS_ecomlib_CONSTANTS_H__

#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

/**
 * @class Constants
 *
 * @brief Extended com library constants.
 */
class ECOMLIBIF_EXPORT Constants {
  
 public:

  /**
   * Trace level for information.
   */
  static unsigned int GetTR_INFO_LEVEL();
  
  /**
   * Trace level for warnings.
   */
  static unsigned int GetTR_WARNING_LEVEL();
  
  /**
   * Trace level for internal errors.
   */
  static unsigned int GetTR_ERROR_LEVEL();
  
  /**
   * Destructor.
   */
  virtual ~Constants() {}
  
 private:
  
  /**
   * Default constructor is private and not implemented.
   */
  Constants();
  
  /**
   * Copy constructor is private and not implemented.
   */
  Constants(const Constants&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  Constants& operator=(const Constants&);
  
};

};

#endif
