// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_requestAttributeOwnershipRelease3.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


// 7.10
void MATIS_FederateAmbassador::requestAttributeOwnershipRelease(RTI::ObjectHandle theObject,
                                                                const RTI::AttributeHandleSet & candidateAttributes,
                                                                const char *theTag)
    throw(RTI::ObjectNotKnown,
          RTI::AttributeNotKnown,
          RTI::AttributeNotOwned, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::ObjectNotKnown,
   RTI::AttributeNotKnown,
   RTI::AttributeNotOwned,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);


    //create the Action
    Action theaction;
    theaction.outgoing = false;
    theaction.hs = *TypeConversion_RTI_13NG::getHS(channelId, candidateAttributes, true);
    theaction.actionContext = Action::REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
    TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);
    
    LOGMSG(2, "Requesting requestAttributeOwnershipRelease for " << theObject << "\n");
    
    try {
        
        theaction.request();
        
    } catch(...){
        
        throw;
        
    };

}
