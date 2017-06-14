// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_GetObjectClass.cpp,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.3 $





void* Action_RTI_13NG::execute_RTI_GetObjectClass(Channel_RTI_13NG* channel, Action* action){

    //make the real call
    returnValue.valHandle = MATIS_RTIAmbassador::getObjectClass(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_ObjectInstanceHandle(*action)
        );

    return &(returnValue.valHandle);
    

}
