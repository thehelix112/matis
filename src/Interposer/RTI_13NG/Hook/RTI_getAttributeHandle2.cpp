// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getAttributeHandle2.cpp,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::AttributeHandle FAKE_RTI_NAME::getAttributeHandle(const char *theName,
                                                       RTI::ObjectClassHandle whichClass)
    throw(RTI::ObjectClassNotDefined,
          RTI::NameNotFound,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	
/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectClassNotDefined,
   RTI::NameNotFound,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: RTI::AttributeHandle                      
*/

   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::GET_ATTRIBUTE_HANDLE;
	TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, whichClass);
	TypeConversion_RTI_13NG::addMeta_AttributeLabel(&theaction, theName);


	try {

       RTI::AttributeHandle retval = *(RTI::AttributeHandle*) theaction.request();
       LOGMSG(4, "Attribute: " << theName << ", Handle: " << retval << "\n");
       return retval;

	} catch(...){

       throw;

	};

};
