// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_Types.h,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.9 $

#ifndef MATIS_TYPES_H
#define MATIS_TYPES_H 1

//Include RTI headers
#include "fedtime.hh"
#include "RTI.hh"

//Include STL headers
#include <map>
#include <deque>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <list>
#include <fstream>

//Include XML library header
#include <libxml/parser.h>

//Include Boost headers
#include "boost/any.hpp"
#include "boost/lexical_cast.hpp"
#include "boost/config.hpp"
#include "boost/graph/adjacency_list.hpp"
#include "boost/tokenizer.hpp"

//Include Matis macros
#include "MATIS_Macros.h"

//Include case insensitive string
#include "cistring.h"

#define MAX_LAEMETHODSTAGES 100000
#define DEFAULT_CONFIG_LOCATION "./matis.xml"

//Global type definitions
typedef unsigned long handleType;

//RTI types
typedef std::map < handleType, boost::any > handleValuePairSetType;
typedef std::set < handleType > handleSetType;
typedef std::set < RTI::Region* > regionSetType;

//Configuration System types
typedef std::map < cistring, cistring > parameterValueMapType;
typedef std::pair < cistring, cistring > parameterValueType;
typedef std::list < cistring > stringListType;
typedef std::list < double > doubleListType;

typedef std::map < handleType, std::string > mapPropertyValueType;
typedef std::map < handleType, unsigned int > mapGroupCompletedType;

namespace MATIS {

    /**
     * Types: define all the different types used by Matis.
     */

    using namespace boost;

    //General types
    typedef std::list < handleType > handleListType;
    typedef std::vector < handleType > handleVectorType;

    //Channel types
    typedef std::multimap < long int, handleType > ptrHandleType;


    typedef enum {

        OBJECT_NULL = 0,
        OBJECT_APIEXCEPTION,
        OBJECT_APIGROUP,
        OBJECT_APIMETHOD,
        OBJECT_APIPARAMETER,
        OBJECT_APIRETURN,
        OBJECT_APIVARIABLE,
        OBJECT_LAECHECKER,
        OBJECT_LAECLASS,
        OBJECT_LAEFUNCTION,
        OBJECT_LAEMETHOD,
        OBJECT_LAEUNRESTRICTED,
        OBJECT_LAEMETHODSTAGE,
        OBJECT_LAEMETHODSTAGEPROGRESSION,
        OBJECT_LAEPOLICY,
        OBJECT_LAEPROPERTY,
        OBJECT_LAEPROPERTYREFERENCE,
        OBJECT_LAEPROPERTYSOURCE,
        OBJECT_LAEREQUIREMENT,
        OBJECT_LAESET,
        OBJECT_LAETRIGGER,
        OBJECT_LAEVALUEGROUP,
        OBJECT_LAEVALUETYPE,
        //////////
        OBJECT_LEAPBM,
        OBJECT_LEAPBMENTRY,
        OBJECT_LEAPBMEXCEPTION,
        OBJECT_LEAPBMEXIT,
        OBJECT_LEAPBMFILE,
        OBJECT_LEAPBMGROUP,
        OBJECT_LEAPBMHOST,
        OBJECT_LEAPBMLAE,
        OBJECT_LEAPBMLAEINTERACTION,
        OBJECT_LEAPBMLAETERM,
        OBJECT_LEAPBMMETHOD,
        OBJECT_LEAPBMMETHODCALL,
        OBJECT_LEAPBMPATHWAY,
        OBJECT_LEAPBMPROCESS,
        OBJECT_LEAPBMPROCESSFILE,
        OBJECT_LEAPBMPROCESSHOST,
        OBJECT_LEAPBMPROCESSMETHOD,
        OBJECT_LEAPBMPROPERTYSET,
        OBJECT_LEAPBMUNORDERED,
        OBJECT_LEAPBMVALUEREFERENCE,

    } objectType;
    

    //API Method Types
    //==============================
    typedef enum {
            
        TYPE_NULL = 0,
        TYPE_STRING,
        TYPE_INT,
        TYPE_LONG,
        TYPE_SHORT,
        TYPE_UNSIGNEDINT,
        TYPE_UNSIGNEDLONG,
        TYPE_UNSIGNEDSHORT,
        TYPE_SIGNEDINT,
        TYPE_SIGNEDLONG,
        TYPE_SIGNEDSHORT,
        TYPE_DOUBLE,
        TYPE_FLOAT,
        TYPE_CHAR,
        TYPE_SIGNEDCHAR,
        TYPE_UNSIGNEDCHAR,
        TYPE_POINTER,
        TYPE_BOOL,
        TYPE_CUSTOM, //generic to allow for anything else (e.g object types)
            
    } APIValueType;

    typedef APIValueType ValueType;

    //LAE Method Types
    //==============================
//     struct vertexIndexT {
//         typedef vertex_property_tag kind;
//     };
//     struct vertexAPIMethodIdT {
//         typedef vertex_property_tag kind;
//     };
//     struct vertexStartT {
//         typedef vertex_property_tag kind;
//     };
    struct vertexHandleT {
        typedef vertex_property_tag kind;
    };

    struct edgeHandleT {
        typedef edge_property_tag kind;
    };

    /*typedef property < vertexStartT, bool > stageStartProperty;
    typedef property < vertexAPIMethodIdT, int, stageStartProperty> stageAPIMethodProperty;
    typedef property < vertexIndexT, std::string, stageAPIMethodProperty> stageProperty;*/
    typedef property < vertexHandleT, long int > stageHandleProperty;
    typedef property < edgeHandleT, long int > edgeHandleProperty;

    typedef adjacency_list < vecS, vecS, 
                             directedS, stageHandleProperty, 
                             edgeHandleProperty > graphLAEMethodStage;
    typedef graph_traits< graphLAEMethodStage >::vertex_descriptor vertexLAEMethodStage;
    typedef graph_traits< graphLAEMethodStage >::out_edge_iterator outEdgeIteratorLAEMethodStage;    
    typedef graph_traits< graphLAEMethodStage >::edge_descriptor edgeLAEMethodStage;
    typedef property_map< graphLAEMethodStage, vertexHandleT >::type propertyMapLAEMethodStage;
    typedef property_map< graphLAEMethodStage, edgeHandleT >::type mapEdgeApiExceptionsType;
    
    typedef std::map < std::string, vertexLAEMethodStage > mapStageIdVertexType;

    typedef enum {

        FLAG_NULL = 0,
        FLAG_CONSTRUCTOR,
        FLAG_DESTRUCTOR,
        
    } LAEMethodFlagType;

    typedef enum {

        STAGE_NULL = 0,
        STAGE_END,
        
    } LAEMethodStageType;
    
    
    //LAE Property Types
    //==============================

    
    //Unique Handle Factory Types
    typedef std::map < std::string, 
                       handleType > mapUniqueStringHandleType;

    // used for reverse lookups
    typedef std::multimap < handleType, 
                            std::string > mapHandleUniqueStringType;
        
    // used for forward lookups
    typedef std::deque < handleType > queueIDHandleType;

    //LAE Set Types
    //==============================
    typedef std::vector < std::string > vectorLAESetRequirementType;
    

    //LibHookup Types
    //==============================
    struct ltstr {
        bool operator()(const char* s1, const char* s2) const {
            return strcmp(s1, s2) < 0;
        }
    };
    typedef std::map < const char *,
                       std::string, ltstr > strHashType;
    typedef std::map < const char *,
                       unsigned short, ltstr > strUIntHashType;

    //LEAPBM Types
    //==============================
    typedef struct {

        std::string id;
        std::string filename;
        unsigned int filesize;
        std::string fullpath;

    } structLEAPBMSourceType;
    
    typedef struct {

        std::string type;
        std::string name;
        
    } structArgumentType;
    
    typedef struct {

        std::string returnType;
        std::string name;
        std::list < structArgumentType > arguments;
        
    } structFunctionType;

    typedef std::multimap < structLEAPBMSourceType,
                            structFunctionType > mapSourceFunctionType;
    

    //LEAPBMPoint Types
    //==============================
    typedef struct {

        std::string transitionId;
        std::string nextId;

    } structLEAPBMPointNextType;

    typedef std::vector < structLEAPBMPointNextType > vectorLEAPBMPointNextsType;
    

    //LEAPBMTime Types
    //==============================
    typedef enum {

        ENTRYTYPE_NULL = 0,
        ENTRYTYPE_METHOD,
        ENTRYTYPE_METHODGROUP,
        ENTRYTYPE_OBJECT,

    } entryTypeType;

    //LEAPBMLAE Types
    //==============================
    typedef struct {

        std::string methodId;
        std::string transitionId;

    } structLEAPBMLAECallType;

    typedef std::vector < structLEAPBMLAECallType > vectorLEAPBMLAECallsType;

    //LEAPBMValueType Types
    //==============================    

    /* Don't need this, use ValueType instead.
    typedef enum {

        VALUETYPE_NULL = 0,
        VALUETYPE_CUSTOM,

        } valueTypeTypeType;*/

    //LEAPBMPathWay Types
    //==============================    
    
    typedef enum {

        DESTINATIONTYPE_NULL = 0,
        DESTINATIONTYPE_LAEINTERACTION,
        DESTINATIONTYPE_UNORDEREDGROUP,
        DESTINATIONTYPE_EXIT,

    } pathwayDestinationTypeType;

    //LAEProperty Types
    //==============================    
    
    typedef enum {

        STORAGE_NULL = 1,
        STORAGE_ACTIONHANDLE,
        STORAGE_HS,
        STORAGE_HS2,
        STORAGE_HVPS,
        STORAGE_HVPS2,
        STORAGE_RS,

    } actionStorageCategoryType;


    //CHECKER Types
    typedef boost::tokenizer < boost::char_separator < char > > tokeniserType;
    
}

//Include Types Methods
#include "MATIS_TypesConvenienceMethods.h"

//Include ConfigurationElement after definitions because it uses them
#include "MATIS_ConfigurationElement.h"

//Include Hashable abstract class
#include "MATIS_Hashable.h"

//Include ModelElement abstract class
#include "MATIS_ModelElement.h"
#define NULL_POST_CONFIGURATION bool postConfigurationLoad(){}

#endif                          // MATIS_TYPES_H
