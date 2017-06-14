// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_TypesConvenienceMethods.h,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.7 $

#ifndef MATIS_TYPESCONVENIENCE_H
#define MATIS_TYPESCONVENIENCE_H 1

namespace MATIS {

    class Types {
    public:

        static std::string trimWhiteSpace(std::string aString){
            std::stringstream astream, bstream;
            char* bString;
            astream << aString;
            astream >> std::ws >> bString;
            return std::string(bString);
        };

        //Lexical cast convenience methods
        static double stringToDouble(std::string aString){
            std::stringstream astream;
            astream << aString;
            double retval;
            astream >> std::dec >> retval;
            return retval;
        };
        
        static int stringToInt(std::string aString){
            std::stringstream astream;
            astream << aString;
            int retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static long stringToLong(std::string aString){
            std::stringstream astream;
            astream << aString;
            long retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static short stringToShort(std::string aString){
            std::stringstream astream;
            astream << aString;
            short retval;
            astream >> std::dec >> retval;
            return retval;
        };
        static unsigned int stringToUnsignedInt(std::string aString){
            std::stringstream astream;
            astream << aString;
            unsigned int retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static handleType stringToHandleType(std::string aString){
            return stringToUnsignedLong(aString);
        };
        
        static unsigned long stringToUnsignedLong(std::string aString){
            std::stringstream astream;
            astream << aString;
            unsigned long retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static unsigned short stringToUnsignedShort(std::string aString){
            std::stringstream astream;
            astream << aString;
            unsigned short retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static signed int stringToSignedInt(std::string aString){
            std::stringstream astream;
            astream << aString;
            signed int retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static signed long stringToSignedLong(std::string aString){
            std::stringstream astream;
            astream << aString;
            signed long retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static signed short stringToSignedShort(std::string aString){
            std::stringstream astream;
            astream << aString;
            signed short retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static float stringToFloat(std::string aString){
            std::stringstream astream;
            astream << aString;
            float retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static char stringToChar(std::string aString){
            std::stringstream astream;
            astream << aString;
            char retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static unsigned char stringToUnsignedChar(std::string aString){
            std::stringstream astream;
            astream << aString;
            unsigned char retval;
            astream >> std::dec >> retval;
            return retval;
        };

        static signed char stringToSignedChar(std::string aString){
            std::stringstream astream;
            astream << aString;
            signed char retval;
            astream >> std::dec >> retval;
            return retval;
        };

        //default return value is false!
        static bool stringToBool(std::string aString){
            std::stringstream astream;
            astream << aString;
            bool retval = false;
            astream >> retval;
            return retval;
        };
        
        static std::string intToString(int aInt){
            std::stringstream astream;
            astream << aInt;
            return astream.str();
        };
        
        static std::string doubleToString(double aDouble){
            std::stringstream astream;
            astream << aDouble;
            return astream.str();
        };

        static std::string longToString(long aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string shortToString(short aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };
        static std::string unsignedIntToString(unsigned int aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string handleTypeToString(handleType aVal){
            return unsignedLongToString(aVal);
        };
            
        static std::string unsignedLongToString(unsigned long aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string unsignedShortToString(unsigned short aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string signedIntToString(signed int aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string signedLongToString(signed long aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string signedShortToString(signed short aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string floatToString(float aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string charToString(char aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string unsignedCharToString(unsigned char aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string signedCharToString(signed char aVal){
            std::stringstream astream;
            astream << aVal;
            return astream.str();
        };

        static std::string boolToString(bool aBool){
            std::stringstream astream;
            astream << aBool;
            return astream.str();
        };
   
        //Boost library convenience methods
        static bool isBoostInt(boost::any a){
            return (a.type() == typeid(int));
        };
        static int boostToInt(boost::any a){
            if(isBoostInt(a))
                return boost::any_cast<int>(a);
            else
                LOGWRN("Boost is not an int!");
        };
        static bool isBoostUnsignedInt(boost::any a){
            return (a.type() == typeid(unsigned int));
        };
        static unsigned int boostToUnsignedInt(boost::any a){
            if(isBoostUnsignedInt(a))
                return boost::any_cast<unsigned int>(a);
            else
                LOGWRN("Boost is not an unsigned int!");
        };
        static bool isBoostSignedInt(boost::any a){
            return (a.type() == typeid(signed int));
        };
        static signed int boostToSignedInt(boost::any a){
            if(isBoostSignedInt(a))
                return boost::any_cast<signed int>(a);
            else
                LOGWRN("Boost is not a signed int!");
        };
        static bool isBoostLong(boost::any a){
            return (a.type() == typeid(long int));
        };
        static long boostToLong(boost::any a){
            if(isBoostLong(a))
                return boost::any_cast<long>(a);
            else
                LOGWRN("Boost is not a long!");
        };        
        static bool isBoostUnsignedLong(boost::any a){
            return (a.type() == typeid(unsigned long));
        };
        static unsigned long boostToUnsignedLong(boost::any a){
            if(isBoostUnsignedLong(a))
                return boost::any_cast<unsigned long>(a);
            else
                LOGWRN("Boost is not an unsigned long!");
        };
        static bool isBoostSignedLong(boost::any a){
            return (a.type() == typeid(signed long));
        };
        static signed long boostToSignedLong(boost::any a){
            if(isBoostSignedLong(a))
                return boost::any_cast<signed long>(a);
            else
                LOGWRN("Boost is not a signed long!");
        };
        static bool isBoostShort(boost::any a){
            return (a.type() == typeid(short int));
        };
        static short boostToShort(boost::any a){
            if(isBoostShort(a))
                return boost::any_cast<short>(a);
            else
                LOGWRN("Boost is not a short!");
        };
        static bool isBoostUnsignedShort(boost::any a){
            return (a.type() == typeid(unsigned short int));
        };
        static unsigned short boostToUnsignedShort(boost::any a){
            if(isBoostUnsignedShort(a))
                return boost::any_cast<unsigned short>(a);
            else
                LOGWRN("Boost is not an unsigned short!");
        };
        static bool isBoostSignedShort(boost::any a){
            return (a.type() == typeid(signed short int));
        };
        static signed short boostToSignedShort(boost::any a){
            if(isBoostSignedShort(a))
                return boost::any_cast<signed short>(a);
            else
                LOGWRN("Boost is not a signed short!");
        };
        static bool isBoostChar(boost::any a){
            return (a.type() == typeid(char));
        };
        static char boostToChar(boost::any a){
            if(isBoostChar(a))
                return boost::any_cast<char>(a);
            else
                LOGWRN("Boost is not a char!");
        };
        static bool isBoostSignedChar(boost::any a){
            return (a.type() == typeid(signed char));
        };
        static signed char boostToSignedChar(boost::any a){
            if(isBoostSignedChar(a))
                return boost::any_cast<signed char>(a);
            else
                LOGWRN("Boost is not a signed char!");
        };
        static bool isBoostUnsignedChar(boost::any a){
            return (a.type() == typeid(unsigned char));
        };
        static unsigned char boostToUnsignedChar(boost::any a){
            if(isBoostUnsignedChar(a))
                return boost::any_cast<unsigned char>(a);
            else
                LOGWRN("Boost is not an unsigned char!");
        };
        static bool isBoostDouble(boost::any a){
            return (a.type() == typeid(double));
        };
        static double boostToDouble(boost::any a){
            if(isBoostDouble(a))
                return boost::any_cast<double>(a);
            else
                LOGWRN("Boost is not a double!");
        };
        static bool isBoostFloat(boost::any a){
            return (a.type() == typeid(float));
        };
        static float boostToFloat(boost::any a){
            if(isBoostFloat(a))
                return boost::any_cast<float>(a);
            else
                LOGWRN("Boost is not a float!");
        };
        static bool isBoostPointer(boost::any a){
            return (a.type() == typeid(void *));
        };
        static bool isBoostString(boost::any a){
            return (a.type() == typeid(std::string));
        };
        static std::string boostToString(boost::any a){
            if(isBoostString(a))
                return boost::any_cast<std::string>(a);
            else
                LOGWRN("Boost is not a string!");
        };
        static bool isBoostBool(boost::any a){
            return (a.type() == typeid(bool));
        };
        static bool boostToBool(boost::any a){
            if(isBoostBool(a))
                return boost::any_cast<bool>(a);
            else
                LOGWRN("Boost is not an bool!");
        };
        static bool isBoostPrimitive(boost::any a){
            if(isBoostInt(a)) return true;
            if(isBoostUnsignedInt(a)) return true;
            if(isBoostSignedInt(a)) return true;
            if(isBoostLong(a)) return true;
            if(isBoostUnsignedLong(a)) return true;
            if(isBoostSignedLong(a)) return true;
            if(isBoostShort(a)) return true;
            if(isBoostUnsignedShort(a)) return true;
            if(isBoostSignedShort(a)) return true;
            if(isBoostChar(a)) return true;
            if(isBoostSignedChar(a)) return true;
            if(isBoostUnsignedChar(a)) return true;
            if(isBoostDouble(a)) return true;
            if(isBoostFloat(a)) return true;
            if(isBoostString(a)) return true;
            if(isBoostBool(a)) return true;
            return false;
        };
        
        static ValueType getBoostTypeAsValueType(boost::any a){
            
            if(isBoostInt(a)) return TYPE_INT;
            if(isBoostUnsignedInt(a)) return TYPE_UNSIGNEDINT;
            if(isBoostSignedInt(a)) return TYPE_SIGNEDINT;
            if(isBoostLong(a)) return TYPE_LONG;
            if(isBoostUnsignedLong(a)) return TYPE_UNSIGNEDLONG;
            if(isBoostSignedLong(a)) return TYPE_SIGNEDLONG;
            if(isBoostShort(a)) return TYPE_SHORT;
            if(isBoostUnsignedShort(a)) return TYPE_UNSIGNEDSHORT;
            if(isBoostSignedShort(a)) return TYPE_SIGNEDSHORT;
            if(isBoostChar(a)) return TYPE_CHAR;
            if(isBoostSignedChar(a)) return TYPE_SIGNEDCHAR;
            if(isBoostUnsignedChar(a)) return TYPE_UNSIGNEDCHAR;
            if(isBoostDouble(a)) return TYPE_DOUBLE;
            if(isBoostFloat(a)) return TYPE_FLOAT;
            if(isBoostPointer(a)) return TYPE_POINTER;
            if(isBoostString(a)) return TYPE_STRING;
            if(isBoostBool(a)) return TYPE_BOOL;
            return TYPE_CUSTOM;
            
        }

        //APIParameter ValueTypes Methods
        static APIValueType stringToAPIValueType(std::string aString){
            cistring aCIString = cistring(aString.c_str());
            if(aCIString == "null")
                return TYPE_NULL;
            if(aCIString == "string")
                return TYPE_STRING;
            if(aCIString == "int")
                return TYPE_INT;
            if(aCIString == "long")
                return TYPE_LONG;
            if(aCIString == "short")
                return TYPE_SHORT;
            if(aCIString == "unsignedint")
                return TYPE_UNSIGNEDINT;
            if(aCIString == "unsignedlong")
                return TYPE_UNSIGNEDLONG;
            if(aCIString == "unsignedshort")
                return TYPE_UNSIGNEDSHORT;
            if(aCIString == "signedint")
                return TYPE_SIGNEDINT;
            if(aCIString == "signedlong")
                return TYPE_SIGNEDLONG;
            if(aCIString == "signedshort")
                return TYPE_SIGNEDSHORT;
            if(aCIString == "double")
                return TYPE_DOUBLE;
            if(aCIString == "float")
                return TYPE_FLOAT;
            if(aCIString == "char")
                return TYPE_CHAR;
            if(aCIString == "signedchar")
                return TYPE_SIGNEDCHAR;
            if(aCIString == "unsignedchar")
                return TYPE_UNSIGNEDCHAR;
            if(aCIString == "pointer")
                return TYPE_POINTER;
            if(aCIString == "bool")
                return TYPE_BOOL;            

            return TYPE_CUSTOM;
        };

        static ValueType stringToValueType(std::string aString){
            return stringToAPIValueType(aString);
        };          

        static std::string APIValueTypeToString(APIValueType aValueType){
            switch(aValueType){
            case TYPE_NULL:
                return "null";
            case TYPE_STRING:
                return "string";
            case TYPE_INT:
                return "int";
            case TYPE_LONG:
                return "long";
            case TYPE_SHORT:
                return "short";
            case TYPE_UNSIGNEDINT:
                return "unsignedint";
            case TYPE_UNSIGNEDLONG:
                return "unsignedlong";
            case TYPE_UNSIGNEDSHORT:
                return "unsignedshort";
            case TYPE_SIGNEDINT:
                return "signedint";
            case TYPE_SIGNEDLONG:
                return "signedlong";
            case TYPE_SIGNEDSHORT:
                return "signedshort";
            case TYPE_DOUBLE:
                return "double";
            case TYPE_FLOAT:
                return "float";
            case TYPE_CHAR:
                return "char";
            case TYPE_SIGNEDCHAR:
                return "signedchar";
            case TYPE_UNSIGNEDCHAR:
                return "unsignedchar";
            case TYPE_POINTER:
                return "pointer";
            case TYPE_BOOL:
                return "bool";
            case TYPE_CUSTOM:
                return "custom";
            }
        };

        static std::string ValueTypeToString(ValueType aValueType){
            return APIValueTypeToString(aValueType);
        };
            
        
        //LAEMethod FlagTypes Methods
        static LAEMethodFlagType stringToLAEMethodFlagType(std::string aString){
            cistring aCIString = cistring(aString.c_str());
            if(aCIString == "null")
                return FLAG_NULL;
            if(aCIString == "constructor")
                return FLAG_CONSTRUCTOR;
            if(aCIString == "destructor")
                return FLAG_DESTRUCTOR;
        };

        static std::string LAEMethodFlagTypeToString(LAEMethodFlagType aFlagType){
            switch(aFlagType){
            case FLAG_NULL:
                return "null";
            case FLAG_CONSTRUCTOR:
                return "constructor";
            case FLAG_DESTRUCTOR:
                return "destructor";
            }
        };

        //LAEProperty actionStoage Methods
        static actionStorageCategoryType stringToActionStorageCategoryType(std::string aString){
            cistring aCIString = cistring(aString.c_str());
            if(aCIString == "null")
                return STORAGE_NULL;
            if(aCIString == "actionhandle")
                return STORAGE_ACTIONHANDLE;
            if(aCIString == "hs")
                return STORAGE_HS;
            if(aCIString == "hs2")
                return STORAGE_HS2;
            if(aCIString == "hvps")
                return STORAGE_HVPS;
            if(aCIString == "hvps2")
                return STORAGE_HVPS2;
            if(aCIString == "rs")
                return STORAGE_RS;

            return STORAGE_ACTIONHANDLE;


        };

        static std::string actionStorageCategoryTypeToString(actionStorageCategoryType aFlagType){
            switch(aFlagType){
            case STORAGE_NULL:
                return "null";
            case STORAGE_ACTIONHANDLE:
                return "actionhandle";
            case STORAGE_HS:
                return "hs";
            case STORAGE_HS2:
                return "hs2";
            case STORAGE_HVPS:
                return "hvps";
            case STORAGE_HVPS2:
                return "hvps2";
            case STORAGE_RS:
                return "rs";
            default:
                return "actionhandle";
            }
        };

        //LAEEntry EntryType Methos
        static entryTypeType stringToEntryTypeType(std::string aString){
            cistring aCIString = cistring(aString.c_str());
            if(aCIString == "null")
                return ENTRYTYPE_NULL;
            if(aCIString == "method")
                return ENTRYTYPE_METHOD;
            if(aCIString == "methodgroup")
                return ENTRYTYPE_METHODGROUP;
            if(aCIString == "object")
                return ENTRYTYPE_OBJECT;
        };

        static std::string entryTypeTypeToString(entryTypeType aFlagType){
            switch(aFlagType){
            case ENTRYTYPE_NULL:
                return "null";
            case ENTRYTYPE_METHOD:
                return "method";
            case ENTRYTYPE_METHODGROUP:
                return "methodgroup";
            case ENTRYTYPE_OBJECT:
                return "object";
            }
        };


        /*
        //ValueTypeTypeType Methods
        static valueTypeTypeType stringToValueTypeTypeType(std::string aString){
            cistring aCIString = cistring(aString.c_str());
            if(aCIString == "null")
                return VALUETYPE_NULL;
            if(aCIString == "custom")
                return VALUETYPE_CUSTOM;

        };

        static std::string valueTypeTypeTypeToString(valueTypeTypeType aFlagType){
            switch(aFlagType){
            case VALUETYPE_NULL:
                return "null";
            case VALUETYPE_CUSTOM:
                return "custom";
            }
        };
        */

        //LAEPathway Destination Type Methods
        static pathwayDestinationTypeType stringToDestinationTypeType(std::string aString){
            cistring aCIString = cistring(aString.c_str());
            if(aCIString == "null")
                return DESTINATIONTYPE_NULL;
            if(aCIString == "laeinteraction")
                return DESTINATIONTYPE_LAEINTERACTION;
            if(aCIString == "unordered")
                return DESTINATIONTYPE_UNORDEREDGROUP;
            if(aCIString == "exit")
                return DESTINATIONTYPE_EXIT;

        };

        static std::string destinationTypeTypeToString(pathwayDestinationTypeType aFlagType){
            switch(aFlagType){
            case DESTINATIONTYPE_NULL:
                return "null";
            case DESTINATIONTYPE_LAEINTERACTION:
                return "laeinteraction";
            case DESTINATIONTYPE_UNORDEREDGROUP:
                return "unordered";
            case DESTINATIONTYPE_EXIT:
                return "exit";

            }
        };

        //LAEMethodStageType Methods
        static LAEMethodStageType stringToLAEMethodStageType(std::string aString){
            cistring aCIString = cistring(aString.c_str());
            if(aCIString == "null")
                return STAGE_NULL;
            if(aCIString == "end")
                return STAGE_END;
        };

        static std::string LAEMethodStageTypeToString(LAEMethodStageType aStageType){
            switch(aStageType){
            case STAGE_NULL:
                return "null";
            case STAGE_END:
                return "end";
            }
        };

        static std::string replaceString(std::string wholeStr, 
                                         std::string queryStr,
                                         std::string replacementStr){
            
            //get the id and search for it in the data of this property set
            std::string::size_type startPos = wholeStr.find(queryStr, 0);
            std::string::size_type size = queryStr.length();
            if(startPos != std::string::npos){

                wholeStr.replace(startPos, size, replacementStr);       
                
            }

            return wholeStr;
            
        };

        static std::string replaceCIString(std::string wholeStr, 
                                           std::string queryStr,
                                           std::string replacementStr){
   
            return replaceString(Types::stringToUpper(wholeStr),
                                 Types::stringToUpper(queryStr),
                                 Types::stringToUpper(replacementStr));
            
        };

        static std::string stringToUpper(std::string astring)
        {
            char astringbuf[astring.length()];
            for(size_t i = 0; i < astring.length(); ++i){
                astringbuf[i] = toupper(astring[i]);
            }
            return std::string(astringbuf, astring.length());
        };
        
    };
    
}

#endif                          // MATIS_TYPESCONVENICNE_H
