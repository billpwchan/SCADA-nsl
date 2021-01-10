//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : san.h                                                  */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon May 05 16:36:46 2003                               */
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


#ifndef _SAN_H_
#define _SAN_H_

#include "dbm.h"
#include "an/prop.h"
// #include "ant/format.h"

class ScsString;
class AnWorkSpace;
class AnObject;
class AnObjectList;
class AnImage;
class SanComponent;
class SanAction;
class SanActionList;
class SanScript;
class SanScriptList;
class SanResource;
class SanResourceList;
typedef SanResource* (*SanResourceConstructor)();
class SanResourceConstructorList;
typedef SanComponent* (*SanComponentConstructor)();
class SanComponentConstructorList;
typedef SanAction* (*SanActionConstructor)();
class SanActionConstructorList;

class SanComponent
{
public:
  SanComponent();
  ~SanComponent();
  virtual void save(ostream&) const;
  virtual void restore(istream&);
  virtual const char* getName() const;
  virtual const char* getClassName() const;
  virtual SanComponent* getComponent(const ScsAddress& address) const;
  virtual ScsStatus acceptResource(const char* resource);
  virtual ScsStatus acceptAction(const char* action);
  virtual ScsAddress getFullAddress() const;
  virtual SanActionList* getAllActionList() const {return _actionList;};
  virtual SanResourceList* getAllResourceList() const {return _resourceList;};
  virtual SanScriptList* getAllScriptList() const {return _scriptList;};
  static int registerComponent(const char* name, 
			       SanComponentConstructor constructor);
  static SanComponent* create(const char* name);
  ScsAddress* getAddress() const {return _address;}
  SanAction* getAction(const char* name) const;
  SanResource* getResource(const char* name) const;
  void add(SanResource* resource);
  SanScript* getScript(const char* name) const;
  SanActionList* getActionList() const {return _actionList;};
  SanResourceList* getResourceList() const {return _resourceList;};
  SanScriptList* getScriptList() const {return _scriptList;};
  static SanComponent* getRoot() {return _root;};
  static ScsStringList* getNameList();
  static SanComponentConstructorList* getConstructorList();
protected:
  SanResourceList* _resourceList;
  SanActionList* _actionList;
  SanScriptList* _scriptList;
  ScsAddress* _address;
  static SanComponent* _root;
};

class SanObjectComponent : public SanComponent
{
public:
  SanObjectComponent();
  ~SanObjectComponent();
  virtual const char* getName() const;
  virtual const char* getClassName() const {return "SanObjectComponent";};
  virtual ScsStatus acceptResource(const char* resource);
  virtual ScsStatus acceptAction(const char* action);
  virtual ScsAddress getFullAddress() const;
  virtual SanComponent* getComponent(const ScsAddress& address) const;
  virtual SanActionList* getAllActionList() const;
  virtual SanResourceList* getAllResourceList() const;
  virtual SanScriptList* getAllScriptList() const;
  virtual AnObject* getObject() const {return _object;}
  virtual void setObject(AnObject* object) {_object = object;};
  virtual int isObjectResource(SanResource* resource);
protected:
  AnObject* _object;
  static int _registerSanObjectComponent;
};

class SanModelComponent : public SanObjectComponent
{
public:
  SanModelComponent();
  ~SanModelComponent();
  virtual const char* getName() const;
  virtual const char* getClassName() const {return "SanModelComponent";};
  virtual ScsAddress getFullAddress() const;
  virtual SanComponent* getComponent(const ScsAddress& address) const;
  virtual SanActionList* getAllActionList() const;
  virtual SanResourceList* getAllResourceList() const;
  virtual SanScriptList* getAllScriptList() const;
  AnObjectList* getObjectList() const {return _objectList;}
protected:
  AnObjectList* _objectList;
  static int _registerSanModelComponent;
};

class SanImageComponent : public SanComponent
{
public:
  SanImageComponent();
  ~SanImageComponent();
  virtual const char* getName() const;
  virtual const char* getClassName() const {return "SanImageComponent";};
  virtual ScsAddress getFullAddress() const;
  virtual SanComponent* getComponent(const ScsAddress& address) const;
  AnImage* getImage() const {return _image;}
  void setImage(AnImage* image) {_image = image;};
  void connectImage(DbmServer* server, DbmPoller* poller);
  void disconnectImage(DbmPoller* poller);
  SanResourceList* getPollList() const {return _pollList;};
  static AnWorkSpace* getWorkSpace(const char* path);
protected:
  AnImage* _image;
  SanResourceList* _readList;
  SanResourceList* _pollList;
  static int _registerSanImageComponent;
};

class SanAnimatorComponent : public AnProperty
{
public:
  SanAnimatorComponent(SanComponent* component = 0) 
    : _component(component) {;};
  virtual void save(ostream& os) const;
  virtual void restore(istream& is);
  void setComponent(SanComponent* component) {_component = component;};
  SanComponent* getComponent() {return _component;};
  AnDeclareProperty(SanAnimatorComponent)
  static const SanComponent *getComponent(AnImage *image);
  static const SanComponent *getComponent(AnObject *object);
protected:
  SanComponent* _component;
};
AnPreRegisterProperty(SanAnimatorComponent);

class SanResource
{
public:
  enum Mode {
    CONSTANT,
    READ,
    READ_WRITE,
    POLL
  };
  SanResource(SanComponent* component = 0);
  ~SanResource();
  virtual void save(ostream&) const;
  virtual void restore(istream&);
  virtual const char* getBase() const = 0;
  virtual const char* getClassName() const = 0;
  virtual ScsType getType() const  = 0;
  static int registerResource(const char* name, 
			      SanResourceConstructor constructor);
  static SanResource* create(const char* name);
  const char* getName() const;
  void setName(const char* name);
  void setComponent(SanComponent* component) {_component = component;};
  SanComponent* getComponent() const {return _component;};
  virtual ScsData getValue() const = 0;
  virtual void setValue(const ScsData& data) = 0;
  static const char* getClassName(int i);
  Mode getMode() const {return _mode;}; 
  void setMode(Mode mode) {_mode = mode;};
  ScsAddress* getAddress() const {return _address;}
  void setAddress(const ScsAddress& address)
  {delete _address; _address = new ScsAddress(address);};
  SanResource* duplicate();
  static ScsStringList* getNameList();
  static SanResourceConstructorList* getConstructorList();
protected:
  ScsString* _name;
  SanComponent* _component;
  ScsAddress* _address;
  Mode _mode;
  ScsStringList* _actionList;
};

#define SanPreRegisterResource(name) 
class name : public SanResource 
{ 
public: 
  virtual const char* getBase() const; 
  virtual const char* getClassName()const; 
  virtual ScsType getType() const; 
  virtual ScsData getValue() const; 
  virtual void setValue(const ScsData& data); 
};

SanPreRegisterResource(SanColorNumber);
SanPreRegisterResource(SanBlinkingState);
SanPreRegisterResource(SanBlinkingRate);
SanPreRegisterResource(SanSymbolNumber);
SanPreRegisterResource(SanText);
SanPreRegisterResource(SanTextFromFloat);
SanPreRegisterResource(SanValue);
SanPreRegisterResource(SanAlarm);

#define SanRegisterResource(name, base, type)
static SanResource* SanCreate##name() {return new name();}; 
static int dummy##name = SanResource::registerResource(#name, &SanCreate##name); 
ScsType name::getType() const {return type;}; 
const char* name::getClassName() const {return #name;}; 
const char* name::getBase() const {return #base;};

class SanIntegerResource : public SanResource
{
public:
  virtual ScsType getType() const {return ScsINTEGER;};
  virtual const char* getBase() const {return "ALWAYS";};
  virtual const char* getClassName() const {return "SanIntegerResource";};  
  virtual ScsData getValue() const {return _data;};
  virtual void setValue(const ScsData& data) {_data = data;};
protected:
  ScsData _data;
};

class SanFloatResource : public SanResource
{
public:
  virtual ScsType getType() const {return ScsFLOAT;};
  virtual const char* getBase() const {return "ALWAYS";};
  virtual const char* getClassName() const {return "SanFloatResource";};  
  virtual ScsData getValue() const {return _data;};
  virtual void setValue(const ScsData& data) {_data = data;};
protected:
  ScsData _data;
};

class SanStringResource : public SanResource
{
public:
  virtual ScsType getType() const {return ScsSTRING;};
  virtual const char* getBase() const {return "ALWAYS";};
  virtual const char* getClassName() const {return "SanStringResource";};  
  virtual ScsData getValue() const {return _data;};
  virtual void setValue(const ScsData& data) {_data = data;};
protected:
  ScsData _data;
};

class SanAction
{
public:
  SanAction(const char* parameters);
  ~SanAction();
  const char* getName() const;
  void setName(const char* name);
  virtual void save(ostream&) const;
  virtual void restore(istream&);
  static int registerAction(const char* name, 
			    SanActionConstructor constructor);
  static SanAction* create(const char* name);
  virtual ScsStatus execute(SanComponent& component, ScsAddress& address) = 0;
  static const char* getClassName(int pos);
  virtual const char* getClassName() const = 0;
  virtual const char* getBase() const = 0;
  virtual const char* getParameters() const = 0;
  SanResource* getResource(const SanComponent& component, const char* name);
  const char* getParameter(int pos);
  ScsType getParameterType(int pos);
  ScsStringList* getResourceList() const {return _resourceList;};
  static ScsStringList* getNameList();
  static SanActionConstructorList* getConstructorList();
protected:
  ScsString* _name;
  ScsStringList* _resourceList;
};

#define SanPreRegisterAction(name) 
class name : public SanAction 
{ 
public: 
  name(); 
  virtual ScsStatus execute(SanComponent& component, ScsAddress& address); 
  virtual const char* getClassName() const; 
  virtual const char* getBase() const; 
  virtual const char* name::getParameters() const; 
};

SanPreRegisterAction(SanOpenImage);
SanPreRegisterAction(SanWriteDb);

#define SanRegisterAction(name, base, parameters) 
static SanAction* SanCreate##name() {return new name();}; 
static int dummy##name = SanAction::registerAction(#name, &SanCreate##name); 
name::name() : SanAction(parameters) {;}; 
const char* name::getClassName() const {return #name;}; 
const char* name::getBase() const {return #base;}; 
const char* name::getParameters() const {return parameters;};

class SanScript
{
public:
  SanScript(const char* name = 0);
  ~SanScript();
  virtual void save(ostream&) const;
  virtual void restore(istream&);
  const char* getName() const;
  ScsStringList* getActionList() const {return _actionList;};
protected:
  ScsString* _name;
  ScsStringList* _actionList;
};

#endif







