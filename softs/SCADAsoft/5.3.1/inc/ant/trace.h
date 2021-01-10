// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [MODULE]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: trace.h
//  description: 
//     creation: 1997/04/24
//       author: olivier
// --------------------------------------------------------------------------
// $Id: trace.h,v 1.2 1999/02/15 14:41:50 ylo Exp $
//
// $Log: trace.h,v $
// Revision 1.2  1999/02/15 14:41:50  ylo
// *** empty log message ***
//
// Revision 1.1  1998/11/23 14:37:19  scadaref
// Initial revision
//
// Revision 1.16  1997/09/24 15:57:13  olivier
// Avoid warnings in HP-UX.
//
// Revision 1.14  1997/07/09 15:37:05  olivier
// *** empty log message ***
//
// Revision 1.13  1997/07/09 12:12:20  olivier
// *** empty log message ***
//
// Revision 1.12  1997/07/02 15:11:54  olivier
// .
//
// Revision 1.11  1997/07/02 12:13:25  olivier
// *** empty log message ***
//
// Revision 1.10  1997/07/01 16:39:59  olivier
// Remove all references to Views.
//
// Revision 1.9  1997/06/11 14:30:42  olivier
// *** empty log message ***
//
// Revision 1.8  1997/06/10 10:07:24  olivier
// clean compilation warning on NT.
//
// Revision 1.7  1997/05/29 15:36:36  olivier
// *** empty log message ***
//
// Revision 1.6  1997/05/27 10:24:16  olivier
// *** empty log message ***
//
// Revision 1.5  1997/05/27 08:02:12  olivier
// *** empty log message ***
//
// Revision 1.4  1997/05/14 16:08:34  olivier
// *** empty log message ***
//
// Revision 1.3  1997/05/13 17:36:27  olivier
// *** empty log message ***
//
// Revision 1.2  1997/04/25 17:36:35  olivier
// *** empty log message ***
//
// Revision 1.1  1997/04/25 14:32:59  olivier
// Initial revision
//
// --------------------------------------------------------------------------
#ifndef _AN_TTRACE_H
#define _AN_TTRACE_H

#define AntTrace ScsAntTrace
#define AntLogError ScsAntLogError
#define AntDefaultOutputFunction ScsAntDefaultOutputFunction
#define AntDefaultTraceFunction ScsAntDefaultTraceFunction
#define AntAddErrorFormat ScsAntAddErrorFormat
// System headers
#include <stdio.h>
#include <stdarg.h>

#include <stdio.h>
#include <string.h> 

#ifdef OSF1
int vsnprintf(char *str, size_t n, const char *fmt, va_list ap);
int snprintf(char *string, size_t size, const char *format, ...);
#endif

#ifdef WIN32
#define vsnprintf _vsnprintf
#define snprintf  _snprintf
#endif

// Tools.h++ headers
class RWHashDictionary;
class RWHashTable;
class RWCString;

// Ilog Views headers

// Local headers
#include <ant/defs.h>
#include "ant/status.h"
#include "ant/path.h"

class ScsThread;

#define ANT_FATAL       AntFatal,   __LINE__, __FILE__
#define ANT_WARNING     AntWarning, __LINE__, __FILE__
#define ANT_INFO        AntInfo,    __LINE__, __FILE__
#define ANT_LEVEL(_i_)  (_i_),  __LINE__, __FILE__

typedef enum
{ 
    AntInfo, AntWarning, AntFatal 
} AntErrorSeverity;
typedef enum
{ 
    AntDetection, AntPropagation
} AntErrorContext;
// For compatibility
#define AnTDetection AntDetection
#define AnTPropagation AntPropagation

typedef AntStatus (*AntOutputFunction)(short            level,
                                       AntErrorSeverity severity, 
				       short            line,
                                       const char*      file,
				       const char*      source,
				       const char*      message,
                                       const char*      module);

typedef void (*AntTraceFunction)(short            level,
                                 short            line,
                                 const char*      file,
                                 const char*      message);

static const int AntMessageMaxSize = 1024;
typedef char AntMessageBody[AntMessageMaxSize];

extern SCSERROR_API AntStatus AntLogError(AntErrorSeverity severity, 
                      short line, const char* file,
                      const char* errorName,
                      const char* source,
                      const char* module,
                      const char* format, ...);

inline void AntPrintTrace(short level, 
                          short line, const char* file,
                          const char* format, ...);

inline void    AntTraceSetOutputFunction(const AntOutputFunction& fn);
inline void    AntTraceSetTraceFunction(const AntTraceFunction& fn);
inline void    AntTraceAppendToPath(const char* dir);
inline void    AntTracePrependToPath(const char* dir);
inline void    AntTraceSetPath(const char* dir);
inline void    AntTraceSetTraceLevel(short level);
inline short   AntTraceGetTraceLevel();
inline const char* AntTraceGetPath();
inline void    AntTraceSetLanguage(const char* lang);



extern SCSERROR_API int AntParseErrorFile(const char* filename);
extern SCSERROR_API void AntAddErrorFormat(const char* componentLabel,
                                  const char* errorName,
                                  const char* language,
                                  const char* errorFormat);

// --------------------------------------------------------------------------
//        class: AntTrace
//   superClass: 
//
//  description: Static class managing error and trace
// --------------------------------------------------------------------------
//     creation: 1997/04/24
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
class SCSERROR_API AntTrace
{
public:
    // Minor error status used by the class
    enum
    {
        MessageTooLong,
        UnknownMessageFormat,
        BadMessageFileLocation
    };
    friend void AntPrintTrace(short level, 
                              short line, const char* file,
                              const char* format, ...);
    friend SCSERROR_API AntStatus AntLogError(AntErrorSeverity severity, 
                                 short line, const char* file,
                                 const char* errorName,
                                 const char* source,
                                 const char* module,
                                 const char* format, ...);

  static AntTrace& trace();
  static void Finalize();
  
    void                 setOutputFunction(const AntOutputFunction& fn);
    void                 setTraceFunction(const AntTraceFunction& fn);
    short                getTraceLevel();
    void                 setTraceLevel(short level);
    void                 incrementErrorLevel();
    void                 initializeErrorLevel();
    AntStatus            parseErrorFile(const char* fileBaseName);
    void                 checkErrorFile(const char* fileBaseName);
    void                 addErrorFormat(const char* componentLabel,
                                         const char* errorName,
                                         const char* language,
                                         const char* errorFormat);
    const char*          getErrorFormat(const char* fileName,
                                         const char* componentLabel,
                                         const char* errorName);
    void                 setLanguage(const char* language);
    const char*          getPath();
    void                 setPath(const char* path);
    void                 appendToPath(const char* path);
    void                 prependToPath(const char* path);
                         ~AntTrace();
    void                 resetErrorFileCache();
private:

  /**
   * The unique class instance. Notice that we 
   */
  static AntTrace*  _THE_INSTANCE;
  
                         AntTrace();
    short                _errorLevel;
    AntOutputFunction    _outputFunction;
    AntTraceFunction     _traceFunction;
    RWHashDictionary*    _errorTable;
    RWHashTable*         _errorFileNameTable;
    RWCString*           _language;
    AntPath              _path;
    short                _traceLevel;
};

// --------------------------------------------------------------------------
//     function: AntPrintTrace
//
//  description: Call the trace output function with the formatted message
//               string 
// --------------------------------------------------------------------------
//     creation: 1997/04/25
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
#ifdef _ANTRACE_
inline void AntPrintTrace(short level, 
                          short line, const char* file,
                          const char* format, ...)

#else
inline void AntPrintTrace(short , 
                          short , const char* ,
                          const char* , ...)
#endif
{
#ifdef _ANTRACE_
    if (level >= AntTrace::trace()._traceLevel)
    {
        va_list args;
        AntMessageBody  message;
        message[0] = '\0';
        va_start(args, format);
        vsnprintf(message, AntMessageMaxSize-1 , format, args);
        (AntTrace::trace()._traceFunction)(level, line, file, message);
        va_end(args);
        return;
    }
#endif
}

inline void
AntTraceSetOutputFunction(const AntOutputFunction& fn)
{
    AntTrace::trace().setOutputFunction(fn);
}

inline void
AntTraceSetTraceFunction(const AntTraceFunction& fn)
{
    AntTrace::trace().setTraceFunction(fn);
}

inline void
AntTraceSetPath(const char* dir)
{
    AntTrace::trace().setPath(dir);
}

inline void
AntTraceAppendToPath(const char* dir)
{
    AntTrace::trace().appendToPath(dir);
}

inline void
AntTracePrependToPath(const char* dir)
{
    AntTrace::trace().prependToPath(dir);
}

inline const char*
AntTraceGetPath()
{
    return AntTrace::trace().getPath();
}

inline void
AntTraceSetLanguage(const char* lang)
{
    AntTrace::trace().setLanguage(lang);
}

inline void
AntTraceSetTraceLevel(short level)
{
    AntTrace::trace().setTraceLevel(level);
}

inline short
AntTraceGetTraceLevel()
{
    return AntTrace::trace().getTraceLevel();
}

#endif

