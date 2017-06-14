// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_Tick0.cpp,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.3 $





void* Action_RTI_13NG::execute_RTI_Tick0(Channel_RTI_13NG* channel, Action* action){

			
    //make the real call
    returnValue.valBool = MATIS_RTIAmbassador::tick(channel->externalRtiAmb);		

    return &(returnValue.valBool);

}
