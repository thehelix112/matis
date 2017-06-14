// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethodStage.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.9 $

#include "MATIS_LAEMethodStage.h"
#include "MATIS_LAEPropertyReference.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
LAEMethodStage::LAEMethodStage():
    id(""),
    APIMethod(0),
    LAEMethod(0),
    flag(STAGE_NULL),
    start(false){
    
};

//Default Destructor
LAEMethodStage::~LAEMethodStage(){
    
};

//Constructor
LAEMethodStage::LAEMethodStage(std::string aId,
                               handleType aAPIMethod,
                               handleType aLAEMethod,
                               LAEMethodStageType aFlag,
                               bool aStart):
    id(aId),
    APIMethod(aAPIMethod),
    LAEMethod(aLAEMethod),
    flag(aFlag),
    start(aStart){
    
};

//Get id method
std::string LAEMethodStage::getId(){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " getting id\n");
    LOGMSG(5, "END LAEMethodStage: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEMethodStage::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEMethodStage: " << id << " setting id\n");

};

//Get LAEMethod method
handleType LAEMethodStage::getLAEMethod(){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " getting LAEMethod\n");
    LOGMSG(5, "END LAEMethodStage: " << id << " getting LAEMethod\n");

    if(LAEMethod == 0){
        LOGWRN("LAEMethod for LAEMethodStage: " << id << " is not set.\n");
    }

    return LAEMethod;

};


//Set LAEMethod method
void LAEMethodStage::setLAEMethod(handleType aLAEMethod){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " setting LAEMethod\n");

    LAEMethod = aLAEMethod;

    LOGMSG(5, "END LAEMethodStage: " << id << " setting LAEMethod\n");

};

//Get APIMethod method
handleType LAEMethodStage::getAPIMethod(){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " getting APIMethod\n");
    LOGMSG(5, "END LAEMethodStage: " << id << " getting APIMethod\n");

    if(APIMethod == 0){
        LOGWRN("APIMethod for LAEMethodStage: " << id << " is not set.\n");
    }

    return APIMethod;

};


//Set APIMethod method
void LAEMethodStage::setAPIMethod(handleType aAPIMethod){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " setting APIMethod\n");

    APIMethod = aAPIMethod;

    LOGMSG(5, "END LAEMethodStage: " << id << " setting APIMethod\n");

};

//Get APIMethod method
LAEMethodStageType LAEMethodStage::getFlag(){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " getting Flag\n");
    LOGMSG(5, "END LAEMethodStage: " << id << " getting Flag\n");

    return flag;

};


//Set Flag method
void LAEMethodStage::setFlag(LAEMethodStageType aFlag){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " setting Flag\n");

    flag = aFlag;

    LOGMSG(5, "END LAEMethodStage: " << id << " setting Flag\n");

};

//Get APIMethod method
bool LAEMethodStage::getStart(){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " getting Start\n");
    LOGMSG(5, "END LAEMethodStage: " << id << " getting Start\n");

    return start;

};


//Set Start method
void LAEMethodStage::setStart(bool aStart){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " setting Start\n");

    start = aStart;

    LOGMSG(5, "END LAEMethodStage: " << id << " setting Start\n");

};



//Load the configuration
bool LAEMethodStage::loadConfiguration(ConfigurationElement *aElement){

    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setFlag(Types::stringToLAEMethodStageType(aElement->getParameterValue("flags").c_str()));

    //scan progressions
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "progression"){
         
            LAEMethodStageProgression *aLAEMethodStageProgression = new LAEMethodStageProgression;
            aLAEMethodStageProgression->loadConfiguration(&(*it));
            aLAEMethodStageProgression->parentType = OBJECT_LAEMETHOD;
            progressions.push_back(
                Model::LAEMethodStageProgressionStore.addValue(aLAEMethodStageProgression));
   
        }
        
    }
    
    apiMethodId = aElement->getParameterValue("apimethod_id").c_str();
    laeMethodId = aElement->getParameterValue("laemethod_id").c_str();
   
}

bool LAEMethodStage::postConfigurationLoad(){
 
    bool success = true;
    handleType handle;

    handleListType::iterator it;
    for(it = progressions.begin(); it != progressions.end(); ++it){
        (Model::LAEMethodStageProgressionStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LAEMethodStageProgressionStore.getValue(*it))->postConfigurationLoad();
    }

    
    //get the APIMethod handle from the id
    if(apiMethodId.length() > 0){ 
        if(LAESet::getAPIMethod(apiMethodId, &handle)){
            setAPIMethod(handle);
            success &= true;
        } else {
            success &= false;
        LOGWRN("Reference made to unknown APIMethod: " << apiMethodId << "\n");
        }
    }
    if(laeMethodId.length() > 0){ 
        if(LAESet::getMethod(laeMethodId, &handle)){
            setLAEMethod(handle);
            success &= true;
        } else {
            success &= false;
        LOGWRN("Reference made to unknown LAEMethod: " << laeMethodId << "\n");
        }
    }
       
    return success;
    
}


//Save the configuration
bool LAEMethodStage::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEMethodStage::hash(){

    LOGMSG(5, "BEGIN LAEMethodStage: " << id << " hash\n");
    LOGMSG(5, "END LAEMethodStage: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEMETHODSTAGE, id);
    
};






