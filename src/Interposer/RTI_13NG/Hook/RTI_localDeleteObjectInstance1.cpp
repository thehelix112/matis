// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_localDeleteObjectInstance1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::localDeleteObjectInstance(RTI::ObjectHandle theObject)
    throw(RTI::ObjectNotKnown,
          RTI::FederateOwnsAttributes,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectNotKnown,
   RTI::FederateOwnsAttributes,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/

   handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


   //create the Action
   Action theaction; 
   theaction.outgoing = true;
   theaction.actionContext = Action::LOCAL_DELETE_OBJECT_INSTANCE;
   theaction.channelId = channelId;
   TypeConversion_RTI_13NG::addMeta_ObjectInstanceHandle(&theaction, theObject);
   
   LOGMSG(3, "Requesting localDeleteObjectInstance for " << theObject << "\n");
   
   try {
	
        theaction.request();
   
   } catch(...){

       throw;

   };

};

