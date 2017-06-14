// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMPropertySet.cpp,v $
// CVS $Date: 2006/01/16 13:41:03 $
// CVS $Revision: 1.11 $

#include "MATIS_LEAPBMPropertySet.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"
#include "MATIS_LEAPBMValueReference.h"

using namespace MATIS;

//Default Constructor
LEAPBMPropertySet::LEAPBMPropertySet():
    property(0),
    byteValue(""){
    
};

//Default Destructor
LEAPBMPropertySet::~LEAPBMPropertySet(){
    
};

//Constructor
LEAPBMPropertySet::LEAPBMPropertySet(handleType aProperty,
                                     std::string aByteValue):
    property(aProperty),
    byteValue(aByteValue){
    
};


//Get id property
std::string LEAPBMPropertySet::getId(){

    LOGMSG(5, "BEGIN LEAPBMPropertySet: " << property << byteValue << " getting id\n");
    LOGMSG(5, "END LEAPBMPropertySet: " << property << byteValue << " getting id\n");

    char buffer[12];
    *(int*)(&buffer) = property;
    *(int*)(&buffer[4]) = parentHandle;
    *(int*)(&buffer[8]) = parentType;

    return std::string(buffer, 12) + byteValue;

};

//Get id runtimeValue
bool LEAPBMPropertySet::getRuntimeValue(){

    LOGMSG(5, "BEGIN LEAPBMRuntimeValueSet: " << getId() << " getting runtimeValueId\n");
    LOGMSG(5, "END LEAPBMRuntimeValueSet: " << getId() << " getting runtimeValueId\n");

    return runtimeValue;

};


//Set id runtimeValue
void LEAPBMPropertySet::setRuntimeValue(bool aRuntimeValue){

    LOGMSG(5, "BEGIN LEAPBMRuntimeValueSet: " << getId() << " setting runtimeValueId\n");

    runtimeValue = aRuntimeValue;

    LOGMSG(5, "END LEAPBMRuntimeValueSet: " << getId() << " setting runtimeValueId\n");

};


//Get id property
handleType LEAPBMPropertySet::getProperty(){

    LOGMSG(5, "BEGIN LEAPBMPropertySet: " << getId() << " getting propertyId\n");
    LOGMSG(5, "END LEAPBMPropertySet: " << getId() << " getting propertyId\n");

    return property;

};


//Set id property
void LEAPBMPropertySet::setProperty(handleType aProperty){

    LOGMSG(5, "BEGIN LEAPBMPropertySet: " << getId() << " setting propertyId\n");

    property = aProperty;

    LOGMSG(5, "END LEAPBMPropertySet: " << getId() << " setting propertyId\n");

};


//Get ByteValue property this value can be a reference to a property
//so we need to check the propertyset for any of these.
std::string LEAPBMPropertySet::getByteValue(){

    LOGMSG(5, "BEGIN LEAPBMPropertySet: " << getId() << " getting byteValue\n");
    LOGMSG(5, "END LEAPBMPropertySet: " << getId() << " getting byteValue\n");

    std::string data = byteValue;

    if(valueReferences.size() > 0){    

        LOGMSG(4, "Old value: " << data);
        
    }
    
        
    for(handleListType::iterator it = valueReferences.begin(); it != valueReferences.end(); ++it){

        LEAPBMValueReference *valueReference = Model::LEAPBMValueReferenceStore.getValue(*it);
        
        LOGMSG(6, "Replacing valuereference: " << valueReference->getId() << " in property set.\n");

        //if found, get the value from the reference and replace that part of the data   
        LEAPBMLAE *referenceLAE = Model::LEAPBMLAEStore.getValue(valueReference->LAE);
        std::string referenceData = referenceLAE->getPropertyValue(valueReference->property);
        
        data = Types::replaceString(data, valueReference->getId(), referenceData);
        
    }

    if(valueReferences.size() > 0){
        
        LOGMSG(4, " new value: " << data << "\n");
        
    }

    return data;

};


//Set ByteValue property
void LEAPBMPropertySet::setByteValue(std::string aByteValue){

    LOGMSG(5, "BEGIN LEAPBMPropertySet: " << getId() << " setting byteValue\n");

    byteValue = aByteValue;

    LOGMSG(5, "END LEAPBMPropertySet: " << getId() << " setting byteValue\n");

};

//Load the configuration
bool LEAPBMPropertySet::loadConfiguration(ConfigurationElement *aElement){
    
    //get the bytedata from the element
    setByteValue(aElement->getData());
    propertyId = aElement->getParameterValue("property_id").c_str();
    
    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){

        if((*it).name == "valuereference"){
         
            LEAPBMValueReference *aValueReference = new LEAPBMValueReference;
            aValueReference->loadConfiguration(&(*it));
            aValueReference->parentType = OBJECT_LEAPBMPROPERTYSET;
            valueReferences.push_back(Model::LEAPBMValueReferenceStore.addValue(aValueReference));
            
        }
        
    }
   
}

bool LEAPBMPropertySet::postConfigurationLoad(){

    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = valueReferences.begin(); it != valueReferences.end(); ++it){
        (Model::LEAPBMValueReferenceStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMValueReferenceStore.getValue(*it))->postConfigurationLoad();
    }
    
    //get the method handle from the id
    handleType handle;
    if(LAESet::getProperty(propertyId, &handle)){
        success &= true;
        setProperty(handle);
    } else {
        success &= false;
        LOGWRN("Reference made to unknown LAE property: " << propertyId << "\n");
    }

    return success;
    
}


//Save the configuration
bool LEAPBMPropertySet::saveConfiguration(ConfigurationElement *aElement){    
    
}


//return a string hash of the current object
std::string LEAPBMPropertySet::hash(){

    LOGMSG(5, "BEGIN LEAPBMPropertySet: " << getId() << " hash\n");
    LOGMSG(5, "END LEAPBMPropertySet: " << getId() << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMPROPERTYSET, getId());
    
};



