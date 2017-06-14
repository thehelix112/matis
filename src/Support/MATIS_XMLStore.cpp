// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_XMLStore.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_XMLStore.h"

using namespace MATIS;

/* Functionality */

/* Constructor */
XMLStore::XMLStore(){

}

/* Destructor */
XMLStore::~XMLStore(){

    xmlFreeDoc(document);
    xmlFree(current);

}

/* configure this XMLStore */
bool XMLStore::loadConfiguration(cistring aFilePath){

    /* attempt to create an xmlDocPtr from the path */
    if((document = xmlParseFile(aFilePath.c_str())) == NULL){
        LOGMSG(3, "XML file not parsed");
        return false;
    }

    inFilepath = aFilePath;

    /* attempt to get a pointer to the first element in the xml document */
    if((current = xmlDocGetRootElement(document)) == NULL){
        LOGMSG(3, "XML document empty");
        return false;
    }

    /* entire the xml document is of the correct type */
    if(xmlStrcmp(current->name, xmlCharStrdup("leapbm")) && 
       xmlStrcmp(current->name, xmlCharStrdup("laeset"))){
        LOGMSG(3, "XML document of incorrect type:" << current->name << "\n");
        return false;
    }    

    /* go through and parse the configuration elements */

    /* create this element */
    rootElement.setName((const char*)current->name);
    
    /* populate the element with parameters and their values */
    xmlAttrPtr aAttribute = current->properties;
    while(aAttribute != NULL){
        
        cistring parameter = (const char*)(aAttribute->name);
        cistring value = (const char*)(xmlGetProp(current, aAttribute->name));
        
        rootElement.addParameterValue(parameter, value);
        
        aAttribute = aAttribute->next;  
        
    } 
    
    /* parse its children */
    parseElements(current->children, &rootElement);

    return true;

};

/* save this configuration */
bool XMLStore::saveConfiguration(){

    /* open the file and truncate it to zero */
    std::fstream outfile;
    outfile.open(outFilepath.c_str(), std::fstream::out | std::fstream::trunc);

    if(!outfile){
        LOGERR("Failed to open `" << outFilepath << "' for writing output.");
    }
        
    outfile << "<?xml version=\"1.0\"?>" << std::endl;

    /* starting from the first real element, go through them
       and write them to the file as xml elements */
    ConfigurationElement firstElement = *(rootElement.getElementList().begin());
    writeElements(outfile, &firstElement);

    /* close the file now that we've finished */
    outfile.close();

    return true;

};


/* private methods */

void XMLStore::parseElements(xmlNodePtr aCurrent,
                             ConfigurationElement *currentElement){

    while(aCurrent != NULL){

        /* skip xmlNodePtrs whose names are `text' as they are pointers to the CDATA value, not elements? */
        if(xmlStrcmp(aCurrent->name, xmlCharStrdup("text")) != 0){

            /* create this element */
            ConfigurationElement aElement((const char*)aCurrent->name);

            /* populate the element with parameters and their values */
            xmlAttrPtr aAttribute = aCurrent->properties;
            while(aAttribute != NULL){
                
                cistring parameter = (const char*)(aAttribute->name);
                cistring value = (const char*)(xmlGetProp(aCurrent, aAttribute->name));
                
                aElement.addParameterValue(parameter, value);
                
                aAttribute = aAttribute->next;  
                
            } 

            /* parse its children */
            parseElements(aCurrent->children, &aElement);
            
            currentElement->addElement(aElement);

        } else {

            /* we have a handle on the CDATA for this element */
            currentElement->setData((const char *)aCurrent->content);
    
        }
        
        aCurrent = aCurrent->next;

    }

}

/* write an element to the xml file */
void XMLStore::writeElements(std::fstream &outfile,
                             ConfigurationElement *currentElement,
                             cistring pre){

    /* open the xml element */
    outfile << pre << "<" << currentElement->name;

    pre += "  ";

    /* write its parameters */
    stringListType parameters = currentElement->getParameterList();
    bool isParameters;
    if(isParameters = (parameters.size() > 0)){

        /* get the values for the parameters */
        stringListType valueList;

        for(stringListType::iterator it = parameters.begin(); it != parameters.end(); ++it){
            outfile << std::endl << pre << (*it) << "=\"" << currentElement->getParameterValue(*it) << "\"";
        }

    }

    pre.erase(0,2);
    configurationElementListType subelements = currentElement->getElementList();

    if(subelements.size() > 0){

        outfile << ">" << std::endl;

        /* write its children */
        for(configurationElementListType::iterator it = subelements.begin(); it != subelements.end(); ++it)
            writeElements(outfile, &(*it), pre + "  ");

        /* close the element */
        outfile << pre << "</" << currentElement->name << ">" << std::endl;

    } else {

        /* close the parent element */
        outfile <<  "/>" << std::endl;

    }


}


bool XMLStore::operator ==(const XMLStore &aStore){

    return (this->document == aStore.document &&
            this->current == aStore.current &&
            this->inFilepath == aStore.inFilepath &&
            this->outFilepath == aStore.outFilepath);

}
