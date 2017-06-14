// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethodStageProgression.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_LAEMethodStageProgression.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
LAEMethodStageProgression::LAEMethodStageProgression():
    stageLAEMethod(0),
    apiException(0){
    
};

//Default Destructor
LAEMethodStageProgression::~LAEMethodStageProgression(){
     
};

//Constructor
LAEMethodStageProgression::LAEMethodStageProgression(handleType aStage,
                                                     handleType aApiException):
    stageLAEMethod(aStage),
    apiException(aApiException){
    
};

//artificially create the id from the string components
std::string LAEMethodStageProgression::getId(){
    
    return (stageId+apiExceptionId);

}


//Get id method
handleType LAEMethodStageProgression::getStage(){

    LOGMSG(5, "BEGIN LAEMethodStageProgression: " << getId() << " getting id\n");
    LOGMSG(5, "END LAEMethodStageProgression: " << getId() << " getting id\n");

    return stageLAEMethod;

};


//Set id method
void LAEMethodStageProgression::setStage(handleType aStage){

    LOGMSG(5, "BEGIN LAEMethodStageProgression: " << getId() << " setting id\n");

    stageLAEMethod = aStage;

    LOGMSG(5, "END LAEMethodStageProgression: " << getId() << " setting id\n");

};

//Get apiExceptionId method
handleType LAEMethodStageProgression::getApiException(){

    LOGMSG(5, "BEGIN LAEMethodStageProgression: " << getId() << " getting apiExceptionId\n");
    LOGMSG(5, "END LAEMethodStageProgression: " << getId() << " getting apiExceptionId\n");

    return apiException;

};


//Set apiExceptionId method
void LAEMethodStageProgression::setApiException(handleType aApiException){

    LOGMSG(5, "BEGIN LAEMethodStageProgression: " << getId() << " setting apiExceptionId\n");

    apiException = aApiException;

    LOGMSG(5, "END LAEMethodStageProgression: " << getId() << " setting apiExceptionId\n");

};


//Load the configuration
bool LAEMethodStageProgression::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    stageId = aElement->getParameterValue("stage_id").c_str();
    apiExceptionId = aElement->getParameterValue("apiexception_id").c_str();

   
}

bool LAEMethodStageProgression::postConfigurationLoad(){
    
    bool success = true;
    handleType handle;
    
    //get the APIMethod handle from the id
    if(stageId.length() > 0){ 
        if(LAESet::getMethodStage(stageId, &handle)){
            setStage(handle);
            success &= true;
        } else {
            success &= false;
        LOGWRN("Reference made to unknown APIMethod: " << stageId << "\n");
        }
    }
    if(apiExceptionId.length() > 0){ 
        if(LAESet::getAPIException(apiExceptionId, &handle)){
            setApiException(handle);
            success &= true;
        } else {
            success &= false;
        LOGWRN("Reference made to unknown LAEMethod: " << apiExceptionId << "\n");
        }
    }

    return success;
    
}


//Save the configuration
bool LAEMethodStageProgression::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEMethodStageProgression::hash(){

    LOGMSG(5, "BEGIN LAEMethodStageProgression: " << getId() << " hash\n");
    LOGMSG(5, "END LAEMethodStageProgression: " << getId() << " hash\n");

    return Hashable::hashObject(OBJECT_LAEMETHODSTAGEPROGRESSION, getId());
    
};






