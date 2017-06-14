// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_CreateFederationExecution.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.3 $





void* Action_RTI_13NG::execute_RTI_CreateFederationExecution(Channel_RTI_13NG* channel, Action* action){

    if(channel->externalRtiAmb == NULL){
        LOGERR("external RTI NULL!!!");
    }

    //make the real call
    MATIS_RTIAmbassador::createFederationExecution(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_FederationExecutionLabel(*action).c_str(),
        TypeConversion_RTI_13NG::getMeta_FedFile(*action).c_str());

    std::cout << "executecreate";
   
}
