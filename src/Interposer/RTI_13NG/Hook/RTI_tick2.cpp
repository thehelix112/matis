// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: RTI_tick2.cpp,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.2 $





#include "MATIS_Hook_RTI_13NG.h"


RTI::Boolean FAKE_RTI_NAME::tick(RTI::TickTime minimum, 
                                 RTI::TickTime maximum)
    throw(RTI::SpecifiedSaveLabelDoesNotExist,
          RTI::ConcurrentAccessAttempted, 
          RTI::RTIinternalError){

	FAKE_RTI_FIX_THIS;
	

/* Automatically generated but editable.
   Ensure only valid exceptions are thrown
   RTI::SpecifiedSaveLabelDoesNotExist,
   RTI::ConcurrentAccessAttempted,
   RTI::RTIinternalError

   Return type is: RTI::Boolean            
*/


    //get the channelId
    handleType channelId = Channel_RTI_13NG::getChannelId(AMB_THIS);


    //create action
    Action theaction; 
    theaction.outgoing = true;
    theaction.channelId = channelId;
    theaction.actionContext = Action::TICK2;
    TypeConversion_RTI_13NG::addMeta_MiscDouble1(&theaction, minimum);
    TypeConversion_RTI_13NG::addMeta_MiscDouble2(&theaction, maximum);

    LOGMSG(4, "Requesting tick2\n");

    try {

        RTI::Boolean retval = *(RTI::Boolean*) theaction.request();
        LOGMSG(4, "tick2 retval: " << Types::boolToString(retval) << "\n");
        return retval;

    } catch(...){

        throw;

    };

};
