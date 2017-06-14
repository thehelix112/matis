// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_publishObjectClass2.cpp,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::publishObjectClass(RTI::ObjectClassHandle theClass,
                                       const RTI::AttributeHandleSet& attributeList) 
    throw(RTI::ObjectClassNotDefined,
          RTI::AttributeNotDefined,
          RTI::OwnershipAcquisitionPending,
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
   RTI::OwnershipAcquisitionPending,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/

	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::PUBLISH_OBJECT_CLASS;
	theaction.channelId = channelId;
	theaction.hs = *TypeConversion_RTI_13NG::getHS(channelId, attributeList, true);
	TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, theClass);

	LOGMSG(3, "Requesting publish object class for " << theClass << "\n");

	try {
   
    theaction.request();

	} catch(...){

       throw;

	};

};
