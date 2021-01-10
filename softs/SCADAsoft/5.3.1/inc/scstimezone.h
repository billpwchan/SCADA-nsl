/******************************************************************************/
/*                                                                            */
/*  FILE             : ScsTimeZone.h                                          */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES INFORMATION SYSTEMS                             */
/*  CREATION DATE    : Fri Aug 02 07:30:42 2002                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/


#ifndef __SCS_TIME_ZONE_H__
#define __SCS_TIME_ZONE_H__

/** \file
    \brief Timezone management.
*/

#include <time.h>

#include "scsdefs.h"

struct RWDaylightRule;
class RWCString;
class RWZoneSimple;

/**
   \brief This class allows new time zones with specific daylight-saving time rule(s).

\code#include "ScsTimeZone.h"\endcode
*/
class SCS_API ScsTimeZone
{
public:
/**@name Constructor / Destructor*/
//@{
  /**
     \par Description:
     Constructor. Constructs a time zone named <em>ZoneName</em> which daylight-saving time (DST) is computed according to the rules specified in the file <em>FileName</em>.
     \param pZoneName  [in]: new zone's name.
     \param pFileName  [in]: file to load in which rules are defined. The file <em>pFileName</em> must be placed in the "$SCSPATH/timezones" directory.. This file contains the following informations, separated by a comma (",") : the year in which this rule first goes in effect, a boolean value that can be used to specify a period of years for which DST is not observed (1 = DST is in effect, 0 = DST is not in effect), the month when DST begins (from 0 to 11, 0 = January), the week when DST begins (from 0 to 4, 0 = first week; or -1), the weekday when DST begins (from 0 to 6, 0 = Sunday; or from 1 to 31 if week = - 1), the minute when DST begins (from 0 to 1439; Usually 2AM = 120), the month when DST ends (from 0 to 11, 0 = January), the week when DST ends (from 0 to 4, 0 = first week; or -1), the weekday when DST ends (from 0 to 6, 0 = Sunday; or from 1 to 31 if week = - 1), the minute when DST ends (from 0 to 1439; Usually 2AM = 120). If several rules are specified in this file, there must be one rule per line and they must be in increasing order. If the file is empty, a default rule willl be used and a error message will be displayed, but this will not stop the application. The DST will not be in effect in this case, until the "StartDST" procedure will be called.
     \param pTzOffset  [in]: the offset from GMT (in seconds, positive if west of 0 degrees longitude).
     \param pAltOffset  [in]: the offset (typically equal to TzOffset - 3600) when DST is in effect.
     \par Return values:
     none.
  */
	ScsTimeZone(const char* pZoneName, const char* pFileName, const int pTzOffset, const int pAltOffset);

  /**
     \par Description:
     Destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
	~ScsTimeZone();
//@}

/**@name Saving rules facilities*/
//@{
  /**
     \par Description:
     Saves the daylight-saving rules of the time zone named <em>ZoneName</em> in the file specified in the constructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
	int SaveFile();
//@}

/**@name General members*/
//@{

  /**
     \par Description:
     Starts the DST (daylight-saving time).
     \param pTmBuf  [in]: structure in which a date is stored.
     \par Return values:
     none.
  */
	void SetDSTStart(struct tm* pTmBuf);

  /**
     \par Description:
     Ends the DST.
     \param pTmBuf  [in]: structure in which a date is stored.
     \par Return values:
     none.
  */
	void SetDSTEnd(struct tm* pTmBuf);

  /**
     \par Description:
     Applies the time zone.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
	void ApplyTimeZone();
//@}
	const char* getZoneName() { return _zoneName; };


protected:
//
// ---- Functions
//
	//  Load the file in which daylight tules are defined. Returns 0 if succeeded.*/
	int LoadFile(RWDaylightRule* &pRule, const char* pFileName);
	
	void AddRulesToStr(const RWDaylightRule *pRule, RWCString& pString);
	void SaveSingleRule(const RWDaylightRule *pRule, RWCString& pString);
	RWDaylightRule* findRule(const struct tm* pTmBuf);
	RWDaylightRule* findPreviousRule(const struct tm* pTmBuf);
	int isDayLight(const struct tm* pTmBuf);

private:
//
// ---- Attributes
//
	RWZoneSimple *_userZone;
	char* _fileName;
	char* _zoneName;
	int _dayLightObserved;
	int _tzOffset;
	int _altOffset;
	RWDaylightRule* _rule;

};


#endif


