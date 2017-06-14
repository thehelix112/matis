// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIException.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_APIException.h"

using namespace MATIS;


//Default Constructor
APIException::APIException():
    id(""),
    name(""){
    
};

//Default Destructor
APIException::~APIException(){
    
};

//Constructor
APIException::APIException(std::string aId, 
                           std::string aName):
    id(aId),
    name(aName){    
    
};

//Get id method
std::string APIException::getId(){

    LOGMSG(5, "BEGIN APIException: " << id << " getting id\n");
    LOGMSG(5, "END APIException: " << id << " getting id\n");

    return id;

};


//Set id method
void APIException::setId(std::string aId){

    LOGMSG(5, "BEGIN APIException: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END APIException: " << id << " setting id\n");

};


//Get name method
std::string APIException::getName(){

    LOGMSG(5, "BEGIN APIException: " << id << " getting name\n");
    LOGMSG(5, "END APIException: " << id << " getting name\n");

    return name;

};


//Set name method
void APIException::setName(std::string aName){

    LOGMSG(5, "BEGIN APIException: " << id << " setting name\n");

    name = aName;

    LOGMSG(5, "END APIException: " << id << " setting name\n");

};

//Load the configuration
bool APIException::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setName(aElement->getParameterValue("name").c_str());
   
}

//Save the configuration
bool APIException::saveConfiguration(ConfigurationElement *aElement){
    
    
}

//return a string hash of the current object
std::string APIException::hash(){

    LOGMSG(5, "BEGIN APIException: " << id << " hash\n");
    LOGMSG(5, "END APIException: " << id << " hash\n");
    
    return Hashable::hashObject(OBJECT_APIEXCEPTION, id);
    
};



