/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*  FILE            : bs_automaton.h                                       */
/*  FULL NAME       :                                                      */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K. L.                                            */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 17 06 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*.........................................................................*/
/*  COMMENT                                                                */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*.........................................................................*/
/*  HISTORY                                                                */
/*                                                                         */
/*.........................................................................*/

#ifndef _BS_AUTOMATON_H
#define _BS_AUTOMATON_H

// DEFINITION BS_API
#ifdef WIN32

#ifdef DLLWIN32

#ifdef DLL_BS_AUTOMATON_EXPORTS
#define BS_API __declspec(dllexport)
#else
#define BS_API __declspec(dllimport)
#endif

#else
#define BS_API
#endif

#else
#define BS_API
#endif

class ScsAutomatonFactory;

extern "C" {
    extern int BS_API Init_BS_AUTOMATON_Library(ScsAutomatonFactory* inpFactory);
}

#endif // _BS_AUTOMATON_H

// end of file bs_automaton.h
