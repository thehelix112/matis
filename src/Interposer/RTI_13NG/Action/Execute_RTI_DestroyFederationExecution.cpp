// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_DestroyFederationExecution.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.7 $





void* Action_RTI_13NG::execute_RTI_DestroyFederationExecution(Channel_RTI_13NG* channel, Action* action){

    //this is the last method we care about so print a summary
    Model::model->summary();

    //make the real call
    MATIS_RTIAmbassador::destroyFederationExecution(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_FederationExecutionLabel(*action).c_str());

    Channel::channels.removeValue(action->channelId);
    

    if(Channel::channels.existsHandle(action->channelId)){
        
        LOGERR("Failed to delete channel with id: " << action->channelId << "\n");
        
    }

}
