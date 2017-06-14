// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMValueReference.cpp,v $
// CVS $Date: 2006/01/17 14:54:58 $
// CVS $Revision: 1.5 $

#include "MATIS_LEAPBMValueReference.h"
#include "MATIS_LAESet.h"
#include "MATIS_LEAPBM.h"

using namespace MATIS;

//Default Constructor
LEAPBMValueReference::LEAPBMValueReference():
    id(""),
    property(0),
    LAE(0){
    
};

//Default Destructor
LEAPBMValueReference::~LEAPBMValueReference(){
    
};

//Constructor
LEAPBMValueReference::LEAPBMValueReference(std::string aId,
                                           handleType aProperty,
                                           handleType aLAE):
    id(aId),
    property(aProperty),
    LAE(aLAE){
    
};

//Get Id property
std::string LEAPBMValueReference::getId(){

    LOGMSG(5, "BEGIN LEAPBMValueReference: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMValueReference: " << id << " getting id\n");

    return id;

};


//Set Id property
void LEAPBMValueReference::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMValueReference: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMValueReference: " << id << " setting id\n");

};

//Get LAE property
handleType LEAPBMValueReference::getLAE(){

    LOGMSG(5, "BEGIN LEAPBMValueReference: " << id << " getting LAE\n");
    LOGMSG(5, "END LEAPBMValueReference: " << id << " getting LAE\n");

    return LAE;

};


//Set LAE property
void LEAPBMValueReference::setLAE(handleType aLAE){

    LOGMSG(5, "BEGIN LEAPBMValueReference: " << id << " setting LAE\n");

    LAE = aLAE;

    LOGMSG(5, "END LEAPBMValueReference: " << id << " setting LAE\n");

};


//Get id property
handleType LEAPBMValueReference::getProperty(){

    LOGMSG(5, "BEGIN LEAPBMValueReference: " << id << " getting property\n");
    LOGMSG(5, "END LEAPBMValueReference: " << id << " getting property\n");

    return property;

};


//Set id property
void LEAPBMValueReference::setProperty(handleType aProperty){

    LOGMSG(5, "BEGIN LEAPBMValueReference: " << id << " setting property\n");

    property = aProperty;

    LOGMSG(5, "END LEAPBMValueReference: " << id << " setting property\n");

};


//Load the configuration
bool LEAPBMValueReference::loadConfiguration(ConfigurationElement *aElement){

    setId(aElement->getParameterValue("id").c_str());

    propertyId = aElement->getParameterValue("property_id").c_str();
    laeId = aElement->getParameterValue("lae_id").c_str();
   
}

bool LEAPBMValueReference::postConfigurationLoad(){
    
    bool success = true;

    //get the lae handle from the id
    handleType handle;
    if(LEAPBM::getLAE(laeId, &handle)){
        success &= true;
        setLAE(handle);
    } else {
        success &= false;
        LOGWRN("Reference made to unknown LAE: " << laeId << "\n");
    }    

    //get the property handle from the id
    if(LAESet::getProperty(propertyId, &handle)){
        success &= true;
        setProperty(handle);
    } else {
        success &= false;
        LOGWRN("Reference made to unknown Property: " << propertyId << "\n");
    }

    return success;
    
}

//Save the configuration
bool LEAPBMValueReference::saveConfiguration(ConfigurationElement *aElement){    
    
}


//return a string hash of the current object
std::string LEAPBMValueReference::hash(){

    LOGMSG(5, "BEGIN LEAPBMValueReference: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMValueReference: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMVALUEREFERENCE, id+laeId+propertyId);
    
};




