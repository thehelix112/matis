// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_registerObjectInstance1.cpp,v $
// CVS $Date: 2006/01/16 13:41:03 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::ObjectHandle FAKE_RTI_NAME::registerObjectInstance(RTI::ObjectClassHandle theClass)
    throw(RTI::ObjectClassNotDefined,
          RTI::ObjectClassNotPublished,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	


/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectClassNotDefined,
   RTI::ObjectClassNotPublished,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: RTI::ObjectHandle                        
*/

	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::REGISTER_OBJECT_INSTANCE1;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, theClass);

	LOGMSG(3,"Requesting registration object instance for " << theClass << "\n");

	try {
	
       RTI::ObjectHandle retval = *(RTI::ObjectHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};

};
