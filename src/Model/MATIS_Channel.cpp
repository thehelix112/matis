// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Channel.cpp,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.3 $

#include "MATIS_Channel.h"

using namespace MATIS;

Channel::Channel():
  protocol(PROTOCOL_NONE),
  isExternal(false){
    
    
};

UniqueHandleFactory < Channel *, 1 > Channel::channels;

/*void Channel::setModel(Model aModel){

    model = aModel;

}

Model Channel::getModel(){

    return model;

    }*/

