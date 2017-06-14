// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEFunction.cpp,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.6 $

#include "MATIS_LAEFunction.h"
#include "MATIS_LAEPropertyReference.h"
#include "MATIS_Model.h"
#include "MATIS_PluginStore.h"

using namespace MATIS;


//Default Constructor
LAEFunction::LAEFunction():
    id(""),
    pluginId(""){
    
};

//Default Destructor
LAEFunction::~LAEFunction(){
    
};

//Constructor
LAEFunction::LAEFunction(std::string aId,
                       std::string aPluginId):
    id(aId),
    pluginId(aPluginId){
    
};

//Get id method
std::string LAEFunction::getId(){

    LOGMSG(5, "BEGIN LAEFunction: " << id << " getting id\n");
    LOGMSG(5, "END LAEFunction: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEFunction::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEFunction: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEFunction: " << id << " setting id\n");

};

//Get pluginId method
std::string LAEFunction::getPluginId(){

    LOGMSG(5, "BEGIN LAEFunction: " << id << " getting pluginId\n");
    LOGMSG(5, "END LAEFunction: " << id << " getting pluginId\n");

    return pluginId;

};


//Set pluginId method
void LAEFunction::setPluginId(std::string aPluginId){

    LOGMSG(5, "BEGIN LAEFunction: " << id << " setting pluginId\n");

    pluginId = aPluginId;

    LOGMSG(5, "END LAEFunction: " << id << " setting pluginId\n");

};


//Load the configuration
bool LAEFunction::loadConfiguration(ConfigurationElement *aElement){

    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setPluginId(aElement->getParameterValue("plugin_id").c_str());  


    //load the function plugin
    PluginStore::setFunctionName(id, pluginId);
    function = PluginStore::getFunction(id);
    
   
}


bool LAEFunction::postConfigurationLoad(){
 
    
}


//Save the configuration
bool LAEFunction::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEFunction::hash(){

    LOGMSG(5, "BEGIN LAEFunction: " << id << " hash\n");
    LOGMSG(5, "END LAEFunction: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAEFUNCTION, id);
    
};






