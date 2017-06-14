// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerHandleSet.cpp,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.2 $

#include "MATIS_CheckerHandleSet.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
CheckerHandleSet::CheckerHandleSet(){
    
};

//Default Destructor
CheckerHandleSet::~CheckerHandleSet(void){
    
};

bool CheckerHandleSet::checkValues(boost::any actionValue, std::string modelValue){
  
    LOGMSG(4, "  CheckerHandleSet: checkValues called.\n");

    //create a list of each value in the RTI::HandleSet from the Action
    handleSetType actionHandleSet;
            
    //cast the action's value appropriately
    try {
        
        actionHandleSet = boost::any_cast < handleSetType >(actionValue);

    } catch(const boost::bad_any_cast &){
    
        LOGWRN("    Value provided by the Action is not a handleSetType.\n");
        return false;
        
    }

    LOGMSG(4, "model value'" << modelValue << "'\n");

    //compare this with the model values which are comma seperated.
    boost::char_separator < char > sep("|");
    tokeniserType tokens(modelValue, sep);

    tokeniserType::iterator it = tokens.begin();
    
    //go through each model value and see if it is in the handleSet
    //if it is remove it, then we can see if there are any left over at the end
    for(; it != tokens.end(); ++it){

        //std::string modelString = Types::trimWhiteSpace(*it);
        //need a proper method for triming whitespace, until this this will do.
        std::string modelString = (*it);

        //bool found = false;

        for(handleSetType::iterator iq = actionHandleSet.begin();
            iq != actionHandleSet.end();
            ++iq){
         
            if((*iq) == Types::stringToInt(modelString)){

                LOGMSG(4, "    model value: '" << modelString << "' matches actionHandleSet.\n");

                //found = true;
                actionHandleSet.erase(*iq);
                break;
                
            }
            
        }

        /* We can't do this as this as the single propertyset whose value this checks
           can be called multiple times for each 

        if(!found){   
            
            //this shouldn't be here. should after checking all handles
            LOGMSG(4, "    model value: " << (*it) << " not found in actions HandleSet.\n");
            return false;
            
            }*/
        
    }

    if(actionHandleSet.size() > 0){
     
        LOGMSG(4, "    actions HandleSet has values not matched by the model: ");

        for(handleSetType::iterator iq = actionHandleSet.begin();
            iq != actionHandleSet.end();
            ++iq){
            LOGMSG(4, (*iq) << " ");
        }
        
        LOGMSG(4, "\n");
        
        return false;
        
    } else {
        
        return true;
        
    } 
  
};

#include "dlc_register.h"
DLC_Register_Macro(CheckerHandleSet);
