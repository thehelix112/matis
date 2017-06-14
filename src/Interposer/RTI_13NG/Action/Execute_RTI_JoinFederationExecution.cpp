// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_JoinFederationExecution.cpp,v $
// CVS $Date: 2005/11/22 07:10:48 $
// CVS $Revision: 1.2 $





void *Action_RTI_13NG::execute_RTI_JoinFederationExecution(Channel_RTI_13NG* channel, Action* action){
    
    // checks: channel->external_fedAmb != NULL
    if(channel->externalFedAmb == NULL){

        LOGERR("External federate ambassador NULL.\n");

    }

    //LOGMSG(1, "About to join\n");

    // make the real call
    returnValue.valHandle = MATIS_RTIAmbassador::joinFederationExecution(
        channel->externalRtiAmb,
        channel->federate.c_str(),
        channel->federation.c_str(), 
        channel->externalFedAmb);
    
    LOGMSG(1, "Joined with handle: " << returnValue.valHandle << "\n");

    //special for here: set the channel to have a map to the
    //federate entity
    channel->federateHandle = returnValue.valHandle;

    return &(returnValue.valHandle);

}
