// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_RequestObjectAttributeValueUpdate.cpp,v $
// CVS $Date: 2006/01/20 12:42:00 $
// CVS $Revision: 1.3 $





void* Action_RTI_13NG::execute_RTI_RequestObjectAttributeValueUpdate(Channel_RTI_13NG* channel, Action* action){

    //make the real call
    MATIS_RTIAmbassador::requestObjectAttributeValueUpdate(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_ObjectInstanceHandle(*action),
        *TypeConversion_RTI_13NG::getAHS(action->hs, true));

}
