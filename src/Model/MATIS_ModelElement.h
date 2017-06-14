// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_ModelElement.h,v $
// CVS $Date: 2005/12/05 12:52:59 $
// CVS $Revision: 1.2 $





#ifndef MATIS_MODELELEMENT_H
#define MATIS_MODELELEMENT_H

//#include "MATIS_ConfigurationElement.h"

namespace MATIS {

    class ConfigurationElement;

    class ModelElement {

      public:
        
        handleType handle;
        handleType parentHandle;
        objectType parentType; //only used if object has multiple parent types

        //Load the configuration
        virtual bool loadConfiguration(ConfigurationElement *aElement) = 0;

        //Functionality
        virtual bool postConfigurationLoad() = 0;

        //Save the configuration
        virtual bool saveConfiguration(ConfigurationElement *aElement) = 0;
        

    };


}
#endif //MATIS_MODELELEMENT_H
