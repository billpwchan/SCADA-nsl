/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/

/*
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
!! File automatically generated
!! by g:\bin\p530\bin\scsmkerror.exe
!! at Mon Jun 06 11:06:20 2016
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_LSTERROR_H
#define _AN_LSTERROR_H
static AntStatus LstInitError(AntStatus::AntError,2700);
inline AntStatus
LstErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","Init"));
  return LstInitError;
}
static AntStatus LstORBError(AntStatus::AntError,2701);
inline AntStatus
LstErrORB(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ORB",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ORB"),arg0);
  return LstORBError;
}
static AntStatus LstHostServerError(AntStatus::AntError,2702);
inline AntStatus
LstErrHostServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "HostServer",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","HostServer"),arg0);
  return LstHostServerError;
}
static AntStatus LstCreatorIdError(AntStatus::AntError,2703);
inline AntStatus
LstErrCreatorId(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CreatorId",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","CreatorId"),arg0);
  return LstCreatorIdError;
}
static AntStatus LstListNameError(AntStatus::AntError,2704);
inline AntStatus
LstErrListName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListName",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ListName"),arg0);
  return LstListNameError;
}
static AntStatus LstNameAlreadyExistsError(AntStatus::AntError,2705);
inline AntStatus
LstErrNameAlreadyExists(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NameAlreadyExists",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","NameAlreadyExists"),arg0);
  return LstNameAlreadyExistsError;
}
static AntStatus LstListNotFoundError(AntStatus::AntError,2706);
inline AntStatus
LstErrListNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListNotFound",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ListNotFound"),arg0);
  return LstListNotFoundError;
}
static AntStatus LstMaxListError(AntStatus::AntError,2707);
inline AntStatus
LstErrMaxList(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MaxList",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","MaxList"));
  return LstMaxListError;
}
static AntStatus LstBadListTypeError(AntStatus::AntError,2708);
inline AntStatus
LstErrBadListType(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadListType",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","BadListType"));
  return LstBadListTypeError;
}
static AntStatus LstAddEntryError(AntStatus::AntError,2709);
inline AntStatus
LstErrAddEntry(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AddEntry",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","AddEntry"));
  return LstAddEntryError;
}
static AntStatus LstDeleteEntryError(AntStatus::AntError,2710);
inline AntStatus
LstErrDeleteEntry(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DeleteEntry",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","DeleteEntry"));
  return LstDeleteEntryError;
}
static AntStatus LstRemoteAllocationError(AntStatus::AntError,2711);
inline AntStatus
LstErrRemoteAllocation(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoteAllocation",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","RemoteAllocation"));
  return LstRemoteAllocationError;
}
static AntStatus LstActionNotAllowedError(AntStatus::AntError,2712);
inline AntStatus
LstErrActionNotAllowed(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ActionNotAllowed",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ActionNotAllowed"));
  return LstActionNotAllowedError;
}
static AntStatus LstListNotErasableError(AntStatus::AntError,2713);
inline AntStatus
LstErrListNotErasable(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListNotErasable",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ListNotErasable"));
  return LstListNotErasableError;
}
static AntStatus LstListNotModifiableError(AntStatus::AntError,2714);
inline AntStatus
LstErrListNotModifiable(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListNotModifiable",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ListNotModifiable"));
  return LstListNotModifiableError;
}
static AntStatus LstUpdateDataError(AntStatus::AntError,2715);
inline AntStatus
LstErrUpdateData(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UpdateData",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","UpdateData"));
  return LstUpdateDataError;
}
static AntStatus LstUpdateConditionError(AntStatus::AntError,2716);
inline AntStatus
LstErrUpdateCondition(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UpdateCondition",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","UpdateCondition"));
  return LstUpdateConditionError;
}
static AntStatus LstCleanError(AntStatus::AntError,2717);
inline AntStatus
LstErrClean(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Clean",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","Clean"));
  return LstCleanError;
}
static AntStatus LstListListsError(AntStatus::AntError,2718);
inline AntStatus
LstErrListLists(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListLists",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ListLists"));
  return LstListListsError;
}
static AntStatus LstDeactivatingANotActivatedListError(AntStatus::AntError,2719);
inline AntStatus
LstErrDeactivatingANotActivatedList(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DeactivatingANotActivatedList",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","DeactivatingANotActivatedList"));
  return LstDeactivatingANotActivatedListError;
}
static AntStatus LstStateListCreationError(AntStatus::AntError,2720);
inline AntStatus
LstErrStateListCreation(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "StateListCreation",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","StateListCreation"));
  return LstStateListCreationError;
}
static AntStatus LstUserListCreationError(AntStatus::AntError,2721);
inline AntStatus
LstErrUserListCreation(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UserListCreation",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","UserListCreation"));
  return LstUserListCreationError;
}
static AntStatus LstXmlSaveError(AntStatus::AntError,2722);
inline AntStatus
LstErrXmlSave(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "XmlSave",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","XmlSave"),arg0);
  return LstXmlSaveError;
}
static AntStatus LstNoStateListAttributeError(AntStatus::AntError,2723);
inline AntStatus
LstErrNoStateListAttribute(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoStateListAttribute",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","NoStateListAttribute"));
  return LstNoStateListAttributeError;
}
static AntStatus LstListDeactivationError(AntStatus::AntError,2724);
inline AntStatus
LstErrListDeactivation(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListDeactivation",
              source,
              "Lst",
              AntTrace::trace().getErrorFormat("lsterror.emf","Lst","ListDeactivation"));
  return LstListDeactivationError;
}
inline const char *
LstGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2700:
    return "Init";
  case 2701:
    return "ORB";
  case 2702:
    return "HostServer";
  case 2703:
    return "CreatorId";
  case 2704:
    return "ListName";
  case 2705:
    return "NameAlreadyExists";
  case 2706:
    return "ListNotFound";
  case 2707:
    return "MaxList";
  case 2708:
    return "BadListType";
  case 2709:
    return "AddEntry";
  case 2710:
    return "DeleteEntry";
  case 2711:
    return "RemoteAllocation";
  case 2712:
    return "ActionNotAllowed";
  case 2713:
    return "ListNotErasable";
  case 2714:
    return "ListNotModifiable";
  case 2715:
    return "UpdateData";
  case 2716:
    return "UpdateCondition";
  case 2717:
    return "Clean";
  case 2718:
    return "ListLists";
  case 2719:
    return "DeactivatingANotActivatedList";
  case 2720:
    return "StateListCreation";
  case 2721:
    return "UserListCreation";
  case 2722:
    return "XmlSave";
  case 2723:
    return "NoStateListAttribute";
  case 2724:
    return "ListDeactivation";
  default:
    return "";
  }
}
#endif
