// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerRegion.cpp,v $
// CVS $Date: 2006/01/05 14:08:39 $
// CVS $Revision: 1.2 $

#include "MATIS_CheckerRegion.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
CheckerRegion::CheckerRegion(){
    
};

//Default Destructor
CheckerRegion::~CheckerRegion(void){
    
};

bool CheckerRegion::checkValues(boost::any actionValue, std::string modelValue){
  
    LOGMSG(4, "CheckerRegion: checkValues called.\n");
    
  
};

#include "dlc_register.h"
DLC_Register_Macro(CheckerRegion);
