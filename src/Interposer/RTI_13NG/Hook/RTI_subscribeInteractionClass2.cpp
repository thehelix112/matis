// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_subscribeInteractionClass2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::subscribeInteractionClass(RTI::InteractionClassHandle theClass,
                                              RTI::Boolean active)
    throw(RTI::InteractionClassNotDefined,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::FederateLoggingServiceCalls,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::InteractionClassNotDefined,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::FederateLoggingServiceCalls,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/

	handleType channelId = Channel_RTI_13NG::getChannelId (AMB_THIS);	


   //Create an action to send
	Action theaction;
	theaction.outgoing = true;
	theaction.actionContext = Action::SUBSCRIBE_INTERACTION_CLASS;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theClass);
   TypeConversion_RTI_13NG::addMeta_Active(&theaction, active);
   
	try {

       theaction.request();

	} catch (...){

       throw;

	}

};

