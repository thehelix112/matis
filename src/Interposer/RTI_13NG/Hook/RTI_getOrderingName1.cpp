// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getOrderingName1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


char *FAKE_RTI_NAME::getOrderingName(RTI::OrderingHandle theHandle)
    throw(RTI::InvalidOrderingHandle,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::InvalidOrderingHandle,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: char *
*/


   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::GET_ORDERING_HANDLE;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_OrderingHandle(&theaction, theHandle);

	LOGMSG(3, "Requesting getOrderingName for " << theHandle << "\n");

	try {

       theaction.request();

	} catch(...){

       throw;

	};

};
