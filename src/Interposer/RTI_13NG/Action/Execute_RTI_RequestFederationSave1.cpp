// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_RequestFederationSave1.cpp,v $
// CVS $Date: 2005/11/22 07:10:49 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_RequestFederationSave1(Channel_RTI_13NG* channel, Action* action){

    //checks: 
    if(TypeConversion_RTI_13NG::getMeta_PointLabel(*action) == ""){

        LOGERR("Empty save point label provided\n");

    }
	    
    //make the real call
    MATIS_RTIAmbassador::requestFederationSave(
        channel->externalRtiAmb,
        TypeConversion_RTI_13NG::getMeta_PointLabel(*action).c_str());
 
}
