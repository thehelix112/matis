// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_joinFederationExecution3.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.6 $





#include "MATIS_Hook_RTI_13NG.h"

RTI::FederateHandle FAKE_RTI_NAME::joinFederationExecution(const char *yourName,
                                                           const char *executionName,
                                                           RTI::FederateAmbassadorPtr federateAmbassadorReference)
    throw(RTI::FederateAlreadyExecutionMember,
          RTI::FederationExecutionDoesNotExist,
          RTI::CouldNotOpenFED,
          RTI::ErrorReadingFED,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

   FAKE_RTI_FIX_THIS;

   MATIS_LibHookup::checkInitialised();

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::FederateAlreadyExecutionMember,
   RTI::FederationExecutionDoesNotExist,
   RTI::CouldNotOpenFED,
   RTI::ErrorReadingFED,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError
   //
   Return type is: RTI::FederateHandle                                              
*/

   handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);

   
   Channel_RTI_13NG *channel = (Channel_RTI_13NG *)Channel::channels.getValue(channelId);
  
   if (channel == NULL) {

      LOGMSG(3, "Instantiating new channel\n");

      channel = new Channel_RTI_13NG();
      channel->id = channelId;
      channel->initialise();

      // set the channel in the entity:
      Channel::channels.setValue(channelId, (Channel*)channel);

   }

   //  Federation, internal_rtiAmb may already be set if the fed called createfedex
   channel->federation = executionName;
   channel->federate = yourName;
   channel->internalFedAmb = federateAmbassadorReference;

   LOGMSG(4, "Channel internalFedAmb: " << channel->internalFedAmb << "\n");
   
   channel->internalRtiAmb = AMB_THIS;
   //channel->external = false;

   //action
   Action theaction; 
   theaction.outgoing = true;
   theaction.actionContext = Action::JOIN_FEDERATION_EXECUTION;
   theaction.channelId = channelId;
   TypeConversion_RTI_13NG::addMeta_FederateLabel(&theaction, yourName);
   TypeConversion_RTI_13NG::addMeta_FederationExecutionLabel(&theaction, executionName);

   try {

       RTI::FederateHandle retval = *(RTI::FederateHandle*) theaction.request();
       return retval;

   } catch(...){

       throw;

   };

}

