// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [MODULE]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: format.h
//  description: Declaration of the AntFormat class
//     creation: 1997/06/12
//       author: olivier
// --------------------------------------------------------------------------
// $Id: format.h,v 1.3 1999/11/30 17:17:14 scadaref Exp $
//
// $Log: format.h,v $
// Revision 1.3  1999/11/30 17:17:14  scadaref
// Port on MSVC6
//
// Revision 1.2  1999/02/15 14:42:17  ylo
// *** empty log message ***
//
// Revision 1.1  1998/11/23 14:37:19  scadaref
// Initial revision
//
// Revision 1.2  1997/06/13 15:08:41  olivier
// .
//
// Revision 1.1  1997/06/12 17:25:39  olivier
// Initial revision
//
// --------------------------------------------------------------------------
#ifndef _AN_TFORMAT_H
#define _AN_TFORMAT_H
// System headers
#include <stdio.h>
#include <float.h>
#ifdef AN_STD
#include <iostream>
#include <iomanip>
#else
#include <iostream.h>
#include <iomanip.h>
#endif
// Local headers
#include "ant/defs.h"
#include "ant/status.h"
#include "ant/trace.h"

class RWCRegexp;
// --------------------------------------------------------------------------
//        class: AntFormat
//   superClass: 
//
//  description:  Manage formatted output for active number
// --------------------------------------------------------------------------
//     creation: 1997/06/12
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
/**
  \#include <ant/format.h>.
  The class AntFormat manages the output format of numbers.
  */
#define AntFormat ScsAntFormat

class SCSERROR_API AntFormat
{
public:
    // Minor error status used by the class
    enum
    {
        UncheckedFormat,
        IncoherentFormat
    };
    // Constants definition
    enum {
        SIGN_EXPR,    // Sign sub-expression
        BRADIX_EXPR,  // Before radix int sub-expression
        RADIX_EXPR,   // Radix sub-expression
        ARADIX_EXPR,  // After radix int sub-expression
        POWER_EXPR,   // Power sub-expression
        PSIGN_EXPR,   // Power sign sub-expression
        PVAL_EXPR,    // Power value sub-expression
        EXPR_COUNT    // Number of sub-expressions
    };
    // Types definition
    typedef unsigned char InternalFormat[EXPR_COUNT+1];
    
    // Constructors
    AntFormat()
    { init(); }
    AntFormat(const char* externalFormat)
    { init(); checkExternal(externalFormat); }
    AntFormat(const InternalFormat& internalFormat);
    AntFormat(unsigned sign,
              unsigned beforeRadix,
              unsigned radix      =0,
              unsigned afterRadix =0,
              unsigned power      =0,
              unsigned powerSign  =0,
              unsigned powerValue =0);
    AntFormat(const AntFormat& rf);

    // Destructor
    virtual ~AntFormat()
    { }

    // Public interface
    AntStatus apply(double value, char* buffer) const;
    const char* getExternalFormat() const;
    double getSample() const;
    const InternalFormat& getInternalFormat() const;
    unsigned getExprCharCount() const;

    inline AntStatus& getStatus()
    { return _status; }
    inline void resetStatus()
    { _status.setValid(); }

    inline int isError() const
    { return _status.isError(); }
    inline int isValid() const
    { return _status.isValid(); }

    AntFormat& operator=(const char* externalFormat);

    friend AN_SL_STD(ostream)& operator<<(AN_SL_STD(ostream)&, const AntFormat&);

protected:
    void        init();
    static void initFmtExpr();

    int   checkExternal(const char* externalFormat);
    int   checkInternal();


private:
    static int              _isInitialized;
    static const RWCRegexp* _fmtExpr[EXPR_COUNT];
    InternalFormat          _internalFormat;
    AntStatus               _status;
};

// --------------------------------------------------------------------------
//        class: getExprCharCount
//       method: AntFormat
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/06/12
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline unsigned
AntFormat::getExprCharCount() const
{
    return (unsigned)_internalFormat[EXPR_COUNT];
}
// --------------------------------------------------------------------------
//        class: getInternalFormat
//       method: AntFormat
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/06/12
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline const AntFormat::InternalFormat&
AntFormat::getInternalFormat() const
{
    return _internalFormat;
}
#endif
