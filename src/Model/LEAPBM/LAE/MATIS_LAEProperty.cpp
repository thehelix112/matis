// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEProperty.cpp,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.7 $

#include "MATIS_LAEProperty.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
LAEProperty::LAEProperty():
    id(""),
    numSources(0),
    type(TYPE_NULL),
    actionStorage(""),
    actionStorageCategory(STORAGE_ACTIONHANDLE){
    
};

//Default Destructor
LAEProperty::~LAEProperty(){
    
};

//Constructor
LAEProperty::LAEProperty(std::string aId,
                         int aSources,
                         ValueType aType,
                         std::string aActionStorage,
                         actionStorageCategoryType aActionStorageCategory):
    id(aId),
    numSources(aSources),
    type(aType),
    actionStorage(aActionStorage),
    actionStorageCategory(aActionStorageCategory){
    
};

//Get id method
std::string LAEProperty::getId(){

    LOGMSG(5, "BEGIN LAEProperty: " << id << " getting id\n");
    LOGMSG(5, "END LAEProperty: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEProperty::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEProperty: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEProperty: " << id << " setting id\n");

};

//Get actionStorage method
std::string LAEProperty::getActionStorage(){

    LOGMSG(5, "BEGIN LAEProperty: " << actionStorage << " getting actionStorage\n");
    LOGMSG(5, "END LAEProperty: " << actionStorage << " getting actionStorage\n");

    return actionStorage;

};


//Set actionStorage method
void LAEProperty::setActionStorage(std::string aActionStorage){

    LOGMSG(5, "BEGIN LAEProperty: " << actionStorage << " setting actionStorage\n");

    actionStorage = aActionStorage;

    LOGMSG(5, "END LAEProperty: " << actionStorage << " setting actionStorage\n");

};

//Get actionStorageCategory method
actionStorageCategoryType LAEProperty::getActionStorageCategory(){

    LOGMSG(5, "BEGIN LAEProperty: " << actionStorageCategory << " getting actionStorageCategory\n");
    LOGMSG(5, "END LAEProperty: " << actionStorageCategory << " getting actionStorageCategory\n");

    return actionStorageCategory;

};


//Set actionStorageCategory method
void LAEProperty::setActionStorageCategory(actionStorageCategoryType aActionStorageCategory){

    LOGMSG(5, "BEGIN LAEProperty: " << actionStorageCategory << " setting actionStorageCategory\n");

    actionStorageCategory = aActionStorageCategory;

    LOGMSG(5, "END LAEProperty: " << actionStorageCategory << " setting actionStorageCategory\n");

};


//Get type method
ValueType LAEProperty::getType(){

    LOGMSG(5, "BEGIN LAEProperty: " << type << " getting type\n");
    LOGMSG(5, "END LAEProperty: " << type << " getting type\n");

    return type;

};


//Set type method
void LAEProperty::setType(ValueType aType){

    LOGMSG(5, "BEGIN LAEProperty: " << type << " setting type\n");

    type = aType;

    LOGMSG(5, "END LAEProperty: " << type << " setting type\n");

};

handleType LAEProperty::getCustomType(){
    
    return customType;
    
};

void LAEProperty::setCustomType(handleType aValueType){
    
    customType = aValueType;
    
};



//Get sources method
int LAEProperty::getNumSources(){

    LOGMSG(5, "BEGIN LAEProperty: " << id << " getting number of expected sources\n");
    LOGMSG(5, "END LAEProperty: " << id << " getting number of expected sources\n");

    return numSources;

};

//Set number of sources
void LAEProperty::setNumSources(int aNumSources){

    LOGMSG(5, "BEGIN LAEProperty: " << id << " setting number of expected sources\n");

    numSources = aNumSources;
    
    LOGMSG(5, "END LAEProperty: " << id << " setting number of expected sources\n");    
    
}


//Load the configuration
bool LAEProperty::loadConfiguration(ConfigurationElement *aElement){

    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setNumSources(Types::stringToInt(aElement->getParameterValue("sources").c_str()));

    setType(Types::stringToValueType(aElement->getParameterValue("type").c_str()));
    if(type == TYPE_CUSTOM){
        customTypeId = aElement->getParameterValue("type").c_str();
    }
    
    setActionStorage(aElement->getParameterValue("action_storage").c_str());
    setActionStorageCategory(Types::stringToActionStorageCategoryType(actionStorage));

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "source"){
         
            LAEPropertySource *aLAEPropertySource = new LAEPropertySource;
            aLAEPropertySource->loadConfiguration(&(*it));
            aLAEPropertySource->parentType = OBJECT_LAEPROPERTY;
            sourceObjects.push_back(aLAEPropertySource);
   
        }
        
    } 
   
}

bool LAEProperty::postConfigurationLoad(){
 
    bool success = true;
    
    for(std::list < LAEPropertySource* >::iterator it = sourceObjects.begin();
        it != sourceObjects.end();
        ++it){

        (*it)->parentHandle = handle;
        success &= (*it)->postConfigurationLoad();
        sources.push_back(Model::LAEPropertySourceStore.addValue(*it));
            
    }

    if(type == TYPE_CUSTOM){
        //lookup the LAEValueType from the name
        if(customTypeId.length() > 0){
            handleType aHandle;
            if(LAESet::getValueType(customTypeId, &aHandle)){
                LOGMSG(6, "Setting value type of LAEProperty:" << id << " to: " << (Model::LAEValueTypeStore.getValue(aHandle))->getId() << "\n");
                setCustomType(aHandle);
                success &= true;
            } else {
                success &= false;
                LOGWRN("Reference made to unknown LAE Value Type: " << customTypeId << "\n");
            }
        }
    }

    return success;

}


//Save the configuration
bool LAEProperty::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEProperty::hash(){

    LOGMSG(5, "BEGIN LAEProperty: " << id << " hash\n");
    LOGMSG(5, "END LAEProperty: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEPROPERTY, id);
    
};
