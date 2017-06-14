// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_requestFederationRestoreSucceeded1.cpp,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


// 4.17
void MATIS_FederateAmbassador::requestFederationRestoreSucceeded(const char *label) 
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
    theaction.actionContext = Action::REQUEST_FEDERATION_RESTORE_SUCCEEDED;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_PointLabel(&theaction, label);
    
    LOGMSG(3, "Requesting requestFederationRestoreSucceeded for " << channel->federateHandle << " for " << label << "\n");
    
    try {
        
        theaction.request();
        
    } catch(...){

        throw;

    };

}
