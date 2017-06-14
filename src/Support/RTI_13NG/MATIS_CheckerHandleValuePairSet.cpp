// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerHandleValuePairSet.cpp,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.2 $

#include "MATIS_CheckerHandleValuePairSet.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
CheckerHandleValuePairSet::CheckerHandleValuePairSet(){
    
};

//Default Destructor
CheckerHandleValuePairSet::~CheckerHandleValuePairSet(void){
    
};

bool CheckerHandleValuePairSet::checkValues(boost::any actionValue, std::string modelValue){
  
    LOGMSG(4, "CheckerHandleValuePairSet: checkValues called.\n");

    
    
  
};

#include "dlc_register.h"
DLC_Register_Macro(CheckerHandleValuePairSet);
