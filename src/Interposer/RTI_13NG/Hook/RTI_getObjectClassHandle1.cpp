// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getObjectClassHandle1.cpp,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::ObjectClassHandle FAKE_RTI_NAME::getObjectClassHandle(const char *theName)
    throw(RTI::NameNotFound,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::NameNotFound,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError
//
Return type is: RTI::ObjectClassHandle     
*/


   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::GET_OBJECT_CLASS_HANDLE;
	TypeConversion_RTI_13NG::addMeta_ObjectClassLabel(&theaction, theName);

	try {

       RTI::ObjectClassHandle retval = *(RTI::ObjectClassHandle*) theaction.request();
       LOGMSG(4, "ObjectClass: " << theName << ", Handle: " << retval << "\n");
       return retval;

	} catch(...){

       throw;

	};


};
