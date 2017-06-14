// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getInteractionRoutingSpaceHandle1.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $






RTI::SpaceHandle FAKE_RTI_NAME::getInteractionRoutingSpaceHandle(RTI::InteractionClassHandle theHandle)
    throw(RTI::InteractionClassNotDefined,
          RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
         RTI::InteractionClassNotDefined,
         RTI::FederateNotExecutionMember,
         RTI::ConcurrentAccessAttempted,
         RTI::RTIinternalError

   Return type is: RTI::SpaceHandle                            
*/

   //get the channelId
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);

   //create action
	Action theaction; 
	theaction.outgoing = true;
	theaction.channelId = channelId;
	theaction.actionContext = Action::GET_INTERACTION_ROUTING_SPACE_HANDLE;
	TypeConversion_RTI_13NG::addMeta_InteractionHandle(&theaction, theHandle);


	try {

       RTI::SpaceHandle retval = *(RTI::SpaceHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};

};
