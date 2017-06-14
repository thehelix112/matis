// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Model.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.7 $





#ifndef MATIS_MODEL_H
#define MATIS_MODEL_H

#include "MATIS_Action.h"
#include "MATIS_ConfigurationStore.h"
#include "MATIS_LEAPBMProcess.h"
#include "MATIS_LEAPBMEntry.h"
#include "MATIS_LEAPBMExit.h"
#include "MATIS_LEAPBMLAETerm.h"
#include "MATIS_LEAPBMLAE.h"
#include "MATIS_LEAPBMMethodCall.h"
#include "MATIS_LEAPBMUnordered.h"
#include "MATIS_LEAPBMValueReference.h"

#include "MATIS_LAEClass.h"
#include "MATIS_LAETrigger.h"
#include "MATIS_APIGroup.h"
#include "MATIS_LAEChecker.h"
#include "MATIS_LAEFunction.h"
#include "MATIS_LAEPropertyReference.h"
#include "MATIS_LAEValueGroup.h"
#include "MATIS_LAERequirement.h"
#include "MATIS_LAEPolicy.h"

namespace MATIS {

    class Model {

      public:
        
        /* Data */
        bool isConfigured;
        unsigned int calls;
        unsigned int rejections;
        bool detection;

        /* Functionality */

        //return whether or not this Model matches an Action
        virtual bool request(Action* aAction, bool *executeAnyway){ 
            return false;    
        };

        //inform the model of the result of the last call
        virtual void result(Action *aAction, void* aReturnValue){};

        //generates a model based on a source file
        virtual void generate(std::string aFilePath){};
        
        //loads a previously save'd model from a file
        virtual bool loadConfiguration(ConfigurationStore *aConfigurationStore){ 
            return false;    
        };

        //configuration which cannot safely be performed until all
        //basic configuration has occurred. this usually involves
        //resolving handles to other objects the creation of which is
        //not gaurunteed to have been performed.
        virtual bool postConfigurationLoad(){ 
            return false;    
        };

        //saves a generated model to a file
        virtual bool saveConfiguration(ConfigurationStore *aConfigurationStore){ 
            return false;    
        };
        
        //the path to any additional configuration information
        //that the model requires in order to generate a model
        virtual void configure(std::string aFilePath){};

        //print the summary of calls, rejections, etc
        virtual void summary(){
            
            std::cerr << "\n---------------------------------------------------------------\n";
            std::cerr << "Total number of interactions requested: " << calls << "\n";
            std::cerr << "Number of anomalies detected: " << rejections << "\n";

            double percentage = ((double)rejections/(double)calls)*100;
            std::cerr << "Percentage anomalous: " << percentage << "\n";
            std::cerr << "---------------------------------------------------------------\n";

        };
        
        /* Static Data */
        static Model* model;

#include "MATIS_LEAPBMModel.h"


        /* Static Functionality */


    };


}
#endif //MATIS_MODEL_H
