// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_resignFederationExecution1.cpp,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.2 $






#include "MATIS_Hook_RTI_13NG.h"

void FAKE_RTI_NAME::resignFederationExecution(RTI::ResignAction theAction)
    throw(RTI::FederateOwnsAttributes,
          RTI::FederateNotExecutionMember,
          RTI::InvalidResignAction,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	


/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::FederateOwnsAttributes,
   RTI::FederateNotExecutionMember,
   RTI::InvalidResignAction,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: void
*/

	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);
	Channel_RTI_13NG *channel = (Channel_RTI_13NG *)Channel::channels.getValue(channelId);
	handleType entityhandle = channel->federateHandle;

   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::RESIGN_FEDERATION_EXECUTION;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_FederateHandle(&theaction, entityhandle);
	TypeConversion_RTI_13NG::addMeta_ResignAction(&theaction, theAction);

	LOGMSG(3, "Requesting resignFederationExecution for " << entityhandle << "\n");

	try {
	
       theaction.request();

	} catch(...){

       throw;

	};
}

