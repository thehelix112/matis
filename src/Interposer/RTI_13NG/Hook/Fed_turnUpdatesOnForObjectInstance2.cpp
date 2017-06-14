// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_turnUpdatesOnForObjectInstance2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


// 6.17
void MATIS_FederateAmbassador::turnUpdatesOnForObjectInstance(RTI::ObjectHandle theObject,
                                                              const RTI::AttributeHandleSet & theAttributes)
    throw(RTI::ObjectNotKnown,
          RTI::AttributeNotOwned, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::ObjectNotKnown,
   RTI::AttributeNotOwned,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);


    //create the Action
    Action theaction;
    theaction.outgoing = false;
    theaction.hs = *TypeConversion_RTI_13NG::getHS(channelId, theAttributes, true);
    theaction.actionContext = Action::TURN_UPDATES_ON_FOR_OBJECT_INSTANCE;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);

    LOGMSG(2, "Requesting turnUpdatesOnForObjectInstance for " << theObject << "\n");

    try {
        
        theaction.request();

    } catch(...){

		throw;

    };

}
