// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_stopRegistrationForObjectClass1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


// 5.11
void MATIS_FederateAmbassador::stopRegistrationForObjectClass(RTI::ObjectClassHandle theClass)
    throw(RTI::ObjectClassNotPublished, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::ObjectClassNotPublished,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);


    //create the Action
    Action theaction;
    theaction.outgoing = false;
    theaction.actionContext = Action::STOP_REGISTRATION_FOR_OBJECT_CLASS;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, theClass);

    LOGMSG(2, "Requesting stopRegistrationForObjectClass for " << theClass << "\n");

    try {

        theaction.request();

    } catch(...){

        throw;

    };
}
