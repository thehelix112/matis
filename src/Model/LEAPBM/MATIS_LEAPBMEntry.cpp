// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMEntry.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.9 $

#include "MATIS_LEAPBMEntry.h"
#include "MATIS_Model.h"

using namespace MATIS;

//Default Constructor
LEAPBMEntry::LEAPBMEntry():
    id(""),
    type(ENTRYTYPE_NULL){
    
};

//Default Destructor
LEAPBMEntry::~LEAPBMEntry(){
    
};

//Constructor
LEAPBMEntry::LEAPBMEntry(std::string aId,
                       entryTypeType aType):
    id(aId),
    type(aType){

    
};

//Get id method
std::string LEAPBMEntry::getId(){

    LOGMSG(5, "BEGIN LEAPBMEntry: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMEntry: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMEntry::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMEntry: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMEntry: " << id << " setting id\n");

};

//Get type method
entryTypeType LEAPBMEntry::getType(){

    LOGMSG(5, "BEGIN LEAPBMEntry: " << id << " getting type\n");
    LOGMSG(5, "END LEAPBMEntry: " << id << " getting type\n");

    return type;

};

//Set type method
void LEAPBMEntry::setType(entryTypeType aType){

    LOGMSG(5, "BEGIN LEAPBMEntry: " << id << " setting type\n");

    type = aType;

    LOGMSG(5, "END LEAPBMEntry: " << id << " setting type\n");

};

//Load the configuration
bool LEAPBMEntry::loadConfiguration(ConfigurationElement *aElement){

    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());
    setType(Types::stringToEntryTypeType(aElement->getParameterValue("type").c_str()));

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
                                                                               
        if((*it).name == "method"){
         
            LEAPBMMethod *aMethod = new LEAPBMMethod;
            aMethod->loadConfiguration(&(*it));
            aMethod->parentType = OBJECT_LEAPBMENTRY;
            methods.push_back(Model::LEAPBMMethodStore.addValue(aMethod));
            
        }

        if((*it).name == "pathway"){
         
            LEAPBMPathway *aPathway = new LEAPBMPathway;
            aPathway->loadConfiguration(&(*it));
            aPathway->parentType = OBJECT_LEAPBMENTRY;
            pathwayObjects.push_back(aPathway);
            
        }
        
    }
    

}

bool LEAPBMEntry::postConfigurationLoad(){
    
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = methods.begin(); it != methods.end(); ++it){
        (Model::LEAPBMMethodStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMMethodStore.getValue(*it))->postConfigurationLoad();
    }

    //delay adding of a pathway until here because its hash depends on its parent's handle
    for(std::list < LEAPBMPathway* >::iterator it = pathwayObjects.begin();
        it != pathwayObjects.end();
        ++it){

        (*it)->parentHandle = handle;
        success &= (*it)->postConfigurationLoad();
        pathways.push_back(Model::LEAPBMPathwayStore.addValue(*it));
    }    

    return success;
    
}


//Save the configuration
bool LEAPBMEntry::saveConfiguration(ConfigurationElement *aElement){    
    
}

//return a string hash of the current object
std::string LEAPBMEntry::hash(){

    LOGMSG(5, "BEGIN LEAPBMEntry: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMEntry: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMENTRY, id);
    
};


std::string LEAPBMEntry::getDot(int level){

    handleListType::iterator it;

    std::string dotString;

    for(int i = 0; i < level; ++i)
        dotString += "  ";

    dotString += "\"" + id + "\" [label=\".\",shape=circle,style=filled,fillcolor=black];\n";

    for(it = pathways.begin(); it != pathways.end(); ++it){
        LEAPBMPathway *aPathway = Model::LEAPBMPathwayStore.getValue(*it);
        dotString += aPathway->getDot(level);
    }

    return dotString;

};





