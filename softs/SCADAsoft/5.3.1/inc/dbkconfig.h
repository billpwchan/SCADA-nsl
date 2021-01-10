//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : dbkconfig.h                                            */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon May 05 16:24:11 2003                               */
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


#ifndef _SCS_DBKCONFIG_H_
#define _SCS_DBKCONFIG_H_

#include <float.h>

#if defined(HPUX11) || defined(OSF1)
#define DBKUSE64
#endif

#if defined(HPUX11) && defined (__LP64__)
#define DBKADDRESSID64
#endif
#if defined(OSF1) && defined(__arch64__)
#define DBKADDRESSID64
#endif

#ifdef WIN32
#define M_PI          3.14159265358979323846
#define M_PI_2        1.57079632679489661923
#define M_PI_4        0.78539816339744830962
#define M_1_PI        0.31830988618379067154
#define M_2_PI        0.63661977236758134308
#endif

#define DbkEpsilonFloat        FLT_EPSILON
#define DbkEpsilonDouble	   DBL_EPSILON

#define DBK_NOREPLICATED		0
#define DBK_REPLICATED			1

#define DBK_GOOD			0
#define DBK_BAD				1

#define SAVE_PTR			0
#define NO_SAVE_PTR			1

#define DBMDIRECTDATA_VERSION_ID        0

#define DBK_STATIC				0
#define DBK_VOLATILE			1
#define DBK_HISTORIC_ST			2
#define DBK_HISTORIC_MT			3
#define DBK_HISTORIC_CHB		4

#define DBK_BOOLEAN				0
#define DBK_UINT8				1
#define DBK_INT8				2
#define DBK_UINT16				3
#define DBK_INT16				4
#define DBK_UINT32				5
#define DBK_INT32				6
#define DBK_UINT64				7
#define DBK_INT64				8
#define DBK_FLOAT				9
#define DBK_DOUBLE				10
#define DBK_COMPLEX				11
#define DBK_CHARN				12
#define DBK_REFERENCE			13
#define DBK_DATE				14
#define DBK_VECTOR				15
#define DBK_VECTORSTRUCT		16
#define DBK_UNKNOWN				17
#define DBK_BITFIELD			18
#define DBK_SHORTDATE			19

#define DBK_VECTOR_PTR			100
#define DBK_CHARN_PTR			101
#define DBK_BITFIELD_PTR		102
#define DBK_DATE_PTR			103

#define DBK_NBATTRCHANGE		0
#define DBK_NBINSTCHANGE		1

#define DBK_TOPCPBRANCH			0
#define DBK_INCPBRANCH			1

#define DBK_SIMPLE_ELMT			0
#define DBK_COMPOSED_ELMT		1

//#ifdef DB_NTPSERVER
#define DBK_DIGITAL_VALUE		0
#define DBK_ANALOGICAL_VALUE		1
//#endif


// Chose number of contexts
//#define DBK_NUM_CONTEXTS		2
// Chose number of restitutions short term
#define DBK_NUM_RESTI_ST		2
// Chose number of restitutions middle term
#define DBK_NUM_RESTI_MT		2
#define DBK_CONTEXT_0			1
#define DBK_FISRT_USER_CONTEXT		1


/***********************************************************************/
/* CONFIG NUMCONTEXT = 4, 4 Short Term restitution buffer : config SRC */
/***********************************************************************/


/* PATH */

#define SCS_PATH "SCSPATH"
#define SCS_HOME "SCSHOME"

/* QUALITY */

#define DBK_QUALITY_OK							0
#define DBK_QUALITY_SUSPECT						1
#define DBK_QUALITY_ERROR						2
#define DBK_QUALITY_DISABLED					3

/* ALARM */
#define ALARM_BUFFER_SIZE                                              50

/* LSTSERVER */
#define DBK_LISTMODIFIEDVALUES  50000

/* FORMULA ACTIVATION */
#define DBK_NB_FORMULA_STATE					2   // doit rester à 2 pour l'ordre d'activation. Sinon changer le code d'activation des formules.

#define DBK_ENABLE								0
#define DBK_DISABLE								1
#define DBK_ENABLE_OPT							2

#ifdef DB_HISTORIZE

#define TABLE_PATH  ":history server:history table";
#define READIX_PATH  ":history server:read index";
#define WRITEIX_PATH ":history server:write index";
#define CYCLE_PATH ":history server:cycle";

#define FIELD_FOR_TIME_HISTORISATION                                    0
#define FIELD_FOR_VALUE_HISTORISATION                                   3


enum ActivationFormula{
	ENABLE,
	DISABLE
};

#endif
#endif
