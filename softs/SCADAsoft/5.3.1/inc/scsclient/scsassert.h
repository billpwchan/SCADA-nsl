// scsassert.h -- Provides assert-like functions to check program correction at runtime

/** 
    Provides the SCS_ASSERT(), SCS_PRECONDITION() and SCS_POSTCONDITION() debugging macros.

    These macros should be used to detect internal program errors, inside a component or an executable file.
    They should never be used to detect user errors, environment errors (like a missing file or an environment variable with 
    the wrong value), program arguments, or a wrong usage of the interface of a CORBA object.

    The preprocessor symbol SCS_ASSERTIONS is used to modify the behavior of the assertion macros.
    If SCS_ASSERTIONS is not defined or is defined to 0, the assertions macros are not expanded.
    If SCS_ASSERTIONS is defined to 1, an assertion evaluated to false just prints an error message on stderr.
    If SCS_ASSERTIONS is defined to 2, an assertion that is evaluated to false triggers an exception.
    If SCS_ASSERTIONS is defined to 3, an assertion that is evaluated to false causes the program to abort().
    Any other value causes a compilation error.    
*/

#ifndef _SCS_ASSERT_H
#define _SCS_ASSERT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


// Check the value of the SCS_ASSERTIONS preprocessor symbol.
#if defined(SCS_ASSERTIONS) && (SCS_ASSERTIONS != 0 && SCS_ASSERTIONS != 1 && SCS_ASSERTIONS != 2 && SCS_ASSERTIONS != 3)
#error "If defined, the preprocessor symbol SCS_ASSERTIONS must be 0, 1, 2 or 3."
#endif 

#if defined(SCS_ASSERTIONS) && (SCS_ASSERTIONS >= 1)

/** Check that a condition is fulfilled.
    Usage: SCS_ASSERT(condition) or SCS_ASSERT(condition, message, ...) with a printf-like format string.  */
#define SCS_ASSERT(condition, ...) SCS_Assert<SCS_AssertException>(condition,  __FILE__, __LINE__, ##__VA_ARGS__)

/** Use this macro to verify the arguments of public functions only: 
    The function is supposed to work only if the condition is true.  */
#define SCS_PRECONDITION(condition, ...) SCS_Assert<SCS_PreconditionException>(condition, __FILE__, __LINE__, ##__VA_ARGS__)

/** Use this macro to verify the exit conditions of a function.  */
#define SCS_POSTCONDITION(condition, ...) SCS_Assert<SCS_PostconditionException>(condition, __FILE__, __LINE__, ##__VA_ARGS__)


#else // !defined(SCS_ASSERTIONS) || (SCS_ASSERTIONS == 0)

// Disable all the assertions macros.

#define SCS_ASSERT(condition, ...)
#define SCS_PRECONDITION(condition, ...)
#define SCS_POSTCONDITION(condition, ...)


#endif // !defined(SCS_ASSERTIONS)


/** Maximum length of an assertion error message. Messages will be truncated if longer.  */
#define SCS_ASSERTIONS_MSG_MAXIMUM_SIZE 2048


/** Exception sent by SCS_ASSERT(). */

class SCS_AssertException
{
public:
   SCS_AssertException(const std::string &message, const char *file, int line)
      : file_(file),
        line_(line),
        message_(message)
   {
   }
   
   SCS_AssertException(const SCS_AssertException &other) 
      : file_(other.file_),
        line_(other.line_),
        message_(other.message_)
   {
   }
   
   SCS_AssertException & operator = (const SCS_AssertException &other)
   {
      file_ = other.file_;
      line_ = other.line_;
      message_ = other.message_;
      return *this;
   }
   
   virtual ~SCS_AssertException() 
   {
   }
   
   /** The source file name where the exception occured.  */
   virtual const std::string &file() const
   {
      return file_;
   }
   
   /** The source line number where the exception occured.  */
   virtual int line() const
   {
      return line_;
   }

   /** The message that was passed in argument to the SCS_ASSERT() macro, or a generic
       message if none was given.  */   
   virtual const std::string &message() const 
   {
      return message_;
   }
   
   /** A message suitable for printing, containing the string that was passed in argument to SCS_ASSERT()
       together with the source file name and the line number.  */
   virtual std::string formatted_message() const
   {
      std::ostringstream stream;
      stream << "Software error in file \"" << file_ << "\" line " << line_ << ": " << message_ << ".";
      return stream.str();
   }
   
private:
   std::string file_;
   int line_;
   std::string message_;      
};


/** Exception sent by SCS_PRECONDITION(). */

class SCS_PreconditionException : public SCS_AssertException
{
public:
   SCS_PreconditionException(const std::string &message, const char *file, int line)
      : SCS_AssertException(message, file, line)
   {
   }
   
   SCS_PreconditionException(const SCS_PreconditionException &other)
      : SCS_AssertException(other)
   {
   }
  
   SCS_PreconditionException & operator = (const SCS_PreconditionException &other)
   {
      SCS_AssertException::operator = (other);
      return *this;
   }
  
   virtual ~SCS_PreconditionException()
   {
   }         
};


/** Exception sent by SCS_POSTCONDITION(). */

class SCS_PostconditionException : public SCS_AssertException
{
public:
   SCS_PostconditionException(const std::string &message, const char *file, int line)
      : SCS_AssertException(message, file, line)
   {
   }
   
   SCS_PostconditionException(const SCS_PostconditionException &other)
      : SCS_AssertException(other)
   {
   }
   
   SCS_PostconditionException & operator = (const SCS_PostconditionException &other)
   {
      SCS_AssertException::operator = (other);
      return *this;
   }
   
   virtual ~SCS_PostconditionException()
   {
   }
};


/** Build an error message of maximum SCS_ASSERTIONS_MSG_MAXIMUM_SIZE characters. 
    You don't have to use this function directly, it is called by SCS_ASSERT() and related macros.  */

inline std::string SCS_AssertBuildErrorMessage(const char *file, int line, const char *message, va_list args)
{
   char buffer[SCS_ASSERTIONS_MSG_MAXIMUM_SIZE];
   vsnprintf(buffer, (sizeof buffer) - 1, message, args);
   buffer[(sizeof buffer) - 1] = '\0';
   return buffer;         
}


/** 
    Checks a condition and, if this condition is not satisfied, prints a message, then optionally 
    launches an exception or aborts the program. 

    You should use the SCS_ASSERT(), SCS_PRECONDITION() and SCS_POSTCONDITION() macros instead of calling
    this function directly. 
    
    @param X the type of the exception that will be thrown if the condition is not satisfied. This is used only
    if the preprocessor symbol SCS_ASSERTIONS is defined to 2.
    @param condition the condition to check.
    @param file the source file where the assertion is located.
    @param line the line in the source file where the assertion is located.
    @param message an error message to print and include in the exception if the assertion is not satisfied (this parameter
    is compulsory and cannot be NULL).
*/

template<typename X>
void SCS_Assert(bool condition, const char *file, int line, const char *message, ...)
{
   if (!condition)
   {         
      va_list args;
      va_start(args, message); 
      std::string full_message = SCS_AssertBuildErrorMessage(file, line, message, args);     
      va_end(args);
      
      std::cerr << "Software error in file \"" << file << "\" line " << line << ": " << full_message << "." << std::endl;

#if SCS_ASSERTIONS == 2
      throw X(full_message, file, line);
#elif SCS_ASSERTIONS == 3
      abort();
#endif // SCS_ASSERTIONS
   }
}


/** 
    Another version of the SCS_Assert() function that does not take a message in argument. 
    A generic error message will be used.  
    Use the SCS_ASSERT(), SCS_PRECONDITION() and SCS_POSTCONDITION() instead of using this function directly.  
*/

template<typename X>
void SCS_Assert(bool condition, const char *file, int line)
{
   SCS_Assert<X>(condition, file, line, "assertion failed");
}

#endif // _SCS_ASSERT_H
