/******************************************************************************/
/*									      */
/*  FILE		: scsDBConst.h	                                      */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 2000/02/04					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Defines for Rtap database class numbers and constantes                */
/*	                                				      */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
/* IDENTIFICATION:                                                            */
/* $Id$                                                                       */
/*                                                                            */
/* HISTORY:                                                                   */
/* $Log$                                                                      */
/******************************************************************************/
#ifndef _SCSDBCONST_H
#define _SCSDBCONST_H

/* Class numbers */
#define SCS_K_CLASS_NULL	0
#define SCS_K_CLASS_EQ		1020
#define SCS_K_CLASS_SUPER	2000
#define SCS_K_CLASS_DIO		105
#define SCS_K_CLASS_DOV		110
#define SCS_K_CLASS_AIO		108
#define SCS_K_CLASS_SIO		109
#define SCS_K_CLASS_DII		104
#define SCS_K_CLASS_AII		106
#define SCS_K_CLASS_SII		107
/* Class for unified MCD */
#define SCS_K_CLASS_CDI SCS_K_CLASS_DII
#define SCS_K_CLASS_DAC 100 + SCS_K_CLASS_CDI
#define SCS_K_CLASS_DCO 200 + SCS_K_CLASS_CDI
#define SCS_K_CLASS_DFO 300 + SCS_K_CLASS_CDI
#define SCS_K_CLASS_DES 400 + SCS_K_CLASS_CDI
#define SCS_K_CLASS_DAL 500 + SCS_K_CLASS_CDI

#define SCS_K_CLASS_CAI SCS_K_CLASS_AII
#define SCS_K_CLASS_AAC 100 + SCS_K_CLASS_CAI
#define SCS_K_CLASS_ACO 200 + SCS_K_CLASS_CAI
#define SCS_K_CLASS_AFO 300 + SCS_K_CLASS_CAI
#define SCS_K_CLASS_AES 400 + SCS_K_CLASS_CAI
#define SCS_K_CLASS_AAL 500 + SCS_K_CLASS_CAI

// ESA 26-02-07 : class Id of SCO and SFO classes must be respectively 307 and 407.
#define SCS_K_CLASS_CSI SCS_K_CLASS_SII
#define SCS_K_CLASS_SAC 100 + SCS_K_CLASS_CSI
#define SCS_K_CLASS_SCO 200 + SCS_K_CLASS_CSI
#define SCS_K_CLASS_SFO 300 + SCS_K_CLASS_CSI

#endif
