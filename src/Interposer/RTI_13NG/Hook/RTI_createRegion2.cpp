// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_createRegion2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::Region* FAKE_RTI_NAME::createRegion(RTI::SpaceHandle theSpace, 
                                         RTI::ULong numberOfExtents)
    throw(RTI::SpaceNotDefined,
          RTI::InvalidExtents,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::SpaceNotDefined,
   RTI::InvalidExtents,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: RTI::Region*                          
*/


	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);

   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::CREATE_REGION;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_RoutingSpaceHandle(&theaction, theSpace);
	TypeConversion_RTI_13NG::addMeta_NumberOf(&theaction, numberOfExtents);

	LOGMSG(3, "Requesting createRegion for " << theSpace << "\n");

	try {

       RTI::Region* retval = (RTI::Region*) theaction.request();
       return retval;
    
	} catch(...){

       throw;

	};

};
