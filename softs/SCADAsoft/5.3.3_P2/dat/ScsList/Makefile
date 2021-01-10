# $Id: Makefile,v 1.1 1999/06/07 16:51:29 scadaref Exp $
# $Log: Makefile,v $
# Revision 1.1  1999/06/07 16:51:29  scadaref
# Initial revision
#
# Revision 1.2  1999/05/26 12:12:08  scadaref
# Add PanelBuilder and Scripts subdirectory for correct delivery.
#
# Revision 1.1  1999/03/01 13:42:44  scadaref
# Initial revision
#
# Revision 1.1  1999/03/01 13:42:15  scadaref
# Initial revision
#
# Revision 1.1  1997/10/27 18:49:08  scadaref
# Initial revision
#

include $(ROOTDIR)/config.mak

SUBLIBDIRTARGET = Scripts 

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
