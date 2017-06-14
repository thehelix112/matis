// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBM.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.8 $

#ifndef MATIS_LEAPBM_H
#define MATIS_LEAPBM_H 1

#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Action.h"
#include "MATIS_Model.h"
#include "MATIS_Types.h"
#include "MATIS_LEAPBMIterator.h"
#include "MATIS_Action_RTI_13NG.h"
#include <ctime>

namespace MATIS {

    /**
     * LEAPBM: class which is responsible for maintaining logical
     * entity abstracted program behaviour models
     */
    class LEAPBM : public Model {

    public:

        //DATA
        //===============
        
        //Program data
        std::string id;
        handleListType processes;
        handleListType entries;
        handleListType exits;
        handleListType LAETerms;
        handleListType LAEs;
        handleListType LAEInteractions;
        handleListType unordereds;

        LEAPBMIterator iter;

        handleListType performedLAEMethods;
        handleListType unrestrictedLAEMethods;

        bool rejected;

        //checking time requirements
        unsigned long long int totalCycles;
        unsigned long long int startCPUCycles;

        std::ofstream outfile;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBM();

        //Default Destructor
        ~LEAPBM();

        //Constructor
        LEAPBM(std::string aId);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //return a string hash of the current object
        std::string hash();

        //Model overloaded functions.

        //test an Action to see if it is in conformance to this LEAPBM
        bool request(Action* aAction, bool *executeAnyway);

        //informed of the result of an Action
        void result(Action *aAction, void *aReturnValue);

        //generates a model based on a source file
        void generate(std::string aFilePath);
        
        //loads a previously save'd model from a file
        bool loadConfiguration(ConfigurationStore *aConfigurationStore);

        //finalise configuration
        bool postConfigurationLoad();

        //saves a generated model to a file
        bool saveConfiguration(ConfigurationStore *aConfigurationStore);
        
        //the path to any additional configuration information
        //that the model requires in order to generate a model
        void configure(std::string aFilePath);

        void loadHeader();

        void summary();

        void outputDot(std::string outfileFile);
        void outputInfo(std::string outputfile);
        void outputAnomaly(int totalRejections);

#include "MATIS_LEAPBMConvenienceMethods.h"
        
        static handleType drawingUnordered;

    private:

        bool checkUnrestricted(Action *aAction);
        void performUnrestricted(LAEMethod *aLAEMethod, Action *aAction);
        handleType performedUnrestrictedMethodCall;

        bool loaded;

    };
    
}


#endif                          // MATIS_LEAPBM_H
