// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Macros.h,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $





#ifndef MATIS_COMMON_H
#define MATIS_COMMON_H 1

#ifndef MATIS_CONFIG_H
#define MATIS_CONFIG_H 1
#include "matis-config.h"
#endif
#include <iostream>

#include "MATIS_MessageLogger.h"

// for historical purposes
#ifndef _WIN32
#define DEBUGCTX \
         __FILE__ << ":" << __LINE__ << ": "        \
         << __PRETTY_FUNCTION__ << ": "
#else
#define DEBUGCTX \
         __FILE__ << ":" << __LINE__ << ": "        \
         << ": "
#endif

#define DEBUG 1 // on by default.  We need it!

// new interface
#ifdef DEBUG
#ifdef _WIN32
#define LOGMSGX(x,y,z)                                      \
  if (MATIS::MessageLogger::getLogger()->willWrite(x)) {    \
    if (MATIS::MessageLogger::getLogger()->willContext()) { \
      std::cout << __FILE__ << ":" << __LINE__ << ": "      \
	            << ": \n";           \
    }                                                       \
    std::cout << y;                                         \
    z; \
  }
#else
#define LOGMSGX(x,y,z)                                      \
  if (MATIS::MessageLogger::getLogger()->willWrite(x)) {    \
    if (MATIS::MessageLogger::getLogger()->willContext()) { \
      std::cout << __FILE__ << ":" << __LINE__ << ": "      \
	            << __PRETTY_FUNCTION__ << ": \n";           \
    }                                                       \
    std::cout << y;                                         \
    z; \
  }
#endif
#else
#define LOGMSGX(x,y,z) // x y z
#endif
#define LOGMSG(x,y) { LOGMSGX(x,y,{}) }
#define LOGERR(x) { LOGMSG(0, "Error: " << x); exit(1); }
#define LOGWRN(x) { LOGMSG(0, "Warning: " << x) }

/* LOGGING LEVELS

  0 - Critical messages such as errors and warnings.
  1 - 
  2 -
  3 -
  4 -
  5 - All available non-debugging output.
  9 - 
*/

#ifdef STRING_AS_HEX
#define STRING_AS_HEX(aString)                                         \
{                                                                      \
	char *blah = new char[aString.length()];		                   \
	blah = (char*)aString.c_str();		                               \
	std::cout << "String Length: " << aString.length() <<              \
          "\n   Value: ";		                                       \
	for(int i = 0; i < aString.length(); i++){                         \
		printf("%x", blah[i]);                                         \
	}                                                                  \
	std::cout << "\n";		                                           \
}
#else
#define STRING_AS_HEX(aString)
#endif

#endif
