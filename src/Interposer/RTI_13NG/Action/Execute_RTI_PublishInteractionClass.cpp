// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_RTI_PublishInteractionClass.cpp,v $
// CVS $Date: 2005/11/22 07:10:49 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_RTI_PublishInteractionClass(Channel_RTI_13NG* channel, Action* action){

	//make the real call
	MATIS_RTIAmbassador::publishInteractionClass(
       channel->externalRtiAmb,
       TypeConversion_RTI_13NG::getMeta_InteractionHandle(*action)
       );
		
}
