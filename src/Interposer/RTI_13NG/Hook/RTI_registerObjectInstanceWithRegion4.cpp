// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_registerObjectInstanceWithRegion4.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::ObjectHandle FAKE_RTI_NAME::registerObjectInstanceWithRegion(RTI::ObjectClassHandle theClass, 
                                                                  RTI::AttributeHandle theAttributes[],
                                                                  RTI::Region * theRegions[], 
                                                                  RTI::ULong theNumberOfHandles)
    throw(RTI::ObjectClassNotDefined, 
          RTI::ObjectClassNotPublished,
          RTI::AttributeNotDefined, 
          RTI::AttributeNotPublished,
          RTI::RegionNotKnown, 
          RTI::InvalidRegionContext,
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
   RTI::AttributeNotDefined,
   RTI::AttributeNotPublished,
   RTI::RegionNotKnown,
   RTI::InvalidRegionContext,
   RTI::FederateNotExecutionMember,
   RTI::ConcurrentAccessAttempted,
   RTI::SaveInProgress,
   RTI::RestoreInProgress,
   RTI::RTIinternalError

   Return type is: RTI::ObjectHandle                             
*/


	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


	//create an action to send
	Action theaction; 
	theaction.outgoing = true;
	theaction.hs = *TypeConversion_RTI_13NG::getHS(channelId, theAttributes, theNumberOfHandles);
	theaction.rs = *TypeConversion_RTI_13NG::getRS(channelId, theRegions, theNumberOfHandles);		   
	theaction.channelId = channelId;
	theaction.actionContext = Action::REGISTER_OBJECT_INSTANCE_WITH_REGION4;
	TypeConversion_RTI_13NG::addMeta_ObjectClassHandle(&theaction, theClass);
	TypeConversion_RTI_13NG::addMeta_NumberOf(&theaction, theNumberOfHandles);	

	LOGMSG(3, "Requesting registerObjectInstanceWithRegion4 for " << theClass << "\n");

	try{

       RTI::ObjectHandle retval = *(RTI::ObjectHandle*) theaction.request();
       return retval;

	} catch(...){

       throw;
      
	};

};
