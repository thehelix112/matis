// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_TypeConversion_RTI_13NG.h,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.2 $






#ifndef MATIS_TYPECONVERSION_RTI_13NG_H
#define MATIS_TYPECONVERSION_RTI_13NG_H

#include "MATIS_TypeConversion.h"
#include "MATIS_Action_RTI_13NG.h"
#include "MATIS_Types.h"

// for these functions, will perform translation to/from internal id forms
// if aConvertUnique is true.

namespace MATIS {

    class TypeConversion_RTI_13NG {
    public:

        static handleSetType *getHS(handleType aChannelId,
                                    const RTI::AttributeHandleSet & aSet,
                                    bool aConvertUnique);

        static regionSetType *getRS(handleType aChannelId,
                                    RTI::Region* aRegions[],
                                    unsigned long int aNumber);

        static handleSetType *getHS(handleType aChannelId,
                                    RTI::AttributeHandle aAttributes[],
                                    unsigned long int aNumber);

        static handleSetType *getHS(handleType aChannelId,
                                    const RTI::AttributeHandle aAttHandle,
                                    bool aConvertUnique);

        static handleSetType *getHS(handleType aChannelId,
                                    const RTI::FederateHandleSet &aSet,
                                    bool aConvertUnique);

        static void addToHS(handleSetType & aSet,
                            handleType aHandle);

        static handleValuePairSetType *getHVPS(handleType aChannelId,
                                               const RTI::AttributeHandleValuePairSet & aSet,
                                               bool aConvertUnique);

        static handleValuePairSetType *getHVPS(handleType aChannelId,
                                               const RTI::ParameterHandleValuePairSet & aSet,
                                               bool aConvertUnique);

        static void addToHVPS(handleValuePairSetType & aSet,
                              handleType aHandle,
                              boost::any aValue);

        static RTI::AttributeHandleSet* getAHS(const handleSetType& aSet,
                                                bool aConvertUnique);

        static RTI::AttributeHandle getAH(const handleSetType& aSet,
                                          bool aConvertUnique);

        static RTI::FederateHandleSet* getFHS(const handleSetType& aSet,
                                               bool aConvertUnique);

        static RTI::AttributeHandle *getAHA(const handleSetType& aSet,
                                            bool aConvertUnique);

        static RTI::Region** getRA(const regionSetType& aSet);

        static RTI::AttributeHandleValuePairSet* getAHVPS(const handleValuePairSetType& aSet,
                                                          bool aConvertUnique);

        static RTI::ParameterHandleValuePairSet* getPHVPS(const handleValuePairSetType& aSet,
                                                          bool aConvertUnique);

        // //////

        static void addMeta_Timestamp(Action* aAction,
                                      RTIfedTime aValue);
        static RTIfedTime getMeta_Timestamp(Action& aAction);
        static RTI::FedTime& getMeta_TimestampFT(Action& aAction);

        static void addMeta_Tag(Action* aAction, 
                                std::string aValue);
        static void addMeta_Tag(Action* aAction, 
                                const char* aValue);
        static std::string getMeta_Tag(Action& aAction);

        static void addMeta_PointLabel(Action* aAction, std::string aValue);
        static void addMeta_PointLabel(Action* aAction, const char* aValue);
        static std::string getMeta_PointLabel(Action& aAction);

        static void addMeta_Active(Action* aAction, 
                                   bool aValue);
        static bool getMeta_Active(Action& aAction);

        static void addMeta_ResignAction(Action* aAction,
                                         RTI::ResignAction aValue);
        static RTI::ResignAction getMeta_ResignAction(Action& aAction);

        static void addMeta_ObjectClassHandle(Action* aAction,
                                              handleType aValue);
        static handleType getMeta_ObjectClassHandle(Action& aAction);

        static void addMeta_ObjectInstanceHandle(Action* aAction,
                                                 handleType aValue);
        static handleType getMeta_ObjectInstanceHandle(Action& aAction);

        static void addMeta_InteractionHandle(Action* aAction,
                                              handleType aValue);
        static std::string getMeta_InteractionLabel(Action& aAction);

        static void addMeta_FederationHandle(Action* aAction,
                                             handleType aValue);
        static handleType getMeta_FederationHandle(Action& aAction);


        static void addMeta_FederateHandle(Action* aAction,
                                           handleType aValue);
        static handleType getMeta_FederateHandle(Action& aAction);

        static void addMeta_AttributeHandle(Action* aAction,
                                            handleType aValue);
        static handleType getMeta_AttributeHandle(Action& aAction);

        static void addMeta_ParameterHandle(Action* aAction,
                                            handleType aValue);
        static handleType getMeta_ParameterHandle(Action& aAction);

        static void addMeta_OrderingHandle(Action* aAction,
                                           handleType aValue);
        static handleType getMeta_OrderingHandle(Action& aAction);

        static void addMeta_TransportationHandle(Action* aAction,
                                                 handleType aValue);
        static handleType getMeta_TransportationHandle(Action& aAction);

        static void addMeta_RoutingSpaceHandle(Action* aAction,
                                               handleType aValue);
        static handleType getMeta_RoutingSpaceHandle(Action& aAction);

        static void addMeta_NumberOf(Action* aAction,
                                     unsigned long int aValue);
        static unsigned long int getMeta_NumberOf(Action& aAction);

        static void addMeta_MiscDouble1(Action* aAction,
                                        double aValue);
        static double getMeta_MiscDouble1(Action& aAction);

        static void addMeta_MiscDouble2(Action* aAction,
                                        double aValue);
        static double getMeta_MiscDouble2(Action& aAction);

        static void addMeta_Region(Action* aAction,
                                   const RTI::Region* aValue);
        static RTI::Region* getMeta_Region(Action& aAction);

        static void addMeta_RegionToken(Action* aAction,
                                        handleType aValue);
        static handleType getMeta_RegionToken(Action& aAction);

        static void addMeta_DimensionHandle(Action* aAction,
                                            handleType aValue);
        static handleType getMeta_DimensionHandle(Action& aAction);

        static void addMeta_EventRetractionHandle(Action* aAction,
                                                  RTI::EventRetractionHandle aValue);
        static RTI::EventRetractionHandle getMeta_EventRetractionHandle(Action& aAction);

        // /////////////////////

        static void addMeta_ObjectInstanceLabel(Action* aAction,
                                                std::string aValue);
        static std::string getMeta_ObjectInstanceLabel(Action& aAction);

        static void addMeta_ObjectClassLabel(Action* aAction,
                                             std::string aValue);
        static std::string getMeta_ObjectClassLabel(Action& aAction);

        static void addMeta_InteractionLabel(Action* aAction,
                                             std::string aValue);
        static handleType getMeta_InteractionHandle(Action& aAction);

        static void addMeta_FederationExecutionLabel(Action* aAction, 
                                                     std::string aValue);
        static std::string getMeta_FederationExecutionLabel(Action& aAction);

        static void addMeta_FederateLabel(Action* aAction,
                                          std::string aValue);
        static std::string getMeta_FederateLabel(Action& aAction);

        static void addMeta_FederationExecutionHandle(Action* aAction, 
                                                      handleType aValue);
        static handleType getMeta_FederationExecutionHandle(Action& aAction);

        static void addMeta_FedFile(Action* aAction,
                                    std::string aValue);
        static std::string getMeta_FedFile(Action& aAction);

        static void addMeta_LookaheadTime(Action* aAction,
                                          RTIfedTime aValue);
        static RTIfedTime getMeta_LookaheadTime(Action& aAction);
        static RTI::FedTime & getMeta_LookaheadTimeFT(Action& aAction);

        static void addMeta_AttributeLabel(Action* aAction,
                                           std::string aValue);
        static std::string getMeta_AttributeLabel(Action& aAction);

        static void addMeta_ParameterLabel(Action* aAction,
                                           std::string aValue);
        static std::string getMeta_ParameterLabel(Action& aAction);

        static void addMeta_RoutingSpaceLabel(Action* aAction,
                                              std::string aValue);
        static std::string getMeta_RoutingSpaceLabel(Action& aAction);

        static void addMeta_DimensionLabel(Action* aAction,
                                           std::string aValue);
        static std::string getMeta_DimensionLabel(Action& aAction);

        static void addMeta_OrderingLabel(Action* aAction,
                                          std::string aValue);
        static std::string getMeta_OrderingLabel(Action& aAction);

        static void addMeta_TransportationLabel(Action* aAction,
                                                std::string aValue);
        static std::string getMeta_TransportationLabel(Action& aAction);

        static void addMeta_Exception(Action* aAction,
                                      RTI::Exception *aValue);
        static RTI::Exception *getMeta_Exception(Action& aAction);
        

        //Decodes a meta name in text to its handle form
        static handleType getMetaFromString(std::string aValue);
        //Decodes a meta name in handle form to text 
        static std::string getStringFromMeta(handleType aValue);

        static bool checkAttributeExists(const handleValuePairSetType& aSet,
                                         handleType aAttHandle);
        static bool checkAttributeExists(const handleSetType& aSet,
                                         handleType aAttHandle);

    };


}
#endif                          // MATIS_TYPECONVERSION_RTI_13NG_H
