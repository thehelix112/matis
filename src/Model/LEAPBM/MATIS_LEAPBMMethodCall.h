// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMMethodCall.h,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LEAPBMMETHODCALL_H
#define MATIS_LEAPBMMETHODCALL_H 1

#include "MATIS_LEAPBMPropertySet.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMMethodcall: class which is responsible for maintaining the
     * details of a method call made on a LAE instance.
     */
    class LEAPBMMethodCall : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //methodcall data
        std::string id;
        handleType method;

        //LAE Property sets
        handleListType propertySets;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMMethodCall();

        //Default Destructor
        ~LEAPBMMethodCall();

        //Constructor
        LEAPBMMethodCall(std::string aId,
                         handleType aMethod);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get MethodId method
        handleType getMethod();

        //Set MethodId method
        void setMethod(handleType aMethod);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        
    private:

        std::string methodId;

        std::list < LEAPBMPropertySet* > propertySetObjects;
        
    };
    
}


#endif                          // MATIS_LEAPBMMETHODCALL_H
