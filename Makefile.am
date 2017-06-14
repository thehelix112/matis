bin_SCRIPTS = matis-config \
		matisrti

## @start 1
AUX_DIST                = $(ac_aux_dir)/config.guess \
                        $(ac_aux_dir)/config.sub \
                        $(ac_aux_dir)/install-sh \
                        $(ac_aux_dir)/ltconfig \
                        $(ac_aux_dir)/ltmain.sh \
                        $(ac_aux_dir)/mdate-sh \
                        $(ac_aux_dir)/missing \
                        $(ac_aux_dir)/mkinstalldirs

AUX_DIST_EXTRA          = \
                        $(ac_aux_dir)/rti.m4 \
                        $(ac_aux_dir)/sigc.m4

EXTRA_DIST              = bootstrap \
			  matis-config.in \
			  matisrti.in

## @end1

# These subdirectories must remain in this order so that
# the libraries can be built in bootstrap.
SUBDIRS			= src \
			  doc \
			  unittest

## @start 1
MAINTAINERCLEANFILES    = Makefile.in aclocal.m4 configure config-h.in \
                        stamp-h.in $(AUX_DIST)

## @end 1
ACLOCAL                 = aclocal -I $(ac_aux_dir)


worktags:
	ctags -e -R

## @start 1
dist-hook:
	(cd $(distdir) && mkdir -p $(ac_aux_dir))
	for file in $(AUX_DIST) $(AUX_DIST_EXTRA); do \
	  cp $$file $(distdir)/$$file; \
	done
## @end 1

