// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMLAEInteraction.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LEAPBMLAEMETHODCALL_H
#define MATIS_LEAPBMLAEMETHODCALL_H 1

#include "MATIS_LEAPBMPathway.h"
#include "MATIS_LEAPBMException.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMMethodcall: class which is responsible for maintaining the
     * legal pathways between calls made on a LAE methods. This class
     * does NOT store the information about the LAE method call itself,
     * only a reference to the LAE and Method in which they can be found.
     */
    class LEAPBMLAEInteraction : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //methodcall data
        std::string id;
        handleType LAE;
        handleType methodCall;
        handleType propertySet;

        //LAE pathways
        handleListType pathways;

        //LAE exceptions
        handleListType exceptions;

        bool performed;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMLAEInteraction();

        //Default Destructor
        ~LEAPBMLAEInteraction();

        //Constructor
        LEAPBMLAEInteraction(std::string id,
                             handleType aLAE,
                             handleType aMethodCall,
                             handleType aPropertySet);

        //Get Id method
        std::string getId();

        //Set Id method
        void setId(std::string aId);

        //Get LAE method
        handleType getLAE();

        //Set LAE method
        void setLAE(handleType aLAE);

        //Get MethodCall method
        handleType getMethodCall();

        //Set MethodCall method
        void setMethodCall(handleType aMethodCall);

        //Get PropertySet method
        handleType getPropertySet();

        //Set PropertySet method
        void setPropertySet(handleType aPropertySet);


        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //set the lae's propertyValues as appropriate
        void perform();

        //return a string hash of the current object
        std::string hash();

        std::string getDot(int level = 1);
        
    private:

        std::string laeId;
        std::string methodCallId;
        std::string propertySetId;

        std::list < LEAPBMPathway* > pathwayObjects;
        std::list < LEAPBMException* > exceptionObjects;
        
    };
    
}


#endif                          // MATIS_LEAPBMLAEMETHODCALL_H
