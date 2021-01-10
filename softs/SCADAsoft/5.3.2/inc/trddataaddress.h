/******************************************************************************/
/*                                                                            */
/*  FILE                : trddataaddress.h                                    */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY             : THALES IS                                           */
/*  CREATION DATE       : 1997/09/30                                          */
/*  LANGUAGE            : C++                                                 */
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
/******************************************************************************/
// IDENTIFICATION:
// $Id: trd.h,v 1.14 2000/02/01 15:35:22 scadaref Exp $
//
// HISTORY:
// $Log: trd.h,v $

#ifndef _TRDDATAADDRESS_H_
#define _TRDDATAADDRESS_H_

class ScsString;

class TRD_API TrdDataAddress
{
 public:
  TrdDataAddress (const char* archiveName, const char* attributeName, long tMin = 0, long tMax = 0, long offset = 0);
  TrdDataAddress(const TrdDataAddress& trdDataAddress);
  ~TrdDataAddress();

  const char* getArchiveName () const;
  const char* getAttributeName () const;
  long getTimeMin() const { return _tMin; }
  long getTimeMax() const { return _tMax; }
  long getTimeOffset() const { return _offset; }

 private:
  ScsString *_archiveName;
  ScsString *_attributeName;

  // FFT SRC 172
  long _tMin;
  long _tMax;
  long _offset;
};

////////////////////////////////////////////////////////////////
// Gestion des listes
////////////////////////////////////////////////////////////////
class TrdDataAddressRWGSlist;
class TrdDataAddressRWGSlistIterator;

class TRD_API TrdDataAddressList
{
public:
  TrdDataAddressList();
  TrdDataAddressList(const TrdDataAddressList& trdDataAddressList);
  ~TrdDataAddressList();

  int entries() const;
  const TrdDataAddress* at(int index) const;
  TrdDataAddress* append (TrdDataAddress* address);

  friend class TrdDataAddressListIt;
private:
  TrdDataAddressRWGSlist* _dataAddresses;
};

class TRD_API TrdDataAddressListIt
{
public:
  TrdDataAddressListIt(const TrdDataAddressList& dataAddressList);
  ~TrdDataAddressListIt();
  
  TrdDataAddress* operator() ();
  TrdDataAddress* key() const;
private:
  TrdDataAddressRWGSlistIterator* _it;
};
#endif
