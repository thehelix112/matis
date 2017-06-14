// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEUnrestricted.h,v $
// CVS $Date: 2005/12/30 10:39:09 $
// CVS $Revision: 1.1 $

#ifndef MATIS_LAEUNRESTRICTED_H
#define MATIS_LAEUNRESTRICTED_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LAERequirement: class which is responsible for maintaining LAE requirements
     */
    class LAEUnrestricted : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Unrestricted data
        handleType afterInteraction;
        handleType beforeInteraction;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEUnrestricted();

        //Default Destructor
        ~LAEUnrestricted();

        //Constructor
        LAEUnrestricted(handleType aAfterInteraction,
                       handleType aBeforeInteraction);

        //Return a unique id composed of: parent handle, after/before interaction ids
        std::string getId();

        //Get afterInteractionId method
        handleType getAfterInteraction();

        //Set afterInteractionId method
        void setAfterInteraction(handleType aAfterInteraction);

        //Get beforeInteraction method
        handleType getBeforeInteraction();

        //Set beforeInteraction method
        void setBeforeInteraction(handleType aBeforeInteraction);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

    private:

        std::string afterInteractionId;
        std::string beforeInteractionId;

    };
    
}

#endif                          // MATIS_LAEUNRESTRICTED_H
