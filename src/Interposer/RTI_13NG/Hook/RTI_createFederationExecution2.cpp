// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_createFederationExecution2.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.6 $





#include "MATIS_Hook_RTI_13NG.h"
#include "MATIS_LibHookup.h"


void FAKE_RTI_NAME::createFederationExecution(const char *executionName,
                                              const char *FED) 
    throw(RTI::FederationExecutionAlreadyExists,
          RTI::CouldNotOpenFED,
          RTI::ErrorReadingFED,
          RTI::ConcurrentAccessAttempted,
          RTI::RTIinternalError){

    FAKE_RTI_FIX_THIS;
    
    //what is the pointer to the actual one at this point:?
    LOGMSG(1, "real function pointer: " << MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__createFederationExecution2 << "\n");

    MATIS_LibHookup::checkInitialised();

    LOGMSG(1, "real function pointer: " << MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__createFederationExecution2 << "\n");

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::FederationExecutionAlreadyExists,
   RTI::CouldNotOpenFED,
   RTI::ErrorReadingFED,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError
   //
   Return type is: void
*/
    handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);
    Channel_RTI_13NG* channel = (Channel_RTI_13NG *)(Channel::channels.getValue(channelId));

    if (channel == NULL) {
        
        LOGMSG(3, "Instantiating new channel\n");
        
        channel = new Channel_RTI_13NG();
        channel->id = channelId;
        channel->initialise();
        
        // set the channel in the entity:
        Channel::channels.setValue(channelId, (Channel*)channel);		

    }

    channel->federation = executionName;
    channel->FEDFile = FED;
    channel->internalRtiAmb = AMB_THIS;
    //channel->external = false;
    
    //create an action to send
    Action theaction; 
    theaction.outgoing = true;
    theaction.actionContext = Action::CREATE_FEDERATION_EXECUTION;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_FederationExecutionLabel(&theaction, executionName);
    TypeConversion_RTI_13NG::addMeta_FedFile(&theaction, FED);    
    
    try {

        theaction.request();
        
    } catch(...){

        throw;

    };    

}
