// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEPropertyReference.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.5 $

#include "MATIS_LAEPropertyReference.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
LAEPropertyReference::LAEPropertyReference():
    id(""),
    property(0){
    
};

//Default Destructor
LAEPropertyReference::~LAEPropertyReference(){
    
};

//Constructor
LAEPropertyReference::LAEPropertyReference(std::string aId,
                                           handleType aProperty):
    id(aId),
    property(aProperty){
    
};

//Get id method
std::string LAEPropertyReference::getId(){

    LOGMSG(5, "BEGIN LAEPropertyReference: " << id << " getting id\n");
    LOGMSG(5, "END LAEPropertyReference: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEPropertyReference::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEPropertyReference: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEPropertyReference: " << id << " setting id\n");

};

//Get property method
handleType LAEPropertyReference::getProperty(){

    LOGMSG(5, "BEGIN LAEPropertyReference: " << id << " getting property\n");
    LOGMSG(5, "END LAEPropertyReference: " << id << " getting property\n");

    return property;

};


//Set property method
void LAEPropertyReference::setProperty(handleType aProperty){

    LOGMSG(5, "BEGIN LAEPropertyReference: " << id << " setting property\n");

    property = aProperty;

    LOGMSG(5, "END LAEPropertyReference: " << id << " setting property\n");

};


//Load the configuration
bool LAEPropertyReference::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    propertyId = aElement->getParameterValue("property_id").c_str();
    

   
}

bool LAEPropertyReference::postConfigurationLoad(){
 
    bool success = true;    
    handleType handle;
    
    //get the Property handle from the id
    if(propertyId.length() > 0){
        if(LAESet::getProperty(propertyId, &handle)){
            setProperty(handle);
            success &= true;
        } else {
            success &= false;
            LOGWRN("Reference made to unknown Property: " << propertyId << "\n");
        }
    }

    return success;

}


//Save the configuration
bool LAEPropertyReference::saveConfiguration(ConfigurationElement *aElement){
    
    
}

//return a string hash of the current object
std::string LAEPropertyReference::hash(){

    LOGMSG(5, "BEGIN LAEPropertyReference: " << id << " hash\n");
    LOGMSG(5, "END LAEPropertyReference: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEPROPERTYREFERENCE, id);
    
};






