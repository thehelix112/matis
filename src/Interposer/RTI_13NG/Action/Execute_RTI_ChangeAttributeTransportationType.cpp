// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_ChangeAttributeTransportationType.cpp,v $
// CVS $Date: 2005/11/22 07:10:47 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_ChangeAttributeTransportationType(Channel_RTI_13NG* channel, Action* action){

	    
        //make the real call
        MATIS_RTIAmbassador::changeAttributeTransportationType(
            channel->externalRtiAmb,
            TypeConversion_RTI_13NG::getMeta_ObjectInstanceHandle(*action),
            *TypeConversion_RTI_13NG::getAHS(action->hs, true),
            TypeConversion_RTI_13NG::getMeta_TransportationHandle(*action));

        // set the MAPS_FROM and MAPS_TO

        // set associations between entities:
		
		}
