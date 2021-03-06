// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_sendInteraction3.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::sendInteraction(RTI::InteractionClassHandle theInteraction,
                                    const RTI::ParameterHandleValuePairSet& theParameters,
                                    const char* theTag)
    throw(RTI::InteractionClassNotDefined,
          RTI::InteractionClassNotPublished,
          RTI::InteractionParameterNotDefined,
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
	theaction.actionContext = Action::SEND_INTERACTION3;
   TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theInteraction);
   TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);

	LOGMSG(2, "Requesting send interaction for " << theInteraction << "\n");

	try {

       theaction.request();

	} catch(...){

       throw;

	};

};

