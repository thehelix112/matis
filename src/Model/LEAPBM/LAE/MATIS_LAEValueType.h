// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEValueType.h,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LAEVALUETYPE_H
#define MATIS_LAEVALUETYPE_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LAEValueType: class which is responsible for maintaining LAE valueTypes
     */
    class LAEValueType : public Hashable, public ModelElement {

    public:

        //DATA
        //===============
        
        //ValueType data
        std::string id;
        std::string validatorId;
        ValueType type;
        handleType validator;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEValueType();

        //Default Destructor
        ~LAEValueType();

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get validator method
        std::string getValidatorId();

        //Set validator method
        void setValidatorId(std::string aValidator);

        //Get validator method
        handleType getValidator();

        //Set validator method
        void setValidator(handleType aValidator);

        //Get type method
        ValueType getType();

        //Set type method
        void setType(ValueType aType);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();
        
        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();

    private:

    };
    
}

#endif                          // MATIS_LAEVALUETYPE_H
