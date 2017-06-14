// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMMethodCall.cpp,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.8 $

#include "MATIS_LEAPBMMethodCall.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
LEAPBMMethodCall::LEAPBMMethodCall():
    id(""),
    method(0){
    
};

//Default Destructor
LEAPBMMethodCall::~LEAPBMMethodCall(){
    
};

//Constructor
LEAPBMMethodCall::LEAPBMMethodCall(std::string aid,
                                   handleType aMethod):
    id(aid),
    method(aMethod){
    
};

//Get id method
std::string LEAPBMMethodCall::getId(){

    LOGMSG(5, "BEGIN LEAPBMMethodCall: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMMethodCall: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMMethodCall::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMMethodCall: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMMethodCall: " << id << " setting id\n");

};


//Get id method
handleType LEAPBMMethodCall::getMethod(){

    LOGMSG(5, "BEGIN LEAPBMMethodCall: " << id << " getting methodId\n");
    LOGMSG(5, "END LEAPBMMethodCall: " << id << " getting methodId\n");

    return method;

};


//Set id method
void LEAPBMMethodCall::setMethod(handleType aMethod){

    LOGMSG(5, "BEGIN LEAPBMMethodCall: " << id << " setting methodId\n");

    method = aMethod;

    LOGMSG(5, "END LEAPBMMethodCall: " << id << " setting methodId\n");

};


//Load the configuration
bool LEAPBMMethodCall::loadConfiguration(ConfigurationElement *aElement){
 
    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());
    methodId = aElement->getParameterValue("method_id").c_str();

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){

        if((*it).name == "propertyset"){
         
            LEAPBMPropertySet *aPropertySet = new LEAPBMPropertySet;
            aPropertySet->loadConfiguration(&(*it));
            aPropertySet->parentType = OBJECT_LEAPBMMETHODCALL;
            propertySetObjects.push_back(aPropertySet);
            
            
            
        }
        
    }
  
}


bool LEAPBMMethodCall::postConfigurationLoad(){

    bool success = true;

    for(std::list < LEAPBMPropertySet* >::iterator it = propertySetObjects.begin();
        it != propertySetObjects.end();
        ++it){

        (*it)->parentHandle = handle;
        success &= (*it)->postConfigurationLoad();
        propertySets.push_back(Model::LEAPBMPropertySetStore.addValue(*it));
    }
    
    //get the method handle from the id
    handleType handle;
    if(LAESet::getMethod(methodId, &handle)){
        success &= true;
        setMethod(handle);
    } else {
        success &= false;
        LOGWRN("Reference made to unknown LAE method: " << methodId << "\n");
    }
    

    return success;
    
}


//Save the configuration
bool LEAPBMMethodCall::saveConfiguration(ConfigurationElement *aElement){    
    
}

//return a string hash of the current object
std::string LEAPBMMethodCall::hash(){

    LOGMSG(5, "BEGIN LEAPBMMethodCall: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMMethodCall: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMMETHODCALL, id);
    
};




