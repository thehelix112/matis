// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethodStageProgression.h,v $
// CVS $Date: 2005/12/30 10:39:09 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LAEMETHODSTAGEPROGRESSION_H
#define MATIS_LAEMETHODSTAGEPROGRESSION_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LAEMethodStageProgression: class which is responsible for maintaining LAE methodStageProgressions
     */
    class LAEMethodStageProgression : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //MethodStageProgression data
        handleType stageLAEMethod;
        handleType apiException;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEMethodStageProgression();

        //Default Destructor
        ~LAEMethodStageProgression();

        //Constructor
        LAEMethodStageProgression(handleType aStage,
                                  handleType aApiException);

        std::string getId();

        //Get stage method
        handleType getStage();

        //Set stage method
        void setStage(handleType aStage);

        //Get apiException method
        handleType getApiException();

        //Set apiException method
        void setApiException(handleType aApiException);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

    private:

        std::string stageId;
        std::string apiExceptionId;


    };
    
}

#endif                          // MATIS_LAEMETHODSTAGEPROGRESSION_H
