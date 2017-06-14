// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getRoutingSpaceHandle1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::SpaceHandle FAKE_RTI_NAME::getRoutingSpaceHandle(const char *theName)
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

   Return type is: RTI::SpaceHandle               
*/


	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);



   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::GET_ROUTING_SPACE_HANDLE;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_RoutingSpaceLabel(&theaction, theName);

	LOGMSG(3, "Requesting getRoutingSpaceHandle for " << theName << "\n");

	try {

       RTI::SpaceHandle retval = *(RTI::SpaceHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};

};
