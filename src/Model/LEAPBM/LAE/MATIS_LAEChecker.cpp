// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEChecker.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_LAEChecker.h"
#include "MATIS_PluginStore.h"

using namespace MATIS;


//Default Constructor
LAEChecker::LAEChecker():
    id(""),
    pluginId(""){
    
};

//Default Destructor
LAEChecker::~LAEChecker(){
     
};

//Constructor
LAEChecker::LAEChecker(std::string aId,
                       std::string aPluginId):
    id(aId),
    pluginId(aPluginId){
    
};

//Get id method
std::string LAEChecker::getId(){

    LOGMSG(5, "BEGIN LAEChecker: " << id << " getting id\n");
    LOGMSG(5, "END LAEChecker: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEChecker::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEChecker: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEChecker: " << id << " setting id\n");

};

//Get pluginId method
std::string LAEChecker::getPluginId(){

    LOGMSG(5, "BEGIN LAEChecker: " << id << " getting pluginId\n");
    LOGMSG(5, "END LAEChecker: " << id << " getting pluginId\n");

    return pluginId;

};


//Set pluginId method
void LAEChecker::setPluginId(std::string aPluginId){

    LOGMSG(5, "BEGIN LAEChecker: " << id << " setting pluginId\n");

    pluginId = aPluginId;

    LOGMSG(5, "END LAEChecker: " << id << " setting pluginId\n");

};


//Load the configuration
bool LAEChecker::loadConfiguration(ConfigurationElement *aElement){
   
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setPluginId(aElement->getParameterValue("plugin_id").c_str());

    //load the checker plugin
    PluginStore::setCheckerName(id, pluginId);
    checker = PluginStore::getChecker(id);
   
}

//Save the configuration
bool LAEChecker::saveConfiguration(ConfigurationElement *aElement){
    
    
}



//return a string hash of the current object
std::string LAEChecker::hash(){

    LOGMSG(5, "BEGIN LAEChecker: " << id << " hash\n");
    LOGMSG(5, "END LAEChecker: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAECHECKER, id);
    
};






