/* -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [TOOLS]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: terror.h
//  description: Common include file of the error message file
//               compiler and interpreter.
//     creation: 1997/05/12
//       author: olivier
// --------------------------------------------------------------------------
// $Id: error.h,v 1.2 1999/02/15 14:40:33 ylo Exp $
//
// $Log: error.h,v $
// Revision 1.2  1999/02/15 14:40:33  ylo
// *** empty log message ***
//
// Revision 1.1  1998/11/23 14:37:19  scadaref
// Initial revision
//
// Revision 1.2  1997/11/14 10:28:22  olivier
// 2
//
// Revision 1.1  1997/11/13 10:36:08  olivier
// Initial revision
//
// Revision 1.11  1997/07/07 16:15:10  olivier
// .
//
// Revision 1.10  1997/07/07 15:59:06  olivier
// Rename extrnal symbols yyXXXXX to AntError_yyXXXX.
//
// Revision 1.9  1997/07/07 15:34:04  olivier
// .
//
// Revision 1.8  1997/06/10 10:07:24  olivier
// clean compilation warning on NT.
//
// Revision 1.7  1997/05/30 11:26:45  olivier
// Portability on WINDOWS/NT.
//
// Revision 1.6  1997/05/23 15:52:18  olivier
// *** empty log message ***
//
// Revision 1.5  1997/05/23 15:23:01  olivier
// *** empty log message ***
//
// Revision 1.4  1997/05/23 09:57:45  olivier
// *** empty log message ***
//
// Revision 1.3  1997/05/15 16:14:15  olivier
// *** empty log message ***
//
// Revision 1.2  1997/05/14 16:06:31  olivier
// *** empty log message ***
//
// Revision 1.1  1997/05/14 11:08:57  olivier
// Initial revision
//
//
// --------------------------------------------------------------------------*/
#ifndef _AN_TERROR_H
#define _AN_TERROR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WINDOWS
#include <process.h>
#endif
//{begin macro}

#define ANT_COPY_STRING_TOKEN(token, token1)    \
                    token[0] = 0;               \
                    strcpy(token, token1)

#define ANT_CONCAT_STRING_TOKEN(token, token1, token2)  \
                    token[0] = 0;                       \
                    strcpy(token, token1);              \
                    strcat(token, token2)

#define STRING_TOKEN_LENGTH     512
//{end macro}

#include "ant/defs.h"

extern "C"
{
extern int AntError_yyerror(char *);
//extern int AntError_yylex();
extern int AntError_yyparse();
extern int AntError_yywrap();
}
extern char *AntError_yytext;
extern int AntError_yylineno;          /* line number */
extern FILE *AntError_yyin;
extern FILE *AntError_yyout;


extern SCSERROR_API void ant_component_rule1(char* token3, char* token5);
extern SCSERROR_API void ant_one_format_rule1(char* token1, char* token3);
extern SCSERROR_API void ant_one_error_rule1(char* token1, char* token3);
extern SCSERROR_API void ant_error_name_rule1(char* token, char* token1);
extern SCSERROR_API void ant_types_rule1(char* token);
extern SCSERROR_API void ant_types_rule2(char* token, char* token1);
extern SCSERROR_API void ant_types_rule3(char* token, char* token1, char* token3);
extern SCSERROR_API void ant_type_rule1(char* token, char* token1);
extern SCSERROR_API void ant_type_rule2(char* token, char* token2);
extern SCSERROR_API void ant_type_rule3(char* token, char* token1);
extern SCSERROR_API void ant_type_rule4(char* token, char* token2);
extern SCSERROR_API void ant_type_rule5(char* token, char* token1);
extern SCSERROR_API void ant_type_rule6(char* token, char* token2);
extern SCSERROR_API void ant_type_rule7(char* token, char* token3);

#endif
