// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_timeAdvanceGrant1.cpp,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


// 8.13
void MATIS_FederateAmbassador::timeAdvanceGrant(const RTI::FedTime & theTime)
    throw(RTI::InvalidFederationTime, 
          RTI::TimeAdvanceWasNotInProgress,
          RTI::FederationTimeAlreadyPassed, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::InvalidFederationTime,
   RTI::TimeAdvanceWasNotInProgress,
   RTI::FederationTimeAlreadyPassed,
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
    theaction.actionContext = Action::TIME_ADVANCE_GRANT;
    TypeConversion_RTI_13NG::addMeta_Timestamp(&theaction, theTime);

    LOGMSG(4, "Requesting timeAdvanceGrant for " << channel->federateHandle << "\n");

    try{

        theaction.request();	

    } catch(...){

        throw;

    };
}
