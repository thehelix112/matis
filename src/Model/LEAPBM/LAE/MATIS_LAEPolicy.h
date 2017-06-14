// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEPolicy.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_LAEPOLICY_H
#define MATIS_LAEPOLICY_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LAEPolicy: class which is responsible for maintaining LAE policys
     */
    class LAEPolicy : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Policy data
        std::string id;
        std::string LEAPBMId;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEPolicy();

        //Default Destructor
        ~LAEPolicy();

        //Constructor
        LAEPolicy(std::string aId,
                  std::string aLEAPBMId);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get leapbmId method
        std::string getLEAPBMId();

        //Set leapbmId method
        void setLEAPBMId(std::string aLEAPBMId);

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

#endif                          // MATIS_LAEPOLICY_H
