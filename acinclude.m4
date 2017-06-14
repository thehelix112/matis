

# Author: David Andrews

# Configure paths for STL
# Based on Gtk-- script by Erik Andersen and Tero Pulkkinen 

dnl Test for boost libraries, and define BOOST_LOCATION
dnl   to be used as follows:
dnl AM_PATH_STL([ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]])
dnl
AC_DEFUN(AM_PATH_STL,
[dnl 
dnl Prefix options
dnl
AC_ARG_WITH(stl-location,
[  --with-stl-location=PREFIX
                  	          Prefix where Standard Template Libraries are installed (mandatory).
                              Example: '/usr/include/g++-v3/']
, stl_location="$withval", stl_location="/usr/include/g++-v3/")

AC_ARG_ENABLE(stl, 
[  --disable-stl      Do not require Standard Template libraries.],
, require_stl=yes)

dnl
dnl Do we require stl?
dnl
  if test x$require_stl = "xyes"; then

	AC_MSG_CHECKING(for STL Includes...)

    if test x$stl_location != x ; then
	  STL_LOCATION=$stl_location
    else
	  no_stl=yes
	  AC_MSG_RESULT(no)
    fi

	if test "x$no_stl" != "xyes" ; then
		dnl
		dnl See if stl is installed 
		dnl
		AC_CHECK_FILE($STL_LOCATION/ext/hash_map, STL_FOUND=yes, STL_FOUND=no)

	  	no_stl=""
	  	if test x$STL_FOUND = xno ; then
	    	no_stl=yes
	  	fi
	fi

  	dnl
	dnl
  	if test "x$no_stl" = x ; then
     	ifelse([$1], , :, [$1])     
  	else
     	ifelse([$2], , :, [$2])
  	fi

  	dnl AC_LANG_RESTORE

  	AC_SUBST(STL_LOCATION)

  fi


])

# Configure paths for RTI
# Based on Gtk-- script by Erik Andersen and Tero Pulkkinen 

dnl Test for boost libraries, and define BOOST_LOCATION
dnl   to be used as follows:
dnl AM_PATH_BOOST([ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]])
dnl
AC_DEFUN(AM_PATH_BOOST,
[dnl 
dnl Prefix options
dnl
AC_ARG_WITH(boost-location,
[  --with-boost-location=PREFIX
                          Prefix where boost is installed (mandatory)]
, boost_location="$withval", boost_location="")

AC_ARG_ENABLE(boost, 
[  --disable-boost      Do not require boost libraries.],
, require_boost=yes)

dnl
dnl Do we require boost?
dnl
  if test x$require_boost = "xyes"; then

	AC_MSG_CHECKING(for Boost Libraries...)

    if test x$boost_location != x ; then
	  BOOST_LOCATION=$boost_location
    else
	  no_boost=yes
	  AC_MSG_RESULT(no)
    fi

	if test "x$no_boost" != "xyes" ; then

		dnl
		dnl See if boost is installed 
		dnl
		AC_CHECK_FILE($BOOST_LOCATION/graph/graph_utility.hpp, BOOST_FOUND=yes, BOOST_FOUND=no)

	  	no_boost=""
	  	if test x$BOOST_FOUND = xno ; then
	    	no_boost=yes
  		fi

	fi

  	dnl
	dnl
  	if test "x$no_boost" = x ; then
     	ifelse([$1], , :, [$1])     
  	else
     	ifelse([$2], , :, [$2])
  	fi

  	dnl AC_LANG_RESTORE

  	AC_SUBST(BOOST_LOCATION)

  fi


])



# Author: John Wharington <jwharington@bigfoot.com>



# Configure paths for RTI
# Based on Gtk-- script by Erik Andersen and Tero Pulkkinen 

dnl Test for RTI, and define RTI_CFLAGS and RTI_LIBS
dnl   to be used as follows:
dnl AM_PATH_RTI(MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]])
dnl
AC_DEFUN(AM_PATH_RTI,
[dnl 
dnl Prefix options
dnl
AC_ARG_WITH(rti-prefix,
[  --with-rti-prefix=PREFIX
                          Prefix where RTI is installed (optional)]
, rti_config_prefix="$withval", rti_config_prefix="/home/dave/Work/HLA/RTI-1.3NGv5/Linux-rh7.2-i386-gcc-3.0.2-opt-mt")

AC_ARG_WITH(rti-exec-prefix,
[  --with-rti-exec-prefix=PREFIX 
                          Exec prefix where  RTI is installed (optional)]
, rti_config_exec_prefix="$withval", rti_config_exec_prefix="")

AC_ARG_ENABLE(rtitest, 
[  --disable-rtitest     Do not try to compile and run a test RTI 
                          program],
, enable_rtitest=yes)

dnl
dnl Prefix handling
dnl
  if test x$rti_config_exec_prefix != x ; then
     rti_config_args="$rti_config_args --exec-prefix=$rti_config_exec_prefix"
     if test x${RTI_CONFIG+set} != xset ; then
        RTI_CONFIG=$rti_config_exec_prefix/bin/rti-config
     fi
  fi
  if test x$rti_config_prefix != x ; then
     rti_config_args="$rti_config_args --prefix=$rti_config_prefix"
     if test x${RTI_CONFIG+set} != xset ; then
        RTI_CONFIG=$rti_config_prefix/bin/rti-config
     fi
  fi

dnl
dnl See if rti-config is alive
dnl
  AC_PATH_PROG(RTI_CONFIG, rti-config, no)
  rti_version_min=$1

  no_rti=""
  if test "$RTI_CONFIG" = "no" ; then
    no_rti=yes
	AC_MSG_ERROR([rti-config not found. Please check config.log.])
  fi
	

dnl
dnl  Version check
dnl
  AC_MSG_CHECKING(for RTI - version >= $rti_version_min)
  rti_version=`$RTI_CONFIG --version`

  RTI_CFLAGS=`$RTI_CONFIG $rti_config_args --cflags`
  RTI_LIBS=`$RTI_CONFIG $rti_config_args --libs`

dnl should really check version here...

  rti_major_version=`echo $rti_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
  rti_minor_version=`echo $rti_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
  rti_micro_version=`echo $rti_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

  if test "X$no_rti" = "Xyes" ; then
      enable_rtitest=no
  fi

  AC_LANG_SAVE
  AC_LANG_CPLUSPLUS

  rti_major_version=1
  rti_minor_version=3
  rti_micro_version=0
dnl
dnl
dnl
  if test "x$enable_rtitest" = "xyes" ; then
    AC_MSG_CHECKING(if rti sane)
    ac_save_CXXFLAGS="$CXXFLAGS"
    ac_save_LIBS="$LIBS"
    CXXFLAGS="-g -O3 $RTI_CFLAGS"
    LIBS="$LIBS $RTI_LIBS"
    rm -f conf.rtitest
    AC_TRY_RUN([
#include <stdio.h>
#include <RTI.hh>

int main(int argc,char **argv)
  {
   RTI::RTIambassador rtiAmb;

   if (RTI_MAJOR_VERSION!=$rti_major_version ||
        RTI_MINOR_VERSION!=$rti_minor_version)
     { printf("(%d.%d.%d) ",
         RTI_MAJOR_VERSION,RTI_MINOR_VERSION,0);
         return 1;
     }
   return 0;

  }

],[
  AC_MSG_RESULT(yes)
],[
  AC_MSG_RESULT(no)
  no_rti=yes
]
,[echo $ac_n "cross compiling; assumed OK... $ac_c"])

     CXXFLAGS="$ac_save_CXXFLAGS"
     LIBS="$ac_save_LIBS"
   fi

  dnl
  dnl
  if test "x$no_rti" = x ; then
     ifelse([$2], , :, [$2])     
  else
     RTI_CFLAGS=""
     RTI_LIBS=""
dnl     RTI_MACROS=""
     ifelse([$3], , :, [$3])
  fi

  AC_LANG_RESTORE

  AC_SUBST(RTI_CFLAGS)
  AC_SUBST(RTI_LIBS)
dnl  AC_SUBST(RTI_MACROS)
])


# Configure paths for Libsigc++
# Based on Gtk-- script by Erik Andersen and Tero Pulkkinen 

dnl Test for Libsigc++, and define SIGC_CFLAGS and SIGC_LIBS
dnl   to be used as follows:
dnl AM_PATH_SIGC(MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]])
dnl
AC_DEFUN(AM_PATH_SIGC,
[dnl 
dnl Get the cflags and libraries from the sigc-config script
dnl

dnl
dnl Prefix options
dnl
AC_ARG_WITH(sigc-prefix,
[  --with-sigc-prefix=PREFIX
                          Prefix where libsigc++ is installed (optional)]
, sigc_config_prefix="$withval", sigc_config_prefix="")

AC_ARG_WITH(sigc-exec-prefix,
[  --with-sigc-exec-prefix=PREFIX 
                          Exec prefix where  libsigc++ is installed (optional)]
, sigc_config_exec_prefix="$withval", sigc_config_exec_prefix="")

AC_ARG_ENABLE(sigctest, 
[  --disable-sigctest     Do not try to compile and run a test libsigc++ 
                          program],
, enable_sigctest=yes)

dnl
dnl Prefix handling
dnl
  if test x$sigc_config_exec_prefix != x ; then
     sigc_config_args="$sigc_config_args --exec-prefix=$sigc_config_exec_prefix"
     if test x${SIGC_CONFIG+set} != xset ; then
        SIGC_CONFIG=$sigc_config_exec_prefix/bin/sigc-config
     fi
  fi
  if test x$sigc_config_prefix != x ; then
     sigc_config_args="$sigc_config_args --prefix=$sigc_config_prefix"
     if test x${SIGC_CONFIG+set} != xset ; then
        SIGC_CONFIG=$sigc_config_prefix/bin/sigc-config
     fi
  fi

dnl
dnl See if sigc-config is alive
dnl
  AC_PATH_PROG(SIGC_CONFIG, sigc-config, no)
  sigc_version_min=$1

dnl
dnl  Version check
dnl
  AC_MSG_CHECKING(for libsigc++ - version >= $sigc_version_min)
  no_sigc=""
  if test "$SIGC_CONFIG" = "no" ; then
    no_sigc=yes
  else
    sigc_version=`$SIGC_CONFIG --version`

    SIGC_CFLAGS=`$SIGC_CONFIG $sigc_config_args --cflags`
    SIGC_LIBS=`$SIGC_CONFIG $sigc_config_args --libs`
    SIGC_MACROS=`$SIGC_CONFIG $sigc_config_args --macros`

    sigc_major_version=`echo $sigc_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
    sigc_minor_version=`echo $sigc_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
    sigc_micro_version=`echo $sigc_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

    sigc_major_min=`echo $sigc_version_min | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
    sigc_minor_min=`echo $sigc_version_min | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
    sigc_micro_min=`echo $sigc_version_min | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

    sigc_version_proper=`expr \
        $sigc_major_version \> $sigc_major_min \| \
        $sigc_major_version \= $sigc_major_min \& \
        $sigc_minor_version \> $sigc_minor_min \| \
        $sigc_major_version \= $sigc_major_min \& \
        $sigc_minor_version \= $sigc_minor_min \& \
        $sigc_micro_version \>= $sigc_micro_min `

    if test "$sigc_version_proper" = "1" ; then
      AC_MSG_RESULT([$sigc_major_version.$sigc_minor_version.$sigc_micro_version])
    else
      AC_MSG_RESULT(no)
      no_sigc=yes
    fi

    if test "X$no_sigc" = "Xyes" ; then
      enable_sigctest=no
    fi

    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS

dnl
dnl
dnl
    if test "x$enable_sigctest" = "xyes" ; then
      AC_MSG_CHECKING(if libsigc++ sane)
      ac_save_CXXFLAGS="$CXXFLAGS"
      ac_save_LIBS="$LIBS"
      CXXFLAGS="$CXXFLAGS $SIGC_CFLAGS"
      LIBS="$LIBS $SIGC_LIBS"

      rm -f conf.sigctest
      AC_TRY_RUN([
#include <stdio.h>
#include <sigc++/signal_system.h>

#ifdef SIGC_CXX_NAMESPACES
using namespace SigC;
#endif

int foo1(int i) 
  {
   return 1;
  }

int main(int argc,char **argv)
  {
   if (sigc_major_version!=$sigc_major_version ||
       sigc_minor_version!=$sigc_minor_version ||
       sigc_micro_version!=$sigc_micro_version)
     { printf("(%d.%d.%d) ",
         sigc_major_version,sigc_minor_version,sigc_micro_version);
       return 1;
     }
   Signal1<int,int> sig1;
   sig1.connect(slot(foo1));
   sig1(1);
   return 0;
  }

],[
  AC_MSG_RESULT(yes)
],[
  AC_MSG_RESULT(no)
  no_sigc=yes
]
,[echo $ac_n "cross compiling; assumed OK... $ac_c"])

       CXXFLAGS="$ac_save_CXXFLAGS"
       LIBS="$ac_save_LIBS"
     fi
  fi

  dnl
  dnl
  if test "x$no_sigc" = x ; then
     ifelse([$2], , :, [$2])     
  else
     SIGC_CFLAGS=""
     SIGC_LIBS=""
     SIGC_MACROS=""
     ifelse([$3], , :, [$3])
  fi

  AC_LANG_RESTORE

  AC_SUBST(SIGC_CFLAGS)
  AC_SUBST(SIGC_LIBS)
  AC_SUBST(SIGC_MACROS)
])




 

dnl
dnl GNOME_INIT_HOOK (script-if-gnome-enabled, [failflag], [additional-inits])
dnl
dnl if failflag is "fail" then GNOME_INIT_HOOK will abort if gnomeConf.sh
dnl is not found. 
dnl

AC_DEFUN([GNOME_INIT_HOOK],[
	AC_SUBST(GNOME_LIBS)
	AC_SUBST(GNOMEUI_LIBS)
	AC_SUBST(GNOMEGNORBA_LIBS)
	AC_SUBST(GTKXMHTML_LIBS)
	AC_SUBST(ZVT_LIBS)
	AC_SUBST(GNOME_LIBDIR)
	AC_SUBST(GNOME_INCLUDEDIR)

	AC_ARG_WITH(gnome-includes,
	[  --with-gnome-includes   Specify location of GNOME headers],[
	CFLAGS="$CFLAGS -I$withval"
	])
	
	AC_ARG_WITH(gnome-libs,
	[  --with-gnome-libs       Specify location of GNOME libs],[
	LDFLAGS="$LDFLAGS -L$withval"
	gnome_prefix=$withval
	])

	AC_ARG_WITH(gnome,
	[  --with-gnome            Specify prefix for GNOME files],
		if test x$withval = xyes; then
	    		want_gnome=yes
	    		dnl Note that an empty true branch is not
			dnl valid sh syntax.
	    		ifelse([$1], [], :, [$1])
        	else
	    		if test "x$withval" = xno; then
	        		want_gnome=no
	    		else
	        		want_gnome=yes
	    			LDFLAGS="$LDFLAGS -L$withval/lib"
	    			CFLAGS="$CFLAGS -I$withval/include"
	    			gnome_prefix=$withval/lib
	    		fi
  		fi,
		want_gnome=yes)

	if test "x$want_gnome" = xyes; then

	    AC_PATH_PROG(GNOME_CONFIG,gnome-config,no)
	    if test "$GNOME_CONFIG" = "no"; then
	      no_gnome_config="yes"
	    else
	      AC_MSG_CHECKING(if $GNOME_CONFIG works)
	      if $GNOME_CONFIG --libs-only-l gnome >/dev/null 2>&1; then
	        AC_MSG_RESULT(yes)
	        GNOME_GNORBA_HOOK([],$2)
	        GNOME_LIBS="`$GNOME_CONFIG --libs-only-l gnome`"
	        GNOMEUI_LIBS="`$GNOME_CONFIG --libs-only-l gnomeui`"
	        GNOMEGNORBA_LIBS="`$GNOME_CONFIG --libs-only-l gnorba gnomeui`"
	        GTKXMHTML_LIBS="`$GNOME_CONFIG --libs-only-l gtkxmhtml`"
		ZVT_LIBS="`$GNOME_CONFIG --libs-only-l zvt`"
	        GNOME_LIBDIR="`$GNOME_CONFIG --libs-only-L gnorba gnomeui`"
	        GNOME_INCLUDEDIR="`$GNOME_CONFIG --cflags gnorba gnomeui`"
                $1
	      else
	        AC_MSG_RESULT(no)
	        no_gnome_config="yes"
              fi
            fi

	    if test x$exec_prefix = xNONE; then
	        if test x$prefix = xNONE; then
		    gnome_prefix=$ac_default_prefix/lib
	        else
 		    gnome_prefix=$prefix/lib
	        fi
	    else
	        gnome_prefix=`eval echo \`echo $libdir\``
	    fi
	
	    if test "$no_gnome_config" = "yes"; then
              AC_MSG_CHECKING(for gnomeConf.sh file in $gnome_prefix)
	      if test -f $gnome_prefix/gnomeConf.sh; then
	        AC_MSG_RESULT(found)
	        echo "loading gnome configuration from" \
		     "$gnome_prefix/gnomeConf.sh"
	        . $gnome_prefix/gnomeConf.sh
	        $1
	      else
	        AC_MSG_RESULT(not found)
 	        if test x$2 = xfail; then
	          AC_MSG_ERROR(Could not find the gnomeConf.sh file that is generated by gnome-libs install)
 	        fi
	      fi
            fi
	fi

	if test -n "$3"; then
	  n="$3"
	  for i in $n; do
	    AC_MSG_CHECKING(extra library \"$i\")
	    case $i in 
	      applets)
		AC_SUBST(GNOME_APPLETS_LIBS)
		GNOME_APPLETS_LIBS=`$GNOME_CONFIG --libs-only-l applets`
		AC_MSG_RESULT($GNOME_APPLETS_LIBS);;
	      docklets)
		AC_SUBST(GNOME_DOCKLETS_LIBS)
		GNOME_DOCKLETS_LIBS=`$GNOME_CONFIG --libs-only-l docklets`
		AC_MSG_RESULT($GNOME_DOCKLETS_LIBS);;
	      capplet)
		AC_SUBST(GNOME_CAPPLET_LIBS)
		GNOME_CAPPLET_LIBS=`$GNOME_CONFIG --libs-only-l capplet`
		AC_MSG_RESULT($GNOME_CAPPLET_LIBS);;
	      *)
		AC_MSG_RESULT(unknown library)
	    esac
	  done
	fi
])

dnl
dnl GNOME_INIT ([additional-inits])
dnl

AC_DEFUN([GNOME_INIT],[
	GNOME_INIT_HOOK([],fail,$1)
])

dnl
dnl GNOME_GNORBA_HOOK (script-if-gnorba-found, failflag)
dnl
dnl if failflag is "failure" it aborts if gnorba is not found.
dnl

AC_DEFUN([GNOME_GNORBA_HOOK],[
	GNOME_ORBIT_HOOK([],$2)
	AC_CACHE_CHECK([for gnorba libraries],gnome_cv_gnorba_found,[
		gnome_cv_gnorba_found=no
		if test x$gnome_cv_orbit_found = xyes; then
			GNORBA_CFLAGS="`gnome-config --cflags gnorba gnomeui`"
			GNORBA_LIBS="`gnome-config --libs gnorba gnomeui`"
			if test -n "$GNORBA_LIBS"; then
				gnome_cv_gnorba_found=yes
			fi
		fi
	])
	AM_CONDITIONAL(HAVE_GNORBA, test x$gnome_cv_gnorba_found = xyes)
	if test x$gnome_cv_orbit_found = xyes; then
		$1
		GNORBA_CFLAGS="`gnome-config --cflags gnorba gnomeui`"
		GNORBA_LIBS="`gnome-config --libs gnorba gnomeui`"
		AC_SUBST(GNORBA_CFLAGS)
		AC_SUBST(GNORBA_LIBS)
	else
	    	if test x$2 = xfailure; then
			AC_MSG_ERROR(gnorba library not installed or installation problem)
	    	fi
	fi
])

AC_DEFUN([GNOME_GNORBA_CHECK], [
	GNOME_GNORBA_HOOK([],failure)
])

dnl
dnl GNOME_ORBIT_HOOK (script-if-orbit-found, failflag)
dnl
dnl if failflag is "failure" it aborts if orbit is not found.
dnl

AC_DEFUN([GNOME_ORBIT_HOOK],[
	AC_PATH_PROG(ORBIT_CONFIG,orbit2-config,no)
	AC_PATH_PROG(ORBIT_IDL,orbit-idl-2,no)
	AC_CACHE_CHECK([for working ORBit environment],gnome_cv_orbit_found,[
		if test x$ORBIT_CONFIG = xno -o x$ORBIT_IDL = xno; then
			gnome_cv_orbit_found=no
		else
			gnome_cv_orbit_found=yes
		fi
	])
	AM_CONDITIONAL(HAVE_ORBIT, test x$gnome_cv_orbit_found = xyes)
	if test x$gnome_cv_orbit_found = xyes; then
		$1
		ORBIT_CFLAGS=`orbit2-config --cflags client server`
		ORBIT_LIBS=`orbit2-config --use-service=name --libs client server`
		AC_SUBST(ORBIT_CFLAGS)
		AC_SUBST(ORBIT_LIBS)
	else
    		if test x$2 = xfailure; then
			AC_MSG_ERROR(ORBit not installed or installation problem)
    		fi
	fi
])

AC_DEFUN([GNOME_ORBIT_CHECK], [
	GNOME_ORBIT_HOOK([],failure)
])

dnl
dnl GNOME_XML_HOOK (script-if-xml-found, failflag)
dnl
dnl If failflag is "failure", script aborts due to lack of XML
dnl 
dnl Check for availability of the libxml library
dnl the XML parser uses libz if available too
dnl

AC_DEFUN([GNOME_XML_HOOK],[
	AC_PATH_PROG(LIBXML2_CONFIG,xml2-config,no)
	if test "$LIBXML2_CONFIG" = no; then
		if test x$2 = xfailure; then
			AC_MSG_ERROR(Could not find xml2-config)
		fi
	fi
	AC_CHECK_LIB(xml2, xmlNewDoc, [
		$1
		GNOME_XML_LIB=`$LIBXML2_CONFIG --libs`
	], [
		if test x$2 = xfailure; then 
			AC_MSG_ERROR(Could not link sample xml program)
		fi
	], `$LIBXML2_CONFIG --libs`)
	AC_SUBST(GNOME_XML_LIB)
])

AC_DEFUN([GNOME_XML_CHECK], [
	GNOME_XML_HOOK([],failure)
])

