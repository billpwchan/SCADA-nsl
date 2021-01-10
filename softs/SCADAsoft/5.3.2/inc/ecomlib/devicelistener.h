/** @file devicelistener.h  
    Allows the user of the ecomlib to define functions that will be called every time a specific
    operation on a device is performed.
*/

#ifndef __SCS_ecomlib_DEVICELISTENER_H__
#define __SCS_ecomlib_DEVICELISTENER_H__

#include <dac.h>
#include <ecomlib/ecomlib_exports.h>

namespace ecomlib
{
   class ECOMLIBIF_EXPORT DeviceListener
   {
     public:
      /** Called when a specific EIV is updated. */
      virtual void hdleSpecificEiv(const DacEIV *) = 0;
      
      /** Called when a specific EOV is updated, after the ecomlib has checked the line state. */ 
      virtual void hdleSpecificEov(const DacEOV *) = 0;
   };
}

#endif // __SCS_ecomlib_DEVICELISTENER_H__
