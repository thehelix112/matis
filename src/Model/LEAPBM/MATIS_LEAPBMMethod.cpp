// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSmethod: MATIS_LEAPBMMethod.cpp,v $
// CVS $Date: 2005/12/05 12:53:00 $
// CVS $Revision: 1.3 $

#include "MATIS_LEAPBMMethod.h"

using namespace MATIS;

//Default Constructor
LEAPBMMethod::LEAPBMMethod():
    id(""),
    name(""){
    
};

//Default Destructor
LEAPBMMethod::~LEAPBMMethod(){
    
};

//Constructor
LEAPBMMethod::LEAPBMMethod(std::string aId,
                                         std::string aName):
    id(aId),
    name(aName){
    
};

//Get id method
std::string LEAPBMMethod::getId(){

    LOGMSG(5, "BEGIN LEAPBMMethod: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMMethod: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMMethod::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMMethod: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMMethod: " << id << " setting id\n");

};



//Get unrestricted method
bool LEAPBMMethod::getUnrestricted(){

    LOGMSG(5, "BEGIN LEAPBMMethod: " << unrestricted << " getting unrestricted\n");
    LOGMSG(5, "END LEAPBMMethod: " << unrestricted << " getting unrestricted\n");

    return unrestricted;

};


//Set unrestricted method
void LEAPBMMethod::setUnrestricted(bool aUnrestricted){

    LOGMSG(5, "BEGIN LEAPBMMethod: " << unrestricted << " setting unrestricted\n");

    unrestricted = aUnrestricted;

    LOGMSG(5, "END LEAPBMMethod: " << unrestricted << " setting unrestricted\n");

};


//Get id method
std::string LEAPBMMethod::getName(){

    LOGMSG(5, "BEGIN LEAPBMMethod: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMMethod: " << id << " getting id\n");

    return name;

};


//Set id method
void LEAPBMMethod::setName(std::string aName){

    LOGMSG(5, "BEGIN LEAPBMMethod: " << id << " setting id\n");

    name = aName;

    LOGMSG(5, "END LEAPBMMethod: " << id << " setting id\n");

};

//Load the configuration
bool LEAPBMMethod::loadConfiguration(ConfigurationElement *aElement){
 
    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());
    setName(aElement->getParameterValue("name").c_str());
    setUnrestricted(Types::stringToBool(aElement->getParameterValue("unrestricted").c_str()));
  
}

//Save the configuration
bool LEAPBMMethod::saveConfiguration(ConfigurationElement *aElement){    
    
}

//return a string hash of the current object
std::string LEAPBMMethod::hash(){

    LOGMSG(5, "BEGIN LEAPBMMethod: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMMethod: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMMETHOD, id);
    
};




