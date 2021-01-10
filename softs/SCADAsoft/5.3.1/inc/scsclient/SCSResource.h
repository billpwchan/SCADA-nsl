// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSResource.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSRESOURCE_H
#define SCSCLIENT_SCSRESOURCE_H
// ----------------------------------------------------------------------------
#ifdef WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif
// ----------------------------------------------------------------------------
#include <scsclient/SCSDef.h>
// ----------------------------------------------------------------------------
/// \class SCSResource
/// \brief Object's cycle life managment.
/// 
/// This class is designed to ensure that an object will be removed from memory
/// when it not anymore linked with other objects.
/// It manages a references counter which is increased when a link is established
/// with another object and decreased when a link is broken (see ref() and unref())
/// The object is removed from memory only when the counter is equal to 0.
// ----------------------------------------------------------------------------
class SCSResource {
public:
  /// \par Description:
  /// Increases the references counter of the given object.
  /// \param[in] res The object for which the counter has to be modified.
  inline static void ref(SCSResource* res) { if (res) res->ref(); }
  /// \par Description:
  /// Decreases the references counter of the given object.
  /// \param[in] res The object for which the counter has to be modified.
  inline static void unref(SCSResource* res) { if (res) res->unref(); }
  /// \par Description:
  /// Creates a new resource.
  SCSResource() : m_count(0) {}

  /// \par Description:
  /// Increases the references counter.
  inline void ref() {
#ifdef WIN32
    InterlockedIncrement(&m_count);
#else 
    #if __GNUC__ > 3
    __sync_add_and_fetch(&m_count, 1);
    #else
    ++m_count;
    #endif
#endif
  }
  /// \par Description:
  /// Decreases the references counter.
  inline void unref() { 
#ifdef WIN32
    if ( InterlockedDecrement(&m_count) <= 0) delete this;
#else
    #if __GNUC__ > 3
    if (__sync_sub_and_fetch(&m_count,1) <= 0) delete this;
    #else
    --m_count; 
    if (m_count == 0) delete this;
    #endif
#endif
  }
  /// \par Description:
  /// Gives the number of current references.
  /// \return The counter value.
  inline long count() const { return m_count; }

protected:
  virtual ~SCSResource() {}
            
private:
  long m_count;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSRESOURCE_H
