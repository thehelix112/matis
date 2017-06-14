// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIParameter.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_APIParameter.h"

using namespace MATIS;


//Default Constructor
APIParameter::APIParameter():
    id(""),
    valueType(TYPE_NULL),
    index(0){
    
};

//Default Destructor
APIParameter::~APIParameter(){
    
};

//Constructor
APIParameter::APIParameter(std::string aId, 
                           APIValueType aType,
                           int aIndex):
    id(aId),
    valueType(aType),
    index(aIndex){
    
};

//Get id method
std::string APIParameter::getId(){

    LOGMSG(5, "BEGIN APIParameter: " << id << " getting id\n");
    LOGMSG(5, "END APIParameter: " << id << " getting id\n");

    return id;

};


//Set id method
void APIParameter::setId(std::string aId){

    LOGMSG(5, "BEGIN APIParameter: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END APIParameter: " << id << " setting id\n");

};

//Get type method
APIValueType APIParameter::getValueType(){
    
    LOGMSG(5, "BEGIN APIParameter: " << id << " getting value type\n");
    LOGMSG(5, "END APIParameter: " << id << " getting value type\n");

    return valueType;

};


//Set type method
void APIParameter::setValueType(APIValueType aValueType){
    
    LOGMSG(5, "BEGIN APIParameter: " << id << " setting value type\n");

    valueType = aValueType;

    LOGMSG(5, "END APIParameter: " << id << " setting value type\n");

};


//Get index method
int APIParameter::getIndex(){
    
    LOGMSG(5, "BEGIN APIParameter: " << id << " getting index\n");
    LOGMSG(5, "END APIParameter: " << id << " getting index\n");

    return index;

};


//Set index method
void APIParameter::setIndex(int aIndex){
    
    LOGMSG(5, "BEGIN APIParameter: " << id << " setting index\n");

    index = aIndex;

    LOGMSG(5, "END APIParameter: " << id << " setting index\n");

};

//Load the configuration
bool APIParameter::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setValueType(Types::stringToAPIValueType(aElement->getParameterValue("name").c_str()));
    setIndex(Types::stringToInt(aElement->getParameterValue("index").c_str()));
   
}

//Save the configuration
bool APIParameter::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string APIParameter::hash(){

    LOGMSG(5, "BEGIN APIParameter: " << id << " hash\n");
    LOGMSG(5, "END APIParameter: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_APIPARAMETER, id);
    
};


