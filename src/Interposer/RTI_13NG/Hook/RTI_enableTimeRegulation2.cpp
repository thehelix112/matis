// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_enableTimeRegulation2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::enableTimeRegulation(const RTI::FedTime& theFederateTime,
                                         const RTI::FedTime& theLookahead)
    throw(RTI::TimeRegulationAlreadyEnabled,
          RTI::EnableTimeRegulationPending,
          RTI::TimeAdvanceAlreadyInProgress,
          RTI::InvalidFederationTime,
          RTI::InvalidLookahead,
          RTI::ConcurrentAccessAttempted,
          RTI::FederateNotExecutionMember,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::TimeRegulationAlreadyEnabled,
   RTI::EnableTimeRegulationPending,
   RTI::TimeAdvanceAlreadyInProgress,
   RTI::InvalidFederationTime,
   RTI::InvalidLookahead,
   RTI::ConcurrentAccessAttempted,
   RTI::FederateNotExecutionMember,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError
//
Return type is: void
*/

   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);

   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::ENABLE_TIME_REGULATION;
	TypeConversion_RTI_13NG::addMeta_Timestamp(&theaction, theFederateTime);
	TypeConversion_RTI_13NG::addMeta_LookaheadTime(&theaction, theLookahead);

	LOGMSG(3, "Requesting enableTimeRegulation\n");

	try {
       
       theaction.request();	

	} catch(...){

       throw;

	};

};

