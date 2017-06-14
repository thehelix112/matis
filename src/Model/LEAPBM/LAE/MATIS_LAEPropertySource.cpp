// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEPropertySource.cpp,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.8 $

#include "MATIS_LAEPropertySource.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;


//Default Constructor
LAEPropertySource::LAEPropertySource():
    authority(0),
    APIParameter(0),
    APIVariable(0),
    APIReturn(0){
    
};

//Default Destructor
LAEPropertySource::~LAEPropertySource(){
    
};

//Constructor
LAEPropertySource::LAEPropertySource(int aAuthority, 
                                     handleType aAPIParameter = 0,
                                     handleType aAPIReturn = 0,
                                     handleType aAPIVariable = 0):
    authority(aAuthority),
    APIParameter(aAPIParameter),
    APIVariable(aAPIVariable),
    APIReturn(aAPIReturn){    
    
};

//Get authority method
std::string LAEPropertySource::getId(){

    LOGMSG(5, "BEGIN LAEPropertySource: " << APIParameter << APIReturn << APIVariable << " getting id\n");
    LOGMSG(5, "END LAEPropertySource: " << APIParameter << APIReturn << APIVariable << " getting id\n");

    char buffer[12];
    *(int *)&(buffer[0]) = APIParameter;
    *(int *)&(buffer[4]) = APIReturn;
    *(int *)&(buffer[8]) = APIVariable;

    return std::string(buffer, 12);

};

//Get authority method
int LAEPropertySource::getAuthority(){

    LOGMSG(5, "BEGIN LAEPropertySource: " << getId() << " getting authority\n");
    LOGMSG(5, "END LAEPropertySource: " << getId() << " getting authority\n");

    return authority;

};


//Set authority method
void LAEPropertySource::setAuthority(int aAuthority){

    LOGMSG(5, "BEGIN LAEPropertySource: " << getId() << " setting authority\n");

    authority = aAuthority;

    LOGMSG(5, "END LAEPropertySource: " << getId() << " setting authority\n");

};


//Get APIParameter method
handleType LAEPropertySource::getAPIParameter(){

    LOGMSG(5, "BEGIN LAEPropertySource: " << getId() << " getting APIParameter\n");
    LOGMSG(5, "END LAEPropertySource: " << getId() << " getting APIParameter\n");

    return APIParameter;

};


//Set APIParameter method
void LAEPropertySource::setAPIParameter(handleType aAPIParameter){

    LOGMSG(5, "BEGIN LAEPropertySource: " << getId() << " setting APIParameter\n");

    APIParameter = aAPIParameter;

    LOGMSG(5, "END LAEPropertySource: " << getId() << " setting APIParameter\n");

};


//Get APIReturn method
handleType LAEPropertySource::getAPIReturn(){

    LOGMSG(5, "BEGIN LAEPropertySource: " << getId() << " getting APIReturn\n");
    LOGMSG(5, "END LAEPropertySource: " << getId() << " getting APIReturn\n");

    return APIReturn;

};


//Set APIReturn method
void LAEPropertySource::setAPIReturn(handleType aAPIReturn){

    LOGMSG(5, "BEGIN LAEPropertySource: " << getId() << " setting APIReturn\n");

    APIReturn = aAPIReturn;

    LOGMSG(5, "END LAEPropertySource: " << getId() << " setting APIReturn\n");

};


//Get APIVariable method
handleType LAEPropertySource::getAPIVariable(){

    LOGMSG(5, "BEGIN LAEPropertySource: " << APIParameter << APIVariable << " getting APIVariable\n");
    LOGMSG(5, "END LAEPropertySource: " << APIParameter << APIVariable << " getting APIVariable\n");

    return APIVariable;

};


//Set APIVariable method
void LAEPropertySource::setAPIVariable(handleType aAPIVariable){

    LOGMSG(5, "BEGIN LAEPropertySource: " << APIParameter << APIVariable << " setting APIVariable\n");

    APIVariable = aAPIVariable;

    LOGMSG(5, "END LAEPropertySource: " << APIParameter << APIVariable << " setting APIVariable\n");

};

//bool helper methods
bool LAEPropertySource::isParameter(){

    return(APIParameter > 0 &&
           APIVariable == 0 &&
           APIReturn == 0);

}

bool LAEPropertySource::isVariable(){

    return(APIParameter == 0 &&
           APIVariable > 0 &&
           APIReturn == 0);

}

bool LAEPropertySource::isReturn(){

    return(APIParameter == 0 &&
           APIVariable == 0 &&
           APIReturn > 0);
    
}


//Load the configuration
bool LAEPropertySource::loadConfiguration(ConfigurationElement *aElement){
   
   //configure the values from the configuration element
    setAuthority(Types::stringToInt(aElement->getParameterValue("authority").c_str()));

    apiParameterId = aElement->getParameterValue("apiparameter_id").c_str();
    apiReturnId = aElement->getParameterValue("apireturn_id").c_str();
    apiVariableId = aElement->getParameterValue("apivariable_id").c_str();

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "propertyreference"){
         
            LAEPropertyReference *aLAEPropertyReference = new LAEPropertyReference;
            aLAEPropertyReference->loadConfiguration(&(*it));
            aLAEPropertyReference->parentType = OBJECT_LAEPROPERTYSOURCE;
            propertyReferences.push_back(Model::LAEPropertyReferenceStore.addValue(aLAEPropertyReference));
            
        }
        
    }

       
}


bool LAEPropertySource::postConfigurationLoad(){
 
    bool success = false;    
    handleType handle;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = propertyReferences.begin(); it != propertyReferences.end(); ++it){
        (Model::LAEPropertyReferenceStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LAEPropertyReferenceStore.getValue(*it))->postConfigurationLoad();
    }
    

    //get the Apiparameter handle from the id
    if(apiParameterId.length() > 0){
        if(LAESet::getAPIParameter(apiParameterId, &handle)){
            setAPIParameter(handle);
            success = true;
        } else {
            success = false;
            LOGWRN("Reference made to unknown Apiparameter: " << apiParameterId << "\n");
        }
    }

    //get the Apireturn handle from the id
    if(apiReturnId.length() > 0){

        if(success){
            //previous set of soruce and we can't set multiples. TODO
            LOGWRN("Property source already set. Multiple sources will be set.\n");
        }
        
        if(LAESet::getAPIReturn(apiReturnId, &handle)){
            LOGMSG(6, " setting source of property to apireturn: " << apiReturnId << "\n");
            setAPIReturn(handle);
            success = true;
        } else {
            success = false;
            LOGWRN("Reference made to unknown Apireturn: " << apiReturnId << "\n");
        }
    }

    //get the Apivariable handle from the id
    if(apiVariableId.length() > 0){
        if(success){
            //previous set of soruce and we can't set multiples. TODO
            LOGWRN("Property source already set. Multiple sources will be set.\n");
        }

        if(LAESet::getAPIVariable(apiVariableId, &handle)){
            setAPIVariable(handle);
            success = true;
        } else {
            success = false;
            LOGWRN("Reference made to unknown Apivariable: " << apiVariableId << "\n");
        }
    }


    return success;

}


//Save the configuration
bool LAEPropertySource::saveConfiguration(ConfigurationElement *aElement){
    
    
}


//return a string hash of the current object
std::string LAEPropertySource::hash(){

    LOGMSG(5, "BEGIN LAEPropertySource: " << getId() << " hash\n");
    LOGMSG(5, "END LAEPropertySource: " << getId() << " hash\n");

    return Hashable::hashObject(OBJECT_LAEPROPERTYSOURCE, getId());
    
};



