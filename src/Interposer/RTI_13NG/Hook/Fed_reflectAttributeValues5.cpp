// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_reflectAttributeValues5.cpp,v $
// CVS $Date: 2006/01/20 12:42:00 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


// 6.5
void MATIS_FederateAmbassador::reflectAttributeValues(RTI::ObjectHandle theObject,
                                                      const RTI::AttributeHandleValuePairSet & theAttributes,
                                                      const RTI::FedTime & theTime,
                                                      const char *theTag,
                                                      RTI::EventRetractionHandle theHandle)
    throw(RTI::ObjectNotKnown,
          RTI::AttributeNotKnown,
          RTI::FederateOwnsAttributes,
          RTI::InvalidFederationTime, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::ObjectNotKnown,
   RTI::AttributeNotKnown,
   RTI::FederateOwnsAttributes,
   RTI::InvalidFederationTime,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);


    //create the Action
    Action theaction; 
    theaction.outgoing = false;
    theaction.actionContext = Action::REFLECT_ATTRIBUTE_VALUES5;
    theaction.channelId = channelId;
    theaction.hvps = *TypeConversion_RTI_13NG::getHVPS(channelId, theAttributes, true);
    TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
    TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);
    TypeConversion_RTI_13NG::addMeta_Timestamp(&theaction, theTime);
    TypeConversion_RTI_13NG::addMeta_EventRetractionHandle(&theaction, theHandle);

    LOGMSG(2, "Requesting reflectAttributeValues for " << theObject << "\n");

    try {

        theaction.request();

    } catch(...){

        throw;

    };
}
