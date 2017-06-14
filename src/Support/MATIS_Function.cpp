// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_Function.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#include "MATIS_Function.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
Function::Function(){
    
};

//Default Destructor
Function::~Function(void){
    
};


//Get id class
std::string Function::getId(){

    LOGMSG(5, "BEGIN Function: " << id << " getting id\n");
    LOGMSG(5, "END Function: " << id << " getting id\n");

};


//Set id class
void Function::setId(std::string aId){

    LOGMSG(5, "BEGIN Function: " << id << " setting id\n");

    LOGMSG(5, "END Function: " << id << " setting id\n");

};
