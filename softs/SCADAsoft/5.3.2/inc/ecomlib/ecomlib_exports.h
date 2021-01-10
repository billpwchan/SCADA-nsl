/******************************************************************************/
/*                                                                            */
/*  FILE                : ecomlib_exports.h                                   */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 02-01-10                                            */
/*  LANGUAGE            : C++                                                 */
/*............................................................................*/
/*  OVERVIEW : Windows DLL export/import macros definition.                   */
/*............................................................................*/
/*  CONTENTS                                                                  */
/******************************************************************************/
/* IDENTIFICATION:
 *
 * HISTORY:
 */
/******************************************************************************/

#ifndef __SCS_ecomlib_ECOMLIB_EXPORTS_H__
#define __SCS_ecomlib_ECOMLIB_EXPORTS_H__

#ifdef WIN32 
#  ifdef EXPORT_ECOMLIB_IF
#    define ECOMLIBIF_EXPORT __declspec(dllexport)
#  else
#    define ECOMLIBIF_EXPORT __declspec(dllimport)
#  endif
#else
#  define ECOMLIBIF_EXPORT
#endif

#endif
