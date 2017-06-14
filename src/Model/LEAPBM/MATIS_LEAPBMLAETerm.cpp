// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMLAETerm.cpp,v $
// CVS $Date: 2006/01/03 12:20:04 $
// CVS $Revision: 1.4 $

#include "MATIS_LEAPBMLAETerm.h"
#include "MATIS_LAESet.h"
#include "MATIS_ConfigurationStore.h"
#include "MATIS_XMLStore.h"

using namespace MATIS;

//Default Constructor
LEAPBMLAETerm::LEAPBMLAETerm():
    id(""),
    version(""),
    path(""){
    
};

//Default Destructor
LEAPBMLAETerm::~LEAPBMLAETerm(){
    
};

//Constructor
LEAPBMLAETerm::LEAPBMLAETerm(std::string aId,
                             std::string aVersion,
                             std::string aPath):
    id(aId),
    version(aVersion),
    path(aPath){
    
};


//Get id class
std::string LEAPBMLAETerm::getId(){

    LOGMSG(5, "BEGIN LEAPBMLAETerm: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMLAETerm: " << id << " getting id\n");

    return id;

};


//Set id class
void LEAPBMLAETerm::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMLAETerm: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMLAETerm: " << id << " setting id\n");

};


//Get version
std::string LEAPBMLAETerm::getVersion(){

    LOGMSG(5, "BEGIN LEAPBMLAETerm: " << id << " getting version\n");
    LOGMSG(5, "END LEAPBMLAETerm: " << id << " getting version\n");

    return version;

};


//Set version
void LEAPBMLAETerm::setVersion(std::string aVersion){

    LOGMSG(5, "BEGIN LEAPBMLAETerm: " << id << " setting version\n");

    version = aVersion;

    LOGMSG(5, "END LEAPBMLAETerm: " << id << " setting version\n");

};

//Get path
std::string LEAPBMLAETerm::getPath(){

    LOGMSG(5, "BEGIN LEAPBMLAETerm: " << id << " getting path\n");
    LOGMSG(5, "END LEAPBMLAETerm: " << id << " getting path\n");

    return path;

};


//Set path
void LEAPBMLAETerm::setPath(std::string aPath){

    LOGMSG(5, "BEGIN LEAPBMLAETerm: " << id << " setting path\n");

    path = aPath;

    LOGMSG(5, "END LEAPBMLAETerm: " << id << " setting path\n");

};

//Load the configuration
bool LEAPBMLAETerm::loadConfiguration(ConfigurationElement *aElement){
    
    std::string id, version, path;

    //configure this LAETerm
    setId(id = aElement->getParameterValue("id").c_str());
    setVersion(version = aElement->getParameterValue("version").c_str());
    setPath(path = aElement->getParameterValue("path").c_str());

    //go and get the file from the path
    std::ifstream laefile;
    laefile.open(getPath().c_str(), std::ifstream::in);
    if(!laefile.is_open()){
        LOGWRN("Error opening file representing LAETerm " << id << " (" << path << ").");
        return false;
    }
    
    laefile.close();
    
    //check that this laeterm hasn't already been loaded
    if(ConfigurationStore::configurationStores["LAESET"+id+version] != NULL){
        LOGWRN("LAETerm: " << id << "(Ver: " << version << ") has already been loaded.");
        return ConfigurationStore::configurationStores["LAESET"+id+version]->initialised;
    }
    
    //create an instance of XMLStore
    ConfigurationStore::configurationStores["LAESET"+id+version] = new XMLStore();
    
    //load the configuration from the default file
    if(!ConfigurationStore::configurationStores["LAESET"+id+version]->loadConfiguration(getPath().c_str())){
        LOGERR("Loading XML Configuration of LEAPBM failed.");
    }

    //instantiate a new LAESet and pass this configuration store instance to it
    bool success = true;
    LAEs = new LAESet();
    success &= LAEs->loadConfiguration(ConfigurationStore::configurationStores["LAESET"+id+version]);
    
    return success;
    
}

bool LEAPBMLAETerm::postConfigurationLoad(){
    
    bool success = true;
    success &= LAEs->postConfigurationLoad();

    return success;
    
}


//Save the configuration
bool LEAPBMLAETerm::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LEAPBMLAETerm::hash(){

    LOGMSG(5, "BEGIN LEAPBMLAETerm: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMLAETerm: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMLAETERM, id);
    
};




