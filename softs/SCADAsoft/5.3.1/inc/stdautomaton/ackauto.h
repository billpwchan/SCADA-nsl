/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : ackauto.h                                            */
/*  FULL NAME       : AckAuto                                              */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : ESA   	                                           */
/*  COMPANY         : Thales Transportation Systems                        */
/*  CREATION DATE   : 30 04 2008                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  Automatic acknowledgement without log                                  */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AckAuto's interface.                               */
/***************************************************************************/
#ifndef _ACKAUTO_HEADER_
#define _ACKAUTO_HEADER_
 
#include "scsbasicackautomaton.h"

class ALMSTDAUT_API AckAuto : public ScsBasicAckAutomaton 
{
 public:
  AckAuto (const AlmInteger64  inAutoId,
	   const DbkAddressId* inDbkAddressId);
  AckAuto (const AckAuto & inAckAuto);
  ~AckAuto();

  virtual int BSFire(const int inNewAlarmState, 
		     int & ioSeverity, 
		     const int inAckRequest, 
		     int & outNewAckState, 
		     const int inShelveRequest, 
		     int & outNewShelveStatus, 
		     const long inUserId);
  // redondancy
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(AckAuto)
};

#endif // _ACKAUTO_HEADER_
