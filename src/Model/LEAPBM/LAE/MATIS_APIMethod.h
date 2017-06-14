// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_APIMethod.h,v $
// CVS $Date: 2006/01/03 12:20:04 $
// CVS $Revision: 1.3 $

#ifndef MATIS_APIMETHOD_H
#define MATIS_APIMETHOD_H 1
 
#include "MATIS_Types.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_APIParameter.h"
#include "MATIS_APIReturn.h"

namespace MATIS {

    /**
     * APIMethod: class which is responsible for maintaining referencing to library API methods
     */
    class APIMethod : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Method data
        std::string id;
        std::string name;
        std::string contextId;
        int numParameters;

        //Parameter storage
        handleListType parameters;

        //Exceptions
        handleListType exceptions;

        //Single APIReturn
        handleType returns;
        
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        APIMethod();

        //Default Destructor
        ~APIMethod();

        //Constructor
        APIMethod(std::string aId, 
                  std::string aName,
                  std::string aContextId,
                  handleType aReturns,
                  int aParameters);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get name method
        std::string getName();

        //Set name method
        void setName(std::string aName);

        //Get contextId method
        std::string getContextId();

        //Set contextId method
        void setContextId(std::string aContextId);

        //Set number of parameters
        void setNumParameters(int aNumParameters);

        //Get number of parameters method
        int getNumParameters();

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);


        //return a string hash of the current object
        std::string hash();     

    private:

        stringListType exceptionIds;

    };
    
}

#endif                          // MATIS_APIMETHOD_H
