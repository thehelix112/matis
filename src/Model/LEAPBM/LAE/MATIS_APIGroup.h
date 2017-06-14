// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIGroup.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_APIGROUP_H
#define MATIS_APIGROUP_H 1

#include "MATIS_Types.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_APIMethod.h"
#include "MATIS_APIException.h"
#include "MATIS_APIVariable.h"

namespace MATIS {

    /**
     * APIGroup: group which is responsible for maintaining logical abstract entity groupes
     */
    class APIGroup : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Method data
        std::string id;

        //Methods map
        handleListType methods;

        //Exceptions map
        handleListType exceptions;

        //Variables map
        handleListType variables;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        APIGroup();

        //Default Destructor
        ~APIGroup();

        //Constructor
        APIGroup(std::string aId);

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


#endif                          // MATIS_APIGROUP_H
