// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethod.cpp,v $
// CVS $Date: 2006/01/05 14:08:39 $
// CVS $Revision: 1.11 $

#include "MATIS_LAEMethod.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"
#include "MATIS_Action_RTI_13NG.h"
#include "MATIS_TypeConversion_RTI_13NG.h"
#include "MATIS_LEAPBM.h"

using namespace MATIS;

//Default Constructor
LAEMethod::LAEMethod():
    id(""),
    numStages(0),
    inEdge(false){

    startStage = new LAEMethodStage("__START", 0, 0, STAGE_NULL, false);
    stages = graphLAEMethodStage(MAX_LAEMETHODSTAGES);
    
};

//Default Destructor
LAEMethod::~LAEMethod(){
     
};

//Constructor
LAEMethod::LAEMethod(std::string aId,
                     int aStages):
    id(aId),
    numStages(aStages),
    inEdge(false){
    
};

//Get id method
std::string LAEMethod::getId(){

    LOGMSG(5, "BEGIN LAEMethod: " << id << " getting id\n");
    LOGMSG(5, "END LAEMethod: " << id << " getting id\n");

    return id;

};


//Set id method
void LAEMethod::setId(std::string aId){

    LOGMSG(5, "BEGIN LAEMethod: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAEMethod: " << id << " setting id\n");

};

//Get number of stages method
int LAEMethod::getNumStages(){

    LOGMSG(5, "BEGIN LAEMethod: " << id << " getting number of expected stages\n");
    LOGMSG(5, "END LAEMethod: " << id << " getting number of expected stages\n");

    return numStages;

};

//Add a stage
void LAEMethod::addStage(handleType aStageHandle, std::string aStageId){    

    LOGMSG(5, "BEGIN LAEMethod: " << id << " addStage: " << aStageId << "\n");

    //add the stage to the graph
    /*stageProperty aProperty = stageProperty(aStage->id, 
                                            stageAPIMethodProperty(aStage->APIMethod, 
                                            stageStartProperty(aStage->start)));*/
    //stageProperty aProperty = stageProperty(aStageId);

    mapStageIdVertex[aStageId] = add_vertex(aStageHandle, stages);

    LOGMSG(5, "END LAEMethod: " << id << " addStage: " << aStageId << "\n");
    
};

//Delete a stage
void LAEMethod::removeStage(std::string stageId){
  
    LOGMSG(5, "BEGIN LAEMethod: " << id << " removeStage: " << stageId << "\n");

    clear_vertex(mapStageIdVertex[stageId], stages);
    remove_vertex(mapStageIdVertex[stageId], stages);

    LOGMSG(5, "END LAEMethod: " << id << " removeStage: " << stageId << "\n");
    
};

void LAEMethod::addStep(std::string fromStageId, std::string toStageId, handleType apiException){
    
    LOGMSG(5, "BEGIN LAEMethod: " << id << " addStep: " << fromStageId << "->" << toStageId << "\n");

    //check that the stages exist in the map
    if(mapStageIdVertex.find(fromStageId) == mapStageIdVertex.end() || 
       mapStageIdVertex.find(toStageId) == mapStageIdVertex.end()){
        LOGWRN("Requested to join an LAEMethod that hasn't been created yet.\n");
    }

    bool inserted = false;
    edgeLAEMethodStage retval;
    tie(retval, inserted) = add_edge(mapStageIdVertex[fromStageId], 
                                     mapStageIdVertex[toStageId], 
                                     stages);

    //assign a value to the edge indicating its apiException
    if(inserted){   
        
        mapEdgeApiExceptions[retval] = apiException;
        LOGMSG(5, "Associated APIException: " << apiException << " with edge in LAEMethod: " << id << "\n");
        
    }

    LOGMSG(5, "END LAEMethod: " << id << " addStep: " << fromStageId << "->" << toStageId << "\n");
    
};

//Get flag method
LAEMethodFlagType LAEMethod::getFlag(){
    
    LOGMSG(5, "BEGIN LAEMethod: " << id << " getting flag\n");
    LOGMSG(5, "END LAEMethod: " << id << " getting flag\n");

    return flag;

};

//Set flag method
void LAEMethod::setFlag(LAEMethodFlagType aFlag){
    
    LOGMSG(5, "BEGIN LAEMethod: " << id << " setting flag\n");

    flag = aFlag;

    LOGMSG(5, "END LAEMethod: " << id << " setting flag\n");

};


//Load the configuration
bool LAEMethod::loadConfiguration(ConfigurationElement *aElement){
 
    isUnrestricted = false;

    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setFlag(Types::stringToLAEMethodFlagType(aElement->getParameterValue("flag").c_str()));
    
    if(cistring(aElement->getParameterValue("unrestricted").c_str()) == "true"){
        isUnrestricted = true;
    }

    //There is a standard single start point (which isn't `really'
    //part of the graph) but it allows us a logical place for an
    //iterator (the equivlant of zero).  add the stage to the graph
    handleType startHandle = Model::LAEMethodStageStore.addValue(startStage);    
    addStage(startHandle, startStage->id);

    //set the iterator to the first element in the stage
    currentVertex = mapStageIdVertex[startStage->id];

    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aElement->getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
             
        if((*it).name == "start"){
         
            starts.push_back((*it).getParameterValue("stage_id").c_str());

        }

        if((*it).name == "stage"){
            
            LAEMethodStage *aLAEMethodStage = new LAEMethodStage;
            aLAEMethodStage->loadConfiguration(&(*it));
            aLAEMethodStage->parentType = OBJECT_LAEMETHOD;
            methodStages.push_back(Model::LAEMethodStageStore.addValue(aLAEMethodStage));
            addStage(methodStages.back(), aLAEMethodStage->id);
            
        }

        if((*it).name == "unrestricted"){
            
            LAEUnrestricted *aLAEUnrestricted = new LAEUnrestricted;
            aLAEUnrestricted->loadConfiguration(&(*it));
            aLAEUnrestricted->parentType = OBJECT_LAEMETHOD;
            unrestrictedObjects.push_back(aLAEUnrestricted);
            
        }

        
    }

   
}



bool LAEMethod::postConfigurationLoad(){

    bool success = true;

    if(isUnrestricted){   
        ((LEAPBM*)Model::model)->unrestrictedLAEMethods.push_back(handle);
    }

    //deferred addition of the LAEUnrestricteds to the model so
    //that the parentHandle's can be set as it is a crucial
    //part of the hash(id) of the Unrestricted.
    for(std::list < LAEUnrestricted* >::iterator it = unrestrictedObjects.begin();
        it != unrestrictedObjects.end();
        ++it){

        (*it)->parentHandle = handle;
        success &= (*it)->postConfigurationLoad();
        unrestricteds.push_back(Model::LAEUnrestrictedStore.addValue(*it));
            
    }

    //go through and finish all the links between things
    handleListType::iterator it;
    for(it = methodStages.begin(); it != methodStages.end(); ++it){
        (Model::LAEMethodStageStore.getValue(*it))->parentHandle = handle;
        success &= (Model::LAEMethodStageStore.getValue(*it))->postConfigurationLoad();
    }

    //once we have processed all the start and stage elements we can
    //go through the list of starts and set the boolean value on the
    //stage accordingly
    for(stringListType::iterator it = starts.begin(); it != starts.end(); ++it){
     
        LOGMSG(5, "Fetching LAEMethodStage start: " << (*it) << "...");

        //get the LAEMethodStage from the id
        LAEMethodStage *aStage;
        if(LAESet::getMethodStage((*it).c_str(), &aStage)){
            success &= true;
            LOGMSG(5, " DONE.\n");
            LOGMSG(5, aStage << "\n");
            aStage->setStart(true);
            addStep(startStage->id, aStage->id);
        } else {
            success &= false;
            LOGMSG(5, " FAILED\n");
        }
            
    }

    //from the information, create the graph accordingly. for each
    //point we need to know what other point preceeded it
    
    //go through each point, then for each point go through all the
    //points looking for ones that have it as their next
    for(handleListType::iterator it = methodStages.begin(); it != methodStages.end(); ++it){

        LAEMethodStage *aStage = Model::LAEMethodStageStore.getValue(*it);

        /* scan the progressions from each stage to the next */
        for(handleListType::iterator iq = aStage->progressions.begin();
            iq != aStage->progressions.end();
            ++iq){

            LAEMethodStageProgression *aMethodStageProgression = 
                Model::LAEMethodStageProgressionStore.getValue(*iq);

            LAEMethodStage *bStage = 
                Model::LAEMethodStageStore.getValue(aMethodStageProgression->stageLAEMethod);

            LOGMSG(5, "LAEMethod: " << id << " Adding step from: " << aStage->id << " to: " << (*iq) << "\n");
            addStep(aStage->id, bStage->id, aMethodStageProgression->apiException);
            
        }
        
    }

    return success;
    
}



//Save the configuration
bool LAEMethod::saveConfiguration(ConfigurationElement *aElement){
    
    
}


/*
template <class graphLAEMethodStage> struct exercise_vertex {
    //...
    exercise_vertex(graphLAEMethodStage& g_) : g(g_) {}
    //...
    graphLAEMethodStage& g;

    void operator()(const vertexLAEMethodStage& v) const
    {
        typedef graph_traits<graphLAEMethodStage> GraphTraits;
        typename property_map<graphLAEMethodStage, vertexHandleT>::type 
            index = get(vertexHandleT(), g);
        std::cout << "vertex: " << index[v];
        
        std::cout << "out-edges: ";
        typename GraphTraits::out_edge_iterator out_i, out_end;
        typename GraphTraits::edge_descriptor e;
        for (tie(out_i, out_end) = out_edges(v, g); 
             out_i != out_end; ++out_i) {
            e = *out_i;
            vertexLAEMethodStage src = source(e, g), targ = target(e, g);
            std::cout << "(" << index[src] << "," 
                      << index[targ] << ") ";
        }
        std::cout << std::endl;
        //...
    }
    //...
    };*/


//This function checks the program step represented by the action context
//parameter to the current location within the LAEMethods definition.
//Returns whether this step is legal
bool LAEMethod::operator +(Action *aAction){

    LOGMSG(4, "   about to check this specific action context\n");

    //print out the graph
    /*std::for_each(vertices(stages).first, vertices(stages).second,
      exercise_vertex<graphLAEMethodStage>(stages));*/
    Action::ActionContextType nextContext = aAction->actionContext;

    handles = get(vertexHandleT(), stages);
    outEdgeIteratorLAEMethodStage outIt, outEnd;
    vertexLAEMethodStage targetVertex;
    edgeLAEMethodStage edge;

    bool targetMatches = false;
    bool isEnd = false;

    //decide whether we are currently at an edge (for an exception)
    //or a vertex (if not)
    if(inEdge){

        LOGMSG(4, "     current in an edge (exception)\n");

        //edge
        targetVertex = target(currentEdge, stages);
        if(checkVertex(targetVertex, aAction, &isEnd)){
            targetMatches = true;
        }
        
    } else {

        LOGMSG(4, "     current in a vertex\n");

        //vertex
        for(tie(outIt, outEnd) = out_edges(currentVertex, stages);
            outIt != outEnd; ++outIt){

            LOGMSG(4, "     edge is: ");

            edge = *outIt;

            //differentiate between normal and exceptional edges?
            if(mapEdgeApiExceptions[edge] > 0){
         
                LOGMSG(4, "exception.\n");

                //exceptional path
                //context must be EXCEPTION?
                if(aAction->actionContext == Action::EXCEPTION){

                    //compare the exceptions
                    RTI::Exception *actionException = 
                        TypeConversion_RTI_13NG::getMeta_Exception(*aAction);
                    APIException *modelException = 
                        Model::APIExceptionStore.getValue(mapEdgeApiExceptions[edge]);
    
                    if(modelException->getName() == 
                       Action_RTI_13NG::rtiExceptionToString(actionException)){
                 
                        currentEdge = edge;
                        inEdge = true;
                        return true;
                        
                    }

                }
            
            } else {

                LOGMSG(4, "normal.\n");

                targetVertex = target(edge, stages);
                //sourceVertex = source(edge, stages),

                if(checkVertex(targetVertex, aAction, &isEnd)){
                    targetMatches = true;
                    continue;
                }   
        
            }
        
        }
        
    }

    if(targetMatches){    
        
        if(isEnd){
            //set the currentVertex back to the start
            currentVertex = mapStageIdVertex[startStage->id];
        } else {    
            //set the current vertex equal to the target here and return true
            currentVertex = targetVertex;
        }
        
        //reset the current edge to zero as we have moved on.
        inEdge = false;
        return true;
        
    }

    return false;
    
}


bool LAEMethod::checkVertex(vertexLAEMethodStage aVertex, Action *aAction, bool *isEnd){

    //get the LAEMethodStage handle from the map;
    handleType nextStageHandle = handles[aVertex];
    
    //get the stage object from the target of the edge
    LAEMethodStage* nextStage = Model::LAEMethodStageStore.getValue(nextStageHandle);
    if(nextStage == NULL){

        LOGWRN("Invalid next Method Stage requested: " << nextStageHandle << "\n");
        return false;

    }

    if(nextStage->getFlag() == STAGE_END){
        //this is the last LAEMethodStage in this LAEMethod
        *isEnd = true;
    }
    
    //get the APIMethod of this stage and compare its context with the one supplied
    APIMethod *nextAPIMethod = Model::APIMethodStore.getValue(nextStage->APIMethod);

    LOGMSG(4, "       action Context: " << 
           Action_RTI_13NG::getContextAsString(aAction->actionContext) << "\n");
    LOGMSG(4, "       vertex Context: " << nextAPIMethod->getContextId() << "\n");
    
    if(Action_RTI_13NG::getContextAsString(aAction->actionContext) == 
       nextAPIMethod->getContextId()){
        
        return true;

    }

    return false;
    
}



//return a string hash of the current object
std::string LAEMethod::hash(){

    LOGMSG(5, "BEGIN LAEMethod: " << id << " hash\n");
    LOGMSG(5, "END LAEMethod: " << id << " hash\n");
    
    return Hashable::hashObject(OBJECT_LAEMETHOD, id);
    
};
