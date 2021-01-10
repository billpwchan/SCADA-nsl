// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDef.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
/// \file SCSDef.h
/// \brief Scadasoft client precompilation definitions.
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDEF_H
#define SCSCLIENT_SCSDEF_H
// ----------------------------------------------------------------------------
#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef SCSCLIENT_EXPORTS
        #define SCSCLIENT_API __declspec(dllexport)
        #else
        #define SCSCLIENT_API __declspec(dllimport)
        #endif
    #else
        #define SCSCLIENT_API
    #endif
#else
    #define SCSCLIENT_API
#endif
#include <scsversion.h>
// ----------------------------------------------------------------------------
// Definition for trace function
#include <scstrace.h>
#include <ant/trace.h>
#define SCSAPI_SCSMODULE 25
#define SCSAPITrace	ScsTraceFunction(SCSAPI_SCSMODULE)
#define SCSAPITraceLevel(level, message)  BaseTraceLevel(SCSAPI_SCSMODULE, level, message)
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDEF_H
