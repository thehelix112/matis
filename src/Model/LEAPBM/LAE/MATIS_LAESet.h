// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAESet.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LAESET_H
#define MATIS_LAESET_H 1

#include "MATIS_Types.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_ConfigurationStore.h"
#include "MATIS_Model.h"

namespace MATIS {

    /**
     * LAESet: class which is responsible for maintaining LAE sets
     */
    class LAESet {

    public:

        //DATA
        //===============
        
        //Set data
        std::string id;
        std::string version;
        std::string author;
        std::string organisation;

        handleListType triggers;
        handleListType requirements;
        handleListType checkers;
        handleListType valueGroups;
        handleListType APIGroups;
        handleListType LAEClasses;
        handleListType functions;

        //Policy LEAPBM
        handleType policy;

        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAESet();

        //Default Destructor
        ~LAESet();

        //Constructor
        LAESet(std::string aId,
               std::string aVersion,
               std::string aAuthor,
               std::string aOrganisation);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get version method
        std::string getVersion();

        //Set version method
        void setVersion(std::string aVersion);

        //Get author method
        std::string getAuthor();

        //Set author method
        void setAuthor(std::string aAuthor);

        //Get organisation method
        std::string getOrganisation();

        //Set organisation method
        void setOrganisation(std::string aOrganisation);

        //loads a previously save'd model from a file
        bool loadConfiguration(ConfigurationStore *aConfigurationStore);
        bool postConfigurationLoad();

        //saves a generated model to a file
        bool saveConfiguration(ConfigurationStore *aConfigurationStore);

        //return a string hash of the current object
        std::string hash();

        
        //Static Data

#include "MATIS_LAESetConvenienceMethods.h"
        

    private:

        bool loaded;

    };
    
}

#endif                          // MATIS_LAESET_H
