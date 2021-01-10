# $Id: Makefile,v 1.1 1999/12/13 13:09:41 scadaref Exp $
# $Log: Makefile,v $
# Revision 1.1  1999/12/13 13:09:41  scadaref
# Initial revision
#
# Revision 1.1  1999/12/13 13:07:46  scadaref
# Initial revision
#
# Revision 1.3  1999/12/13 13:06:13  scadaref
# EB add subdirs
#
# Revision 1.2  1999/11/17 13:38:55  scadaref
# EB
#
# Revision 1.1  1999/03/01 13:48:30  scadaref
# Initial revision
#
# Revision 1.1  1999/03/01 13:42:15  scadaref
# Initial revision
#
# Revision 1.1  1997/10/27 18:49:08  scadaref
# Initial revision
#
include $(ROOTDIR)/config.mak

SUBLIBDIRTARGET = fr_FR.ISO-8859-1 fr_FR.windows-1252

# Default rule (call sub-module default rules).
.DEFAULT:
	@for target in $(SUBLIBDIRTARGET); do \
	  if [ -f $$target/Makefile ]; then \
	    cd $$target; $(MAKE) $@; \
	  else echo "*** Can't make [$@] in '$$target'"; fi \
	done

# Rule to rebuild all.
.PHONY: all
all: $(SUBLIBDIRTARGET)

# Rules to build sub-modules (individually).
.PHONY: $(SUBLIBDIRTARGET)
$(SUBLIBDIRTARGET):
	@if [ -f $@/Makefile ]; then \
	    cd $@; $(MAKE); \
	else echo "*** Can't make [default rule] in '$@'"; fi

# Rule to build TAGS file (for xemacs)
.PHONY: TAGS tags
TAGS tags:
	@echo "### Building TAGS file ..."
	@mktags -k `echo '($(strip $(SUBLIBDIRTARGET))' | \
	  sed -e 's/ /|/g'` -o TAGS .

