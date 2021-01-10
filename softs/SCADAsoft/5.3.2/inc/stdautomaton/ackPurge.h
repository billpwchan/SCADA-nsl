/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/

#ifndef _ACKPURGE_HEADER_
#define _ACKPURGE_HEADER_

#include "scsbasicackautomaton.h"

class ALMSTDAUT_API AckPurge: public ScsBasicAckAutomaton
{
 public:
  AckPurge (const AlmInteger64 inAutoId,
       const DbkAddressId* inDbkAddressId) : ScsBasicAckAutomaton(inAutoId, inDbkAddressId)
  { BSReset();}
  
  AckPurge (const AckPurge & inAckPurge) : ScsBasicAckAutomaton(inAckPurge)
  { BSReset();}
  
  
  virtual ~AckPurge () {}

  virtual int BSReset();

  virtual int BSFire(const int inNewAlarmState,
                     int & ioSeverity,
                     const int inAckRequest,
                     int & outNewAckState,
                     const int inShelveRequest,
                     int & outNewShelveStatus,
                     const long inUserId);

  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(AckPurge)
  int PS;
  int NS;
};

#endif // _ACKPURGE_HEADER_


