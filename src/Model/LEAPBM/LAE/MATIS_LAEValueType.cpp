// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEValueType.cpp,v $
// CVS $Date: 2006/01/05 14:08:39 $
// CVS $Revision: 1.6 $

#include "MATIS_LAEValueType.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
LAEValueType::LAEValueType():
    id(""),
    type(TYPE_NULL),
    validatorId(""){
    
};

//Default Destructor
LAEValueType::~LAEValueType(){
    
};

//Get id method
std::string LAEValueType::getId(){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " getting id\n");
    LOGMSG(5, "END LAEValueType: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEValueType::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEValueType: " << id << " setting id\n");

};

//Get type method
ValueType LAEValueType::getType(){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " getting type\n");
    LOGMSG(5, "END LAEValueType: " << id << " getting type\n");

    return type;

};


//Set type method
void LAEValueType::setType(ValueType aType){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " setting type\n");

    type = aType;

    LOGMSG(5, "END LAEValueType: " << id << " setting type\n");

};


//Get validator method
std::string LAEValueType::getValidatorId(){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " getting validator\n");
    LOGMSG(5, "END LAEValueType: " << id << " getting validator\n");

    return validatorId;

};


//Set validator method
void LAEValueType::setValidatorId(std::string aValidator){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " setting validator\n");

    validatorId = aValidator;

    LOGMSG(5, "END LAEValueType: " << id << " setting validator\n");

};

//Get validator method
handleType LAEValueType::getValidator(){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " getting validator\n");
    LOGMSG(5, "END LAEValueType: " << id << " getting validator\n");

    return validator;

};


//Set validator method
void LAEValueType::setValidator(handleType aValidator){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " setting validator\n");

    validator = aValidator;

    LOGMSG(5, "END LAEValueType: " << id << " setting validator\n");

};

//Load the configuration
bool LAEValueType::loadConfiguration(ConfigurationElement *aElement){

    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());

    if(cistring(aElement->getParameterValue("type").c_str()) == "custom")
        setType(TYPE_CUSTOM);
    else
        setType(TYPE_NULL);

    setValidatorId(aElement->getParameterValue("validator").c_str());
    
    return true;
   
}

bool LAEValueType::postConfigurationLoad(){
 
    bool success = true;    
    handleType handle;

    //get the Checker handle from the id
    if(validatorId.length() > 0){
        
        if(LAESet::getChecker(getValidatorId(), &handle)){
            setValidator(handle);
            success &= true;
        } else {
            success &= false;
            LOGWRN("Reference made to unknown Checker: " << getValidatorId() << "\n");
        }

    }

    return success;

}


//Save the configuration
bool LAEValueType::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEValueType::hash(){

    LOGMSG(5, "BEGIN LAEValueType: " << id << " hash\n");
    LOGMSG(5, "END LAEValueType: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEVALUETYPE, id);
    
};






