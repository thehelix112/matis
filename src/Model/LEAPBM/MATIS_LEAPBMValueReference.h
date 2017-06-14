// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMValueReference.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LEAPBMVALUEREFERENCE_H
#define MATIS_LEAPBMVALUEREFERENCE_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMValuereference: class which is responsible for maintaining
     * references to other LAE property values made in PropertySets.
     */
    class LEAPBMValueReference : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //valuereference data
        std::string id;
        handleType property;
        handleType LAE;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMValueReference();

        //Default Destructor
        ~LEAPBMValueReference();

        //Constructor
        LEAPBMValueReference(std::string id,
                             handleType aProperty,
                             handleType aLAE);

        //Get Id property
        std::string getId();

        //Set Id property
        void setId(std::string aId);

        //Get Property property
        handleType getProperty();

        //Set Property property
        void setProperty(handleType aProperty);

        //Get LAE property
        handleType getLAE();

        //Set LAE property
        void setLAE(handleType aLAE);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        
    private:

        std::string laeId;
        std::string propertyId;
        
    };
    
}


#endif                          // MATIS_LEAPBMVALUEREFERENCE_H
