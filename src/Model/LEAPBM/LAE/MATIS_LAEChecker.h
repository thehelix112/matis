// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEChecker.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_LAECHECKER_H
#define MATIS_LAECHECKER_H 1

#include "MATIS_Types.h"
#include "MATIS_Checker.h"

namespace MATIS {

    /**
     * LAEChecker: class which is responsible for maintaining LAE checkers
     */
    class LAEChecker : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Checker data
        std::string id;
        std::string pluginId;
        Checker *checker;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEChecker();

        //Default Destructor
        ~LAEChecker();

        //Constructor
        LAEChecker(std::string aId,
                   std::string aPluginId);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get pluginId method
        std::string getPluginId();

        //Set pluginId method
        void setPluginId(std::string aPluginId);

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

#endif                          // MATIS_LAECHECKER_H
