/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsbasicvalue.h                                      */
/*  FULL NAME       : ScsBasicValue                                        */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : Fri December 08 2000                                 */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsBasicValue is a class template for basic value.                     */
/*.........................................................................*/
/*  COMMENT                                                                */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsBasicValue's interface and implementation.      */
/***************************************************************************/
// Revision 3.9.0  2002/11/18 KLL
// FFT SRC-375 - snapshot

#ifndef SCSBASICVALUE_H
#define SCSBASICVALUE_H

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scs.h"

template <typename T>
class ScsBasicValue
{

// FIELDS
 private:
  // limits
  T* _limits;
  // limits size
  int _limitsSize;
  // value
  T _value;

// METHODS
 public:
  // default constructor
  ScsBasicValue<T>()
    :_value(0),
     _limits(NULL),
     _limitsSize(0)
    {
    };
  // constructor for copy
  ScsBasicValue<T>(const ScsBasicValue<T>& inScsBasicValueInstance)
    :_value(inScsBasicValueInstance._value),
     _limits(NULL),
     _limitsSize(0)
    {
      setLimits(inScsBasicValueInstance._limits, inScsBasicValueInstance._limitsSize);
    };
  // destructor
  virtual ~ScsBasicValue<T>()
    {
      if (_limits != NULL)
      {
        delete[] _limits;
        _limits = NULL;
      }
    };

  // redundancy
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream)
    {
      outStream.rdbuf()->sputn((const char*)&_value, sizeof(T));
      outStream.rdbuf()->sputn((const char*)&_limitsSize, sizeof(int));
      for (int i=0; i<_limitsSize; i++)
        outStream.rdbuf()->sputn((const char*)&_limits[i], sizeof(T));
      return ScsValid;
    };

  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream)
    {
      inStream.rdbuf()->sgetn((char*)&_value,sizeof(T));
      inStream.rdbuf()->sgetn((char*)&_limitsSize,sizeof(int));
      if (_limits != NULL)
        delete[] _limits;
      _limits = new T[_limitsSize];
      for (int i=0; i<_limitsSize; i++)
        inStream.rdbuf()->sgetn((char*)&_limits[i],sizeof(T));
      return ScsValid;
    };

  // limits
  // set
  virtual void setLimits(T*  inValueLimits,
			 int inLimitsSize)
    {
      if (_limitsSize != inLimitsSize)
      {
        _limitsSize = inLimitsSize;
        if (_limits!=NULL)
        {
          delete[] _limits;
        }
        _limits = new T[_limitsSize];
      }
      for (int i=0; i<_limitsSize; i++)
        _limits[i] = inValueLimits[i];
    };
  // get limits's list 
  const T* getLimits() const
    {
      return _limits;
    };
  // get limits's size 
  int getLimitsSize() const
    {
      return (_limitsSize);
    };
  // get one value of limits array
  const T getLimit(int inIndex) const
    {
      if ((inIndex>0)&&(inIndex<_limitsSize))
        return _limits[inIndex];
      else
        return _limits[0];
    }
  // value
  void setValue(T inNewValue)
    {
      update(inNewValue);
      _value = inNewValue;
    };
  // get
  const T getValue() const
    {
      return _value;
    };
  // 

  int getDomain(const T inValue,
		const T inHisteresis = 0) const
    {
      int domain = -1;
      while ( (++domain<_limitsSize) && (_limits[domain]-inValue<inHisteresis) );
      // ESA - 30/08/2006 - range domain must be [1;5] whereas the domain found in the array is [0;4], it 
      // must be incremented.
      return ++domain;
    };

  virtual int compare(const T   inNewValue,
		      const T*  inLimits,
		      const int inLimitsSize) const
    {
      int result = 0;
      if (_value == inNewValue)
	{
        if (_limitsSize == inLimitsSize)
        {
          int index     = 0;
          int condition = 1;
          while ( (index<_limitsSize) && (condition == 1))
          {
            if (_limits[index]!=inLimits[index])
              condition = 0;
            else
              index++;
          }
          if (condition == 1)
            result = 1;
        }
      }
      return result;
    };

  virtual int BSFire(T inNewValue ) = 0;
  inline virtual void update(T inNewValue) { BSFire( inNewValue ); };

 protected:
  // automaton instance pointer
  inline void * getPointer() const 
    {
      return (void *) this;
    };
  // to set value without updating
  inline void setValueWithoutUpdating(T inNewValue) { _value = inNewValue; };
};

// compiler specific
#ifdef HPUX11
template class ScsBasicValue<long>;
template class ScsBasicValue<double>;
#endif
#ifdef OSF1
#pragma instantiate ScsBasicValue<long>
#pragma instantiate ScsBasicValue<double>
#endif

// class for long type: digital value
typedef ScsBasicValue<long> ScsBasicDIValue;
// class for double type: analog value
typedef ScsBasicValue<double> ScsBasicAIValue;

#endif
// SCSBASICVALUE_H

// end of file scsbasicvalue.h
