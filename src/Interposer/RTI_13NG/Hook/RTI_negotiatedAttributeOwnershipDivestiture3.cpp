// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_negotiatedAttributeOwnershipDivestiture3.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::negotiatedAttributeOwnershipDivestiture(RTI::ObjectHandle theObject,
                                                            const RTI::AttributeHandleSet & theAttributes,
                                                            const char *theTag)
    throw(RTI::ObjectNotKnown,
          RTI::AttributeNotDefined,
          RTI::AttributeNotOwned,
          RTI::AttributeAlreadyBeingDivested,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectNotKnown,
   RTI::AttributeNotDefined,
   RTI::AttributeNotOwned,
   RTI::AttributeAlreadyBeingDivested,
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
	theaction.actionContext = Action::NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE;
	TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
   TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);

	LOGMSG(3, "Requesting negotiatedAttributeOwnershipDivestiture for " << theObject << "\n");

	try {

       theaction.request();

	} catch(...){

       throw;

	};

};
