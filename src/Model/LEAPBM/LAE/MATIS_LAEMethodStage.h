// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethodStage.h,v $
// CVS $Date: 2006/01/01 07:40:38 $
// CVS $Revision: 1.5 $

#ifndef MATIS_METHODSTAGE_H
#define MATIS_METHODSTAGE_H 1

#include "MATIS_Types.h"
#include "MATIS_LAEMethodStageProgression.h"

namespace MATIS {

    /**
     * MethodStage: class which is responsible for maintaining LAE functions
     */
    class LAEMethodStage : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Function data
        std::string id;
        handleType APIMethod;
        handleType LAEMethod;
        LAEMethodStageType flag;
        bool start;

        handleListType progressions;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEMethodStage();

        //Default Destructor
        ~LAEMethodStage();

        //Constructor
        LAEMethodStage(std::string aId,
                       handleType aAPIMethod,
                       handleType aLAEMethod,
                       LAEMethodStageType aFlag,
                       bool aStart);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get APIMethod method
        handleType getAPIMethod();

        //Set APIMethod method
        void setAPIMethod(handleType aAPIMethod);

        //Get LAEMethod method
        handleType getLAEMethod();

        //Set LAEMethod method
        void setLAEMethod(handleType aLAEMethod);

        //Get Flag method
        LAEMethodStageType getFlag();

        //Set Flag method
        void setFlag(LAEMethodStageType aFlag);

        //Get Start method
        bool getStart();

        //Set Start method
        void setStart(bool aStart);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

    private:

        std::string apiMethodId;
        std::string laeMethodId;

    };
    
}

#endif                          // MATIS_METHODSTAGE_H
