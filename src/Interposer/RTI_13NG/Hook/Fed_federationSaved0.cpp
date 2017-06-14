// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_federationSaved0.cpp,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


// 4.15
void MATIS_FederateAmbassador::federationSaved()
    throw(RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::FederateInternalError

   Return type is: void
*/

    handleType channelId = Channel_RTI_13NG::getChannelId(this);
    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(channelId));
    
    //create the Action
    Action theaction; 
    theaction.outgoing = false;
    theaction.actionContext = Action::FEDERATION_SAVED;
    theaction.channelId = channelId;

    LOGMSG(3, "Requesting federationSaved for " << channel->federateHandle << "\n");

    try {
        
        theaction.request();

    } catch(...){

        throw;

    };
}
