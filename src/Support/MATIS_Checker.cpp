// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_Checker.cpp,v $
// CVS $Date: 2006/02/26 14:47:33 $
// CVS $Revision: 1.5 $

#include "MATIS_Checker.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"

using namespace MATIS;

Checker *Checker::defaultChecker = NULL;

//Default Constructor
Checker::Checker(){
    
};

//Default Destructor
Checker::~Checker(void){
    
};


//Get id class
std::string Checker::getId(){

    LOGMSG(5, "BEGIN Checker: " << id << " getting id\n");
    LOGMSG(5, "END Checker: " << id << " getting id\n");

};


//Set id class
void Checker::setId(std::string aId){

    LOGMSG(5, "BEGIN Checker: " << id << " setting id\n");

    LOGMSG(5, "END Checker: " << id << " setting id\n");

};

bool Checker::configure(xmlDoc* doc, xmlNode* cur) 
{
	LOGMSG(2, "No configuration method defined.\n");
	return true;
}

Checker *Checker::getDefaultChecker(){
    
    if(defaultChecker == NULL)
        defaultChecker = new Checker();
    
    return defaultChecker;
    
}

bool Checker::checkValues(boost::any actionValue, std::string modelValue){
    
    //determine what type the boost::any value is. based on this we
    //will cast the string value to be of the same type and use the ==
    //operator
    
    if(Types::isBoostPrimitive(actionValue)){
        
        switch(Types::getBoostTypeAsValueType(actionValue)){            

        case TYPE_STRING:
            LOGMSG(5, "    action Value: " << Types::boostToString(actionValue) << "\n" <<
                      "    model  Value: " << modelValue << "\n");
            return (Types::boostToString(actionValue) == modelValue);
            break;
        case TYPE_INT:
            return (Types::boostToInt(actionValue) == Types::stringToInt(modelValue));
            break;
        case TYPE_LONG:
            return (Types::boostToLong(actionValue) == Types::stringToLong(modelValue));
            break;
        case TYPE_SHORT:
            return (Types::boostToShort(actionValue) == Types::stringToShort(modelValue));
            break;
        case TYPE_UNSIGNEDINT:
            return (Types::boostToUnsignedInt(actionValue) == Types::stringToUnsignedInt(modelValue));
            break;
        case TYPE_UNSIGNEDLONG:
            LOGMSG(4, "    action value: " << Types::boostToUnsignedLong(actionValue) << "\n" <<
                   "    model  value: " << Types::stringToUnsignedLong(modelValue) << "\n");
            LOGMSG(4, "    bool: " << (Types::boostToUnsignedLong(actionValue) == Types::stringToUnsignedLong(modelValue)) << "\n");
            return (Types::boostToUnsignedLong(actionValue) == Types::stringToUnsignedLong(modelValue));
            break;
        case TYPE_UNSIGNEDSHORT:
            return (Types::boostToUnsignedShort(actionValue) == Types::stringToUnsignedShort(modelValue));
            break;
        case TYPE_SIGNEDINT:
            return (Types::boostToSignedInt(actionValue) == Types::stringToSignedInt(modelValue));
            break;
        case TYPE_SIGNEDLONG:
            return (Types::boostToSignedLong(actionValue) == Types::stringToSignedLong(modelValue));
            break;
        case TYPE_SIGNEDSHORT:
            return (Types::boostToSignedShort(actionValue) == Types::stringToSignedShort(modelValue));
            break;
        case TYPE_DOUBLE:
            return (Types::boostToDouble(actionValue) == Types::stringToDouble(modelValue));
            break;
        case TYPE_FLOAT:
            return (Types::boostToFloat(actionValue) == Types::stringToDouble(modelValue));
            break;
        case TYPE_CHAR:
            return (Types::boostToChar(actionValue) == Types::stringToChar(modelValue));
            break;
        case TYPE_SIGNEDCHAR:
            return (Types::boostToSignedChar(actionValue) == Types::stringToSignedChar(modelValue));
            break;
        case TYPE_UNSIGNEDCHAR:
            return (Types::boostToUnsignedChar(actionValue) == Types::stringToUnsignedChar(modelValue));
            break;
        case TYPE_BOOL:
            return (Types::boostToBool(actionValue) == Types::stringToBool(modelValue));
            break;

        default:
            LOGWRN("Value type is reported as primitive but doesn't match any.");
            return false;
            
        }
        
    } else {
        
        LOGWRN("Default checker called on non-primitive values (model value: " << modelValue << "(as string)");
        return false;
        
    }
    
}
