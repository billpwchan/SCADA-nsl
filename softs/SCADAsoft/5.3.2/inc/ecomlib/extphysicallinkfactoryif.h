// @file extphysicallinkfactoryif.h

#ifndef __SCS_ecomlib_EXTPHYSICALLINKFACTORYIF_H__
#define __SCS_ecomlib_EXTPHYSICALLINKFACTORYIF_H__

#include <ecomlib/physicallinkfactoryif.h>

class DacComOutVariable;


namespace ecomlib
{
  typedef std::vector< const DacComOutVariable* > OutVariables;

  /**
   * @class ExtPhysicalLinkFactoryIF
   *
   * @brief Extends PhysicalLinkFactoryIF with a version of
   * getLinks() allowing to pass EOV.
   *
   * This class is more likely to change than `PhysicalLinkFactoryIF`, so
   * try to use `PhysicalLinkFactoryIF` whenever possible.
   */

  class ECOMLIBIF_EXPORT ExtPhysicalLinkFactoryIF : public PhysicalLinkFactoryIF
  {
    public:
      virtual ~ExtPhysicalLinkFactoryIF() { }
      /**
        * Require the creation of the concrete links to be associated with the
        * extended com library lines.
        *
        * @param exchange_filename The daccom exchanged file name from the
        *                          `ScsDacCtrt.cfg`.
        * @param addresses         The generic daccom device line addresses.
        * @param eivs              The generic daccom device external input
        *                          variables.
        * @param eovs              The generic daccom device external output
        *                          variables.
        * @param links             The physical links to be associated with the
        *                          generic daccom lines.
        * @param loggers           Some loggers to use to log incoming and
        *                          outgoing raw data buffers.
        *
        * @return An ScsError when the links creation has failed.
      */
      virtual ScsStatus getLinks(const char* exchange_filename,
        const LineAddresses& addresses,
        const InVariables& eivs,
        const InVariables& specific_eivs,
        const OutVariables& eovs,
        const OutVariables& specific_eovs,
        Links& links,
        Loggers& logger) = 0;

    protected:
      ExtPhysicalLinkFactoryIF() {}

    private:
      // Not implemented.
      ExtPhysicalLinkFactoryIF(const ExtPhysicalLinkFactoryIF&);
      ExtPhysicalLinkFactoryIF& operator = (const ExtPhysicalLinkFactoryIF&);
  };
}

#endif
