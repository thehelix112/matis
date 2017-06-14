// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getParameterHandle2.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::ParameterHandle FAKE_RTI_NAME::getParameterHandle(const char *theName,
                                                       RTI::InteractionClassHandle whichClass)
    throw(RTI::InteractionClassNotDefined,
          RTI::NameNotFound,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){
    
	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::InteractionClassNotDefined,
   RTI::NameNotFound,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: RTI::ParameterHandle                           
*/

   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);

   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::GET_PARAMETER_HANDLE;
	TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, whichClass);
	TypeConversion_RTI_13NG::addMeta_ParameterLabel(&theaction, theName);

	try {
	
       RTI::ParameterHandle retval = *(RTI::ParameterHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};

};
