/******************************************************************************/
/*                                                                            */
/*  FILE             : olsrplreplayemulator.h                                 */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : J.MARTINET                                             */
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : 09/07/2004 18:15                                       */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
#ifndef OLSRPLREPLAYEMULATOR_H
#define OLSRPLREPLAYEMULATOR_H

#ifdef SCS_STD
#   include <iostream>
#   include <fstream>
#else
#   include <iostream.h>
#   include <fstream.h>
#endif

#ifdef SCS_STD
#include <sstream>
#else
#ifdef _WINDOWS
#include <strstrea.h>
#else
#define istringstream istrstream
#include <strstream.h>
#endif
#endif

#include "scsrpl.h"

class OlsRplReplayEmulator : public ScsRplReplayEmulator
{
public:
    OlsRplReplayEmulator(int period = 250);
    virtual ~OlsRplReplayEmulator();
    
    virtual ScsStatus init(long pDate);
    virtual ScsStatus go(timeval pTime);
    virtual ScsStatus newRecord(unsigned int recordSize,
				const char *record);

private:
    ScsStatus readIncrSnapFiles(timeval pTimeFrom, timeval pTimeTo);
    ScsStatus openStream(const char* pFileName);
    ScsStatus closeStream();
    ScsStatus readIncrRecord(timeval pTimeTo);
    ScsStatus updateList(SCS_SL_STD(istream) &is);
    
    timeval _lastTimeTreated;
    int _lastIndexTreated;
    SCS_SL_STD(ifstream) *_ifstream;
    bool _isStreamOpen;
    timeval _lastTimeRead;
    long _indexRec;
    long _nbRecords;
    int _period;
};


#endif //OLSRPLREPLAYEMULATOR_H


