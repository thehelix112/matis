// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEClass.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LAECLASS_H
#define MATIS_LAECLASS_H 1

#include "MATIS_Types.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_LAEMethod.h"
#include "MATIS_LAEProperty.h"

namespace MATIS {

    /**
     * LAEClass: class which is responsible for maintaining logical abstract entity classes
     */
    class LAEClass : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Method data
        std::string id;

        //Methods map
        handleListType methods;

        //Properties map
        handleListType properties;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEClass();

        //Default Destructor
        ~LAEClass();

        //Constructor
        LAEClass(std::string aId);

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


#endif                          // MATIS_LAECLASS_H
