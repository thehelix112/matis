// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMFile.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.7 $

#include "MATIS_LEAPBMFile.h"
#include "MATIS_Model.h"


using namespace MATIS;

//Default Constructor
LEAPBMFile::LEAPBMFile():
    id(""),
    path(""){
    
};

//Default Destructor
LEAPBMFile::~LEAPBMFile(){
    
};

//Constructor
LEAPBMFile::LEAPBMFile(std::string aId,
                       std::string aPath):
    id(aId),
    path(aPath){
    
};

//Get id method
std::string LEAPBMFile::getId(){

    LOGMSG(5, "BEGIN LEAPBMFile: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMFile: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMFile::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMFile: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMFile: " << id << " setting id\n");

};


//Get id method
std::string LEAPBMFile::getPath(){

    LOGMSG(5, "BEGIN LEAPBMFile: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMFile: " << id << " getting id\n");

    return path;

};


//Set id method
void LEAPBMFile::setPath(std::string aPath){

    LOGMSG(5, "BEGIN LEAPBMFile: " << id << " setting id\n");

    path = aPath;

    LOGMSG(5, "END LEAPBMFile: " << id << " setting id\n");

};

//Load the configuration
bool LEAPBMFile::loadConfiguration(ConfigurationElement *aElement){

    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());
    setPath(aElement->getParameterValue("path").c_str());

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){

        if((*it).name == "method"){
         
            LEAPBMMethod *aMethod = new LEAPBMMethod;
            aMethod->loadConfiguration(&(*it));
            aMethod->parentType = OBJECT_LEAPBMFILE;
            methods.push_back(Model::LEAPBMMethodStore.addValue(aMethod));
            
        }
                                                                               
    }
   
}

bool LEAPBMFile::postConfigurationLoad(){

    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = methods.begin(); it != methods.end(); ++it){
        (Model::LEAPBMMethodStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMMethodStore.getValue(*it))->postConfigurationLoad();
    }

    return success;
}


//Save the configuration
bool LEAPBMFile::saveConfiguration(ConfigurationElement *aElement){    
    
}




//return a string hash of the current object
std::string LEAPBMFile::hash(){

    LOGMSG(5, "BEGIN LEAPBMFile: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMFile: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMFILE, id);
    
};




