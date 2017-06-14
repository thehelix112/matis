// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_ConfigurationStore.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.6 $

#include "MATIS_ConfigurationStore.h"
#include "MATIS_XMLStore.h"
#include "MATIS_Model.h"
#include "MATIS_LEAPBM.h"
#include "rdtscTimer.h"

using namespace MATIS;

/* Functionality */

/* Constructor */
ConfigurationStore::ConfigurationStore(){

}

/* Destructor */
ConfigurationStore::~ConfigurationStore(){

}


/* Place holder for sublcass: Load all elements */
bool ConfigurationStore::loadConfiguration(cistring aConfiguration){
    return true;
};

/* Place holder for sublcass: Save all elements */
bool ConfigurationStore::saveConfiguration(){
    return true;
};

void ConfigurationStore::print(cistring pre){

    rootElement.print();

}

/*bool ConfigurationStore::operator ==(const ConfigurationStore &aStore){

return(this->elements == aStore.elements);

}*/

void ConfigurationStore::setOutfile(cistring prefix){

    //cistring basefilepath = inFilepath.substr(0, inFilepath.find_last_of("\/")+1);
    cistring basefilename = inFilepath.substr(inFilepath.find_last_of("\\/")+1,
                                              inFilepath.find_last_of(".")-inFilepath.find_last_of("\\/")-1);

    outFilepath = prefix
        + basefilename
        + ".xml";

}

/* Static Data */
typedef std::map < std::string,
                   ConfigurationStore* > mapIdConfigurationStoreType;
mapIdConfigurationStoreType ConfigurationStore::configurationStores;

bool ConfigurationStore::initialised = false;


/* Static Functionality */

/* Initialise method is called by LibHookup::initialise() immediately preceeding any interposed call */
bool ConfigurationStore::initialise(){

    if(!initialised){
    
        //create an instance of XMLStore
        ConfigurationStore::configurationStores["LEAPBM"] = new XMLStore();
        
        //load the configuration from the default file
        if(!ConfigurationStore::configurationStores["LEAPBM"]->loadConfiguration(DEFAULT_CONFIG_LOCATION)){
            LOGERR("  Loading XML Configuration of LEAPBM failed.");
        }
        
        //instantiate a new LEAPBM and pass this configuration store instance to it
        Model::model = new LEAPBM();
        ((LEAPBM*)Model::model)->startCPUCycles = rdtsc();
        LOGMSG(1, "  Loading LEAPBM configuration............  ");
        initialised = Model::model->loadConfiguration(configurationStores["LEAPBM"]);
        LOGMSG(1, "DONE\n");
        LOGMSG(1, "  Performing LEAPBM post configuration....  ");
        initialised &= Model::model->postConfigurationLoad();
        LOGMSG(1, "DONE\n");

    }
    

}

