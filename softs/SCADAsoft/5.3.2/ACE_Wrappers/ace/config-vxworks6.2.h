/* -*- C++ -*- */
// $Id: config-vxworks6.2.h 1162 2009-05-19 22:07:29Z mitza $

// The following configuration file is designed to work for VxWorks
// 6.2 platforms using one of these compilers:
// 1) The GNU g++ compiler that is shipped with VxWorks 6.2

#ifndef ACE_CONFIG_VXWORKS_6_2_H
#define ACE_CONFIG_VXWORKS_6_2_H
#include /**/ "ace/pre.h"

#if ! defined (VXWORKS)
# define VXWORKS
#endif /* ! VXWORKS */

#if ! defined (ACE_VXWORKS)
# define ACE_VXWORKS 0x620
#endif /* ! ACE_VXWORKS */

#if defined __RTP__
  // Fix wrong typedef in unistd.h (unsigned short)
  #define _SUSECONDS_T
  typedef long suseconds_t;
#endif
#include <unistd.h>

// Fix for including right typedef for pid_t in VxTypes.h (int)
#include <vxWorksCommon.h>

#if ! defined (__ACE_INLINE__)
# define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Compiler-specific configuration.
#if defined (__GNUG__)
# include "ace/config-g++-common.h"

# define ACE_LACKS_IOSTREAM_FX
# define ACE_LACKS_LINEBUFFERED_STREAMBUF

# if defined (__RTP__) && !defined (_HAS_C9X)
// Workaround for the fact that under RTP the log2 method can't be used
// without this define set, see TSR560446
#  if !defined (_C99)
#   define _C99
#  endif
# endif

#elif defined (__DCPLUSPLUS__) || defined (__DCC__)
  // Diab 4.2a or later.
# if !defined (ACE_LACKS_PRAGMA_ONCE)
    // We define it with a -D with make depend.
#   define ACE_LACKS_PRAGMA_ONCE
# endif /* ! ACE_LACKS_PRAGMA_ONCE */

# define ACE_HAS_STANDARD_CPP_LIBRARY 1
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
# define ACE_TEMPLATES_REQUIRE_SOURCE

#else  /* ! __GNUG__ && ! ghs && !__DCC__ */
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#    error unsupported compiler on VxWorks
#  endif  /* __cplusplus */
#endif /* ! __GNUG__ && ! ghs */

#if !defined __RTP__
# if defined (TOOL) && (TOOL == gnu)
#  if defined (CPU) && (CPU == PPC85XX || CPU == PPC604 || CPU == PPC603)
// These PPC's do lack log2 in kernel mode
#   define ACE_LACKS_LOG2
#  endif
# endif
#endif

// OS-specific configuration
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
#define ACE_HAS_NONCONST_GETBY
#define ACE_HAS_NONCONST_INET_ADDR
#define ACE_HAS_NONCONST_SWAB
#define ACE_HAS_NONCONST_READV
#define ACE_LACKS_UNIX_SYSLOG
#define ACE_DEFAULT_MAX_SOCKET_BUFSIZ 32768
#define ACE_DEFAULT_THREAD_KEYS 16
#define ACE_HAS_BROKEN_ACCEPT_ADDR
#define ACE_HAS_NONCONST_SENDMSG
#define ACE_HAS_NONCONST_WRITEV
#define ACE_HAS_CHARPTR_DL
#define ACE_HAS_CLOCK_GETTIME
#define ACE_HAS_CLOCK_SETTIME
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_CPLUSPLUS_HEADERS
#define ACE_HAS_DIRENT
#define ACE_HAS_DLL 0
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_IOCTL_INT_3_PARAM
#define ACE_HAS_MSG
#define ACE_HAS_NONCONST_READV
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_NONSTATIC_OBJECT_MANAGER
#define ACE_HAS_POSIX_NONBLOCK
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_REENTRANT_FUNCTIONS
#define ACE_HAS_SIGACTION_CONSTP2
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_SOCKADDR_IN_SIN_LEN
#define ACE_HAS_SOCKADDR_IN6_SIN6_LEN
#define ACE_HAS_STRERROR
#define ACE_HAS_THREADS
#define ACE_HAS_SYSCTL
#define ACE_LACKS_ALPHASORT
#define ACE_LACKS_EXEC
#define ACE_LACKS_FILELOCKS
#define ACE_LACKS_FORK
#define ACE_LACKS_GETHOSTENT
#define ACE_LACKS_GETSERVBYNAME
#define ACE_LACKS_GETPROTOBYNAME
#define ACE_LACKS_GETPROTOBYNUMBER
#define ACE_LACKS_KEY_T
#define ACE_LACKS_LSTAT
#define ACE_LACKS_MADVISE
#define ACE_LACKS_MALLOC_H
#define ACE_LACKS_MEMORY_H
#define ACE_LACKS_MKFIFO
#define ACE_LACKS_MKTEMP
#define ACE_LACKS_MKSTEMP
#define ACE_LACKS_MMAP
#define ACE_LACKS_MPROTECT
#define ACE_LACKS_MSYNC
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_SYS_PARAM_H
#define ACE_LACKS_PWD_FUNCTIONS
#define ACE_LACKS_READDIR_R
#define ACE_LACKS_READLINK
#define ACE_LACKS_REALPATH
#define ACE_LACKS_PIPE
#define ACE_LACKS_RLIMIT
#define ACE_LACKS_RWLOCK_T
#define ACE_LACKS_SBRK
#define ACE_LACKS_SEEKDIR
#define ACE_LACKS_SEMBUF_T
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_SI_ADDR
#define ACE_LACKS_SOCKETPAIR
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_SYSV_SHMEM
#define ACE_LACKS_TELLDIR
#define ACE_LACKS_TEMPNAM
#define ACE_LACKS_TIMESPEC_T
#define ACE_LACKS_TRUNCATE
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_USECONDS_T
#define ACE_LACKS_UMASK
#define ACE_LACKS_STRPTIME
#define ACE_PAGE_SIZE 4096
#define ACE_THR_PRI_FIFO_DEF 101
#define ACE_THR_PRI_OTHER_DEF ACE_THR_PRI_FIFO_DEF
#define ACE_HAS_SIGTIMEDWAIT
#define ACE_HAS_SIGSUSPEND
#if !defined (ACE_VXWORKS_SPARE)
# define ACE_VXWORKS_SPARE spare4
#endif /* ! ACE_VXWORKS_SPARE */
#define ACE_HAS_GETIFADDRS

#define ACE_LACKS_SETEGID
#define ACE_LACKS_SETPGID
#define ACE_LACKS_SETREGID
#define ACE_LACKS_SETREUID
#define ACE_LACKS_SETSID
#define ACE_LACKS_SETUID
#define ACE_LACKS_SETEUID
#define ACE_LACKS_GETEUID
#define ACE_LACKS_GETUID
#define ACE_LACKS_GETPGID
#define ACE_LACKS_GETEGID
#define ACE_LACKS_GETGID
#define ACE_LACKS_SETGID

#define ACE_LACKS_SYS_UIO_H
#define ACE_LACKS_SYS_IPC_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_PWD_H
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_TERMIOS_H
#define ACE_LACKS_POLL_H
#define ACE_LACKS_FCNTL

// Some string things
#define ACE_LACKS_STRCASECMP
#define ACE_LACKS_ITOW
#define ACE_LACKS_WCSDUP
#define ACE_LACKS_WCSICMP
#define ACE_LACKS_WCSNICMP
#define ACE_LACKS_STRTOLL
#define ACE_LACKS_WCSTOLL
#define ACE_LACKS_STRTOULL
#define ACE_LACKS_WCSTOULL

#define ACE_HAS_CHARPTR_SOCKOPT
#define ACE_LACKS_SYMLINKS
#define ACE_LACKS_ISCTYPE

#if defined __RTP__
  // We are building for RTP mode
  #if !defined (ACE_AS_STATIC_LIBS)
  #  define ACE_HAS_SVR4_DYNAMIC_LINKING
  #endif
  #define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
  #define ACE_LACKS_REGEX_H
  #define ACE_LACKS_PUTENV
  #define ACE_HAS_SETENV
  #define ACE_HAS_3_PARAM_WCSTOK
  #define ACE_HAS_WCHAR
  #define ACE_HAS_VFWPRINTF
  #define ACE_SIZEOF_WCHAR 2
  #define ACE_HAS_TIMEZONE
  #define ACE_LACKS_ISASCII
#else
  // We are building for kernel mode
  #define ACE_LACKS_INTPTR_T
  #define ACE_LACKS_SUSECONDS_T
  #define ACE_LACKS_INTTYPES_H
  #define ACE_LACKS_STDINT_H
  #define ACE_LACKS_UNAME
  #define ACE_LACKS_UTSNAME_T
  #define ACE_LACKS_RAND_REENTRANT_FUNCTIONS
  #define ACE_LACKS_DLFCN_H
  #define ACE_LACKS_WAIT
  #define ACE_LACKS_WAITPID
  #define ACE_LACKS_SYS_TIME_H
  #define ACE_LACKS_SYS_SELECT_H
  #define ACE_LACKS_STRINGS_H
  #define ACE_MKDIR_LACKS_MODE
  #define ACE_HAS_SIZET_PTR_ASCTIME_R_AND_CTIME_R
  #define ACE_LACKS_SEARCH_H
  #define ACE_LACKS_SYSCONF
  #define ACE_LACKS_GETPID
  #define ACE_LACKS_GETPPID
  #define ACE_LACKS_WCHAR_H
  #define ACE_LACKS_WCTYPE_H
  #define ACE_LACKS_WCSCAT
  #define ACE_LACKS_WCSCHR
  #define ACE_LACKS_WCSCMP
  #define ACE_LACKS_WCSCPY
  #define ACE_LACKS_WCSCSPN
  #define ACE_LACKS_WCSLEN
  #define ACE_LACKS_WCSNCAT
  #define ACE_LACKS_WCSNCMP
  #define ACE_LACKS_WCSNCPY
  #define ACE_LACKS_WCSPBRK
  #define ACE_LACKS_WCSRCHR
  #define ACE_LACKS_WCSSPN
  #define ACE_LACKS_WCSSTR
  #define ACE_LACKS_WCSTOK
  #define ACE_LACKS_TOWLOWER
  #define ACE_LACKS_TOWUPPER
  #define ACE_LACKS_WCSTOD
  #define ACE_LACKS_WCSTOL
  #define ACE_LACKS_WCSTOUL
  #define ACE_LACKS_FGETWC
  #define ACE_LACKS_FGETWS
  #define ACE_LACKS_FPUTWS
  #define ACE_LACKS_ISWCTYPE
  #if !defined (ACE_MAIN)
  #  define ACE_MAIN ace_main
  #endif /* ! ACE_MAIN */
  #define ACE_LACKS_TZSET
  #define ACE_LACKS_ISBLANK
#endif

// It is possible to enable pthread support with VxWorks, when the user decides
// to use this, we need some more defines
#if defined ACE_HAS_PTHREADS
# define ACE_HAS_THREAD_SPECIFIC_STORAGE
# define ACE_HAS_POSIX_SEM
# define ACE_LACKS_MUTEXATTR_PSHARED
# define ACE_LACKS_CONDATTR_PSHARED
// Include this file, the sys/stat.h file shipped with VxWorks has old types
// and without this include we get a lot of compile errors. A TSR has been filed
// so that hopefully in the future we can zap this include
#include "types/vxTypesOld.h"
#else
# define ACE_LACKS_PTHREAD_H
# define ACE_HAS_VXTHREADS
# if !defined __RTP__
// Only when building for kernel mode we can use TSS emulation, in rtp mode
// we can't use the WIND_TCB struct anymore
#  define ACE_HAS_TSS_EMULATION
# endif
// VxWorks has no recursive mutexes. This was set in the past but it doesn't
// work with the pthread support, so only set it for the time being when pthread
// is disabled
# define ACE_HAS_RECURSIVE_MUTEXES
# define ACE_LACKS_COND_T
# define ACE_HAS_MUTEX_TIMEOUTS
#endif

#if !defined (ACE_MT_SAFE)
# define ACE_MT_SAFE 1
#endif

// Needed include to get all VxWorks CPU types
#include "types/vxCpu.h"
#if (CPU == PENTIUM || CPU == PENTIUM2 || CPU == PENTIUM3 || CPU == PENTIUM4)
// If running an Intel Pentium the
// ACE_OS::gethrtime () can use the RDTSC instruction.
# define ACE_HAS_PENTIUM
#endif

// VxWorks defines the CPU define MAP, undef it to prevent problems with
// application code
#if defined (MAP)
#undef MAP
#endif /* MAP */

#if !defined (ACE_NEEDS_HUGE_THREAD_STACKSIZE)
# define ACE_NEEDS_HUGE_THREAD_STACKSIZE 65536
#endif /* ACE_NEEDS_HUGE_THREAD_STACKSIZE */

#if !defined (ACE_NTRACE)
# define ACE_NTRACE 1
#endif /* ACE_NTRACE */

// By default, don't include RCS Id strings in object code.
#if !defined (ACE_USE_RCSID)
#define ACE_USE_RCSID 0
#endif /* !ACE_USE_RCSID */

#if defined (ACE_HAS_IP_MULTICAST)
# define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
#endif /* ACE_HAS_IP_MULTICAST */

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_VXWORKS_6_2_H */