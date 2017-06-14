// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_ConfigurationElement.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_ConfigurationElement.h"

using namespace MATIS;

typedef std::list < ConfigurationElement > configurationElementListType;

/* Functionality */

/* Constructor */
ConfigurationElement::ConfigurationElement():
    name(""),
    data(""){


}

ConfigurationElement::ConfigurationElement(cistring aName){

    name = aName;

}

ConfigurationElement::ConfigurationElement(cistring aName,
                                           std::string aData){

    name = aName;
    data = aData;

}


/* Destructor */
ConfigurationElement::~ConfigurationElement(){

}

/* Return a list of elements */
configurationElementListType ConfigurationElement::getElementList(){

    return elements;

}

/* Set name */
void ConfigurationElement::setName(cistring aName){
    
    name = aName;
    
}


/* Get name */
cistring ConfigurationElement::getName(){
    
    return name;
    
}


/* Set data */
void ConfigurationElement::setData(std::string aData){
    
    data = aData;
    
}


/* Get data */
std::string ConfigurationElement::getData(){
    
    return data;
    
}


/* Add an ConfigurationElement to the list */
bool ConfigurationElement::addElement(ConfigurationElement aElement){

    elements.push_back(aElement);
    return true;

}

/* Delete a ConfigurationElement from the list */
bool ConfigurationElement::deleteElement(ConfigurationElement aElement){

    elements.remove(aElement);
    return true;

}


/* Return a list of parameters for an element */
stringListType ConfigurationElement::getParameterList(){

    stringListType retval;

    /* go through the multimap getting a list of the distinct parameters */
    for(parameterValueMapType::const_iterator it = parameterValues.begin(); it != parameterValues.end(); ++it){
        retval.push_back((*it).first);
    }

    return retval;

}

/* Return the first value of a parameter */
cistring ConfigurationElement::getParameterValue(cistring aParameter){

    return parameterValues[aParameter];

    /*stringListType list = getParameterValueList(aParameter);
      return *(list.begin());    */

}


/* Return the value of a parameter */
// stringListType ConfigurationElement::getParameterValueList(cistring aParameter){


//     stringListType retval;

//     /* get all the values for this parameter */
//     pair < parameterValueMapType::iterator,
//         parameterValueMapType::iterator > p = parameterValues.equal_range(aParameter);

//     /* go through the list of values until we find the correct one */
//     parameterValueMapType::iterator it;
//     for(it = p.first; it != p.second; ++it){
//         retval.push_back((*it).second);
//     }

//     return retval;

// }

/* delete a parameter and all its values */
bool ConfigurationElement::deleteParameter(cistring aParameter){

    /* delete all the values associated with the parameter */
    parameterValues.erase(aParameter);
    return true;

}

/* add a parameter's value */
bool ConfigurationElement::addParameterValue(cistring aParameter,
                                             cistring aValue){

    parameterValues.insert(parameterValueType(aParameter, aValue));
    return true;

}

/* delete a parameter's value */
bool ConfigurationElement::deleteParameterValue(cistring aParameter,
                                                cistring aValue){

    /* get all the values for this parameter */
    std::pair < parameterValueMapType::iterator,
        parameterValueMapType::iterator > p = parameterValues.equal_range(aParameter);

    /* go through the list of values until we find the correct one */
    parameterValueMapType::iterator it;
    for(it = p.first; it != p.second; ++it){
        if((*it).second == aValue) break;
    }

    /* erase the particular parameter value */
    parameterValues.erase(it, it);
    return true;

}

/* print this elements parameters and their values */
void ConfigurationElement::print(cistring pre){

    LOGMSG(3, pre << "CONFIGURATIONELEMENT: " << name);
    stringListType parameterList = getParameterList();
    stringListType valueList;

    pre += "  ";

    for(stringListType::iterator it = parameterList.begin(); it != parameterList.end(); ++it){

        LOGMSG(3, pre << (*it) << ": " << getParameterValue(*it));
        //valueList = getParameterValueList(*it);
        //
        //for(stringListType::iterator iq = valueList.begin(); iq != valueList.end(); ++iq){
        //    cout << pre << (*it) << ":  " << (*iq) << endl;
        //}
    }

    if(elements.size() > 0){

        /* go through each subelement and print it */
        for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it)
            (*it).print(pre);

    }


}


bool ConfigurationElement::operator ==(const ConfigurationElement &aElement){

    return(this->name == aElement.name &&
           this->parameterValues == aElement.parameterValues);

}
