// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_receiveInteraction5.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


// 6.7
void MATIS_FederateAmbassador::receiveInteraction(RTI::InteractionClassHandle theInteraction,
                                                  const RTI::ParameterHandleValuePairSet & theParameters,
                                                  const RTI::FedTime & theTime,
                                                  const char *theTag,
                                                  RTI::EventRetractionHandle theHandle)
    throw(RTI::InteractionClassNotKnown,
          RTI::InteractionParameterNotKnown,
          RTI::InvalidFederationTime, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::InteractionClassNotKnown,
   RTI::InteractionParameterNotKnown,
   RTI::InvalidFederationTime,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);

    //create the Action
    Action theaction; 
    theaction.outgoing = false;
    theaction.actionContext = Action::RECEIVE_INTERACTION5;
    theaction.channelId = channelId;
    theaction.hvps = *TypeConversion_RTI_13NG::getHVPS(channelId, theParameters, true);
    TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theInteraction);
    TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);
    TypeConversion_RTI_13NG::addMeta_Timestamp(&theaction, theTime);
    TypeConversion_RTI_13NG::addMeta_EventRetractionHandle(&theaction, theHandle);

    LOGMSG(3, "Requesting receiveInteraction5 for " << theInteraction << "\n");

    try {
        
        theaction.request();

    } catch(...){

		throw;

    };
}
