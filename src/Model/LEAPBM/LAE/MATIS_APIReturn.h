// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIReturn.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_APIRETURN_H
#define MATIS_APIRETURN_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * APIReturn: class which is responsible for maintaining API Returns
     */
    class APIReturn : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Checker data
        std::string id;
        APIValueType type;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        APIReturn();

        //Default Destructor
        ~APIReturn();

        //Constructor
        APIReturn(std::string aId,
                  APIValueType aType);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get type method
        APIValueType getType();

        //Set type method
        void setType(APIValueType aType);

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

#endif                          // MATIS_APIRETURN_H
