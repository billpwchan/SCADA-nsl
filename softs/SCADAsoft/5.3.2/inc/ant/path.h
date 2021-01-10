// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [TOOLS]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: path.h
//  description: declaration of AntPath
//     creation: 1997/04/24
//       author: dom
// --------------------------------------------------------------------------
// $Id: path.h,v 1.3 1999/11/30 17:18:58 scadaref Exp $
//
// $Log: path.h,v $
// Revision 1.3  1999/11/30 17:18:58  scadaref
// Port on MSVC6
//
// Revision 1.2  1999/02/15 14:42:46  ylo
// *** empty log message ***
//
// Revision 1.1  1998/11/23 14:37:19  scadaref
// Initial revision
//
// Revision 1.6  1997/07/03 09:13:33  olivier
// .
//
// Revision 1.4  1997/07/01 16:45:04  olivier
// *** empty log message ***
//
// Revision 1.2  1997/05/27 08:01:55  olivier
// *** empty log message ***
//
// Revision 1.1  1997/05/13 17:35:32  olivier
// Initial revision
//
//
// --------------------------------------------------------------------------
#ifndef _AN_TPATH_H_
#define _AN_TPATH_H_
#ifdef AN_STD
#include <iostream>
#else
#include <iostream.h>
#endif
#include "ant/pathname.h"
// --------------------------------------------------------------------------
//        class: AntPath
//   superClass: -
//
//  description: To manage compound path names
// --------------------------------------------------------------------------
//     creation: 1997/05/13
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
/**
  \#include <ant/path.h>.
  The class AntPath manages compound search paths for files.
  */
class SCSERROR_API AntPath
{
public:
    AntPath(const char* path="", const char sep=';');
    virtual ~AntPath();

    const char*         getPath() const { return _path; }
    void                setPath(const char* path);
    char                getSeparator() const { return _separator; }
    void                appendToPath(const char* path);
    void                prependToPath(const char* path);
//    const char*         findInPath(const char* fileName) const;
    const AntPathName&  findInPath(const char* fileName);
    friend AN_SL_STD(ostream)&     operator<<(AN_SL_STD(ostream)& os, AntPath&);
private:
    char*               _path;
    const char          _separator;
    AntPathName         _fileName;
};



#endif /* ! _AN_TPATH_H_ */
