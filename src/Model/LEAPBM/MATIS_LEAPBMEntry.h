// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMEntry.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LEAPBMENTRY_H
#define MATIS_LEAPBMENTRY_H 1

#include "MATIS_LEAPBMMethod.h"
#include "MATIS_LEAPBMPathway.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMENTRY: class which is responsible for maintaining the entry
     * conditions which can be placed at execution points within the
     * program.
     */
    class LEAPBMEntry : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Entry condition data
        std::string id;
        entryTypeType type;

        //Methods
        handleListType methods;

        //Pathways
        handleListType pathways;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMEntry();

        //Default Destructor
        ~LEAPBMEntry();

        //Constructor
        LEAPBMEntry(std::string aId,
                    entryTypeType aType);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get action method
        entryTypeType getType();

        //Set action method
        void setType(entryTypeType aType);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        std::string getDot(int level = 1);

        //return a string hash of the current object
        std::string hash();
        
    private:

        std::list < LEAPBMPathway* > pathwayObjects;

        
    };
    
}


#endif                          // MATIS_LEAPBMENTRY_H
