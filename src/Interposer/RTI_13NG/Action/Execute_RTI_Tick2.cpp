// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_Tick2.cpp,v $
// CVS $Date: 2005/11/22 07:10:49 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_Tick2(Channel_RTI_13NG * channel, Action * action){
		
    //make the real call
    returnValue.valBool = MATIS_RTIAmbassador::tick(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_MiscDouble1(*action),
        TypeConversion_RTI_13NG::getMeta_MiscDouble2(*action));		

    return &(returnValue.valBool);

}
