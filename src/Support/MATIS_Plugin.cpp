// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Plugin.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_Plugin.h"

using namespace MATIS;

bool Plugin::attach(){
    return true;
}

Plugin::~Plugin(){
}

void Plugin::setIdentity(std::string aLabel, 
                         std::string aId) {
    label = aLabel;
    id = aId;
};

Plugin::Plugin():
    label("<unknown>"), 
    id("<unknown>"){

};
