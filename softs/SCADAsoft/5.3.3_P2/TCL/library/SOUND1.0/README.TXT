Sound 1.0 for Tcl/Tk 8.2.0 under Windows
----------------------------------------

This is a very simple interface to the Windows Multi-Media library for playing sound files
in .WAV format. The package uses the stubs interface to Tcl/Tk and has been tested under the 
Scriptics Binary release of Tcl/Tk 8.2.0. It requires stubs support to run.

This package has no other attributes to recommend itself.

Using the Sound 1.0 Package
---------------------------

Download the "sound.zip" archive into your $tcl_library directory. Unzip the archive using a
utility that will preserve the directory structure embedded in the archive. (I use unzip.exe)
This should create a sub-directory names sound1.0 with a pkgIndex.tcl file and a .dll file,
as well as this readme.txt file.

You can load the package with a 

	package require Sound 1.0

statement.

Command Format
--------------

The package provides 1 command with the following format...

	sound filespec [...options...]

where filespec is the name of the .WAV file. If no path is given, the the command tries the
current directory, then the windows directory. This means that the command..

	sound ding.wav

will play the standard Windows "Ding" file, usually found in the Windows directory.

The following options are available:

	-sync		Return after sound is finished playing
	-async		Return immediately, play the sound in background
	-loop		Continue to loop the sound in background
	-nodefault	Error on file not found
	-memory		Play a memory block (See below)
	-nostop		Don't interrupt a playing sound

Obviously, both -sync (the default) and -async should not both be specified. By fooling with
the command you will get to see how it works fairly quickly. If you don't specify -nostop,
a subsequent sound command will cancel a currently running one.

If you specify -loop, the sound file will loop indefinitely. To cancel looping, use:

	sound filespec

where filespec is the name of the looping sound file. This will stop the loop.

The -memory option is useful as this extension saves a .WAV file in a list of memory
blocks that hold the data from a file. This saves reloading the file each time it is
played, something that can grind a Tcl application to a halt, or at least make voice
files stutter. If the -memory option is specified, the extension tries to locate the file
data in the memory list, and, on success, plays the data from memory. Otherwise, the file
is reloaded.

License
-------

Free for non-commercial use. Redistribution permitted, resale prohibited.

Warranty
--------

None. This software is provides "as is" without warranty of any kind. Use it at your own
risk.

Copyright(C) 1998,1999 I.B.Findleton

ifindleton@videotron.ca
 