
CXXFLAGS = $(AM_CXXFLAGS) $(SIGC_CFLAGS) $(RTI_CFLAGS) $(GNOME_XML_CFLAGS) -g -pg
INCLUDES = $(DSILI_INCLUDES) -I/home/boost_1_28_0 -I/usr/include/g++-v3/ext

noinst_PROGRAMS = 
#testmodel_SOURCES = testmodel.cpp
#testmodel_LDFLAGS =  ${top_builddir}/exp/libDSILIRTI.la
# ---------------------------------------------------

DISTCLEANFILES       = atconfig 
MAINTAINERCLEANFILES = Makefile.in $(TESTSUITE)

## ------------ ##
## package.m4.  ##
## ------------ ##

$(srcdir)/package.m4: $(top_srcdir)/configure.ac
	{					\
	  echo '# Signature of the current package.'; \
	  echo 'm4_define([AT_PACKAGE_NAME],      [@PACKAGE_NAME@])'; \
	  echo 'm4_define([AT_PACKAGE_TARNAME],   [@PACKAGE_TARNAME@])'; \
	  echo 'm4_define([AT_PACKAGE_VERSION],   [@PACKAGE_VERSION@])'; \
	  echo 'm4_define([AT_PACKAGE_STRING],    [@PACKAGE_STRING@])'; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [@PACKAGE_BUGREPORT@])'; \
	} >$(srcdir)/package.m4

## ------------ ##
## Test suite.  ##
## ------------ ##

TESTSUITE_AT = \
	testsuite.at 
TESTSUITE = $(srcdir)/testsuite

EXTRA_DIST = $(TESTSUITE_AT) testsuite package.m4

AUTOTEST = $(AUTOM4TE) --language=autotest

#$(srcdir)/$(TESTSUITE): package.m4 $(TESTSUITE_AT)
#	$(AUTOTEST) -I $(srcdir) testsuite.at -o $@.tmp
#	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && ./config.status tests/$@

clean-local:
	$(SHELL) $(TESTSUITE) --clean

check-local: atconfig atlocal $(TESTSUITE)
	$(SHELL) $(TESTSUITE)

# Run the test suite on the *installed* tree.
installcheck-local:
	$(SHELL) $(TESTSUITE) AUTOTEST_PATH=$(exec_prefix)/bin

#############################
# another way
testeverything: $(TESTSUITE)
	$(TESTSUITE)


clean:	clean-local
	echo "clean"
