// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_changeInteractionTransportationType2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::changeInteractionTransportationType(RTI::InteractionClassHandle theClass,
                                                        RTI::TransportationHandle theType)
    throw(RTI::InteractionClassNotDefined,
          RTI::InteractionClassNotPublished,
          RTI::InvalidTransportationHandle,
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
   RTI::InvalidTransportationHandle,
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
	theaction.channelId = channelId;
	theaction.actionContext = Action::CHANGE_INTERACTION_TRANSPORTATION_TYPE;
	TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theClass);
	TypeConversion_RTI_13NG::addMeta_TransportationHandle(&theaction, theType);

	LOGMSG(3, "Requesting changeInteractionTransportationType for " << theClass << "\n");

	try{

       theaction.request();

	} catch(...){

       throw;

	};


};
