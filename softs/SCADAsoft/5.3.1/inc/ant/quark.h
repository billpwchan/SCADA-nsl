// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [MODULE]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: AntQuark.h
//  description: 
//     creation: 1997/05/16
//       author: dom
// --------------------------------------------------------------------------
#ifndef __ANT_QUARK_H__
#define __ANT_QUARK_H__
#include "ant/string.h"

// --------------------------------------------------------------------------
//        class: AntQuark
//   superClass: -
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/05/16
//       author: dom
// modification: 
// --------------------------------------------------------------------------

class AntPQuark;

/**
  \#include <ant/quark.h>.
  The class AntQuark manages string constants used to manipulate specific entities.
  Thay are used as a generic manner of handling unique strings within a given application.
  The strings are called quarks, and are managed by the AntQuark class.
  You must use the global function : AntGetQuark to get an existing quark or create a new one.
  @see AntString, AntGetQuark.
  */
class SCSERROR_API AntQuark
{
    friend class AntPQuark;

public:
/**@name General usage member functions*/
//@{
/**
  .
  Returns string associated with the quark. 
  */
    const AntString& name()     const;
/**
  .
  Conversion operator to const AntString&. 
  */
    operator const AntString&() const;
/**
  .
  Conversion operator to const char*. 
  */
    operator const char*()     const;
//@}
    AntPQuark* quark() const;

protected:
    AntQuark(const char* name);

    // forbidden ctors
    AntQuark();
    AntQuark(const AntQuark&) {}

    ~AntQuark() { };

    AntString  _name;
    AntPQuark* _quark;
};

// --------------------------------------------------------------------------
//        class: AntQuark
//       method: ...
//
//  description: all inline methods
// --------------------------------------------------------------------------
//     creation: 1997/07/09
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline
AntQuark::AntQuark(const char* name)
    : _name(name),
      _quark(0)
{ }
inline const AntString&
AntQuark::name() const
{
    return _name;
}
inline
AntQuark::operator const AntString&() const
{
    return _name;
}
inline
AntQuark::operator const char*() const
{
    return _name;
}
inline AntPQuark*
AntQuark::quark() const
{
    return _quark;
}

// --------------------------------------------------------------------------
//     function: ...
//
//  description: exported global functions and constants
// --------------------------------------------------------------------------
//     creation: 1997/07/09
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
extern SCSERROR_API const AntQuark* AntNilQuark;
/**
  .
  Returns the existing quark which name is equal to 'name' or creates a new one
  if the 'createIt' parameter is set to AntTrue.
  */
extern SCSERROR_API const AntQuark* AntGetQuark(const char* name,
                                 AntBoolean createIt = AntTrue);

#endif /* ! __AN_QUARK_H__ */
