// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMLAE.cpp,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.8 $

#include "MATIS_LEAPBMLAE.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
LEAPBMLAE::LEAPBMLAE():
    id(""),
    laeClass(0){
    
};

//Default Destructor
LEAPBMLAE::~LEAPBMLAE(){
    
};

//Constructor
LEAPBMLAE::LEAPBMLAE(std::string aId,
                     handleType aClass):
    id(aId),
    laeClass(aClass){
    
};


//Get id class
std::string LEAPBMLAE::getId(){

    LOGMSG(5, "BEGIN LEAPBMLAE: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMLAE: " << id << " getting id\n");

    return id;

};


//Set id class
void LEAPBMLAE::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMLAE: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMLAE: " << id << " setting id\n");

};

//Set property value method
void LEAPBMLAE::setPropertyValue(handleType property, std::string value){

    LOGMSG(4, "-----------------------------------------------------\n");
    LOGMSG(4, "LAE: " << id << " Property: " << (Model::LAEPropertyStore.getValue(property))->id << "\n");
    LOGMSG(4, "  SET VALUE: " << value << "\n");
    LOGMSG(4, "-----------------------------------------------------\n");

    propertyValues[property] = value;

}


//Get property value method        
std::string LEAPBMLAE::getPropertyValue(handleType property){

    return propertyValues[property];
    
}


//Get id class
handleType LEAPBMLAE::getClass(){

    LOGMSG(5, "BEGIN LEAPBMLAE: " << id << " getting classId\n");
    LOGMSG(5, "END LEAPBMLAE: " << id << " getting classId\n");

    return laeClass;

};


//Set id class
void LEAPBMLAE::setClass(handleType aClassId){

    LOGMSG(5, "BEGIN LEAPBMLAE: " << id << " setting classId\n");

    laeClass = aClassId;

    LOGMSG(5, "END LEAPBMLAE: " << id << " setting classId\n");

};


//Load the configuration
bool LEAPBMLAE::loadConfiguration(ConfigurationElement *aElement){

    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());
    classId = aElement->getParameterValue("class_id").c_str();
    

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
                                                                               
        if((*it).name == "methodcall"){
         
            LEAPBMMethodCall *aMethodCall = new LEAPBMMethodCall;
            aMethodCall->loadConfiguration(&(*it));
            aMethodCall->parentType = OBJECT_LEAPBMLAE;
            methodCalls.push_back(Model::LEAPBMMethodCallStore.addValue(aMethodCall));
            
        }

        if((*it).name == "propertyset"){
         
            LEAPBMPropertySet *aPropertySet = new LEAPBMPropertySet;
            aPropertySet->loadConfiguration(&(*it));
            aPropertySet->parentType = OBJECT_LEAPBMLAE;
            propertySets.push_back(Model::LEAPBMPropertySetStore.addValue(aPropertySet));

            
        }
        
    }

    return true;
   
}

bool LEAPBMLAE::postConfigurationLoad(){

    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = methodCalls.begin(); it != methodCalls.end(); ++it){
        (Model::LEAPBMMethodCallStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMMethodCallStore.getValue(*it))->postConfigurationLoad();
    }

    for(it = propertySets.begin(); it != propertySets.end(); ++it){
        (Model::LEAPBMPropertySetStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMPropertySetStore.getValue(*it))->postConfigurationLoad();
    }

    //get the LAEClass handle from the id
    handleType handle;
    if(LAESet::getClass(classId, &handle)){
        setClass(handle);

        //go and look up the properties for this LAE class and add default
        //entry into the property values map
        LAEClass *laeClassObject = Model::LAEClassStore.getValue(laeClass);
        for(handleListType::iterator it = laeClassObject->properties.begin(); 
            it != laeClassObject->properties.end(); 
            ++it){
            propertyValues[(*it)] = "";
        }

        success &= true;

    } else {
        
        LOGWRN("Reference made to unknown LAE Class: " << classId << "\n");
        success &= false;
        
    }    

    return success;
    
}


//Save the configuration
bool LEAPBMLAE::saveConfiguration(ConfigurationElement *aElement){    
    
}


//return a string hash of the current object
std::string LEAPBMLAE::hash(){

    LOGMSG(5, "BEGIN LEAPBMLAE: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMLAE: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMLAE, id);
    
};




