// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_discoverObjectInstance3.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"

void MATIS_FederateAmbassador::discoverObjectInstance(RTI::ObjectHandle theObject,
                                                      RTI::ObjectClassHandle theObjectClass,
                                                      const char *theObjectName)
    throw(RTI::CouldNotDiscover,
          RTI::ObjectClassNotKnown, 
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::CouldNotDiscover,
   RTI::ObjectClassNotKnown,
   RTI::FederateInternalError

   Return type is: void
*/

    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(this);


    //create the Action
    Action theaction; 
    theaction.outgoing = false;
    theaction.actionContext = Action::DISCOVER_OBJECT_INSTANCE;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
    TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, theObjectClass);
    TypeConversion_RTI_13NG::addMeta_ObjectInstanceLabel(&theaction, theObjectName);
    
    LOGMSG(2, "Requesting discoverObjectInstance for " << theObject << "\n");
    
    try {
        
        theaction.request();
        
    } catch(...){
        
        throw;
        
    };

}
