// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMHost.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LEAPBMHOST_H
#define MATIS_LEAPBMHOST_H 1

#include "MATIS_LEAPBMFile.h"
#include "MATIS_LEAPBMMethod.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMPROCESS: class which is responsible for maintaining the
     * execution processs of logical entity abstracted program behaviour
     * models.
     */
    class LEAPBMHost : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Program data
        std::string id;
        std::string domainName;

        //Files
        handleListType files;

        //Methods
        handleListType methods;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMHost();

        //Default Destructor
        ~LEAPBMHost();

        //Constructor
        LEAPBMHost(std::string aId,
                          std::string aDomainName);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get id method
        std::string getDomainName();

        //Set id method
        void setDomainName(std::string aDomainName);

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


#endif                          // MATIS_LEAPBMHOST_H
