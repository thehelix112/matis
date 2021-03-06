// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_GetInteractionClassName.cpp,v $
// CVS $Date: 2005/11/22 07:10:48 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_GetInteractionClassName(Channel_RTI_13NG* channel, Action* action){
		
    //As we can answer this question without having to ask the RTI
    //there is no need for code here. Ie it all happens in the
    //RTI_getInteractionClassName.cpp file
    returnValue.valStringPtr = MATIS_RTIAmbassador::getInteractionClassName(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_InteractionHandle(*action)); 

    return returnValue.valStringPtr;

			
}
