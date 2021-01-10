/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/

#ifndef _ACKSHELVE_HEADER_
#define _ACKSHELVE_HEADER_

#include "scsbasicackautomaton.h"

class ALMSTDAUT_API AckShelve: public ScsBasicAckAutomaton
{
 public:
  AckShelve (const AlmInteger64 inAutoId,
	     const DbkAddressId* inDbkAddressId) 
    : ScsBasicAckAutomaton(inAutoId, inDbkAddressId)
    { BSReset(); }
  
  AckShelve (const AckShelve & inAckShelve) 
    : ScsBasicAckAutomaton(inAckShelve)
    { BSReset(); }
  
  virtual ~AckShelve () {}

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
  CREATOR_H(AckShelve)
  int PS;
  int NS;
};

#endif // _ACKSHELVE_HEADER_


