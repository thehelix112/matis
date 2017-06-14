// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_registerFederationSynchronizationPoint2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::registerFederationSynchronizationPoint(const char *label,
                                                           const char *theTag)
    throw(RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/

	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);

   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT2;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);
	TypeConversion_RTI_13NG::addMeta_PointLabel(&theaction, label);

	LOGMSG(3, "Requesting registerFederationSynchronisationPoint2\n");

	try {
	
		theaction.request();

	} catch(...) {

		throw;

	};
}
