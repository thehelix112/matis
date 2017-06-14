// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIVariable.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_APIVARIABLE_H
#define MATIS_APIVARIABLE_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * APIVariable: class which is responsible for maintaining referencing to library API variables
     */
    class APIVariable : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Method data
        std::string id;
        std::string name;
        APIValueType type;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        APIVariable();

        //Default Destructor
        ~APIVariable();

        //Constructor
        APIVariable(std::string aId,
                    APIValueType aType,
                    std::string aName);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get type method
        APIValueType getType();

        //Set type method
        void setType(APIValueType aType);

        //Get name method
        std::string getName();

        //Set name method
        void setName(std::string aName);

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

#endif                          // MATIS_APIVARIABLE_H
