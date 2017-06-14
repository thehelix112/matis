// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_SendInteractionWithRegion5.cpp,v $
// CVS $Date: 2005/11/22 07:10:49 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_SendInteractionWithRegion5(Channel_RTI_13NG* channel, Action* action){
 
	    
    //make the real call
    returnValue.valErh = MATIS_RTIAmbassador::sendInteractionWithRegion(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_InteractionHandle(*action), 
        *TypeConversion_RTI_13NG::getPHVPS(action->hvps, true),   
        TypeConversion_RTI_13NG::getMeta_Timestamp(*action),
        TypeConversion_RTI_13NG::getMeta_Tag(*action).c_str(),
        *TypeConversion_RTI_13NG::getMeta_Region(*action));

    return &(returnValue.valErh);
    
}
