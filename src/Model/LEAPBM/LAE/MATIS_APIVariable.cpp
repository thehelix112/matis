// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIVariable.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_APIVariable.h"

using namespace MATIS;


//Default Constructor
APIVariable::APIVariable():
    id(""),
    type(TYPE_NULL),
    name(""){
    
};

//Default Destructor
APIVariable::~APIVariable(){
    
};

//Constructor
APIVariable::APIVariable(std::string aId,
                         APIValueType aType,
                         std::string aName):
    id(aId),
    type(aType),
    name(aName){    
    
};

//Get id method
std::string APIVariable::getId(){

    LOGMSG(5, "BEGIN APIVariable: " << id << " getting id\n");
    LOGMSG(5, "END APIVariable: " << id << " getting id\n");

    return id;

};


//Set id method
void APIVariable::setId(std::string aId){

    LOGMSG(5, "BEGIN APIVariable: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END APIVariable: " << id << " setting id\n");

};


//Get type method
APIValueType APIVariable::getType(){
    
    LOGMSG(5, "BEGIN APIVariable: " << id << " getting type\n");
    LOGMSG(5, "END APIVariable: " << id << " getting type\n");

    return type;

};

//Set type method
void APIVariable::setType(APIValueType aType){
    
    LOGMSG(5, "BEGIN APIVariable: " << id << " setting type\n");

    type = aType;

    LOGMSG(5, "END APIVariable: " << id << " setting type\n");

};


//Get name method
std::string APIVariable::getName(){

    LOGMSG(5, "BEGIN APIVariable: " << id << " getting name\n");
    LOGMSG(5, "END APIVariable: " << id << " getting name\n");

    return name;

};


//Set name method
void APIVariable::setName(std::string aName){

    LOGMSG(5, "BEGIN APIVariable: " << id << " setting name\n");

    name = aName;

    LOGMSG(5, "END APIVariable: " << id << " setting name\n");

};

//Load the configuration
bool APIVariable::loadConfiguration(ConfigurationElement *aElement){
 
   //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setType(Types::stringToAPIValueType(aElement->getParameterValue("name").c_str()));
    setName(aElement->getParameterValue("name").c_str());   
   
}

//Save the configuration
bool APIVariable::saveConfiguration(ConfigurationElement *aElement){
    
    
}



//return a string hash of the current object
std::string APIVariable::hash(){

    LOGMSG(5, "BEGIN APIVariable: " << id << " hash\n");
    LOGMSG(5, "END APIVariable: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_APIVARIABLE, id);
    
};



