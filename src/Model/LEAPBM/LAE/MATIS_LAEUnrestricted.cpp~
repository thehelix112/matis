// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAERequirement.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_LAERequirement.h"

using namespace MATIS;


//Default Constructor
LAERequirement::LAERequirement():
    id(""),
    version(""){
    
};

//Default Destructor
LAERequirement::~LAERequirement(){
     
};

//Constructor
LAERequirement::LAERequirement(std::string aId,
                               std::string aVersion):
    id(aId),
    version(aVersion){
    
};

//Get id method
std::string LAERequirement::getId(){

    LOGMSG(5, "BEGIN LAERequirement: " << id << " getting id\n");
    LOGMSG(5, "END LAERequirement: " << id << " getting id\n");

    return id;

};


//Set id method
void LAERequirement::setId(std::string aId){

    LOGMSG(5, "BEGIN LAERequirement: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAERequirement: " << id << " setting id\n");

};

//Get version method
std::string LAERequirement::getVersion(){

    LOGMSG(5, "BEGIN LAERequirement: " << id << " getting version\n");
    LOGMSG(5, "END LAERequirement: " << id << " getting version\n");

    return version;

};


//Set version method
void LAERequirement::setVersion(std::string aVersion){

    LOGMSG(5, "BEGIN LAERequirement: " << id << " setting version\n");

    version = aVersion;

    LOGMSG(5, "END LAERequirement: " << id << " setting version\n");

};


//Load the configuration
bool LAERequirement::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setVersion(aElement->getParameterValue("version").c_str());
   
}

//Save the configuration
bool LAERequirement::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAERequirement::hash(){

    LOGMSG(5, "BEGIN LAERequirement: " << id << " hash\n");
    LOGMSG(5, "END LAERequirement: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEREQUIREMENT, id);
    
};






