//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : dbminfo.h                                              */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Fri Mar 21 17:50:48 2003                               */
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


#ifndef _SCS_DBMINFO_H_
#define _SCS_DBMINFO_H_

class DbmClassInfo {
public:
  DbmClassInfo() : _nbInstances(0), _stPeriodicity(0), 
    _nbStHistorised(0), _mtPeriodicity(0), _nbMtHistorised(0), _classId(0)
    {}

  DbmClassInfo(int nbInstances, int stPeriodicity, int nbStHistorised, int mtPeriodicity, int nbMtHistorised, int classId)
    : _nbInstances(nbInstances),
      _stPeriodicity(stPeriodicity),
      _nbStHistorised(nbStHistorised),
      _mtPeriodicity(mtPeriodicity),
      _nbMtHistorised(nbMtHistorised),
      _classId(classId) {}
          
  virtual ~DbmClassInfo() {}

  void save(SCS_SL_STD(ostream) &);
  void restore(SCS_SL_STD(istream) &);

  int getNbInstances() {return _nbInstances;}
  int getStPeriodicity() {return _stPeriodicity;}
  int getNbStHistorised() {return _nbStHistorised;}
  int getMtPeriodicity() {return _mtPeriodicity;}
  int getNbMtHistorised() {return _nbMtHistorised;}
  int getClassId() { return _classId; };

private:
  int _nbInstances;
  int _stPeriodicity;
  int _nbStHistorised;
  int _mtPeriodicity;
  int _nbMtHistorised;
  int _classId;
};

class DbmDatabaseInfo {
public:
  enum DatabaseType {RTAP, SCADASoft};

  DbmDatabaseInfo() : 
    _size(0),
    _nbClasses(0),
    _nbInstances(0),
    _nbFormulas(0),
    _scsPath(0),
    _dbType(SCADASoft),
    _usedShm(0),
    _version(0),
    _nbUserContexts(0),
    _nbSTRestitutionBuffers(DBK_NUM_RESTI_ST),
    _nbMTRestitutionBuffers(DBK_NUM_RESTI_MT),
    _optimized(0)
    {}
    
  DbmDatabaseInfo(DatabaseType dbType, 
                  unsigned long size, 
                  int nbClasses, 
                  int nbInstances, 
                  int nbFormulas, 
                  const char* scsPath, 
                  char usedShm = 0, 
                  int nbUserContexts = 0,
                  int nbSTRestBuffers = DBK_NUM_RESTI_ST,
                  int nbMTRestBuffers = DBK_NUM_RESTI_MT,
                  int p_optimized = 0) : 
      _size(size),
      _nbClasses(nbClasses),
      _nbInstances(nbInstances),
      _nbFormulas(nbFormulas),
      _scsPath(strdup(scsPath)),
      _dbType(dbType),
      _usedShm(usedShm),
      _version(0),
      _nbUserContexts(nbUserContexts),
      _nbSTRestitutionBuffers(nbSTRestBuffers),
      _nbMTRestitutionBuffers(nbMTRestBuffers),
      _optimized(p_optimized) 
      
      {}
                  
  virtual ~DbmDatabaseInfo() 
    {
        if (_version) free(_version);
        if (_scsPath) free(_scsPath);
    }

  void setVersion(const char* version)
    {
        if (_version) free(_version);
        _version = strdup(version);
    }


  void save(SCS_SL_STD(ostream) &);
  void restore(SCS_SL_STD(istream) &);

  unsigned long getSize() {return _size;}
  int getNbClasses() {return _nbClasses;}
  int getNbInstances() {return _nbInstances;}
  int getNbFormulas() {return _nbFormulas;}
  const char* getScsPath() {return _scsPath;}
  DatabaseType getType() {return _dbType;}
  char getUsedShm() {return _usedShm;}
  const char* getVersion() {return _version;}
  int getNbUserContexts() { return _nbUserContexts; };
  int getNbSTRestitutionBuffers() { return _nbSTRestitutionBuffers; };
  int getNbMTRestitutionBuffers() { return _nbMTRestitutionBuffers; };
  int isOptimized() { return _optimized; };

private:
  unsigned long _size;
  int _nbClasses;
  int _nbInstances;
  int _nbFormulas;
  char* _scsPath;
  DatabaseType _dbType;
  char _usedShm;
  char *_version;
  int _nbUserContexts;         // Number of user contexts
  int _nbSTRestitutionBuffers; // Number of short term restitution buffer (default DBK_NUM_RESTI_ST)
  int _nbMTRestitutionBuffers; // Number of middle term restitution buffer (default DBK_NUM_RESTI_MT)
  int _optimized;              // optimisation mode (0 means not optimized, 1 optimized)
};

#endif
