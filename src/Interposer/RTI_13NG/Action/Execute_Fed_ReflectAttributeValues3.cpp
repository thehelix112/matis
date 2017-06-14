// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: Execute_Fed_ReflectAttributeValues3.cpp,v $
// CVS $Date: 2005/11/22 07:10:46 $
// CVS $Revision: 1.2 $





void* Action_RTI_13NG::execute_Fed_ReflectAttributeValues3(Channel_RTI_13NG* channel, Action* action){			


    //make the real call
    channel->internalFedAmb->reflectAttributeValues(
        TypeConversion_RTI_13NG::getMeta_ObjectInstanceHandle(*action) ,
        *TypeConversion_RTI_13NG::getAHVPS(action->hvps, true),
        TypeConversion_RTI_13NG::getMeta_Tag(*action).c_str()
        );			
		
}
