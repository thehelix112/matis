// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerBoolean.cpp,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.5 $

#include "MATIS_CheckerBoolean.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
CheckerBoolean::CheckerBoolean(){
    
};

//Default Destructor
CheckerBoolean::~CheckerBoolean(void){
    
};

bool CheckerBoolean::checkValues(boost::any actionValue, std::string modelValue){
  
    LOGMSG(4, "CheckerBoolean: checkValues called.\n");
    
    RTI::Boolean actionBool;
            
    //cast the action's value appropriately
    try {
        
        actionBool = boost::any_cast < RTI::Boolean >( actionValue);

    } catch(const boost::bad_any_cast &){
    
        LOGWRN("Value provided by the Action is not a RTIBoolean.\n");
        return false;
        
    }
    
    bool modelBool = Types::stringToBool(modelValue);
    
    if(modelBool)
        return(actionBool == RTI::RTI_TRUE);
    else
        return(actionBool == RTI::RTI_FALSE);
  
};

#include "dlc_register.h"
DLC_Register_Macro(CheckerBoolean);
