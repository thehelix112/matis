// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_disableTimeRegulation0.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::disableTimeRegulation()
    throw(RTI::TimeRegulationWasNotEnabled,
          RTI::ConcurrentAccessAttempted,
          RTI::FederateNotExecutionMember,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::TimeRegulationWasNotEnabled,
   RTI::ConcurrentAccessAttempted,
   RTI::FederateNotExecutionMember,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/

   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::DISABLE_TIME_REGULATION;

	LOGMSG(3, "Requesting disableTimeRegulation\n");

	try {

       theaction.request();	

	} catch(...){

       throw;

	};

};

