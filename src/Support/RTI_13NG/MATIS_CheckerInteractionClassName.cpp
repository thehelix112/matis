// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerInteractionClassName.cpp,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.4 $

#include "MATIS_CheckerInteractionClassName.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
CheckerInteractionClassName::CheckerInteractionClassName(){
    
};

//Default Destructor
CheckerInteractionClassName::~CheckerInteractionClassName(void){
    
};

bool CheckerInteractionClassName::checkValues(boost::any actionValue, std::string modelValue){
  
    LOGMSG(4, "CheckerInteractionClassName: checkValues called.\n");
    
    std::string actionStr;
            
    //cast the action's value appropriately
    try {
        
        actionStr = boost::any_cast < std::string >( actionValue);

    } catch(const boost::bad_any_cast &){
    
        LOGWRN("Value provided by the Action is not a RTI InteractionClassName.\n");
        return false;
        
    }

    //try with and without `interactionroot.' prefix
    //strip the prefix from both then compare.
    actionStr = Types::replaceCIString(actionStr, "interactionroot.", "");
    modelValue = Types::replaceCIString(modelValue, "interactionroot.", "");
    
    return (actionStr == modelValue);
  
};

#include "dlc_register.h"
DLC_Register_Macro(CheckerInteractionClassName);
