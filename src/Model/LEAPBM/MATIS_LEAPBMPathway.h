// Copyright 2004 DavdestinationId Andrews
// Authors: DavdestinationId Andrews
// CVS $RCSfile: MATIS_LEAPBMPathway.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.4 $

#ifndef MATIS_LEAPBMPATHWAY_H
#define MATIS_LEAPBMPATHWAY_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMPATHWAY: class which is responsible for maintaining the pathway
     * conditions which can be placed at execution points within the
     * program.
     */
    class LEAPBMPathway : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Pathway condition data
        handleType destination;
        pathwayDestinationTypeType destinationType;

        //required for the special hashing of pathway given its idless nature
        std::string destinationId;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMPathway();

        //Default Destructor
        ~LEAPBMPathway();

        //Constructor
        LEAPBMPathway(handleType aDestination,
                    pathwayDestinationTypeType aDestinationType);

        //Get destination method
        handleType getDestination();

        //Set destination method
        void setDestination(handleType aDestination);

        //Get action method
        pathwayDestinationTypeType getDestinationType();

        //Set action method
        void setDestinationType(pathwayDestinationTypeType aDestinationType);        

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);

        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        std::string getDot(int level = 1);
        
    private:

    };
    
}


#endif                          // MATIS_LEAPBMPATHWAY_H
