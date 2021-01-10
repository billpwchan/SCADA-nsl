// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [TOOLS]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: interval.h
//  description: declaration of AntInterval classe
//     creation: 1997/04/28
//       author: dom
// --------------------------------------------------------------------------
// $Id: interval.h,v 1.3 1999/11/30 18:36:04 scadaref Exp $Log: 
//
// --------------------------------------------------------------------------

#ifndef _AN_TINTERV_H_
#define _AN_TINTERV_H_

#include "ant/defs.h"

// System headers
#ifdef ILVSTD
#   include <iostream>
#   include <limits>
#   include <float.h>
#else
#   include <iostream.h>
#   include <float.h>
#endif

class RWCString;

// --------------------------------------------------------------------------
//        class: AntInterval
//   superClass: -
//
//  description: describe real interval
// --------------------------------------------------------------------------
//     creation: 1997/04/28
//       author: dom
// modification: 
// --------------------------------------------------------------------------
/**
  \#include <ant/interval.h>.
  The class AntInterval manages intervals of double precision floating-point values.
  */
#define AntInterval ScsAntInterval
class SCSERROR_API AntInterval
{
public:
    enum Brace
    {
        NoBoundaryBrace,
        OpenedBrace,
        ClosedBrace
    };

    AntInterval();
    AntInterval(Brace leftBrace, double leftValue,
                double rightValue, Brace rightBrace);
    AntInterval(const AntInterval& i);
    AntInterval(AN_SL_STD(istream)& is);
    AntInterval(const char* s);
    AntInterval(const RWCString& s);
    virtual ~AntInterval();

    // virtual constructor
    virtual AntInterval* clone() const;

    // accessors
    int    isBad() const;
    Brace  getLeftBrace()  const;
    double getLeftValue()  const;
    double getRightValue() const;
    Brace  getRightBrace() const;
    void   setLeftBrace(const Brace leftBrace);
    void   setLeftValue(const double leftValue);
    void   setRightValue(const double rightValue);
    void   setRightBrace(const Brace rightBrace);
    void   setLeftBoundary(const Brace leftBrace, const double leftValue);
    void   setRightBoundary(const double rightValue, const Brace rightBrace);

    // intersection predicates
    int isInside(const double value) const;

    int isInside(const Brace, const double) const;
    int isInside(const double, const Brace) const;
    int isEqual(const Brace, const double) const;
    int isEqual(const double, const Brace) const;

    int leftIntersects(const AntInterval& i) const;
    int leftIntersects(const AntInterval* i) const;
    int rightIntersects(const AntInterval& i) const;
    int rightIntersects(const AntInterval* i) const;
    int isIncluded(const AntInterval& i) const;
    int sameLeftBoundary(const AntInterval& i) const;
    int sameLeftBoundary(const AntInterval* i) const;
    int sameRightBoundary(const AntInterval& i) const;
    int sameRightBoundary(const AntInterval* i) const;

    // intersections methods
    AntInterval* splitLeft(const Brace leftBrace,
                           const double leftValue);
    AntInterval* splitLeft(const AntInterval& i);
    AntInterval* splitLeft(const AntInterval* i);
    AntInterval* splitRight(const double rightValue,
                            const Brace rightBrace);
    AntInterval* splitRight(const AntInterval& i);
    AntInterval* splitRight(const AntInterval* i);

    // input/output methods
    virtual AN_SL_STD(ostream)& output(AN_SL_STD(ostream)&) const;
    virtual AN_SL_STD(istream)& input(AN_SL_STD(istream)&);

    friend AN_SL_STD(ostream)& operator<<(AN_SL_STD(ostream)&, const AntInterval&);
    friend AN_SL_STD(ostream)& operator<<(AN_SL_STD(ostream)&, const AntInterval*);
    friend AN_SL_STD(istream)& operator>>(AN_SL_STD(istream)&, AntInterval&);
    friend AN_SL_STD(istream)& operator>>(AN_SL_STD(istream)&, AntInterval*);

    // token char accessors
    const char& getLeftOpenedBraceToken() const;
    const char& getLeftClosedBraceToken() const;
    const char& getBoundarySeparatorToken() const;
    const char& getRightOpenedBraceToken() const;
    const char& getRightClosedBraceToken() const;
    const char& getInfiniteBoundaryToken() const;
    static void setLeftOpenedBraceToken(const char& token);
    static void setLeftClosedBraceToken(const char& token);
    static void setBoundarySeparatorToken(const char& token);
    static void setRightOpenedBraceToken(const char& token);
    static void setRightClosedBraceToken(const char& token);
    static void setInfiniteBoundaryToken(const char& token);

private:
    int _isBad;

    Brace  _leftBrace;
    double _leftValue;
    double _rightValue;
    Brace  _rightBrace;

    static char _leftOpenedBraceToken;
    static char _leftClosedBraceToken;
    static char _boundarySeparatorToken;
    static char _rightOpenedBraceToken;
    static char _rightClosedBraceToken;
    static char _infiniteBoundaryToken;

    void readInterval(AN_SL_STD(istream)& is,
                      int& isBad,
                      Brace& leftBrace,
                      double& leftValue,
                      double& rightValue,
                      Brace& rightBrace);
};

// --------------------------------------------------------------------------
//        class: AntInterval
//       method: AntInterval
//
//  description: constructors and destructor
// --------------------------------------------------------------------------
//     creation: 1997/04/28
//       author: dom
// modification: 
// --------------------------------------------------------------------------
inline
AntInterval::AntInterval()
    : _isBad(0),
      _leftBrace(NoBoundaryBrace),
      _leftValue(-DBL_MAX),
      _rightValue(+DBL_MAX),
      _rightBrace(NoBoundaryBrace)
{ }
inline
AntInterval::AntInterval(Brace leftBrace, double leftValue,
            double rightValue, Brace rightBrace)
    : _isBad(0),
      _leftBrace(leftBrace),
      _leftValue(leftValue),
      _rightValue(rightValue),
      _rightBrace(rightBrace)
{ }
inline
AntInterval::AntInterval(const AntInterval& i)
    : _isBad(i._isBad),
      _leftBrace(i._leftBrace),
      _leftValue(i._leftValue),
      _rightValue(i._rightValue),
      _rightBrace(i._rightBrace)
{ }
inline
AntInterval::~AntInterval()
{ }

// --------------------------------------------------------------------------
//        class: AntInterval
//       method: clone
//
//  description: virtual constructor
// --------------------------------------------------------------------------
//     creation: 1997/04/28
//       author: dom
// modification: 
// --------------------------------------------------------------------------
inline AntInterval*
AntInterval::clone() const
{
    return new AntInterval(*this);
}

// --------------------------------------------------------------------------
//        class: AntInterval
//       method: get.../set...
//
//  description: accessors
// --------------------------------------------------------------------------
//     creation: 1997/04/28
//       author: dom
// modification: 
// --------------------------------------------------------------------------
inline int
AntInterval::isBad() const
{
    return _isBad;
}
inline AntInterval::Brace
AntInterval::getLeftBrace() const
{
    return _leftBrace;
}
inline double
AntInterval::getLeftValue() const
{
    return _leftValue;
}
inline double
AntInterval::getRightValue() const
{
    return _rightValue;
}
inline AntInterval::Brace
AntInterval::getRightBrace() const
{
    return _rightBrace;
}
inline void
AntInterval::setLeftBrace(const Brace leftBrace)
{
    _leftBrace = leftBrace;
}
inline void
AntInterval::setLeftValue(const double leftValue)
{
    _leftValue = leftValue;
}
inline void
AntInterval::setRightValue(const double rightValue)
{
    _rightValue = rightValue;
}
inline void
AntInterval::setRightBrace(const Brace rightBrace)
{
    _rightBrace = rightBrace;
}
inline void
AntInterval::setLeftBoundary(const Brace leftBrace,
                             const double leftValue)
{
    _leftBrace = leftBrace;
    _leftValue = leftValue;
}
inline void
AntInterval::setRightBoundary(const double rightValue,
                              const Brace rightBrace)
{
    _rightValue = rightValue;
    _rightBrace = rightBrace;
}
inline const char&
AntInterval::getLeftOpenedBraceToken() const
{
    return _leftOpenedBraceToken;
}
inline const char&
AntInterval::getLeftClosedBraceToken() const
{
    return _leftClosedBraceToken;
}
inline const char&
AntInterval::getBoundarySeparatorToken() const
{
    return _boundarySeparatorToken;
}
inline const char&
AntInterval::getRightOpenedBraceToken() const
{
    return _rightOpenedBraceToken;
}
inline const char&
AntInterval::getRightClosedBraceToken() const
{
    return _rightClosedBraceToken;
}
inline const char&
AntInterval::getInfiniteBoundaryToken() const
{
    return _infiniteBoundaryToken;
}

// --------------------------------------------------------------------------
//        class: AntInterval
//       method: ...Intersects/isIncluded/same...Boundary/
//
//  description: intersection predicates
// --------------------------------------------------------------------------
//     creation: 1997/04/28
//       author: dom
// modification: 
// --------------------------------------------------------------------------
inline int
AntInterval::leftIntersects(const AntInterval& i) const
{
    return isInside(i._leftBrace, i._leftValue);
}
inline int
AntInterval::leftIntersects(const AntInterval* i) const
{
    return isInside(i->_leftBrace, i->_leftValue);
}
inline int
AntInterval::rightIntersects(const AntInterval& i) const
{
    return isInside(i._rightValue, i._rightBrace);
}
inline int
AntInterval::rightIntersects(const AntInterval* i) const
{
    return isInside(i->_rightValue, i->_rightBrace);
}
inline int
AntInterval::isIncluded(const AntInterval& i) const
{
    return (leftIntersects(i) && rightIntersects(i));
}
inline int
AntInterval::sameLeftBoundary(const AntInterval& i) const
{
    return isEqual(i._leftBrace, i._leftValue);
}
inline int
AntInterval::sameLeftBoundary(const AntInterval* i) const
{
    return isEqual(i->_leftBrace, i->_leftValue);
}
inline int
AntInterval::sameRightBoundary(const AntInterval& i) const
{
    return isEqual(i._rightValue, i._rightBrace);
}
inline int
AntInterval::sameRightBoundary(const AntInterval* i) const
{
    return isEqual(i->_rightValue, i->_rightBrace);
}

// --------------------------------------------------------------------------
//        class: AntInterval
//       method: split...
//
//  description: intersection methods
// --------------------------------------------------------------------------
//     creation: 1997/04/28
//       author: dom
// modification: 
// --------------------------------------------------------------------------
inline AntInterval*
AntInterval::splitLeft(const AntInterval& i)
{
    return splitLeft(i._leftBrace, i._leftValue);
}
inline AntInterval*
AntInterval::splitLeft(const AntInterval* i)
{
    return splitLeft(i->_leftBrace, i->_leftValue);
}
inline AntInterval*
AntInterval::splitRight(const AntInterval& i)
{
    return splitRight(i._rightValue, i._rightBrace);
}
inline AntInterval*
AntInterval::splitRight(const AntInterval* i)
{
    return splitRight(i->_rightValue, i->_rightBrace);
}


#endif
