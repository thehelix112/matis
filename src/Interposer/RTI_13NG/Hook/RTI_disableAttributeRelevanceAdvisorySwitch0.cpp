// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_disableAttributeRelevanceAdvisorySwitch0.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::disableAttributeRelevanceAdvisorySwitch()
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
	theaction.actionContext = Action::DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH;
	theaction.channelId = channelId;

	LOGMSG(3, "Requesting disableAttributeRelevanceAdvisorySwitch\n");

	try {
	
       theaction.request();

	} catch(...){

       throw;
      
	};

};
