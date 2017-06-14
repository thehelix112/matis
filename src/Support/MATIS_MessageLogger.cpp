// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_MessageLogger.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#include "MATIS_MessageLogger.h"
#include "MATIS_Macros.h"
#include <stdlib.h>
#include <stdio.h>

using namespace MATIS;


bool MessageLogger::willWrite(int aLevel) {

  return (aLevel <= filterLevel);

}

bool MessageLogger::willContext() {

  return displayContext;

}

MessageLogger* MessageLogger::getLogger(){

  if (loggerInstance == 0) {

      loggerInstance = new MessageLogger();
      
      // Default values
      loggerInstance->displayContext = false;
      loggerInstance->filterLevel = 0;
      //
      
      char *fenv = getenv("MATIS_DEBUGLEVEL");
      
      if (fenv != NULL) {
          
          sscanf(fenv,"%d",&(loggerInstance->filterLevel));
          std::cout << "Debug level " << loggerInstance->filterLevel << "\n";
          
      }
      
      char *genv = getenv("MATIS_DEBUGCONTEXT");
      
      if (genv != NULL) {
          
          std::cout << "Debug context ON\n";
          loggerInstance->displayContext = true;
          
      }
      
  }
  
  return loggerInstance;

}

MessageLogger * MessageLogger::loggerInstance= 0;

MessageLogger::MessageLogger(){

  filterLevel= 0;
  displayContext= true;

  std::cout
	  << "\n======================================================================\n"
	  << PACKAGE << " version " << VERSION << "\n"
	  << "Copyright 2004 David Andrews\n"
	  << " All rights reserved.\n"
	  << "======================================================================\n\n";

}

void MessageLogger::write(int aLevel, 
                          std::string aMessage, 
                          std::string aFile,
                          int aLine, 
                          std::string aFunction){

  if (willWrite(aLevel)) {

    if (displayContext) {

      std::cout << aFile << ":"<< aLine<<": "<< aFunction << ": \n";

    }

    std::cout << aMessage;

  }

}


