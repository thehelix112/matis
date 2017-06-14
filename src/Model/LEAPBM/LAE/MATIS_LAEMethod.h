// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethod.h,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.8 $

#ifndef MATIS_LAEMETHOD_H
#define MATIS_LAEMETHOD_H 1

#include "MATIS_Types.h"
#include "MATIS_LAEMethodStage.h"
#include "MATIS_Action.h"
#include "MATIS_LAEUnrestricted.h"

namespace MATIS {

    /**
     * LAEMethod: class which is responsible for maintaining LAE methods
     */
    class LAEMethod : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Method data
        std::string id;
        LAEMethodFlagType flag;
        int numStages;
        bool isUnrestricted;

        //stages graph
        graphLAEMethodStage stages;

        //map from stage id to vertex
        mapStageIdVertexType mapStageIdVertex;
        mapEdgeApiExceptionsType mapEdgeApiExceptions;
        
        //store 
        handleListType methodStages;
        handleListType unrestricteds;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEMethod();

        //Default Destructor
        ~LAEMethod();

        //Constructor
        LAEMethod(std::string aId,
                  int aStages);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get number of stages method
        int getNumStages();

        //Add a stage
        void addStage(handleType aStageHandle, std::string aStageId);

        //Add a step
        void addStep(std::string fromStageId, 
                     std::string toStageId,
                     handleType apiException = 0);

        //Delete a stage
        void removeStage(std::string aStageId);

        //Get flag method
        LAEMethodFlagType getFlag();

        //Set flag method
        void setFlag(LAEMethodFlagType aType);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        bool operator +(Action* aAction);


    private:
        
        //this is only temporarily used to allow for seperate `start'
        //and `stage' elements in the xml
        stringListType starts;

        LAEMethodStage *startStage;

        vertexLAEMethodStage currentVertex;
        edgeLAEMethodStage currentEdge;
        bool inEdge;

        bool checkVertex(vertexLAEMethodStage aVertex, 
                         Action *aAction,
                         bool *isEnd);

        //propertymap for the method stage handle stored in graph verticies
        propertyMapLAEMethodStage handles;

        //special treatment of LAEUnrestricted elements as part of their
        //hash is the parent LAEMethod so we cannot add them to the model(hash them)
        //until all loadConfiguration()s have occurred
        std::list < LAEUnrestricted* > unrestrictedObjects;

    };
    
}

#endif                          // MATIS_LAEMETHOD_H
