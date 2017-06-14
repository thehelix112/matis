// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIGroup.cpp,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.8 $

#include "MATIS_APIGroup.h"
#include "MATIS_Model.h"

using namespace MATIS;

//Default Constructor
APIGroup::APIGroup():
    id(""){
    
};

//Default Destructor
APIGroup::~APIGroup(){
     
};

//Constructor
APIGroup::APIGroup(std::string aId):
    id(aId){
    
};

//Get id method
std::string APIGroup::getId(){

    LOGMSG(5, "BEGIN APIGroup: " << id << " getting id\n");
    LOGMSG(5, "END APIGroup: " << id << " getting id\n");

    return id;

};


//Set id method
void APIGroup::setId(std::string aId){

    LOGMSG(5, "BEGIN APIGroup: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END APIGroup: " << id << " setting id\n");

};

//Load the configuration
bool APIGroup::loadConfiguration(ConfigurationElement *aElement){

   //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "apimethod"){
         
            APIMethod *aAPIMethod = new APIMethod;
            aAPIMethod->loadConfiguration(&(*it));
            aAPIMethod->parentType = OBJECT_APIGROUP;
            methods.push_back(Model::APIMethodStore.addValue(aAPIMethod));
            
        }

        if((*it).name == "apiexception"){
         
            APIException *aAPIException = new APIException;
            aAPIException->loadConfiguration(&(*it));
            aAPIException->parentType = OBJECT_APIGROUP;
            exceptions.push_back(Model::APIExceptionStore.addValue(aAPIException));
            
        }

        if((*it).name == "apivariable"){
         
            APIVariable *aAPIVariable = new APIVariable;
            aAPIVariable->loadConfiguration(&(*it));
            aAPIVariable->parentType = OBJECT_APIGROUP;
            variables.push_back(Model::APIVariableStore.addValue(aAPIVariable));
            
        }
        
    }
   
}


bool APIGroup::postConfigurationLoad(){
  
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;

    LOGMSG(6, "APIMethods\n");
    for(it = methods.begin(); it != methods.end(); ++it){
        LOGMSG(6, " " << (*it));
        (Model::APIMethodStore.getValue(*it))->parentHandle = handle;
        success &= (Model::APIMethodStore.getValue(*it))->postConfigurationLoad();
        LOGMSG(6, "D\n");
    }

    LOGMSG(6, "APIException\n");    
    for(it = exceptions.begin(); it != exceptions.end(); ++it){
        LOGMSG(6, " " << (*it));
        (Model::APIExceptionStore.getValue(*it))->parentHandle = handle;
        success &= (Model::APIExceptionStore.getValue(*it))->postConfigurationLoad();
        LOGMSG(6, "D\n");
    }

    LOGMSG(6, "APIVariable\n");
    for(it = variables.begin(); it != variables.end(); ++it){
        LOGMSG(6, " " << (*it));
        (Model::APIVariableStore.getValue(*it))->parentHandle = handle;
        success &= (Model::APIVariableStore.getValue(*it))->postConfigurationLoad();
        LOGMSG(6, "D\n");
    }

    return success; 
    
}

//Save the configuration
bool APIGroup::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string APIGroup::hash(){

    LOGMSG(5, "BEGIN APIGroup: " << id << " hash\n");
    LOGMSG(5, "END APIGroup: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_APIGROUP, id);
    
};
