/******************************************************************************/
/*                                                                            */
/*  FILE                : incomingdataif.h                                    */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 02-09-10                                            */
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

#ifndef __SCS_ecomlib_INCOMINGDATAIF_H__
#define __SCS_ecomlib_INCOMINGDATAIF_H__

#include <ecomlib/physicallinkfactoryif.h>
#include <vector>

class DacEIV;

namespace ecomlib {

//
// Some usefull type definitions
//
typedef std::vector<DacEIV*> DacEIVs;

/**
 * @class IncomingDataIF
 *
 * @brief Interface for wrapping incoming data.
 */
class ECOMLIBIF_EXPORT IncomingDataIF {
  
 public:
  
  /**
   * Destructor.
   */
  virtual ~IncomingDataIF() {}

  /**
   * Umarshall the incoming status indication telegram and compute
   * the corresponding to be updated variables list and eivs from 
   * unmarshalled data.
   *
   * @param variables Updated with the corresponding to be updated 
   *                  variables.
   * @param eivs      Updated with the corresponding values.
   */
  virtual void unmarshall(InVariables& variables,DacEIVs& eivs) = 0;
  
  bool updateOnTimestampChange() const { return m_updateOnTimestampChange; }
  
 protected:
  
  /**
   * Default constructor.
   */
  IncomingDataIF() : m_updateOnTimestampChange(false) {}
  
  IncomingDataIF(bool tsc) : m_updateOnTimestampChange(tsc) {}
      
 private:
  
  /**
   * Copy constructor is private and not implemented.
   */
  IncomingDataIF(const IncomingDataIF&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  IncomingDataIF& operator=(const IncomingDataIF&);
  
  bool m_updateOnTimestampChange;
};

};

#endif
