// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEFunction.h,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LAEFUNCTION_H
#define MATIS_LAEFUNCTION_H 1

#include "MATIS_Types.h"
#include "MATIS_Function.h"

namespace MATIS {

    /**
     * LAEFunction: class which is responsible for maintaining LAE functions
     */
    class LAEFunction : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Function data
        std::string id;
        std::string pluginId;
        Function *function;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEFunction();

        //Default Destructor
        ~LAEFunction();

        //Constructor
        LAEFunction(std::string aId,
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
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

    private:

    };
    
}

#endif                          // MATIS_LAEFUNCTION_H
