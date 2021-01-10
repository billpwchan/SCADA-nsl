//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsdefs.h                                              */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Tue Nov 23 15:01:46 1999                               */
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
// IDENTIFICATION:
// $Id: scsdefs.h,v 1.2 2000/02/28 14:16:45 jpu Exp $
//
// HISTORY:
// $Log: scsdefs.h,v $
// Revision 1.2  2000/02/28 14:16:45  jpu
// Add ScsTraceModules enum
//
// Revision 1.1  1999/11/24 09:53:06  scadaref
// Initial revision
//
/******************************************************************************/
#ifndef _SCS_SCSDEFS_H_
#define _SCS_SCSDEFS_H_

/** \file
    \brief Definition of priority levels.
*/

#ifdef WIN32
#pragma warning (disable : 4786) //  identifier was truncated to '255' characters in the debug information
#pragma warning (disable : 4251)
#pragma warning (disable : 4273)
#pragma warning (disable : 4275) // non dll-interface class used as base for dll-interface class
#endif

#ifdef SCS_STD
#   ifndef AN_STD
#       define AN_STD
#   endif
#endif

#if defined(SCS_STD)
#    define SCS_SL_STD(SCS_NAME)          std::SCS_NAME
#    define SCS_SL_STD_USING              using namespace std;
#else
#    define SCS_SL_STD(SCS_NAME)          SCS_NAME
#    define SCS_SL_STD_USING
#endif

#ifdef WIN32
    #ifdef SCS_DLL
        
        #ifdef ALM_EXPORTS
        #define ALM_API __declspec(dllexport)
        #else
        #define ALM_API __declspec(dllimport)
        #endif
        
        #ifdef ALMAUT_EXPORTS
        #define ALMAUT_API __declspec(dllexport)
        #else
        #define ALMAUT_API __declspec(dllimport)
        #endif
        
        #ifdef DLL_STD_AUTOMATON_EXPORTS
        #define ALMSTDAUT_API __declspec(dllexport)
        #else
        #define ALMSTDAUT_API __declspec(dllimport)
        #endif
        
        #ifdef ASC_EXPORTS
        #define ASC_API __declspec(dllexport)
        #else
        #define ASC_API __declspec(dllimport)
        #endif
        
        #ifdef CTL_EXPORTS
        #define CTL_API __declspec(dllexport)
        #else
        #define CTL_API __declspec(dllimport)
        #endif
        
        #ifdef DAC_EXPORTS
        #define DAC_API __declspec(dllexport)
        #else
        #define DAC_API __declspec(dllimport)
        #endif
        
        #ifdef DACCOM_EXPORTS
        #define DACCOM_API __declspec(dllexport)
        #else
        #define DACCOM_API __declspec(dllimport)
        #endif
        
        #ifdef DACSIM_EXPORTS
        #define DACSIM_API __declspec(dllexport)
        #else
        #define DACSIM_API __declspec(dllimport)
        #endif
        
        #ifdef DBK_EXPORTS
        #define DBK_API __declspec(dllexport)
        #else
        #define DBK_API __declspec(dllimport)
        #endif
        
        #ifdef DBKI_EXPORTS
        #define DBKI_API __declspec(dllexport)
        #else
        #define DBKI_API __declspec(dllimport)
        #endif
        
        #ifdef DBM_EXPORTS
        #define DBM_API __declspec(dllexport)
        #else
        #define DBM_API __declspec(dllimport)
        #endif
        
        #ifdef DPCV_EXPORTS
        #define DPCV_API __declspec(dllexport)
        #else
        #define DPCV_API __declspec(dllimport)
        #endif
        
        #ifdef DPCE_EXPORTS
        #define DPCE_API __declspec(dllexport)
        #else
        #define DPCE_API __declspec(dllimport)
        #endif
        
        #ifdef DSS_EXPORTS
        #define DSS_API __declspec(dllexport)
        #else
        #define DSS_API __declspec(dllimport)
        #endif
        
        #ifdef FTS_EXPORTS
        #define FTS_API __declspec(dllexport)
        #else
        #define FTS_API __declspec(dllimport)
        #endif
        
        #ifdef HIS_EXPORTS
        #define HIS_API __declspec(dllexport)
        #else
        #define HIS_API __declspec(dllimport)
        #endif
        
        #ifdef HLT_EXPORTS
        #define HLT_API __declspec(dllexport)
        #else
        #define HLT_API __declspec(dllimport)
        #endif
        
        #ifdef LST_EXPORTS
        #define LST_API __declspec(dllexport)
        #else
        #define LST_API __declspec(dllimport)
        #endif
        
        #ifdef MED_EXPORTS
        #define MED_API __declspec(dllexport)
        #else
        #define MED_API __declspec(dllimport)
        #endif
        
        #ifdef NTP_EXPORTS
        #define NTP_API __declspec(dllexport)
        #else
        #define NTP_API __declspec(dllimport)
        #endif
        
        #ifdef OPM_EXPORTS
        #define OPM_API __declspec(dllexport)
        #else
        #define OPM_API __declspec(dllimport)
        #endif
        
        #ifdef OLS_EXPORTS
        #define OLS_API __declspec(dllexport)
        #else
        #define OLS_API __declspec(dllimport)
        #endif
        
        #ifdef OLSI_EXPORTS
        #define OLSI_API __declspec(dllexport)
        #else
        #define OLSI_API __declspec(dllimport)
        #endif
        
        #ifdef RPL_EXPORTS
        #define RPL_API __declspec(dllexport)
        #else
        #define RPL_API __declspec(dllimport)
        #endif
        
        #ifdef SCS_EXPORTS
        #define SCS_API __declspec(dllexport)
        #else
        #define SCS_API __declspec(dllimport)
        #endif
        
        #ifdef SCSSNMP_EXPORTS
        #define SCSSNMP_API __declspec(dllexport)
        #else
        #define SCSSNMP_API __declspec(dllimport)
        #endif

        #ifdef SCSCOMMON_EXPORTS
        #define SCSCOMMON_API __declspec(dllexport)
        #else
        #define SCSCOMMON_API __declspec(dllimport)
        #endif

        #ifdef SEC_EXPORTS
        #define SEC_API __declspec(dllexport)
        #else
        #define SEC_API __declspec(dllimport)
        #endif
        
        #ifdef SPT_EXPORTS
        #define SPT_API __declspec(dllexport)
        #else
        #define SPT_API __declspec(dllimport)
        #endif
        
        #ifdef TRD_EXPORTS
        #define TRD_API __declspec(dllexport)
        #else
        #define TRD_API __declspec(dllimport)
        #endif
        
        #ifdef TSC_EXPORTS
        #define TSC_API __declspec(dllexport)
        #else
        #define TSC_API __declspec(dllimport)
        #endif
        
        #ifdef VCFGSTUDIO_EXPORTS
        #define VCFGSTUDIO_API __declspec(dllexport)
        #else
        #define VCFGSTUDIO_API __declspec(dllimport)
        #endif
        
        #ifdef VDSSSTUDIO_EXPORTS
        #define VDSSSTUDIO_API __declspec(dllexport)
        #else
        #define VDSSSTUDIO_API __declspec(dllimport)
        #endif
        
        #ifdef VLST_EXPORTS
        #define VLST_API __declspec(dllexport)
        #else
        #define VLST_API __declspec(dllimport)
        #endif
        
        #ifdef VSTUDIO_EXPORTS
        #define VSTUDIO_API __declspec(dllexport)
        #else
        #define VSTUDIO_API __declspec(dllimport)
        #endif
        
        #ifdef VSU_EXPORTS
        #define VSU_API __declspec(dllexport)
        #else
        #define VSU_API __declspec(dllimport)
        #endif
        
        #ifdef VTCL_EXPORTS
        #define VTCL_API __declspec(dllexport)
        #else
        #define VTCL_API __declspec(dllimport)
        #endif
        
        #ifdef VTOOL_EXPORTS
        #define VTOOL_API __declspec(dllexport)
        #else
        #define VTOOL_API __declspec(dllimport)
        #endif
        
        #ifdef VTRD_EXPORTS
        #define VTRD_API __declspec(dllexport)
        #else
        #define VTRD_API __declspec(dllimport)
        #endif
        
        #ifdef VTRDSTUD_EXPORTS
        #define VTRDSTUD_API __declspec(dllexport)
        #else
        #define VTRDSTUD_API __declspec(dllimport)
        #endif
        
    #else
        #define ALM_API
        #define ALMAUT_API
        #define ALMSTDAUT_API
        #define ASC_API
        #define CTL_API 
        #define DAC_API
        #define DACCOM_API
        #define DACSIM_API
        #define DBK_API
        #define DBKI_API
        #define DBM_API
        #define DPCE_API
        #define DPCV_API
        #define DSS_API
        #define FTS_API
        #define HIS_API
        #define HLT_API
        #define LST_API
        #define MED_API
        #define NTP_API
        #define OPM_API
        #define OLS_API
        #define OLSI_API
        #define RPL_API
        #define SCS_API
        #define SCSSNMP_API
        #define SCSCOMMON_API
        #define SEC_API
        #define SPT_API
        #define TRD_API
        #define TSC_API
        #define VCFGSTUDIO_API
        #define VDSSSTUDIO_API
        #define VLST_API
        #define VSTUDIO_API
        #define VSU_API
        #define VTCL_API
        #define VTOOL_API
        #define VTRD_API
        #define VTRDSTUD_API
    #endif
#else
    #define ALM_API
    #define ALMAUT_API
    #define ALMSTDAUT_API
    #define ASC_API
    #define CTL_API 
    #define DAC_API
    #define DACCOM_API
    #define DACSIM_API
    #define DBK_API
    #define DBKI_API
    #define DBM_API
    #define DPCE_API
    #define DPCV_API
    #define DSS_API
    #define FTS_API
    #define HIS_API
    #define HLT_API
    #define LST_API
    #define MED_API
    #define NTP_API
    #define OPM_API
    #define OLS_API
    #define OLSI_API
    #define RPL_API
    #define SCS_API
    #define SCSSNMP_API
    #define SCSCOMMON_API
    #define SEC_API
    #define SPT_API
    #define TRD_API
    #define TSC_API
    #define VCFGSTUDIO_API
    #define VDSSSTUDIO_API
    #define VLST_API
    #define VSTUDIO_API
    #define VSU_API
    #define VTCL_API
    #define VTOOL_API
    #define VTRD_API
    #define VTRDSTUD_API
#endif

// ---------------------------
// Definition of trace modules
// ---------------------------
enum ScsTraceModules {
  SCS_SCSMODULE = 1, // 1
  ASC_SCSMODULE,     // 2
  DBM_SCSMODULE,     // 3
  OLS_SCSMODULE,     // 4
  ALM_SCSMODULE,     // 5
  HIS_SCSMODULE,     // 6
  TRD_SCSMODULE,     // 7
  SEC_SCSMODULE,     // 8
  RED_SCSMODULE,     // 9
  DAC_SCSMODULE,     // 10
  CTL_SCSMODULE,     // 11
  DPC_SCSMODULE,     // 12
  TSC_SCSMODULE,     // 13
  DSS_SCSMODULE,     // 14
  OPM_SCSMODULE,     // 15
  FTS_SCSMODULE,     // 16
  WDG_SCSMODULE,     // 17
  LST_SCSMODULE,     // 18
  RPL_SCSMODULE,     // 19
  VIS_SCSMODULE,     // 20
  NB_TRACE_MODULES 
};

// --------------------------
// Definition of trace levels
// --------------------------
#define LEVEL_0		1
#define LEVEL_1		2
#define LEVEL_2		4
#define LEVEL_3		8
#define LEVEL_4		16
#define LEVEL_5		32
#define LEVEL_6         64
#define LEVEL_7         128
#define LEVEL_8         256
#define LEVEL_9         512
#define LEVEL_10        1024
#define LEVEL_11        2048        
#define LEVEL_12        4096  


// -----------------------------
// Definition of priority levels
// -----------------------------
/**
\code#include "scsdefs.h"\endcode
   \par Description:
     this enum represents the possible priority levels for the messages sent to a server running in a redunded (either local or remote) SCADAsoft environment. The priority is set globally using a parameter of the constructor of the server interface class.
   The possible values are the following :
   \code
   enum ScsPriorityLevels {
     SCS_PRIORITY_NORMAL = 0,
     SCS_PRIORITY_HIGH,
     SCS_PRIORITY_LOW,
     SCS_PRIORITY_URG,
     SCS_PRIORITY_LOWER,
     SCS_PRIORITY_LOWEST
   }; \endcode
   \par Values:
   \li \c SCS_PRIORITY_LOW:  low priority level,
   \li \c SCS_PRIORITY_NORMAL:  default priority level,
   \li \c SCS_PRIORITY_HIGH:  high priority level,
   \li \c SCS_PRIORITY_URG:  most urgent priority level,
   \li \c SCS_PRIORITY_LOWER:  lower priority level,
   \li \c SCS_PRIORITY_LOWEST:  lowest priority level.
*/
enum ScsPriorityLevels {
  SCS_PRIORITY_NORMAL = 0,
  SCS_PRIORITY_HIGH,
  SCS_PRIORITY_LOW,
  SCS_PRIORITY_URG,
  SCS_PRIORITY_LOWER,
  SCS_PRIORITY_LOWEST
};

extern SCS_API const char* SCS_UP;
extern SCS_API const char* SCS_DOWN;
extern SCS_API const char* SCS_UNDEF;
extern SCS_API const char* SCS_DEGRADED;
extern SCS_API const char* SCS_INIT;
extern SCS_API const char* SCS_ONLINENOSTANDBY;
extern SCS_API const char* SCS_ONLINESNAPSHOT;
extern SCS_API const char* SCS_ONLINE;
extern SCS_API const char* SCS_STANDBY;
extern SCS_API const char* SCS_STANDBYSYNC;
extern SCS_API const char* SCS_FAILOVER;
extern SCS_API const char* SCS_ONLINEISOLATED;
extern SCS_API const char* SCS_STANDBYISOLATED;
extern SCS_API const char* SCS_ONLINEINIT;
extern SCS_API const char* SCS_STANDBYINIT;
extern SCS_API const char* SCS_ISOLATED;
extern SCS_API const char* SCS_INPUTMGRISREADY;

#endif
