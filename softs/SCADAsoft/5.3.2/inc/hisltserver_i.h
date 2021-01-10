//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : hisltserver_i.h                                        */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  AUTHOR           : M. HEYBERGER                                           */
/*  COMPANY          : THALES-IS                                              */
/*  CREATION DATE    : Wed May 14 15:00:59 2003                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*      Definition of the LT historisation server                             */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $
//
// Revision 4.3.0  18/08/2004 KLL 
// FFT SCS 509 - Traitement de données suite à un changement de VDC
//

#ifndef _SCS_HISLTSERVER_I_H_
#define _SCS_HISLTSERVER_I_H_


#include "scs.h"
#include "hislt.h"

class HisLTServerIdl_i;

class HLT_API HisLTServer_i
{
  public :

    HisLTServer_i(const char* p_inEnvName,
		  const char* p_inProcessName,
		  const char* p_storagePath);
  
    virtual ~HisLTServer_i();

      /** writeSnapshot is called by LT generic part on online to manage application specific snapshot.
        You have to return 0 for success or an error code in case of problem. */
    virtual int writeSnapshot(const char* snapdir) { return 0; }
  
    /** readSnapshot is called by LT generic part on standby,
        so you can retrieve application specific data stored by writeSnapshot.
        You have to return 0 for success or an error code in case of problem. */
    virtual int readSnapshot(const char* snapdir) { return 0; }

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

    typedef void (*getHistFilesCallback)(char** p_copiedFilesList,
					 unsigned int p_count,
					 ScsAny p_arg,
					 const ScsStatus& p_returnStatus);

    typedef void (*getDBVStructureCallback)(char** p_copiedFilesList,
					    unsigned int p_count,
					    ScsAny p_arg,
					    const ScsStatus& p_returnStatus);


//  ---- putDBVStructure (2003/07/29) ----
//   --- Memorisation au LT des fichiers correspondant à la structure Statique de la DBV
// IDE:	
//      p_DBV    : Structure contenant : Identifiant de la DBV et la Date de Debut de la DBV 
//      p_StructDirPath: Path du directory contenant les fichiers statiques de la Structure DBV   
//                       que le serveur LT doit memoriser
// ---------------------------------------------------------------------------------------------
    virtual ScsStatus putDBVStructure(HisLTDBVInfo *p_DBV,
				      const char* p_StructDirPath);

				     
//  ---- putHistFiles (2003/07/29) ----
//   --- Memorisation au LT des fichiers d'historiques de la DBV
//       et eventuellement des fichiers de la structure statique de la DBV
// IDE:	
//   p_HistDirPath : Path du directory contenant les fichiers d'historiques à memoriser sur le LT serveur
//   p_dbvId    : Identifiant de la DBV (Peut etre vide, dans ce cas prendre l'identifiant de la courant DBV)
// -------------------------------------------------------------------------------------------------------

    virtual ScsStatus putHistFiles(const char* p_HistDirPath,
				   const char* p_dbvId,
				   const short p_type);



// ---- getAllDBVInfos ----
// --- Recuperation du LT server toutes les DBV et leurs dates associées (start et End Time)
// IDE:
//       out p_count    : out Nombre de toutes les DBVs passees
//       out p_DBVInfos : List de toutes les DBV et dates associees
//  Pas de callback associees , ni de treads car fait en Init
// ----------------------------------------------------------------------------------------------------
    virtual ScsStatus getAllDBVInfos ( unsigned int             *p_Count,
				       HisLTDBVInfo            **p_DBVInfos);


//  ---- getDBVStructure (2003/07/29) ----
//   --- Recuperation du LT des fichiers correspondant à la structure statique de la DBV 
// IDE:	
//	p_requestId : Identifiant de la requete
//      p_dbvId    : Identifiant de la DBV 
//      p_StructDirPath: Path ou le LT server doit copier les  fichiers STATIQUES de la Structure DBV 
// ......
// ----------------------------------------------------------------------------------------------------

    virtual ScsStatus getDBVStructure(const unsigned int      p_requestId,
				      const char*             p_dbvId,
				      const char*             p_StructDirPath,
				      getDBVStructureCallback p_callback,
				      ScsAny                  p_arg);


//  ---- getHistFiles (2003/07/29) ----
//   --- Recuperation du LT des fichiers  d'historiques
//       ==> OPTIMISATION possible : Recupere les fichiers d'historiques en meme temps que la Structure DBV
// IDE:
//      p_requestId : Identifiant de la requete
//      p_dbvId    : Identifiant de la DBV (A mettre a NULL: Ne sert pas pour l'instant , en vue d'optimisation)
//      p_histFileNames : Liste des fichiers d'historiques à recupérer
//      p_count    : Nombre de fichiers d'historiques à récuperer
//      p_DestHistPath: Path ou recopier les fichiers d'historiques
//      p_DestStructPath: Path ou recopier les fichiers de Structure statique de la DBV 
//       (A mettre à NULL: Ne sert pas pour l'instant, en vue d'optimisation
// ......
// ----------------------------------------------------------------------------------------------------

    virtual ScsStatus getHistFiles(const unsigned int      p_requestId,
				   const char*             p_dbvId,
				   char**                  p_histFileNames,
				   const unsigned int      p_count,
				   const char*             p_DestHistPath,
				   const char*             p_DestStructPath,
				   getHistFilesCallback    p_callback,
				   ScsAny                  p_arg);


//  ---- purgeFiles (2004/08/19) ----
//  ---- Effacer les fichiers sur le disque dont la date de création est inférieure à p_startTime
//       On appelle la deuxième méthode purgeFiles qui prend comme paramètre une liste de fichiers
//       Lorsque le client désire effacer des fichiers du disque, il doit obligatoirement passer 
//       par cette méthode et non par celle qui en protected
// ......
// ------------------------------------------------------------------------------------------------
  virtual ScsStatus getSubDirListForInterval(unsigned long p_startTime,
					     unsigned long p_endTime,
					     const char *  p_dbvId,
					     short         p_type,
					     char **&      p_filesList,
					     int&          p_nbElement) const;
  
    
  private:
  
  HisLTServerIdl_i * _LTServer;

};

#endif
