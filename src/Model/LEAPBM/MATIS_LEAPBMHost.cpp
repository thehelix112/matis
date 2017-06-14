// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMHost.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.7 $

#include "MATIS_LEAPBMHost.h"
#include "MATIS_Model.h"

using namespace MATIS;

//Default Constructor
LEAPBMHost::LEAPBMHost():
    id(""),
    domainName(""){
    
};

//Default Destructor
LEAPBMHost::~LEAPBMHost(){
    
};

//Constructor
LEAPBMHost::LEAPBMHost(std::string aId,
                                     std::string aDomainName):
    id(aId),
    domainName(aDomainName){
    
};

//Get id method
std::string LEAPBMHost::getId(){

    LOGMSG(5, "BEGIN LEAPBMHost: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMHost: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMHost::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMHost: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMHost: " << id << " setting id\n");

};


//Get id method
std::string LEAPBMHost::getDomainName(){

    LOGMSG(5, "BEGIN LEAPBMHost: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMHost: " << id << " getting id\n");

    return domainName;

};


//Set id method
void LEAPBMHost::setDomainName(std::string aDomainName){

    LOGMSG(5, "BEGIN LEAPBMHost: " << id << " setting id\n");

    domainName = aDomainName;

    LOGMSG(5, "END LEAPBMHost: " << id << " setting id\n");

};


//Load the configuration
bool LEAPBMHost::loadConfiguration(ConfigurationElement *aElement){

    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());
    setDomainName(aElement->getParameterValue("domainname").c_str());

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){

        if((*it).name == "file"){
         
            LEAPBMFile *aFile = new LEAPBMFile;
            aFile->loadConfiguration(&(*it));
            aFile->parentType = OBJECT_LEAPBMHOST;
            files.push_back(Model::LEAPBMFileStore.addValue(aFile));
            
        }

        if((*it).name == "method"){
         
            LEAPBMMethod *aMethod = new LEAPBMMethod;
            aMethod->loadConfiguration(&(*it));
            aMethod->parentType = OBJECT_LEAPBMHOST;
            methods.push_back(Model::LEAPBMMethodStore.addValue(aMethod));
            
        }
                                                                               
    }
   
}

bool LEAPBMHost::postConfigurationLoad(){
    
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = methods.begin(); it != methods.end(); ++it){
        (Model::LEAPBMMethodStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMMethodStore.getValue(*it))->postConfigurationLoad();
    }

    for(it = files.begin(); it != files.end(); ++it){
        (Model::LEAPBMFileStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMFileStore.getValue(*it))->postConfigurationLoad();
    }

    return success;
    
}

//Save the configuration
bool LEAPBMHost::saveConfiguration(ConfigurationElement *aElement){    
    
}


//return a string hash of the current object
std::string LEAPBMHost::hash(){

    LOGMSG(5, "BEGIN LEAPBMHost: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMHost: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMHOST, id);
    
};




