//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : msgfilter.h                                            */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : Y. Lozinguez                                           */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Wed Dec  2 14:14:59 1998                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: msgfilter.h,v 1.4 1999/08/17 16:40:17 scadaref Exp $
//
// HISTORY:
// $Log: msgfilter.h,v $
// Revision 1.4  1999/08/17 16:40:17  scadaref
// Port on Orbix 3.0
//
// Revision 1.3  1998/12/14 14:10:43  ylo
// Use Scadasoft portable thread library.
//
// Revision 1.2  1998/12/07 17:27:00  scadaref
// Port on Windows NT.
//
// Revision 1.1  1998/12/07 15:59:27  ylo
// Initial revision
//


#ifndef _SCS_MSGFILTER_H_
#define _SCS_MSGFILTER_H_

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "scsredtype.hh"
#include "scsthread.h"

#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef IMG_EXPORTS
        #define IMG_API __declspec(dllexport)
        #else
        #define IMG_API __declspec(dllimport)
        #endif
        
    #else
        #define IMG_API
    #endif
#else
    #define IMG_API
#endif

struct ScsMsgCounter {
  ScsMessageTag tag;
  int nbMessages;
};

class ScsMsgCounterRWGSlist;

class IMG_API ScsMsgFilter {
public:
  ScsMsgFilter(int nbMaxMessages);
  ~ScsMsgFilter();

  int addMessage(const ScsMessageTag &tag);
  int addMessageNoOrderControl(const ScsMessageTag &tag);
  void signalFirstMessage();
  unsigned char  waitForFirstMessage(const unsigned int & timeout);


private:
  ScsLock _msgCritical;
  ScsCondition _msgReceived;
  ScsLock _messagesLock;
  ScsMsgCounterRWGSlist* _messages;
  ScsMsgCounterRWGSlist* _newestmessages;
  int _nbMaxMessages;
  int _waiting;
};

#endif
