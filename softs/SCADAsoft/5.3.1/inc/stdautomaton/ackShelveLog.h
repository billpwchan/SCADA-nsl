/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/

#ifndef _ACKSHELVE_LOG_HEADER_
#define _ACKSHELVE_LOG_HEADER_

#include "ackShelve.h"

class ALMSTDAUT_API AckShelveLog: public AckShelve
{
 public:
  AckShelveLog (const AlmInteger64  inAutoId,
                          const  DbkAddressId* inDbkAddressId);
 
  AckShelveLog (const AckShelveLog& inAckShelveLog);
 
  virtual ~AckShelveLog () {}

 private:
  CREATOR_H(AckShelveLog)
};

#endif // _ACKSHELVE_LOG_HEADER_


