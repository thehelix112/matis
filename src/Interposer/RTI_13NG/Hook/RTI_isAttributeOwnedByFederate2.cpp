// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_isAttributeOwnedByFederate2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::Boolean FAKE_RTI_NAME::isAttributeOwnedByFederate(RTI::ObjectHandle theObject, 
                                                       RTI::AttributeHandle theAttribute)
    throw(RTI::ObjectNotKnown,
          RTI::AttributeNotDefined,
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
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: RTI::Boolean                         
*/


	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


	Action theaction; 
	theaction.outgoing = true;
	theaction.hs = *TypeConversion_RTI_13NG::getHS(channelId, theAttribute, true);
	theaction.channelId = channelId;
	theaction.actionContext = Action::IS_ATTRIBUTE_OWNED_BY_FEDERATE;
	TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);

	LOGMSG(3, "Requesting isAttributeOwnedByFederate for " << theObject << "\n");

	try {

       RTI::Boolean retval = *(RTI::Boolean*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};

};
