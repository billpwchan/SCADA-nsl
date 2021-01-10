//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scsuserstatus.h                                        */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : Y. Lozinguez                                           */
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : Thu Apr 21 15:34:08 2005                               */
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


#ifndef _SCS_SCSUSERSTATUS_H_
#define _SCS_SCSUSERSTATUS_H_

//{begin internal}
#include "scsdata.h"
//{end internal}

/**
   \brief This class is .

   The class <em>ScsUserStatus</em> aggregates an error code and an error message. It is provided to allow applications to report error message from a server process to a client process. It may be used in conjonction with the "scsmkerror -u" utility.
\code#include "scsuserstatus.h"\endcode
*/
class SCSERROR_API ScsUserStatus : public ScsStatus {
 public:
  /**@name General member functions*/
  //@{
  /**
     .
     \par Description:
     Default constructor.
  */
  ScsUserStatus();
  /**
     .
     \par Description:
     Aggregates an ScsStatus and a message. The message is duplicated.
  */
  ScsUserStatus(const ScsStatus& status, const char* message = 0);
  /**
     .
     \par Description:
     Copy constructor. The message is duplicated.
  */
  ScsUserStatus(const ScsUserStatus&);
  /**
     .
     \par Description:
     Default destructor.
  */
  ~ScsUserStatus();
  //@}

  /**
     .
     \par Description:
     Assignement operator. The message is duplicated.
     \param us  [in]: ScsUserStatus to copy.
     \return this
  */
  ScsUserStatus& operator=(const ScsUserStatus& us);
  //@}
  
  /**@name General member functions*/
  //@{
  /**
     .
     \par Description:
     Get the message string.
     \return
     the current message string or 0 if none.
  */
  const char* getMessage() const;
  /**
     .
     \par Description:
     Replace the message by the new ones.
     \param message  [in]: the new message.
     \return
     void
  */
  void setMessage(const char*);
  //@}

 private:
  char* _message;
};

#endif
