// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMExit.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.3 $

#include "MATIS_LEAPBMExit.h"

using namespace MATIS;

//Default Constructor
LEAPBMExit::LEAPBMExit():
    id(""){
    
};

//Default Destructor
LEAPBMExit::~LEAPBMExit(){
    
};

//Constructor
LEAPBMExit::LEAPBMExit(std::string aId):
    id(aId){
    
};


//Get id class
std::string LEAPBMExit::getId(){

    LOGMSG(5, "BEGIN LEAPBMExit: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMExit: " << id << " getting id\n");

    return id;

};


//Set id class
void LEAPBMExit::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMExit: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMExit: " << id << " setting id\n");

};

//Load the configuration
bool LEAPBMExit::loadConfiguration(ConfigurationElement *aElement){
   
    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());

}

//Save the configuration
bool LEAPBMExit::saveConfiguration(ConfigurationElement *aElement){    
    
}

//return a string hash of the current object
std::string LEAPBMExit::hash(){

    LOGMSG(5, "BEGIN LEAPBMExit: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMExit: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMEXIT, id);
    
};




std::string LEAPBMExit::getDot(int level){

    std::string dotString;

    for(int i = 0; i < level; ++i)
        dotString += "  ";

    dotString += id + " [label=\"\",shape=doublecircle,style=filled,fillcolor=black];\n";

    return dotString;

};
