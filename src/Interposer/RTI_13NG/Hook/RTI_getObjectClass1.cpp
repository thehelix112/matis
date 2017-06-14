// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getObjectClass1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::ObjectClassHandle FAKE_RTI_NAME::getObjectClass(RTI::ObjectHandle theObject)
    throw(RTI::ObjectNotKnown,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectNotKnown,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: RTI::ObjectClassHandle           
*/

	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);

   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::GET_OBJECT_CLASS;
	TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);

	try {

       RTI::ObjectClassHandle retval = *(RTI::ObjectClassHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};

};
