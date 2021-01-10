// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [MODULE]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: antdefs.h
//  description: 
//     creation: 1998/01/22
//       author: jpm : extraction de an/defs.h
// --------------------------------------------------------------------------
// $Id: defs.h,v 1.4 1999/11/23 19:11:00 scadaref Exp $
//
//
// --------------------------------------------------------------------------

#ifndef _ANT_DEFS_H_
#define _ANT_DEFS_H_

/*
 * The following two macros are used to help resolve ambiguities between
 * standard library namespace names and other names 
 */
#ifdef AN_STD
#   ifndef ILVSTD
#       define ILVSTD
#   endif
#endif

#if defined(AN_STD)
#    define AN_SL_STD(AN_NAME)          std::AN_NAME
#    define AN_SL_STD_USING             using namespace std;
#else
#ifdef __SCSLINUX__
#    define AN_SL_STD(AN_NAME)          std::AN_NAME
#    define AN_SL_STD_USING             using namespace std;
#else
#    define AN_SL_STD(AN_NAME)          AN_NAME
#    define AN_SL_STD_USING
#endif
#endif

#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef SCSERROR_EXPORTS
            #define SCSERROR_API __declspec(dllexport)
        #else
            #define SCSERROR_API __declspec(dllimport)
        #endif
    #else
        #define SCSERROR_API
    #endif
#else
    #define SCSERROR_API
#endif

#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef ANT_EXPORTS
            #define ANT_API __declspec(dllexport)
        #else
            #define ANT_API __declspec(dllimport)
        #endif
        
        #ifdef ANG_EXPORTS
            #define ANG_API __declspec(dllexport)
        #else
            #define ANG_API __declspec(dllimport)
        #endif
        
        #ifdef AST_EXPORTS
            #define AST_API __declspec(dllexport)
        #else
            #define AST_API __declspec(dllimport)
        #endif
    #else
        #define ANT_API
        #define ANG_API
        #define AST_API
    #endif
#else
    #define ANT_API
    #define ANG_API
    #define AST_API
#endif
    
#ifdef _MSC_VER
    extern "C" int IlvMain(int argc, char* argv[]);
#endif /* !_MSC_VER */

#include <stdio.h>
#if defined(__alpha) && !defined(WIN32) || (defined(HPUX) && defined(__LP64__))
typedef int AntInt;
typedef long AntLong;
typedef unsigned int AntUInt;
typedef unsigned long AntULong;
#else  /* !__alpha || WIN32 */
typedef long AntInt;
typedef long AntLong;
typedef unsigned long AntUInt;
typedef unsigned long AntULong;
#endif /* !__alpha || WIN32 */

typedef void* AntAny;
typedef short AntShort;
typedef unsigned short AntUShort;
typedef unsigned char AntUChar;

extern SCSERROR_API const AntAny AntNil;

typedef bool AntBoolean;

extern SCSERROR_API const AntBoolean AntFalse;
extern SCSERROR_API const AntBoolean AntTrue;

typedef float AntFloat;
typedef double AntDouble;

typedef size_t AntId;
extern SCSERROR_API const AntId AntInvalidId;

#define AntMin(x, y) ((x) >= (y) ? (y) : (x))
#define AntMax(x, y) ((x) >= (y) ? (x) : (y))

#endif
