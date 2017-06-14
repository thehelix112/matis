// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAETrigger.cpp,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $

#include "MATIS_LAETrigger.h"

using namespace MATIS;


//Default Constructor
LAETrigger::LAETrigger():
    id(""),
    header(""),
    library(""){
    
};

//Default Destructor
LAETrigger::~LAETrigger(){
     
};

//Constructor
LAETrigger::LAETrigger(std::string aId,
                       std::string aHeader,
                       std::string aLibrary):
    id(aId),
    header(aHeader),
    library(aLibrary){
    
};

//Get id method
std::string LAETrigger::getId(){

    LOGMSG(5, "BEGIN LAETrigger: " << id << " getting id\n");
    LOGMSG(5, "END LAETrigger: " << id << " getting id\n");

    return id;

};


//Set id method
void LAETrigger::setId(std::string aId){

    LOGMSG(5, "BEGIN LAETrigger: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LAETrigger: " << id << " setting id\n");

};

//Get header method
std::string LAETrigger::getHeader(){

    LOGMSG(5, "BEGIN LAETrigger: " << id << " getting header\n");
    LOGMSG(5, "END LAETrigger: " << id << " getting header\n");

    return header;

};


//Set header method
void LAETrigger::setHeader(std::string aHeader){

    LOGMSG(5, "BEGIN LAETrigger: " << id << " setting header\n");

    header = aHeader;

    LOGMSG(5, "END LAETrigger: " << id << " setting header\n");

};


//Get library method
std::string LAETrigger::getLibrary(){

    LOGMSG(5, "BEGIN LAETrigger: " << id << " getting library\n");
    LOGMSG(5, "END LAETrigger: " << id << " getting library\n");

    return library;

};


//Set library method
void LAETrigger::setLibrary(std::string aLibrary){

    LOGMSG(5, "BEGIN LAETrigger: " << id << " setting library\n");

    library = aLibrary;

    LOGMSG(5, "END LAETrigger: " << id << " setting library\n");

};


//Load the configuration
bool LAETrigger::loadConfiguration(ConfigurationElement *aElement){
    
    //configure the values from the configuration element
    setId(aElement->getParameterValue("id").c_str());
    setHeader(aElement->getParameterValue("header").c_str());
    setLibrary(aElement->getParameterValue("library").c_str());
   
}

//Save the configuration
bool LAETrigger::saveConfiguration(ConfigurationElement *aElement){
    
    
}



//return a string hash of the current object
std::string LAETrigger::hash(){

    LOGMSG(5, "BEGIN LAETrigger: " << id << " hash\n");
    LOGMSG(5, "END LAETrigger: " << id << " hash\n");

    return Hashable::hashObject(OBJECT_LAETRIGGER, id);
    
};






