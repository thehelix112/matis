// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_timeAdvanceRequestAvailable1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::timeAdvanceRequestAvailable(const RTI::FedTime & theTime)
    throw(RTI::InvalidFederationTime,
          RTI::FederationTimeAlreadyPassed,
          RTI::TimeAdvanceAlreadyInProgress,
          RTI::EnableTimeRegulationPending,
          RTI::EnableTimeConstrainedPending,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;	


/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::InvalidFederationTime,
   RTI::FederationTimeAlreadyPassed,
   RTI::TimeAdvanceAlreadyInProgress,
   RTI::EnableTimeRegulationPending,
   RTI::EnableTimeConstrainedPending,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/


   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create action
	Action theaction; theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::TIME_ADVANCE_REQUEST_AVAILABLE;
	TypeConversion_RTI_13NG::addMeta_Timestamp(&theaction, theTime);

	LOGMSG(2, "Requesting timeAdvanceRequestAvailable\n");

	try {
       
       theaction.request();	
       
	} catch(...){
       
       throw;

	};

};
