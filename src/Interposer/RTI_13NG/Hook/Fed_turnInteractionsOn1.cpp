// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_turnInteractionsOn1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


// 5.12
void MATIS_FederateAmbassador::turnInteractionsOn(RTI::InteractionClassHandle theHandle)
    throw(RTI::InteractionClassNotPublished, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::InteractionClassNotPublished,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);

    //create the Action
    Action theaction;
    theaction.outgoing = false;
    theaction.actionContext = Action::TURN_INTERACTIONS_ON;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theHandle);

    LOGMSG(2, "Requesting turnInteractionsOn for " << theHandle << "\n");
    
    try {
        
        theaction.request();

    } catch(...){
        
        throw;

    };
 
}
