// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_deleteObjectInstance3.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::EventRetractionHandle FAKE_RTI_NAME::deleteObjectInstance(RTI::ObjectHandle theObject, 
                                                               const RTI::FedTime& theTime,
                                                               const char *theTag)
    throw(RTI::ObjectNotKnown,
          RTI::DeletePrivilegeNotHeld,
          RTI::InvalidFederationTime,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectNotKnown,
   RTI::DeletePrivilegeNotHeld,
   RTI::InvalidFederationTime,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: RTI::EventRetractionHandle                
*/

   handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);
   
   //create the Action
   Action theaction; 
   theaction.outgoing = true;   
   theaction.actionContext = Action::DELETE_OBJECT_INSTANCE3;
   theaction.channelId = channelId;
   TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
   TypeConversion_RTI_13NG::addMeta_Tag(&theaction, theTag);
   TypeConversion_RTI_13NG::addMeta_Timestamp(&theaction, theTime);
   
   LOGMSG(3, "Requesting deleteObjectInstance3 for " << theObject << "\n");
   
   try {

       RTI::EventRetractionHandle retval = *(RTI::EventRetractionHandle*) theaction.request();
       return retval;

   } catch(...){

       throw;

   };

};
