// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [MODULE]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: AntString.h
//  description: 
//     creation: 1997/11/27
//       author: jpm
// --------------------------------------------------------------------------
// $Id: string.h,v 1.4 1999/11/23 19:08:55 scadaref Exp $
//
// $Log: string.h,v $
// Revision 1.4  1999/11/23 19:08:55  scadaref
// Port on MSVC6
//
// Revision 1.3  1999/10/18 10:14:09  scadaref
// Port on NT
//
// Revision 1.2  1999/02/15 15:51:58  ylo
// *** empty log message ***
//
// Revision 1.1  1999/02/15 14:45:58  ylo
// Initial revision
//
// Revision 1.4  1998/02/10 10:13:36  v9
// a98_210
//
//
// --------------------------------------------------------------------------
#ifndef	_ANT_STRING_H_
#define	_ANT_STRING_H_

#include "ant/defs.h"

#ifdef AN_STD
#include <iostream>
#else
#include <iostream.h>
#endif

class RWCString;
class RWCSubString;

class AntString;

// --------------------------------------------------------------------------
//        class: AntSubString
//   superClass: -
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/11/27
//       author: jpm
// modification: rewriting with RWCString use
// --------------------------------------------------------------------------

/**
  \#include <ant/string.h>.
  The class AntSubString allows some subsection of an AntString to be addressed by defining
  a starting position and an extent. For example the 7th through the 11th elements, inclusive,
  would have a starting position of 7 and an extent of 5.
  There are no public constructors -- AntSubStrings are constructed by various functions
  of the AntString class and then destroyed immediately. 

  A zero length substring is one with a defined starting position and an extent of zero.
  It can be thought of as starting just before the indicated character, but not including it.
  It can be used as an lvalue. A null substring is also legal and is frequently used to
  indicate that a requested substring, perhaps through a search, does not exist.
  A null substring can be detected with member function isNull().
  However, it cannot be used as an lvalue. 
  @see AntString.
  */
class SCSERROR_API AntSubString
{
public:
/**@name Constructors / destructor*/
//@{
/**
  .
  Copy constructor.
  */
    AntSubString(const AntSubString& sp);

//{begin internal}
    AntSubString(const RWCSubString& sp);
//{end internal}

/**
  .
  Virtual destructor.
  */
    virtual ~AntSubString();
//@}

/**@name Assignment operators*/
//@{
/**
  .
  Assignment operator. Copies the null-terminated character string pointed to by cs into self. Returns a reference to self.
  */
    AntSubString& operator=(const char* cs);
/**
  .
  Assignment operator. The substring will copy str's data. Returns a reference to self.
  */
    AntSubString& operator=(const AntString& str);
/**
  .
  Assignment operator. The substring will copy str's data. Returns a reference to self.
  */
    AntSubString& operator=(const AntSubString& str);
//@}
/**@name Indexing operators*/
//@{
/**
  .
  Returns the ith byte. This first variant can be used as an lvalue.
  The index i must be between 0 and the length of the substring less one.
  Bounds checking is performed -- if the index is out of range then an exception will occur.
  */
    char&        operator[](size_t i);          // Index with bounds checking
/**
  .
  Returns the ith byte. This second variant can not be used as an lvalue.
  The index i must be between 0 and the length of the substring less one.
  Bounds checking is performed -- if the index is out of range then an exception will occur.
  */
    char         operator[](size_t index) const;
/**
  .
  Returns the ith byte. This first variant can be used as an lvalue.
  The index i must be between 0 and the length of the substring less one.
  Bounds checking is not performed.
  */
    char&        operator()(size_t i);          // Index with optional bounds checking
/**
  .
  Returns the ith byte. This first variant can not be used as an lvalue.
  The index i must be between 0 and the length of the substring less one.
  Bounds checking is not performed.
  */
    char         operator()(size_t index) const;
//@}
    
/**@name General usage member functions*/
//@{
/**
  .
  Returns the number of bytes in self. 
  */
    size_t       length() const;
/**
  .
  Returns the starting element of the substring.
  */
    size_t       start() const;
/**
  .
  Changes all upper-case letters in self to lower-case, using the standard C library facilities declared in <ctype.h>. 
  */
    void         toLower();              // Convert self to lower-case
/**
  .
  Changes all lower-case letters in self to upper-case, using the standard C library facilities declared in <ctype.h>. 
  */
    void         toUpper();              // Convert self to upper-case
    
/**
  .
  Returns AntTrue if this is a zero lengthed substring (i.e., the null string). 
  */
    AntBoolean    isNull() const;
//@}
    int          operator!() const;

/**@name Related global operators*/
//@{
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntSubString& s1, const AntSubString& s2);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntSubString& s1, const char* s2);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const char*        s2, const AntSubString& s1);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntSubString& s1, const AntString& s2);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntString&    s1, const AntSubString& s2);

/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntSubString& s1, const AntSubString& s2);
/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntSubString& s1, const char* s2);
/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const char*        s2, const AntSubString& s1);
/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntSubString& s1, const AntString& s2);
/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntString&    s1, const AntSubString& s2);
//@}

protected:
    
    RWCSubString* _rwCSubString;

private:
        
    friend class AntString;
};

// --------------------------------------------------------------------------
//        class: AntString
//   superClass: -
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/11/27
//       author: jpm
// modification: rewriting with RWCString use
// --------------------------------------------------------------------------


/**
  \#include <ant/string.h>.
  Class AntString offers very powerful and convenient facilities for manipulating strings
  that are just as efficient as the familiar standard C <string.h> functions.

  The class is implemented using a technique called copy on write.
  With this technique, the copy constructor and assignment operators still reference
  the old object and hence are very fast. An actual copy is made only when a "write"
  is performed, that is if the object is about to be changed. The net result is excellent
  performance, but with easy-to-understand copy semantics.

  Parameters of type "const char*" must not be passed a value of zero.

  A separate class AntSubString supports substring extraction and modification operations.
  @see AntSubString.
  */
class AntString
{
public:

/**@name Constructors / destructor*/
//@{
/**
  .
  Creates a string of length zero (the null string).
  */
    AntString();
/**
  .
  Copy constructor.
  */
    AntString(const AntString& str);         // Copy constructor
/**
  .
  Conversion from the null-terminated character string 'cs'.
  The created string will copy the data pointed to by 'cs', up to the first terminating null.
  */
    AntString(const char* cs);
/**
  .
  Constructs a string from the character string 'cs'.
  The created string will copy the data pointed to by 'cs'. Exactly 'N' bytes are copied,
  including any embedded nulls. Hence, the buffer pointed to by 'cs' must be at least 'N' bytes long.
  */
    AntString(const char *cs, size_t N);  // Copy past any embedded nulls
/**
  .
  Constructs a string containing the single character 'c'.
  */
    AntString(char c);
/**
  .
  Constructs a string containing the character 'c' repeated 'N' times.
  */
    AntString(char c, size_t N);
/**
  .
  Conversion from sub-string. The created string will copy the substring represented by 'ss'.
  */
    AntString(const AntSubString& ss);

//{begin internal}
    AntString(const RWCString& string);
    AntString(RWCString* string);
//{end internal}

/**
  .
  Virtual destructor.
  */
    virtual ~AntString();
//@}

/**@name Type conversion operators*/
//@{
/**
  .
  Access to the AntString's data as a null terminated string. This data is owned by the AntString and may not be
  deleted or changed. If the AntString object itself changes or goes out of scope, the pointer value previously returned
  may (will!) become invalid. While the string is null-terminated, note that its length is still given by the member function
  length(). That is, it may contain embedded nulls.
  */
    operator const char*() const;
/**
  .
  Equivalent to the type conversion operator defined above.
  */
    const char* data() const;
//@}

/**@name Assignment operators*/
//@{
/**
  .
  Assignment operator. Copies the null-terminated character string pointed to by cs into self. Returns a reference to self.
  */
    AntString& operator=(const char* cs);
/**
  .
  Assignment operator. The string will copy str's data. Returns a reference to self.
  */
    AntString& operator=(const AntString& str);

/**
  .
  Append the null-terminated character string pointed to by cs to self. Returns a reference to self.
  */
    AntString& operator+=(const char* cs);
/**
  .
  Append the string str to self. Returns a reference to self.
  */
    AntString& operator+=(const AntString& str);
//@}

/**@name Indexing operators*/
//@{
/**
  .
  Returns the ith byte. This first variant can be used as an lvalue.
  The index i must be between 0 and the length of the string less one.
  Bounds checking is performed -- if the index is out of range then an exception will occur.
  */
    char& operator[](size_t i);
/**
  .
  Returns the ith byte. This second variant can not be used as an lvalue.
  The index i must be between 0 and the length of the string less one.
  Bounds checking is performed -- if the index is out of range then an exception will occur.
  */
    char  operator[](size_t i) const;
/**
  .
  Returns the ith byte. This first variant can be used as an lvalue.
  The index i must be between 0 and the length of the string less one.
  Bounds checking is not performed.
  */
    char& operator()(size_t i);
/**
  .
  Returns the ith byte. This first variant can not be used as an lvalue.
  The index i must be between 0 and the length of the string less one.
  Bounds checking is not performed.
  */
    char  operator()(size_t i) const;
   
/**
  .
  Substring operator. Returns an AntSubString of self with length len, starting at index start.
  This first variant can be used as an lvalue. The sum of start plus len must be less than or equal to the string length.
  */
    AntSubString  operator()(size_t start, size_t len);
/**
  .
  Substring operator. Returns an AntSubString of self with length len, starting at index start.
  This second variant can not be used as an lvalue. The sum of start plus len must be less than or equal to the string length.
  */
    const AntSubString  operator()(size_t start, size_t len) const;
//@}

/**@name General usage member functions*/
//@{
/**
  .
  Appends a copy of the null-terminated character string pointed to by cs to self. Returns a reference to self. 
  */
    AntString&    append(const char* cs);
/**
  .
  Appends a copy of the character string cs to self. Exactly N bytes are copied, including any embedded nulls. Hence,
  the buffer pointed to by cs must be at least N bytes long. Returns a reference to self.
  */
    AntString&    append(const char* cs, size_t N);
/**
  .
  Appends a copy of the string cstr to self. Returns a reference to self.
  */
    AntString&    append(const AntString& cstr);
/**
  .
  Appends the first N bytes or the length of cstr (whichever is less) of cstr to self. Returns a reference to self.
  */
    AntString&    append(const AntString& cstr, size_t N);
/**
  .
  Appensd N copies of the character c to self. Returns a reference to self.

  */
    AntString&    append(char c, size_t N=1);

/**
  .
  Returns the index of the first occurence of the character c in self. Returns AntInvalidId if there is no such character or if
  there is an embedded null prior to finding c.
  */
    size_t first(char c) const;
/**
  .
  Returns the index of the first occurence of the character c in self. Continues to search past embedded nulls.
  Returns AntInvalidId if there is no such character.
  */
    size_t first(char c, size_t i) const;
/**
  .
  Returns the index of the first occurence in self of any character in str. Returns AntInvalidId if there is no match or if there
  is an embedded null prior to finding any character from str. 
  */
    size_t first(const char* str) const;
/**
  .
  Returns the index of the first occurence in self of any character in str. Exactly N bytes in str are checked including
  any embedded nulls so str must point to a buffer containing at least N bytes. Returns AntInvalidId if there is no match.
  */
    size_t first(const char* str, size_t N) const;

/**
  .
   Pattern matching. Starting with index i, searches for the first occurrence of pat in self and returns the index of the start of the match.
   Returns AntInvalidId if there is no match.
  */
    size_t index(const char* pat, size_t i=0) const;
/**
  .
   Pattern matching. Starting with index i, searches for the first occurrence of s in self and returns the index of the start of the match.
   Returns AntInvalidId if there is no match.
  */
    size_t index(const AntString& s, size_t i=0) const;
/**
  .
  Returns AntTrue if self contains no bytes with the high bit set. 
  */
    AntBoolean isAscii() const;
/**
  .
  Returns AntTrue if this is a zero lengthed string (i.e., the null string). 
  */
    AntBoolean isNull() const;
/**
  .
  Returns the index of the last occurrence in the string of the character c. Returns AntInvalidId if there is no such character or
  if there is an embedded null to the right of c in self. 
  */
    size_t last(char c) const;
/**
  .
  Returns the index of the last occurrence in the string of the character c. Continues to search past embedded nulls.
  Returns AntInvalidId if there is no such character.  
  */
    size_t last(char c,size_t i) const;
/**
  .
  Returns the number of bytes in self. 
  */
    size_t length() const;

/**
  .
  Prepends a copy of the null-terminated character string pointed to by cs to self.
  Returns a reference to self. This function is incompatible with cs strings with embedded nulls. 
  */
    AntString&    prepend(const char* cs);
/**
  .
  Prepends a copy of the character string cs to self. Exactly N bytes are copied, including any embedded nulls. Hence,
  the buffer pointed to by cs must be at least N bytes long. Returns a reference to self.  
  */
    AntString&    prepend(const char* cs, size_t N);
/**
  .
  Prepends a copy of the string cstr to self. Returns a reference to self. 
  */
    AntString&    prepend(const AntString& cstr);
/**
  .
  Prepends the first N bytes or the length of cstr (whichever is less) of cstr to self. Returns a reference to self. 
  */
    AntString&    prepend(const AntString& cstr, size_t N);
/**
  .
  Prepends N copies of character c to self. Returns a reference to self. 
  */
    AntString&    prepend(char c, size_t N=1);

/**
  .
  Removes the bytes from the byte position pos, which must be no greater than length(), to the end of string. Returns a
  reference to self. 
  */
    AntString&    remove(size_t pos);
/**
  .
  Removes N bytes or to the end of string (whichever comes first) starting at the byte position pos, which must be no
  greater than length(). Returns a reference to self. 
  */
    AntString&    remove(size_t pos, size_t n);
/**
  .
  Replaces N bytes or to the end of string (whichever comes first) starting at byte position pos, which must be no greater
  than length(), with a copy of the null-terminated string cs. Returns a reference to self. 
  */
    AntString&    replace(size_t pos, size_t N, const char* cs);
/**
  .
  Replaces N1 bytes or to the end of string (whichever comes first) starting at byte position pos, which must be no greater
  than length(), with a copy of the string cs. Exactly N2 bytes are copied, including any embedded nulls. Hence, the
  buffer pointed to by cs must be at least N2 bytes long. Returns a reference to self. 
  */
    AntString&    replace(size_t pos, size_t N1, const char* cs, size_t N2);
/**
  .
  Replaces N bytes or to the end of string (whichever comes first) starting at byte position pos, which must be no greater
  than length(), with a copy of the string str. Returns a reference to self. 
  */
    AntString&    replace(size_t pos, size_t N, const AntString& str);
/**
  .
  Replaces N1 bytes or to the end of string (whichever comes first) starting at position pos, which must be no greater than
  length(), with a copy of the first N2 bytes, or the length of str (whichever is less), from str. Returns a reference to
  self. 
  */
    AntString&    replace(size_t pos, size_t N1, const AntString& str, size_t N2);
/**
  .
  Changes the length of self to N bytes, adding blanks or truncating as necessary.
  */
    void resize(size_t N);
/**
  .
  Changes all upper-case letters in self to lower-case, using the standard C library facilities declared in <ctype.h>. 
  */
    void toLower();
/**
  .
  Changes all lower-case letters in self to upper-case, using the standard C library facilities declared in <ctype.h>. 
  */
    void toUpper();

/**
  .
     Reads characters from the input stream s, replacing the previous contents of self, until EOF is reached. Null characters are treated the same
     as other characters.
  */
    AN_SL_STD(istream)& readFile(AN_SL_STD(istream)& s);


/**
  .
     Reads characters from the input stream s, replacing the previous contents of self, until a newline (or an EOF) is encountered. The newline is
     removed from the input stream but is not stored. Null characters are treated the same as other characters. If the skipWhite argument is
     AntTrue, then whitespace is skipped (using the iostream library manipulator ws) before saving characters.
  */
    AN_SL_STD(istream)& readLine(AN_SL_STD(istream)& s, AntBoolean skipWhite = AntTrue);

/**
  .
     Reads characters from the input stream s, replacing the previous contents of self, until an EOF or null terminator is encountered. If the
     number of bytes remaining in the stream is large, you should resize the RWCString to approximately the number of bytes to be read prior
     to using this method. See "Implementation Details" in the User's Guide for more information. This function is incompatible with strings
     with embedded nulls. This function may be incompatible with MBCS strings.
  */
    AN_SL_STD(istream)& readString(AN_SL_STD(istream)& s);

/**
  .
     Reads characters from the input stream s, replacing the previous contents of self, until an EOF or the delimiting character delim is
     encountered. The delimiter is removed from the input stream but is not stored. Null characters are treated the same as other characters. If
     delim is '\0' then this function is incompatible with strings with embedded nulls.
  */
    AN_SL_STD(istream)& readToDelim(AN_SL_STD(istream)& s, char delim='\n');


/**
  .
     Whitespace is skipped before saving characters. Characters are then read from the input stream s, replacing previous contents of self, until
     trailing whitespace or an EOF is encountered. The whitespace is left on the input stream. Null characters are treated the same as other
     characters. Whitespace is identified by the standard C library function isspace().
  */
    AN_SL_STD(istream)& readToken(AN_SL_STD(istream)& s);

    
//@}

    static size_t initialCapacity(size_t ic);
    static size_t maxWaste(size_t mw);
    static size_t resizeIncrement(size_t ri);

    static size_t getInitialCapacity();
    static size_t getResizeIncrement();
    static size_t getMaxWaste();

/**@name Related global operators*/
//@{
/**
  .
  Concatenation operators. This function is incompatible with const char* strings with embedded nulls.
  */
    friend AntString  operator+(const AntString& s1, const AntString& s2);
/**
  .
  Concatenation operators. This function is incompatible with const char* strings with embedded nulls.
  */
    friend AntString  operator+(const AntString& s1, const char* s2);
/**
  .
  Concatenation operators. This function is incompatible with const char* strings with embedded nulls.
  */
    friend AntString  operator+(const char* s1,     const AntString& s2);

/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntString&    s1, const AntString& s2);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntString&    s1, const char* s2);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const char*        s1, const AntString& s2);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntSubString& s1, const AntString& s2);
/**
  .
  Logical equality. Case sensitivity is exact.
  */
    friend AntBoolean operator==(const AntString&    s1, const AntSubString& s2);

/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntSubString& s1, const AntString& s2);
/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntString&    s1, const AntSubString& s2);
/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntString&    s1, const AntString& s2);

/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const AntString&    s1, const char* s2);
/**
  .
  Logical inequality. Case sensitivity is exact.
  */
    friend AntBoolean operator!=(const char*        s1, const AntString& s2);
/**
  .
  Output an AntString on ostream os.
  */
    friend AN_SL_STD(ostream)&  operator<<(AN_SL_STD(ostream)& os, const AntString& s );
//@}

    RWCString* getRWCString() const;

protected:

    RWCString*  _rwCString;
    
private:

    friend class AntSubString;
};

inline RWCString*
AntString::getRWCString() const
{
    return _rwCString;
}

#endif /* ! _AN_STRING_H_ */
