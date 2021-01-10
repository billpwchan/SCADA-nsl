// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [TOOLS]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: tdefs.h
//  description: declaration of AntSkipWhites class
//     creation: 1997/04/24
//       author: dom
// --------------------------------------------------------------------------
// $Id: 
//
// $Log: 
//
// --------------------------------------------------------------------------
#ifndef _AN_TSKIPWHITE_H_
#define _AN_TSKIPWHITE_H_

// --------------------------------------------------------------------------
//        class: AntSkipWhites
//   superClass: -
//
//  description: in order to skip spaces and tabulations in input streams
// --------------------------------------------------------------------------
//     creation: 1997/04/28
//       author: dom
// modification: 
// --------------------------------------------------------------------------
// Local headers
#include "ant/defs.h"

// System headers
#ifdef AN_STD
#   include <iostream>
#else
#   include <iostream.h>
#endif

#define AntSkipWhites ScsAntSkipWhites
class SCSERROR_API AntSkipWhites
{
public:
    AntSkipWhites() {}
    friend AN_SL_STD(istream)& operator>>(AN_SL_STD(istream)& is, AntSkipWhites&);
};

#endif /* ! _AN_TSKIPWHITE_H_ */
