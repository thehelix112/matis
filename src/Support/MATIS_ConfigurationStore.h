// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_ConfigurationStore.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_CONFIGURATIONSTORE_H
#define MATIS_CONFIGURATIONSTORE_H 1

#include "MATIS_ConfigurationElement.h"

namespace MATIS {

    /**
     * ConfigurationStore: maintains an overall configuration.
     */
    class ConfigurationStore {

    typedef std::map < std::string, 
                       ConfigurationStore* > mapIdConfigurationStoreType;
        
    public:

        /* Data */
        ConfigurationElement rootElement;
        cistring inFilepath;
        cistring outFilepath;
        cistring outFilePrefix;

        /* Functionality */

        /* Constructor */
        ConfigurationStore();

        /* Destructor */
        virtual ~ConfigurationStore();

        /* Load all elements */
        virtual bool loadConfiguration(cistring aConfiguration);

        /* Save all elements */
        virtual bool saveConfiguration();

        /* print out the elements */
        void print(cistring pre = "");

        //bool operator ==(const ConfigurationStore &aStore);

        void setOutfile(cistring prefix);

        //Static Data
        static mapIdConfigurationStoreType configurationStores;
        static bool initialised;

        //Static Functionality
        static bool initialise();


        
    };
    
}

#endif                        //MATIS_CONFIGURATIONSTORE_H

    
