// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEClass.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.7 $

#include "MATIS_LAEClass.h"
#include "MATIS_Model.h"

using namespace MATIS;

//Default Constructor
LAEClass::LAEClass():
    id(""){
    
};

//Default Destructor
LAEClass::~LAEClass(){
    
};

//Constructor
LAEClass::LAEClass(std::string aId):
    id(aId){
    
};

//Get id method
std::string LAEClass::getId(){

    return id;

};


//Set id method
void LAEClass::setId(std::string aId){

    id = aId;

};


//Load the configuration
bool LAEClass::loadConfiguration(ConfigurationElement *aElement){
   
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "laemethod"){
         
            LAEMethod *aLAEMethod = new LAEMethod;
            aLAEMethod->loadConfiguration(&(*it));
            aLAEMethod->parentType = OBJECT_LAECLASS;
            methods.push_back(Model::LAEMethodStore.addValue(aLAEMethod));
            
        }

        if((*it).name == "laeproperty"){
         
            LAEProperty *aLAEProperty = new LAEProperty;
            aLAEProperty->loadConfiguration(&(*it));
            aLAEProperty->parentType = OBJECT_LAECLASS;
            properties.push_back(Model::LAEPropertyStore.addValue(aLAEProperty));
            
        }
        
    } 
   
}

bool LAEClass::postConfigurationLoad(){
 
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = methods.begin(); it != methods.end(); ++it){
        (Model::LAEMethodStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LAEMethodStore.getValue(*it))->postConfigurationLoad();
    }
    
    
    for(it = properties.begin(); it != properties.end(); ++it){
        (Model::LAEPropertyStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LAEPropertyStore.getValue(*it))->postConfigurationLoad();
    }
    

    return success;
    
}


//Save the configuration
bool LAEClass::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEClass::hash(){

    LOGMSG(5, "BEGIN LAEClass: " << id << " hash\n");
    LOGMSG(5, "END LAEClass: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAECLASS, id);
    
};


    
