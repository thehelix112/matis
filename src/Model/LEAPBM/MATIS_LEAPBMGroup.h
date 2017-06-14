// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMGroup.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.6 $

#ifndef MATIS_LEAPBMGROUP_H
#define MATIS_LEAPBMGROUP_H 1

#include "MATIS_LEAPBMLAEInteraction.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    class LEAPBMGroupIterator;

    /**
     * LEAPBMGroup: class which is responsible for maintaining the
     * details of a method call made on a LAE instance.
     */
    class LEAPBMGroup : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //group data
        std::string id;
        int requiredMin;
        int requiredMax;
        bool minimumInclusive, maximumInclusive, maximumInfinite;
        handleType entry;
        pathwayDestinationTypeType entryType;

        //iterator
        LEAPBMGroupIterator *iter;

        //LAE Method Calls
        handleListType LAEInteractions;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMGroup();

        //Default Destructor
        ~LEAPBMGroup();

        //Constructor
        LEAPBMGroup(std::string aId,
                     int aRequiredMin,
                     int aRequiredMax,
                     handleType aEntry,
                     pathwayDestinationTypeType aEntryType);

        //Get id method
        std::string getId();
        //Set id method
        void setId(std::string aId);

        //Get Entry method
        handleType getEntry();
        //Set Entry method
        void setEntry(handleType aEntry);


        //Get RequiredMin method
        int getRequiredMin();
        //Set RequiredMin method
        void setRequiredMin(int aRequiredMin);

        //Get RequiredMax method
        int getRequiredMax();
        //Set RequiredMax method
        void setRequiredMax(int aRequiredMax);

        //Get EntryType method
        pathwayDestinationTypeType getEntryType();

        //Set EntryType method
        void setEntryType(pathwayDestinationTypeType aEntryType);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        std::string getDot(int level = 1);

        
    private:

        std::string entryId;

        bool parseRequired(std::string aRequiredString);
        
    };
    
}


#endif                          // MATIS_LEAPBMGROUP_H
