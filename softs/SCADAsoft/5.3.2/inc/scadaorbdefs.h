//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scadaorbdefs.h                                         */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon May 05 16:37:15 2003                               */
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
// $Id: $
//
// HISTORY:
// $Log: $


#ifndef SCADA_ORB_DEFS_H
#define SCADA_ORB_DEFS_H

#ifndef TRUE 
#define TRUE 1 
#endif 

#ifndef FALSE
#define FALSE 0 
#endif 

#ifdef _SUNOS
#include <iostream>
#include <stdexcept>
#endif

#if defined(_SCS_ORBACUS_)
#ifndef _SCS_NO_INCLUDE_
#include <OB/CORBA.h>
#include <OB/Reactor.h>
#include <OB/Codec.h>
#include <OB/CosNaming.h>
#include <OB/Properties.h>
#include <OB/Logger.h>
#include <OB/OBPolicies.h>
#include <OB/Messaging.h>
#include <OB/IIOP.h>
#endif 

#define ORB_HOME                "ORBACUSHOME"
#define ORB_CONFIG              "ORBACUS_CONFIG"
#define ORB_EXE_PATH_VALUE      "bin"
#define ORB_EXE                 "nameserv"
#define ORB_SIL_OPTION          ""
#define ORB_EXE_OPTION          ""
#define ORB_SPV_OPTION          "-s -d" 

#elif defined(_SCS_TAO_)
#ifndef _SCS_NO_INCLUDE_
//
// TAO INCLUDES
// 
#include <tao/DynamicInterface/Request.h>       // Because of DII in proxies
#include <tao/AnyTypeCode/NVList.h>             // Because of proxies
#include <tao/corba.h>
#include <tao/ORB.h>
#include <tao/PortableServer/PortableServer.h>
#include <tao/AnyTypeCode/TypeCode_Constants.h> // Because of DII in proxies
#include <tao/DynamicInterface/Context.h>       // Because of DII in proxies

#include <orbsvcs/CosNamingC.h>   
#endif 

#ifdef SCS_STD
#include <string>
#else
#include <string.h>
#endif

#include <scsdefs.h>

#define ORB_HOME                "TAO_ROOT"
#define ORB_CONFIG              "SCSCONFIG"
#define ORB_EXE_PATH_VALUE      "orbsvcs/Naming_Service"
#define ORB_EXE                 "Naming_Service"
#define ORB_SIL_OPTION          ""
#define ORB_EXE_OPTION          ""
#define ORB_SPV_OPTION          "-m 0 -f"

const SCS_SL_STD(string) _TAO_CFG_ARG_DIRECTIVE="-ORBSvcConfDirective";

#endif

#define _POA_IMPL_
#define OBJECT_PTR(x) x->_this()
/* Name of base context for all Scadasoft process */
#define BASE_CONTEXT_NAME    "Scadasoft"   

#ifdef WIN32
    #ifdef SCS_DLL
        #ifdef SCSORB_EXPORTS
        #define SCSORB_API __declspec(dllexport)
        #else
        #define SCSORB_API __declspec(dllimport)
        #endif
    #else
        #define SCSORB_API
    #endif
#else
    #define SCSORB_API
#endif

#endif
