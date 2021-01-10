/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/

#ifndef _ACKPURGELOG_HEADER_
#define _ACKPURGELOG_HEADER_

#include "ackPurge.h"

class ALMSTDAUT_API AckPurgeLog : public AckPurge
{
 public:
  AckPurgeLog (const AlmInteger64 inAutoId,
       const DbkAddressId* inDbkAddressId) : AckPurge(inAutoId, inDbkAddressId)
  { setFlagLogEvent();BSReset();}
  
  AckPurgeLog (const AckPurgeLog & inAckPurge) : AckPurge(inAckPurge)
  { setFlagLogEvent ();BSReset();}
  
  virtual ~AckPurgeLog () {}

 private:
  CREATOR_H(AckPurgeLog)
};

#endif // _ACKPURGELOG_HEADER_


