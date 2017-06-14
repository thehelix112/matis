// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_PluginStore.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $








#include "matis-config.h"
#include "MATIS_PluginStore.h"
#include "MATIS_TypeConversion.h"

using namespace MATIS;


PluginStore *PluginStore::store = 0;

std::string PluginStore::getPluginFullPath(std::string aName){
	
    std::string path;	
    path = std::string(MATISDATADIR) + "/plugins/matis_" + aName + ".so";
    return path;
}

void PluginStore::initialise(){
    
    LOGMSG(1, "  loading plugins\n");

}

Plugin *PluginStore::getInstance(std::string aName,
                                 std::string aSuggestedPath){

    Plugin *retval = New < Plugin > (aName.c_str());

    if (retval == 0) {

        // module not present, attempt autoloading
        std::string path;

        if(aSuggestedPath.length() > 0)
            path = aSuggestedPath;
        else
            path = getPluginFullPath(aName);

        if(!DLC_Server.load(path.c_str())){
            LOGERR("opening module '" << path << "'.");
        } else {
            LOGMSG(1, "Loaded module '" << aName << "'");
        }

        retval = New < Plugin > (aName.c_str());

    }

    if (retval == 0)
        LOGERR("plugin " << aName << " not found.");    

    return retval;

}

PluginStore *PluginStore::getStore(){

    if(store == 0){
        store = new PluginStore();
    }
    return store;

}

PluginStore::PluginStore(){

    // should autoload plugins here maybe?

}


// ///////////////////

Checker* PluginStore::getChecker(std::string aId){

    PluginStore* ps = getStore();
    std::string name = (ps->checkerNames)[aId.c_str()];
    std::string filename = (ps->checkerFilenames)[aId.c_str()];

    if (name.length()>0) {
        return (Checker*) ps->getInstance(name, filename);
    }

    // default, assume the id is actually the name..
    return (Checker*) ps->getInstance(aId);	
}


void PluginStore::setCheckerFilename(std::string aId,
                                     std::string aFilename){
	
    PluginStore* ps = getStore();
    ps->checkerFilenames[aId.c_str()]= aFilename;
	
}



void PluginStore::setCheckerName(std::string aId,
                                 std::string aName){
	
    PluginStore* ps = getStore();
    ps->checkerNames[aId.c_str()] = aName;	

}

// ///////////////////

Function* PluginStore::getFunction(std::string aId){

    PluginStore* ps = getStore();
    std::string name = (ps->functionNames)[aId.c_str()];
    std::string filename = (ps->functionFilenames)[aId.c_str()];

    if (name.length()>0) {
        return (Function*) ps->getInstance(name, filename);
    }

    // default, assume the id is actually the name..
    return (Function*) ps->getInstance(aId);	
}


void PluginStore::setFunctionFilename(std::string aId,
                                     std::string aFilename){
	
    PluginStore* ps = getStore();
    ps->functionFilenames[aId.c_str()]= aFilename;
	
}



void PluginStore::setFunctionName(std::string aId,
                                 std::string aName){
	
    PluginStore* ps = getStore();
    ps->functionNames[aId.c_str()] = aName;	

}

