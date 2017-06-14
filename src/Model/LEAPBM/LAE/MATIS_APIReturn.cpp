// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIReturn.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_APIReturn.h"

using namespace MATIS;


//Default Constructor
APIReturn::APIReturn():
    id(""),
    type(TYPE_NULL){
    
};

//Default Destructor
APIReturn::~APIReturn(){
    
};

//Constructor
APIReturn::APIReturn(std::string aId,
                     APIValueType aType):
    id(aId),
    type(aType){
    
};

//Get id method
std::string APIReturn::getId(){

    LOGMSG(5, "BEGIN APIReturn: " << id << " getting id\n");
    LOGMSG(5, "END APIReturn: " << id << " getting id\n");

    return id;

};


//Set id method
void APIReturn::setId(std::string aId){

    LOGMSG(5, "BEGIN APIReturn: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END APIReturn: " << id << " setting id\n");

};


//Get type method
APIValueType APIReturn::getType(){
    
    LOGMSG(5, "BEGIN APIReturn: " << id << " getting type\n");
    LOGMSG(5, "END APIReturn: " << id << " getting type\n");

    return type;

};

//Set type method
void APIReturn::setType(APIValueType aType){
    
    LOGMSG(5, "BEGIN APIReturn: " << id << " setting type\n");

    type = aType;

    LOGMSG(5, "END APIReturn: " << id << " setting type\n");

};


//Load the configuration
bool APIReturn::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setType(Types::stringToAPIValueType(aElement->getParameterValue("name").c_str()));
   
}

//Save the configuration
bool APIReturn::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string APIReturn::hash(){

    LOGMSG(5, "BEGIN APIReturn: " << id << " hash\n");
    LOGMSG(5, "END APIReturn: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_APIRETURN, id);
    
};






