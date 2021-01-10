/******************************************************************************/
/*									      */
/*  FILE		: dac.h                                               */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1999/12/2					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Definition of C++ class DacServer providing ORB client access to    */
/*	the DAC component server (daccontrol process)                         */
/*	An object of such a class must be built be the client process in      */
/*	order to access services to this component                            */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
// IDENTIFICATION:
// $Id$
//
// HISTORY:
// $Log$
/******************************************************************************/
#ifndef _DAC_H_
#define _DAC_H_

/** \file
  \brief DacServer Classes definition providing ORB client access to
         the DAC component server (daccontrol process)

   An object of such a class must be built be the client process in 
   order to access services to this component
 */

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"
#include "manager.h"

class ScsString;

#define DacTrace ScsTraceFunction(DAC_SCSMODULE)
#define DacTraceLevel(level, message) BaseTraceLevel(DAC_SCSMODULE, level, message)

/************************************************************************/
//                                                                      //
//                       VARIABLES                                      //
//                                                                      //
/************************************************************************/

/**
   Max length for the name of an external input or output variable.
\code#include "dac.h"\endcode
*/
#define DAC_K_MAXLEN_EV_NAME	65

/** External variable name (DAC component).
\code#include "dac.h"\endcode
   This type is used to store the name of an external variable (EV).
   Its maximum length is DAC_K_MAXLEN_EV_NAME-1.
*/
typedef char DacEVName[DAC_K_MAXLEN_EV_NAME];

/************************************************************************/
//                                                                      //
//                       DacEIV CLASS                                   //
//                                                                      //
/************************************************************************/

/**
   \brief External input variable (EIV) definition for the <em>DAC</em> component.

   This class is used to describe a variable received from an equipment. 
   The DacServer sends or receives external input variable lists.
   The variables can be of any type : int, float, bit fields.
\code#include "dac.h"\endcode
*/
class DAC_API DacEIV
{
public:
  /**@name Typedefs / defines*/
  //@{
  /** 
      \par Description:
     enum corresponding to the possible values for the current status of an external input variable.
      \code
      enum Status { 
         UNDEFINED = 0,
         VALID,
         INVALID_LINK,
         INVALID_INTERNAL,
         INVALID_RANGE,
         INVALID_GETTING,
         INVALID_CHATTERING,
         INVALID_INTERNAL_VALID,
         INVALID_INTERNAL_LINK,
         INVALID_INTERNAL_RANGE,
         INVALID_INTERNAL_GETTING,
         INVALID_INTERNAL_CHATTERING
      }; \endcode
      \par Values:
      \li \c UNDEFINED:  the status of the equipment associated with the variable is undefined.
      \li \c VALID:  the value of the variable is valid. The RTU associated to the variable is in the <em>INS</em> state and a value has been received from this RTU for the variable.
      \li \c INVALID_LINK:  data exchanges with the RTU associated to the variable are not possible. The value of the variable is the last received for the variable. Do not test directly this state, use isInvalidInternal() method.
      \li \c INVALID_INTERNAL:  the variable has been invalidated.
      \li \c INVALID_RANGE:  the value is wrong for the verification function.
      \li \c INVALID_CHATTERING:  the value is invalidated by the IO toggling detection algorithm.
      \li \c INVALID_INTERNAL_VALID: variable invalidated with a previous state VALID.
      \li \c INVALID_INTERNAL_LINK: variable invalidated with a previous state INVALID_LINK.
      \li \c INVALID_INTERNAL_RANGE: variable invalidated with a previous state INVALID_RANGE.
      \li \c INVALID_INTERNAL_GETTING: variable invalidated with a previous state INVALID_GETTING.
      \li \c INVALID_INTERNAL_CHATTERING: variable invalidated with a previous state INVALID_CHATTERING.
  */
  enum Status { 
    UNDEFINED = 0,
    VALID,
    INVALID_LINK,
    INVALID_INTERNAL,
    INVALID_RANGE,
    INVALID_GETTING,
    INVALID_CHATTERING,
    INVALID_INTERNAL_VALID,
    INVALID_INTERNAL_LINK,
    INVALID_INTERNAL_RANGE,
    INVALID_INTERNAL_GETTING,
    INVALID_INTERNAL_CHATTERING
  };

  static const char* StatusToText(Status s);
  /** 
      \par Description:
     enum corresponding to the possible values for the type of an external input variable.
      \code
      enum Status { 
         UNDEFINED_TYPE = 0,
         DEIV,
         AEIV,
         SEIV
      }; \endcode
      \par Values:
      \li \c UNDEFINED_TYPE: unknown type, or not already set
      \li \c DEIV: digital external input variable: integer.
      \li \c AEIV: analogic external input variable: float.
      \li \c SEIV: structured external input variable: bit field.
  */
  enum EivType
  {
    UNDEFINED_TYPE = 0,
    DEIV,
    AEIV,
    SEIV
  };
  //@}

  /**@name Constructors / destructor*/
  //@{

  /**
     \par Description:
     default constructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  DacEIV();

  /**
     \par Description:
     constructor. This function creates a discrete external input variable object (DEIV).
     \param identifier  [in]: identifier of the variable. It is defined by the <em>DacServer::subscribeEIV()</em> function.
     \param value  [in]: value of the variable, of integer type.
     \param status  [in]: status of the variable, by default UNDEFINED. 
     \param sec  [in]: acquisition or modification time (seconds) associated with the value. 
     \param msec  [in]: acquisition or modification time (microseconds) associated with the value. 
     \par Return values:
     none.
  */
  DacEIV( const unsigned int identifier, const int value, const Status status = UNDEFINED,
	  const unsigned long sec = 0, const unsigned long msec = 0 );
  /**
     \par Description:
     constructor. This function creates an analog external input variable object (AEIV).
     \param identifier  [in]: identifier of the variable. It is defined by the <em>DacServer::subscribeEIV()</em> function.
     \param value  [in]: value of the variable, of  float type.
     \param status  [in]: status of the variable, by default UNDEFINED. 
     \param sec  [in]: acquisition or modification time (seconds) associated with the value. 
     \param msec  [in]: acquisition or modification time (microseconds) associated with the value. 
     \par Return values:
     none.
  */
  DacEIV( const unsigned int identifier, const float value, const Status status = UNDEFINED,
	  const unsigned long sec = 0, const unsigned long msec = 0 );
  /**
     \par Description:
     constructor. This function creates a structured external input variable object (SEIV).
     \param identifier  [in]: identifier of the variable. It is defined by the <em>DacServer::subscribeEIV()</em> function.
     \param value  [in]: value of the variable, of bit field type.
     \param size  [in]: value size in bytes.
     \param status  [in]: status of the variable, by default UNDEFINED. 
     \param sec  [in]: acquisition or modification time (seconds) associated with the value. 
     \param msec  [in]: acquisition or modification time (microseconds) associated with the value. 
     \par Return values:
     none.
  */
  DacEIV( const unsigned int   identifier,
	  const unsigned char* value,
	  const unsigned int   size,
	  const Status         status = UNDEFINED,
	  const unsigned long  sec = 0,
	  const unsigned long  msec = 0 );

   DacEIV(const DacEIV&);
   
  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~DacEIV();
  //@}

  /**@name General member functions */
  //@{
  /** returns the variable identifier. */
  inline int getId() const;
  /** sets the variable identifier. */
  inline void setId(int id);

  /** returns the variable type. */
  inline EivType getType() const ;

  /** returns the variable data containing value. */
  inline ScsData getData() const ;
  
  /** returns the variable name. */
  inline char* getName() const ;

  /** 
      \par Description:
     assignment of the variable name.
      \param name  [in]: name of the variable.
      \par Return values:
     none.
  */
  inline void setName( const char* name );

  /** 
     \par Description:
     assignment of a DEIV value, the status is set to VALID.
     \param val  [in]: value of the integer variable.
     \par Return values:
     none.
  */
  void setValue( const int val );

  /**
     \par Description:
     assignment of an AEIV value, the status is set to VALID.
     \param val  [in]: value of the float variable.
     \par Return values:
     none.
  */
  void setValue( const float val );

  /**
     \par Description:
     assignment of a SEIV value, the status is set to VALID.
     \param val  [in]: pointer to a buffer.
     \param size  [in]: length of the buffer, in bytes.
     \par Return values:
     none.
  */
  void setValue( const unsigned char* val, const unsigned int size );

  /**
     \par Description:
     assignment of a value of type ScsData, the status is set to VALID.
     \param val  [in]: reference to an ScsData.
     \par Return values:
     none.
  */
  void setValue( const ScsData& val );

  /** returns the variable status. */
  inline Status getStatus() const ;

  /**
     \par Description:
     assignment of a status.
     \param state  [in]: status to assign to the variable.
     \par Return values:
     none.
  */
  void setStatus( Status state ); 

  /**
     \par Description:
     Check if variable is invalidated.
     \par Return values:
     1 if variable state is one of INVALID_INTERNAL Status, 0 if not
  */
  int isInvalidInternal() const;
  
  /**
     \par Description:
     Change state to INVALID_INTERNAL + previous state.
     For exemple if state was INVALID_LINK the new state is INVALID_INTERNAL_LINK.
     \par Return values:
     none.
  */
  void setInvalidInternal();
  
  /**
     \par Description:
     Change state to previous set (before setInvalidInternal()).
     \par Return values:
     none.
  */
  void unsetInvalidInternal();
  

  /**
     \par Description:
     set the external data acquisition time.
     \param sec  [in]: seconds since 00:00 Coordinated Universal Time (UTC), January 1, 1970.
     \param usec [in]: microseconds.
     \par Return values:
     none.
  */
  void setAcqTime(unsigned long sec, unsigned long usec); 
  
  /**
     \par Description:
     get the external data acquisition time.
     \param sec  [out]: seconds since 00:00 Coordinated Universal Time (UTC), January 1, 1970.
     \param usec [out]: microseconds.
     \par Return values:
     none.
  */
  void getAcqTime(unsigned long *sec, unsigned long *usec); 

  /** write a variable with the trace level given in parameter . */
  void debugTrace( int level ) ;
  //@}


  /**@name Operators / cast */
  //@{
  /** assignment operator. */
  DacEIV& operator=( const DacEIV& arg );
  /** comparison operator. */
  int operator==( const DacEIV& arg ) const ;
  //@}

  /**@name Save / restore methods */
  //@{
  /** save in a stream. */
  void save(SCS_SL_STD(ostream)& os,bool optimized=false) const;    // if optimized, the name is not serialized
  /** restore from the stream. */
  void restore(SCS_SL_STD(istream)& is,bool optimized=false);   // if optimized, the name is not deserialized
  //@}

private:
  //. Identifier number of the external input variable
  int     _id;
  //. Current status of the external input variable
  Status  _status;
  //. Type of the variable
  EivType _type ;
  //. Value of the variable
  ScsData _value;
  //. Date d'acquisition
  unsigned long _sec, _microsec;
  //. Name of the external input variable
  DacEVName     _name;
};

/************************************************************************/
//                                                                      //
//                   INLINE METHODS FOR DacEIV CLASS                    //
//                                                                      //
/************************************************************************/

int DacEIV::getId() const
{
  return( _id );
}

void DacEIV::setId(int id)
{
  _id = id;
}

DacEIV::Status DacEIV::getStatus() const
{
  return( _status );
}

DacEIV::EivType DacEIV::getType() const
{
  return( _type );
}

ScsData DacEIV::getData() const
{
  return( _value );
}

void DacEIV::setName( const char* name )
{
  strcpy( _name, name );
}

char* DacEIV::getName() const
{
  return( (char*) _name );
}

/************************************************************************/
//                                                                      //
//                       DacEOV CLASS                                   //
//                                                                      //
/************************************************************************/

/**
   \brief External output variable (EOV) definition for the <em>DAC</em> component.

   This class is used to describe a command to send to an equipment. A command corresponds to an external output variable. 
   This class is used by the DacServer methods to send or receive
   external output variable lists, where variables can be of any type: int, float, bit fields.
\code#include "dac.h"\endcode
*/

class DAC_API DacEOV
{
public:
  /**@name Typedefs / defines*/
  //@{
  /** 
      \par Description:
     enum corresponding to the possible values for the type of an external output variable.
      \code
      enum Status { 
         UNDEFINED_TYPE = 0,
         DEOV,
         AEOV,
         SEOV
      }; \endcode
      \par Values:
      \li \c UNDEFINED_TYPE:  unknown type, or not already set.
      \li \c DEOV:  digital external output variable : integer.
      \li \c AEOV:  analogic external output variable : float.
      \li \c SEOV: structured external output variable : bit field.
  */
  enum EovType
  {
    UNDEFINED_TYPE = 0,
    DEOV,
    AEOV,
    SEOV
  };
  //@}

  /**@name Constructors / destructor*/
  //@{
  /** 
      \par Description:
     default constructor.
      \par Parameters:
     none.
      \par Return values:
     none.
  */
  DacEOV();

  /** 
      \par Description:
     constructor. This function creates a discrete external output variable object (DEOV).
      \param name  [in]: name of the variable. It is defined by the <em>DacServer::sendEOV()</em> function.
      \param value  [in]: value of the variable, of integer type.
      \par Return values:
     none.
  */
  DacEOV( const char* name, const int value );

  /** 
      \par Description:
     constructor. This function creates an analog external output variable object (AEIV).
      \param name  [in]: name of the variable. It is defined by the <em>DacServer::sendEOV()</em> function.
      \param value  [in]: value of the variable, of float type.
      \par Return values:
     none.
  */
  DacEOV( const char* name, const float value );

  /** 
      \par Description:
     constructor. This function creates a structured external output variable object (SEIV).
      \param name  [in]: name of the variable. It is defined by the <em>DacServer::sendEOV()</em> function.
      \param value  [in]: value of the variable, of bit field type.
      \param size  [in]: length of the value, in bytes.
      \par Return values:
     none.
  */
  DacEOV( const char *name, const unsigned char* value, const unsigned int size );

  /** 
      \par Description:
     destructor.
      \par Parameters:
     none.
      \par Return values:
     none.
  */
  ~DacEOV();
  //@}

  /**@name General member functionss */
  //@{
  /** returns the variable name. */
  inline char* getName() const ;

  /** 
      \par Description:
     assignment of the variable name.
      \param name  [in]: name of the variable.
      \par Return values:
     none.
  */
  inline void setName( const char* name );

  /** returns the variable type. */
  inline EovType getType() const ;

  /** returns the variable data containing value. */
  inline ScsData getData() const ;

  /** 
      \par Description:
     assignment of a DEOV value.
      \param val  [in]: value of the integer variable.
  */
  void setValue( const int val );

  /** 
      \par Description:
     assignment of a AEOV value.
      \param val  [in]: value of the float variable.
  */
  void setValue( const float val );

  /** 
      \par Description:
     assignment of a SEOV value.
      \param val  [in]: pointer to a buffer.
      \param size  [in]: length of the buffer, in bytes.
  */
  void setValue( const unsigned char *val, const unsigned int size );

  /**
     \par Description:
     assignment of a value of type ScsData, the status is set to VALID.
     \param val  [in]: pointer to a ScsData.
  */
  void setValue( const ScsData& val );

  /** write a variable with the trace level given in parameter. */
  void debugTrace( int level ) ;
  //@}

  /**@name Operators / cast */
  //@{
  /** assignment operator. */
  DacEOV& operator=( const DacEOV& arg );
  //@}

  /**@name Save / restore methods */
  //@{
  /** save in a stream. */
  void save( SCS_SL_STD(ostream)& os ) const;
  /** restore from the stream. */
  void restore( SCS_SL_STD(istream)& is );
  //@}

private:
  //. Comparison operator
  int operator==( const DacEOV& arg ) const ;

  friend class DacCtlOutVariable;
  
  /**
     \par Description:
     Reset the internal value i.e. assigned with a ScsUNKNOWN data.
  */
  void reset();

  //. Name of the external output variable
  DacEVName     _name;
  //. Type of the variable
  EovType       _type ;
  //. Value of the variable
  ScsData       _value;
};

/************************************************************************/
//                                                                      //
//                   INLINE METHODS FOR DacEOV CLASS                    //
//                                                                      //
/************************************************************************/

char* DacEOV::getName() const
{
  return( (char*) _name );
}

ScsData DacEOV::getData() const
{
  return( _value );
}

DacEOV::EovType DacEOV::getType() const
{
  return( _type );
}

void DacEOV::setName( const char* name )
{
  strcpy( _name, name );
}

/************************************************************************/
//                                                                      //
//              PROTOTYPE FOR EIV NOTIFICATION CALLBACK                 //
//                                                                      //
/************************************************************************/

/**
   Prototype of the external input variable (EIV) notification callback function.
\code#include "dac.h"\endcode
   \par Description:
     This function is a function of the client application for external input variables notification. A client can subscribe to the DACCONTROL server to a list of external input variables, and the server will call this callback function to asynchronously notify the client about changes in values or statuses of the external input variables the client subscribed to. 
   \param subscriptionId  [in]: identifier of the subscription.
   \param eivCount  [in]: number of external input variables (EIV).
   \param eivList  [in]: list of external input variables.
   \param usrArg  [in]: user optional argument (not used by DAC component). This argument is given by the client when it calls the subscription function and returned to it when the current callback function is called by the DAC component. This parameter is optional, but, if set, could be used to give back information to the client.
   \par Return values:
     none.
*/
typedef void (*DacUpdateCallback)(unsigned int     subscriptionId,
				  unsigned int     eivCount,
				  DacEIV*          eivList,
				  ScsAny           usrArg);


class DacServerProxy;
class DacClientIdl_i;

/**
   \brief Interface class for the exported services of the <em>DAC</em> component.

   This class is the interface class for the services exported by the DACCONTROL server. It is used to send a list of commands or external output variables (EOV) or to subscribe or unsubscribe to external input variables (EIV). 
\code#include "dac.h"\endcode
*/
class DAC_API DacServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /** 
      \par Description:
     constructor. This function creates an interface object connected to the DACCONTROL server.
      \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required DACCONTROL server is running.
      \param updateCallback  [in]: address of the notification callback function which will be used to notify a client of the new value of external input variables.
     \param priority  [in]: priority of the messages to the DacServer (only useful with redudancy).
      \par Return values:
     none. The result of the connection could be obtain by calling the <em>getStatus()</em> function.
  */
  DacServer(const char *logicalEnv,
	    DacUpdateCallback updateCallback = NULL,
	    ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);

  /** 
      \par Description:
     destructor. This function closes the connection with the DACCONTROL server.
      \par Parameters:
     none.
      \par Return values:
     none.
  */
  ~DacServer();
  //@}

  /**@name General member functions*/
  //@{ 
  /** 
      \par Description:
     return the status of the connection to the DACCONTROL server process.
      \par Parameters:
     none.
      \return
      \li \c ScsValid : success.
      \li \c DacHostServerError : cannot connect with the <em>ascmanager</em> process.
      \li \c DacORBError : cannot connect with the remote DACCONTROL server.
  */
  ScsStatus getStatus() const;

  /**
     \par Description:
     this function deactivates the embedded CORBA services.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
  */
  ScsStatus deactivate();
  
  /** 
      \par Description:
     this function sends a list of commands or external output variables (EOV) to execute.
      \param eovCount  [in]: number of EOVs in the list.
      \param eovList  [in]: list of EOVs.
      \param statusList [out]: list of returned statuses.
      \return
      \li \c ScsValid : success.
      \li \c DacORBError : ORB communication error (exception raised).
  */
  ScsStatus sendEOV(unsigned int  eovCount,
		    DacEOV       *eovList,
		    ScsStatus    *&statusList);

  /** 
      \par Description:
     this function initiates a subscription to a set of external input variables (EIV).
      \param eivCount  [in]: number of EIVs in the following list.
      \param eivNames  [in]: list of EIV names.
      \param eivList  [out]: list of EIV identifiers and values.
      \param subscriptionId  [out]: subscription identifier.
      \param usrArg  [in]: user argument (not used by DAC component). This argument is returned to the client when the notification callback function is called by the DAC component. This parameter is optional, but, if set, could be used to give back information to the client.
      \return
      \li \c ScsValid : success.
      \li \c DacORBError : ORB communication error (exception raised).
  */
  ScsStatus subscribeEIV(unsigned int   eivCount,
			 DacEVName     *eivNames,
			 unsigned int  &subscriptionId,
			 DacEIV       *&eivList,
			 ScsAny         usrArg);
  
  /** 
      \par Description:
     this function cancels a subscription to a set of external input variables.
      \param subscriptionId  [in]: subscription identifier.
      \return
      \li \c ScsValid : success.
      \li \c DacORBError : ORB communication error (exception raised).
  */
  ScsStatus unsubscribeEIV(unsigned int subscriptionId);

  /** 
      \par Description:
     this function invalidates the notifications of EIVs to the requester client. This is used in clients which subscription phase is very long, at the beginning of this phase. It avoids ORB timeouts when DacControl server tries to notify EIVs during the subscription phase. The notifications could be revalidate at the end of the subscription phase using <em>revalidateNotifications()</em> function.
      \par Parameters:
     none.
      \return
      \li \c ScsValid : success.
      \li \c DacORBError : ORB communication error (exception raised).
  */
  ScsStatus invalidateNotifications();

  /**
     \par Description:
     this function revalidates the notifications of EIVs to the requester client, invalidated after a call to the <em>invalidateNotifications()</em> function.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c DacORBError : ORB communication error (exception raised).
  */
  ScsStatus revalidateNotifications();
    
  /**
     \par Description:
     return the logical SCADAsoft environment name of the DACCONTROL server to which the interface object is connected.
     \par Parameters:
     none.
     \par Return values:
     the name of the environment.
  */
  const char *getServerEnv();
  /** 
      \par Description:
     this function read a set of external input variables (EIV).
      \param eivCount  [in]: number of EIVs in the following list.
      \param eivNames  [in]: list of EIV names.
      \param eivList  [out]: list of EIV identifiers and values.
      \return
      \li \c ScsValid : success.
      \li \c DacORBError : ORB communication error (exception raised).
  */
  ScsStatus getEIV(unsigned int   eivCount,
		   DacEVName     *eivNames,
		   DacEIV       *&eivList);


  //@}

  ScsStatus getSubscriber(int    &count,
			  char **&clientList);

  inline ScsAny getArg() const;
  inline DacUpdateCallback getCallback() const;

private:
  ScsStatus nullSubscription();

  DacServerProxy     * _proxy;
  AscManager         * _ascMgr;
  ScsStatus            _status;
  DacClientIdl_i     * _client;
  DacUpdateCallback    _callback;
  ScsAny               _arg;
  ScsString          * _envName;
};

ScsAny DacServer::getArg() const
{
  return( _arg );
}

DacUpdateCallback DacServer::getCallback() const
{
  return( _callback );
}

#endif // _DAC_H_

