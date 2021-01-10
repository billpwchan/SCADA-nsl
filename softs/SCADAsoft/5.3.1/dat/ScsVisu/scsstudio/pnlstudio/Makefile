# $Id: Makefile,v 1.3 1999/12/13 13:53:41 scadaref Exp $
# $Log: Makefile,v $
# Revision 1.3  1999/12/13 13:53:41  scadaref
# EB add subdirs
#
# Revision 1.2  1999/11/17 13:47:00  scadaref
# *** empty log message ***
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

SUBLIBDIRTARGET = icons locale

# Default rule (call sub-module default rules).
.DEFAULT:
	@for target in $(SUBLIBDIRTARGET); do \
	  if [ -f $$target/Makefile ]; then \
	    $(MAKE) -C $$target $@; \
	  else echo "*** Can't make [$@] in '$$target'"; fi \
	done

# Rule to rebuild all.
.PHONY: all
all: $(SUBLIBDIRTARGET)

# Rules to build sub-modules (individually).
.PHONY: $(SUBLIBDIRTARGET)
$(SUBLIBDIRTARGET):
	@if [ -f $@/Makefile ]; then \
	    $(MAKE) -C $@; \
	else echo "*** Can't make [default rule] in '$@'"; fi

# Rule to update sub-module sources and datas
.PHONY: update updatedata updateforced
update:
	@$(SHELL) -c "codiff RCS/*,v ; true"
	@for target in $(SUBLIBDIRTARGET); do \
	  $(MAKE) -C $$target $@; \
	done

updatedata:
#	@echo "### Updating data..."
#	@for dir in $(DATADIR) ; do \
#	  cd $$dir ; \
#	  co RCS/* ; \
#	done

updateforced: updatedata
	@$(SHELL) -c "co RCS/*,v ; true"
	@for target in $(SUBLIBDIRTARGET) $(EXECDIRTARGET); do \
	  $(MAKE) -C $$target $@; \
	done

# Rule to build TAGS file (for xemacs)
.PHONY: TAGS tags
TAGS tags:
	@echo "### Building TAGS file ..."
	@mktags -k `echo '($(strip $(SUBLIBDIRTARGET))' | \
	  sed -e 's/ /|/g'` -o TAGS .


