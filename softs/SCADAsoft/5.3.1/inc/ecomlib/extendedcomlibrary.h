/******************************************************************************/
/*                                                                            */
/*  FILE                : extendedcomlibrary.h                                */
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

#ifndef __SCS_ecomlib_EXTENDEDCOMLIBRARY_H__
#define __SCS_ecomlib_EXTENDEDCOMLIBRARY_H__

#include <scs.h>
#include <ecomlib/ecomlib_exports.h>

namespace ecomlib {

class PhysicalLinkFactoryIF;

/**
 * @class ExtendedComLibrary
 *
 * @brief ExtendedComLibrary provides static method to perform initialization
 *        of the extended com library, to run the generic daccom CORBA main
 *        loop and release resources before exiting daccom main function.
 */
class ECOMLIBIF_EXPORT ExtendedComLibrary {
  
 public:

  /**
   * Initialize the extended com library generic daccom.
   *
   * @param factory Register a factory to use to get physical links.
   * @param argc    Command line parameters count.
   * @param argv    Command line paraemters.
   */
  static ScsStatus Initialize(PhysicalLinkFactoryIF& factory,int argc,char** argv);

  /**
   * Start the CORBA main loop.
   */
  static ScsStatus Run();

  /**
   * Release extended com library generic daccom resources.
   */
  static void Release();

 private:
  
  /**
   * Default constructor is private and not implemented.
   */
  ExtendedComLibrary();
  
  /**
   * Destructor.
   */
  virtual ~ExtendedComLibrary();
  
  /**
   * Copy constructor is private and not implemented.
   */
  ExtendedComLibrary(const ExtendedComLibrary&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  ExtendedComLibrary& operator=(const ExtendedComLibrary&);
  
};

};

#endif
