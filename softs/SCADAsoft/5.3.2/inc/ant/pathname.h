// -------------------------------------------------------------- -*- C++ -*-
//     SYSECA                                 Animator
//                                            [TOOLS]
// --------------------------------------------------------------------------
// The information contained in this document is proprietary to Animator's
//   group of SYSECA and shall not be disclosed by the recipent to third
//             persons without the written consent of SYSECA
// --------------------------------------------------------------------------
//         file: pathname.h
//  description: declaration of AntPathName
//     creation: 1997/04/24
//       author: dom
// --------------------------------------------------------------------------
// $Id: pathname.h,v 1.7 1999/08/09 07:28:57 scadaref Exp $
//
// $Log: pathname.h,v $
// Revision 1.7  1999/08/09 07:28:57  scadaref
// Port on NT.
//
// Revision 1.6  1999/08/05 12:33:07  ylo
// Add isExecutable and SearchInPath methods.
//
// Revision 1.5  1999/04/21 08:41:18  scadaref
// port on NT.
//
// Revision 1.4  1999/03/02 09:33:09  ylo
// Add CopyFile method.
//
// Revision 1.3  1999/01/20 08:11:01  bertrand
// Add createDirectory method.
//
// Revision 1.2  1999/01/11 08:22:14  scadaref
// *** empty log message ***
//
// Revision 1.1  1998/11/23 14:37:19  scadaref
// Initial revision
//
// --------------------------------------------------------------------------
#ifndef	__AN_TPATHNAME_H
#define __AN_TPATHNAME_H
#include <ant/defs.h>

#ifdef WIN32
#include <io.h>
#undef CopyFile
#else
#include <dirent.h>
#endif

// --------------------------------------------------------------------------
//        class: AntPathName
//   superClass: -
//
//  description: To manage path names
// --------------------------------------------------------------------------
//     creation: 1997/05/13
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
/**
  \#include <ant/pathname.h>.
  The class AntPathName allows the management of file and directory path names
  regardless of the underlying operative system.
  A path name is composed of four parts :
  \begin{itemize}
  \item the device name (for Windows path names only),
  \item the directory,
  \item the file base name,
  \item the file extension.
  \end{itemize}
  The separators between these parts are system-dependant.
  */
class SCSERROR_API AntPathName
{
public:
/**@name Constructors / destructor*/
//@{
/**
  Default constructor.
  */
    AntPathName();
/**
  Copy constructor.
  */
    AntPathName(const AntPathName&);
/**
  Creates and initializes a new path name from the null-terminated character string pointed to by 'fileName'.
  */
    AntPathName(const char* fileName);

/**
  Destructor.
  */
    ~AntPathName();
//@}
/**@name General usage member functions*/
//@{
/**
  Sets the device name part of the pathname with a copy of 'device'.
  */
    void            setDevice(const char* device);
/**
  Sets the directory name part of the pathname with a copy of 'dirName'.
  */
    void            setDirName(const char* dirName);
/**
  Sets the base file name part of the pathname with a copy of 'baseName'.
  */
    void            setBaseName(const char* baseName);
/**
  Sets the file extension part of the pathname with a copy of 'extension'.
  */
    void            setExtension(const char* extension);
/**
  Returns the device name part of the pathname.
  */
    const char*     getDevice() const;
/**
  Returns the directory name part of the pathname.
  */
    const char*     getDirName() const;
/**
  Returns the last directory name part of the pathname.
  */
    AntBoolean      getLastDirName(char* &lastDirName) const;
/**
  Returns the device + directory parts of the pathname.
  */
    const char*     getDirectory(AntBoolean stripped=AntFalse) const;
/**
  Returns the file base name part of the pathname.
  */
    const char*     getBaseName() const;
/**
  Returns the file extension part of the pathname.
  */
    const char*     getExtension() const;

/**
  Returns the pathname as a system-dependant string.
  */
    const char*     getValue() const;
/**
  Returns the pathname as a system-dependant string.
  */
                    operator const char*() const;
/**
  Assignment operator.
  */
    AntPathName&    operator=(const AntPathName&);
/**
  Appends the pathname 'path' to self.
  */
    AntPathName&    operator+(const AntPathName& path);
/**
  Appends the pathname 'path' to self.
  The device part of 'path' is ignored.
  The directory part of 'aath' is appended to the one of 'self'.
  The base file and extension parts of 'self' are overloaded by the ones of 'path'
  */
    AntPathName&    append(const AntPathName& path);
    void            reset();

/**
  Appends the directory 'dirName' to the directoty part of the pathname.
  */
    void            addDirectory(const char* dirName);
/**
  Moves to the upper directory.
  */
    size_t          upDirectory();
/**
  Returns AntTrue if the file pointed to by the pathname exists, is executable or is directory.
  */
  AntBoolean      doesExist() const;
  AntBoolean      isExecutable() const;
  AntBoolean	  isDirectory() const;
/**
  Returns AntTrue if the file pointed to by fileName is executable in the list of path pointed to by path. If path is a null pointer the PATH variable is used.
  */
    static AntBoolean SearchInPath(const char *fileName, const char *path = 0);

/**
  creates the directory. This methods creates only the last directory of the pathname
  */
    AntBoolean      createDirectory() const;

/**
  creates all the directories contained in the path. 
  */
    AntBoolean      createPath() const;

/**
  Returns the last modification time of the file described by the pathname.
  */
    int            getModificationTime(unsigned long& modtime) const;

/**
  Reads the contents of a directory. Readir and listDir functions are identical execpt that :
  - readDir considers all the directory entries as file (result's filename part is never empty)
  - listDir considers subdirectories as directory (result's filename part is empty).  
  */
    AntBoolean openDir();
    AntBoolean readDir(AntPathName& result)         const;
    AntBoolean listDir(AntPathName& result)         const;
    AntBoolean closeDir()                           const;
 
/**
  Returns the filename part of the pathname.
  */
    const char *getFilename() const;

  /**
     Delete filename
  */
  AntBoolean removePath(AntBoolean force = AntFalse);

/**
  Copies the file contents of fromFile to toFile.
  Returns AntFalse fromFile is not redadable or toFile cannot be created.
  Default behavior is to make a real copy,
  with hardLinkFlag set, function tries to hardlink files if possible,
  WIN32 hard links are not supported.
  */
  static AntBoolean CopyFile(const AntPathName &fromFile, const AntPathName &toFile, AntBoolean hardLinkFlag=AntFalse);
/**
  Copies the files of directory fromDir to directory toDir. ONLY files and not
  subdirectories are copied.
  Returns AntFalse if fromDir is not redadable or if toDir cannot be created
  or if any files can not be copied.
  Default behavior is to make a real copy,
  with hardLinkFlag set, function tries to hardlink files if possible,
  WIN32 hard links are not supported.
  */
  static AntBoolean CopyFiles(const AntPathName &fromFile, const AntPathName &toFile, AntBoolean hardLinkFlag=AntFalse);

  /** 
      Move file or directory fromPath to file or directory toPath. 
       Returns AntFalse fromFile is not redadable or toFile cannot be created.
  */
  static AntBoolean Move (const AntPathName &fromFile, const AntPathName &toFile);

//@}
private:
    char*           _device;
    char*           _dirName;
    char*           _baseName;
    char*           _extension;
    char*           _outputValue;
    char*           _outputDirectory;
    char*           _outputFilename;
    AntBoolean      _computeOutputValue;
    AntBoolean      _computeOutputDirectory;
    AntBoolean      _computeOutputFilename;
#ifdef WIN32
    long                _directory;
    struct _finddata_t* _fileInfo;
#else
    DIR*                _directory;
#endif
};

// --------------------------------------------------------------------------
//        class: AntPathName
//       method: getDevice
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/07/01
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline const char*
AntPathName::getDevice() const
{
    return _device;
}
// --------------------------------------------------------------------------
//        class: AntPathName
//       method: getDirName
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/07/01
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline const char*
AntPathName::getDirName() const
{
    return _dirName;
}

inline const char*
AntPathName::getBaseName() const
{
    return _baseName;
}

// --------------------------------------------------------------------------
//        class: AntPathName
//       method: getExtension
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/07/01
//       author: olivier
// modification: 
// --------------------------------------------------------------------------

inline const char*
AntPathName::getExtension() const
{
    return _extension;
}

// --------------------------------------------------------------------------
//        class: AntPathName
//       method: operator const char*
//
//  description: 
// --------------------------------------------------------------------------
//     creation: 1997/07/01
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline
AntPathName::operator const char*() const
{
        return getValue();
}
// --------------------------------------------------------------------------
//        class: AntPathName
//       method: operator+
//
//  description: append a pathname to another
// --------------------------------------------------------------------------
//     creation: 1997/07/01
//       author: olivier
// modification: 
// --------------------------------------------------------------------------
inline AntPathName&
AntPathName::operator+(const AntPathName& pathName)
{
        return append(pathName);
}

#endif
