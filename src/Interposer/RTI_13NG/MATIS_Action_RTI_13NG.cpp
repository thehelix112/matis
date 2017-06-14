// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Action_RTI_13NG.cpp,v $
// CVS $Date: 2006/01/20 12:42:00 $
// CVS $Revision: 1.7 $

#include "MATIS_TypeConversion_RTI_13NG.h"
#include "MATIS_Action_RTI_13NG.h"
#include "MATIS_LAESet.h"
#include "MATIS_Types.h"

#ifdef _WIN32
#pragma warning (disable:4101)
#endif

using namespace MATIS;

Action_Return_RTI_13NG Action_RTI_13NG::returnValue;

void Action_RTI_13NG::print(Action* action){

    LOGMSG(1, "  channel id           = " << action->channelId << "\n"
           << "  action context       = " << Action_RTI_13NG::getContextAsString(action->actionContext) << "\n"
           << "  outgoing             = " << ((action->outgoing)?"true":"false") << "\n");


    handleValuePairSetType::const_iterator it = action->hvps.begin();


    for(it = action->hvps.begin(); it != action->hvps.end(); ++it) {

        handleType handle = (*it).first;
        LOGMSG(1, "  " << handle << ": '" << boost::any_cast<std::string>((*it).second) << "'\n");
        
    }

    for(it = action->metadata.begin(); it != action->metadata.end(); ++it) {

        handleType handle = (*it).first;
        LOGMSG(1, "  " << Action_RTI_13NG::getActionHandleValuePairAsString(action, handle) << "\n");
        
    }

    it = action->hvps2.begin();

    while (it != action->hvps2.end()) {

        handleType handle = (*it).first;
        
        if (handle >= Action_RTI_13NG::META_DATA_TOP) {

            LOGMSG(1, "  " << handle << ": '" << boost::any_cast<std::string>((*it).second) << "'\n");
            
        } else {
            
            LOGMSG(1, "  " << Action_RTI_13NG::getActionHandleValuePairAsString(action, handle) << "\n");
            
        }
        
        it++;

    }
    
    handleSetType::const_iterator iv = action->hs.begin();

    while (iv != action->hs.end()) {

        handleType handle = *iv;
        LOGMSG(1, "  " << handle << "\n");
        iv++;

    }

}



void *Action_RTI_13NG::execute(Channel_RTI_13NG* channel, Action* action){

    LOGMSG(1, "About to execute action context: " << getContextAsString(action->actionContext) << ".\n");

    //return value
    void* retval;

    //print out the action
    Action_RTI_13NG::print(action);

    //checks
    if(isContextIncoming(action->actionContext)){        

        LOGMSG(4, "Incoming action..\n");

        if(channel->internalFedAmb == NULL){
            LOGERR("Internal federate ambassador NULL.\n");
        }
        
    }

    try{        

        switch (action->actionContext) {
            
        case Action::NOP:
            // nothing
            break;

        case Action::EXCEPTION:
            //throw the exception back to the client
            //create an appropriate exception object
            throwDerivedException(TypeConversion_RTI_13NG::getMeta_Exception(*action));
            break;

            //////////////////////////// RTI AMBASSADOR /////////////

        case Action::UPDATE_ATTRIBUTE_VALUES4:
            retval = execute_RTI_UpdateAttributeValues4(channel, action); 
            break;
        case Action::UPDATE_ATTRIBUTE_VALUES3:
            retval = execute_RTI_UpdateAttributeValues3(channel, action); 
            break;
        case Action::REGISTER_OBJECT_INSTANCE1:
            retval = execute_RTI_RegisterObjectInstance1(channel, action); 
            break;
        case Action::REGISTER_OBJECT_INSTANCE2:
            retval = execute_RTI_RegisterObjectInstance2(channel, action); 
            break;
        case Action::SEND_INTERACTION3:
            retval = execute_RTI_SendInteraction3(channel, action); 
            break;
        case Action::SEND_INTERACTION4:
            retval = execute_RTI_SendInteraction4(channel, action); 
            break;
        case Action::CREATE_FEDERATION_EXECUTION:
            retval = execute_RTI_CreateFederationExecution(channel, action); 
            break;
        case Action::JOIN_FEDERATION_EXECUTION:
            retval = execute_RTI_JoinFederationExecution(channel, action); 
            break;
        case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES:
            retval = execute_RTI_SubscribeObjectClassAttributes(channel, action); 
            break;
        case Action::DESTROY_FEDERATION_EXECUTION:
            retval = execute_RTI_DestroyFederationExecution(channel, action); 
            break;
        case Action::FEDERATE_RESTORE_COMPLETE:
            retval = execute_RTI_FederateRestoreComplete(channel, action); 
            break;
        case Action::FEDERATE_RESTORE_NOT_COMPLETE:
            retval = execute_RTI_FederateRestoreNotComplete(channel, action); 
            break;
        case Action::FEDERATE_SAVE_BEGUN:
            retval = execute_RTI_FederateSaveBegun(channel, action); 
            break;
        case Action::FEDERATE_SAVE_COMPLETE:
            retval = execute_RTI_FederateSaveComplete(channel, action); 
            break;
        case Action::FEDERATE_SAVE_NOT_COMPLETE:
            retval = execute_RTI_FederateSaveNotComplete(channel, action); 
            break;
        case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT2:
            retval = execute_RTI_RegisterFederationSynchronisationPoint2(channel, action); 
            break;
        case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT3:
            retval = execute_RTI_RegisterFederationSynchronisationPoint3(channel, action); 
            break;
        case Action::REQUEST_FEDERATION_RESTORE:
            retval = execute_RTI_RequestFederationRestore(channel, action); 
            break;
        case Action::REQUEST_FEDERATION_SAVE1:
            retval = execute_RTI_RequestFederationSave1(channel, action); 
            break;
        case Action::REQUEST_FEDERATION_SAVE2:
            retval = execute_RTI_RequestFederationSave2(channel, action);
            break;
        case Action::RESIGN_FEDERATION_EXECUTION:
            retval = execute_RTI_ResignFederationExecution(channel, action);
            break;
        case Action::SYNCHRONISATION_POINT_ACHIEVED:
            retval = execute_RTI_SynchronisationPointAchieved(channel, action);
            break;

            //declaration management
        case Action::PUBLISH_INTERACTION_CLASS:
            retval = execute_RTI_PublishInteractionClass(channel, action);
            break;
        case Action::PUBLISH_OBJECT_CLASS:
            retval = execute_RTI_PublishObjectClass(channel, action);
            break;
        case Action::SUBSCRIBE_INTERACTION_CLASS:
            retval = execute_RTI_SubscribeInteractionClass(channel, action);
            break;
        case Action::UNPUBLISH_INTERACTION_CLASS:
            retval = execute_RTI_UnpublishInteractionClass(channel, action);
            break;
        case Action::UNPUBLISH_OBJECT_CLASS:
            retval = execute_RTI_UnpublishObjectClass(channel, action);
            break;
        case Action::UNSUBSCRIBE_INTERACTION_CLASS:
            retval = execute_RTI_UnsubscribeInteractionClass(channel, action);
            break;
        case Action::UNSUBSCRIBE_OBJECT_CLASS:
            retval = execute_RTI_UnsubscribeObjectClass(channel, action); 
            break;

		
            //object management
        case Action::CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE:
            retval = execute_RTI_ChangeAttributeTransportationType(channel, action); 
            break;
        case Action::CHANGE_INTERACTION_TRANSPORTATION_TYPE:
            retval = execute_RTI_ChangeInteractionTransportationType(channel, action); 
            break;
        case Action::DELETE_OBJECT_INSTANCE2:
            retval = execute_RTI_DeleteObjectInstance2(channel, action); 
            break;
        case Action::DELETE_OBJECT_INSTANCE3:
            retval = execute_RTI_DeleteObjectInstance3(channel, action); 
            break;
        case Action::LOCAL_DELETE_OBJECT_INSTANCE:
            retval = execute_RTI_LocalDeleteObjectInstance(channel, action); 
            break;
        case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE:
            retval = execute_RTI_RequestClassAttributeValueUpdate(channel, action); 
            break;
        case Action::REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE:
            retval = execute_RTI_RequestObjectAttributeValueUpdate(channel, action); 
            break;



            //ownership managment
        case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION:
            retval = execute_RTI_AttributeOwnershipAcquisition(channel, action); 
            break;
        case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE:
            retval = execute_RTI_AttributeOwnershipAcquisitionIfAvailable(channel, action); 
            break;
        case Action::ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE:
            retval = execute_RTI_AttributeOwnershipReleaseResponse(channel, action); 
            break;
        case Action::CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION:
            retval = execute_RTI_CancelAttributeOwnershipAcquisition(channel, action); 
            break;
        case Action::CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
            retval = execute_RTI_CancelNegotiatedAttributeOwnershipDivestiture(channel, action); 
            break;
        case Action::IS_ATTRIBUTE_OWNED_BY_FEDERATE:
            retval = execute_RTI_IsAttributeOwnedByFederate(channel, action); 
            break;
        case Action::NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
            retval = execute_RTI_NegotiatedAttributeOwnershipDivestiture(channel, action); 
            break;
        case Action::QUERY_ATTRIBUTE_OWNERSHIP:
            retval = execute_RTI_QueryAttributeOwnership(channel, action); 
            break;
        case Action::UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
            retval = execute_RTI_UnconditionalAttributeOwnershipDivestiture(channel, action); 
            break;


            //time management
        case Action::ENABLE_TIME_CONSTRAINED:
            retval = execute_RTI_EnableTimeConstrained(channel, action); 
            break;
        case Action::ENABLE_TIME_REGULATION:
            retval = execute_RTI_EnableTimeRegulation(channel, action); 
            break;
        case Action::DISABLE_TIME_CONSTRAINED:
            retval = execute_RTI_DisableTimeConstrained(channel, action); 
            break;
        case Action::DISABLE_TIME_REGULATION:
            retval = execute_RTI_DisableTimeRegulation(channel, action); 
            break;
        case Action::ENABLE_ASYNCHRONOUS_DELIVERY:
            retval = execute_RTI_EnableAsynchronousDelivery(channel, action); 
            break;
        case Action::DISABLE_ASYNCHRONOUS_DELIVERY:
            retval = execute_RTI_DisableAsynchronousDelivery(channel, action); 
            break;
        case Action::CHANGE_ATTRIBUTE_ORDER_TYPE:
            retval = execute_RTI_ChangeAttributeOrderType(channel, action); 
            break;
        case Action::CHANGE_INTERACTION_ORDER_TYPE:
            retval = execute_RTI_ChangeInteractionOrderType(channel, action); 
            break;
        case Action::FLUSH_QUEUE_REQUEST:
            retval = execute_RTI_FlushQueueRequest(channel, action); 
            break;
        case Action::MODIFY_LOOKAHEAD:
            retval = execute_RTI_ModifyLookahead(channel, action); 
            break;
        case Action::NEXT_EVENT_REQUEST:
            retval = execute_RTI_NextEventRequest(channel, action); 
            break;
        case Action::NEXT_EVENT_REQUEST_AVAILABLE:
            retval = execute_RTI_NextEventRequestAvailable(channel, action); 
            break;
        case Action::QUERY_FEDERATE_TIME:
            retval = execute_RTI_QueryFederateTime(channel, action); 
            break;
        case Action::QUERY_LBTS:
            retval = execute_RTI_QueryLbts(channel, action); 
            break;
        case Action::QUERY_LOOKAHEAD:
            retval = execute_RTI_QueryLookahead(channel, action); 
            break;
        case Action::QUERY_MINNEXTEVENTTIME:
            retval = execute_RTI_QueryMinnexteventtime(channel, action); 
            break;
        case Action::RETRACT:
            retval = execute_RTI_Retract(channel, action); 
            break;
        case Action::TIME_ADVANCE_REQUEST:
            retval = execute_RTI_TimeAdvanceRequest(channel, action); 
            break;
        case Action::TIME_ADVANCE_REQUEST_AVAILABLE:
            retval = execute_RTI_TimeAdvanceRequestAvailable(channel, action); 
            break;


            //data distribution management
        case Action::ASSOCIATE_REGION_FOR_UPDATES:
            retval = execute_RTI_AssociateRegionForUpdates(channel, action); 
            break;
        case Action::CREATE_REGION:
            retval = execute_RTI_CreateRegion(channel, action); 
            break;
        case Action::DELETE_REGION:
            retval = execute_RTI_DeleteRegion(channel, action); 
            break;
        case Action::NOTIFY_ABOUT_REGION_MODIFICATION:
            retval = execute_RTI_NotifyAboutRegionModification(channel, action); 
            break;
        case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1:
            retval = execute_RTI_RegisterObjectInstanceWithRegionSub1(channel, action); 
            break;
        case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION4:
            retval = execute_RTI_RegisterObjectInstanceWithRegion4(channel, action); 
            break;
        case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION5:
            retval = execute_RTI_RegisterObjectInstanceWithRegion5(channel, action); 
            break;
        case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION:
            retval = execute_RTI_RequestClassAttributeValueUpdateWithRegion(channel, action); 
            break;
        case Action::SEND_INTERACTION_WITH_REGION4:
            retval = execute_RTI_SendInteractionWithRegion4(channel, action); 
            break;
        case Action::SEND_INTERACTION_WITH_REGION5:
            retval = execute_RTI_SendInteractionWithRegion5(channel, action); 
            break;
        case Action::SUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
            retval = execute_RTI_SubscribeInteractionClassWithRegion(channel, action); 
            break;
        case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION:
            retval = execute_RTI_SubscribeObjectClassAttributesWithRegion(channel, action); 
            break;
        case Action::UNASSOCIATE_REGION_FOR_UPDATES:
            retval = execute_RTI_UnassociateRegionForUpdates(channel, action); 
            break;
        case Action::UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
            retval = execute_RTI_UnsubscribeInteractionClassWithRegion(channel, action); 
            break;
        case Action::UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION:
            retval = execute_RTI_UnsubscribeObjectClassWithRegion(channel, action); 
            break;


            //miscellaneous
        case Action::DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
            retval = execute_RTI_DisableAttributeRelevanceAdvisorySwitch(channel, action); 
            break;
        case Action::DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
            retval = execute_RTI_DisableAttributeScopeAdvisorySwitch(channel, action); 
            break;
        case Action::DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
            retval = execute_RTI_DisableClassRelevanceAdvisorySwitch(channel, action); 
            break;
        case Action::DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
            retval = execute_RTI_DisableInteractionRelevanceAdvisorySwitch(channel, action); 
            break;
        case Action::ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
            retval = execute_RTI_EnableAttributeRelevanceAdvisorySwitch(channel, action); 
            break;
        case Action::ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
            retval = execute_RTI_EnableAttributeScopeAdvisorySwitch(channel, action); 
            break;
        case Action::ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
            retval = execute_RTI_EnableClassRelevanceAdvisorySwitch(channel, action); 
            break;
        case Action::ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
            retval = execute_RTI_EnableInteractionRelevanceAdvisorySwitch(channel, action); 
            break;
        case Action::GET_ATTRIBUTE_HANDLE:
            retval = execute_RTI_GetAttributeHandle(channel, action); 
            break;
        case Action::GET_ATTRIBUTE_NAME:
            retval = execute_RTI_GetAttributeName(channel, action); 
            break;
        case Action::GET_ATTRIBUTE_ROUTING_SPACE_HANDLE:
            retval = execute_RTI_GetAttributeRoutingSpaceHandle(channel, action); 
            break;
        case Action::GET_DIMENSION_HANDLE:
            retval = execute_RTI_GetDimensionHandle(channel, action); 
            break;
        case Action::GET_DIMENSION_NAME:
            retval = execute_RTI_GetDimensionName(channel, action); 
            break;
        case Action::GET_INTERACTION_CLASS_HANDLE:
            retval = execute_RTI_GetInteractionClassHandle(channel, action); 
            break;
        case Action::GET_INTERACTION_CLASS_NAME:
            retval = execute_RTI_GetInteractionClassName(channel, action); 
            break;
        case Action::GET_INTERACTION_ROUTING_SPACE_HANDLE:
            retval = execute_RTI_GetInteractionRoutingSpaceHandle(channel, action); 
            break;
        case Action::GET_OBJECT_CLASS:
            retval = execute_RTI_GetObjectClass(channel, action); 
            break;
        case Action::GET_OBJECT_CLASS_HANDLE:
            retval = execute_RTI_GetObjectClassHandle(channel, action); 
            break;
        case Action::GET_OBJECT_CLASS_NAME:
            retval = execute_RTI_GetObjectClassName(channel, action); 
            break;
        case Action::GET_OBJECT_INSTANCE_HANDLE:
            retval = execute_RTI_GetObjectInstanceHandle(channel, action); 
            break;
        case Action::GET_OBJECT_INSTANCE_NAME:
            retval = execute_RTI_GetObjectInstanceName(channel, action); 
            break;
        case Action::GET_ORDERING_HANDLE:
            retval = execute_RTI_GetOrderingHandle(channel, action); 
            break;
        case Action::GET_ORDERING_NAME:
            retval = execute_RTI_GetOrderingName(channel, action); 
            break;
        case Action::GET_PARAMETER_HANDLE:
            retval = execute_RTI_GetParameterHandle(channel, action); 
            break;
        case Action::GET_PARAMETER_NAME:
            retval = execute_RTI_GetParameterName(channel, action); 
            break;
        case Action::GET_REGION:
            retval = execute_RTI_GetRegion(channel, action); 
            break;
        case Action::GET_REGION_TOKEN:
            retval = execute_RTI_GetRegionToken(channel, action); 
            break;
        case Action::GET_ROUTING_SPACE_HANDLE:
            retval = execute_RTI_GetRoutingSpaceHandle(channel, action); 
            break;
        case Action::GET_ROUTING_SPACE_NAME:
            retval = execute_RTI_GetRoutingSpaceName(channel, action); 
            break;
        case Action::GET_TRANSPORTATION_HANDLE:
            retval = execute_RTI_GetTransportationHandle(channel, action); 
            break;
        case Action::GET_TRANSPORTATION_NAME:
            retval = execute_RTI_GetTransportationName(channel, action); 
            break;
        case Action::TICK0:	
            retval = execute_RTI_Tick0(channel, action); 
            break;
        case Action::TICK2:
            retval = execute_RTI_Tick2(channel, action); 
            break;

            //////////////////////////// FEDERATE AMBASSADOR /////////////
        case Action::TIME_REGULATION_ENABLED:
            retval = execute_Fed_TimeRegulationEnabled(channel, action); 
            break;
        case Action::TIME_CONSTRAINED_ENABLED:
            retval = execute_Fed_TimeConstrainedEnabled(channel, action); 
            break;

		
            //time management
        case Action::REQUEST_RETRACTION:
            retval = execute_Fed_RequestRetraction(channel, action); 
            break;
        case Action::TIME_ADVANCE_GRANT:
            retval = execute_Fed_TimeAdvanceGrant(channel, action); 
            break;


            //federate managment
        case Action::ANNOUNCE_SYNCHRONISATION_POINT:
            retval = execute_Fed_AnnounceSynchronisationPoint(channel, action); 
            break;
        case Action::FEDERATION_NOT_RESTORED:
            retval = execute_Fed_FederationNotRestored(channel, action); 
            break;
        case Action::FEDERATION_NOT_SAVED:
            retval = execute_Fed_FederationNotSaved(channel, action); 
            break;
        case Action::FEDERATION_RESTORE_BEGUN:
            retval = execute_Fed_FederationRestoreBegun(channel, action); 
            break;
        case Action::FEDERATION_RESTORED:
            retval = execute_Fed_FederationRestored(channel, action); 
            break;
        case Action::FEDERATION_SAVED:
            retval = execute_Fed_FederationSaved(channel, action); 
            break;
        case Action::FEDERATION_SYNCHRONISED:
            retval = execute_Fed_FederationSynchronised(channel, action); 
            break;
        case Action::INITIATE_FEDERATE_RESTORE:
            retval = execute_Fed_InitiateFederateRestore(channel, action); 
            break;
        case Action::INITIATE_FEDERATE_SAVE:
            retval = execute_Fed_InitiateFederateSave(channel, action); 
            break;
        case Action::REQUEST_FEDERATION_RESTORE_FAILED:
            retval = execute_Fed_RequestFederationRestoreFailed(channel, action); 
            break;
        case Action::REQUEST_FEDERATION_RESTORE_SUCCEEDED:
            retval = execute_Fed_RequestFederationRestoreSucceeded(channel, action); 
            break;
        case Action::SYNCHRONISATION_POINT_REGISTRATION_FAILED:
            retval = execute_Fed_SynchronisationPointRegistrationFailed(channel, action); 
            break;
        case Action::SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED:
            retval = execute_Fed_SynchronisationPointRegistrationSucceeded(channel, action); 
            break;

            //declaration management
        case Action::START_REGISTRATION_FOR_OBJECT_CLASS:
            retval = execute_Fed_StartRegistrationForObjectClass(channel, action); 
            break;
        case Action::STOP_REGISTRATION_FOR_OBJECT_CLASS:
            retval = execute_Fed_StopRegistrationForObjectClass(channel, action); 
            break;
        case Action::TURN_INTERACTIONS_OFF:
            retval = execute_Fed_TurnInteractionsOff(channel, action); 
            break;
        case Action::TURN_INTERACTIONS_ON:
            retval = execute_Fed_TurnInteractionsOn(channel, action); 
            break;


            //object management
        case Action::ATTRIBUTES_IN_SCOPE:
            retval = execute_Fed_AttributesInScope(channel, action); 
            break;
        case Action::ATTRIBUTES_OUT_OF_SCOPE:
            retval = execute_Fed_AttributesOutOfScope(channel, action); 
            break;
        case Action::DISCOVER_OBJECT_INSTANCE:
            retval = execute_Fed_DiscoverObjectInstance(channel, action); 
            break;
        case Action::PROVIDE_ATTRIBUTE_VALUE_UPDATE:
            retval = execute_Fed_ProvideAttributeValueUpdate(channel, action); 
            break;
        case Action::RECEIVE_INTERACTION3:
            retval = execute_Fed_ReceiveInteraction3(channel, action); 
            break;
        case Action::RECEIVE_INTERACTION5:
            retval = execute_Fed_ReceiveInteraction5(channel, action); 
            break;
        case Action::REFLECT_ATTRIBUTE_VALUES5:
            retval = execute_Fed_ReflectAttributeValues5(channel, action); 
            break;
        case Action::REFLECT_ATTRIBUTE_VALUES3:
            retval = execute_Fed_ReflectAttributeValues3(channel, action); 
            break;
        case Action::REMOVE_OBJECT_INSTANCE2:
            retval = execute_Fed_RemoveObjectInstance2(channel, action); 
            break;
        case Action::REMOVE_OBJECT_INSTANCE4:
            retval = execute_Fed_RemoveObjectInstance4(channel, action); 
            break;
        case Action::TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE:
            retval = execute_Fed_TurnUpdatesOffForObjectInstance(channel, action); 
            break;
        case Action::TURN_UPDATES_ON_FOR_OBJECT_INSTANCE:
            retval = execute_Fed_TurnUpdatesOnForObjectInstance(channel, action); 
            break;


            //ownership managment
        case Action::ATTRIBUTE_IS_NOT_OWNED:
            retval = execute_Fed_AttributeIsNotOwned(channel, action); 
            break;
        case Action::ATTRIBUTE_OWNED_BY_RTI:
            retval = execute_Fed_AttributeOwnedByRti(channel, action); 
            break;
        case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION:
            retval = execute_Fed_AttributeOwnershipAcquisitionNotification(channel, action); 
            break;
        case Action::ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION:
            retval = execute_Fed_AttributeOwnershipDivestitureNotification(channel, action); 
            break;
        case Action::ATTRIBUTE_OWNERSHIP_UNAVAILABLE:
            retval = execute_Fed_AttributeOwnershipUnavailable(channel, action); 
            break;
        case Action::CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION:
            retval = execute_Fed_ConfirmAttributeOwnershipAcquisitionCancellation(channel, action); 
            break;
        case Action::INFORM_ATTRIBUTE_OWNERSHIP:
            retval = execute_Fed_InformAttributeOwnership(channel, action); 
            break;
        case Action::REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION:
            retval = execute_Fed_RequestAttributeOwnershipAssumption(channel, action); 
            break;
        case Action::REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE:
            retval = execute_Fed_RequestAttributeOwnershipRelease(channel, action); 
            break;

        default:
            LOGERR("Unknown Action Context `" << Action_RTI_13NG::getContextAsString(action->actionContext) << "' \n");
            break;
        };
        
        //} catch(RTI::Exception &aException){

        //LOGMSG(4, "Caught an exception: " << aException._name << "\n");
        //LOGMSG(4, "  throwing back to client, ignoring in matis for now.\n");
        
        //if a known exception was caught we should inform the model of this.
        /*Action theExceptionAction;
        theExceptionAction.actionContext = Action::EXCEPTION;
        theExceptionAction.channelId = action->channelId;
        RTI::Exception *newException = &aException;
        TypeConversion_RTI_13NG::addMeta_Exception(&theExceptionAction, newException);
        
        try {

            theExceptionAction.request();

        } catch(...) {

            throw;

            }*/
 
    } catch(...){

        LOGMSG(4, "Caught an exception throwing back to client, ignoring in matis for now.\n");

        //the exception was something else so (for now) continue to
        //throw it back to the client.        
        throw;        

    }

    return retval;

};

/////////////////////////////////////////////////////////////////////
		
#include "Action/Execute_RTI_UpdateAttributeValues4.cpp"
#include "Action/Execute_RTI_UpdateAttributeValues3.cpp"
#include "Action/Execute_RTI_RegisterObjectInstance1.cpp"
#include "Action/Execute_RTI_RegisterObjectInstance2.cpp"
#include "Action/Execute_RTI_SendInteraction3.cpp"
#include "Action/Execute_RTI_SendInteraction4.cpp"
#include "Action/Execute_RTI_CreateFederationExecution.cpp"
#include "Action/Execute_RTI_JoinFederationExecution.cpp"
#include "Action/Execute_RTI_SubscribeObjectClassAttributes.cpp"
#include "Action/Execute_RTI_DestroyFederationExecution.cpp"
#include "Action/Execute_RTI_FederateRestoreComplete.cpp"
#include "Action/Execute_RTI_FederateRestoreNotComplete.cpp"
#include "Action/Execute_RTI_FederateSaveBegun.cpp"
#include "Action/Execute_RTI_FederateSaveComplete.cpp"
#include "Action/Execute_RTI_FederateSaveNotComplete.cpp"
#include "Action/Execute_RTI_RegisterFederationSynchronisationPoint2.cpp"
#include "Action/Execute_RTI_RegisterFederationSynchronisationPoint3.cpp"
#include "Action/Execute_RTI_RequestFederationRestore.cpp"
#include "Action/Execute_RTI_RequestFederationSave1.cpp"
#include "Action/Execute_RTI_RequestFederationSave2.cpp"
#include "Action/Execute_RTI_ResignFederationExecution.cpp"
#include "Action/Execute_RTI_SynchronisationPointAchieved.cpp"
#include "Action/Execute_RTI_PublishInteractionClass.cpp"
#include "Action/Execute_RTI_PublishObjectClass.cpp"
#include "Action/Execute_RTI_SubscribeInteractionClass.cpp"
#include "Action/Execute_RTI_UnpublishInteractionClass.cpp"
#include "Action/Execute_RTI_UnpublishObjectClass.cpp"
#include "Action/Execute_RTI_UnsubscribeInteractionClass.cpp"
#include "Action/Execute_RTI_UnsubscribeObjectClass.cpp"
#include "Action/Execute_RTI_ChangeAttributeTransportationType.cpp"
#include "Action/Execute_RTI_ChangeInteractionTransportationType.cpp"
#include "Action/Execute_RTI_DeleteObjectInstance2.cpp"
#include "Action/Execute_RTI_DeleteObjectInstance3.cpp"
#include "Action/Execute_RTI_LocalDeleteObjectInstance.cpp"
#include "Action/Execute_RTI_RequestClassAttributeValueUpdate.cpp"
#include "Action/Execute_RTI_RequestObjectAttributeValueUpdate.cpp"
#include "Action/Execute_RTI_AttributeOwnershipAcquisition.cpp"
#include "Action/Execute_RTI_AttributeOwnershipAcquisitionIfAvailable.cpp"
#include "Action/Execute_RTI_AttributeOwnershipReleaseResponse.cpp"
#include "Action/Execute_RTI_CancelAttributeOwnershipAcquisition.cpp"
#include "Action/Execute_RTI_CancelNegotiatedAttributeOwnershipDivestiture.cpp"
#include "Action/Execute_RTI_IsAttributeOwnedByFederate.cpp"
#include "Action/Execute_RTI_NegotiatedAttributeOwnershipDivestiture.cpp"
#include "Action/Execute_RTI_QueryAttributeOwnership.cpp"
#include "Action/Execute_RTI_UnconditionalAttributeOwnershipDivestiture.cpp"
#include "Action/Execute_RTI_EnableTimeConstrained.cpp"
#include "Action/Execute_RTI_EnableTimeRegulation.cpp"
#include "Action/Execute_RTI_DisableTimeConstrained.cpp"
#include "Action/Execute_RTI_DisableTimeRegulation.cpp"
#include "Action/Execute_RTI_EnableAsynchronousDelivery.cpp"
#include "Action/Execute_RTI_DisableAsynchronousDelivery.cpp"
#include "Action/Execute_RTI_ChangeAttributeOrderType.cpp"
#include "Action/Execute_RTI_ChangeInteractionOrderType.cpp"
#include "Action/Execute_RTI_FlushQueueRequest.cpp"
#include "Action/Execute_RTI_ModifyLookahead.cpp"
#include "Action/Execute_RTI_NextEventRequest.cpp"
#include "Action/Execute_RTI_NextEventRequestAvailable.cpp"
#include "Action/Execute_RTI_QueryFederateTime.cpp"
#include "Action/Execute_RTI_QueryLbts.cpp"
#include "Action/Execute_RTI_QueryLookahead.cpp"
#include "Action/Execute_RTI_QueryMinnexteventtime.cpp"
#include "Action/Execute_RTI_Retract.cpp"
#include "Action/Execute_RTI_TimeAdvanceRequest.cpp"
#include "Action/Execute_RTI_TimeAdvanceRequestAvailable.cpp"
#include "Action/Execute_RTI_AssociateRegionForUpdates.cpp"
#include "Action/Execute_RTI_CreateRegion.cpp"
#include "Action/Execute_RTI_DeleteRegion.cpp"
#include "Action/Execute_RTI_NotifyAboutRegionModification.cpp"
#include "Action/Execute_RTI_RegisterObjectInstanceWithRegionSub1.cpp"
#include "Action/Execute_RTI_RegisterObjectInstanceWithRegion4.cpp"
#include "Action/Execute_RTI_RegisterObjectInstanceWithRegion5.cpp"
#include "Action/Execute_RTI_RequestClassAttributeValueUpdateWithRegion.cpp"
#include "Action/Execute_RTI_SendInteractionWithRegion4.cpp"
#include "Action/Execute_RTI_SendInteractionWithRegion5.cpp"
#include "Action/Execute_RTI_SubscribeInteractionClassWithRegion.cpp"
#include "Action/Execute_RTI_SubscribeObjectClassAttributesWithRegion.cpp"
#include "Action/Execute_RTI_UnassociateRegionForUpdates.cpp"
#include "Action/Execute_RTI_UnsubscribeInteractionClassWithRegion.cpp"
#include "Action/Execute_RTI_UnsubscribeObjectClassWithRegion.cpp"
#include "Action/Execute_RTI_DisableAttributeRelevanceAdvisorySwitch.cpp"
#include "Action/Execute_RTI_DisableAttributeScopeAdvisorySwitch.cpp"
#include "Action/Execute_RTI_DisableClassRelevanceAdvisorySwitch.cpp"
#include "Action/Execute_RTI_DisableInteractionRelevanceAdvisorySwitch.cpp"
#include "Action/Execute_RTI_EnableAttributeRelevanceAdvisorySwitch.cpp"
#include "Action/Execute_RTI_EnableAttributeScopeAdvisorySwitch.cpp"
#include "Action/Execute_RTI_EnableClassRelevanceAdvisorySwitch.cpp"
#include "Action/Execute_RTI_EnableInteractionRelevanceAdvisorySwitch.cpp"
#include "Action/Execute_RTI_GetAttributeHandle.cpp"
#include "Action/Execute_RTI_GetAttributeName.cpp"
#include "Action/Execute_RTI_GetAttributeRoutingSpaceHandle.cpp"
#include "Action/Execute_RTI_GetDimensionHandle.cpp"
#include "Action/Execute_RTI_GetDimensionName.cpp"
#include "Action/Execute_RTI_GetInteractionClassHandle.cpp"
#include "Action/Execute_RTI_GetInteractionClassName.cpp"
#include "Action/Execute_RTI_GetInteractionRoutingSpaceHandle.cpp"
#include "Action/Execute_RTI_GetObjectClass.cpp"
#include "Action/Execute_RTI_GetObjectClassHandle.cpp"
#include "Action/Execute_RTI_GetObjectClassName.cpp"
#include "Action/Execute_RTI_GetObjectInstanceHandle.cpp"
#include "Action/Execute_RTI_GetObjectInstanceName.cpp"
#include "Action/Execute_RTI_GetOrderingHandle.cpp"
#include "Action/Execute_RTI_GetOrderingName.cpp"
#include "Action/Execute_RTI_GetParameterHandle.cpp"
#include "Action/Execute_RTI_GetParameterName.cpp"
#include "Action/Execute_RTI_GetRegion.cpp"
#include "Action/Execute_RTI_GetRegionToken.cpp"
#include "Action/Execute_RTI_GetRoutingSpaceHandle.cpp"
#include "Action/Execute_RTI_GetRoutingSpaceName.cpp"
#include "Action/Execute_RTI_GetTransportationHandle.cpp"
#include "Action/Execute_RTI_GetTransportationName.cpp"
#include "Action/Execute_RTI_Tick0.cpp"
#include "Action/Execute_RTI_Tick2.cpp"
#include "Action/Execute_Fed_TimeRegulationEnabled.cpp"
#include "Action/Execute_Fed_TimeConstrainedEnabled.cpp"
#include "Action/Execute_Fed_RequestRetraction.cpp"
#include "Action/Execute_Fed_TimeAdvanceGrant.cpp"
#include "Action/Execute_Fed_AnnounceSynchronisationPoint.cpp"
#include "Action/Execute_Fed_FederationNotRestored.cpp"
#include "Action/Execute_Fed_FederationNotSaved.cpp"
#include "Action/Execute_Fed_FederationRestoreBegun.cpp"
#include "Action/Execute_Fed_FederationRestored.cpp"
#include "Action/Execute_Fed_FederationSaved.cpp"
#include "Action/Execute_Fed_FederationSynchronised.cpp"
#include "Action/Execute_Fed_InitiateFederateRestore.cpp"
#include "Action/Execute_Fed_InitiateFederateSave.cpp"
#include "Action/Execute_Fed_RequestFederationRestoreFailed.cpp"
#include "Action/Execute_Fed_RequestFederationRestoreSucceeded.cpp"
#include "Action/Execute_Fed_SynchronisationPointRegistrationFailed.cpp"
#include "Action/Execute_Fed_SynchronisationPointRegistrationSucceeded.cpp"
#include "Action/Execute_Fed_StartRegistrationForObjectClass.cpp"
#include "Action/Execute_Fed_StopRegistrationForObjectClass.cpp"
#include "Action/Execute_Fed_TurnInteractionsOff.cpp"
#include "Action/Execute_Fed_TurnInteractionsOn.cpp"
#include "Action/Execute_Fed_AttributesInScope.cpp"
#include "Action/Execute_Fed_AttributesOutOfScope.cpp"
#include "Action/Execute_Fed_DiscoverObjectInstance.cpp"
#include "Action/Execute_Fed_ProvideAttributeValueUpdate.cpp"
#include "Action/Execute_Fed_ReceiveInteraction3.cpp"
#include "Action/Execute_Fed_ReceiveInteraction5.cpp"
#include "Action/Execute_Fed_ReflectAttributeValues5.cpp"
#include "Action/Execute_Fed_ReflectAttributeValues3.cpp"
#include "Action/Execute_Fed_RemoveObjectInstance2.cpp"
#include "Action/Execute_Fed_RemoveObjectInstance4.cpp"
#include "Action/Execute_Fed_TurnUpdatesOffForObjectInstance.cpp"
#include "Action/Execute_Fed_TurnUpdatesOnForObjectInstance.cpp"
#include "Action/Execute_Fed_AttributeIsNotOwned.cpp"
#include "Action/Execute_Fed_AttributeOwnedByRti.cpp"
#include "Action/Execute_Fed_AttributeOwnershipAcquisitionNotification.cpp"
#include "Action/Execute_Fed_AttributeOwnershipDivestitureNotification.cpp"
#include "Action/Execute_Fed_AttributeOwnershipUnavailable.cpp"
#include "Action/Execute_Fed_ConfirmAttributeOwnershipAcquisitionCancellation.cpp"
#include "Action/Execute_Fed_InformAttributeOwnership.cpp"
#include "Action/Execute_Fed_RequestAttributeOwnershipAssumption.cpp"
#include "Action/Execute_Fed_RequestAttributeOwnershipRelease.cpp"



/////////////////////////////////////////////



// JUNK YARD

//         theExceptionAction.actionException = Action::EXCEPT_ArrayIndexOutOfBounds;
//         newException = &aException;
    
//     } catch(RTI::AsynchronousDeliveryAlreadyDisabled &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AsynchronousDeliveryAlreadyDisabled;
//         newException = &aException;

            
//     } catch(RTI::AsynchronousDeliveryAlreadyEnabled &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AsynchronousDeliveryAlreadyEnabled;
//         newException = &aException;

            
//     } catch(RTI::AttributeAcquisitionWasNotRequested &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeAcquisitionWasNotRequested;
//         newException = &aException;

            
//     } catch(RTI::AttributeAcquisitionWasNotCanceled &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeAcquisitionWasNotCanceled;
//         newException = &aException;

            
//     } catch(RTI::AttributeAlreadyBeingAcquired &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeAlreadyBeingAcquired;
//         newException = &aException;

            
//     } catch(RTI::AttributeAlreadyBeingDivested &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeAlreadyBeingDivested;
//         newException = &aException;

            
//     } catch(RTI::AttributeAlreadyOwned &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeAlreadyOwned;
//         newException = &aException;

            
//     } catch(RTI::AttributeDivestitureWasNotRequested &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeDivestitureWasNotRequested;
//         newException = &aException;

            
//     } catch(RTI::AttributeNotDefined &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeNotDefined;
//         newException = &aException;

            
//     } catch(RTI::AttributeNotKnown &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeNotKnown;
//         newException = &aException;

            
//     } catch(RTI::AttributeNotOwned &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeNotOwned;
//         newException = &aException;

            
//     } catch(RTI::AttributeNotPublished &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_AttributeNotPublished;
//         newException = &aException;

            
//     } catch(RTI::ConcurrentAccessAttempted &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ConcurrentAccessAttempted;
//         newException = &aException;

            
//     } catch(RTI::CouldNotDiscover &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_CouldNotDiscover;
//         newException = &aException;

            
//     } catch(RTI::CouldNotOpenFED &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_CouldNotOpenFED;
//         newException = &aException;

            
//     } catch(RTI::CouldNotRestore &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_CouldNotRestore;
//         newException = &aException;

            
//     } catch(RTI::DeletePrivilegeNotHeld &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_DeletePrivilegeNotHeld;
//         newException = &aException;

            
//     } catch(RTI::DimensionNotDefined &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_DimensionNotDefined;
//         newException = &aException;

            
//     } catch(RTI::EnableTimeConstrainedPending &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_EnableTimeConstrainedPending;
//         newException = &aException;

            
//     } catch(RTI::EnableTimeConstrainedWasNotPending &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_EnableTimeConstrainedWasNotPending;
//         newException = &aException;

            
//     } catch(RTI::EnableTimeRegulationPending &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_EnableTimeRegulationPending;
//         newException = &aException;

            
//     } catch(RTI::EnableTimeRegulationWasNotPending &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_EnableTimeRegulationWasNotPending;
//         newException = &aException;

            
//     } catch(RTI::ErrorReadingFED &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ErrorReadingFED;
//         newException = &aException;

            
//     } catch(RTI::EventNotKnown &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_EventNotKnown;
//         newException = &aException;

            
//     } catch(RTI::FederateAlreadyExecutionMember &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederateAlreadyExecutionMember;
//         newException = &aException;

            
//     } catch(RTI::FederateInternalError &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederateInternalError;
//         newException = &aException;

            
//     } catch(RTI::FederateLoggingServiceCalls &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederateLoggingServiceCalls;
//         newException = &aException;

            
//     } catch(RTI::FederateNotExecutionMember &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederateNotExecutionMember;
//         newException = &aException;

            
//     } catch(RTI::FederateOwnsAttributes &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederateOwnsAttributes;
//         newException = &aException;

            
//     } catch(RTI::FederateWasNotAskedToReleaseAttribute &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederateWasNotAskedToReleaseAttribute;
//         newException = &aException;

            
//     } catch(RTI::FederatesCurrentlyJoined &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederatesCurrentlyJoined;
//         newException = &aException;

            
//     } catch(RTI::FederationExecutionAlreadyExists &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederationExecutionAlreadyExists;
//         newException = &aException;

            
//     } catch(RTI::FederationExecutionDoesNotExist &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederationExecutionDoesNotExist;
//         newException = &aException;

            
//     } catch(RTI::FederationTimeAlreadyPassed &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_FederationTimeAlreadyPassed;
//         newException = &aException;

            
//     } catch(RTI::HandleValuePairMaximumExceeded &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_HandleValuePairMaximumExceeded;
//         newException = &aException;

            
//     } catch(RTI::InteractionClassNotDefined &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InteractionClassNotDefined;
//         newException = &aException;

            
//     } catch(RTI::InteractionClassNotKnown &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InteractionClassNotKnown;
//         newException = &aException;

            
//     } catch(RTI::InteractionClassNotPublished &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InteractionClassNotPublished;
//         newException = &aException;

            
//     } catch(RTI::InteractionClassNotSubscribed &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InteractionClassNotSubscribed;
//         newException = &aException;

            
//     } catch(RTI::InteractionParameterNotDefined &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InteractionParameterNotDefined;
//         newException = &aException;

            
//     } catch(RTI::InteractionParameterNotKnown &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InteractionParameterNotKnown;
//         newException = &aException;

            
//     } catch(RTI::InvalidExtents &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidExtents;
//         newException = &aException;

            
//     } catch(RTI::InvalidFederationTime &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidFederationTime;
//         newException = &aException;

            
//     } catch(RTI::InvalidHandleValuePairSetContext &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidHandleValuePairSetContext;
//         newException = &aException;

            
//     } catch(RTI::InvalidLookahead &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidLookahead;
//         newException = &aException;

            
//     } catch(RTI::InvalidOrderingHandle &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidOrderingHandle;
//         newException = &aException;

            
//     } catch(RTI::InvalidRegionContext &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidRegionContext;
//         newException = &aException;

            
//     } catch(RTI::InvalidResignAction &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidResignAction;
//         newException = &aException;

            
//     } catch(RTI::InvalidRetractionHandle &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidRetractionHandle;
//         newException = &aException;

            
//     } catch(RTI::InvalidTransportationHandle &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_InvalidTransportationHandle;
//         newException = &aException;

            
//     } catch(RTI::MemoryExhausted &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_MemoryExhausted;
//         newException = &aException;

            
//     } catch(RTI::NameNotFound &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_NameNotFound;
//         newException = &aException;

            
//     } catch(RTI::ObjectClassNotDefined &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ObjectClassNotDefined;
//         newException = &aException;

            
//     } catch(RTI::ObjectClassNotKnown &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ObjectClassNotKnown;
//         newException = &aException;

            
//     } catch(RTI::ObjectClassNotPublished &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ObjectClassNotPublished;
//         newException = &aException;

            
//     } catch(RTI::ObjectClassNotSubscribed &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ObjectClassNotSubscribed;
//         newException = &aException;

            
//     } catch(RTI::ObjectNotKnown &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ObjectNotKnown;
//         newException = &aException;

            
//     } catch(RTI::ObjectAlreadyRegistered &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ObjectAlreadyRegistered;
//         newException = &aException;

            
//     } catch(RTI::OwnershipAcquisitionPending &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_OwnershipAcquisitionPending;
//         newException = &aException;

            
//     } catch(RTI::RegionInUse &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_RegionInUse;
//         newException = &aException;

            
//     } catch(RTI::RegionNotKnown &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_RegionNotKnown;
//         newException = &aException;

            
//     } catch(RTI::RestoreInProgress &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_RestoreInProgress;
//         newException = &aException;

            
//     } catch(RTI::RestoreNotRequested &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_RestoreNotRequested;
//         newException = &aException;

            
//     } catch(RTI::RTIinternalError &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_RTIinternalError;
//         newException = &aException;

            
//     } catch(RTI::SpaceNotDefined &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_SpaceNotDefined;
//         newException = &aException;

            
//     } catch(RTI::SaveInProgress &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_SaveInProgress;
//         newException = &aException;

            
//     } catch(RTI::SaveNotInitiated &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_SaveNotInitiated;
//         newException = &aException;

            
//     } catch(RTI::SpecifiedSaveLabelDoesNotExist &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_SpecifiedSaveLabelDoesNotExist;
//         newException = &aException;

            
//     } catch(RTI::SynchronizationPointLabelWasNotAnnounced &aException) {

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_SynchronizationPointLabelWasNotAnnounced;
//         newException = &aException;

            
//     } catch(RTI::TimeAdvanceAlreadyInProgress &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_TimeAdvanceAlreadyInProgress;
//         newException = &aException;

            
//     } catch(RTI::TimeAdvanceWasNotInProgress &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_TimeAdvanceWasNotInProgress;
//         newException = &aException;

            
//     } catch(RTI::TimeConstrainedAlreadyEnabled &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_TimeConstrainedAlreadyEnabled;
//         newException = &aException;

            
//     } catch(RTI::TimeConstrainedWasNotEnabled &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_TimeConstrainedWasNotEnabled;
//         newException = &aException;

            
//     } catch(RTI::TimeRegulationAlreadyEnabled &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_TimeRegulationAlreadyEnabled;
//         newException = &aException;

            
//     } catch(RTI::TimeRegulationWasNotEnabled &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_TimeRegulationWasNotEnabled;
//         newException = &aException;

            
//     } catch(RTI::UnableToPerformSave &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_UnableToPerformSave;
//         newException = &aException;

            
//     } catch(RTI::ValueCountExceeded &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ValueCountExceeded;
//         newException = &aException;

            
//     } catch(RTI::ValueLengthExceeded &aException){

//         exceptionCaught = true;
//         theExceptionAction.actionException = Action::EXCEPT_ValueLengthExceeded;
//         newException = &aException;
