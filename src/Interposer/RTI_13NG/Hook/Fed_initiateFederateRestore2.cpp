// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Fed_initiateFederateRestore2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


// 4.19
void MATIS_FederateAmbassador::initiateFederateRestore(const char *label,
                                                       RTI::FederateHandle handle) 
    throw(RTI::SpecifiedSaveLabelDoesNotExist,
          RTI::CouldNotRestore,
          RTI::FederateInternalError){

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown:
   RTI::SpecifiedSaveLabelDoesNotExist,
   RTI::CouldNotRestore,
   RTI::FederateInternalError

   Return type is: void
*/

    handleType channelId = Channel_RTI_13NG::getChannelId(this);


    //create the Action
    Action theaction; 
    theaction.outgoing = false;
    theaction.actionContext = Action::INITIATE_FEDERATE_RESTORE;
    theaction.channelId = channelId;
    TypeConversion_RTI_13NG::addMeta_PointLabel(&theaction, label);
    TypeConversion_RTI_13NG::addMeta_FederateHandle(&theaction, handle);
    
    LOGMSG(3, "Requesting initiateFederateRestore for " << label << "\n");
    
    try {
        
        theaction.request();
        
    } catch(...){
        
        throw;
        
    };
}
