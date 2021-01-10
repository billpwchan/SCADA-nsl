
#ifndef _ACK_RESET_LOG_HEADER_
#define _ACK_RESET_LOG_HEADER_
 
#include "ackreset.h"

class ALMSTDAUT_API AckResetLog : public AckReset 
{
 public:
  AckResetLog(const AlmInteger64  inAutoId,
	    const DbkAddressId* inDbkAddressId);
  AckResetLog(const AckResetLog &    inAckReset);
  ~AckResetLog();

 private:
  CREATOR_H(AckResetLog)
};

#endif // _ACK_RESET_LOG_HEADER_

 
