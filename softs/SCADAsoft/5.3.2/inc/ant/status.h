// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [TOOLS]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: status.h
//  description: declaration of the AntStatus class
//     creation: 1997/04/23
//       author: olivier
// --------------------------------------------------------------------------
// $Id: status.h,v 1.2 1999/02/15 14:43:38 ylo Exp $
//
// $Log: status.h,v $
// Revision 1.2  1999/02/15 14:43:38  ylo
// *** empty log message ***
//
// Revision 1.1  1998/11/23 14:37:19  scadaref
// Initial revision
//
// Revision 1.2  1997/08/19 14:53:09  olivier
// *** empty log message ***
//
// --------------------------------------------------------------------------
#ifndef _AN_STATUS_H
#define _AN_STATUS_H


// --------------------------------------------------------------------------
//        class: AntStatus
//   superClass: 
//
//  description: Manage the error log mecanism
// --------------------------------------------------------------------------
//     creation: 1997/04/23
//       author: olivier
// modification:
// --------------------------------------------------------------------------
/**
  \#include <ant/status.h>.
  The class AntStatus is used as a generic manner of handling status return values.
  */
  
#include "ant/defs.h"

#define AntError ScsAntError
#define AntValid ScsAntValid

class AntStatus
{
public:

    enum AntMajor
    {
        AntValid,
        AntError
    };

    AntStatus();
    AntStatus(AntMajor major, int minor =0);
    
    AntStatus& set(AntMajor major, int minor =0);
    AntStatus& setError(int minor =0);
    AntStatus& setValid();
    
    AntMajor getMajor() const;
    int getMinor() const;
    
    int isError() const;
    int isValid() const;

    AntStatus& operator=(const AntStatus& stat);
    friend int operator==(const AntStatus& stat1, const AntStatus& stat2); 
    friend int operator!=(const AntStatus& stat1, const AntStatus& stat2); 

private:
    AntMajor    _major;
    int        _minor;
};

// --------------------------------------------------------------------------
//        class: AntStatus
//       method: 
//
//  description: Inline methods
// --------------------------------------------------------------------------
//     creation: 1997/07/07
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline
AntStatus::AntStatus()
    : _major(AntValid), _minor(0)
{}

inline
AntStatus::AntStatus(AntMajor major, int minor)
    : _major(major), _minor(minor)
{}

inline AntStatus&
AntStatus::set(AntStatus::AntMajor major, int minor)
{ _major=major; _minor=minor; return *this; }

inline AntStatus&
AntStatus::setError(int minor)
{ _major=AntError; _minor=minor; return *this; }
inline AntStatus&
AntStatus::setValid()
{ _major=AntValid; _minor=0; return *this; }

inline AntStatus::AntMajor
AntStatus::getMajor() const
{ return _major; }
inline int
AntStatus::getMinor() const
{ return _minor; }

inline int
AntStatus::isError() const
{ return _major==AntError; }
inline int
AntStatus::isValid() const
{ return _major==AntValid; }

inline AntStatus&
AntStatus::operator=(const AntStatus& stat)
{
    _major = stat._major;
    _minor = stat._minor;
    return *this;
}
inline int operator==(const AntStatus& stat1, const AntStatus& stat2)
{
    return (stat1._major == stat2._major && stat1._minor == stat2._minor);
}
inline int operator!=(const AntStatus& stat1, const AntStatus& stat2)
{
    return (!operator==(stat1, stat2));
}

// --------------------------------------------------------------------------
//     variable: AntError, AntValid
//
//  description: external declaration of global variables
// --------------------------------------------------------------------------
//     creation: 1997/07/07
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
extern SCSERROR_API const AntStatus AntError;
extern SCSERROR_API const AntStatus AntValid;

#endif

