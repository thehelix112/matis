// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEValueGroup.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LAEVALUEGROUP_H
#define MATIS_LAEVALUEGROUP_H 1

#include "MATIS_Types.h"
#include "MATIS_LAEValueType.h"
#include "MATIS_UniqueHandleFactory.h"

namespace MATIS {

    /**
     * LAEValueGroup: class which is responsible for maintaining LAE valueGroups
     */
    class LAEValueGroup : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //ValueGroup data
        std::string id;

        //Value Types
        handleListType valueTypes;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEValueGroup();

        //Default Destructor
        ~LAEValueGroup();

        //Constructor
        LAEValueGroup(std::string aId);

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

#endif                          // MATIS_LAEVALUEGROUP_H
