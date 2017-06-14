# ----------------------------------------------------------------
# --

CXXFLAGS="-O3"

dnl Process this file with autoconf to produce a configure script.
AC_INIT(matis)
AC_CONFIG_SRCDIR([bootstrap])
AC_CONFIG_AUX_DIR(config)
PACKAGE=matis

AC_REVISION($Revision: 1.2 $) 
# That's the revision of this file.

#--------------------- DEFAULTS ----------------------------------

if eval "test x$prefix = xNONE"; then
 dprefix=$ac_default_prefix
else
 dprefix=$prefix
fi

matisdatadir=$dprefix/share/$PACKAGE
AC_DEFINE_UNQUOTED(MATISDATADIR, "$matisdatadir", "MATIS Data Directory")

# -------------------- VERSION MANAGEMENT -------------------------------

MATIS_MAJOR_VERSION=0
MATIS_MINOR_VERSION=8
MATIS_MICRO_VERSION=0

#
# +1 : ? : +1  == new interface that does not break old one
# +1 : ? : 0   == new interface that breaks old one
#  ? : ? : 0   == no new interfaces, but breaks apps
#  ? :+1 : ?   == just some internal changes, nothing breaks but might work
#                 better
# CURRENT : REVISION : AGE
LIBMATIS_SO_VERSION=0:8:0
LIBMATISRTI_SO_VERSION=0:8:0

MATIS_VERSION=$MATIS_MAJOR_VERSION.$MATIS_MINOR_VERSION.$MATIS_MICRO_VERSION
MATIS_RELEASE=$MATIS_MAJOR_VERSION.$MATIS_MINOR_VERSION

AC_DEFINE_UNQUOTED(MATIS_MAJOR_VERSION,$MATIS_MAJOR_VERSION, "MATIS Major Version")
AC_DEFINE_UNQUOTED(MATIS_MINOR_VERSION,$MATIS_MINOR_VERSION, "MATIS Minor Version")
AC_DEFINE_UNQUOTED(MATIS_MICRO_VERSION,$MATIS_MICRO_VERSION, "MATIS Micro Version")

AC_SUBST(LIBMATIS_SO_VERSION)
AC_SUBST(LIBMATISRTI_SO_VERSION)
AC_SUBST(MATIS_VERSION)
AC_SUBST(MATIS_MAJOR_VERSION)
AC_SUBST(MATIS_MINOR_VERSION)
AC_SUBST(MATIS_MICRO_VERSION)

VERSION=$MATIS_VERSION
# ---------------------------- STARTUP AUTOMAKE -------------------------
dnl For automake

AM_INIT_AUTOMAKE($PACKAGE,$VERSION)
#AC_SUBST($PACKAGE_NAME)
#AC_SUBST($PACKAGE_TARNAME)
#AC_SUBST($PACKAGE_VERSION)
#AC_SUBST($PACKAGE_STRING)
#AC_SUBST($PACKAGE_BUGREPORT)

#########################################################################
#  Configure arguments
#########################################################################

AC_ARG_ENABLE(threads,
[  --disable-threads       disables support threading  ],
enable_threads=$enableval,enable_threads="yes"
)

#########################################################################

AM_CONFIG_HEADER(matis-config.h:matis-config-h.in)

####################################### Initialise the test suite

# Initialize the test suite.
AC_CONFIG_TESTDIR(unittest)

#########################################################################
# AM_MAINTAINER_MODE

AM_MISSING_PROG([AUTOM4TE], [autom4te])
dnl Checks for programs.
AC_LIBTOOL_DLOPEN
AC_PROG_CC
AC_PROG_CPP
AC_PROG_MAKE_SET
AC_PROG_INSTALL
AM_PROG_CC_STDC
AM_PROG_LIBTOOL
AC_PROG_LIBTOOL
# AM_PROG_ETAGS
# AC_CHECK_PROG(ETAGS, ctags, ctags -e)

# AC_CANONICAL_HOST

AM_ENABLE_SHARED(yes)
AM_ENABLE_STATIC(yes)

# We DON'T need Perl
# ------------------
#dnl We need Perl
#dnl
#AC_CHECK_PROGS(PERL, perl5 perl, no)
#if test "$PERL" = "no"; then
#        AC_MSG_WARN([Perl5 is not installed])
#fi
# -------------------

dnl Checks for libraries.

dnl Checks for header files.

AC_HEADER_STDC

dnl GLIB_CFLAGS=`glib-config --cflags`
dnl AC_SUBST(GLIB_CFLAGS)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN
AC_C_CONST
AC_C_INLINE
AC_SUBST(host_alias)

# AM_PATH_GTK(1.2.7)
# AM_PATH_LIBGLADE(,[AC_MSG_ERROR([libglade is required to compile MATIS. Please check config.log.])],gnome)

# ----------------- Sources ------------------------------------------
#SUPPORT_H_FILES=`cd Support ; ls *.h | xargs echo`
#AC_SUBST(SUPPORT_H_FILES)

dnl Had to add these two lines below because 'prefix' and
dnl 'exec_prefix' will be set to NONE at this point unless the user
dnl specified them with a --prefix/--exec_prefix option.
dnl - GL

test "x$prefix" = xNONE && prefix=$ac_default_prefix
test "x$exec_prefix" = xNONE && exec_prefix='${prefix}'
test "x$datadir" = xNONE && datadir='${prefix}/share'

dnl C++ compiler feature check start here
dnl moved the c++ compiler a little to make the basename check work right..
AC_PROG_CXX
AC_LANG([C++])

# ------------------ MACROS ---------------------------------------------

#AM_PATH_SIGC(1.0.0,,
#[AC_MSG_ERROR([Libsigc++ is required to compile matis. Please check config.log.])])

AM_PATH_BOOST(,AC_MSG_ERROR([Boost is required to compile matis. Please check config.log.]))

#AM_PATH_STL(,AC_MSG_ERROR([STL is required to compile matis. Please check config.log.]))

AM_PATH_RTI(1.3.0,,
[AC_MSG_ERROR([RTI is required to compile matis. Please check config.log.])])

#GNOME_INIT_HOOK(gnome_ok=yes,nofail)
GNOME_XML_HOOK(xml_ok=yes,nofail)

AC_DEFUN([AC_DEFINE_DIR], [
  test "x$prefix" = xNONE && prefix="$ac_default_prefix"
  test "x$exec_prefix" = xNONE && exec_prefix='${prefix}'
  ac_define_dir=`eval echo [$]$2`
  ac_define_dir=`eval echo [$]ac_define_dir`
  ifelse($3, ,
    AC_DEFINE_UNQUOTED($1, "$ac_define_dir"),
    AC_DEFINE_UNQUOTED($1, "$ac_define_dir", $3))
])

#--------------------- DEFAULTS ----------------------------------


#AC_ARG_VAR(rtienv.sh-location, [The full path to the RTI's rtienv.sh script which defines the RTI environment variables RTI_HOME and RTI_BUILD_TYPE])


# ----------------------------------- SUBSTITUTIONS ---------------------

MATIS_INCLUDES='-I${top_builddir}/src/Support -I${top_builddir}/src/Support/RTI_13NG -I${top_builddir}/src/Interposer -I${top_builddir}/src/Interposer/RTI_13NG -I${top_builddir}/src/Model -I${top_builddir}/src/Model/LEAPBM/LAE -I${top_builddir}/src/Model/LEAPBM -I${top_builddir}/src '

GNOME_XML_CFLAGS=`xml2-config --cflags`
GNOME_XML_LIB=`xml2-config --libs`

# -----------
AC_SUBST(MATISDATADIR)
AC_SUBST(GNOME_XML_LIB)
AC_SUBST(GNOME_XML_CFLAGS)
AC_SUBST(GNOME_LIBS)
AC_SUBST(GNOME_LIBDIR)
AC_SUBST(GNOME_INCLUDEDIR)
#AC_SUBST(LIBGLADE_CFLAGS)
#AC_SUBST(LIBGLADE_LIBS)
AC_SUBST(RTI_LIBS)
AC_SUBST(RTI_CFLAGS)
AC_SUBST(ac_aux_dir)

AC_SUBST(MATIS_INCLUDES)
#---------------------------------- global flags ----------------------

CFLAGS=""
CPPFLAGS="-O3"
INCLUDES=' -I${top_srcdir}'
CFLAGS="$INCLUDES $CFLAGS"
CPPFLAGS="$INCLUDES $CPPFLAGS"
CXXFLAGS="$CPPFLAGS"

# --------------------------------- generated files --------------------
AC_CONFIG_FILES([
matis-config
matisrti
])
AC_OUTPUT([
Makefile 
src/Makefile
doc/Makefile
unittest/Makefile
unittest/atlocal
])



AC_CONFIG_COMMANDS([default],[[chmod a+x matis-config matisrti]],[[]])
#-----------------------------------------------------------------------
echo \
"------------------------------------------------------------------------
Configuration:

  Source code location:       ${srcdir}
  Host System Type:           ${host}
  Install path:               ${prefix}

  Compiler C:                 ${CC}
  Compiler flags:             ${CFLAGS}
  MATIS Includes:             ${MATIS_INCLUDES}
  Compiler C++:               ${CXX}
  Compiler flags:             ${CXXFLAGS}
  Libs:			      ${LIBS}
"
echo \
"  See matis-config.h for further configuration information."

echo "Module options: "
if test x"$have_boost" = "xtrue"; then
  echo "      boost (regular expression)"
fi
echo \
"------------------------------------------------------------------------"
