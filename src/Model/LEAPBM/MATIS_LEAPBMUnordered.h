// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMUnordered.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.4 $

#ifndef MATIS_LEAPBMUNORDERED_H
#define MATIS_LEAPBMUNORDERED_H 1

#include "MATIS_LEAPBMGroup.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMUnordered: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class LEAPBMUnordered : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Program data
        std::string id;

        //Groups
        handleListType groups;
        mapGroupCompletedType groupCompletions;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMUnordered();

        //Default Destructor
        ~LEAPBMUnordered();

        //Constructor
        LEAPBMUnordered(std::string aId);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //set group completion method
        void setGroupCompletion(handleType aGroup, unsigned int aCompleted);
        
        //increment group completion method
        unsigned int incGroupCompletion(handleType aGroup);

        //get group completion method
        unsigned int getGroupCompletion(handleType aGroup);

        bool isDestinationContained(LEAPBMPathway *aPathway);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        void resetGroupCompletions();
        
        std::string getDot(int level = 1);

    private:
    };
    
}


#endif                          // MATIS_LEAPBMUNORDERED_H
