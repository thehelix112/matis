// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMException.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LEAPBMEXCEPTION_H
#define MATIS_LEAPBMEXCEPTION_H 1

#include "MATIS_LEAPBMPathway.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMException: class which is responsible for maintaining the
     * legal pathways from an exceptional return from an LAEMethodCall.
     */
    class LEAPBMException : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //exception data
        handleType exception;

        //Pathways
        handleListType pathways;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMException();

        //Default Destructor
        ~LEAPBMException();

        //Constructor
        LEAPBMException(handleType aException);

        //Get Exception method
        handleType getException();

        //Set Exception method
        void setException(handleType aException);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);


        //return a string hash of the current object
        std::string hash();

        std::string getDot(int level = 1);

        std::string getExceptionId();
        
        
    private:

        std::string exceptionId;

        std::list < LEAPBMPathway* > pathwayObjects;
        
        
    };
    
}


#endif                          // MATIS_LEAPBMEXCEPTION_H
