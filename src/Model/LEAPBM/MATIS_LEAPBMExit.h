// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMExit.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LEAPBMEXIT_H
#define MATIS_LEAPBMEXIT_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMExit: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class LEAPBMExit : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Exit data
        std::string id;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMExit();

        //Default Destructor
        ~LEAPBMExit();

        //Constructor
        LEAPBMExit(std::string aId);

        //Get Id method
        std::string getId();

        //Set Id method
        void setId(std::string aId);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        
        NULL_POST_CONFIGURATION;
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        std::string getDot(int level = 1);

        
    private:

    };
    
}


#endif                          // MATIS_LEAPBMEXIT_H
