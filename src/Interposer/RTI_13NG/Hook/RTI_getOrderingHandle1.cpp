// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getOrderingHandle1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::OrderingHandle FAKE_RTI_NAME::getOrderingHandle(const char *theName)
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

   Return type is: RTI::OrderingHandle        
*/


	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::GET_ORDERING_HANDLE;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_OrderingLabel(&theaction, theName);

	LOGMSG(3, "Requesting getOrderingHandle for " << theName << "\n");

	try {

       RTI::OrderingHandle retval = *(RTI::OrderingHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};

};
