/******************************************************************************/
/*                                                                            */
/*  FILE		: opmapi.h                                            */
/*  FULL NAME		:                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS                                           */
/*  CREATION DATE	: 2000/03/7                                           */
/*  LANGUAGE		: C++                                                 */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Api object                                                            */
/*............................................................................*/
/*  CONTENTS								      */
/*  A. NG               : 2006/09/26                                          */
/*                        PCR-SCS-814 (Evolution for Operator Anthentication) */
/******************************************************************************/

#ifndef _OPM_API_H
#define _OPM_API_H

/**
  \file
  \brief Access to the OPM component.
*/

#include "scs.h"
#include "opmtypes.h"

class opmProfileLoader;
class opmFactory;

/**
   \brief Class used to access the <em>OPM</em> component services.

   This class is used when an application needs user access rights based on operators
   profiles.
\code#include "opmapi.h"\endcode
*/

class OPM_API OpmApi
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
    \par Description:
      constructor.
    \param server  [in]: name of the server to connect to.
    \param env  [in]: environnement where the server is.
    \param priority  [in]: priority of the messages to the OpmApi (only useful with redudancy).
    \return 
      none. 
      The result of the initialization can be obtained by calling the <em>getStatus()</em> function.
    */
  OpmApi(const char *server, const char *env, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);
  /**
    \par Description:
     destructor.
    \par Parameters:
     none.
    \par Return values:
     none. 
    */
  ~OpmApi();
  /**
    \par Description:
      return the initialisation status of the API.
      none.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : initialisation error.
    */
  ScsStatus getStatus() {return _status;}
  //@}
  /**@name Load/Unload profile functions*/
  //@{
  /**
    \par Description:
      load a single profile in the process and recalculate the current profile.
    \param profile  [in]: name of the profile to load.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfAlreadyLoadedError : profile is already loaded.
    */
  ScsStatus load(char *profile);
  /**
    \par Description:
      removes a single profile from the process and recalculate the current profile.
    \param profile  [in]: name of the profile to unload.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmErrProfNotLoaded : profile is not loaded before.
    */
  ScsStatus unload(char *profile);
  /**
    \par Description:
      check if a profile is loaded or not. 
    \param profile  [in]: name of the profile to check.
    \return
    \li \c TRUE or 1: the profile is loaded 
    \li \c FALSE or 0: the profile is not loaded
    */
  long isLoaded(char *profile);
  /**
    \par Description:
      return an array of loaded profiles names string. The user must delete each item and 
      the array itself after use.
    \param nameList  [out]: string array of loaded profile names.
    \param count  [out]: number of string in the array.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result list not valid.
    */
  ScsStatus getLoadedProfiles(char **& nameList, long &count);
  //@}
  /**@name Retrieve access matrix geometry data functions*/
  //@{
  /**
    \par Description:
      return an array of locations names string. The user must delete each item and 
      the array itself after use.
    \param o_nameList  [out]: string array of locations names.
    \param o_count  [out]: number of string in the array.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result list not valid.
    */
  ScsStatus getLocations(char **& o_nameList, long &o_count);
  /**
    \par Description:
      return an array of functions names string. The user must delete each item and 
      the array itself after use.
    \param o_nameList  [out]: string array of functions names.
    \param o_count  [out]: number of string in the array.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result list not valid.
    */
  ScsStatus getFunctions(char **& o_nameList, long &o_count);
  /**
    \par Description:
      return an array of actions names string. The user must delete each item and 
      the array itself after use.
    \param o_nameList  [out]: string array of actions names.
    \param o_count  [out]: number of string in the array.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result list not valid.
    */
  ScsStatus getActions(char **& o_nameList, long &o_count);
  /**
    \par Description:
      return an array of all known profiles names string. The user must delete the array 
      after use. 
    \param o_nameList  [out]: string array of profiles names.
    \param o_count  [out]: number of string in the array.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result list not valid.
    */
  ScsStatus getProfiles(char **& o_nameList, long &o_count);
  /**
    \par Description:
      return the value of an attribute for a given location.
    \param location: string name of the location.
    \param value  [out]: description std::string.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getLocationDescription(const char *location, SCS_SL_STD(string)& value) const;
  /**
    \par Description:
      return the value of an attribute for a given location.
    \param location: string name of the location.
    \param value  [out]: category.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getLocationCategory(const char *location, t_category& value) const;
  /**
    \par Description:
      return the value of an attribute for a given location.
    \param location: string name of the location.
    \param value  [out]: masks.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getLocationFlags(const char *location, t_mask& value) const;
  /**
    \par Description:
      return the value of an attribute for a given function.
    \param function  [in]: string name of the function.
    \param value  [out]: description.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getFunctionDescription(const char *function, SCS_SL_STD(string)& value) const;
  /**
    \par Description:
      return the value of an attribute for a given function.
    \param function  [in]: string name of the function.
    \param value  [out]: category.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getFunctionCategory(const char *function, t_category& value) const;
  /**
    \par Description:
      return the value of an attribute for a given function.
    \param function  [in]: string name of the function.
    \param value  [out]: category.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getFunctionFlags(const char *function, t_mask& value) const;
  /**
    \par Description:
      return the value of an attribute for a given function.
    \param function  [in]: string name of the function.
    \param value  [out]: string to get the family name.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getFunctionFamily(const char *function, SCS_SL_STD(string)& value) const;
  /**
    \par Description:
      return the value of an attribute for a given action.
    \param action  [in]: string name of the faction.
    \param value  [out]: description.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getActionDescription(const char *action, SCS_SL_STD(string)& value) const;
  /**
    \par Description:
      return the value of an attribute for a given action.
    \param action  [in]: string name of the faction.
    \param value  [out]: category.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getActionCategory(const char *action, t_category& value) const;
  /**
    \par Description:
      return the value of an attribute for a given action.
    \param action  [in]: string name of the faction.
    \param value  [out]: flags.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getActionFlags(const char *action, t_mask& value) const;
  /**
    \par Description:
      return the value of an attribute for a given action.
    \param action  [in]: string name of the faction.
    \param value  [out]: category.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result attribute not valid.
    */
  ScsStatus getActionAbbrev(const char *action, SCS_SL_STD(string)& value) const;
  //@}
  /**@name Subscription functions*/
  //@{
  /**
    \par Description:
      subscribe to change in a given single profile. The profile must be loaded 
      before subscribing.
    \param profile  [in]: string name of the profile to subscribe.
    \param callback  [in]: callback function to trigger when the profile is modified.
    \return 
    \li \c ScsValid : success.
    \li \c OpmSubscribeError : failed to subscribe to a remote OlsList.
    \li \c ScsError : any other error.
    */
  ScsStatus subscribe(char * profile, OpmCallback callback);
  /**
    \par Description:
      unsubscribe from a profile
    \param profile  [in]: string name of the profile to unsubscribe.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed because profile was not found in subscription list.
    */
  ScsStatus unsubscribe(char * profile);
  //@}
  /**@name Configuration functions*/
  //@{
  /**
    \par Description:
      reset the definition reference by loading all definitions from reference file.
      none.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, definitions not loaded.
    */
  ScsStatus loadDefinitions();
  /**
    \par Description:
      reset the profile reference by loading all profiles from reference file.
      none.
    \return 
    \li \c ScsValid : success.
    \li \c OpmORBError : ORB communication failure (signal trapped).
    \li \c ScsError : function failed, profiles not loaded.
    */
  ScsStatus loadProfiles();
  /**
    \par Description:
      update the profile reference by saving profiles to reference file.
      none.
    \return 
    \li \c ScsValid : success.
    \li \c OpmORBError : ORB communication failure (signal trapped).
    \li \c ScsError : function failed, profiles not loaded.
    */
  ScsStatus saveProfiles();
  /**
    \par Description:
      set the current reading mask mode.
    \param maskMode  [in]: mask mode number (from 0 to 3).
    \return 
    \li \c ScsValid : success.
    \li \c OpmORBError : ORB communication failure (signal trapped).
    \li \c ScsError : function failed, mask not set.
    */
  ScsStatus setCurrentMaskMode(long maskMode);
  /**
    \par Description:
      set the mask of a single profile.
    \param profile  [in]: profile name string.
    \param location  [in]: location category.
    \param function  [in]: function category.
    \param maskMode  [in]: mask mode number (from 0 to 3).
    \param mask  [in]: mask to set.
    \param source  [in]: source of the request (used to event logging).
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c OpmORBError : ORB communication failure (signal trapped).
    \li \c ScsError : any other error.
    */
  ScsStatus setMask(char       *profile,
		    t_category  location,
		    t_category  function,
		    long        maskMode,
		    t_mask      mask,
		    const char *source = NULL);
  ScsStatus setLocalMask(char       *profile,
			 t_category  location,
			 t_category  function,
			 long        maskMode,
			 t_mask      mask);
  /**
    \par Description:
      set the mask of a single profile.
    \param profile  [in]: profile name string.
    \param location  [in]: location name string.
    \param function  [in]: function name string.
    \param maskMode  [in]: mask mode number (from 0 to 3).
    \param mask  [in]: mask to set.
    \param source  [in]: source of the request (used to event logging).
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c OpmORBError : ORB communication failure (signal trapped).
    \li \c ScsError : any other error.
    */
  ScsStatus setMask(char       *profile,
		    char       *location,
		    char       *function,
		    long        maskMode,
		    t_mask      mask,
		    const char *source = NULL);
  ScsStatus setLocalMask(char   *profile,
			 char   *location,
			 char   *function,
			 long    maskMode,
			 t_mask  mask);
  /**
    \par Description:
      set the mask of a single profile.
    \param profile  [in]: profile name string.
    \param location  [in]: location category.
    \param function  [in]: function category.
    \param maskMode  [in]: mask mode number (from 0 to 3).
    \param mask  [in]: string mask to set.
    \param source  [in]: source of the request (used to event logging).
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c OpmErrInvStringMask : string mask not valid.
    \li \c OpmORBError : ORB communication failure (signal trapped).
    \li \c ScsError : any other error.
    */
  ScsStatus setMask(char       *profile,
		    t_category  location,
		    t_category  function,
		    long        maskMode,
		    char       *mask,
		    const char *source = NULL);
  ScsStatus setLocalMask(char       *profile,
			 t_category  location,
			 t_category  function,
			 long        maskMode,
			 char       *mask);
  /**
    \par Description:
      set the mask of a single profile.
    \param profile  [in]: profile name string.
    \param location  [in]: location name string.
    \param function  [in]: function name string.
    \param maskMode  [in]: mask mode number (from 0 to 3).
    \param mask  [in]: string mask to set.
    \param source  [in]: source of the request (used to event logging).
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c OpmErrInvStringMask : string mask not valid.
    \li \c OpmORBError : ORB communication failure (signal trapped).
    \li \c ScsError : any other error.
    */
  ScsStatus setMask(char       *profile,
		    char       *location,
		    char       *function,
		    long        maskMode,
		    char       *mask,
		    const char *source = NULL);
  ScsStatus setLocalMask(char *profile,
			 char *location,
			 char *function,
			 long  maskMode,
			 char *mask);
  /**
    \par Description:
      Reset the temporary mask of a single profile with loaded,default profile.
    \param p  [in]: profile name string.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus unsetLocalMask(char *p);

  //@}
  /**@name Retrieve "single profile" data functions*/
  //@{
  /**
    \par Description:
      get the mask of a single profile.
    \param p  [in]: profile name string.
    \param l  [in]: location category.
    \param f  [in]: function category.
    \param m  [out]: mask result.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus getMask(char *p, t_category l, t_category f, t_mask &m);
  /**
    \par Description:
      get the mask of a single profile.
    \param p  [in]: profile name string.
    \param l  [in]: location string name.
    \param f  [in]: function string name.
    \param m  [out]: mask result.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus getMask(char *p, char * l, char * f, t_mask &m);
  /**
    \par Description:
      check the access right according to a bit field mask. 
    \param p  [in]: profile name string.
    \param l  [in]: location category.
    \param f  [in]: function category.
    \param req_mask  [in]: bit filed mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(char *p, t_category l, t_category f, t_mask req_mask, short &o_result);
  /**
    \par Description:
      check the access right according to a bit field mask.
    \param p  [in]: profile name string.
    \param l  [in]: location string name.
    \param f  [in]: function string name.
    \param req_mask  [in]: bit field mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(char *p, char * l, char * f, t_mask req_mask, short &o_result);
  /**
    \par Description:
      check the access right according to a string mask. 
    \param p  [in]: profile name string.
    \param l  [in]: location category.
    \param f  [in]: function category.
    \param req_mask  [in]: string mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(char *p, t_category l, t_category f, char * req_mask, short &o_result);
  /**
    \par Description:
      check the access right according to a string mask. 
    \param p  [in]: profile name string.
    \param l  [in]: location string name.
    \param f  [in]: function string name.
    \param req_mask  [in]: string mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvProfNameError : profile string is NULL.
    \li \c OpmProfNotLoadedError : profile is not loaded.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(char *p, char * l, char * f, char *  req_mask, short &o_result);
  //@}
  /**@name Retrieve "current profile" (logical AND of all loaded profiles) data functions*/
  //@{
  /**
    \par Description:
      get the mask of the current profile.
    \param l  [in]: location category.
    \param f  [in]: function category.
    \param m  [out]: mask result.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus getMask(t_category l, t_category f, t_mask &m);
  /**
    \par Description:
      get the mask of the current profile.
    \param l  [in]: location string name.
    \param f  [in]: function string name.
    \param m  [out]: mask result.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus getMask(char * l, char * f, t_mask &m);
  /**
    \par Description:
      get in one call the masks of the current profile. It is caller responsibility to remove the output matrix memory.
    \param masks  [out]: masks matrix.
    \param nbLocations  [out]: number of locations.
    \param nbFunctions  [out]: number of functions.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : any other error.
    */
  ScsStatus getMasks(t_mask*& masks, int& nbLocations, int& nbFunctions);
  /**
    \par Description:
      check the access right on the current profile according to a bit field mask. 
    \param l  [in]: location category.
    \param f  [in]: function category.
    \param req_mask  [in]: string mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(t_category l, t_category f, t_mask req_mask, short &o_result);
  /**
    \par Description:
      check the access right on the current profile according to a bit field mask.
    \param l  [in]: location string mask.
    \param f  [in]: function string mask.
    \param req_mask  [in]: string mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(char * l, char * f, t_mask req_mask, short &o_result);
  /**
    \par Description:
      check the access right on the current profile according to a string mask. 
    \param l  [in]: location category.
    \param f  [in]: function category.
    \param req_mask  [in]: string mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvLocCategoryError : location category not valid.
    \li \c OpmInvFuncCategoryError : function  category not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(t_category l, t_category f, char * req_mask, short &o_result);
  /**
    \par Description:
      check the access right on the current profile according to a string mask.
    \param l  [in]: location string mask.
    \param f  [in]: function string mask.
    \param req_mask  [in]: string mask required to have access granted.
    \param o_result  [out]: TRUE access is granted or FALSE access is forbiden.
    \return 
    \li \c ScsValid : success.
    \li \c OpmInvLocNameError : location name string not valid.
    \li \c OpmInvFuncNameError : function  name string not valid.
    \li \c ScsError : any other error.
    */
  ScsStatus checkAccess(char * l, char * f, char * req_mask, short &o_result);
  //@}
  /**@name Operators related functions (optional functions)*/
  //@{
  /**
    \par Description:
      return an array of operators names string. The user must delete each item and 
      the array itself after use.
    \param o_nameList  [out]: string array of operators names.
    \param o_count  [out]: number of string in the array.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result list not valid.
    */
  ScsStatus getOperators(char **& o_nameList, long &o_count);
  /**
    \par Description:
      return an array of profiles names string associated with an operator. The user must 
      delete each item and the array itself after use.
    \param oper [in]: operator name.
    \param o_nameList  [out]: string array of profiles names.
    \param o_count  [out]: number of string in the array.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed, result list not valid.
    */
  ScsStatus getOperatorProfilesList(const char * oper, char **& o_nameList, long &o_count);
  /**
    \par Description:
      return a particular profile string associated to an operator.
    \param oper  [in]: operator name.
    \param num  [in]: profile number. (from 1 to N)
    \param profile  [out]: resulting profile name.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
    */
  ScsStatus getOperatorProfile(const char* oper, int num, SCS_SL_STD(string)& profile) const;
  /**
    \par Description:
      return a particular property string associated to an operator.
      the property string is content free a may be used by the application
      to store any convenient data. for now up to 5 property can be defined.
    \param oper  [in]: operator name.
    \param num  [in]: property number. (from 1 to 5)
    \param property  [out]: resulting property string.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
    */
  ScsStatus getOperatorProperty(const char * oper, int num, SCS_SL_STD(string)& property) const;
  /**
    \par Description:
      return the group of an operator.
    \param oper  [in]: operator name.
    \param group  [out]: resulting group string.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
    */
  ScsStatus getOperatorGroup(const char * oper, SCS_SL_STD(string)& group) const;
  /**
    \par Description:
    return the password of an operator. The password returned is <b>crypted</b>.
    \param oper  [in]: operator name.
    \param password  [out]: resulting password string.
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
    */
  ScsStatus getOperatorPassword(const char * oper, SCS_SL_STD(string)& password) const;
  /**
    \par Description:
    change the password of an operator. The value of the current password is verified and, if it is correct, the new password is crypted and set to the operator password.
    \param operatorName  [in]: operator name.
    \param currentPassword  [in]: current password.
    \param newPassword  [in]: new password.
    \param source  [in]: source of the request (used for event logging).
    \return 
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
    */
  ScsStatus changeOperatorPassword(const char     *operatorName,
				   const char     *currentPassword,
				   const char     *newPassword,
				   const char     *source = NULL);
  /**
     \par Description:
     test if an operator password is valid or not. The value of the password is crypted and compared with the current crypted password. 
     \param operatorName  [in]: operator name.
     \param password  [in]: password to test.
     \param isValid  [out]: result if the password is valid.
     \param source  [in]: source of the request (used for event logging).
     \return 
     \li \c ScsValid : success.
     \li \c ScsError : function failed.
  */
  ScsStatus isOperatorPasswordValid(const char     *operatorName,
				    const char     *password,
                                    unsigned short &isValid,
                                    const char     *source = NULL);
  /**
     \par Description:
     Create a new operator.
     \param operatorName  [in]: operator name.
     \return 
     \li \c ScsValid : success.
     \li \c ScsError : function failed.
  */
  ScsStatus createOperator(const char *operatorName);
   /**
      \par Description:
      Remove an operator. 
      \param operatorName  [in]: operator name.
      \return 
      \li \c ScsValid : success.
      \li \c ScsError : function failed.
   */
  ScsStatus removeOperator(const char *operatorName);
  /**
     \par Description:
     Remove a profile from an operator. 
     \param operatorName  [in]: operator name.
     \param profile  [in]: profile to remove.
     \return 
     \li \c ScsValid : success.
     \li \c ScsError : function failed.
  */
  ScsStatus removeOperatorProfile(const char* operatorName, const char* profile);
  /**
     \par Description:
     Add a profile to an operator.
     \param operatorName  [in]: operator name.
     \param profile  [in]: profile to add.
     \return 
     \li \c ScsValid : success.
     \li \c ScsError : function failed.
  */
  ScsStatus addOperatorProfile(const char* operatorName, const char* profile);
  /**
    \par Description: 
    return the last date of password changed of an operator.
    \param operatorName [in]: operator name.
    \param o_date_time [out]: date of last password update (GMT in seconds) 
    \return
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
  */
  ScsStatus getOperatorLastPasswordUpdate(const char * operatorName, unsigned long& o_date_time);
  /**
    \par Description: 
    return the lock/unlock status an operator.
    \param operatorName  [in]: operator name.
    \param o_status  [out]: lock status.
    \return
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
  */
  ScsStatus getOperatorStatus(const char * operatorName, SCS_SL_STD(string)& o_status);
  /**
    \par Description: 
    return the number of current consecutive failed login an operator.
    \param operatorName  [in]: operator name.
    \param o_number  [out]: number of current consecutive failed login.
    \return
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
  */
  ScsStatus getOperatorCurrentFailedLogin(const char * operatorName, unsigned short& o_number);
  /**
    \par Description: 
    return the expiration duration of the password of an operator.
    \param operatorName  [in]: operator name.
    \param o_day  [out]: number of day(s) for password expiration.
    \return
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
  */
  ScsStatus getOperatorExpirationDuration(const char * operatorName, unsigned short& o_day);
  /**
    \par Description: 
    return the minimum password length of an operator 
    \param operatorName  [in]: operator name.
    \param o_length  [out]: minimum number of character(s) of the password 
    \return
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
  */
  ScsStatus getOperatorMinPasswordLength(const char * operatorName, unsigned short& o_length);
  /**
    \par Description: 
    return the maximum number of consecutive failed login of an operator.
    \param operatorName  [in]: operator name.
    \param o_number  [out]: maximum number of consecutive failed login 
    \return
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
  */
  ScsStatus getOperatorMaxFailedLogin(const char * operatorName, unsigned short& o_number);
  /**
    \par Description:
    return if the password is expired of an operator.
    \param operatorName  [in]: operator name.
    \param o_expired  [out]: 0 - password is expired. 
                             1 - password is not yet expired. 
    \return
    \li \c ScsValid : success.
    \li \c ScsError : function failed.
  */
  ScsStatus isOperatorPasswordExpired(const char * operatorName, unsigned short &o_expired);
  ScsStatus writeOperatorsFile(const char *operatorName, const char *keyword, const char *value, const long int_value);
  ScsStatus hookOpmEvent(const char* operatorName, const char* source, const long opType);       
 
  //@}
private:

  ScsStatus convertStringMask(char *stringMask, t_mask &mask);
  ScsStatus convertCategory(t_category c, t_index &i);

  long exists(char *name);

  ScsStatus getNameList(long type, char **& outList, long &outCount);

  opmProfileLoader * _profilelist;
  opmFactory * _factory;

  long _maskMode;

  ScsStatus _status;
};


#endif
