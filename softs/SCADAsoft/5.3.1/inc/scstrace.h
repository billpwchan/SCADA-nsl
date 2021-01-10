/******************************************************************************/
/*									      */
/*  FILE		: scstrace.h                                          */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 2000/06/29					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	                                				      */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
#ifndef _SCS_TRACE_H
#define _SCS_TRACE_H

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scsdefs.h"

// Trace handling
// --------------
typedef void (*traceProto)(short level, 
			   short line, const char* file, 
			   const char* format, ...);


extern SCS_API void ScsNullTraceFunction(short level, short line, 
			  const char* file, const char* format, ...); 
 
extern SCS_API traceProto ScsGetTraceFunction(int module);

#ifdef _SCSTRACE_ 
#define ScsTraceFunction(m) ScsGetTraceFunction(m)
#define ScsUserTraceFunction(m) ScsGetTraceFunction(m+32)
#else
#define ScsTraceFunction(m) ScsNullTraceFunction
#define ScsUserTraceFunction(m) ScsNullTraceFunction
#endif

#define ScsTrace	ScsTraceFunction(1)
#define ScsUserTrace	ScsUserTraceFunction(0)
#define SCS_LEVEL(_i_)	ANT_LEVEL(_i_)
#define USER_LEVEL(_i_)	ANT_LEVEL(_i_)



/********************/
/* New Trace system */      
/********************/

typedef void (*TraceHeaderFunction)(SCS_SL_STD(ostream)&  os,
                                    short                 level,
                                    short                 line,
                                    const char*           file);

class StreamTrace {
 
    public: 
        StreamTrace() :
            _header(NULL), _tail(NULL), _os(&SCS_SL_STD(cout)) {};    
    
        StreamTrace(SCS_SL_STD(ostream)& os) :
            _header(NULL), _tail(NULL), _os(&os) {};
    
        void setOstream(SCS_SL_STD(ostream)& os) { 
            _os = &os; 
        };
    
        SCS_SL_STD(ostream)& getOstream() const {
            return *_os;
        }
        
        void setHeaderFunction(const TraceHeaderFunction& fn) {
            _header = fn;
        }
        
        void setTailFunction(const TraceHeaderFunction& fn) {
            _tail = fn;
        }
        
        void printHeader(short level, short line, const char* file) {
            _header(*_os, level, line, file);
        }
        
        void printTail(short level, short line, const char* file) {
            _tail(*_os, level, line, file);
        }
 
    protected:
        
        TraceHeaderFunction  _header;
        TraceHeaderFunction  _tail;
        SCS_SL_STD(ostream)* _os;
        
    public:
        static SCS_API StreamTrace inst;
        
};


#ifdef _SCSTRACE_ 
#define BaseTraceLevel(module, level, message) \
    if (Scadasoft::IsModuleEnable(module, level)) { \
        StreamTrace::inst.printHeader(level, __LINE__, __FILE__); \
        StreamTrace::inst.getOstream() << message; \
        StreamTrace::inst.printTail(level, __LINE__, __FILE__); \
    }
#else
#define BaseTraceLevel(module, level, message) {}
#endif   // _SCSTRACE_

#define UserTraceLevel(module, level, message)  BaseTraceLevel(module+32, level, message)
#define ScsTraceLevel(level, message) BaseTraceLevel(SCS_SCSMODULE, level, message)



#endif
