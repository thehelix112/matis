// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIMethod.cpp,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.10 $

#include "MATIS_APIMethod.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
APIMethod::APIMethod():
    id(""),
    name(""),
    contextId(""),
    numParameters(0),
    returns(0){
    
};

//Default Destructor
APIMethod::~APIMethod(){
        
};

//Constructor
APIMethod::APIMethod(std::string aId, 
                     std::string aName,
                     std::string aContextId,
                     handleType aReturns,
                     int aParameters):
    id(aId),
    name(aName),
    contextId(aContextId),
    numParameters(aParameters),
    returns(aReturns){    
    
};

//Get id method
std::string APIMethod::getId(){

    LOGMSG(5, "BEGIN APIMethod: " << id << " getting id\n");
    LOGMSG(5, "END APIMethod: " << id << " getting id\n");

    return id;

};


//Set id method
void APIMethod::setId(std::string aId){

    LOGMSG(5, "BEGIN APIMethod: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END APIMethod: " << id << " setting id\n");

};


//Get name method
std::string APIMethod::getName(){

    LOGMSG(5, "BEGIN APIMethod: " << id << " getting name\n");
    LOGMSG(5, "END APIMethod: " << id << " getting name\n");

    return name;

};


//Set name method
void APIMethod::setName(std::string aName){

    LOGMSG(5, "BEGIN APIMethod: " << id << " setting name\n");

    name = aName;

    LOGMSG(5, "END APIMethod: " << id << " setting name\n");

};

//Get contextId method
std::string APIMethod::getContextId(){

    LOGMSG(5, "BEGIN APIMethod: " << id << " getting contextId\n");
    LOGMSG(5, "END APIMethod: " << id << " getting contextId\n");

    return contextId;

};


//Set contextId method
void APIMethod::setContextId(std::string aContextId){

    LOGMSG(5, "BEGIN APIMethod: " << id << " setting contextId\n");

    contextId = aContextId;

    LOGMSG(5, "END APIMethod: " << id << " setting contextId\n");

};

//Set number of parameters
void APIMethod::setNumParameters(int aNumParameters){

    LOGMSG(5, "BEGIN APIMethod: " << id << " setting number of parameters\n");
    
    numParameters = aNumParameters;

    LOGMSG(5, "END APIMethod: " << id << " setting number of parameters\n");
    
}

//Get parameters method
int APIMethod::getNumParameters(){

    LOGMSG(5, "BEGIN APIMethod: " << id << " getting number of parameters\n");
    LOGMSG(5, "END APIMethod: " << id << " getting number of parameters\n");

    return numParameters;

};

//Load the configuration
bool APIMethod::loadConfiguration(ConfigurationElement *aElement){

    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setName(aElement->getParameterValue("name").c_str());
    setContextId(aElement->getParameterValue("context_id").c_str());
    setNumParameters(Types::stringToInt(aElement->getParameterValue("parameters").c_str()));

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "apireturn"){
         
            APIReturn *aAPIReturn = new APIReturn;
            aAPIReturn->loadConfiguration(&(*it));
            aAPIReturn->parentType = OBJECT_APIMETHOD;
            returns = Model::APIReturnStore.addValue(aAPIReturn);
            
        }

        if((*it).name == "apiexceptionreference"){
            
            exceptionIds.push_back((*it).getParameterValue("apiexception_id").c_str());
                        
        }

        if((*it).name == "apiparameter"){
         
            APIParameter *aAPIParameter = new APIParameter;
            aAPIParameter->loadConfiguration(&(*it));
            aAPIParameter->parentType = OBJECT_APIMETHOD;
            parameters.push_back(Model::APIParameterStore.addValue(aAPIParameter));
            
        }
        
    }
   
}

bool APIMethod::postConfigurationLoad(){
  
    bool success = true;

    //go through and finish all the links between things
    if(returns > 0){
        (Model::APIReturnStore.getValue(returns))->parentHandle = handle;
        success &= (Model::APIReturnStore.getValue(returns))->postConfigurationLoad();
    }    

    handleListType::iterator it;    
    for(it = parameters.begin(); it != parameters.end(); ++it){
        (Model::APIParameterStore.getValue(*it))->parentHandle = handle;
        success &= (Model::APIParameterStore.getValue(*it))->postConfigurationLoad();
    }    

    stringListType::iterator iq;
    handleType handle;
    for(iq = exceptionIds.begin(); iq != exceptionIds.end(); ++iq){
    
        //get the APIException handle from the id
        if(LAESet::getAPIException((*iq).c_str(), &handle)){
            exceptions.push_back(handle);
            success &= true;
        } else {
            success &= false;
            LOGWRN("Reference made to unknown APIException: " << (*iq) << "\n");
        }
        
    }

    return success; 
    
}

//Save the configuration
bool APIMethod::saveConfiguration(ConfigurationElement *aElement){
    
    
}



//return a string hash of the current object
std::string APIMethod::hash(){

    LOGMSG(5, "BEGIN APIMethod: " << id << " hash\n");
    LOGMSG(5, "END APIMethod: " << id << " hash\n");
    
    return Hashable::hashObject(OBJECT_APIMETHOD, id);
    
};



