// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [MODULE]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: pquark.h
//  description: 
//     creation: 1997/05/16
//       author: dom
// --------------------------------------------------------------------------
#ifndef __ANTP_QUARK_H__
#define __ANTP_QUARK_H__

#include <rw/rwset.h>

#include "ant/quark.h"

// --------------------------------------------------------------------------
//        class: AntPQuark
//   superClass: RWCollectable
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/05/16
//       author: dom
// modification: 
// --------------------------------------------------------------------------
class SCSERROR_API AntPQuark : public RWCollectable
{
    friend class AntPQuarkFactory;

public:
    AntPQuark(const char* name);

    const AntQuark* quark() const;

    unsigned hash() const;
    RWBoolean isEqual(const RWCollectable*) const;

protected:
    AntQuark _quark;
};

inline const AntQuark*
AntPQuark::quark() const
{
    return &_quark;
}

// --------------------------------------------------------------------------
//        class: AntPQuarkFactory
//   superClass: -
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/05/16
//       author: dom
// modification: 
// --------------------------------------------------------------------------
#ifdef AN_STD
#   include <iostream>
#else
#   include <iostream.h>
#endif

class AntPQuarkFactory
{
public:
    ~AntPQuarkFactory();

    const AntQuark* getQuark(const char* name, AntBoolean createIt = AntTrue);

    static AntPQuarkFactory* theFactory(AntBoolean destroy = AntFalse);

    friend AN_SL_STD(ostream)& operator<<(AN_SL_STD(ostream)&, AntPQuarkFactory&);

private:
    AntPQuarkFactory();
    AntPQuarkFactory(const AntPQuarkFactory&);

    RWSet _quarks;
};

#endif /* ! __ANK_QUARK_H__ */
