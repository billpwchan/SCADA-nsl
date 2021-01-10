/******************************************************************************/
/*                                                                            */
/*  FILE                : guard.h                                             */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR              :                                                     */
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 03-16-10                                            */
/*  LANGUAGE            : C++                                                 */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*............................................................................*/
/*  CONTENTS                                                                  */
/******************************************************************************/
/* IDENTIFICATION:
 *
 * HISTORY:
 */
/******************************************************************************/

#ifndef __SCS_ecomlib_GUARD_H__
#define __SCS_ecomlib_GUARD_H__

namespace ecomlib {

/**
 * @class Guard
 *
 * @brief Enable to automatically lock/unlock a resource what ever its type is. 
 */
template <class T>
class Guard {
  
 public:
  
  /**
   * Constructor. The constructor automatically locks the provided resource.
   *
   * @param resource The resource to be locked.
   */
  Guard(T& resource);
  
  /**
   * Constructor. The constructor automatically locks the provided resource.
   *
   * @param resource The resource to be locked.
   */
  Guard(T* resource);
  
  /**
   * Destructor. The constructor automatically unlocks the provided resource.
   */
  virtual ~Guard();
  
 private:
  
  /**
   * The resource to be locked/unlocked automatically.
   */
  T* _resource;
  
  /**
   * Default constructor is private and not implemented.
   */
  Guard();
  
  /**
   * Copy constructor is private and not implemented.
   */
  Guard(const Guard&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  Guard& operator=(const Guard&);
  
};
 
/**
 * 
 */
template<class T>
Guard<T>::Guard(T& resource) : _resource(&resource) {
  
  _resource->lock();
}
  
/**
 * 
 */
template<class T>
Guard<T>::Guard(T* resource) : _resource(resource) {
  
  if (_resource) {
    _resource->lock();
  }
}
 
/**
 * 
 */
template<class T>
Guard<T>::~Guard() {
  
  if (_resource) {
    _resource->unlock();
  }
  
}

};

#endif
