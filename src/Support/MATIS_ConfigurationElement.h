// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_ConfigurationElement.h,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#ifndef MATIS_CONFIGURATIONELEMENT_H
#define MATIS_CONFIGURATIONELEMENT_H 1

#include "MATIS_Types.h"

namespace MATIS {

    /**
     * ConfigurationElement: maintains individual configuration elements
     */
    class ConfigurationElement {

    typedef std::list < ConfigurationElement > configurationElementListType;

    public:

        /* Data */
        cistring name;
        parameterValueMapType parameterValues;
        configurationElementListType elements;
        std::string data;
        
        /* Functionality */

        /* Constructor */
        ConfigurationElement();
        ConfigurationElement(cistring aName);
        ConfigurationElement(cistring aName,
                             std::string data);

        /* Destructor */
        ~ConfigurationElement();

        /* Return a list of elements */
        configurationElementListType getElementList();


        /* Set name */
        void setName(cistring);
        
        /* Get name */
        cistring getName();

        /* Set data */
        void setData(std::string);
        
        /* Get data */
        std::string getData();

        /* Add a ConfigurationElement to the list */
        bool addElement(ConfigurationElement aElement);

        /* Delete a ConfigurationElement from the list */
        bool deleteElement(ConfigurationElement aElement);

        /* delete a parameter and all its values */
        bool deleteParameter(cistring aParameter);
        
        /* add a parameter's value */
        bool addParameterValue(cistring name, cistring aValue);
        
        /* delete a parameter's value */
        bool deleteParameterValue(cistring name, cistring aValue);

        /* Return a list of parameters for an element */
        stringListType getParameterList();
        
        /* Return the first value of a parameter */
        cistring getParameterValue(cistring aParameter);

        /* Return the value of a parameter */
        //cistring getParameterValueList(cistring aParameter);

        /* print this element and its parameters and their values */
        void print(cistring pre = "");

        bool operator ==(const ConfigurationElement &aElement);
        
    };

}

#endif                     //MATIS_CONFIGURATIONELEMENT_H

    
