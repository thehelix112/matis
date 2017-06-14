// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEUnrestricted.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.3 $

#include "MATIS_LAEUnrestricted.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
LAEUnrestricted::LAEUnrestricted():
    afterInteraction(0),
    beforeInteraction(0){
    
};

//Default Destructor
LAEUnrestricted::~LAEUnrestricted(){
     
};

//Constructor
LAEUnrestricted::LAEUnrestricted(handleType aAfterInteraction,
                                 handleType aBeforeInteraction):
    afterInteraction(aAfterInteraction),
    beforeInteraction(aBeforeInteraction){
    
};

std::string LAEUnrestricted::getId(){
    
    char buffer[4];
    *(handleType *)&(buffer) = parentHandle;

    return (afterInteractionId)+(beforeInteractionId)+std::string(buffer, 4);
    
}


//Get afterInteraction method
handleType LAEUnrestricted::getAfterInteraction(){

    LOGMSG(5, "BEGIN LAEUnrestricted: " << afterInteraction << " getting afterInteraction\n");
    LOGMSG(5, "END LAEUnrestricted: " << afterInteraction << " getting afterInteraction\n");

    return afterInteraction;

};


//Set afterInteraction method
void LAEUnrestricted::setAfterInteraction(handleType aAfterInteraction){

    LOGMSG(5, "BEGIN LAEUnrestricted: " << afterInteraction << " setting afterInteraction\n");

    afterInteraction = aAfterInteraction;

    LOGMSG(5, "END LAEUnrestricted: " << afterInteraction << " setting afterInteraction\n");

};

//Get beforeInteraction method
handleType LAEUnrestricted::getBeforeInteraction(){

    LOGMSG(5, "BEGIN LAEUnrestricted: " << getId() << " getting beforeInteraction\n");
    LOGMSG(5, "END LAEUnrestricted: " << getId() << " getting beforeInteraction\n");

    return beforeInteraction;

};


//Set beforeInteraction method
void LAEUnrestricted::setBeforeInteraction(handleType aBeforeInteraction){

    LOGMSG(5, "BEGIN LAEUnrestricted: " << getId() << " setting beforeInteraction\n");

    beforeInteraction = aBeforeInteraction;

    LOGMSG(5, "END LAEUnrestricted: " << getId() << " setting beforeInteraction\n");

};


//Load the configuration
bool LAEUnrestricted::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    afterInteractionId = aElement->getParameterValue("after_interaction_id").c_str();
    beforeInteractionId = aElement->getParameterValue("before_interaction_id").c_str();
   
}


bool LAEUnrestricted::postConfigurationLoad(){
 
    bool success = true;
    handleType handle;

    //get the after interaction id handle from the id
    if(afterInteractionId.length() > 0){ 
        if(LAESet::getMethod(afterInteractionId, &handle)){
            setAfterInteraction(handle);
            success &= true;
        } else {
            success &= false;
            LOGWRN("Reference made to unknown LAEMethod: " << afterInteractionId << "\n");
        }
    }

    //get the before interaction id handle from the id
    if(beforeInteractionId.length() > 0){ 
        if(LAESet::getMethod(beforeInteractionId, &handle)){
            setBeforeInteraction(handle);
            success &= true;
        } else {
            success &= false;
            LOGWRN("Reference made to unknown LAEMethod: " << beforeInteractionId << "\n");
        }
    }
    
}


//Save the configuration
bool LAEUnrestricted::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEUnrestricted::hash(){

    LOGMSG(5, "BEGIN LAEUnrestricted hash: " << Hashable::hashObject(OBJECT_LAEUNRESTRICTED, getId()) << "\n");
    LOGMSG(5, "END LAEUnrestricted hash: " << Hashable::hashObject(OBJECT_LAEUNRESTRICTED, getId()) << "\n");

    return Hashable::hashObject(OBJECT_LAEUNRESTRICTED, getId());
    
};






