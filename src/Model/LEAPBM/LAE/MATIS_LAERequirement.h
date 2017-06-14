// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAERequirement.h,v $
// CVS $Date: 2005/12/30 10:39:09 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LAEREQUIREMENT_H
#define MATIS_LAEREQUIREMENT_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LAERequirement: class which is responsible for maintaining LAE requirements
     */
    class LAERequirement : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Requirement data
        std::string id;
        std::string version;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAERequirement();

        //Default Destructor
        ~LAERequirement();

        //Constructor
        LAERequirement(std::string aId,
                   std::string aVersion);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get version method
        std::string getVersion();

        //Set version method
        void setVersion(std::string aVersion);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        
        NULL_POST_CONFIGURATION;

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

    private:

    };
    
}

#endif                          // MATIS_LAEREQUIREMENT_H
