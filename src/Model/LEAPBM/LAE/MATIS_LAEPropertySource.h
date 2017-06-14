// Copyright 2004 Davauthority Andrews
// Authors: Davauthority Andrews
// CVS $RCSfile: MATIS_LAEPropertySource.h,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.5 $

#ifndef MATIS_LAEPROPERTYSOURCE_H
#define MATIS_LAEPROPERTYSOURCE_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LAEPropertySource: class which is responsible for maintaining referencing to library API exceptions
     */
    class LAEPropertySource : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //Method data
        int authority;
        handleType APIParameter;
        handleType APIReturn;
        handleType APIVariable;

        handleListType propertyReferences;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEPropertySource();

        //Default Destructor
        ~LAEPropertySource();

        //Constructor
        LAEPropertySource(int aAuthority, 
                          handleType aAPIParameter,
                          handleType aAPIReturn,
                          handleType aAPIVariable);
        
        //get Id
        std::string getId();

        //Get authority method
        int getAuthority();

        //Set authority method
        void setAuthority(int aAuthority);

        //Get APIParameter method
        handleType getAPIParameter();

        //Set APIParameter method
        void setAPIParameter(handleType aAPIParameter);

        //Get APIReturn method
        handleType getAPIReturn();

        //Set APIReturn method
        void setAPIReturn(handleType aAPIReturn);

        //Get APIVariable method
        handleType getAPIVariable();

        //Set APIVariable method
        void setAPIVariable(handleType aAPIVariable);


        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

        //bool helper methods
        bool isParameter();
        bool isVariable();
        bool isReturn();

    private:

        std::string apiParameterId;
        std::string apiReturnId;
        std::string apiVariableId;

    };
    
}

#endif                          // MATIS_LAEPROPERTYSOURCE_H
