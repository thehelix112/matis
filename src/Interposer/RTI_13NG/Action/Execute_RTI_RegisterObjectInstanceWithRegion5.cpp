// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_RegisterObjectInstanceWithRegion5.cpp,v $
// CVS $Date: 2005/11/22 07:10:49 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_RegisterObjectInstanceWithRegion5(Channel_RTI_13NG* channel, Action* action){


    //make the real call
    returnValue.valHandle = MATIS_RTIAmbassador::registerObjectInstanceWithRegion(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_ObjectClassHandle(*action),
        TypeConversion_RTI_13NG::getMeta_ObjectInstanceLabel(*action).c_str(),
        TypeConversion_RTI_13NG::getAHA(action->hs, true),
        TypeConversion_RTI_13NG::getRA(action->rs),
        TypeConversion_RTI_13NG::getMeta_NumberOf(*action));
       
    return &(returnValue.valHandle);
}
