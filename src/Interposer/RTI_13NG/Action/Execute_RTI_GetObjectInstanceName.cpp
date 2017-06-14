// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_GetObjectInstanceName.cpp,v $
// CVS $Date: 2005/11/22 07:10:48 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_GetObjectInstanceName(Channel_RTI_13NG* channel, Action* action){



    //make the real call
    returnValue.valStringPtr = MATIS_RTIAmbassador::getObjectInstanceName(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_ObjectInstanceHandle(*action)); 

    return returnValue.valStringPtr;
}