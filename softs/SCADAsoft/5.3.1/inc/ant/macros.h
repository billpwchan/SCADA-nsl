// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [MODULE]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: macros.h
//  description: 
//     creation: 1997/05/20
//       author: olivier
// --------------------------------------------------------------------------
// $Id: macros.h,v 1.2 1999/05/03 14:29:41 ylo Exp $
//
// $Log: macros.h,v $
// Revision 1.2  1999/05/03 14:29:41  ylo
// *** empty log message ***
//
// Revision 1.1  1998/11/23 14:37:19  scadaref
// Initial revision
//
// Revision 1.7  1997/07/18 09:22:39  olivier
// .
//
// Revision 1.6  1997/07/07 09:12:17  dom
// use of AnString
//
// Revision 1.5  1997/06/18 09:48:05  olivier
// .
//
// Revision 1.4  1997/06/16 11:50:23  olivier
// *** empty log message ***
//
// Revision 1.3  1997/06/04 16:04:36  olivier
// Adds AnString class
//
// Revision 1.2  1997/05/23 09:31:50  olivier
// 23/05/1997
//
// Revision 1.1  1997/05/20 13:45:23  olivier
// Initial revision
//
// --------------------------------------------------------------------------
#ifndef _ANT_MACROS_H_
#define _ANT_MACROS_H_
#include "ant/quark.h"
//{begin macro}

#define AnName2                AntName2 
#define AnDeclareTopClassInfo  AntDeclareTopClassInfo
#define AnRegisterTopClassInfo AntRegisterTopClassInfo
#define AnDeclareClassInfo     AntDeclareClassInfo
#define AnRegisterClassInfo    AntRegisterClassInfo

// --------------------------------------------------------------------------
// Class hierarchy definitions
// --------------------------------------------------------------------------
#define AntName2(a,b) a##b

#define AntDeclareTopClassInfo()          \
private:                                 \
  static const AntQuark* _TopClassQuark;  \
protected:                               \
  static const AntQuark* TopClassQuark();

#define AntRegisterTopClassInfo(_top_)                            \
const AntQuark* _top_::_TopClassQuark = AntGetQuark(#_top_);       \
const AntQuark* _top_::TopClassQuark() { return _TopClassQuark; }

#define AntDeclareClassInfo(_class_)                                    \
private:                                                               \
  static const AntQuark* _ClassQuark;                                   \
public:                                                                \
  static const AntString& ClassName();                                  \
  static const AntQuark* ClassQuark();                                  \
  virtual const AntString& isA() const { return *_ClassQuark;}          \
  virtual const AntQuark*  getClassQuark() const { return _ClassQuark;} \
  virtual AntBoolean isSubtypeOf(const AntQuark* ancestor) const;        \
  virtual AntBoolean isSubtypeOf(const char* ancestor) const;

#define AntRegisterClassInfo(_class_,_baseClass_)              \
const AntQuark* _class_::_ClassQuark= AntGetQuark(#_class_);    \
const AntQuark* _class_::ClassQuark() { return _ClassQuark; }  \
const AntString& _class_::ClassName() { return *_ClassQuark; } \
AntBoolean _class_::isSubtypeOf(const char* ancestor) const    \
{                                                             \
  const AntQuark* q = AntGetQuark(ancestor,AntFalse);            \
  if (q)                                                      \
    return _class_::isSubtypeOf(q);                           \
  else                                                        \
    return AntFalse;                                           \
}                                                             \
AntBoolean _class_::isSubtypeOf(const AntQuark* ancestor) const \
{                                                             \
  if(_class_::ClassQuark() == ancestor)                       \
    return AntTrue;                                            \
  if(TopClassQuark() == ancestor)                             \
    return AntTrue;                                            \
  if(_baseClass_::ClassQuark() != TopClassQuark())            \
    return _baseClass_::isSubtypeOf(ancestor);                \
  return AntFalse;                                             \
}
//{end macro}
#endif /* ! _AN_MACROS_H_ */
