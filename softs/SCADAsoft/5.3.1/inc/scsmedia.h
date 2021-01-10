//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsmedia.h                                             */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : 24/03/99                                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW         : Header file for the media class                        */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $

#ifndef __SCSMEDIA_H__
#define __SCSMEDIA_H__

/** \file
    \brief Evaluation of TCL expressions
*/

#include "tcl.h"

class ScsScript;
class TclServer;

/**
   \brief This class is used to send a TCL expression to and ScsVisu process and get the evaluation result.

\code#include "scsmedia.h"\endcode
*/
class MED_API ScsMedia
{
public:

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.
     \param pScript  [in]: the <em>ScsScript</em> object that implements the local TCL interpreter. That argument is required only inside an ScsVisu process.
     \par Return values:
     none.
  */
  ScsMedia(ScsScript* pScript = 0);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~ScsMedia();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     returns the object containing the symbolic description of the point attribute.
     \param pServerName  [in]:
     \param pEnv  [in]:
     \param pInstruction  [in]:
     \param pResult  [out]:
     \par Return values:
     the <em>ScsAddress</em> object of the <em>DbmData</em> object.
  */
  int Call(const char* pServerName, const char* pEnv, const char* pInstruction, char*& pResult);
  //@}

protected:
  TclServer* _server;
  Tcl_Interp* _interpret;

  char *_environment;
  char *_serverName;
};

#endif
