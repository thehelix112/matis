// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LibHookup.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.4 $


#include "MATIS_LibHookup.h"
#include "MATIS_ConfigurationStore.h"

#include <iostream>
#include <stdio.h>
#include <map>

#ifndef _WIN32 ////////////////////////////////////////////////////////////////////

// unix flavors

#include <dlfcn.h>
#define RTLD_NEXT ((void *) -1l)

#else ///////////////////////////////////////////////////////////////////////////////

// windows

#include "stdafx.h"
#include "MATISRTI.h"
#include <shlwapi.h>		// PathStripPath()

// HINSTANCE hDLL;
// Function pointer types
//typedef HMODULE (WINAPI *LoadLibrary_Type)(LPCSTR lpLibFileName);
//typedef HMODULE (WINAPI *LoadLibraryEx_Type)(LPCTSTR lpFileName, HANDLE hFile, DWORD dwFlags);

// Function prototypes.

HMODULE WINAPI MATIS_LoadLibraryA(LPCSTR lpLibFileName);
HMODULE WINAPI MATIS_LoadLibraryW(LPCSTR lpLibFileName);
HMODULE WINAPI MATIS_LoadLibraryExA(LPCTSTR lpFileName, HANDLE hFile, DWORD dwFlags);
HMODULE WINAPI MATIS_LoadLibraryExW(LPCTSTR lpFileName, HANDLE hFile, DWORD dwFlags);

// Hook structure

#include "MATIS_LibHookup_SymbolTable_w32_funcptrs.cpp"
#include "MATIS_LibHookup_SymbolTable_w32_hookstruct.cpp"
#include "MATIS_LibHookup_SymbolTable_w32_hookenum.cpp"

FakeRTIambassador MATIS_LibHookup::global_FakeRTIambassador;

#endif ///////////////////////////////////////////////////////////////////////////////


MATIS::strHashType MATIS_LibHookup::functionNames;
MATIS::strHashType MATIS_LibHookup::functionNamesMangled;
bool MATIS_LibHookup::libInitialised = 0;

void MATIS_LibHookup::initialise(){

    libInitialised = 1;
    MATIS::MessageLogger::getLogger();
    //MATIS_Interface::init();
    initSymbolTable();
    obtainHooks();
    //MATIS::PluginStore::getStore()->initialise();
    //MATIS::Honcho::init();
    MATIS::ConfigurationStore::initialise();

    LOGMSG(2,"\n======================================================================\n");

}

void MATIS_LibHookup::checkInitialised(){

    if (!libInitialised) {

        initialise();

    }

}

void *MATIS_LibHookup::getFunctionPointer(std::string aInternalFunctionName){

    void *retVal = NULL;

    std::string functionName = lookupFunctionName(aInternalFunctionName);
    std::string functionNameMangled = lookupFunctionNameMangled(aInternalFunctionName);
    retVal = dlsym(RTLD_NEXT, functionNameMangled.c_str());

    //LOGMSG(1, "pointer to next function for: " << aInternalFunctionName << " is: " << retVal << "\n");

    if (!retVal) {

        LOGMSG(2, "Binding symbol \"" << functionName << "\"");
        LOGMSG(2, " not found!\n");
        exit(1);

    }

    return retVal;
}

std::string MATIS_LibHookup::lookupFunctionNameMangled(std::string aInternalFunctionName){

    std::string retVal = functionNamesMangled[aInternalFunctionName.c_str()];

    if (retVal.length() == 0) {

        LOGMSG(2, "Error: Symbol `" << aInternalFunctionName << "' not found in mangle table\n");
        retVal = " ";
        exit(1);

    }

    return retVal;
}

std::string MATIS_LibHookup::lookupFunctionName(std::string aInternalFunctionName)
{

    std::string retVal = functionNames[aInternalFunctionName.c_str()];

    if (retVal.length() == 0) {

        LOGMSG(2, "Error: Symbol `" << aInternalFunctionName << "' not found in mangle table\n");
        retVal = " ";
        exit(1);

    }

    return retVal;
}

#ifdef _WIN32

MATIS::strUIntHashType functionNumbers;

unsigned short MATIS_LibHookup::lookupFunctionNumber(std::string aInternalFunctionName){

 LOGERR("Deprecated\n");
 
 /*
	unsigned short retval = funcnums[aInternalFunctionName.c_str()];
    if (funcnums.find(internalfuncnams.c_str() == 
			funcnums.end()) {
        LOGMSG(2, "Error: Symbol "
            << aInternalFunctionName << " not found in mangle table\n");
        exit(1);
    }
    return retval;
*/
  return 0;
  
}

#endif

void MATIS_LibHookup::initSymbolTable(){
  
    LOGMSG(1, "  Binding symbol table....................  ");

#include "MATIS_LibHookup_SymbolTable_RTI_13NG.cpp"

    LOGMSG(1, "DONE\n");

}

void MATIS_LibHookup::obtainHooks(){

#ifndef _WIN32

    LOGMSG(1, "  Obtain Function Pointer Hooks...........  ");

#include "MATIS_LibHookup_ObtainHooks_RTI_13NG.cpp"

    LOGMSG(1, "DONE\n");

#endif

}

#ifndef _WIN32

#include "MATIS_LibHookup_HookInit_RTI_13NG.cpp"

#endif




