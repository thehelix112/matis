// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_destroyFederationExecution1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $






#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::destroyFederationExecution(const char *executionName) 
    throw(RTI::FederatesCurrentlyJoined,
          RTI::FederationExecutionDoesNotExist,
          RTI::ConcurrentAccessAttempted,
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
         RTI::FederatesCurrentlyJoined,
         RTI::FederationExecutionDoesNotExist,
         RTI::ConcurrentAccessAttempted,
         RTI::RTIinternalError

   Return type is: void
*/

   handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create the Action
   Action theaction; 
   theaction.outgoing = true;
   theaction.actionContext = Action::DESTROY_FEDERATION_EXECUTION;
   theaction.channelId = channelId;
   TypeConversion_RTI_13NG::addMeta_FederationExecutionLabel(&theaction, executionName);

   LOGMSG(3, "Requesting destroyFederationExecution for " << executionName << "\n");

   try {
	
       theaction.request();

   } catch(...){

       throw;

   };

}
