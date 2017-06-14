// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getParameterName2.cpp,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


char *FAKE_RTI_NAME::getParameterName(RTI::ParameterHandle theHandle,
                                      RTI::InteractionClassHandle whichClass) 
    throw(RTI::InteractionClassNotDefined,
          RTI::InteractionParameterNotDefined,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::RTIinternalError){

    FAKE_RTI_FIX_THIS;
    
/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::InteractionClassNotDefined,
   RTI::InteractionParameterNotDefined,
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
	theaction.actionContext = Action::GET_PARAMETER_NAME;
	TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, whichClass);
	TypeConversion_RTI_13NG::addMeta_ParameterHandle(&theaction, theHandle);

	try {
	
       theaction.request();

	} catch(...){

       throw;

	};

};
