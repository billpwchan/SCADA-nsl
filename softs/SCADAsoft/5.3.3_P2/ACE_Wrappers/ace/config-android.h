/* -*- C++ -*- */
// $Id: config-android.h 1859 2011-08-03 21:01:01Z fieldst $

// The following configuration file is designed to work for Android
// platforms using the Android NDK standalone toolkit.

// This was used to build for Android 2.3.1 (API level 9), arm processor

#ifndef ACE_CONFIG_LINUX_ANDROID_H
#define ACE_CONFIG_LINUX_ANDROID_H
#include /**/ "ace/pre.h"

#define ACE_PLATFORM_CONFIG config-linux-android.h

#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SSIZE_T
// system errorno is a volatile int
#define ACE_HAS_VOLATILE_ERRNO

#define ACE_LACKS_NEW_H
#define ACE_LACKS_SEARCH_H
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_SYS_SYSCTL_H
#define ACE_LACKS_UCONTEXT_H

#define ACE_LACKS_CUSERID
#define ACE_LACKS_FD_MASK
#define ACE_LACKS_GETHOSTENT
#define ACE_LACKS_GETLOADAVG
#define ACE_LACKS_ISCTYPE
#define ACE_LACKS_LOG2
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_PWD_FUNCTIONS
#define ACE_LACKS_PTHREAD_CANCEL
#define ACE_LACKS_SEEKDIR
#define ACE_LACKS_SEMBUF_T
#define ACE_LACKS_SETINHERITSCHED
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_SWAB
#define ACE_LACKS_SYSV_SHMEM
#define ACE_LACKS_TELLDIR
#define ACE_LACKS_WCSTOLL
#define ACE_LACKS_WCSTOULL


#include "ace/config-linux.h"

#include /**/ "ace/post.h"

#endif /* ACE_CONFIG_LINUX_ANDROID_H */
