// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_TypeConversion_RTI_13NG.cpp,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.3 $








#include "MATIS_TypeConversion_RTI_13NG.h"

using namespace MATIS;

/*
  NOTE all pointers to handleType (MATIS_Profile* profile...) used in
  the argument list to functions have been replaced with (handleType
  aChannelId...)  This will affect all methods that call these. of which
  there are only a few so it should be easy to implement/change.

  these methods convert a given protocol specific whatever (eg
  AttributeHandleSet) into a MATIS corresponding whatever (eg
  handleSetType) with all Handles converted to internal MATIS Form.
*/

handleSetType *TypeConversion_RTI_13NG::getHS(handleType aChannelId,
                                              const RTI::AttributeHandleSet& aSet,
                                              bool aConvertUnique){

    static handleSetType *newd = NULL;

    if (newd){

        delete newd;

    }

    newd = new handleSetType;
    int asize = aSet.size();

    for (int i = 0; i < asize; i++) {

        handleType handle = aSet.getHandle(i);

        (*newd).insert(handle);
    }

    return newd;

}


regionSetType *TypeConversion_RTI_13NG::getRS(handleType aChannelId,
                                              RTI::Region* aRegions[],
                                              unsigned long int aNumber){

    static regionSetType *newd = NULL;

    if (newd) {

        delete newd;

    }

    newd = new regionSetType;	
    
    for(unsigned int i = 0; i < aNumber; i++){

        (*newd).insert(aRegions[i]);		

    }

    return newd;

}

handleSetType *TypeConversion_RTI_13NG::getHS(handleType aChannelId,
                                              RTI::AttributeHandle attributes[],
                                              unsigned long int aNumber){

    static handleSetType *newd = NULL;

    if (newd) {
        delete newd;
    }
    newd = new handleSetType;	
    
    for(unsigned int i = 0; i < aNumber; i++){
        
        (*newd).insert(attributes[i]);		
        
    }
    
    return newd;
}

handleSetType *TypeConversion_RTI_13NG::getHS(handleType aChannelId,
                                              const RTI::AttributeHandle theA,
                                              bool aConvertUnique){

    static handleSetType *newd = NULL;

    if (newd) {

        delete newd;

    }

    newd = new handleSetType;
    handleType handle = theA;

    (*newd).insert(handle);
    
    return newd;

}

handleSetType *TypeConversion_RTI_13NG::getHS(handleType aChannelId,
                                              const RTI::FederateHandleSet & aSet,
                                              bool aConvertUnique){

    static handleSetType *newd = NULL;

    if (newd) {

        delete newd;

    }

    newd = new handleSetType;
    int asize = aSet.size();

    for (int i = 0; i < asize; i++) {

        handleType handle = aSet.getHandle(i);

        (*newd).insert(handle);

    }

    return newd;

}

void TypeConversion_RTI_13NG::addToHS(handleSetType& aSet,
                                      handleType aHandle){

    aSet.insert(aHandle);
    
}

handleValuePairSetType *TypeConversion_RTI_13NG::getHVPS(handleType aChannelId,
                                                         const RTI::AttributeHandleValuePairSet & aSet, 
                                                         bool aConvertUnique){

    static handleValuePairSetType *newd = NULL;

    if (newd) {

        delete newd;

    }

    newd = new handleValuePairSetType;	
    int asize = aSet.size();
	
    for (int i = 0; i < asize; i++) {

        unsigned long int length = aSet.getValueLength(i);		
        std::string value = std::string(aSet.getValuePointer(i, length), length);
        handleType handle = aSet.getHandle(i);

        (*newd)[handle] = value;

    }

    return newd;

}

handleValuePairSetType *TypeConversion_RTI_13NG::getHVPS(handleType aChannelId,
                                                         const RTI::ParameterHandleValuePairSet & aSet, 
                                                         bool aConvertUnique){

    static handleValuePairSetType *newd = NULL;

    if (newd) {

        delete newd;

    }

    newd = new handleValuePairSetType;
    int asize = aSet.size();

    for (int i = 0; i < asize; i++) {

        unsigned long int length = aSet.getValueLength(i);
        std::string value = std::string(aSet.getValuePointer(i, length), length);
        handleType handle = aSet.getHandle(i);

        (*newd)[handle] = value;

    }

    return newd;

}

void TypeConversion_RTI_13NG::addToHVPS(handleValuePairSetType & aSet,
                                        handleType handle,
                                        boost::any inval){
    
    std::string value;

    try{

        //we must first try and cast the boost value to 
        //string as appropriate
        value = boost::any_cast<std::string>(inval);
        
    } catch(boost::bad_any_cast &){
        LOGERR("Bad boost any cast while adding to HVPS.\n");
    } catch(...){
        LOGERR("Bad something else which should have been bad_any_cast\n");
    }
    
    aSet[handle] = value;

}

///////////////

// note: we strip the internal data elements (see enumerated handles
// in Entity_RTI_13NG.h) for outgoing RTI types with conversion.

RTI::AttributeHandleValuePairSet* TypeConversion_RTI_13NG::getAHVPS(const handleValuePairSetType& theR,
                                                                    bool aConvertUnique){

    int asize = theR.size();
    static RTI::AttributeHandleValuePairSet * newd = NULL;
    
    if (newd) {

        delete newd;

    }

    newd = RTI::AttributeSetFactory::create(asize);
    handleValuePairSetType::const_iterator it = theR.begin();

    while (it != theR.end()) {

        handleType handle = (*it).first;
        std::string aval;

        LOGMSG(3," 2 AHVPS\n");
        
        aval = boost::any_cast < std::string > ((*it).second);
        newd->add(handle, aval.c_str(), aval.length());
        
        LOGMSG(3, "  Added to AHVPS[" << handle << "] = " << aval << "\n");

        it++;

    }

    LOGMSG(3,"creating AHVPS\n");	
    return newd;

}

RTI::ParameterHandleValuePairSet* TypeConversion_RTI_13NG::getPHVPS(const handleValuePairSetType& theR, 
                                                                    bool aConvertUnique) {
    int asize = theR.size();
    
    static RTI::ParameterHandleValuePairSet* newd = NULL;
    
    if (newd) {

        delete newd;

    }

    newd = RTI::ParameterSetFactory::create(asize);
    handleValuePairSetType::const_iterator it = theR.begin();

    while (it != theR.end()) {

        handleType handle = (*it).first;
        std::string aval;

        aval = boost::any_cast < std::string > ((*it).second);
        newd->add(handle, aval.c_str(), aval.length());
        
        it++;
    }
    
    return newd;
    
}

RTI::AttributeHandleSet* TypeConversion_RTI_13NG::getAHS(const handleSetType& theR,
                                                         bool aConvertUnique){
    
    int asize = theR.size();
    static RTI::AttributeHandleSet *newd = NULL;
    
    if (newd) {
        
        delete newd;
        
    }

    newd = RTI::AttributeHandleSetFactory::create(asize);
    handleSetType::const_iterator it = theR.begin();
    
    while (it != theR.end()) {
        
        handleType handle = (*it);
        
        LOGMSG(4, "Fetching handle from Action: " << handle << "\n");
        newd->add(handle);
        
        it++;
        
    }
    
    return newd;
    
}

RTI::FederateHandleSet* TypeConversion_RTI_13NG::getFHS(const handleSetType& theR,
                                                        bool aConvertUnique){
    
    
    int asize = theR.size();
    static RTI::FederateHandleSet * newd = NULL;
    
    if (newd) {

        delete newd;

    }

    newd = RTI::FederateHandleSetFactory::create(asize);
    handleSetType::const_iterator it = theR.begin();

    while (it != theR.end()) {

        handleType handle = (*it);
        newd->add(handle);
        it++;

    }

    return newd;

}

RTI::AttributeHandle TypeConversion_RTI_13NG::getAH(const handleSetType& theR,
                                                    bool aConvertUnique){

    int asize = theR.size();

    if(asize == 1){
        
        handleType handle = *(theR.begin());
        return (RTI::AttributeHandle)handle;

    }

    LOGERR("Shouldn't get here\n");
    return 0;

}

RTI::AttributeHandle* TypeConversion_RTI_13NG::getAHA(const handleSetType& theR,
                                                      bool aConvertUnique){

    int asize = theR.size();
    RTI::AttributeHandle *retval = (RTI::AttributeHandle*) calloc(asize, sizeof(RTI::AttributeHandle));

    handleSetType::const_iterator it = theR.begin();

    while (it != theR.end()) {

        handleType handle = (*it);         
        retval[asize] = handle;
        it++;

    }

    return retval;

}



RTI::Region** TypeConversion_RTI_13NG::getRA(const regionSetType& theR){

    int asize = theR.size();
    RTI::Region** retval = (RTI::Region**) calloc(asize, sizeof(RTI::Region*));

    regionSetType::const_iterator it = theR.begin();

    while (it != theR.end()) {

        RTI::Region* cur = (*it);
        retval[asize] = cur;
        it++;

    }

    return retval;	

}

////////////////////////////
#include <string.h>

// Convenience accessors with type conversion for
// meta-handlevalues (i.e. special handlevalues associated 
// with object model information)

bool
getMetaAsCharArray(const handleValuePairSetType & theR,
                   handleType hand, char **pval, int *len)
{
    handleValuePairSetType::const_iterator it = theR.find(hand);
    if (it == theR.end()) {
        LOGMSG(2, "Warning: meta handle " << hand << " not found in HVPS\n");
        return false;
    } else {
        std::string aval = boost::any_cast < std::string > ((*it).second);

        *len = aval.length();
        *pval = (char *) aval.c_str();
        return true;
    }
};

///////////////////////////////////////////////////////////////////

// it remains to be seen whether RTIfedTime fulfills boost's requirements
// to allow its storage in an boost::any.
void

TypeConversion_RTI_13NG::addMeta_Timestamp(Action* action,
                                           RTIfedTime aValue)
{

    action->metadata[Action_RTI_13NG::TIMESTAMP] = aValue;
}

RTI::FedTime & TypeConversion_RTI_13NG::
getMeta_TimestampFT(Action &action)
{
    static RTI::FedTime *ft = (RTI::FedTimeFactory::makeZero());

    *ft = getMeta_Timestamp(action);
    return *ft;
}

RTIfedTime
TypeConversion_RTI_13NG::
getMeta_Timestamp(Action &action)
{
    boost::any aValue;
    RTIfedTime retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::TIMESTAMP, &aValue);

    try {
        retval = boost::any_cast < RTIfedTime > (aValue);
    } catch(...) {
        throw;
    }

    return retval;
}
////////////////////////////////////////////////////////
void
TypeConversion_RTI_13NG::addMeta_Tag(Action* action,
                                     std::string aValue)
{
    action->metadata[Action_RTI_13NG::TAG] = std::string(aValue.c_str(), aValue.length());
}

void
TypeConversion_RTI_13NG::addMeta_Tag(Action* action,
                                     const char* aValue)
{
    if(aValue != NULL){
        std::string str = aValue;
        action->metadata[Action_RTI_13NG::TAG] = std::string(str.c_str(), str.length());
    } else {
        LOGMSG(3, "Warning: NULL tag specified.");
        action->metadata[Action_RTI_13NG::TAG] = std::string("", 0);
    }
}

std::string TypeConversion_RTI_13NG::getMeta_Tag(Action &action)
{
    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::TAG, &aValue);

    try {
        retval = boost::any_cast < std::string > (aValue);
    } catch(...) {
        throw;
    }
    return std::string(retval.c_str(), retval.length());
}
////////////////////////////////////////////////////
void
TypeConversion_RTI_13NG::addMeta_PointLabel(Action* action,
                                            std::string aValue)
{
    action->metadata[Action_RTI_13NG::POINT_LABEL] = std::string(aValue.c_str(), aValue.length());
}

void
TypeConversion_RTI_13NG::addMeta_PointLabel(Action* action,
                                            const char* aValue)
{
    if(aValue != NULL){
        std::string str = aValue;
        action->metadata[Action_RTI_13NG::POINT_LABEL] = std::string(str.c_str(), str.length());
    } else {
        LOGMSG(3, "Warning: NULL tag specified.");
        action->metadata[Action_RTI_13NG::POINT_LABEL] = std::string("", 0);
    }
}

std::string TypeConversion_RTI_13NG::
getMeta_PointLabel(Action &action)
{
    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::POINT_LABEL, &aValue);

    try {
        retval = boost::any_cast < std::string > (aValue);
    } catch(...) {
        throw;
    }
    return std::string(retval.c_str(), retval.length());
}

////////////////////////////////////////
void TypeConversion_RTI_13NG::addMeta_Active(Action *action,
                                             bool aValue)
{
    action->metadata[Action_RTI_13NG::BOOLEAN_ACTIVE] = aValue;
}

bool TypeConversion_RTI_13NG::getMeta_Active(Action &action)
{
    boost::any aValue;
    bool retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::BOOLEAN_ACTIVE, &aValue);
    try {
        retval = boost::any_cast < bool > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}
////////////////////////////////////////////////
void TypeConversion_RTI_13NG::addMeta_ResignAction
(Action *action, RTI::ResignAction aValue) {

    action->metadata[Action_RTI_13NG::RESIGN_ACTION] = aValue;
}

RTI::ResignAction TypeConversion_RTI_13NG::
getMeta_ResignAction(Action &action)
{
    boost::any aValue;
    RTI::ResignAction retval;
    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::RESIGN_ACTION, &aValue);
    try {
        retval = boost::any_cast < RTI::ResignAction > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}
////////////////////////////////////////////////////////////
// this one explicitly takes a aChannelId.
void TypeConversion_RTI_13NG::
addMeta_ObjectClassHandle(Action *action, handleType aValue)
{
    action->metadata[Action_RTI_13NG::OBJECT_CLASS_HANDLE] = aValue;
	
//        Entity_RTI_13NG::getObjectClassHandle(action->aChannelId, aValue);
}


handleType
TypeConversion_RTI_13NG::
getMeta_ObjectClassHandle(Action &action)
{
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::OBJECT_CLASS_HANDLE,
                            &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}
/////////////////////////////////////////////////
void

TypeConversion_RTI_13NG::
addMeta_ObjectInstanceHandle(Action *action, handleType aValue)
{
    action->metadata[Action_RTI_13NG::OBJECT_INSTANCE_HANDLE] = aValue;
	
//        Entity_RTI_13NG::getObjectInstanceHandle(action->aChannelId, aValue);
}


handleType
TypeConversion_RTI_13NG::
getMeta_ObjectInstanceHandle(Action &action)
{
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::OBJECT_INSTANCE_HANDLE,
                            &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}
//////////////////////////////////////////////////////
void
TypeConversion_RTI_13NG::addMeta_InteractionHandle(Action *action, handleType aValue)
{
    action->metadata[Action_RTI_13NG::INTERACTION_HANDLE] = aValue;
	
//        Entity_RTI_13NG::getInteractionHandle(action->aChannelId, aValue);
}


handleType
TypeConversion_RTI_13NG::
getMeta_InteractionHandle(Action &action)
{
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::INTERACTION_HANDLE,
                            &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////

void
TypeConversion_RTI_13NG::addMeta_FederateHandle(Action *action, handleType aValue)
{
    action->metadata[Action_RTI_13NG::FEDERATE_HANDLE] = aValue;
	
//        Entity_RTI_13NG::getFederateHandle(action->aChannelId, aValue);
}


handleType
TypeConversion_RTI_13NG::
getMeta_FederateHandle(Action &action)
{
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::FEDERATE_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

//////////////////

void
TypeConversion_RTI_13NG::addMeta_FederationHandle(Action *action, handleType aValue)
{

    action->metadata[Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE] = aValue;
	
//        Entity_RTI_13NG::getFederateHandle(action->aChannelId, aValue);
}

handleType TypeConversion_RTI_13NG::getMeta_FederationHandle(Action &action)
{
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_AttributeHandle(Action *action,
                                                      handleType aValue){
    action->metadata[Action_RTI_13NG::ATTRIBUTE_HANDLE] = aValue;
	
//        Entity_RTI_13NG::getAttributeHandle(action->aChannelId, aValue);
}

handleType TypeConversion_RTI_13NG::getMeta_AttributeHandle(Action &action){
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::ATTRIBUTE_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

//////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_ParameterHandle(Action *action,
                                                      handleType aValue){
    action->metadata[Action_RTI_13NG::PARAMETER_HANDLE] = aValue;
	
// WRONG        Entity_RTI_13NG::getAttributeHandle(action->aChannelId, aValue);
}


handleType TypeConversion_RTI_13NG::getMeta_ParameterHandle(Action &action){
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::PARAMETER_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}


///////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_RoutingSpaceHandle(Action *action,
                                                         handleType aValue){
    action->metadata[Action_RTI_13NG::ROUTING_SPACE_HANDLE] = aValue;
}

handleType TypeConversion_RTI_13NG::getMeta_RoutingSpaceHandle(Action &action){
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::ROUTING_SPACE_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_NumberOf(Action *action,
                                               unsigned long int aValue){
    action->metadata[Action_RTI_13NG::NUMBER_OF] = aValue;
}

unsigned long int TypeConversion_RTI_13NG::getMeta_NumberOf(Action &action){
    boost::any aValue;
    unsigned long int retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::NUMBER_OF, &aValue);
    try {
        retval = boost::any_cast < unsigned long int > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////////////
void TypeConversion_RTI_13NG::addMeta_MiscDouble1(Action *action,
                                                  double aValue){
    action->metadata[Action_RTI_13NG::MISC_DOUBLE1] = aValue;
}

double TypeConversion_RTI_13NG::getMeta_MiscDouble1(Action &action){
    boost::any aValue;
    double retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::MISC_DOUBLE1, &aValue);
    try {
        retval = boost::any_cast < double > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////////////
void TypeConversion_RTI_13NG::addMeta_MiscDouble2(Action *action,
                                                  double aValue){
    action->metadata[Action_RTI_13NG::MISC_DOUBLE2] = aValue;
}

double TypeConversion_RTI_13NG::getMeta_MiscDouble2(Action &action){
    boost::any aValue;
    double retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::MISC_DOUBLE2, &aValue);
    try {
        retval = boost::any_cast < double > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_Region(Action* action,
                                             const RTI::Region* aValue){
    action->metadata[Action_RTI_13NG::REGION] = aValue;
}

RTI::Region* TypeConversion_RTI_13NG::getMeta_Region(Action& action){
    boost::any aValue;
    RTI::Region* retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::REGION, &aValue);
    try {
        retval = boost::any_cast < RTI::Region* > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_RegionToken(Action *action,
                                                  handleType aValue){
    action->metadata[Action_RTI_13NG::REGION_HANDLE] = aValue;
}

handleType TypeConversion_RTI_13NG::getMeta_RegionToken(Action &action){
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::REGION_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

//////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_DimensionHandle(Action *action,
                                                      handleType aValue){
    action->metadata[Action_RTI_13NG::DIMENSION_HANDLE] = aValue;
}


handleType TypeConversion_RTI_13NG::getMeta_DimensionHandle(Action &action){
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::DIMENSION_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

/////////////////////////////


void TypeConversion_RTI_13NG::addMeta_OrderingHandle(Action *action,
                                                     handleType aValue){
    action->metadata[Action_RTI_13NG::ORDERING_HANDLE] = aValue;
}


handleType TypeConversion_RTI_13NG::getMeta_OrderingHandle(Action &action){
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::ORDERING_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;	
}
/////////////////////////////


void TypeConversion_RTI_13NG::addMeta_TransportationHandle(Action *action,
                                                           handleType aValue){
    action->metadata[Action_RTI_13NG::TRANSPORTATION_HANDLE] = aValue;
}


handleType TypeConversion_RTI_13NG::getMeta_TransportationHandle(Action &action){
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::TRANSPORTATION_HANDLE, &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;	
}

//////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_EventRetractionHandle(Action *action,
                                                            RTI::EventRetractionHandle aValue){
    action->metadata[Action_RTI_13NG::EVENT_RETRACTION_HANDLE] = aValue;
	

}

RTI::EventRetractionHandle TypeConversion_RTI_13NG::getMeta_EventRetractionHandle(Action &action){
    boost::any aValue;
    RTI::EventRetractionHandle retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::EVENT_RETRACTION_HANDLE, &aValue);
    try {
        retval = boost::any_cast < RTI::EventRetractionHandle > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}


/////////////////////////

void TypeConversion_RTI_13NG::
addMeta_ObjectInstanceLabel(Action* action,
                            std::string aValue)
{
    action->metadata[Action_RTI_13NG::OBJECT_INSTANCE_LABEL] = aValue;
}

std::string TypeConversion_RTI_13NG::
getMeta_ObjectInstanceLabel(Action &action)
{
    boost::any aValue;
    std::string retval;
    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::OBJECT_INSTANCE_LABEL,
                            &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////

void TypeConversion_RTI_13NG::
addMeta_ObjectClassLabel(Action* action,
                         std::string aValue)
{
    action->metadata[Action_RTI_13NG::OBJECT_CLASS_LABEL] = aValue;
}

std::string TypeConversion_RTI_13NG::
getMeta_ObjectClassLabel(Action &action)
{
    boost::any aValue;
    std::string retval;
    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::OBJECT_CLASS_LABEL,
                            &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}
///////////////////////////

void TypeConversion_RTI_13NG::
addMeta_InteractionLabel(Action* action,
                         std::string aValue)
{
    action->metadata[Action_RTI_13NG::INTERACTION_LABEL] = aValue;
}

std::string TypeConversion_RTI_13NG::
getMeta_InteractionLabel(Action &action)
{
    boost::any aValue;
    std::string retval;
    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::INTERACTION_LABEL,
                            &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

///////////////////////////

void TypeConversion_RTI_13NG::
addMeta_FederationExecutionLabel(Action *action,
                                 std::string aValue)
{
    action->metadata[Action_RTI_13NG::FEDERATION_EXECUTION_LABEL] = aValue;
}

std::string TypeConversion_RTI_13NG::
getMeta_FederationExecutionLabel(Action &action)
{
    boost::any aValue;
    std::string retval;
    TypeConversion::getMeta(action.metadata,
                            Action_RTI_13NG::FEDERATION_EXECUTION_LABEL,
                            &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

/////////////////////////////

void TypeConversion_RTI_13NG::
addMeta_FederateLabel(Action *action, std::string aValue)
{
    action->metadata[Action_RTI_13NG::FEDERATE_LABEL] = aValue;
}

std::string TypeConversion_RTI_13NG::
getMeta_FederateLabel(Action &action)
{
    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::FEDERATE_LABEL, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;

}

void TypeConversion_RTI_13NG::addMeta_LookaheadTime(Action* action,
                                                    RTIfedTime aValue)
{

    action->metadata[Action_RTI_13NG::LOOKAHEAD_TIME] = aValue;
}

RTI::FedTime & TypeConversion_RTI_13NG::
getMeta_LookaheadTimeFT(Action &action)
{
    static RTI::FedTime * ft = (RTI::FedTimeFactory::makeZero());

    *ft = getMeta_LookaheadTime(action);
    return *ft;
}

RTIfedTime
TypeConversion_RTI_13NG::
getMeta_LookaheadTime(Action &action)
{
    boost::any aValue;
    RTIfedTime retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::LOOKAHEAD_TIME, &aValue);

    try {
        retval = boost::any_cast < RTIfedTime > (aValue);
    } catch(...) {
        throw;
    }

    return retval;
}

///////////////////////////////

void TypeConversion_RTI_13NG::
addMeta_FederationExecutionHandle(Action *action,
                                  handleType aValue)
{
    action->metadata[Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE] = aValue;
}

handleType
TypeConversion_RTI_13NG::
getMeta_FederationExecutionHandle(Action &action)
{
    boost::any aValue;
    handleType retval;

    TypeConversion::getMeta(action.metadata,
                            Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE,
                            &aValue);
    try {
        retval = boost::any_cast < handleType > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

//////////////

void
TypeConversion_RTI_13NG::addMeta_FedFile(Action *action,
                                         std::string aValue)
{
    action->metadata[Action_RTI_13NG::FED_FILE] = aValue;
}

std::string TypeConversion_RTI_13NG::
getMeta_FedFile(Action &action)
{
    boost::any aValue;
    std::string retval;
    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::FED_FILE, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }
    return retval;
}

////////////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_AttributeLabel(Action *action,
                                                     std::string aValue){
    action->metadata[Action_RTI_13NG::ATTRIBUTE_LABEL] = aValue;	
}

std::string TypeConversion_RTI_13NG::getMeta_AttributeLabel(Action &action){

    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::ATTRIBUTE_LABEL, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;
}


/////////////////////////////


void TypeConversion_RTI_13NG::addMeta_ParameterLabel(Action *action,
                                                     std::string aValue){
    action->metadata[Action_RTI_13NG::PARAMETER_LABEL] = aValue;
}


std::string TypeConversion_RTI_13NG::getMeta_ParameterLabel(Action &action){
    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::PARAMETER_LABEL, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;	
}

/////////////////////////////


void TypeConversion_RTI_13NG::addMeta_OrderingLabel(Action *action,
                                                    std::string aValue){
    action->metadata[Action_RTI_13NG::ORDERING_LABEL] = aValue;
}


std::string TypeConversion_RTI_13NG::getMeta_OrderingLabel(Action &action){
    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::ORDERING_LABEL, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;	
}
/////////////////////////////


void TypeConversion_RTI_13NG::addMeta_TransportationLabel(Action *action,
                                                          std::string aValue){
    action->metadata[Action_RTI_13NG::TRANSPORTATION_LABEL] = aValue;
}


std::string TypeConversion_RTI_13NG::getMeta_TransportationLabel(Action &action){
    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::TRANSPORTATION_LABEL, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;	
}


////////////////////////////////////////

void TypeConversion_RTI_13NG::addMeta_RoutingSpaceLabel(Action *action,
                                                        std::string aValue){
    action->metadata[Action_RTI_13NG::ROUTING_SPACE_LABEL] = aValue;	
}

std::string TypeConversion_RTI_13NG::getMeta_RoutingSpaceLabel(Action &action){

    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::ROUTING_SPACE_LABEL, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;
}

/////////////////////////////


void TypeConversion_RTI_13NG::addMeta_DimensionLabel(Action *action,
                                                     std::string aValue){
    action->metadata[Action_RTI_13NG::DIMENSION_LABEL] = aValue;
}


std::string TypeConversion_RTI_13NG::getMeta_DimensionLabel(Action &action){
    boost::any aValue;
    std::string retval;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::DIMENSION_LABEL, &aValue);
    try {
        retval = boost::any_cast < std::string > (aValue);
    }
    catch(...) {
        throw;
    }

    return retval;	
}

/////////////////////////////


void TypeConversion_RTI_13NG::addMeta_Exception(Action *action,
                                                RTI::Exception *aValue){
    action->metadata[Action_RTI_13NG::EXCEPTION] = aValue;
}


RTI::Exception *TypeConversion_RTI_13NG::getMeta_Exception(Action &action){
    boost::any aValue;

    TypeConversion::getMeta(action.metadata, Action_RTI_13NG::EXCEPTION, &aValue);
    try {
        RTI::Exception *retval = boost::any_cast < RTI::Exception* > (aValue);
        return retval;
    }
    catch(...) {
        throw;
    }
}


/////////////////////////////


///////////////////////////////////////////////

bool TypeConversion_RTI_13NG::
checkAttributeExists(const handleValuePairSetType & theR,
                     handleType hand)
{
    handleValuePairSetType::const_iterator it = theR.find(hand);
    if (it == theR.end()) {
        return false;
    } else {
        return true;
    }
}

///////////////////////////////////////////////

bool TypeConversion_RTI_13NG::
checkAttributeExists(const handleSetType & theR,
                     handleType hand)
{
    handleSetType::const_iterator it = theR.find(hand);
    if (it == theR.end()) {
        return false;
    } else {
        return true;
    }
}


//////////

handleType TypeConversion_RTI_13NG::getMetaFromString(std::string aValue) 
{
	
    if (aValue == "TIMESTAMP") {
        return Action_RTI_13NG::TIMESTAMP ;
    }
	
    if (aValue == "TAG") {
        return Action_RTI_13NG::TAG;
    }
	
    if (aValue == "BOOLEAN_ACTIVE") {
        return Action_RTI_13NG::BOOLEAN_ACTIVE;
    }
	
    if (aValue == "RESIGN_ACTION") {
        return Action_RTI_13NG::RESIGN_ACTION;
    }
	
    if (aValue == "OBJECT_CLASS_HANDLE") {
        return Action_RTI_13NG::OBJECT_CLASS_HANDLE ;
    }
	
    if (aValue == "OBJECT_CLASS_LABEL") {
        return Action_RTI_13NG::OBJECT_CLASS_LABEL ;
    }
	
    if (aValue == "OBJECT_INSTANCE_LABEL") {
        return Action_RTI_13NG::OBJECT_INSTANCE_LABEL ;
    }
	
    if (aValue == "OBJECT_INSTANCE_HANDLE") {
        return Action_RTI_13NG::OBJECT_INSTANCE_HANDLE ;
    }
	
    if (aValue == "INTERACTION_LABEL") {
        return Action_RTI_13NG::INTERACTION_LABEL ;
    }
	
    if (aValue == "INTERACTION_HANDLE") {
        return Action_RTI_13NG::INTERACTION_HANDLE ;
    }
	
    if (aValue == "FEDERATE_LABEL") {
        return Action_RTI_13NG::FEDERATE_LABEL ;
    }
	
    if (aValue == "FEDERATE_HANDLE") {
        return Action_RTI_13NG::FEDERATE_HANDLE ;
    }
	
    if (aValue == "FEDERATION_EXECUTION_LABEL") {
        return Action_RTI_13NG::FEDERATION_EXECUTION_LABEL ;
    }
	
    if (aValue == "FEDERATION_EXECUTION_HANDLE") {
        return Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE ;
    }
	
    if (aValue == "FED_FILE") {
        return Action_RTI_13NG::FED_FILE ;
    }
    if (aValue == "ATTRIBUTE_HANDLE") {
        return Action_RTI_13NG::ATTRIBUTE_HANDLE ;
    }
    if (aValue == "ATTRIBUTE_LABEL") {
        return Action_RTI_13NG::ATTRIBUTE_LABEL ;
    }
    if (aValue == "PARAMETER_HANDLE") {
        return Action_RTI_13NG::PARAMETER_HANDLE ;
    }
    if (aValue == "PARAMETER_LABEL") {
        return Action_RTI_13NG::PARAMETER_LABEL ;
    }

    if(aValue == "FEDERATE_LABEL"){
        return Action_RTI_13NG::FEDERATE_LABEL;
    }
   
    if(aValue == "FEDERATE_HANDLE"){
        return Action_RTI_13NG::FEDERATE_HANDLE;
    }
   

    if(aValue == "FEDERATION_EXECUTION_LABEL"){
        return Action_RTI_13NG::FEDERATION_EXECUTION_LABEL;
    }
   
    if(aValue == "FEDERATION_EXECUTION_HANDLE"){
        return Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE;
    }
   

    if(aValue == "FED_FILE"){
        return Action_RTI_13NG::FED_FILE;
    }
   

    if(aValue == "LOOKAHEAD_TIME"){
        return Action_RTI_13NG::LOOKAHEAD_TIME;
    }
   

    if(aValue == "ORDERING_HANDLE"){
        return Action_RTI_13NG::ORDERING_HANDLE;
    }
   
    if(aValue == "ORDERING_LABEL"){
        return Action_RTI_13NG::ORDERING_LABEL;
    }
   
    if(aValue == "TRANSPORTATION_HANDLE"){
        return Action_RTI_13NG::TRANSPORTATION_HANDLE;
    }
   
    if(aValue == "TRANSPORTATION_LABEL"){
        return Action_RTI_13NG::TRANSPORTATION_LABEL;
    }
   
            
    if(aValue == "ROUTING_SPACE_HANDLE"){
        return Action_RTI_13NG::ROUTING_SPACE_HANDLE;
    }
   
    if(aValue == "ROUTING_SPACE_LABEL"){
        return Action_RTI_13NG::ROUTING_SPACE_LABEL;
    }
   
            
    if(aValue == "DIMENSION_HANDLE"){
        return Action_RTI_13NG::DIMENSION_HANDLE;
    }
   
    if(aValue == "DIMENSION_LABEL"){
        return Action_RTI_13NG::DIMENSION_LABEL;
    }
   
            
    if(aValue == "NUMBER_OF"){
        return Action_RTI_13NG::NUMBER_OF;
    }
   
    if(aValue == "REGION_HANDLE"){
        return Action_RTI_13NG::REGION_HANDLE;
    }
   
            
    if(aValue == "POINT_LABEL"){
        return Action_RTI_13NG::POINT_LABEL;
    }
   
            
    if(aValue == "EVENT_RETRACTION_HANDLE"){
        return Action_RTI_13NG::EVENT_RETRACTION_HANDLE;
    }
   
            
    if(aValue == "MISC_DOUBLE1"){
        return Action_RTI_13NG::MISC_DOUBLE1;
    }
   
    if(aValue == "MISC_DOUBLE2"){
        return Action_RTI_13NG::MISC_DOUBLE2;
    }
   
    LOGWRN("Unknown meta label '" << aValue << "'\n");
    return 0;

}


std::string TypeConversion_RTI_13NG::getStringFromMeta(handleType aValue) 
{
    std::string retval;
	
    switch (aValue) {
    case Action_RTI_13NG::TIMESTAMP :
        retval = "TIMESTAMP"; break;
    case Action_RTI_13NG::TAG:
        retval = "TAG"; break;
		
    case Action_RTI_13NG::BOOLEAN_ACTIVE:
        retval = "BOOLEAN_ACTIVE"; break;
		
    case Action_RTI_13NG::RESIGN_ACTION:
        retval = "RESIGN_ACTION"; break;
		
    case Action_RTI_13NG::OBJECT_CLASS_HANDLE:
        retval = "OBJECT_CLASS_HANDLE"; break;
		
    case Action_RTI_13NG::OBJECT_CLASS_LABEL:
        retval = "OBJECT_CLASS_LABEL"; break;
		
    case Action_RTI_13NG::OBJECT_INSTANCE_LABEL:
        retval = "OBJECT_INSTANCE_LABEL"; break;
		
    case Action_RTI_13NG::OBJECT_INSTANCE_HANDLE:
        retval = "OBJECT_INSTANCE_HANDLE"; break;
		
    case Action_RTI_13NG::INTERACTION_LABEL:
        retval = "INTERACTION_LABEL"; break;
		
    case Action_RTI_13NG::INTERACTION_HANDLE:
        retval = "INTERACTION_HANDLE"; break;
		
    case Action_RTI_13NG::FEDERATE_LABEL:
        retval = "FEDERATE_LABEL"; break;
		
    case Action_RTI_13NG::FEDERATE_HANDLE:
        retval = "FEDERATE_HANDLE"; break;
		
    case Action_RTI_13NG::FEDERATION_EXECUTION_LABEL:
        retval = "FEDERATION_EXECUTION_LABEL"; break;
		
    case Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE:
        retval = "FEDERATION_EXECUTION_HANDLE"; break;
		
    case Action_RTI_13NG::FED_FILE:
        retval = "FED_FILE"; break;

    case Action_RTI_13NG::ATTRIBUTE_HANDLE:
        retval = "ATTRIBUTE_HANDLE"; break;

    case Action_RTI_13NG::ATTRIBUTE_LABEL:
        retval = "ATTRIBUTE_LABEL"; break;

    case Action_RTI_13NG::PARAMETER_HANDLE:
        retval = "PARAMETER_HANDLE"; break;

    case Action_RTI_13NG::PARAMETER_LABEL:
        retval = "PARAMETER_LABEL"; break;       

    case Action_RTI_13NG::LOOKAHEAD_TIME:
        retval = "LOOKAHEAD_TIME";
        break;

    case Action_RTI_13NG::ORDERING_HANDLE:
        retval = "ORDERING_HANDLE";
        break;
       
    case Action_RTI_13NG::ORDERING_LABEL:
        retval = "ORDERING_LABEL";
        break;
       
    case Action_RTI_13NG::TRANSPORTATION_HANDLE:
        retval = "TRANSPORTATION_HANDLE";
        break;
       
    case Action_RTI_13NG::TRANSPORTATION_LABEL:
        retval = "TRANSPORTATION_LABEL";
        break;
            
    case Action_RTI_13NG::ROUTING_SPACE_HANDLE:
        retval = "ROUTING_SPACE_HANDLE";
        break;
       
    case Action_RTI_13NG::ROUTING_SPACE_LABEL:
        retval = "ROUTING_SPACE_LABEL";
        break;
            
    case Action_RTI_13NG::DIMENSION_HANDLE:
        retval = "DIMENSION_HANDLE";
        break;
       
    case Action_RTI_13NG::DIMENSION_LABEL:
        retval = "DIMENSION_LABEL";
        break;
            
    case Action_RTI_13NG::NUMBER_OF:
        retval = "NUMBER_OF";
        break;
       
    case Action_RTI_13NG::REGION_HANDLE:
        retval = "REGION_HANDLE";
        break;
       
            
    case Action_RTI_13NG::POINT_LABEL:
        retval = "POINT_LABEL";
        break;
            
    case Action_RTI_13NG::EVENT_RETRACTION_HANDLE:
        retval = "EVENT_RETRACTION_HANDLE";
        break;
            
    case Action_RTI_13NG::MISC_DOUBLE1:
        retval = "MISC_DOUBLE1";
        break;
       
    case Action_RTI_13NG::MISC_DOUBLE2:
        retval = "MISC_DOUBLE2";
        break;
       

    default:
        std::cout << "Unknown metadata handle " << aValue << "\n";
//		exit(1);
		
    }
    return retval;	
}
