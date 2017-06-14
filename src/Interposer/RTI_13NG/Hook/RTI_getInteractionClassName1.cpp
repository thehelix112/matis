// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getInteractionClassName1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


char *FAKE_RTI_NAME::getInteractionClassName(RTI::InteractionClassHandle theHandle)
    throw(RTI::InteractionClassNotDefined,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::InteractionClassNotDefined,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: char *
*/

//get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::GET_INTERACTION_CLASS_NAME;
	TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theHandle);

	try {
	
       std::string retval = *(std::string*) theaction.request();
       return (char*)retval.c_str();

	} catch(...){

       throw;

	};

};
