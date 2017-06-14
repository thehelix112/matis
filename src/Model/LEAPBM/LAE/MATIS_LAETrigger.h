// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAETrigger.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_LAETRIGGER_H
#define MATIS_LAETRIGGER_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LAETrigger: class which is responsible for maintaining LAE triggers
     */
    class LAETrigger : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Trigger data
        std::string id;
        std::string header;
        std::string library;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAETrigger();

        //Default Destructor
        ~LAETrigger();

        //Constructor
        LAETrigger(std::string aId,
                   std::string aHeader,
                   std::string aLibrary);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get header method
        std::string getHeader();

        //Set header method
        void setHeader(std::string aHeader);

        //Get library method
        std::string getLibrary();

        //Set library method
        void setLibrary(std::string aLibrary);

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

#endif                          // MATIS_LAETRIGGER_H
