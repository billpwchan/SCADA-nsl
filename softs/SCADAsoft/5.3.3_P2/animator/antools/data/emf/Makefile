# $Id: Makefile,v 1.9 2000/02/07 10:02:18 scadaref Exp $
# $Log: Makefile,v $
# Revision 1.9  2000/02/07 10:02:18  scadaref
# Add dcp and ctl modules (J. PUJOL)
#
# Revision 1.8  2000/02/07 09:05:03  scadaref
# Add scstcl module (P. GEORGET)
#
# Revision 1.7  2000/02/01 08:50:52  hot
# Add dac errors
#
# Revision 1.6  99/06/09  14:37:42  14:37:42  jmb (Jean-Michel Brocart)
# Add scsalmerror.h
# 
# Revision 1.5  1999/03/29 15:14:31  scadaref
# Add scadasoft alarms (use scsalmerror instead of almerror.h).
#
# Revision 1.4  1999/03/10 09:54:12  ylo
# Use -o option to generate #ifdef protection
#
# Revision 1.3  1999/03/10 09:43:36  ylo
# Change error base numbers.
#
# Revision 1.2  1999/03/08 17:25:51  ylo
# Add automatic .h generation
#
# Revision 1.1  1998/12/07 13:50:25  scadaref
# Initial revision
#
# Revision 1.1  1997/10/27 18:49:50  scadaref
# Initial revision
#
# Revision 1.1  1997/10/27 18:49:08  scadaref
# Initial revision
#
TARGET    = libDummyEmf.$(LIB_EXTENSION)
CURDIR    = inc
SRCDIR    = $(ROOTDIR)/$(CURDIR)
BUILDMODE = -l

TARGETS = $(BINDIR)/inc/ant/ant.h
        
emf: createbinarydirifneeded $(TARGETS)

ifeq ($(SYSTEMFAMILY), win32)
SCSMKERROR = scsmkerror.exe
else
SCSMKERROR = scsmkerror
endif

$(BINDIR)/inc/ant/ant.h : $(ROOTDIR)/an/antools/data/emf/ant.emf
	$(SCSMKERROR) -m 0 -o $@ $<

include $(ROOTDIR)/config.mak
include $(CONFDIR)/stdrules.mak
