#ifndef FAAFederateAmbassador_h
#define FAAFederateAmbassador_h

#include "MyFederateAmbassador.h"

class FAAFederateAmbassador : public MyFederateAmbassador
{
public:
	FAAFederateAmbassador();
	~FAAFederateAmbassador() throw (RTI::FederateInternalError);
};

#endif