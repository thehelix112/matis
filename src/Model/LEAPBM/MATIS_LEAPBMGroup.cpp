// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMGroup.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.10 $

#include "MATIS_LEAPBMGroup.h"
#include "MATIS_Model.h"
#include "MATIS_LEAPBM.h"
#include "MATIS_LEAPBMGroupIterator.h"

using namespace MATIS;

//Default Constructor
LEAPBMGroup::LEAPBMGroup():
    id(""),
    entry(0),
    requiredMin(0),
    requiredMax(0),
    entryType(DESTINATIONTYPE_NULL),
    maximumInclusive(false),
    minimumInclusive(false),
    maximumInfinite(false){

    iter = new LEAPBMGroupIterator;
    
};

//Default Destructor
LEAPBMGroup::~LEAPBMGroup(){

    delete iter;
    
};

//Constructor
LEAPBMGroup::LEAPBMGroup(std::string aId,
                         int aRequiredMin,
                         int aRequiredMax,
                         handleType aEntry,
                         pathwayDestinationTypeType aEntryType):
    id(aId),
    requiredMin(aRequiredMin),
    requiredMax(aRequiredMax),
    entry(aEntry),
    entryType(aEntryType){
    
};

//Get id method
std::string LEAPBMGroup::getId(){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBMGroup: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBMGroup::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBMGroup: " << id << " setting id\n");

};

//Get requiredMin method
int LEAPBMGroup::getRequiredMin(){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " getting requiredMin\n");
    LOGMSG(5, "END LEAPBMGroup: " << id << " getting requiredMin\n");

    return requiredMin;

};
//Set requiredMin method
void LEAPBMGroup::setRequiredMin(int aRequiredMin){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " setting requiredMin\n");

    requiredMin = aRequiredMin;

    LOGMSG(5, "END LEAPBMGroup: " << id << " setting requiredMin\n");

};
//Get requiredMax method
int LEAPBMGroup::getRequiredMax(){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " getting requiredMax\n");
    LOGMSG(5, "END LEAPBMGroup: " << id << " getting requiredMax\n");

    return requiredMax;

};
//Set requiredMax method
void LEAPBMGroup::setRequiredMax(int aRequiredMax){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " setting requiredMax\n");

    requiredMax = aRequiredMax;

    LOGMSG(5, "END LEAPBMGroup: " << id << " setting requiredMax\n");

};


//Get entry method
handleType LEAPBMGroup::getEntry(){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " getting entry\n");
    LOGMSG(5, "END LEAPBMGroup: " << id << " getting entry\n");

    return entry;

};


//Set entry method
void LEAPBMGroup::setEntry(handleType aEntry){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " setting entry\n");

    entry = aEntry;

    LOGMSG(5, "END LEAPBMGroup: " << id << " setting entry\n");

};

//Get entryType method
pathwayDestinationTypeType LEAPBMGroup::getEntryType(){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " getting entryType\n");
    LOGMSG(5, "END LEAPBMGroup: " << id << " getting entryType\n");

    return entryType;

};


//Set entryType method
void LEAPBMGroup::setEntryType(pathwayDestinationTypeType aEntryType){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " setting entryType\n");

    entryType = aEntryType;

    LOGMSG(5, "END LEAPBMGroup: " << id << " setting entryType\n");

};


//Load the configuration
bool LEAPBMGroup::loadConfiguration(ConfigurationElement *aElement){
   
    //configure the ID of this
    setId(aElement->getParameterValue("id").c_str());
    setEntryType(Types::stringToDestinationTypeType(aElement->getParameterValue("entrytype").c_str()));
    std::string requiredString = aElement->getParameterValue("required").c_str();

    if(!parseRequired(requiredString)){
        LOGWRN("Required string incorrectly parsed.\n");
    }

    entryId = aElement->getParameterValue("entry_id").c_str();

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){

        if((*it).name == "laeinteraction"){
         
            LEAPBMLAEInteraction *aLAEInteraction = new LEAPBMLAEInteraction;
            aLAEInteraction->loadConfiguration(&(*it));
            aLAEInteraction->parentType = OBJECT_LEAPBMGROUP;
            LAEInteractions.push_back(Model::LEAPBMLAEInteractionStore.addValue(aLAEInteraction));
            
        }
        
    }
    

}

bool LEAPBMGroup::postConfigurationLoad(){
    
    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = LAEInteractions.begin(); it != LAEInteractions.end(); ++it){
        (Model::LEAPBMLAEInteractionStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LEAPBMLAEInteractionStore.getValue(*it))->postConfigurationLoad();
    }

    iter->parentGroup = handle;

    //do this afterwards so that child LAEInteractions will have been instantiated
    handleType handle;
    if(LEAPBM::getLAEInteraction(entryId, &handle)){
        setEntry(handle);
        success &= true;
    } else {
        LOGWRN("Reference made to unknown LAE Method Call: " << entryId << "\n");
        success &= false;
    }

    return success;

}

bool LEAPBMGroup::parseRequired(std::string aRequiredString){

    boost::char_separator < char > sep("-", "[()]");
    tokeniserType tokens(aRequiredString, sep);
    tokeniserType::iterator it = tokens.begin();

    unsigned int count = 0;
    for(; it != tokens.end(); ++it){
        ++count;
    }
    
    if(count < 4){
        LOGWRN("Invalid required specified: " << aRequiredString << "\n");
        return false;
    }    
    
    //tokens go, lower range boundary then value, upper range value then boundary
    it = tokens.begin();
    minimumInclusive = ((*it) == "(");
    
    ++it;
    if(*it == "INF"){
        LOGWRN("Lower value specified as infinite. Invalid.\n");
        return false;
    } else {
        requiredMin = Types::stringToInt(*it);
    }
    
    ++it;
    if(*it == "INF"){
        maximumInfinite = true;
    } else {
        requiredMax = Types::stringToInt(*it);
    }

    ++it;
    maximumInclusive = ((*it) == ")");

    if((++it) != tokens.end()){
   
        LOGMSG(4, "Spurious tokens in model value: ");

        for(;it != tokens.end(); ++it){
            
            LOGMSG(4, (*it));
            
        }

        LOGMSG(4, "  ignored.\n");
        
    }

    return true;
    
}



//Save the configuration
bool LEAPBMGroup::saveConfiguration(ConfigurationElement *aElement){    
    
}

//return a string hash of the current object
std::string LEAPBMGroup::hash(){

    LOGMSG(5, "BEGIN LEAPBMGroup: " << id << " hash\n");
    LOGMSG(5, "END LEAPBMGroup: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LEAPBMGROUP, id);
    
};






std::string LEAPBMGroup::getDot(int level){

    //default line from start of unorderd subject
    std::string dotString;

    for(int i = 0; i < level; ++i)
        dotString += "  ";

    LEAPBMUnordered *aUnordered = Model::LEAPBMUnorderedStore.getValue(parentHandle);

    handleListType::iterator it;
    for(it = LAEInteractions.begin(); it != LAEInteractions.end(); ++it){
        dotString += "Unord_" + aUnordered->getId() + " -> Inter_" + (Model::LEAPBMLAEInteractionStore.getValue(*it))->getId();
        dotString += ";\n";
        dotString += (Model::LEAPBMLAEInteractionStore.getValue(*it))->getDot(level);

    }

    return dotString;
    

    
}
