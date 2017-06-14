// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEPropertyReference.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LAEPROPERTYREFERENCE_H
#define MATIS_LAEPROPERTYREFERENCE_H 1

#include "MATIS_Types.h"
#include "MATIS_UniqueHandleFactory.h"

namespace MATIS {

    /**
     * LAEPropertyReference: class which is responsible for maintaining LAE property references
     */
    class LAEPropertyReference : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //PropertyReference data
        std::string id;
        handleType property;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEPropertyReference();

        //Default Destructor
        ~LAEPropertyReference();

        //Constructor
        LAEPropertyReference(std::string aId,
                             handleType aProperty);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get property method
        handleType getProperty();

        //Set property method
        void setProperty(handleType aProperty);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);


        //return a string hash of the current object
        std::string hash();

    private:

        std::string propertyId;

    };
    
}

#endif                          // MATIS_LAEPROPERTYREFERENCE_H
