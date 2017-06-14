// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMProcess.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LEAPBMPROCESS_H
#define MATIS_LEAPBMPROCESS_H 1

#include "MATIS_LEAPBMHost.h"
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
    class LEAPBMProcess : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Program data
        std::string id;

        //Hosts
        handleListType hosts;

        //Files
        handleListType files;

        //Methods
        handleListType methods;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMProcess();

        //Default Destructor
        ~LEAPBMProcess();

        //Constructor
        LEAPBMProcess(std::string aId);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

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


#endif                          // MATIS_LEAPBMPROCESS_H
