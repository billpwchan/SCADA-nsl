//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scscstring.h                                           */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : D. LAYES                                               */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Mon Apr 25 11:32:06 2005                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $


#ifndef _SCS_SCSCSTRING_H_
#define _SCS_SCSCSTRING_H_


#include <scs.h>

#include "scscsubstring.h"

const size_t SCS_NPOS = ~(size_t)0;


class SCS_API ScsCString
{
 public:

  enum stripType {leading = 1, trailing = 2, both = 3};
  enum caseCompare {exact = 0, ignoreCase = 1};

  ScsCString(void);

  ScsCString(const char* cs);

  ScsCString(const ScsCString& str);

  ScsCString(const ScsCSubString& ss);

  ScsCString(char c);

  ~ScsCString(void);

  ScsCString& operator =(const char* cs);

  ScsCString& operator =(const ScsCString& str);

  ScsCString& operator +=(const char* cs);

  ScsCString& operator +=(const ScsCString& str);

  ScsCSubString operator ()(size_t start, size_t len);

  operator const char* () const;

  ScsCString& append(const char* cs);

  ScsCString& append(const ScsCString& cstr);

  const char* data(void) const;

  size_t length(void) const;

  int isNull(void) const;

  size_t first(char c) const;

  size_t first(char c, size_t sz) const;

  size_t first(const char* str) const;

  size_t last(char c) const;

  size_t last(char c, size_t N) const;

  unsigned hash(caseCompare c = ScsCString::exact) const;

  ScsCSubString strip(stripType s = ScsCString::trailing, char c = ' ');

  SCS_SL_STD(istream)& readFile(SCS_SL_STD(istream)& s);

  static unsigned hash(const ScsCString& str);

  private :

    friend class ScsCSubString;

  friend SCS_API int operator ==(const ScsCString& str1, const char* str2);
  friend SCS_API int operator ==(const char* str1, const ScsCString& str2);
  friend SCS_API int operator ==(const ScsCString& str1, const ScsCString& str2);
  friend SCS_API int operator !=(const ScsCString& str1, const char* str2);
  friend SCS_API int operator !=(const char* str1, const ScsCString& str2);
  friend SCS_API int operator !=(const ScsCString& str1, const ScsCString& str2);
  friend SCS_API ScsCString operator +(const ScsCString& str1, const ScsCString& str2);
  friend SCS_API ScsCString operator +(const ScsCString& str1, const char* str2);
  friend SCS_API ScsCString operator +(const char* str1, const ScsCString& str2);
  friend SCS_API int operator <(const ScsCString& str1, const ScsCString& str2);
  friend SCS_API int operator <(const ScsCString& str1, const char* str2);
  friend SCS_API int operator <(const char* str1, const ScsCString& str2);

  void* _string;
};

// Global operators

extern SCS_API int operator ==(const ScsCString& str1, const char* str2);

extern SCS_API int operator ==(const char* str1, const ScsCString& str2);

extern SCS_API int operator ==(const ScsCString& str1, const ScsCString& str2);

extern SCS_API int operator !=(const ScsCString& str1, const char* str2);

extern SCS_API int operator !=(const char* str1, const ScsCString& str2);

extern SCS_API int operator !=(const ScsCString& str1, const ScsCString& str2);

extern SCS_API ScsCString operator +(const ScsCString& str1, const ScsCString& str2);

extern SCS_API ScsCString operator +(const ScsCString& str1, const char* str2);

extern SCS_API ScsCString operator +(const char* str1, const ScsCString& str2);

extern SCS_API int operator <(const ScsCString& str1, const ScsCString& str2);

extern SCS_API int operator <(const ScsCString& str1, const char* str2);

extern SCS_API int operator <(const char* str1, const ScsCString& str2);

#endif

