// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_timeRegulationEnabled1.cpp,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"

// 8.3
void MATIS_FederateAmbassador::timeRegulationEnabled(const RTI::FedTime& theFederateTime)
    throw(RTI::InvalidFederationTime,
          RTI::EnableTimeRegulationWasNotPending, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::InvalidFederationTime,
   RTI::EnableTimeRegulationWasNotPending,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);
    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(channelId));
    

    //create action
    Action theaction; 
    theaction.outgoing = false;
    theaction.channelId = channelId;
    theaction.actionContext = Action::TIME_REGULATION_ENABLED;
    TypeConversion_RTI_13NG::addMeta_Timestamp(&theaction, theFederateTime);

    LOGMSG(3, "Requesting timeRegulationEnabled for " << channel->federateHandle << "\n");

    try{

        theaction.request();	

    } catch(...){

        throw;
        
    };

}
