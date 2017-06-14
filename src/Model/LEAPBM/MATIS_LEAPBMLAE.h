// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMLAE.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LEAPBMLAE_H
#define MATIS_LEAPBMLAE_H 1

#include "MATIS_LEAPBMMethodCall.h"
#include "MATIS_LEAPBMPropertySet.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMLAE: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class LEAPBMLAE : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //LAE data
        std::string id;
        handleType laeClass;

        //these values are instantaneous and set by a successful
        //iterator progression
        mapPropertyValueType propertyValues;

        //Calls to LAE Methods
        handleListType methodCalls;

        //Settings made to LAE Properties
        handleListType propertySets;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMLAE();

        //Default Destructor
        ~LEAPBMLAE();

        //Constructor
        LEAPBMLAE(std::string aId,
                  handleType aClass);

        //Get Id method
        std::string getId();

        //Set Id method
        void setId(std::string aId);

        //Get Class method
        handleType getClass();

        //Set Class method
        void setClass(handleType aClass);

        //Set property value method
        void setPropertyValue(handleType property, std::string value);

        //Get property value method        
        std::string getPropertyValue(handleType property);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        
    private:

        std::string classId;
        
    };
    
}


#endif                          // MATIS_LEAPBMLAE_H
