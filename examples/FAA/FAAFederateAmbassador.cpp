#include "FAAFederateAmbassador.h"

#if !defined(WIN32) && !defined(VXWORKS) && !defined(__KCC) && (__SUNPRO_CC_COMPAT != 5)
#  include <stream.h>
#else
#  include <iostream.h>
#endif

FAAFederateAmbassador::FAAFederateAmbassador()
{
}

FAAFederateAmbassador::~FAAFederateAmbassador() throw (RTI::FederateInternalError)
{
}