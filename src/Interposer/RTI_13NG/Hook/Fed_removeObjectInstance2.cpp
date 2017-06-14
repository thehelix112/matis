// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_removeObjectInstance2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void MATIS_FederateAmbassador::removeObjectInstance(RTI::ObjectHandle theObject,
                                                    const char *theTag)
    throw(RTI::ObjectNotKnown, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::ObjectNotKnown,
   RTI::FederateInternalError

   Return type is: void
*/


    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);

    //create the Action
    Action theaction;
    theaction.outgoing = false;
    theaction.actionContext = Action::REMOVE_OBJECT_INSTANCE2;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
    TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);
    
    LOGMSG(2, "Requesting removeObjectInstance2 for " << theObject << "\n");

    try {

        theaction.request();

    } catch(...){

        throw;

    };

}
