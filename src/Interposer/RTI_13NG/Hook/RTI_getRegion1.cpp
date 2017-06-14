// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_getRegion1.cpp,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.2 $

#include "MATIS_Hook_RTI_13NG.h"

RTI::Region *FAKE_RTI_NAME::getRegion(RTI::RegionToken aToken)
        throw(
            RTI::FederateNotExecutionMember,
            RTI::ConcurrentAccessAttempted,
            RTI::RegionNotKnown,
            RTI::RTIinternalError){
    

	FAKE_RTI_FIX_THIS;

    
	handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);



   //create the Action
	Action theaction; 
	theaction.outgoing = true;
	theaction.actionContext = Action::GET_REGION;
	theaction.channelId = channelId;
	TypeConversion_RTI_13NG::addMeta_RegionToken(&theaction, aToken);

	LOGMSG(3, "Requesting getRegion for " << aToken << "\n");

	try {

       RTI::Region *retval = (RTI::Region*) theaction.request();
       return retval;

	} catch(...){

       throw;

	};


}
