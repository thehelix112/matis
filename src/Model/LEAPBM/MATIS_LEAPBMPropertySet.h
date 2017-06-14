// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMPropertySet.h,v $
// CVS $Date: 2005/12/05 12:53:00 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LEAPBMPROPERTYSET_H
#define MATIS_LEAPBMPROPERTYSET_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMPropertyset: class which is responsible for maintaining
     * the setting of lae property values during transitions or method
     * calls.
     */
    class LEAPBMPropertySet : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //propertyset data
        handleType property;
        std::string byteValue;
        handleListType valueReferences;
        bool runtimeValue;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMPropertySet();

        //Default Destructor
        ~LEAPBMPropertySet();

        //Constructor
        LEAPBMPropertySet(handleType aProperty,
                          std::string aByteValue);

        //get id
        std::string getId();

        //Get RuntimeValue runtimeValue
        bool getRuntimeValue();

        //Set RuntimeValue runtimeValue
        void setRuntimeValue(bool aRuntimeValue);


        //Get Property property
        handleType getProperty();

        //Set Property property
        void setProperty(handleType aProperty);

        //Get ByteValue property
        std::string getByteValue();

        //Set ByteValue property
        void setByteValue(std::string aByteValue);

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


#endif                          // MATIS_LEAPBMPROPERTYSET_H
