// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIParameter.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_APIPARAMETER_H
#define MATIS_APIPARAMETER_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * APIParameter: class which is responsible for maintaining referencing to library API parameters
     */
    class APIParameter : public Hashable, public ModelElement {

    public:

        //DATA
        //===============

        //Parameter data
        std::string id;
        APIValueType valueType;
        int index;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        APIParameter();

        //Default Destructor
        ~APIParameter();

        //Constructor
        APIParameter(std::string aId, 
                     APIValueType aType,
                     int aIndex);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get type method
        APIValueType getValueType();

        //Set type method
        void setValueType(APIValueType aValueType);

        //Get index method
        int getIndex();

        //Set index method
        void setIndex(int aIndex);

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

#endif                          // MATIS_APIPARAMETER_H
