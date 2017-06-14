// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEProperty.h,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.4 $

#ifndef MATIS_LAEPROPERTY_H
#define MATIS_LAEPROPERTY_H 1

#include "MATIS_Types.h"
#include "MATIS_LAEPropertySource.h"
#include "MATIS_UniqueHandleFactory.h"

namespace MATIS {

    /**
     * LAEProperty: class which is responsible for maintaining LAE properties
     */
    class LAEProperty : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Method data
        std::string id;
        actionStorageCategoryType actionStorageCategory;
        std::string actionStorage;
        int numSources;
        ValueType type;
        handleType customType;

        //sources 
        handleListType sources;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEProperty();

        //Default Destructor
        ~LAEProperty();

        //Constructor
        LAEProperty(std::string aId,
                    int aSources,
                    ValueType aType,
                    std::string aActionStorage,
                    actionStorageCategoryType aActionStorageCategory);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get actionStorage method
        actionStorageCategoryType getActionStorageCategory();

        //Set actionStorage method
        void setActionStorageCategory(actionStorageCategoryType aActionStorageCategory);

        //Get actionStorage method
        std::string getActionStorage();

        //Set actionStorage method
        void setActionStorage(std::string aActionStorage);

        //Get type method
        ValueType getType();

        //Set type method
        void setType(ValueType aType);

        handleType getCustomType();

        void setCustomType(handleType aValueType);

        //Get number of sources method
        int getNumSources();        

        //Set number of sources
        void setNumSources(int aNumSources);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();


    private:

        std::string customTypeId;

        std::list < LAEPropertySource* > sourceObjects;
        

    };
    
}

#endif                          // MATIS_LAEMETHOD_H
