/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : dibasic2statelog.h                                   */
/*  FULL NAME       : DIBasic2Statelog                                     */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  DI value automaton with 2 states and with log when acknowledge         */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes DIBasic2StateLog's interface.                      */
/***************************************************************************/

#ifndef _BS_DIBASIC2STATELOG_HEADER_
#define _BS_DIBASIC2STATELOG_HEADER_

#include "dibasic2state.h"

class ALMSTDAUT_API DIBasic2StateLog : public DIBasic2State
{

 public:
  DIBasic2StateLog(const AlmInteger64  inAutoId,
		   const DbkAddressId* inDbkAdddressid);
  ~DIBasic2StateLog();
  
 private:
  CREATOR_H(DIBasic2StateLog)
};
#endif   /* _BS_DIBASIC2STATELOG_HEADER_ */


