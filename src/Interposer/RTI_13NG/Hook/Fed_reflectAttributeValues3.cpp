// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_reflectAttributeValues3.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void MATIS_FederateAmbassador::reflectAttributeValues(RTI::ObjectHandle theObject,
                                                      const RTI::AttributeHandleValuePairSet & theAttributes,
                                                      const char *theTag)
    throw(RTI::ObjectNotKnown,
          RTI::AttributeNotKnown,
          RTI::FederateOwnsAttributes, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::ObjectNotKnown,
   RTI::AttributeNotKnown,
   RTI::FederateOwnsAttributes,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);


    //create the Action
    Action theaction; 
    theaction.outgoing = false;
    theaction.actionContext = Action::REFLECT_ATTRIBUTE_VALUES3;
    theaction.channelId = channelId;
    theaction.hvps = *TypeConversion_RTI_13NG::getHVPS(channelId, theAttributes, true);
    TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
    TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);

    LOGMSG(2, "Requesting reflectAttributeValues for " << theObject << "\n");

    try {

        theaction.request();

    } catch(...){

        throw;

    };

}
