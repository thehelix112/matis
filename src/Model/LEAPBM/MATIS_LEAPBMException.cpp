// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMException.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.8 $

#include "MATIS_LEAPBMException.h"
#include "MATIS_LEAPBM.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
LEAPBMException::LEAPBMException():
    exception(0){
    
};

//Default Destructor
LEAPBMException::~LEAPBMException(){
    
};

//Constructor
LEAPBMException::LEAPBMException(handleType aException):
    exception  (aException){
    
};

//Get exception class
handleType LEAPBMException::getException(){

    LOGMSG(5, "BEGIN LEAPBMException: " << exception << " getting exception\n");
    LOGMSG(5, "END LEAPBMException: " << exception << " getting exception\n");

    return exception;

};


//Set exception class
void LEAPBMException::setException(handleType aException){

    LOGMSG(5, "BEGIN LEAPBMException: " << exception << " setting exception\n");

    exception = aException;

    LOGMSG(5, "END LEAPBMException: " << exception << " setting exception\n");

};

//Load the configuration
bool LEAPBMException::loadConfiguration(ConfigurationElement *aElement){

    exceptionId = aElement->getParameterValue("exception_id").c_str();

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){

        if((*it).name == "pathway"){
         
            LEAPBMPathway *aPathway = new LEAPBMPathway;
            aPathway->loadConfiguration(&(*it));
            aPathway->parentType = OBJECT_LEAPBMEXCEPTION;
            pathwayObjects.push_back(aPathway);
            
        }

    }
   
}


bool LEAPBMException::postConfigurationLoad(){
    
    bool success = true;

    //delay adding of a pathway until here because its hash depends on its parent's handle
    for(std::list < LEAPBMPathway* >::iterator it = pathwayObjects.begin();
        it != pathwayObjects.end();
        ++it){

        (*it)->parentHandle = handle;
        success &= (*it)->postConfigurationLoad();
        pathways.push_back(Model::LEAPBMPathwayStore.addValue(*it));
    }

    //get the exception handle from the id
    handleType handle;
    if(LAESet::getAPIException(exceptionId, &handle)){
        setException(handle);
        success &= true;
    } else {
        LOGWRN("Reference made to unknown Exception: " << exceptionId << "\n");
        success &= false;
    }

    return success;
    
}


//Save the configuration
bool LEAPBMException::saveConfiguration(ConfigurationElement *aElement){    
    
}

//return a string hash of the current object
std::string LEAPBMException::hash(){

    LOGMSG(5, "BEGIN LEAPBMException: " << exceptionId << " hash\n");
    LOGMSG(5, "END LEAPBMException: " << exceptionId << " hash\n");

    //include parent in this hash
    std::string fullhan;
    fullhan += Types::unsignedLongToString(parentHandle);
    char buffer[4] = {0,0,0,0};
    *(objectType *) buffer = parentType;
    fullhan += std::string(buffer,4);
    fullhan += exceptionId;

    return Hashable::hashObject(OBJECT_LEAPBMEXCEPTION, fullhan);
    
};


std::string LEAPBMException::getDot(int level){

    handleListType::iterator it;

    std::string dotString;

    for(int i = 0; i < level; ++i)
        dotString += "  ";

    for(it = pathways.begin(); it != pathways.end(); ++it){

        LEAPBMPathway *aPathway = Model::LEAPBMPathwayStore.getValue(*it);
        std::string tmpString = aPathway->getDot(0);
        //insert our stuff before ;

        tmpString.insert(tmpString.find(';'), " [label=\"" + exceptionId + "\"]");
        dotString += tmpString;
        
    }

    return dotString;
    
}

std::string LEAPBMException::getExceptionId(){

    return exceptionId;
    
}




