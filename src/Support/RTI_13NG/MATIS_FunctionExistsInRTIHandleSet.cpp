// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_FunctionExistsInRTIHandleSet.cpp,v $
// CVS $Date: 2005/12/01 14:37:15 $
// CVS $Revision: 1.1 $

#include "MATIS_FunctionExistsInRTIHandleSet.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
FunctionExistsInRTIHandleSet::FunctionExistsInRTIHandleSet(){
    
};

//Default Destructor
FunctionExistsInRTIHandleSet::~FunctionExistsInRTIHandleSet(void){
    
};

/*bool FunctionExistsInRTIHandleSet::checkValues(boost::any actionValue, std::string modelValue){
  
    
    
  
};*/

#include "dlc_register.h"
DLC_Register_Macro(FunctionExistsInRTIHandleSet);
