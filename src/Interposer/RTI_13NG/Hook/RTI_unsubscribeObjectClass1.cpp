// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_unsubscribeObjectClass1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


void FAKE_RTI_NAME::unsubscribeObjectClass(RTI::ObjectClassHandle theClass)
    throw(RTI::ObjectClassNotDefined,
          RTI::ObjectClassNotSubscribed,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::SaveInProgress, 
          RTI::RestoreInProgress, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;


/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::ObjectClassNotDefined,
   RTI::ObjectClassNotSubscribed,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: void
*/

	handleType channelId = Channel_RTI_13NG::getChannelId (AMB_THIS);

   //Create and action to send
	Action theaction;
	theaction.outgoing = true;
	theaction.actionContext = Action::UNSUBSCRIBE_OBJECT_CLASS;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, theClass);

	try {

       theaction.request();

	} catch(...){

       throw;

	};

};

