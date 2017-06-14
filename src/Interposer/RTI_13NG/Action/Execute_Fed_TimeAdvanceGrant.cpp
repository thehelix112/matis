// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_Fed_TimeAdvanceGrant.cpp,v $
// CVS $Date: 2006/01/06 02:02:57 $
// CVS $Revision: 1.4 $





void* Action_RTI_13NG::execute_Fed_TimeAdvanceGrant(Channel_RTI_13NG* channel, Action* action){
    
    //LOGMSG(4, "Channel internalFedAmb: " << channel->internalFedAmb << "\n");

//    LOGMSG(4, "about to get timestamp from action....");
//    TypeConversion_RTI_13NG::getMeta_Timestamp(*action);
//    LOGMSG(4, "  DONE\n");    

    //make the real call
    channel->internalFedAmb->timeAdvanceGrant(
        TypeConversion_RTI_13NG::getMeta_Timestamp(*action));		
    
}
