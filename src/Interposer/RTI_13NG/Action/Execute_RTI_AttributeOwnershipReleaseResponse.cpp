// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_AttributeOwnershipReleaseResponse.cpp,v $
// CVS $Date: 2005/11/22 07:10:47 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_AttributeOwnershipReleaseResponse(Channel_RTI_13NG* channel, Action* action){

    //make the real call
    returnValue.valAHSPtr = MATIS_RTIAmbassador::attributeOwnershipReleaseResponse(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_ObjectInstanceHandle(*action),
        *TypeConversion_RTI_13NG::getAHS(action->hs, true));

    return returnValue.valAHSPtr;
    
}
