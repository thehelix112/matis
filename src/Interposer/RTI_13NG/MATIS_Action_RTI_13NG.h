// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Action_RTI_13NG.h,v $
// CVS $Date: 2006/01/16 13:41:03 $
// CVS $Revision: 1.5 $





#ifndef MATIS_ACTION_RTI_13NG_H
#define MATIS_ACTION_RTI_13NG_H

#include "MATIS_Channel_RTI_13NG.h"
#include "MATIS_Action_Return_RTI_13NG.h"
#include "MATIS_Action.h"

// should have an execute method here that determines what to do
// to dispatch actions.
// this should be a static function, and this class will have
// to be declared a friend of Action.

// note this means we MUST be able to determine the protocol from
// an action, so it really should be a direct member of Action,
// or part of the hvps.

// the conversion functions in TypeConversion should be implemented
// in this class.

namespace MATIS {

    class Action_RTI_13NG {
    public:

        // These handles are (mostly) used for individual actions

        //actionMetaHandle;
        //Action_RTI_13NG Types

        typedef enum {

            // event identifiers
            TIMESTAMP = 1,   // RTIfedTime, (can be
            // null?)
            TAG,                // (string) extra object model
            // identifiers

            BOOLEAN_ACTIVE,     // boolean
            RESIGN_ACTION,      // enum RTI::ResignAction

            OBJECT_CLASS_HANDLE,    // handleType
            OBJECT_CLASS_LABEL, // (string)
            //
            ATTRIBUTE_HANDLE,
            ATTRIBUTE_LABEL,
            //
            OBJECT_INSTANCE_LABEL,  // (string)
            OBJECT_INSTANCE_HANDLE, // handleType
            // 
            INTERACTION_LABEL,
            INTERACTION_HANDLE,
            //
            PARAMETER_HANDLE,
            PARAMETER_LABEL,
            // 
            FEDERATE_LABEL,
            FEDERATE_HANDLE,
            // 
            FEDERATION_EXECUTION_LABEL,
            FEDERATION_EXECUTION_HANDLE,
            // 
            FED_FILE, //createFederationExecution
            //
            LOOKAHEAD_TIME, //enableTimeRegulation
            //
            ORDERING_HANDLE, //changeAttributeOrderType
            ORDERING_LABEL,
            TRANSPORTATION_HANDLE, //changeAttributeTransportType
            TRANSPORTATION_LABEL,
            //
            ROUTING_SPACE_HANDLE,
            ROUTING_SPACE_LABEL,
            //
            DIMENSION_HANDLE,
            DIMENSION_LABEL,
            //
            NUMBER_OF, //createRegion (DDM)
            REGION_HANDLE,
            REGION,
            //
            POINT_LABEL, //save/restore/synch
            //
            EVENT_RETRACTION_HANDLE,
            //
            MISC_DOUBLE1, //TICK2
            MISC_DOUBLE2, //TICK2
            //
            EXCEPTION,

            // This should always be the last.
            META_DATA_TOP = 100,

        } actionMetaHandleType;

        static void print(Action* action);

        static void *execute(Channel_RTI_13NG* channel, Action* theaction);
        
        static handleType getContextFromString(std::string context);
        static std::string getContextAsString(handleType context);	

        static bool isMetaLabel(handleType actionhandle);
        static bool isMetaHandle(handleType actionhandle);

        static bool isContextOutgoing(handleType context);
        static bool isContextIncoming(handleType context);
        static std::string getByteValueFromActionReturn(Action *aAction, 
                                                        void *aReturnValue);


        static std::string getActionHandleValuePairAsString(Action *action, 
                                                            handleType actionhandle);
        static handleType getActionHandleFromString(std::string actionhandle);

        static std::string actionMetaHandleToString(actionMetaHandleType actionhandle);
        static actionMetaHandleType stringToActionMetaHandle(std::string aString);

        static void throwDerivedException(RTI::Exception *aException);
        static std::string rtiExceptionToString(RTI::Exception *aException);

        // 

    private:
        
        static Action_Return_RTI_13NG returnValue;
		
        static void* 
		  execute_RTI_UpdateAttributeValues4(Channel_RTI_13NG * channel, Action * action);
        static void* 
		  execute_RTI_UpdateAttributeValues3(Channel_RTI_13NG * channel, Action * action);
        static void* 
		  execute_RTI_RegisterObjectInstance1(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RegisterObjectInstance2(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SendInteraction3(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SendInteraction4(Channel_RTI_13NG *channel, Action *action);
        static void*
		  execute_RTI_CreateFederationExecution(Channel_RTI_13NG *channel, Action *action);
        static void*
		  execute_RTI_JoinFederationExecution(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SubscribeObjectClassAttributes(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DestroyFederationExecution(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_FederateRestoreComplete(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_FederateRestoreNotComplete(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_FederateSaveBegun(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_FederateSaveComplete(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_FederateSaveNotComplete(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RegisterFederationSynchronisationPoint2(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RegisterFederationSynchronisationPoint3(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RequestFederationRestore(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RequestFederationSave1(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RequestFederationSave2(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_ResignFederationExecution(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SynchronisationPointAchieved(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_PublishInteractionClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_PublishObjectClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SubscribeInteractionClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnpublishInteractionClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnpublishObjectClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnsubscribeInteractionClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnsubscribeObjectClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_ChangeAttributeTransportationType(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_ChangeInteractionTransportationType(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DeleteObjectInstance2(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DeleteObjectInstance3(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_LocalDeleteObjectInstance(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RequestClassAttributeValueUpdate(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RequestObjectAttributeValueUpdate(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_AttributeOwnershipAcquisition(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_AttributeOwnershipAcquisitionIfAvailable(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_AttributeOwnershipReleaseResponse(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_CancelAttributeOwnershipAcquisition(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_CancelNegotiatedAttributeOwnershipDivestiture(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_IsAttributeOwnedByFederate(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_NegotiatedAttributeOwnershipDivestiture(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_QueryAttributeOwnership(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnconditionalAttributeOwnershipDivestiture(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_EnableTimeConstrained(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_EnableTimeRegulation(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DisableTimeConstrained(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DisableTimeRegulation(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_EnableAsynchronousDelivery(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DisableAsynchronousDelivery(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_ChangeAttributeOrderType(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_ChangeInteractionOrderType(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_FlushQueueRequest(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_ModifyLookahead(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_NextEventRequest(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_NextEventRequestAvailable(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_QueryFederateTime(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_QueryLbts(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_QueryLookahead(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_QueryMinnexteventtime(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_Retract(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_TimeAdvanceRequest(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_TimeAdvanceRequestAvailable(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_AssociateRegionForUpdates(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_CreateRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DeleteRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_NotifyAboutRegionModification(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RegisterObjectInstanceWithRegionSub1(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RegisterObjectInstanceWithRegion4(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RegisterObjectInstanceWithRegion5(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_RequestClassAttributeValueUpdateWithRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SendInteractionWithRegion4(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SendInteractionWithRegion5(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SubscribeInteractionClassWithRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_SubscribeObjectClassAttributesWithRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnassociateRegionForUpdates(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnsubscribeInteractionClassWithRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_UnsubscribeObjectClassWithRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DisableAttributeRelevanceAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DisableAttributeScopeAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DisableClassRelevanceAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_DisableInteractionRelevanceAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_EnableAttributeRelevanceAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_EnableAttributeScopeAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_EnableClassRelevanceAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_EnableInteractionRelevanceAdvisorySwitch(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetAttributeHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetAttributeName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetAttributeRoutingSpaceHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetDimensionHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetDimensionName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetInteractionClassHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetInteractionClassName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetInteractionRoutingSpaceHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetObjectClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetObjectClassHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetObjectClassName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetObjectInstanceHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetObjectInstanceName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetOrderingHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetOrderingName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetParameterHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetParameterName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetRegion(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetRegionToken(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetRoutingSpaceHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetRoutingSpaceName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetTransportationHandle(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_GetTransportationName(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_Tick0(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_RTI_Tick2(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_TimeRegulationEnabled(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_TimeConstrainedEnabled(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_RequestRetraction(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_TimeAdvanceGrant(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AnnounceSynchronisationPoint(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_FederationNotRestored(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_FederationNotSaved(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_FederationRestoreBegun(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_FederationRestored(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_FederationSaved(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_FederationSynchronised(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_InitiateFederateRestore(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_InitiateFederateSave(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_RequestFederationRestoreFailed(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_RequestFederationRestoreSucceeded(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_SynchronisationPointRegistrationFailed(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_SynchronisationPointRegistrationSucceeded(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_StartRegistrationForObjectClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_StopRegistrationForObjectClass(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_TurnInteractionsOff(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_TurnInteractionsOn(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AttributesInScope(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AttributesOutOfScope(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_DiscoverObjectInstance(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_ProvideAttributeValueUpdate(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_ReceiveInteraction3(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_ReceiveInteraction5(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_ReflectAttributeValues5(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_ReflectAttributeValues3(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_RemoveObjectInstance2(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_RemoveObjectInstance4(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_TurnUpdatesOffForObjectInstance(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_TurnUpdatesOnForObjectInstance(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AttributeIsNotOwned(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AttributeOwnedByRti(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AttributeOwnershipAcquisitionNotification(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AttributeOwnershipDivestitureNotification(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_AttributeOwnershipUnavailable(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_ConfirmAttributeOwnershipAcquisitionCancellation(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_InformAttributeOwnership(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_RequestAttributeOwnershipAssumption(Channel_RTI_13NG *channel, Action *action);
        static void* 
		  execute_Fed_RequestAttributeOwnershipRelease(Channel_RTI_13NG *channel, Action *action);
    };

}

#endif
