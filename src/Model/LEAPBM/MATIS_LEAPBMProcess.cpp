// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMProcess.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.7 $

#include "MATIS_LEAPBMProcess.h"
#include "MATIS_LEAPBMHost.h"
#include "MATIS_LEAPBM.h"

using namespace MATIS;

//Default Constructor
LEAPBMProcess::LEAPBMProcess():
    id(""){
    
};

//Default Destructor
LEAPBMProcess::~LEAPBMProcess(){
    
};

//Constructor
LEAPBMProcess::LEAPBMProcess(std::string aId):
    id(aId){
    
};

//Get id method
std::string LEAPBMProcess::getId(){

    LOGMSG(5, "BEGIN LEAPBMProcess: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMProcess: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMProcess::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMProcess: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMProcess: " << id << " setting id\n");

};


//Load the configuration
bool LEAPBMProcess::loadConfiguration(ConfigurationElement *aElement){

    //configure the ID of this LEAPBM.
    setId(aElement->getParameterValue("id").c_str());

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
                                                                               
        if((*it).name == "host"){
         
            LEAPBMHost *aHost = new LEAPBMHost;
            aHost->loadConfiguration(&(*it));
            aHost->parentType = OBJECT_LEAPBMPROCESS;
            hosts.push_back(Model::LEAPBMHostStore.addValue(aHost));
            
        }

        if((*it).name == "file"){
         
            LEAPBMFile *aFile = new LEAPBMFile;
            aFile->loadConfiguration(&(*it));
            aFile->parentType = OBJECT_LEAPBMPROCESS;
            files.push_back(Model::LEAPBMFileStore.addValue(aFile));
            
        }

        if((*it).name == "method"){
         
            LEAPBMMethod *aMethod = new LEAPBMMethod;
            aMethod->loadConfiguration(&(*it));
            aMethod->parentType = OBJECT_LEAPBMPROCESS;
            methods.push_back(Model::LEAPBMMethodStore.addValue(aMethod));
            
        }
                                                                               
    }

  
}

bool LEAPBMProcess::postConfigurationLoad(){
    
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = hosts.begin(); it != hosts.end(); ++it){
        (Model::LEAPBMHostStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMHostStore.getValue(*it))->postConfigurationLoad();
    }

    for(it = files.begin(); it != files.end(); ++it){
        (Model::LEAPBMFileStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMFileStore.getValue(*it))->postConfigurationLoad();
    }

    for(it = methods.begin(); it != methods.end(); ++it){
        (Model::LEAPBMMethodStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMMethodStore.getValue(*it))->postConfigurationLoad();
    }

    return success;
    
}


//Save the configuration
bool LEAPBMProcess::saveConfiguration(ConfigurationElement *aElement){    
    
}


//return a string hash of the current object
std::string LEAPBMProcess::hash(){

    LOGMSG(5, "BEGIN LEAPBMProcess: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMProcess: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMPROCESS, id);
    
};




