// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_XMLStore.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_XMLSTORE_H
#define MATIS_XMLSTORE_H 1

#include "MATIS_ConfigurationStore.h"
#include "MATIS_ConfigurationElement.h"

namespace MATIS {

    /**
     * LAEValueType: class which is responsible for maintaining LAE valueTypes
     */
    class ConfigurationElement;

    typedef std::list < ConfigurationElement > configurationElementListType;

    class XMLStore : public ConfigurationStore {
        
    public:

        /* Data */
        xmlDocPtr document;
        xmlNodePtr current;

        /* Functionality */
        
        /* Constructor */
        XMLStore();

        /* Destructor */
        virtual ~XMLStore();

        /* load the configuration given a path to an XML file */
        bool loadConfiguration(cistring filePath);
        
        /* write the configuration back to the store */
        bool saveConfiguration();

        bool operator ==(const XMLStore &aStore);
        
    private:
        
        void parseElements(xmlNodePtr aCurrent, 
                           ConfigurationElement *currentElement);
        void writeElements(std::fstream &outfile, 
                           ConfigurationElement *currentElement,
                           cistring pre = "");
        
    };
    
}

#endif                           //MATIS_XMLSTORE_H
