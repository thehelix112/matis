// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMUnordered.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.11 $

#include "MATIS_LEAPBMUnordered.h"
#include "MATIS_Model.h"
#include "MATIS_LEAPBM.h"

using namespace MATIS;

//Default Constructor
LEAPBMUnordered::LEAPBMUnordered():
    id(""){

};

//Default Destructor
LEAPBMUnordered::~LEAPBMUnordered(){
        
};

//Constructor
LEAPBMUnordered::LEAPBMUnordered(std::string aId):
    id(aId){
    
};

//Get id method
std::string LEAPBMUnordered::getId(){

    LOGMSG(5, "BEGIN LEAPBMUnordered: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMUnordered: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMUnordered::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMUnordered: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMUnordered: " << id << " setting id\n");

};

//set group completion method
void LEAPBMUnordered::setGroupCompletion(handleType aGroup, unsigned int aCompleted){
    
    groupCompletions[aGroup] = aCompleted;

}


//increment group completion method
unsigned int LEAPBMUnordered::incGroupCompletion(handleType aGroup){
    
    unsigned int retval = getGroupCompletion(aGroup);
    setGroupCompletion(aGroup, ++retval);
    return retval;
    
}


//get group completion method
unsigned int LEAPBMUnordered::getGroupCompletion(handleType aGroup){
    
    return groupCompletions[aGroup];
    
}

bool LEAPBMUnordered::isDestinationContained(LEAPBMPathway *aPathway){

    if(aPathway->destinationType == DESTINATIONTYPE_UNORDEREDGROUP){
        //unordered groups are currently not allowed to be nested??
        return false;
    }

    LEAPBMGroup *aGroup;
    
    //go through each group comparing laemethodcalls to the one in aPathway.
    for(handleListType::iterator it = groups.begin(); it != groups.end(); ++it){

        aGroup = Model::LEAPBMGroupStore.getValue(*it);
        for(handleListType::iterator iq = aGroup->LAEInteractions.begin(); 
            iq != aGroup->LAEInteractions.end(); 
            ++iq){
     
            LOGMSG(6, "Group  interaction  handle: " << *iq << "\n");
            LOGMSG(6, "Pathway interaction handle: " << aPathway->destination << "\n");
            if(*iq == aPathway->destination)
                return true;
       
        }
        
    }

    return false;
    
}



//Load the configuration
bool LEAPBMUnordered::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the ID of this LEAPBM.
    setId(aElement->getParameterValue("id").c_str());

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
                                                                               
        if((*it).name == "group"){
         
            LEAPBMGroup *aGroup = new LEAPBMGroup;
            aGroup->loadConfiguration(&(*it));
            aGroup->parentType = OBJECT_LEAPBMUNORDERED;
            groups.push_back(Model::LEAPBMGroupStore.addValue(aGroup));
            
        }
        
    }
    

}

bool LEAPBMUnordered::postConfigurationLoad(){
    
    bool success = true;

    resetGroupCompletions();

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = groups.begin(); it != groups.end(); ++it){
        (Model::LEAPBMGroupStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMGroupStore.getValue(*it))->postConfigurationLoad();
    }

    return success;
    
}


//Save the configuration
bool LEAPBMUnordered::saveConfiguration(ConfigurationElement *aElement){    
    
}


//return a string hash of the current object
std::string LEAPBMUnordered::hash(){

    LOGMSG(5, "BEGIN LEAPBMUnordered: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMUnordered: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMUNORDERED, id);
    
};




void LEAPBMUnordered::resetGroupCompletions(){

    for(handleListType::iterator it = groups.begin(); it != groups.end(); ++it){
        
        setGroupCompletion(*it, 0);
        
    }
    
}


std::string LEAPBMUnordered::getDot(int level){

    LEAPBM::drawingUnordered = handle;

    std::string dotString;

    for(int i = 0; i < level; ++i)
        dotString += "  ";

    //dotString += "subgraph Unord_" + id + " { \n";

    //for(int i = 0; i < level; ++i)
    //    dotString += "  ";

    //draw start node from which all other stem
    dotString += "  Unord_" + id + " [label=\"\",shape=circle,style=filled];\n";

    handleListType::iterator it;
    for(it = groups.begin(); it != groups.end(); ++it){
        dotString += (Model::LEAPBMGroupStore.getValue(*it))->getDot(level+1);
    }

    //if(!leapbmUnordered->isDestinationContained(aPathway)){

    //for(int i = 0; i < level; ++i)
    //    dotString += "  ";

    //dotString += "}\n";

    LEAPBM::drawingUnordered = 0;

    return dotString;
    
}

    
