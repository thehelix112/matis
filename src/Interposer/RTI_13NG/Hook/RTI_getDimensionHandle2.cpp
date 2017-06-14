// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getDimensionHandle2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::DimensionHandle FAKE_RTI_NAME::getDimensionHandle(const char *theName,
                                                       RTI::SpaceHandle whichSpace)
    throw(RTI::SpaceNotDefined,
          RTI::NameNotFound,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::SpaceNotDefined,
   RTI::NameNotFound,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: RTI::DimensionHandle                  
*/

   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::GET_DIMENSION_HANDLE;
	TypeConversion_RTI_13NG::addMeta_RoutingSpaceHandle(&theaction, whichSpace);
	TypeConversion_RTI_13NG::addMeta_DimensionLabel(&theaction, theName);

	try {

       RTI::DimensionHandle retval = *(RTI::DimensionHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};


};
