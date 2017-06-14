// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LibHookup.h,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $


#ifndef MATIS_LIBHOOKUP_H
#define MATIS_LIBHOOKUP_H

#include "MATIS_RTIAmbassador.h"
#include "MATIS_MessageLogger.h"
#include "MATIS_Types.h"

#include <string>

#ifdef _WIN32
#define FAKE_RTI_NAME FakeRTIambassador

#ifdef BROKEN_WIN32_INTERCEPT // didn't work with release build
#define FAKE_RTI_FIX_THIS \
   RTI::RTIambassador * pRTIamb = \
       reinterpret_cast<RTI::RTIambassador* >(this); \
   FakeRTIambassador* pglobal_FakeRTIambassador = \
       & (MATIS_LibHookup::global_FakeRTIambassador); \
   __asm { mov ecx, pglobal_FakeRTIambassador } \
   __asm { mov dword ptr [ ebp-4], ecx }
#define AMB_THIS pRTIamb

#else
#define FAKE_RTI_FIX_THIS \
   RTI::RTIambassador * pRTIamb = reinterpret_cast<RTI::RTIambassador* >(this);
#define AMB_THIS pRTIamb

#endif

#include "MATIS_FakeRTIambassador.h"

#else // non-windows
#define AMB_THIS this
#define FAKE_RTI_NAME RTI::RTIambassador
#define FAKE_RTI_FIX_THIS
#endif

/**
 * MATIS_LibHookup:
 */
class MATIS_LibHookup {
public:

    static MATIS::strHashType functionNames;
    static MATIS::strHashType functionNamesMangled;

    /**
     *
     */
    static std::string lookupFunctionName(std::string aInternalFunctionName);

#ifdef _WIN32
    static unsigned short lookupFunctionNumber(std::string aInternalFunctionName);

    static FakeRTIambassador globalFakeRTIambassador;
#endif

    /**
     *
     */
    static std::string lookupFunctionNameMangled(std::string aInternalFunctionName);

    /**
     *
     */
    static void *getFunctionPointer(std::string aInternalFuncName);

    /**
     *
     */
    static void initSymbolTable();

    /**
     *
     */
    static void checkInitialised();

    /**
     *
     */
    static void initialise();

    /**
     *
     */
    static void obtainHooks();
private:
    static bool libInitialised;

};

#endif                          // MATIS_LIBHOOKUP_H
