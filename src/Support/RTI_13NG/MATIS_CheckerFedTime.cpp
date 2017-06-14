// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerFedTime.cpp,v $
// CVS $Date: 2006/01/16 13:41:04 $
// CVS $Revision: 1.4 $

#include "MATIS_CheckerFedTime.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

//Default Constructor
CheckerFedTime::CheckerFedTime(){

    usageString = "CheckerFedTime Model Value Specification Usage: VALUETYPE:VALUE

VALUETYPE can be:

  VAL               indicates a single value is represented.  In this
                    case VALUE should be the digits of the federation
                    time to be represented. 

                    Examples:
                      10         Federation time of 10.
                      1.14       Federation time of 1.14.
                                         

  RAN               indicates a range of values are represented.   In
                    this case VALUE is of the format:

                      LOWERBOUND LOWERVALUE - UPPERVALUE UPPERBOUND

                      LOWERBOUND and UPPERBOUND are a matching pair
                      of either:

                        Parentheses: ( ) indicating the LOWERVALUE
                        and UPPERVALUE values are inclusive.

                        or

                        Square brackets: [ ] indicating the LOWERVALUE
                        and UPPERVALUE values are exclusive.
                        
                      Both LOWERVALUE and UPPERVALUE can be either
                      digits representing federation times, or special
                      strings with meanings:

                        INF      Infinite value

                    Examples:
                     (1-14)      Federation times from 1 through to 14 
                                 inclusive.
                     [0-INF]     Federation times greater than 0 to
                                 infinity.

  
  SET               indicates a discrete set of values is represented.
                    In this case VALUE specifies this set as digits
                    representing federation times seperated by commas.

                    Examples:
                     1,4,8       Federate times 1, 4 and 8.";

};

//Default Destructor
CheckerFedTime::~CheckerFedTime(void){
    
};

bool CheckerFedTime::checkValues(boost::any actionValue, std::string modelValue){
  
    LOGMSG(4, "CheckerFedTime: checkValues called.\n");

    RTIfedTime actionTime;
            
    //cast the action's value appropriately
    try {
        
        actionTime = boost::any_cast < RTIfedTime >( actionValue);

    } catch(const boost::bad_any_cast &){
    
        LOGWRN("Value provided by the Action is not a RTIfedTime.\n");
        return false;
        
    }

    //extract the value from the model's string
    //  if `VAL:' initial characters then it is a hard value
    //  if `RAN:' initial characters then it is a range
    //    seperated by a `-' character
    boost::char_separator < char > sep(":-,", "[()]");
    tokeniserType tokens(modelValue, sep);

    tokeniserType::iterator it = tokens.begin();

    if(*it == "VAL"){
        //value
        LOGMSG(4, "Model has a single VALue.\n");
        
        //next token specifies the value
        return checkSingleValue(tokens, actionTime);

    } else if(*it == "RAN"){
        //range
        LOGMSG(4, "Model has a RANge of values.\n");

        return checkRangeValues(tokens, actionTime);

    } else if(*it == "SET"){
        //set
        LOGMSG(4, "Model has a SET of values.\n");

        return checkSetValues(tokens, actionTime);

    } else {

        LOGWRN("\nModel specified value: " << modelValue << " invalid!\n");
        LOGWRN("\n" << usageString << "\n");
        return false;

    }
  
};

bool CheckerFedTime::checkSingleValue(tokeniserType tokens, RTIfedTime aActionTime){

    tokeniserType::iterator it = tokens.begin();
    ++it;

    const RTIfedTime modelTime(Types::stringToDouble(*it));
    
    try{
        
        LOGMSG(4, "Checking action time: " << aActionTime.getTime() 
               << " with model time: " << modelTime.getTime() << "\n");
        
        
        return(aActionTime == modelTime);

    } catch(RTI::InvalidFederationTime){

        LOGWRN("Invalid Federation Time comparison requested: " << aActionTime.getTime() 
               << " == " << modelTime.getTime() << "\n");
        return false;
        
    }
    
}

bool CheckerFedTime::checkRangeValues(tokeniserType tokens, RTIfedTime aActionTime){

    RTIfedTime lowerTime, upperTime;
    bool lowerInclusive = false, 
        upperInclusive = false, 
        matchesLower = false, 
        matchesUpper = false;
    tokeniserType::iterator it = tokens.begin();

    unsigned int count = 0;
    std::string modelString;
    for(; it != tokens.end(); ++it){
        ++count;
        modelString+=(*it);
    }
    
    if(count < 4){
        LOGWRN("Invalid model value specified: " << modelString << "\n");
        return false;
    }    
    
    //tokens go, lower range boundary then value, upper range value then boundary
    it = tokens.begin();
    ++it;
    lowerInclusive = ((*it) == "(");
    
    ++it;
    if(*it == "INF"){
        LOGWRN("Lower time value specified as inifinite. Invalid.\n");
        return false;
    } else {
        lowerTime = RTIfedTime(Types::stringToDouble(*it));
    }
    
    ++it;
    if(*it == "INF"){
        //gaurunteed to be smaller than infinite.
        matchesUpper = true;
    } else {
        upperTime = RTIfedTime(Types::stringToDouble(*it));
    }

    ++it;
    upperInclusive = ((*it) == ")");

    if((++it) != tokens.end()){
   
        LOGMSG(4, "Spurious tokens in model value: ");

        for(;it != tokens.end(); ++it){
            
            LOGMSG(4, (*it));
            
        }

        LOGMSG(4, "  ignored.\n");
        
    }

    
    try{

        if(lowerInclusive){

            LOGMSG(4, "Checking action Time: " << aActionTime.getTime() 
                   << " >= lower time: " << lowerTime.getTime() << "\n");
            
            matchesLower = (aActionTime >= lowerTime);
            
        } else {

            LOGMSG(4, "Checking action Time: " << aActionTime.getTime() 
                   << " > lower time: " << lowerTime.getTime() << "\n");

            matchesLower = (aActionTime > lowerTime);

        }        

        if(!matchesUpper){
            
            if(upperInclusive){

            LOGMSG(4, "Checking action Time: " << aActionTime.getTime() 
                   << " < upper time: " << upperTime.getTime() << "\n");
                
                matchesUpper = (aActionTime <= upperTime);
                
            } else {

            LOGMSG(4, "Checking action Time: " << aActionTime.getTime() 
                   << " <= upper time: " << upperTime.getTime() << "\n");
                
                matchesUpper = (aActionTime < upperTime);
                
            }

        }

        return (matchesLower && matchesUpper);

    } catch(RTI::InvalidFederationTime){

        LOGWRN("Invalid Federation Time comparison requested with action time: " << 
               aActionTime.getTime() << "\n");
        return false;

    }
   
}

bool CheckerFedTime::checkSetValues(tokeniserType tokens, RTIfedTime aActionTime){
    
    //next tokens are set
    tokeniserType::iterator it = tokens.begin();
    ++it;

    for(; it != tokens.end(); ++it){
     
        RTIfedTime aSetTime(Types::stringToDouble(*it));
    
        try{

            LOGMSG(4, "Checking actionTime: " << aActionTime.getTime() 
                   << " with set time: " << aSetTime.getTime() << "\n");

            if(aSetTime == aActionTime)
                return true;
            
        } catch(RTI::InvalidFederationTime){
            
            LOGWRN("Invalid Federation Time comparison requested: " << aActionTime.getTime() 
                   << " == " << aSetTime.getTime() << "\n");
            return false;
            
        }
        
    }

    return false;

}

#include "dlc_register.h"
DLC_Register_Macro(CheckerFedTime);
