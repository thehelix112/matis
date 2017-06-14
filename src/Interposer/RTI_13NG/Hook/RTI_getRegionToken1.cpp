// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getRegionToken1.cpp,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.2 $

#include "MATIS_Hook_RTI_13NG.h"

RTI::RegionToken FAKE_RTI_NAME::getRegionToken(RTI::Region* aRegion)
    throw(RTI::FederateNotExecutionMember,
          RTI::ConcurrentAccessAttempted,
          RTI::RegionNotKnown,
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
   
    
    handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);
    
    

   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::GET_REGION_TOKEN;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_Region(&theaction, aRegion);

	LOGMSG(3, "Requesting getRegionToken for " << aRegion << "\n");

	try {

       RTI::RegionToken retval = *(RTI::RegionToken*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};


}

