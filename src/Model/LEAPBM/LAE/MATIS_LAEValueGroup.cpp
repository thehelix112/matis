// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEValueGroup.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.5 $

#include "MATIS_LAEValueGroup.h"
#include "MATIS_Model.h"

using namespace MATIS;


//Default Constructor
LAEValueGroup::LAEValueGroup():
    id(""){
    
};

//Default Destructor
LAEValueGroup::~LAEValueGroup(){
    
};

//Constructor
LAEValueGroup::LAEValueGroup(std::string aId):
    id(aId){
    
};

//Get id method
std::string LAEValueGroup::getId(){

    LOGMSG(5, "BEGIN LAEValueGroup: " << id << " getting id\n");
    LOGMSG(5, "END LAEValueGroup: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEValueGroup::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEValueGroup: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEValueGroup: " << id << " setting id\n");

};


//Load the configuration
bool LAEValueGroup::loadConfiguration(ConfigurationElement *aElement){
  
   //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "valuetype"){
         
            LAEValueType *aLAEValueType = new LAEValueType;
            aLAEValueType->loadConfiguration(&(*it));
            aLAEValueType->parentType = OBJECT_LAEVALUEGROUP;
            valueTypes.push_back(Model::LAEValueTypeStore.addValue(aLAEValueType));
            
        }
        
    }
   
}


bool LAEValueGroup::postConfigurationLoad(){
  
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = valueTypes.begin(); it != valueTypes.end(); ++it){
        (Model::LAEValueTypeStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LAEValueTypeStore.getValue(*it))->postConfigurationLoad();
    }
    
    return success;
    
}

//Save the configuration
bool LAEValueGroup::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEValueGroup::hash(){

    LOGMSG(5, "BEGIN LAEValueGroup: " << id << " hash\n");
    LOGMSG(5, "END LAEValueGroup: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEVALUEGROUP, id);
    
};
