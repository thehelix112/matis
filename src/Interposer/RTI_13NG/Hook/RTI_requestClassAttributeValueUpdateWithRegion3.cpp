// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_requestClassAttributeValueUpdateWithRegion3.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::requestClassAttributeValueUpdateWithRegion(RTI::ObjectClassHandle theClass,
                                                               const RTI::AttributeHandleSet& theAttributes,
                                                               const RTI::Region& theRegion)
    throw(RTI::ObjectClassNotDefined,
          RTI::AttributeNotDefined,
          RTI::RegionNotKnown,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectClassNotDefined,
   RTI::AttributeNotDefined,
   RTI::RegionNotKnown,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/


	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


	Action theaction; 
	theaction.outgoing = true;
	theaction.hs = *TypeConversion_RTI_13NG::getHS(channelId, theAttributes, true);
	theaction.channelId = channelId;
	theaction.actionContext = Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION;
	TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, theClass);
	TypeConversion_RTI_13NG::addMeta_Region(&theaction, &theRegion);

	LOGMSG(3, "Requesting associateRegionForUpdates for " << theClass << "\n");

	try {

       theaction.request();
       
	} catch(...){
       
       throw;
      
	};

};
