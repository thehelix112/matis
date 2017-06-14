// Copyright 2004 DavdestinationId Andrews
// Authors: DavdestinationId Andrews
// CVS $RCSfile: MATIS_LEAPBMPathway.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.7 $

#include "MATIS_LEAPBMPathway.h"
#include "MATIS_Model.h"
#include "MATIS_LEAPBM.h"

using namespace MATIS;

//Default Constructor
LEAPBMPathway::LEAPBMPathway():
    destination(0),
    destinationType(DESTINATIONTYPE_NULL){
    
};

//Default Destructor
LEAPBMPathway::~LEAPBMPathway(){
    
};

//Constructor
LEAPBMPathway::LEAPBMPathway(handleType aDestination,
                             pathwayDestinationTypeType aDestinationType):
    destination(aDestination),
    destinationType(aDestinationType){

    
};

//Get destination method
handleType LEAPBMPathway::getDestination(){

    LOGMSG(5, "BEGIN LEAPBMPathway: " << destination << " getting destination\n");
    LOGMSG(5, "END LEAPBMPathway: " << destination << " getting destination\n");

    return destination;

};


//Set destination method
void LEAPBMPathway::setDestination(handleType aDestination){

    LOGMSG(5, "BEGIN LEAPBMPathway: " << destination << " setting destination\n");

    destination = aDestination;

    LOGMSG(5, "END LEAPBMPathway: " << destination << " setting destination\n");

};

//Get destinationType method
pathwayDestinationTypeType LEAPBMPathway::getDestinationType(){

    LOGMSG(5, "BEGIN LEAPBMPathway: " << destination << " getting destinationType\n");
    LOGMSG(5, "END LEAPBMPathway: " << destination << " getting destinationType\n");

    return destinationType;

};

//Set destinationType method
void LEAPBMPathway::setDestinationType(pathwayDestinationTypeType aDestinationType){

    LOGMSG(5, "BEGIN LEAPBMPathway: " << destination << " setting destinationType\n");

    destinationType = aDestinationType;

    LOGMSG(5, "END LEAPBMPathway: " << destination << " setting destinationType\n");

};

//Load the configuration
bool LEAPBMPathway::loadConfiguration(ConfigurationElement *aElement){
 
    //configure the ID of this
    setDestinationType(Types::stringToDestinationTypeType(aElement->getParameterValue("destinationtype").c_str()));
  
    //get the destination handle from the id
    destinationId = aElement->getParameterValue("destination_id").c_str();
    
}


bool LEAPBMPathway::postConfigurationLoad(){
    
    handleType handle;
    bool success = true;
    
    switch(destinationType){
        
    case DESTINATIONTYPE_LAEINTERACTION:
        success &= LEAPBM::getLAEInteraction(destinationId, &handle);
        break;
    case DESTINATIONTYPE_UNORDEREDGROUP:
        success &= LEAPBM::getUnordered(destinationId, &handle);
        break;
    default:
        break;
    }

    if(success)
        setDestination(handle);
    else
        LOGWRN("Reference made to unknown LAE Destination: " << destinationId << "\n");

    return success;

}

//Save the configuration
bool LEAPBMPathway::saveConfiguration(ConfigurationElement *aElement){    
    
}

//return a string hash of the current object
std::string LEAPBMPathway::hash(){

    LOGMSG(5, "BEGIN LEAPBMPathway: " << destinationId << " hash\n");
    LOGMSG(5, "END LEAPBMPathway: " << destinationId << " hash\n");

    std::string fullhan;
    
    fullhan += Types::unsignedLongToString(parentHandle);
    char buffer[4] = {0,0,0,0};
    *(objectType *) buffer = parentType;
    fullhan += std::string(buffer,4);
    fullhan += destinationId;
    fullhan += Types::destinationTypeTypeToString(destinationType);

    LOGMSG(6, "!!!hash of pathway: " << Hashable::hashObject(OBJECT_LEAPBMPATHWAY, fullhan) << "\n");
    
    return Hashable::hashObject(OBJECT_LEAPBMPATHWAY, fullhan);
    
};


std::string LEAPBMPathway::getDot(int level){

    std::string dotString;

    for(int i = 0; i < level; ++i)
        dotString += "  ";

    //get the parent id and use that as originator
    switch(parentType){
        
    case OBJECT_LEAPBMENTRY:
        dotString += "\"" + Model::LEAPBMEntryStore.getValue(parentHandle)->getId() + "\"";
        break;
    case OBJECT_LEAPBMEXCEPTION:
        //get the parent of the parent
        dotString += "Inter_" + Model::LEAPBMLAEInteractionStore.getValue(
            Model::LEAPBMExceptionStore.getValue(parentHandle)->parentHandle
            )->getId();
        break;
    case OBJECT_LEAPBMLAEINTERACTION:
        dotString += "Inter_" + Model::LEAPBMLAEInteractionStore.getValue(parentHandle)->getId();
        break;
    default:
        break;
    }
    
    dotString += " -> ";

    switch(destinationType){
        
    case DESTINATIONTYPE_LAEINTERACTION:
        dotString += " Inter_";
        break;
    case DESTINATIONTYPE_UNORDEREDGROUP:
        dotString += " Unord_";
        break;
    default:
        break;
    }

    dotString += destinationId;

    if(LEAPBM::drawingUnordered != 0){
    
        LEAPBMUnordered *aUnordered = Model::LEAPBMUnorderedStore.getValue(LEAPBM::drawingUnordered);
        if(!aUnordered->isDestinationContained(this)){

            //this pathway is not within the current unordered so make the lines dashed
            dotString += " [style=dashed]";
   
        }
        
    }    
    
    dotString += ";\n";

    return dotString;

};




