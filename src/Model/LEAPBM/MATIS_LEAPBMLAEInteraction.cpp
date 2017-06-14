// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMLAEInteraction.cpp,v $
// CVS $Date: 2005/12/05 12:53:00 $
// CVS $Revision: 1.4 $

#include "MATIS_LEAPBMLAEInteraction.h"
#include "MATIS_LEAPBM.h"
#include "MATIS_Model.h"

using namespace MATIS;

//Default Constructor
LEAPBMLAEInteraction::LEAPBMLAEInteraction():
    id(""),
    LAE(0),
    methodCall(0),
    propertySet(0),
    performed(false){
    
};

//Default Destructor
LEAPBMLAEInteraction::~LEAPBMLAEInteraction(){
    
};

//Constructor
LEAPBMLAEInteraction::LEAPBMLAEInteraction(std::string aId,
                                           handleType aLAE,
                                           handleType aMethodCall,
                                           handleType aPropertySet):
    id(aId),
    LAE(aLAE),
    methodCall(aMethodCall),
    propertySet(aPropertySet),
    performed(false){
    
};

//Get id class
std::string LEAPBMLAEInteraction::getId(){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " getting id\n");

    return id;

};


//Set id class
void LEAPBMLAEInteraction::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " setting id\n");

};

//Get LAE method
handleType LEAPBMLAEInteraction::getLAE(){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " getting LAE\n");
    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " getting LAE\n");

    return LAE;

};


//Set LAE method
void LEAPBMLAEInteraction::setLAE(handleType aLAE){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << LAE << " setting LAE\n");

    LAE = aLAE;

    LOGMSG(5, "END LEAPBMLAEInteraction: " << LAE << " setting LAE\n");

};


//Get id method
handleType LEAPBMLAEInteraction::getMethodCall(){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " getting methodCall\n");
    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " getting methodCall\n");

    return methodCall;

};


//Set id method
void LEAPBMLAEInteraction::setMethodCall(handleType aMethodCall){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " setting methodCall\n");

    methodCall = aMethodCall;

    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " setting methodCall\n");

};

//Get id method
handleType LEAPBMLAEInteraction::getPropertySet(){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " getting propertySet\n");
    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " getting propertySet\n");

    return propertySet;

};


//Set id method
void LEAPBMLAEInteraction::setPropertySet(handleType aPropertySet){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " setting propertySet\n");

    propertySet = aPropertySet;

    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " setting propertySet\n");

};


//Load the configuration
bool LEAPBMLAEInteraction::loadConfiguration(ConfigurationElement *aElement){
   
    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());

    laeId = aElement->getParameterValue("lae_id").c_str();
    methodCallId = aElement->getParameterValue("methodcall_id").c_str();
    propertySetId = aElement->getParameterValue("propertyset_id").c_str();
    
    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){

        if((*it).name == "pathway"){
         
            LEAPBMPathway *aPathway = new LEAPBMPathway;
            aPathway->loadConfiguration(&(*it));
            aPathway->parentType = OBJECT_LEAPBMLAEINTERACTION;
            pathwayObjects.push_back(aPathway);
            
        }

        if((*it).name == "exception"){
         
            LEAPBMException *aException = new LEAPBMException;
            aException->loadConfiguration(&(*it));
            aException->parentType = OBJECT_LEAPBMLAEINTERACTION;
            exceptionObjects.push_back(aException);
            
        }
        
    }

}

bool LEAPBMLAEInteraction::postConfigurationLoad(){

    bool success = true;

    //delay adding of a pathway until here because its hash depends on its parent's handle
    for(std::list < LEAPBMPathway* >::iterator it = pathwayObjects.begin();
        it != pathwayObjects.end();
        ++it){

        (*it)->parentHandle = handle;
        success &= (*it)->postConfigurationLoad();
        pathways.push_back(Model::LEAPBMPathwayStore.addValue(*it));
    }


    //delay adding of a exception until here because its hash depends on its parent's handle
    for(std::list < LEAPBMException* >::iterator it = exceptionObjects.begin();
        it != exceptionObjects.end();
        ++it){

        (*it)->parentHandle = handle;
        handleType thisException = Model::LEAPBMExceptionStore.addValue(*it);
        exceptions.push_back(thisException);

        //get it and post load now so its pathways get set appropriately
        LEAPBMException *aException = Model::LEAPBMExceptionStore.getValue(thisException);
        success &= aException->postConfigurationLoad();
    }

    handleType handle;

    //get the lae handle from the id
    if(LEAPBM::getLAE(laeId, &handle)){
        success &= true;
        setLAE(handle);
    } else {
        success &= false;
        LOGWRN("Reference made to unknown LAE: " << laeId << "\n");
    }    

    if(methodCallId.length() > 0){
        //get the methodcall handle from the id
        if(LEAPBM::getMethodCall(methodCallId, &handle)){
            success &= true;
            setMethodCall(handle);
        } else {
            success &= false;
            LOGWRN("Reference made to unknown MethodCall: " << methodCallId << "\n");
        }
    } else if(propertySetId.length() > 0) {
        //get the propertySet handle from the id
        if(LEAPBM::getPropertySet(propertySetId, &handle)){
            success &= true;
            setPropertySet(handle);
        } else {
            success &= false;
            LOGWRN("Reference made to unknown PropertySet: " << propertySetId << "\n");
        }
    } else {
        LOGERR("Reference to neither MethodCall or PropertySet!");   
    }
        
    return success;
    
}



//Save the configuration
bool LEAPBMLAEInteraction::saveConfiguration(ConfigurationElement *aElement){    
    
}


//return a string hash of the current object
std::string LEAPBMLAEInteraction::hash(){

    LOGMSG(5, "BEGIN LEAPBMLAEInteraction: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMLAEInteraction: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMLAEINTERACTION, id);
    
};


//perform will set the property reference values of the lae as set in
//this lae method call
void LEAPBMLAEInteraction::perform(){

    performed = true;

    //Set the LAE propertyReference map values as determined by this method call's <propertyset>s
    LEAPBMLAE *laeInstance = Model::LEAPBMLAEStore.getValue(LAE);
    LEAPBMMethodCall *laeMethodCall = Model::LEAPBMMethodCallStore.getValue(methodCall);

    //lots to be done here for the CORRECT setting of ALL possible LAE properties.
    //  ?? can't think now, do it later on but basically we want to get
    //  a list of sources and THEN perform them. 

    //for each <propertyset> in the <methodcall> go and set the LAE's property value
    for(handleListType::iterator it = laeMethodCall->propertySets.begin(); it != laeMethodCall->propertySets.end(); ++it){
     
        LEAPBMPropertySet *propertySet = Model::LEAPBMPropertySetStore.getValue(*it);
        laeInstance->setPropertyValue(propertySet->property, propertySet->getByteValue());
        
    }

    //Decide whether we need to record if a laemethodcall is performed or if it fails checks.
    //add this LEAPBMMethodCall to the list of ones that have been performed.
    ((LEAPBM*)Model::model)->performedLAEMethods.push_back(laeMethodCall->method);
    
}


std::string LEAPBMLAEInteraction::getDot(int level){

    handleListType::iterator it;

    std::string dotString;

    for(int i = 0; i < level; ++i)
        dotString += "  ";

    //generate the appropriate id
    //<LAE Instance Name> : <interaction name><interaction type>
    //E.g. fed_XA : create();
    std::string label = laeId + "\\n";
    
    if(methodCall == 0){
        //tis a property set
        label += propertySetId;
    } else if(propertySet == 0){
        //tis a method call
        label += methodCallId + "()";
    }

    dotString += "Inter_" + id + " [label=\"" + label
        + "\",shape=circle];\n";

    for(it = pathways.begin(); it != pathways.end(); ++it){
        LEAPBMPathway *aPathway = Model::LEAPBMPathwayStore.getValue(*it);
        dotString += aPathway->getDot(level);
    }

    for(it = exceptions.begin(); it != exceptions.end(); ++it){
        LEAPBMException *aException = Model::LEAPBMExceptionStore.getValue(*it);
        dotString += aException->getDot(level);
    }

    return dotString;
    
}

    
