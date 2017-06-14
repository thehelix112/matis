// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAESet.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.9 $

#include "MATIS_LAESet.h"
#include "MATIS_LAEClass.h"
#include "MATIS_LAETrigger.h"
#include "MATIS_APIGroup.h"
#include "MATIS_LAEChecker.h"
#include "MATIS_LAEFunction.h"
#include "MATIS_LAEValueGroup.h"
#include "MATIS_LAERequirement.h"
#include "MATIS_LAEPolicy.h"
#include "MATIS_Model.h"

using namespace MATIS;


//Default Constructor
LAESet::LAESet():
    id(""),
    version(""),
    author(""),
    organisation(""){
    
};

//Default Destructor
LAESet::~LAESet(){
     
};

//Constructor
LAESet::LAESet(std::string aId,
               std::string aVersion,
               std::string aAuthor,
               std::string aOrganisation):
    id(aId),
    version(aVersion),
    author(aAuthor),
    organisation(aOrganisation){
    
};

//Get id method
std::string LAESet::getId(){

    LOGMSG(5, "BEGIN LAESet: " << id << " getting id\n");
    LOGMSG(5, "END LAESet: " << id << " getting id\n");

    return id;

};


//Set id method
void LAESet::setId(std::string aId){

    LOGMSG(5, "BEGIN LAESet: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAESet: " << id << " setting id\n");

};


//Get version method
std::string LAESet::getVersion(){

    LOGMSG(5, "BEGIN LAESet: " << id << " getting version\n");
    LOGMSG(5, "END LAESet: " << id << " getting version\n");

    return version;

};


//Set version method
void LAESet::setVersion(std::string aVersion){

    LOGMSG(5, "BEGIN LAESet: " << id << " setting version\n");

    version = aVersion;

    LOGMSG(5, "END LAESet: " << id << " setting version\n");

};


//Get author method
std::string LAESet::getAuthor(){

    LOGMSG(5, "BEGIN LAESet: " << id << " getting author\n");
    LOGMSG(5, "END LAESet: " << id << " getting author\n");

    return author;

};


//Set author method
void LAESet::setAuthor(std::string aAuthor){

    LOGMSG(5, "BEGIN LAESet: " << id << " setting author\n");

    author = aAuthor;

    LOGMSG(5, "END LAESet: " << id << " setting author\n");

};


//Get organisation method
std::string LAESet::getOrganisation(){

    LOGMSG(5, "BEGIN LAESet: " << id << " getting organisation\n");
    LOGMSG(5, "END LAESet: " << id << " getting organisation\n");

    return organisation;

};


//Set organisation method
void LAESet::setOrganisation(std::string aOrganisation){

    LOGMSG(5, "BEGIN LAESet: " << id << " setting organisation\n");

    organisation = aOrganisation;

    LOGMSG(5, "END LAESet: " << id << " setting organisation\n");

};


//loads a previously save'd model from a file
bool LAESet::loadConfiguration(ConfigurationStore *aConfigurationStore){    

    //first thing to do is get the laeterm elements from the
    //configuration store and instantiate an laeset from this.
    
    //configure the ID of this LAE.
    setId(aConfigurationStore->rootElement.getParameterValue("id").c_str());

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aConfigurationStore->rootElement.getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             

        if((*it).name == "trigger"){
         
            LAETrigger *aLAETrigger = new LAETrigger;
            aLAETrigger->loadConfiguration(&(*it));
            aLAETrigger->parentType = OBJECT_LAESET;
            triggers.push_back(Model::LAETriggerStore.addValue(aLAETrigger));
            
        }
                                      
        if((*it).name == "requirement"){
         
            LAERequirement *aLAERequirement = new LAERequirement;
            aLAERequirement->loadConfiguration(&(*it));
            aLAERequirement->parentType = OBJECT_LAESET;
            requirements.push_back(Model::LAERequirementStore.addValue(aLAERequirement));
            
        }

        if((*it).name == "checker"){
         
            LAEChecker *aLAEChecker = new LAEChecker;
            aLAEChecker->loadConfiguration(&(*it));
            aLAEChecker->parentType = OBJECT_LAESET;
            checkers.push_back(Model::LAECheckerStore.addValue(aLAEChecker));
            
        }

        if((*it).name == "policy"){

            LAEPolicy *aLAEPolicy = new LAEPolicy;
            aLAEPolicy->loadConfiguration(&(*it));
            aLAEPolicy->parentType = OBJECT_LAESET;
            policy = Model::LAEPolicyStore.addValue(aLAEPolicy);
            
        }

        if((*it).name == "valuetypegroup"){
         
            LAEValueGroup *aLAEValueGroup = new LAEValueGroup;
            aLAEValueGroup->loadConfiguration(&(*it));
            aLAEValueGroup->parentType = OBJECT_LAESET;
            valueGroups.push_back(Model::LAEValueGroupStore.addValue(aLAEValueGroup));
            
        }

        if((*it).name == "apigroup"){
         
            APIGroup *aAPIGroup = new APIGroup;
            aAPIGroup->loadConfiguration(&(*it));
            aAPIGroup->parentType = OBJECT_LAESET;
            APIGroups.push_back(Model::APIGroupStore.addValue(aAPIGroup));
            
        }
                                      
        if((*it).name == "laeclass"){
         
            LAEClass *aLAEClass = new LAEClass;
            aLAEClass->loadConfiguration(&(*it));
            aLAEClass->parentType = OBJECT_LAESET;
            LAEClasses.push_back(Model::LAEClassStore.addValue(aLAEClass));
            
        }

        if((*it).name == "function"){
         
            LAEFunction *aLAEFunction = new LAEFunction;
            aLAEFunction->loadConfiguration(&(*it));
            aLAEFunction->parentType = OBJECT_LAESET;
            functions.push_back(Model::LAEFunctionStore.addValue(aLAEFunction));
            
        }
                                                                               
    }
    
}

bool LAESet::postConfigurationLoad(){
  
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    
    LOGMSG(6, "LAETrigger\n");
    for(it = triggers.begin(); it != triggers.end(); ++it){
        success &= (Model::LAETriggerStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LAERequirement\n");    
    for(it = requirements.begin(); it != requirements.end(); ++it){
        success &= (Model::LAERequirementStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LAEChecker\n");
    for(it = checkers.begin(); it != checkers.end(); ++it){
        success &= (Model::LAECheckerStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LAEValueGroup\n");
    for(it = valueGroups.begin(); it != valueGroups.end(); ++it){
        success &= (Model::LAEValueGroupStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LAEAPIGroup\n");
    for(it = APIGroups.begin(); it != APIGroups.end(); ++it){
        success &= (Model::APIGroupStore.getValue(*it))->postConfigurationLoad();
    }
    
    LOGMSG(6, "LAEClass\n");
    for(it = LAEClasses.begin(); it != LAEClasses.end(); ++it){
        success &= (Model::LAEClassStore.getValue(*it))->postConfigurationLoad();
    }
    
    LOGMSG(6, "LAEFunction\n");
    for(it = functions.begin(); it != functions.end(); ++it){
        success &= (Model::LAEFunctionStore.getValue(*it))->postConfigurationLoad();
    }

    loaded = success;

    return success;

    
    
}

//saves a generated model to a file
bool LAESet::saveConfiguration(ConfigurationStore *aConfigurationStore){
    
    
}




//return a string hash of the current object
std::string LAESet::hash(){

    LOGMSG(5, "BEGIN LAESet: " << id << " hash\n");
    LOGMSG(5, "END LAESet: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAESET, id);
    
};





