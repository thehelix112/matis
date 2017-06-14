// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEPolicy.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_LAEPolicy.h"

using namespace MATIS;


//Default Constructor
LAEPolicy::LAEPolicy():
    id(""),
    LEAPBMId(""){
    
};

//Default Destructor
LAEPolicy::~LAEPolicy(){
     
};

//Constructor
LAEPolicy::LAEPolicy(std::string aId,
                     std::string aLEAPBMId):
    id(aId),
    LEAPBMId(aLEAPBMId){
    
};

//Get id method
std::string LAEPolicy::getId(){

    LOGMSG(5, "BEGIN LAEPolicy: " << id << " getting id\n");
    LOGMSG(5, "END LAEPolicy: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEPolicy::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEPolicy: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEPolicy: " << id << " setting id\n");

};

//Get LEAPBMId method
std::string LAEPolicy::getLEAPBMId(){

    LOGMSG(5, "BEGIN LAEPolicy: " << id << " getting LEAPBMId\n");
    LOGMSG(5, "END LAEPolicy: " << id << " getting LEAPBMId\n");

    return LEAPBMId;

};


//Set LEAPBMId method
void LAEPolicy::setLEAPBMId(std::string aLEAPBMId){

    LOGMSG(5, "BEGIN LAEPolicy: " << id << " setting LEAPBMId\n");

    LEAPBMId = aLEAPBMId;

    LOGMSG(5, "END LAEPolicy: " << id << " setting LEAPBMId\n");

};


//Load the configuration
bool LAEPolicy::loadConfiguration(ConfigurationElement *aElement){
   
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setLEAPBMId(aElement->getParameterValue("leapbm_id").c_str()); 

    //look up the handle for this leapbm after the configuration has finished
   
}

//Save the configuration
bool LAEPolicy::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEPolicy::hash(){

    LOGMSG(5, "BEGIN LAEPolicy: " << id << " hash\n");
    LOGMSG(5, "END LAEPolicy: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEPOLICY, id);
    
};






