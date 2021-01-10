//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsaddress.h                                           */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Fri Aug  4 14:57:39 2000                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
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


#ifndef _SCS_SCSADDRESS_H_
#define _SCS_SCSADDRESS_H_

#include "scsdefs.h"


class ScsPath;

/**
   \brief This class represents a database address.

   The class <em>ScsAddress</em> represents a database address, which is composed of an alias, a relative path and an attribute. Each of these components are optional.
\code#include "scs.h"\endcode
*/
class SCS_API ScsAddress
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. It creates an empty address.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ScsAddress();

  /**
     \par Description:
     constructor. It creates an <em>ScsAddress</em> object from a character string corresponding to a symbolic description. For example: &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, this example of symbolic address will be used for the examples of the other methods of the current class.
     \param address  [in]: the character string. 
     \par Return values:
     none.
  */
  ScsAddress(const char* address);

  /**
     \par Description:
     copy constructor.
     \param address  [in]: the <em>ScsAddress</em> object to copy. 
     \par Return values:
     none.
  */
  ScsAddress(const ScsAddress& address);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~ScsAddress();
  //@}

  /**@name General Usage Member functions*/
  //@{
  /**
     \par Description:
     returns the path part of the current <em>ScsAddress</em> object. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;. <b>Warning: this method uses internally a static variable, so the result string should be duplicated to be used if the current method shall be recalled</b>.
     \par Parameters:
     none.
     \par Return values:
     the path part of current object.
  */
  const char* getPath() const;
  /**
     \par Description:
     returns the relative path part of the current <em>ScsAddress</em> object. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>child1:child2</em>&quot;.
     \par Parameters:
     none.
     \par Return values:
     the relative path part of current object.
  */
  const char* getRelativePath() const;
  /**
     \par Description:
     returns the alias part of the current <em>ScsAddress</em> object, if any, NULL otherwise. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>point</em>&quot;.
     \par Parameters:
     none.
     \par Return values:
     the alias part of current object.
  */
  const char* getAlias() const;
  /**
     \par Description:
     returns the context part of the current <em>ScsAddress</em> object, if any, NULL otherwise. For example, if the object was created with the string &quot;<em>\<context\>my_context:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>mycontext</em>&quot;.
     \par Parameters:
     none.
     \par Return values:
     the context part of current object.
  */
  const char* getContext() const;
  /**
     \par Description:
     returns the point path part of the current <em>ScsAddress</em> object (i.e. omits the attribute part). For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>\<alias\>point:child1:child2</em>&quot;.
     \par Parameters:
     none.
     \par Return values:
     the point path part of current object.
  */
  const char* getPointPath() const;
  /**
     \par Description:
     returns the attribute name of the current <em>ScsAddress</em> object. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>value</em>&quot;.
     \par Parameters:
     none.
     \par Return values:
     the attribute name of current object.
  */
  const char* getAttribute() const;
   /**
     \par Description:
     returns the attribute part of the current <em>ScsAddress</em> object. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>(i,j)</em>&quot;.
     \par Parameters:
     none.
     \par Return values:
     the attribute part of current object.
  */
  const char* getAttributePart() const;
  /**
     \par Description:
     returns the last part of the relative path of the current <em>ScsAddress</em> object. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be &quot;<em>child2</em>&quot;.
     \par Parameters:
     none.
     \par Return values:
     the last part of relative path of current object.
  */
  const char* getLastInPath() const;
  /**
     \par Description:
     returns the name of the <em>pos</em>th part of the relative path of the current <em>ScsAddress</em> object. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result with a <em>pos</em> parameter set to 0 will be &quot;<em>child1</em>&quot;.
     \param pos  [in]: position of relative path part. 
     \par Return values:
     the name of <em>pos</em>th part of relative path of current object.
  */
  const char* getPathAt(int pos) const;
  /**
     \par Description:
     returns the number of elements in the relative path of the current <em>ScsAddress</em> object. For example, if the object was created with the string &quot;<em>\<alias\>point:child1:child2.value(i,j)</em>&quot;, the result will be 2.
     \par Parameters:
     none.
     \par Return values:
     the number of elements in the relative path of current object.
  */
  int getPathLength() const;
  /**
     \par Description:
     returns the parent path of the current <em>ScsAddress</em> object. The return memory has to be deleted by the caller.
     \par Parameters:
     none.
     \par Return values:
     the parent path. The method returns null if no parent path is available (only the alias property is set).
  */
  const char* getParentPath() const;
  /**
     \par Description:
     test if the <em>ScsAddress</em> is absolute (i.e. has an alias part) or not.
     \par Parameters:
     none.
     \par Return values:
     1 if current object is absolute, 0 otherwise.
  */
  int isAbsolute() const;
  /**
     \par Description:
     test if the <em>ScsAddress</em> is empty (i.e. no alias part, no relative path part and no attribute part) or not.
     \par Parameters:
     none.
     \par Return values:
     1 is current object is empty, 0 otherwise.
  */
  int isEmpty() const;
  //@}

  /**@name Operator / cast*/
  //@{
  /**
     \par Description:
     assignment operator. This operator is used to assign an <em>ScsAddress</em> object to another <em>ScsAddress</em> object.
     \param address  [in]: the address to assign.
     \par Return values:
     current object.
    */
  ScsAddress& operator=(const ScsAddress& address);
  /**
     \par Description:
     cast operator, returns the path of the current <em>ScsAddress</em> object (as <em>getPath()</em> function).
     \par Parameters:
     none.
     \par Return values:
     the path of current object.
  */
  operator const char* () const;
  /**
     \par Description:
     this operator concatenates two relative paths or an absolute and a relative path.
     \param address  [in]: the address object containing the path to concatenate.
     \par Return values:
     the result address object.
  */
  ScsAddress operator+(const ScsAddress& address) const;
  //@}

public :
    
   mutable ScsPath* _address;
   char* _fullpath;
};

#endif
