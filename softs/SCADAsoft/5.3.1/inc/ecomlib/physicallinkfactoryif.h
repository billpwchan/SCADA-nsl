/******************************************************************************/
/*                                                                            */
/*  FILE                : physicallinkfactoryif.h                             */
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

#ifndef __SCS_ecomlib_PHYSICALLINKFACTORYIF_H__
#define __SCS_ecomlib_PHYSICALLINKFACTORYIF_H__

#include <scs.h>

#include <vector>
#include <string>

#include <ecomlib/ecomlib_exports.h>

class DacComInVariable;

namespace ecomlib {

class PhysicalLinkIF;
class LoggerIF;

typedef std::vector< std::string >             LineAddresses;
typedef std::vector< PhysicalLinkIF* >         Links;
typedef std::vector< LoggerIF* >               Loggers;
typedef std::vector< const DacComInVariable* > InVariables;

/**
 * @class PhysicalLinkFactoryIF
 *
 * @brief The PhysicalLinkFactoryIF interface enables to associates line with
 *        physical link whatever the concentrator and the protocol used to 
 *        exchange data with it are.
 */
class ECOMLIBIF_EXPORT PhysicalLinkFactoryIF {
  
 public:
  
  /**
   * Destructor.
   */
  virtual ~PhysicalLinkFactoryIF() {}

  /**
   * Require the creation of the concrete links to be associated with the 
   * extended com library lines.
   *
   * @param exchange_filename The daccom exchanged file name from the 
   *                          ScsDacCtrt.cfg.
   * @param addresses         The generic daccom device line addresses.
   * @param eivs              The generic daccom device external internal 
   *                          variables.
   * @param links             The physical links to be associated with the
   *                          generic daccom lines.
   * @param loggers           Some loggers to use to log incoming and 
   *                          outgoing raw data buffers.
   * 
   * @return An ScsError when the links creation has failed.
   */
  virtual ScsStatus getLinks(const char*          exchange_filename,
			     const LineAddresses& addresses,
			     const InVariables&   eivs,
			     const InVariables&   specific_eivs,
			     Links&               links,
			     Loggers&             logger) = 0;
  
 protected:
  
  /**
   * Default constructor.
   */
  PhysicalLinkFactoryIF() {}
  
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  PhysicalLinkFactoryIF(const PhysicalLinkFactoryIF&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  PhysicalLinkFactoryIF& operator=(const PhysicalLinkFactoryIF&);
  
};

};

#endif
