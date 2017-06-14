// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_sendInteractionWithRegion4.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::sendInteractionWithRegion(RTI::InteractionClassHandle theInteraction,
                                              const RTI::ParameterHandleValuePairSet& theParameters,
                                              const char* theTag,
                                              const RTI::Region& theRegion)
    throw(RTI::InteractionClassNotDefined,
          RTI::InteractionClassNotPublished,
          RTI::InteractionParameterNotDefined,
          RTI::RegionNotKnown,
          RTI::InvalidRegionContext,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::InteractionClassNotDefined,
   RTI::InteractionClassNotPublished,
   RTI::InteractionParameterNotDefined,
   RTI::RegionNotKnown,
   RTI::InvalidRegionContext,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/

	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


	Action theaction; 
	theaction.outgoing = true;
	theaction.hvps = *TypeConversion_RTI_13NG::getHVPS(channelId, theParameters, true);
	theaction.channelId = channelId;
	theaction.actionContext = Action::SEND_INTERACTION_WITH_REGION4;
	TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theInteraction);
	TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);
	TypeConversion_RTI_13NG::addMeta_Region(&theaction, &theRegion);

	LOGMSG(3, "Requesting sendInteractionWithRegion4 for " << theInteraction << "\n");

	try {

       theaction.request();

	} catch(...){

       throw;

	};

};
