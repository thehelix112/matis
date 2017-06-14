// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_ActionUtil_RTI_13NG.cpp,v $
// CVS $Date: 2006/01/16 13:41:03 $
// CVS $Revision: 1.4 $


#include "MATIS_TypeConversion_RTI_13NG.h"
#include "MATIS_Action_RTI_13NG.h"
#include "MATIS_Types.h"

using namespace MATIS;

bool Action_RTI_13NG::isContextIncoming(handleType context){
    
    LOGMSG(5, "action context: " << context << ".\n");

    switch(context) {

    case Action::NOP:
        return false;
        break;
        
        //federation management
    case Action::CREATE_FEDERATION_EXECUTION:
    case Action::DESTROY_FEDERATION_EXECUTION:
    case Action::FEDERATE_RESTORE_COMPLETE:
    case Action::FEDERATE_RESTORE_NOT_COMPLETE:
    case Action::FEDERATE_SAVE_BEGUN:
    case Action::FEDERATE_SAVE_COMPLETE:
    case Action::FEDERATE_SAVE_NOT_COMPLETE:
    case Action::JOIN_FEDERATION_EXECUTION:
    case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT2:
    case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT3:
    case Action::REQUEST_FEDERATION_RESTORE:
    case Action::REQUEST_FEDERATION_SAVE1:
    case Action::REQUEST_FEDERATION_SAVE2:
    case Action::RESIGN_FEDERATION_EXECUTION:
    case Action::SYNCHRONISATION_POINT_ACHIEVED:		

        //declaration management
    case Action::PUBLISH_INTERACTION_CLASS:
    case Action::PUBLISH_OBJECT_CLASS:
    case Action::SUBSCRIBE_INTERACTION_CLASS:
    case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES:
    case Action::UNPUBLISH_INTERACTION_CLASS:
    case Action::UNPUBLISH_OBJECT_CLASS:
    case Action::UNSUBSCRIBE_INTERACTION_CLASS:
    case Action::UNSUBSCRIBE_OBJECT_CLASS:

        //ownership management
    case Action::CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE:
    case Action::CHANGE_INTERACTION_TRANSPORTATION_TYPE:
    case Action::DELETE_OBJECT_INSTANCE2:
    case Action::DELETE_OBJECT_INSTANCE3:
    case Action::LOCAL_DELETE_OBJECT_INSTANCE:
    case Action::REGISTER_OBJECT_INSTANCE1:
    case Action::REGISTER_OBJECT_INSTANCE2:
    case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE:
    case Action::REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE:
    case Action::SEND_INTERACTION3:
    case Action::SEND_INTERACTION4:
    case Action::UPDATE_ATTRIBUTE_VALUES4:
    case Action::UPDATE_ATTRIBUTE_VALUES3:

        //time management
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION:
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE:
    case Action::ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE:
    case Action::CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION:
    case Action::CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
    case Action::IS_ATTRIBUTE_OWNED_BY_FEDERATE:
    case Action::NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
    case Action::QUERY_ATTRIBUTE_OWNERSHIP:
    case Action::UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE:		

        //time management
    case Action::ENABLE_TIME_CONSTRAINED:
    case Action::ENABLE_TIME_REGULATION:
    case Action::DISABLE_TIME_CONSTRAINED:
    case Action::DISABLE_TIME_REGULATION:
    case Action::ENABLE_ASYNCHRONOUS_DELIVERY:
    case Action::DISABLE_ASYNCHRONOUS_DELIVERY:
    case Action::CHANGE_ATTRIBUTE_ORDER_TYPE:
    case Action::CHANGE_INTERACTION_ORDER_TYPE:
    case Action::FLUSH_QUEUE_REQUEST:
    case Action::MODIFY_LOOKAHEAD:
    case Action::NEXT_EVENT_REQUEST:
    case Action::NEXT_EVENT_REQUEST_AVAILABLE:
    case Action::QUERY_FEDERATE_TIME:
    case Action::QUERY_LBTS:
    case Action::QUERY_LOOKAHEAD:
    case Action::QUERY_MINNEXTEVENTTIME:
    case Action::RETRACT:
    case Action::TIME_ADVANCE_REQUEST:
    case Action::TIME_ADVANCE_REQUEST_AVAILABLE:

        //data distribution
    case Action::ASSOCIATE_REGION_FOR_UPDATES:
    case Action::CREATE_REGION:
    case Action::DELETE_REGION:
    case Action::NOTIFY_ABOUT_REGION_MODIFICATION:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION4:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION5:
    case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION:
    case Action::SEND_INTERACTION_WITH_REGION4:
    case Action::SEND_INTERACTION_WITH_REGION5:
    case Action::SUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
    case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION:
    case Action::UNASSOCIATE_REGION_FOR_UPDATES:
    case Action::UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
    case Action::UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION:

        //miscellaneous
    case Action::DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
    case Action::DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
    case Action::DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
    case Action::DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
    case Action::ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
    case Action::ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
    case Action::ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
    case Action::ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
    case Action::GET_ATTRIBUTE_HANDLE:
    case Action::GET_ATTRIBUTE_NAME:
    case Action::GET_ATTRIBUTE_ROUTING_SPACE_HANDLE:
    case Action::GET_DIMENSION_HANDLE:
    case Action::GET_DIMENSION_NAME:
    case Action::GET_INTERACTION_CLASS_HANDLE:
    case Action::GET_INTERACTION_CLASS_NAME:
    case Action::GET_INTERACTION_ROUTING_SPACE_HANDLE:
    case Action::GET_OBJECT_CLASS:
    case Action::GET_OBJECT_CLASS_HANDLE:
    case Action::GET_OBJECT_CLASS_NAME:
    case Action::GET_OBJECT_INSTANCE_HANDLE:
    case Action::GET_OBJECT_INSTANCE_NAME:
    case Action::GET_ORDERING_HANDLE:
    case Action::GET_ORDERING_NAME:
    case Action::GET_PARAMETER_HANDLE:
    case Action::GET_PARAMETER_NAME:
    case Action::GET_REGION:
    case Action::GET_REGION_TOKEN:
    case Action::GET_ROUTING_SPACE_HANDLE:
    case Action::GET_ROUTING_SPACE_NAME:
    case Action::GET_TRANSPORTATION_HANDLE:
    case Action::GET_TRANSPORTATION_NAME:
    case Action::TICK0:
    case Action::TICK2:
        return false;
        break;        

        /////////// FEDERATE AMBASSADOR ///////////////////

        //time management
    case Action::REQUEST_RETRACTION:
    case Action::TIME_ADVANCE_GRANT:
    case Action::TIME_REGULATION_ENABLED:
    case Action::TIME_CONSTRAINED_ENABLED:
		

        //federate managment
    case Action::ANNOUNCE_SYNCHRONISATION_POINT:
    case Action::FEDERATION_NOT_RESTORED:
    case Action::FEDERATION_NOT_SAVED:
    case Action::FEDERATION_RESTORE_BEGUN:
    case Action::FEDERATION_RESTORED:
    case Action::FEDERATION_SAVED:
    case Action::FEDERATION_SYNCHRONISED:
    case Action::INITIATE_FEDERATE_RESTORE:
    case Action::INITIATE_FEDERATE_SAVE:
    case Action::REQUEST_FEDERATION_RESTORE_FAILED:
    case Action::REQUEST_FEDERATION_RESTORE_SUCCEEDED:
    case Action::SYNCHRONISATION_POINT_REGISTRATION_FAILED:
    case Action::SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED:
		

        //declaration management
    case Action::START_REGISTRATION_FOR_OBJECT_CLASS:
    case Action::STOP_REGISTRATION_FOR_OBJECT_CLASS:
    case Action::TURN_INTERACTIONS_OFF:
    case Action::TURN_INTERACTIONS_ON:
		

        //object management
    case Action::ATTRIBUTES_IN_SCOPE:
    case Action::ATTRIBUTES_OUT_OF_SCOPE:
    case Action::DISCOVER_OBJECT_INSTANCE:
    case Action::PROVIDE_ATTRIBUTE_VALUE_UPDATE:
    case Action::RECEIVE_INTERACTION3:
    case Action::RECEIVE_INTERACTION5:
    case Action::REFLECT_ATTRIBUTE_VALUES3:
    case Action::REFLECT_ATTRIBUTE_VALUES5:
    case Action::REMOVE_OBJECT_INSTANCE2:
    case Action::REMOVE_OBJECT_INSTANCE4:
    case Action::TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE:
    case Action::TURN_UPDATES_ON_FOR_OBJECT_INSTANCE:
		

        //ownership managment
    case Action::ATTRIBUTE_IS_NOT_OWNED:
    case Action::ATTRIBUTE_OWNED_BY_RTI:
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION:
    case Action::ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION:
    case Action::ATTRIBUTE_OWNERSHIP_UNAVAILABLE:
    case Action::CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION:
    case Action::INFORM_ATTRIBUTE_OWNERSHIP:
    case Action::REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION:
    case Action::REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE:
        return true;
        break;
        
    default:
        LOGERR("Unknown action context " << context << "\n");
        break;		
    };

    return false;

}


bool Action_RTI_13NG::isContextOutgoing(handleType context){
    
    LOGMSG(5, "action context: " << context << ".\n");

    switch(context) {

    case Action::NOP:
        return false;
        break;
        
        //federation management
    case Action::CREATE_FEDERATION_EXECUTION:
    case Action::DESTROY_FEDERATION_EXECUTION:
    case Action::FEDERATE_RESTORE_COMPLETE:
    case Action::FEDERATE_RESTORE_NOT_COMPLETE:
    case Action::FEDERATE_SAVE_BEGUN:
    case Action::FEDERATE_SAVE_COMPLETE:
    case Action::FEDERATE_SAVE_NOT_COMPLETE:
    case Action::JOIN_FEDERATION_EXECUTION:
    case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT2:
    case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT3:
    case Action::REQUEST_FEDERATION_RESTORE:
    case Action::REQUEST_FEDERATION_SAVE1:
    case Action::REQUEST_FEDERATION_SAVE2:
    case Action::RESIGN_FEDERATION_EXECUTION:
    case Action::SYNCHRONISATION_POINT_ACHIEVED:		

        //declaration management
    case Action::PUBLISH_INTERACTION_CLASS:
    case Action::PUBLISH_OBJECT_CLASS:
    case Action::SUBSCRIBE_INTERACTION_CLASS:
    case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES:
    case Action::UNPUBLISH_INTERACTION_CLASS:
    case Action::UNPUBLISH_OBJECT_CLASS:
    case Action::UNSUBSCRIBE_INTERACTION_CLASS:
    case Action::UNSUBSCRIBE_OBJECT_CLASS:

        //ownership management
    case Action::CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE:
    case Action::CHANGE_INTERACTION_TRANSPORTATION_TYPE:
    case Action::DELETE_OBJECT_INSTANCE2:
    case Action::DELETE_OBJECT_INSTANCE3:
    case Action::LOCAL_DELETE_OBJECT_INSTANCE:
    case Action::REGISTER_OBJECT_INSTANCE1:
    case Action::REGISTER_OBJECT_INSTANCE2:
    case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE:
    case Action::REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE:
    case Action::SEND_INTERACTION3:
    case Action::SEND_INTERACTION4:
    case Action::UPDATE_ATTRIBUTE_VALUES4:
    case Action::UPDATE_ATTRIBUTE_VALUES3:

        //time management
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION:
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE:
    case Action::ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE:
    case Action::CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION:
    case Action::CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
    case Action::IS_ATTRIBUTE_OWNED_BY_FEDERATE:
    case Action::NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
    case Action::QUERY_ATTRIBUTE_OWNERSHIP:
    case Action::UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE:		

        //time management
    case Action::ENABLE_TIME_CONSTRAINED:
    case Action::ENABLE_TIME_REGULATION:
    case Action::DISABLE_TIME_CONSTRAINED:
    case Action::DISABLE_TIME_REGULATION:
    case Action::ENABLE_ASYNCHRONOUS_DELIVERY:
    case Action::DISABLE_ASYNCHRONOUS_DELIVERY:
    case Action::CHANGE_ATTRIBUTE_ORDER_TYPE:
    case Action::CHANGE_INTERACTION_ORDER_TYPE:
    case Action::FLUSH_QUEUE_REQUEST:
    case Action::MODIFY_LOOKAHEAD:
    case Action::NEXT_EVENT_REQUEST:
    case Action::NEXT_EVENT_REQUEST_AVAILABLE:
    case Action::QUERY_FEDERATE_TIME:
    case Action::QUERY_LBTS:
    case Action::QUERY_LOOKAHEAD:
    case Action::QUERY_MINNEXTEVENTTIME:
    case Action::RETRACT:
    case Action::TIME_ADVANCE_REQUEST:
    case Action::TIME_ADVANCE_REQUEST_AVAILABLE:

        //data distribution
    case Action::ASSOCIATE_REGION_FOR_UPDATES:
    case Action::CREATE_REGION:
    case Action::DELETE_REGION:
    case Action::NOTIFY_ABOUT_REGION_MODIFICATION:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION4:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION5:
    case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION:
    case Action::SEND_INTERACTION_WITH_REGION4:
    case Action::SEND_INTERACTION_WITH_REGION5:
    case Action::SUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
    case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION:
    case Action::UNASSOCIATE_REGION_FOR_UPDATES:
    case Action::UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
    case Action::UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION:

        //miscellaneous
    case Action::DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
    case Action::DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
    case Action::DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
    case Action::DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
    case Action::ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
    case Action::ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
    case Action::ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
    case Action::ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
    case Action::GET_ATTRIBUTE_HANDLE:
    case Action::GET_ATTRIBUTE_NAME:
    case Action::GET_ATTRIBUTE_ROUTING_SPACE_HANDLE:
    case Action::GET_DIMENSION_HANDLE:
    case Action::GET_DIMENSION_NAME:
    case Action::GET_INTERACTION_CLASS_HANDLE:
    case Action::GET_INTERACTION_CLASS_NAME:
    case Action::GET_INTERACTION_ROUTING_SPACE_HANDLE:
    case Action::GET_OBJECT_CLASS:
    case Action::GET_OBJECT_CLASS_HANDLE:
    case Action::GET_OBJECT_CLASS_NAME:
    case Action::GET_OBJECT_INSTANCE_HANDLE:
    case Action::GET_OBJECT_INSTANCE_NAME:
    case Action::GET_ORDERING_HANDLE:
    case Action::GET_ORDERING_NAME:
    case Action::GET_PARAMETER_HANDLE:
    case Action::GET_PARAMETER_NAME:
    case Action::GET_REGION:
    case Action::GET_REGION_TOKEN:
    case Action::GET_ROUTING_SPACE_HANDLE:
    case Action::GET_ROUTING_SPACE_NAME:
    case Action::GET_TRANSPORTATION_HANDLE:
    case Action::GET_TRANSPORTATION_NAME:
    case Action::TICK0:
    case Action::TICK2:
        return true;
        break;        

        /////////// FEDERATE AMBASSADOR ///////////////////

        //time management
    case Action::REQUEST_RETRACTION:
    case Action::TIME_ADVANCE_GRANT:
    case Action::TIME_REGULATION_ENABLED:
    case Action::TIME_CONSTRAINED_ENABLED:
		

        //federate managment
    case Action::ANNOUNCE_SYNCHRONISATION_POINT:
    case Action::FEDERATION_NOT_RESTORED:
    case Action::FEDERATION_NOT_SAVED:
    case Action::FEDERATION_RESTORE_BEGUN:
    case Action::FEDERATION_RESTORED:
    case Action::FEDERATION_SAVED:
    case Action::FEDERATION_SYNCHRONISED:
    case Action::INITIATE_FEDERATE_RESTORE:
    case Action::INITIATE_FEDERATE_SAVE:
    case Action::REQUEST_FEDERATION_RESTORE_FAILED:
    case Action::REQUEST_FEDERATION_RESTORE_SUCCEEDED:
    case Action::SYNCHRONISATION_POINT_REGISTRATION_FAILED:
    case Action::SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED:
		

        //declaration management
    case Action::START_REGISTRATION_FOR_OBJECT_CLASS:
    case Action::STOP_REGISTRATION_FOR_OBJECT_CLASS:
    case Action::TURN_INTERACTIONS_OFF:
    case Action::TURN_INTERACTIONS_ON:
		

        //object management
    case Action::ATTRIBUTES_IN_SCOPE:
    case Action::ATTRIBUTES_OUT_OF_SCOPE:
    case Action::DISCOVER_OBJECT_INSTANCE:
    case Action::PROVIDE_ATTRIBUTE_VALUE_UPDATE:
    case Action::RECEIVE_INTERACTION3:
    case Action::RECEIVE_INTERACTION5:
    case Action::REFLECT_ATTRIBUTE_VALUES3:
    case Action::REFLECT_ATTRIBUTE_VALUES5:
    case Action::REMOVE_OBJECT_INSTANCE2:
    case Action::REMOVE_OBJECT_INSTANCE4:
    case Action::TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE:
    case Action::TURN_UPDATES_ON_FOR_OBJECT_INSTANCE:
		

        //ownership managment
    case Action::ATTRIBUTE_IS_NOT_OWNED:
    case Action::ATTRIBUTE_OWNED_BY_RTI:
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION:
    case Action::ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION:
    case Action::ATTRIBUTE_OWNERSHIP_UNAVAILABLE:
    case Action::CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION:
    case Action::INFORM_ATTRIBUTE_OWNERSHIP:
    case Action::REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION:
    case Action::REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE:
        return false;
        break;
        
    default:
        LOGERR("Unknown action context " << context << "\n");
        break;		
    };

    return false;

}

std::string Action_RTI_13NG::getContextAsString(handleType context){

    //LOGMSG(2, "action context: " << context << ".\n");

    std::string retval;

    switch(context) {

    case Action::NOP:
        retval = "NOP"; 
        break;
        
        //federation management
    case Action::CREATE_FEDERATION_EXECUTION:
        retval = "CREATE_FEDERATION_EXECUTION"; 
        break;
    case Action::DESTROY_FEDERATION_EXECUTION:
        retval = "DESTROY_FEDERATION_EXECUTION"; 
        break;
    case Action::FEDERATE_RESTORE_COMPLETE:
        retval = "FEDERATE_RESTORE_COMPLETE"; 
        break;
    case Action::FEDERATE_RESTORE_NOT_COMPLETE:
        retval = "FEDERATE_RESTORE_NOT_COMPLETE"; 
        break;
    case Action::FEDERATE_SAVE_BEGUN:
        retval = "FEDERATE_SAVE_BEGUN"; 
        break;
    case Action::FEDERATE_SAVE_COMPLETE:
        retval = "FEDERATE_SAVE_COMPLETE"; 
        break;
    case Action::FEDERATE_SAVE_NOT_COMPLETE:
        retval = "FEDERATE_SAVE_NOT_COMPLETE"; 
        break;
    case Action::JOIN_FEDERATION_EXECUTION:
        retval = "JOIN_FEDERATION_EXECUTION"; 
        break;
    case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT2:
        retval = "REGISTER_FEDERATION_SYNCHRONISATION_POINT2"; 
        break;
    case Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT3:
        retval = "REGISTER_FEDERATION_SYNCHRONISATION_POINT3"; 
        break;
    case Action::REQUEST_FEDERATION_RESTORE:
        retval = "REQUEST_FEDERATION_RESTORE"; 
        break;
    case Action::REQUEST_FEDERATION_SAVE1:
        retval = "REQUEST_FEDERATION_SAVE1"; 
        break;
    case Action::REQUEST_FEDERATION_SAVE2:
        retval = "REQUEST_FEDERATION_SAVE2"; 
        break;
    case Action::RESIGN_FEDERATION_EXECUTION:
        retval = "RESIGN_FEDERATION_EXECUTION"; 
        break;
    case Action::SYNCHRONISATION_POINT_ACHIEVED:
        retval = "SYNCHRONISATION_POINT_ACHIEVED"; 
        break;
		

        //declaration management
    case Action::PUBLISH_INTERACTION_CLASS:
        retval = "PUBLISH_INTERACTION_CLASS"; 
        break;
    case Action::PUBLISH_OBJECT_CLASS:
        retval = "PUBLISH_OBJECT_CLASS"; 
        break;
    case Action::SUBSCRIBE_INTERACTION_CLASS:
        retval = "SUBSCRIBE_INTERACTION_CLASS"; 
        break;
    case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES:
        retval = "SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES"; 
        break;
    case Action::UNPUBLISH_INTERACTION_CLASS:
        retval = "UNPUBLISH_INTERACTION_CLASS"; 
        break;
    case Action::UNPUBLISH_OBJECT_CLASS:
        retval = "UNPUBLISH_OBJECT_CLASS"; 
        break;
    case Action::UNSUBSCRIBE_INTERACTION_CLASS:
        retval = "UNSUBSCRIBE_INTERACTION_CLASS"; 
        break;
    case Action::UNSUBSCRIBE_OBJECT_CLASS:
        retval = "UNSUBSCRIBE_OBJECT_CLASS"; 
        break;
		

        //ownership management
    case Action::CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE:
        retval = "CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE"; 
        break;
    case Action::CHANGE_INTERACTION_TRANSPORTATION_TYPE:
        retval = "CHANGE_INTERACTION_TRANSPORTATION_TYPE"; 
        break;
    case Action::DELETE_OBJECT_INSTANCE2:
        retval = "DELETE_OBJECT_INSTANCE"; 
        break;
    case Action::DELETE_OBJECT_INSTANCE3:
        retval = "DELETE_OBJECT_INSTANCE"; 
        break;
    case Action::LOCAL_DELETE_OBJECT_INSTANCE:
        retval = "LOCAL_DELETE_OBJECT_INSTANCE"; 
        break;
    case Action::REGISTER_OBJECT_INSTANCE1:
        retval = "REGISTER_OBJECT_INSTANCE1";
        break;
    case Action::REGISTER_OBJECT_INSTANCE2:
        retval = "REGISTER_OBJECT_INSTANCE2"; 
        break;
    case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE:
        retval = "REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE"; 
        break;
    case Action::REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE:
        retval = "REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE"; 
        break;
    case Action::SEND_INTERACTION3:
        retval = "SEND_INTERACTION3"; 
        break;
    case Action::SEND_INTERACTION4:
        retval = "SEND_INTERACTION4"; 
        break;
    case Action::UPDATE_ATTRIBUTE_VALUES4:
        retval = "UPDATE_ATTRIBUTE_VALUES4"; 
        break;
    case Action::UPDATE_ATTRIBUTE_VALUES3:
        retval = "UPDATE_ATTRIBUTE_VALUES3"; 
        break;
		

        //time management
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION:
        retval = "ATTRIBUTE_OWNERSHIP_ACQUISITION"; 
        break;
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE:
        retval = "ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE"; 
        break;
    case Action::ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE:
        retval = "ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE"; 
        break;
    case Action::CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION:
        retval = "CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION"; 
        break;
    case Action::CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
        retval = "CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE"; 
        break;
    case Action::IS_ATTRIBUTE_OWNED_BY_FEDERATE:
        retval = "IS_ATTRIBUTE_OWNED_BY_FEDERATE";
        break;
    case Action::NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
        retval = "NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE";
        break;
    case Action::QUERY_ATTRIBUTE_OWNERSHIP:
        retval = "QUERY_ATTRIBUTE_OWNERSHIP";
        break;
    case Action::UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE:
        retval = "UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE";
        break;
		

        //time management
    case Action::ENABLE_TIME_CONSTRAINED:
        retval = "ENABLE_TIME_CONSTRAINED";
        break;
    case Action::ENABLE_TIME_REGULATION:
        retval = "ENABLE_TIME_REGULATION";
        break;
    case Action::DISABLE_TIME_CONSTRAINED:
        retval = "DISABLE_TIME_CONSTRAINED";
        break;
    case Action::DISABLE_TIME_REGULATION:
        retval = "DISABLE_TIME_REGULATION";
        break;
    case Action::ENABLE_ASYNCHRONOUS_DELIVERY:
        retval = "ENABLE_ASYNCHRONOUS_DELIVERY";
        break;
    case Action::DISABLE_ASYNCHRONOUS_DELIVERY:
        retval = "DISABLE_ASYNCHRONOUS_DELIVERY";
        break;
    case Action::CHANGE_ATTRIBUTE_ORDER_TYPE:
        retval = "CHANGE_ATTRIBUTE_ORDER_TYPE";
        break;
    case Action::CHANGE_INTERACTION_ORDER_TYPE:
        retval = "CHANGE_INTERACTION_ORDER_TYPE";
        break;
    case Action::FLUSH_QUEUE_REQUEST:
        retval = "FLUSH_QUEUE_REQUEST";
        break;
    case Action::MODIFY_LOOKAHEAD:
        retval = "MODIFY_LOOKAHEAD";
        break;
    case Action::NEXT_EVENT_REQUEST:
        retval = "NEXT_EVENT_REQUEST";
        break;
    case Action::NEXT_EVENT_REQUEST_AVAILABLE:
        retval = "NEXT_EVENT_REQUEST_AVAILABLE";
        break;
    case Action::QUERY_FEDERATE_TIME:
        retval = "QUERY_FEDERATE_TIME";
        break;
    case Action::QUERY_LBTS:
        retval = "QUERY_LBTS";
        break;
    case Action::QUERY_LOOKAHEAD:
        retval = "QUERY_LOOKAHEAD";
        break;
    case Action::QUERY_MINNEXTEVENTTIME:
        retval = "QUERY_MINNEXTEVENTTIME";
        break;
    case Action::RETRACT:
        retval = "RETRACT";
        break;
    case Action::TIME_ADVANCE_REQUEST:
        retval = "TIME_ADVANCE_REQUEST";
        break;
    case Action::TIME_ADVANCE_REQUEST_AVAILABLE:
        retval = "TIME_ADVANCE_REQUEST_AVAILABLE";
        break;
		

        //data distribution
    case Action::ASSOCIATE_REGION_FOR_UPDATES:
        retval = "ASSOCIATE_REGION_FOR_UPDATES";
        break;
    case Action::CREATE_REGION:
        retval = "CREATE_REGION";
        break;
    case Action::DELETE_REGION:
        retval = "DELETE_REGION";
        break;
    case Action::NOTIFY_ABOUT_REGION_MODIFICATION:
        retval = "NOTIFY_ABOUT_REGION_MODIFICATION";
        break;
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION4:
        retval = "REGISTER_OBJECT_INSTANCE_WITH_REGION4";
        break;
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1:
        retval = "REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1";
        break;
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION5:
        retval = "REGISTER_OBJECT_INSTANCE_WITH_REGION5";
        break;
    case Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION:
        retval = "REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION";
        break;
    case Action::SEND_INTERACTION_WITH_REGION4:
        retval = "SEND_INTERACTION_WITH_REGION4";
        break;
    case Action::SEND_INTERACTION_WITH_REGION5:
        retval = "SEND_INTERACTION_WITH_REGION5";
        break;
    case Action::SUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
        retval = "SUBSCRIBE_INTERACTION_CLASS_WITH_REGION";
        break;
    case Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION:
        retval = "SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION";
        break;
    case Action::UNASSOCIATE_REGION_FOR_UPDATES:
        retval = "UNASSOCIATE_REGION_FOR_UPDATES";
        break;
    case Action::UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION:
        retval = "UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION";
        break;
    case Action::UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION:
        retval = "UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION";
        break;
		

        //miscellaneous
    case Action::DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
        retval = "DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH";
        break;
    case Action::DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
        retval = "DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH";
        break;
    case Action::DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
        retval = "DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH";
        break;
    case Action::DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
        retval = "DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH";
        break;
    case Action::ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH:
        retval = "ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH";
        break;
    case Action::ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH:
        retval = "ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH";
        break;
    case Action::ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH:
        retval = "ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH";
        break;
    case Action::ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH:
        retval = "ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH";
        break;
    case Action::GET_ATTRIBUTE_HANDLE:
        retval = "GET_ATTRIBUTE_HANDLE";
        break;
    case Action::GET_ATTRIBUTE_NAME:
        retval = "GET_ATTRIBUTE_NAME";
        break;
    case Action::GET_ATTRIBUTE_ROUTING_SPACE_HANDLE:
        retval = "GET_ATTRIBUTE_ROUTING_SPACE_HANDLE";
        break;
    case Action::GET_DIMENSION_HANDLE:
        retval = "GET_DIMENSION_HANDLE";
        break;
    case Action::GET_DIMENSION_NAME:
        retval = "GET_DIMENSION_NAME";
        break;
    case Action::GET_INTERACTION_CLASS_HANDLE:
        retval = "GET_INTERACTION_CLASS_HANDLE";
        break;
    case Action::GET_INTERACTION_CLASS_NAME:
        retval = "GET_INTERACTION_CLASS_NAME";
        break;
    case Action::GET_INTERACTION_ROUTING_SPACE_HANDLE:
        retval = "GET_INTERACTION_ROUTING_SPACE_HANDLE";
        break;
    case Action::GET_OBJECT_CLASS:
        retval = "GET_OBJECT_CLASS";
        break;
    case Action::GET_OBJECT_CLASS_HANDLE:
        retval = "GET_OBJECT_CLASS_HANDLE";
        break;
    case Action::GET_OBJECT_CLASS_NAME:
        retval = "GET_OBJECT_CLASS_NAME";
        break;
    case Action::GET_OBJECT_INSTANCE_HANDLE:
        retval = "GET_OBJECT_INSTANCE_HANDLE";
        break;
    case Action::GET_OBJECT_INSTANCE_NAME:
        retval = "GET_OBJECT_INSTANCE_NAME";
        break;
    case Action::GET_ORDERING_HANDLE:
        retval = "GET_ORDERING_HANDLE";
        break;
    case Action::GET_ORDERING_NAME:
        retval = "GET_ORDERING_NAME";
        break;
    case Action::GET_PARAMETER_HANDLE:
        retval = "GET_PARAMETER_HANDLE";
        break;
    case Action::GET_PARAMETER_NAME:
        retval = "GET_PARAMETER_NAME";
        break;
    case Action::GET_REGION:
        retval = "GET_REGION";
        break;
    case Action::GET_REGION_TOKEN:
        retval = "GET_REGION_TOKEN";
        break;
    case Action::GET_ROUTING_SPACE_HANDLE:
        retval = "GET_ROUTING_SPACE_HANDLE"; 
        break;
    case Action::GET_ROUTING_SPACE_NAME:
        retval = "GET_ROUTING_SPACE_NAME"; 
        break;
    case Action::GET_TRANSPORTATION_HANDLE:
        retval = "GET_TRANSPORTATION_HANDLE"; 
        break;
    case Action::GET_TRANSPORTATION_NAME:
        retval = "GET_TRANSPORTATION_NAME"; 
        break;
    case Action::TICK0:
        retval = "TICK0"; 
        break;
    case Action::TICK2:
        retval = "TICK2"; 
        break;

        /////////// FEDERATE AMBASSADOR ///////////////////

        //time management
    case Action::REQUEST_RETRACTION:
        retval = "REQUEST_RETRACTION"; 
        break;
    case Action::TIME_ADVANCE_GRANT:
        retval = "TIME_ADVANCE_GRANT"; 
        break;
    case Action::TIME_REGULATION_ENABLED:
        retval = "TIME_REGULATION_ENABLED"; 
        break;
    case Action::TIME_CONSTRAINED_ENABLED:
        retval = "TIME_CONSTRAINED_ENABLED"; 
        break;
		

        //federate managment
    case Action::ANNOUNCE_SYNCHRONISATION_POINT:
        retval = "ANNOUNCE_SYNCHRONISATION_POINT"; 
        break;
    case Action::FEDERATION_NOT_RESTORED:
        retval = "FEDERATION_NOT_RESTORED"; 
        break;
    case Action::FEDERATION_NOT_SAVED:
        retval = "FEDERATION_NOT_SAVED"; 
        break;
    case Action::FEDERATION_RESTORE_BEGUN:
        retval = "FEDERATION_RESTORE_BEGUN"; 
        break;
    case Action::FEDERATION_RESTORED:
        retval = "FEDERATION_RESTORED"; 
        break;
    case Action::FEDERATION_SAVED:
        retval = "FEDERATION_SAVED"; 
        break;
    case Action::FEDERATION_SYNCHRONISED:
        retval = "FEDERATION_SYNCHRONISED"; 
        break;
    case Action::INITIATE_FEDERATE_RESTORE:
        retval = "INITIATE_FEDERATE_RESTORE"; 
        break;
    case Action::INITIATE_FEDERATE_SAVE:
        retval = "INITIATE_FEDERATE_SAVE"; 
        break;
    case Action::REQUEST_FEDERATION_RESTORE_FAILED:
        retval = "REQUEST_FEDERATION_RESTORE_FAILED"; 
        break;
    case Action::REQUEST_FEDERATION_RESTORE_SUCCEEDED:
        retval = "REQUEST_FEDERATION_RESTORE_SUCCEEDED"; 
        break;
    case Action::SYNCHRONISATION_POINT_REGISTRATION_FAILED:
        retval = "SYNCHRONISATION_POINT_REGISTRATION_FAILED"; 
        break;
    case Action::SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED:
        retval = "SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED"; 
        break;
		

        //declaration management
    case Action::START_REGISTRATION_FOR_OBJECT_CLASS:
        retval = "START_REGISTRATION_FOR_OBJECT_CLASS"; 
        break;
    case Action::STOP_REGISTRATION_FOR_OBJECT_CLASS:
        retval = "STOP_REGISTRATION_FOR_OBJECT_CLASS"; 
        break;
    case Action::TURN_INTERACTIONS_OFF:
        retval = "TURN_INTERACTIONS_OFF"; 
        break;
    case Action::TURN_INTERACTIONS_ON:
        retval = "TURN_INTERACTIONS_ON"; 
        break;
		

        //object management
    case Action::ATTRIBUTES_IN_SCOPE:
        retval = "ATTRIBUTES_IN_SCOPE"; 
        break;
    case Action::ATTRIBUTES_OUT_OF_SCOPE:
        retval = "ATTRIBUTES_OUT_OF_SCOPE"; 
        break;
    case Action::DISCOVER_OBJECT_INSTANCE:
        retval = "DISCOVER_OBJECT_INSTANCE"; 
        break;
    case Action::PROVIDE_ATTRIBUTE_VALUE_UPDATE:
        retval = "PROVIDE_ATTRIBUTE_VALUE_UPDATE"; 
        break;
    case Action::RECEIVE_INTERACTION3:
        retval = "RECEIVE_INTERACTION5"; 
        break;
    case Action::RECEIVE_INTERACTION5:
        retval = "RECEIVE_INTERACTION5"; 
        break;
    case Action::REFLECT_ATTRIBUTE_VALUES3:
        retval = "REFLECT_ATTRIBUTE_VALUES3"; 
        break;
    case Action::REFLECT_ATTRIBUTE_VALUES5:
        retval = "REFLECT_ATTRIBUTE_VALUES5"; 
        break;
    case Action::REMOVE_OBJECT_INSTANCE2:
        retval = "REMOVE_OBJECT_INSTANCE2"; 
        break;
    case Action::REMOVE_OBJECT_INSTANCE4:
        retval = "REMOVE_OBJECT_INSTANCE4"; 
        break;
    case Action::TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE:
        retval = "TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE"; 
        break;
    case Action::TURN_UPDATES_ON_FOR_OBJECT_INSTANCE:
        retval = "TURN_UPDATES_ON_FOR_OBJECT_INSTANCE"; 
        break;
		

        //ownership managment
    case Action::ATTRIBUTE_IS_NOT_OWNED:
        retval = "ATTRIBUTE_IS_NOT_OWNED"; 
        break;
    case Action::ATTRIBUTE_OWNED_BY_RTI:
        retval = "ATTRIBUTE_OWNED_BY_RTI"; 
        break;
    case Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION:
        retval = "ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION"; 
        break;
    case Action::ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION:
        retval = "ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION"; 
        break;
    case Action::ATTRIBUTE_OWNERSHIP_UNAVAILABLE:
        retval = "ATTRIBUTE_OWNERSHIP_UNAVAILABLE"; 
        break;
    case Action::CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION:
        retval = "CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION"; 
        break;
    case Action::INFORM_ATTRIBUTE_OWNERSHIP:
        retval = "INFORM_ATTRIBUTE_OWNERSHIP"; 
        break;
    case Action::REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION:
        retval = "REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION"; 
        break;
    case Action::REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE:
        retval = "REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE"; 
        break;
        
    default:
        LOGERR("Unknown action context " << context << "\n");
        break;		
    };

    return retval;
}


std::string Action_RTI_13NG::getByteValueFromActionReturn(Action *aAction, 
                                                          void *aReturnValue){
    
    //how to interpret the void* depends on the context: switch
    std::string retval;
    RTI::EventRetractionHandle valErh;
    RTI::Region* valRegion;
    RTI::AttributeHandleSet* valAHSPtr;
    RTI::Boolean valBool;
    
    switch(aAction->actionContext) {

        //valHandle Group
    case Action::GET_ATTRIBUTE_HANDLE:
    case Action::GET_DIMENSION_HANDLE:
    case Action::GET_INTERACTION_CLASS_HANDLE:
    case Action::GET_INTERACTION_ROUTING_SPACE_HANDLE:
    case Action::GET_OBJECT_CLASS_HANDLE:
    case Action::GET_OBJECT_INSTANCE_HANDLE:
    case Action::GET_ORDERING_HANDLE:
    case Action::GET_PARAMETER_HANDLE:
    case Action::GET_ROUTING_SPACE_HANDLE:
    case Action::GET_TRANSPORTATION_HANDLE:
    case Action::GET_OBJECT_CLASS:
    case Action::JOIN_FEDERATION_EXECUTION:
    case Action::REGISTER_OBJECT_INSTANCE1:
    case Action::REGISTER_OBJECT_INSTANCE2:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION4:
    case Action::REGISTER_OBJECT_INSTANCE_WITH_REGION5:
        retval = Types::handleTypeToString(*(handleType*)aReturnValue);
        break;
    case Action::GET_ATTRIBUTE_ROUTING_SPACE_HANDLE:
        //not implemented yet
        break;

        //valStrPtr Group
    case Action::GET_ATTRIBUTE_NAME:
    case Action::GET_DIMENSION_NAME:
    case Action::GET_INTERACTION_CLASS_NAME:
    case Action::GET_OBJECT_CLASS_NAME:
    case Action::GET_OBJECT_INSTANCE_NAME:
    case Action::GET_ORDERING_NAME:
    case Action::GET_PARAMETER_NAME:
    case Action::GET_ROUTING_SPACE_NAME:
    case Action::GET_TRANSPORTATION_NAME:
        retval = std::string((char*)aReturnValue); 
        break;

        //valERH Group
    case Action::DELETE_OBJECT_INSTANCE3:
    case Action::SEND_INTERACTION4:
    case Action::SEND_INTERACTION_WITH_REGION5:
    case Action::UPDATE_ATTRIBUTE_VALUES4:
        //structure with two unsigned longs
        valErh = *(RTI::EventRetractionHandle*)aReturnValue;
        retval = (Types::unsignedLongToString(valErh.theSerialNumber)) + 
            (Types::unsignedLongToString(valErh.sendingFederate));
        break;

        //valBool Group
    case Action::IS_ATTRIBUTE_OWNED_BY_FEDERATE:
    case Action::TICK2:
        valBool = *(RTI::Boolean*)aReturnValue;
        retval = Types::boolToString(valBool == RTI::RTI_TRUE);
        retval = ""; 
        break;

        //valRegionPtr Group
    case Action::CREATE_REGION:
    case Action::GET_REGION:
        valRegion = (RTI::Region*)aReturnValue;
        retval = "";
        break;

        //valRegionToken
    case Action::GET_REGION_TOKEN:
        retval = Types::unsignedLongToString(*(RTI::RegionToken*)aReturnValue);
        break;

        //valAHSPtr
    case Action::ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE:
        valAHSPtr = (RTI::AttributeHandleSet*)aReturnValue;
        retval = ""; 
        break;

    default:
        retval = "";
        break;		
    };

    return retval;
    
}


handleType 
Action_RTI_13NG::getContextFromString(std::string context)
{

    LOGMSG(2, "Action context: " << context << "\n");
    if (strcasecmp(context.c_str(), "NOP")==0) {
        return Action::NOP;		
    }

    //federation management

    if(strcasecmp(context.c_str(), "CREATE_FEDERATION_EXECUTION")==0){
        return Action::CREATE_FEDERATION_EXECUTION;
    }
	
    if(strcasecmp(context.c_str(), "DESTROY_FEDERATION_EXECUTION")==0){
        return Action::DESTROY_FEDERATION_EXECUTION;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATE_RESTORE_COMPLETE")==0){
        return Action::FEDERATE_RESTORE_COMPLETE;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATE_RESTORE_NOT_COMPLETE")==0){
        return Action::FEDERATE_RESTORE_NOT_COMPLETE;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATE_SAVE_BEGUN")==0){
        return Action::FEDERATE_SAVE_BEGUN;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATE_SAVE_COMPLETE")==0){
        return Action::FEDERATE_SAVE_COMPLETE;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATE_SAVE_NOT_COMPLETE")==0){
        return Action::FEDERATE_SAVE_NOT_COMPLETE;
    }
	
    if(strcasecmp(context.c_str(), "JOIN_FEDERATION_EXECUTION")==0){
        return Action::JOIN_FEDERATION_EXECUTION;
    }
	
    if(strcasecmp(context.c_str(), "REGISTER_FEDERATION_SYNCHRONISATION_POINT2")==0){
        return Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT2;
    }
    if(strcasecmp(context.c_str(), "REGISTER_FEDERATION_SYNCHRONISATION_POINT3")==0){
        return Action::REGISTER_FEDERATION_SYNCHRONISATION_POINT3;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_FEDERATION_RESTORE")==0){
        return Action::REQUEST_FEDERATION_RESTORE;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_FEDERATION_SAVE1")==0){
        return Action::REQUEST_FEDERATION_SAVE1;
    }

    if(strcasecmp(context.c_str(), "REQUEST_FEDERATION_SAVE2")==0){
        return Action::REQUEST_FEDERATION_SAVE2;
    }
	
    if(strcasecmp(context.c_str(), "RESIGN_FEDERATION_EXECUTION")==0){
        return Action::RESIGN_FEDERATION_EXECUTION;
    }
	
    if(strcasecmp(context.c_str(), "SYNCHRONISATION_POINT_ACHIEVED")==0){
        return Action::SYNCHRONISATION_POINT_ACHIEVED;
    }
	

    //declaration management
    if(strcasecmp(context.c_str(), "PUBLISH_INTERACTION_CLASS")==0){
        return Action::PUBLISH_INTERACTION_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "PUBLISH_OBJECT_CLASS")==0){
        return Action::PUBLISH_OBJECT_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "SUBSCRIBE_INTERACTION_CLASS")==0){
        return Action::SUBSCRIBE_INTERACTION_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES")==0){
        return Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES;
    }
	
    if(strcasecmp(context.c_str(), "UNPUBLISH_INTERACTION_CLASS")==0){
        return Action::UNPUBLISH_INTERACTION_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "UNPUBLISH_OBJECT_CLASS")==0){
        return Action::UNPUBLISH_OBJECT_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "UNSUBSCRIBE_INTERACTION_CLASS")==0){
        return Action::UNSUBSCRIBE_INTERACTION_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "UNSUBSCRIBE_OBJECT_CLASS")==0){
        return Action::UNSUBSCRIBE_OBJECT_CLASS;
    }
	

    //object management
    if(strcasecmp(context.c_str(), "CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE")==0){
        return Action::CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE;
    }
	
    if(strcasecmp(context.c_str(), "CHANGE_INTERACTION_TRANSPORTATION_TYPE")==0){
        return Action::CHANGE_INTERACTION_TRANSPORTATION_TYPE;
    }
	
    if(strcasecmp(context.c_str(), "DELETE_OBJECT_INSTANCE2")==0){
        return Action::DELETE_OBJECT_INSTANCE2;
    }
	
    if(strcasecmp(context.c_str(), "DELETE_OBJECT_INSTANCE3")==0){
        return Action::DELETE_OBJECT_INSTANCE3;
    }

    if(strcasecmp(context.c_str(), "LOCAL_DELETE_OBJECT_INSTANCE")==0){
        return Action::LOCAL_DELETE_OBJECT_INSTANCE;
    }
	
    if(strcasecmp(context.c_str(), "REGISTER_OBJECT_INSTANCE1")==0){
        return Action::REGISTER_OBJECT_INSTANCE1;
    }
    if(strcasecmp(context.c_str(), "REGISTER_OBJECT_INSTANCE2")==0){
        return Action::REGISTER_OBJECT_INSTANCE2;
    }	
    if(strcasecmp(context.c_str(), "REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE")==0){
        return Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE")==0){
        return Action::REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE;
    }
	
    if(strcasecmp(context.c_str(), "SEND_INTERACTION3")==0){
        return Action::SEND_INTERACTION3;
    }
    if(strcasecmp(context.c_str(), "SEND_INTERACTION4")==0){
        return Action::SEND_INTERACTION4;
    }
	
    if(strcasecmp(context.c_str(), "UPDATE_ATTRIBUTE_VALUES3")==0){
        return Action::UPDATE_ATTRIBUTE_VALUES3;
    }
    if(strcasecmp(context.c_str(), "UPDATE_ATTRIBUTE_VALUES4")==0){
        return Action::UPDATE_ATTRIBUTE_VALUES4;
    }	

    //ownership managment
    if(strcasecmp(context.c_str(), "ATTRIBUTE_OWNERSHIP_ACQUISITION")==0){
        return Action::ATTRIBUTE_OWNERSHIP_ACQUISITION;
    }
	
    if(strcasecmp(context.c_str(), "ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE")==0){
        return Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE;
    }
	
    if(strcasecmp(context.c_str(), "ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE")==0){
        return Action::ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE;
    }
	
    if(strcasecmp(context.c_str(), "CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION")==0){
        return Action::CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION;
    }
	
    if(strcasecmp(context.c_str(), "CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE")==0){
        return Action::CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE;
    }
	
    if(strcasecmp(context.c_str(), "IS_ATTRIBUTE_OWNED_BY_FEDERATE")==0){
        return Action::IS_ATTRIBUTE_OWNED_BY_FEDERATE;
    }
	
    if(strcasecmp(context.c_str(), "NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE")==0){
        return Action::NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE;
    }
	
    if(strcasecmp(context.c_str(), "QUERY_ATTRIBUTE_OWNERSHIP")==0){
        return Action::QUERY_ATTRIBUTE_OWNERSHIP;
    }
	
    if(strcasecmp(context.c_str(), "UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE")==0){
        return Action::UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE;
    }
	

    //time management
    if(strcasecmp(context.c_str(), "ENABLE_TIME_CONSTRAINED")==0){
        return Action::ENABLE_TIME_CONSTRAINED;
    }
	
    if(strcasecmp(context.c_str(), "ENABLE_TIME_REGULATION")==0){
        return Action::ENABLE_TIME_REGULATION;
    }
	
    if(strcasecmp(context.c_str(), "DISABLE_TIME_CONSTRAINED")==0){
        return Action::DISABLE_TIME_CONSTRAINED;
    }
	
    if(strcasecmp(context.c_str(), "DISABLE_TIME_REGULATION")==0){
        return Action::DISABLE_TIME_REGULATION;
    }
	
    if(strcasecmp(context.c_str(), "ENABLE_ASYNCHRONOUS_DELIVERY")==0){
        return Action::ENABLE_ASYNCHRONOUS_DELIVERY;
    }
	
    if(strcasecmp(context.c_str(), "DISABLE_ASYNCHRONOUS_DELIVERY")==0){
        return Action::DISABLE_ASYNCHRONOUS_DELIVERY;
    }
	
    if(strcasecmp(context.c_str(), "CHANGE_ATTRIBUTE_ORDER_TYPE")==0){
        return Action::CHANGE_ATTRIBUTE_ORDER_TYPE;
    }
	
    if(strcasecmp(context.c_str(), "CHANGE_INTERACTION_ORDER_TYPE")==0){
        return Action::CHANGE_INTERACTION_ORDER_TYPE;
    }
	
    if(strcasecmp(context.c_str(), "FLUSH_QUEUE_REQUEST")==0){
        return Action::FLUSH_QUEUE_REQUEST;
    }
	
    if(strcasecmp(context.c_str(), "MODIFY_LOOKAHEAD")==0){
        return Action::MODIFY_LOOKAHEAD;
    }
	
    if(strcasecmp(context.c_str(), "NEXT_EVENT_REQUEST")==0){
        return Action::NEXT_EVENT_REQUEST;
    }
	
    if(strcasecmp(context.c_str(), "NEXT_EVENT_REQUEST_AVAILABLE")==0){
        return Action::NEXT_EVENT_REQUEST_AVAILABLE;
    }
	
    if(strcasecmp(context.c_str(), "QUERY_FEDERATE_TIME")==0){
        return Action::QUERY_FEDERATE_TIME;
    }
	
    if(strcasecmp(context.c_str(), "QUERY_LBTS")==0){
        return Action::QUERY_LBTS;
    }
	
    if(strcasecmp(context.c_str(), "QUERY_LOOKAHEAD")==0){
        return Action::QUERY_LOOKAHEAD;
    }
	
    if(strcasecmp(context.c_str(), "QUERY_MINNEXTEVENTTIME")==0){
        return Action::QUERY_MINNEXTEVENTTIME;
    }
	
    if(strcasecmp(context.c_str(), "RETRACT")==0){
        return Action::RETRACT;
    }
	
    if(strcasecmp(context.c_str(), "TIME_ADVANCE_REQUEST")==0){
        return Action::TIME_ADVANCE_REQUEST;
    }
	
    if(strcasecmp(context.c_str(), "TIME_ADVANCE_REQUEST_AVAILABLE")==0){
        return Action::TIME_ADVANCE_REQUEST_AVAILABLE;
    }
	

    //data distribution management
    if(strcasecmp(context.c_str(), "ASSOCIATE_REGION_FOR_UPDATES")==0){
        return Action::ASSOCIATE_REGION_FOR_UPDATES;
    }
	
    if(strcasecmp(context.c_str(), "CREATE_REGION")==0){
        return Action::CREATE_REGION;
    }
	
    if(strcasecmp(context.c_str(), "DELETE_REGION")==0){
        return Action::DELETE_REGION;
    }
	
    if(strcasecmp(context.c_str(), "NOTIFY_ABOUT_REGION_MODIFICATION")==0){
        return Action::NOTIFY_ABOUT_REGION_MODIFICATION;
    }
	
    if(strcasecmp(context.c_str(), "REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1")==0){
        return Action::REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1;
    }
    if(strcasecmp(context.c_str(), "REGISTER_OBJECT_INSTANCE_WITH_REGION4")==0){
        return Action::REGISTER_OBJECT_INSTANCE_WITH_REGION4;
    }
    if(strcasecmp(context.c_str(), "REGISTER_OBJECT_INSTANCE_WITH_REGION5")==0){
        return Action::REGISTER_OBJECT_INSTANCE_WITH_REGION5;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION")==0){
        return Action::REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION;
    }
	
    if(strcasecmp(context.c_str(), "SEND_INTERACTION_WITH_REGION4")==0){
        return Action::SEND_INTERACTION_WITH_REGION4;
    }
    if(strcasecmp(context.c_str(), "SEND_INTERACTION_WITH_REGION5")==0){
        return Action::SEND_INTERACTION_WITH_REGION5;
    }
	
    if(strcasecmp(context.c_str(), "SUBSCRIBE_INTERACTION_CLASS_WITH_REGION")==0){
        return Action::SUBSCRIBE_INTERACTION_CLASS_WITH_REGION;
    }
	
    if(strcasecmp(context.c_str(), "SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION")==0){
        return Action::SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION;
    }
	
    if(strcasecmp(context.c_str(), "UNASSOCIATE_REGION_FOR_UPDATES")==0){
        return Action::UNASSOCIATE_REGION_FOR_UPDATES;
    }
	
    if(strcasecmp(context.c_str(), "UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION")==0){
        return Action::UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION;
    }
	
    if(strcasecmp(context.c_str(), "UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION")==0){
        return Action::UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION;
    }
	

    //miscellaneous
    if(strcasecmp(context.c_str(), "DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH")==0){
        return Action::DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH")==0){
        return Action::DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH")==0){
        return Action::DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH")==0){
        return Action::DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH")==0){
        return Action::ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH")==0){
        return Action::ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH")==0){
        return Action::ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH")==0){
        return Action::ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH;
    }
	
    if(strcasecmp(context.c_str(), "GET_ATTRIBUTE_HANDLE")==0){
        return Action::GET_ATTRIBUTE_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_ATTRIBUTE_NAME")==0){
        return Action::GET_ATTRIBUTE_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_ATTRIBUTE_ROUTING_SPACE_HANDLE")==0){
        return Action::GET_ATTRIBUTE_ROUTING_SPACE_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_DIMENSION_HANDLE")==0){
        return Action::GET_DIMENSION_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_DIMENSION_NAME")==0){
        return Action::GET_DIMENSION_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_INTERACTION_CLASS_HANDLE")==0){
        return Action::GET_INTERACTION_CLASS_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_INTERACTION_CLASS_NAME")==0){
        return Action::GET_INTERACTION_CLASS_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_INTERACTION_ROUTING_SPACE_HANDLE")==0){
        return Action::GET_INTERACTION_ROUTING_SPACE_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_OBJECT_CLASS")==0){
        return Action::GET_OBJECT_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "GET_OBJECT_CLASS_HANDLE")==0){
        return Action::GET_OBJECT_CLASS_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_OBJECT_CLASS_NAME")==0){
        return Action::GET_OBJECT_CLASS_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_OBJECT_INSTANCE_HANDLE")==0){
        return Action::GET_OBJECT_INSTANCE_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_OBJECT_INSTANCE_NAME")==0){
        return Action::GET_OBJECT_INSTANCE_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_ORDERING_HANDLE")==0){
        return Action::GET_ORDERING_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_ORDERING_NAME")==0){
        return Action::GET_ORDERING_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_PARAMETER_HANDLE")==0){
        return Action::GET_PARAMETER_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_PARAMETER_NAME")==0){
        return Action::GET_PARAMETER_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_REGION")==0){
        return Action::GET_REGION;
    }
	
    if(strcasecmp(context.c_str(), "GET_REGION_TOKEN")==0){
        return Action::GET_REGION_TOKEN;
    }
	
    if(strcasecmp(context.c_str(), "GET_ROUTING_SPACE_HANDLE")==0){
        return Action::GET_ROUTING_SPACE_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_ROUTING_SPACE_NAME")==0){
        return Action::GET_ROUTING_SPACE_NAME;
    }
	
    if(strcasecmp(context.c_str(), "GET_TRANSPORTATION_HANDLE")==0){
        return Action::GET_TRANSPORTATION_HANDLE;
    }
	
    if(strcasecmp(context.c_str(), "GET_TRANSPORTATION_NAME")==0){
        return Action::GET_TRANSPORTATION_NAME;
    }
	
    if(strcasecmp(context.c_str(), "TICK0")==0){
        return Action::TICK0;
    }

    if(strcasecmp(context.c_str(), "TICK2")==0){
        return Action::TICK2;
    }


    //////////// FEDERATE AMBASSADOR ///////////////////////////

    //time management
    if(strcasecmp(context.c_str(), "REQUEST_RETRACTION")==0){
        return Action::REQUEST_RETRACTION;
    }
	
    if(strcasecmp(context.c_str(), "TIME_ADVANCE_GRANT")==0){
        return Action::TIME_ADVANCE_GRANT;
    }
	
    if(strcasecmp(context.c_str(), "TIME_REGULATION_ENABLED")==0){
        return Action::TIME_REGULATION_ENABLED;
    }
	
    if(strcasecmp(context.c_str(), "TIME_CONSTRAINED_ENABLED")==0){
        return Action::TIME_CONSTRAINED_ENABLED;
    }
	

    //federate managment
    if(strcasecmp(context.c_str(), "ANNOUNCE_SYNCHRONISATION_POINT")==0){
        return Action::ANNOUNCE_SYNCHRONISATION_POINT;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATION_NOT_RESTORED")==0){
        return Action::FEDERATION_NOT_RESTORED;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATION_NOT_SAVED")==0){
        return Action::FEDERATION_NOT_SAVED;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATION_RESTORE_BEGUN")==0){
        return Action::FEDERATION_RESTORE_BEGUN;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATION_RESTORED")==0){
        return Action::FEDERATION_RESTORED;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATION_SAVED")==0){
        return Action::FEDERATION_SAVED;
    }
	
    if(strcasecmp(context.c_str(), "FEDERATION_SYNCHRONISED")==0){
        return Action::FEDERATION_SYNCHRONISED;
    }
	
    if(strcasecmp(context.c_str(), "INITIATE_FEDERATE_RESTORE")==0){
        return Action::INITIATE_FEDERATE_RESTORE;
    }
	
    if(strcasecmp(context.c_str(), "INITIATE_FEDERATE_SAVE")==0){
        return Action::INITIATE_FEDERATE_SAVE;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_FEDERATION_RESTORE_FAILED")==0){
        return Action::REQUEST_FEDERATION_RESTORE_FAILED;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_FEDERATION_RESTORE_SUCCEEDED")==0){
        return Action::REQUEST_FEDERATION_RESTORE_SUCCEEDED;
    }
	
    if(strcasecmp(context.c_str(), "SYNCHRONISATION_POINT_REGISTRATION_FAILED")==0){
        return Action::SYNCHRONISATION_POINT_REGISTRATION_FAILED;
    }
	
    if(strcasecmp(context.c_str(), "SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED")==0){
        return Action::SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED;
    }
	

    //declaration management
    if(strcasecmp(context.c_str(), "START_REGISTRATION_FOR_OBJECT_CLASS")==0){
        return Action::START_REGISTRATION_FOR_OBJECT_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "STOP_REGISTRATION_FOR_OBJECT_CLASS")==0){
        return Action::STOP_REGISTRATION_FOR_OBJECT_CLASS;
    }
	
    if(strcasecmp(context.c_str(), "TURN_INTERACTIONS_OFF")==0){
        return Action::TURN_INTERACTIONS_OFF;
    }
	
    if(strcasecmp(context.c_str(), "TURN_INTERACTIONS_ON")==0){
        return Action::TURN_INTERACTIONS_ON;
    }
	

    //object management
    if(strcasecmp(context.c_str(), "ATTRIBUTES_IN_SCOPE")==0){
        return Action::ATTRIBUTES_IN_SCOPE;
    }
	
    if(strcasecmp(context.c_str(), "ATTRIBUTES_OUT_OF_SCOPE")==0){
        return Action::ATTRIBUTES_OUT_OF_SCOPE;
    }
	
    if(strcasecmp(context.c_str(), "DISCOVER_OBJECT_INSTANCE")==0){
        return Action::DISCOVER_OBJECT_INSTANCE;
    }
	
    if(strcasecmp(context.c_str(), "PROVIDE_ATTRIBUTE_VALUE_UPDATE")==0){
        return Action::PROVIDE_ATTRIBUTE_VALUE_UPDATE;
    }

    if(strcasecmp(context.c_str(), "RECEIVE_INTERACTION3")==0){
        return Action::RECEIVE_INTERACTION3;
    }
	
    if(strcasecmp(context.c_str(), "RECEIVE_INTERACTION5")==0){
        return Action::RECEIVE_INTERACTION5;
    }

    if(strcasecmp(context.c_str(), "REFLECT_ATTRIBUTE_VALUES3")==0){
        return Action::REFLECT_ATTRIBUTE_VALUES3;
    }
	
    if(strcasecmp(context.c_str(), "REFLECT_ATTRIBUTE_VALUES5")==0){
        return Action::REFLECT_ATTRIBUTE_VALUES5;
    }

    if(strcasecmp(context.c_str(), "REMOVE_OBJECT_INSTANCE2")==0){
        return Action::REMOVE_OBJECT_INSTANCE2;
    }

    if(strcasecmp(context.c_str(), "REMOVE_OBJECT_INSTANCE4")==0){
        return Action::REMOVE_OBJECT_INSTANCE4;
    }
	
    if(strcasecmp(context.c_str(), "TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE")==0){
        return Action::TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE;
    }
	
    if(strcasecmp(context.c_str(), "TURN_UPDATES_ON_FOR_OBJECT_INSTANCE")==0){
        return Action::TURN_UPDATES_ON_FOR_OBJECT_INSTANCE;
    }
	

    //ownership managment
    if(strcasecmp(context.c_str(), "ATTRIBUTE_IS_NOT_OWNED")==0){
        return Action::ATTRIBUTE_IS_NOT_OWNED;
    }
	
    if(strcasecmp(context.c_str(), "ATTRIBUTE_OWNED_BY_RTI")==0){
        return Action::ATTRIBUTE_OWNED_BY_RTI;
    }
	
    if(strcasecmp(context.c_str(), "ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION")==0){
        return Action::ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION;
    }
	
    if(strcasecmp(context.c_str(), "ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION")==0){
        return Action::ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION;
    }
	
    if(strcasecmp(context.c_str(), "ATTRIBUTE_OWNERSHIP_UNAVAILABLE")==0){
        return Action::ATTRIBUTE_OWNERSHIP_UNAVAILABLE;
    }
	
    if(strcasecmp(context.c_str(), "CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION")==0){
        return Action::CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION;
    }
	
    if(strcasecmp(context.c_str(), "INFORM_ATTRIBUTE_OWNERSHIP")==0){
        return Action::INFORM_ATTRIBUTE_OWNERSHIP;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION")==0){
        return Action::REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION;
    }
	
    if(strcasecmp(context.c_str(), "REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE")==0){
        return Action::REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE;
    }
	
    LOGERR("Unknown action context " << context << "\n");
	
}

bool Action_RTI_13NG::isMetaLabel(handleType actionhandle){
   
    switch (actionhandle) {

    case Action_RTI_13NG::TIMESTAMP :
        return false;
    case Action_RTI_13NG::TAG:
        return false; // just to be safe.
    case Action_RTI_13NG::BOOLEAN_ACTIVE: 
        return false;
    case Action_RTI_13NG::RESIGN_ACTION: 
        return false;
    case Action_RTI_13NG::OBJECT_CLASS_HANDLE:
        return false;
    case Action_RTI_13NG::OBJECT_CLASS_LABEL:
        return true;
    case Action_RTI_13NG::OBJECT_INSTANCE_LABEL:
        return true;
    case Action_RTI_13NG::OBJECT_INSTANCE_HANDLE:
        return false;
    case Action_RTI_13NG::INTERACTION_LABEL:
        return true;
    case Action_RTI_13NG::INTERACTION_HANDLE:
        return false;
    case Action_RTI_13NG::FEDERATE_LABEL:
        return true;
    case Action_RTI_13NG::FEDERATE_HANDLE:
        return false;
    case Action_RTI_13NG::FEDERATION_EXECUTION_LABEL:
        return true;
    case Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE:
        return false;
    case Action_RTI_13NG::FED_FILE:
        return true;
    case Action_RTI_13NG::ATTRIBUTE_HANDLE:
        return false;
    case Action_RTI_13NG::ATTRIBUTE_LABEL:
        return true;
    case Action_RTI_13NG::PARAMETER_HANDLE:
        return false;
    case Action_RTI_13NG::PARAMETER_LABEL:
        return true;
    case Action_RTI_13NG::POINT_LABEL:
        return true;
    case Action_RTI_13NG::LOOKAHEAD_TIME:
        return false;

    default:
        return false;

    }
    
}

bool Action_RTI_13NG::isMetaHandle(handleType actionhandle){

    switch (actionhandle) {
    case Action_RTI_13NG::TIMESTAMP :
        return false;
    case Action_RTI_13NG::TAG:
        return false;
    case Action_RTI_13NG::BOOLEAN_ACTIVE: 
        return false;
    case Action_RTI_13NG::RESIGN_ACTION: 
        return false;
    case Action_RTI_13NG::OBJECT_CLASS_HANDLE:
        return true;
    case Action_RTI_13NG::OBJECT_CLASS_LABEL:
        return false;
    case Action_RTI_13NG::OBJECT_INSTANCE_LABEL:
        return false;
    case Action_RTI_13NG::OBJECT_INSTANCE_HANDLE:
        return true;
    case Action_RTI_13NG::INTERACTION_LABEL:
        return false;
    case Action_RTI_13NG::INTERACTION_HANDLE:
        return true;
    case Action_RTI_13NG::FEDERATE_LABEL:
        return false;
    case Action_RTI_13NG::FEDERATE_HANDLE:
        return true;
    case Action_RTI_13NG::FEDERATION_EXECUTION_LABEL:
        return false;
    case Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE:
        return true;
    case Action_RTI_13NG::FED_FILE:
        return false;
    case Action_RTI_13NG::ATTRIBUTE_HANDLE:
        return true;
    case Action_RTI_13NG::ATTRIBUTE_LABEL:
        return false;
    case Action_RTI_13NG::PARAMETER_HANDLE:
        return true;
    case Action_RTI_13NG::PARAMETER_LABEL:
        return false;
    case Action_RTI_13NG::POINT_LABEL:
        return false;
    case Action_RTI_13NG::LOOKAHEAD_TIME:
        return false;

    default:
        return false;

    }
    
};

Action_RTI_13NG::actionMetaHandleType Action_RTI_13NG::stringToActionMetaHandle(std::string aString){
    
    if(aString == "TIMESTAMP"){       
        return Action_RTI_13NG::TIMESTAMP;
    }
    if(aString == "TAG"){       
        return Action_RTI_13NG::TAG;
    }   
    if(aString == "BOOLEAN_ACTIVE"){       
        return Action_RTI_13NG::BOOLEAN_ACTIVE;
    }
    if(aString == "RESIGN_ACTION"){       
        return Action_RTI_13NG::RESIGN_ACTION;
    }
    if(aString == "OBJECT_CLASS_HANDLE"){       
        return Action_RTI_13NG::OBJECT_CLASS_HANDLE;
    }
    if(aString == "OBJECT_CLASS_LABEL"){       
        return Action_RTI_13NG::OBJECT_CLASS_LABEL;
    }
    if(aString == "OBJECT_INSTANCE_LABEL"){       
        return Action_RTI_13NG::OBJECT_INSTANCE_LABEL;
    }
    if(aString == "OBJECT_INSTANCE_HANDLE"){       
        return Action_RTI_13NG::OBJECT_INSTANCE_HANDLE;
    }
    if(aString == "INTERACTION_LABEL"){       
        return Action_RTI_13NG::INTERACTION_LABEL;
    }
    if(aString == "INTERACTION_HANDLE"){
        return Action_RTI_13NG::INTERACTION_HANDLE;
    }
    if(aString == "FEDERATE_LABEL"){       
        return Action_RTI_13NG::FEDERATE_LABEL;
    }
    if(aString == "FEDERATE_HANDLE"){       
        return Action_RTI_13NG::FEDERATE_HANDLE;
    }
    if(aString == "FEDERATION_EXECUTION_LABEL"){       
        return Action_RTI_13NG::FEDERATION_EXECUTION_LABEL;
    }
    if(aString == "FEDERATION_EXECUTION_HANDLE"){
        return Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE;
    }
    if(aString == "FED_FILE"){       
        return Action_RTI_13NG::FED_FILE;
    }
    if(aString == "ATTRIBUTE_HANDLE"){       
        return Action_RTI_13NG::ATTRIBUTE_HANDLE;
    }
    if(aString == "ATTRIBUTE_LABEL"){
        return Action_RTI_13NG::ATTRIBUTE_LABEL;
    }
    if(aString == "PARAMETER_HANDLE"){       
        return Action_RTI_13NG::PARAMETER_HANDLE;
    }
    if(aString == "PARAMETER_LABEL"){       
        return Action_RTI_13NG::PARAMETER_LABEL;
    }
    if(aString == "POINT_LABEL"){       
        return Action_RTI_13NG::POINT_LABEL;
    }
    if(aString == "LOOKAHEAD_TIME"){            
        return Action_RTI_13NG::LOOKAHEAD_TIME;
    }
    
}

std::string Action_RTI_13NG::actionMetaHandleToString(actionMetaHandleType actionhandle){

    switch (actionhandle) {
    case Action_RTI_13NG::TIMESTAMP :
        return "TIMESTAMP";
    case Action_RTI_13NG::TAG:
        return "TAG";
    case Action_RTI_13NG::BOOLEAN_ACTIVE:
        return "BOOLEAN_ACTIVE";
    case Action_RTI_13NG::RESIGN_ACTION:
        return "RESIGN_ACTION";
    case Action_RTI_13NG::OBJECT_CLASS_HANDLE:
        return "OBJECT_CLASS_HANDLE";
    case Action_RTI_13NG::OBJECT_CLASS_LABEL:
        return "OBJECT_CLASS_LABEL";
    case Action_RTI_13NG::OBJECT_INSTANCE_LABEL:
        return "OBJECT_INSTANCE_LABEL";
    case Action_RTI_13NG::OBJECT_INSTANCE_HANDLE:
        return "OBJECT_INSTANCE_HANDLE";
    case Action_RTI_13NG::INTERACTION_LABEL:
        return "INTERACTION_LABEL";
    case Action_RTI_13NG::INTERACTION_HANDLE:
        return "INTERACTION_HANDLE";
    case Action_RTI_13NG::FEDERATE_LABEL:
        return "FEDERATE_LABEL";
    case Action_RTI_13NG::FEDERATE_HANDLE:
        return "FEDERATE_HANDLE";
    case Action_RTI_13NG::FEDERATION_EXECUTION_LABEL:
        return "FEDERATION_EXECUTION_LABEL";
    case Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE:
        return "FEDERATION_EXECUTION_HANDLE";
    case Action_RTI_13NG::FED_FILE:
        return "FED_FILE";
    case Action_RTI_13NG::ATTRIBUTE_HANDLE:
        return "ATTRIBUTE_HANDLE";
    case Action_RTI_13NG::ATTRIBUTE_LABEL:
        return "ATTRIBUTE_LABEL";
    case Action_RTI_13NG::PARAMETER_HANDLE:
        return "PARAMETER_HANDLE";
    case Action_RTI_13NG::PARAMETER_LABEL:
        return "PARAMETER_LABEL";
    case Action_RTI_13NG::POINT_LABEL:
        return "POINT_LABEL";
    case Action_RTI_13NG::LOOKAHEAD_TIME:
        return "LOOKAHEAD_TIME";
    default:
        return false;

    }
    
}


std::string Action_RTI_13NG::getActionHandleValuePairAsString(Action *action, handleType actionhandle){

    std::string str = "";    

    try{        

        switch (actionhandle) {
        case Action_RTI_13NG::TIMESTAMP :
            str += "TIMESTAMP = ";
            str +=  boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_Timestamp(*action));
            break;

        case Action_RTI_13NG::TAG:
            str += "TAG = ";					
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_Tag(*action)); 
            break;

        case Action_RTI_13NG::BOOLEAN_ACTIVE: 
            str += "BOOLEAN_ACTIVE = "; 
            break;

        case Action_RTI_13NG::RESIGN_ACTION: 
            str += "RESIGN_ACTION = "; 
            break;

        case Action_RTI_13NG::OBJECT_CLASS_HANDLE:
            str += "OBJECT_CLASS_HANDLE = ";					
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_ObjectClassHandle(*action)); 
            break;

        case Action_RTI_13NG::OBJECT_CLASS_LABEL:
            str += "OBJECT_CLASS_LABEL = ";
            str += TypeConversion_RTI_13NG::getMeta_ObjectClassLabel(*action); 
            break;

        case Action_RTI_13NG::OBJECT_INSTANCE_LABEL:
            str += "OBJECT_INSTANCE_LABEL = ";
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_ObjectInstanceLabel(*action)); 
            break;

        case Action_RTI_13NG::OBJECT_INSTANCE_HANDLE:
            str += "OBJECT_INSTANCE_HANDLE = ";
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_ObjectInstanceHandle(*action)); 
            break;

        case Action_RTI_13NG::INTERACTION_LABEL:
            str += "INTERACTION_LABEL = ";
            str += TypeConversion_RTI_13NG::getMeta_InteractionLabel(*action); 
            break;

        case Action_RTI_13NG::INTERACTION_HANDLE:
            str += "INTERACTION_HANDLE = ";
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_InteractionHandle(*action)); 
            break;

        case Action_RTI_13NG::FEDERATE_LABEL:
            str += "FEDERATE_LABEL = "; 
            str += TypeConversion_RTI_13NG::getMeta_FederateLabel(*action); 
            break;

        case Action_RTI_13NG::FEDERATE_HANDLE:
            str += "FEDERATE_HANDLE = "; 
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_FederateHandle(*action)); 
            break;

        case Action_RTI_13NG::FEDERATION_EXECUTION_LABEL:
            str += "FEDERATION_EXECUTION_LABEL = ";
            str += TypeConversion_RTI_13NG::getMeta_FederationExecutionLabel(*action); 
            break;

        case Action_RTI_13NG::FEDERATION_EXECUTION_HANDLE:
            str += "FEDERATION_EXECUTION_HANDLE = ";
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_FederationHandle(*action)); 
            break;

        case Action_RTI_13NG::FED_FILE:
            str += "FED_FILE = "; 
            str += TypeConversion_RTI_13NG::getMeta_FedFile(*action); 
            break;

        case Action_RTI_13NG::ATTRIBUTE_HANDLE:
            str += "ATTRIBUTE_HANDLE = "; 
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_AttributeHandle(*action)); 
            break;

        case Action_RTI_13NG::ATTRIBUTE_LABEL:
            str += "ATTRIBUTE_LABEL = "; 
            str += TypeConversion_RTI_13NG::getMeta_AttributeLabel(*action); 
            break;

        case Action_RTI_13NG::PARAMETER_HANDLE:
            str += "PARAMETER_HANDLE = "; 
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_ParameterHandle(*action)); 
            break;

        case Action_RTI_13NG::PARAMETER_LABEL:
            str += "PARAMETER_LABEL = "; 
            str += TypeConversion_RTI_13NG::getMeta_ParameterLabel(*action); 
            break;

        case Action_RTI_13NG::POINT_LABEL:
            str += "POINT_LABEL = "; 
            str += TypeConversion_RTI_13NG::getMeta_PointLabel(*action); 
            break;

        case Action_RTI_13NG::LOOKAHEAD_TIME:
            str += "LOOKAHEAD_TIME = ";
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_LookaheadTime(*action));	
				break;

        case Action_RTI_13NG::MISC_DOUBLE1:
            str += "MISC_DOUBLE1 = ";
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_MiscDouble1(*action));					
				break;

        case Action_RTI_13NG::MISC_DOUBLE2:
            str += "MISC_DOUBLE2 = ";
            str += boost::lexical_cast<std::string>(
                TypeConversion_RTI_13NG::getMeta_MiscDouble2(*action));					
				break;

        default:
            str += "  ";            
            str += TypeConversion_RTI_13NG::getStringFromMeta(actionhandle);
            str += "\n";

        }
        
    } catch (...){
        throw;
    }    

    return str;
    
}

handleType Action_RTI_13NG::getActionHandleFromString(std::string actionhandle){

    LOGMSG(0, "TODO: Implement this\n");

    return 0;
}

void Action_RTI_13NG::throwDerivedException(RTI::Exception *aException){

    if(dynamic_cast<RTI::ArrayIndexOutOfBounds*>(aException) != NULL)
        throw *((RTI::ArrayIndexOutOfBounds*)aException);

    if(dynamic_cast<RTI::AsynchronousDeliveryAlreadyDisabled*>(aException) != NULL)
        throw *((RTI::AsynchronousDeliveryAlreadyDisabled*)aException);
    
    if(dynamic_cast<RTI::AsynchronousDeliveryAlreadyEnabled*>(aException) != NULL)
        throw *((RTI::AsynchronousDeliveryAlreadyEnabled*)aException);
    
    if(dynamic_cast<RTI::AttributeAcquisitionWasNotRequested*>(aException) != NULL)
        throw *((RTI::AttributeAcquisitionWasNotRequested*)aException);
    
    if(dynamic_cast<RTI::AttributeAcquisitionWasNotCanceled*>(aException) != NULL)
        throw *((RTI::AttributeAcquisitionWasNotCanceled*)aException);
    
    if(dynamic_cast<RTI::AttributeAlreadyBeingAcquired*>(aException) != NULL)
        throw *((RTI::AttributeAlreadyBeingAcquired*)aException);
    
    if(dynamic_cast<RTI::AttributeAlreadyBeingDivested*>(aException) != NULL)
        throw *((RTI::AttributeAlreadyBeingDivested*)aException);
    
    if(dynamic_cast<RTI::AttributeAlreadyOwned*>(aException) != NULL)
        throw *((RTI::AttributeAlreadyOwned*)aException);
    
    if(dynamic_cast<RTI::AttributeDivestitureWasNotRequested*>(aException) != NULL)
        throw *((RTI::AttributeDivestitureWasNotRequested*)aException);
    
    if(dynamic_cast<RTI::AttributeNotDefined*>(aException) != NULL)
        throw *((RTI::AttributeNotDefined*)aException);
    
    if(dynamic_cast<RTI::AttributeNotKnown*>(aException) != NULL)
        throw *((RTI::AttributeNotKnown*)aException);
    
    if(dynamic_cast<RTI::AttributeNotOwned*>(aException) != NULL)
        throw *((RTI::AttributeNotOwned*)aException);
    
    if(dynamic_cast<RTI::AttributeNotPublished*>(aException) != NULL)
        throw *((RTI::AttributeNotPublished*)aException);
    
    if(dynamic_cast<RTI::ConcurrentAccessAttempted*>(aException) != NULL)
        throw *((RTI::ConcurrentAccessAttempted*)aException);
    
    if(dynamic_cast<RTI::CouldNotDiscover*>(aException) != NULL)
        throw *((RTI::CouldNotDiscover*)aException);
    
    if(dynamic_cast<RTI::CouldNotOpenFED*>(aException) != NULL)
        throw *((RTI::CouldNotOpenFED*)aException);
    
    if(dynamic_cast<RTI::CouldNotRestore*>(aException) != NULL)
        throw *((RTI::CouldNotRestore*)aException);
    
    if(dynamic_cast<RTI::DeletePrivilegeNotHeld*>(aException) != NULL)
        throw *((RTI::DeletePrivilegeNotHeld*)aException);
    
    if(dynamic_cast<RTI::DimensionNotDefined*>(aException) != NULL)
        throw *((RTI::DimensionNotDefined*)aException);
    
    if(dynamic_cast<RTI::EnableTimeConstrainedPending*>(aException) != NULL)
        throw *((RTI::EnableTimeConstrainedPending*)aException);
    
    if(dynamic_cast<RTI::EnableTimeConstrainedWasNotPending*>(aException) != NULL)
        throw *((RTI::EnableTimeConstrainedWasNotPending*)aException);
    
    if(dynamic_cast<RTI::EnableTimeRegulationPending*>(aException) != NULL)
        throw *((RTI::EnableTimeRegulationPending*)aException);
    
    if(dynamic_cast<RTI::EnableTimeRegulationWasNotPending*>(aException) != NULL)
        throw *((RTI::EnableTimeRegulationWasNotPending*)aException);
    
    if(dynamic_cast<RTI::ErrorReadingFED*>(aException) != NULL)
        throw *((RTI::ErrorReadingFED*)aException);
    
    if(dynamic_cast<RTI::EventNotKnown*>(aException) != NULL)
        throw *((RTI::EventNotKnown*)aException);
    
    if(dynamic_cast<RTI::FederateAlreadyExecutionMember*>(aException) != NULL)
        throw *((RTI::FederateAlreadyExecutionMember*)aException);
    
    if(dynamic_cast<RTI::FederateInternalError*>(aException) != NULL)
        throw *((RTI::FederateInternalError*)aException);
    
    if(dynamic_cast<RTI::FederateLoggingServiceCalls*>(aException) != NULL)
        throw *((RTI::FederateLoggingServiceCalls*)aException);
    
    if(dynamic_cast<RTI::FederateNotExecutionMember*>(aException) != NULL)
        throw *((RTI::FederateNotExecutionMember*)aException);
    
    if(dynamic_cast<RTI::FederateOwnsAttributes*>(aException) != NULL)
        throw *((RTI::FederateOwnsAttributes*)aException);
    
    if(dynamic_cast<RTI::FederateWasNotAskedToReleaseAttribute*>(aException) != NULL)
        throw *((RTI::FederateWasNotAskedToReleaseAttribute*)aException);
    
    if(dynamic_cast<RTI::FederatesCurrentlyJoined*>(aException) != NULL)
        throw *((RTI::FederatesCurrentlyJoined*)aException);
    
    if(dynamic_cast<RTI::FederationExecutionAlreadyExists*>(aException) != NULL)
        throw *((RTI::FederationExecutionAlreadyExists*)aException);
    
    if(dynamic_cast<RTI::FederationExecutionDoesNotExist*>(aException) != NULL)
        throw *((RTI::FederationExecutionDoesNotExist*)aException);
    
    if(dynamic_cast<RTI::FederationTimeAlreadyPassed*>(aException) != NULL)
        throw *((RTI::FederationTimeAlreadyPassed*)aException);
    
    if(dynamic_cast<RTI::HandleValuePairMaximumExceeded*>(aException) != NULL)
        throw *((RTI::HandleValuePairMaximumExceeded*)aException);
    
    if(dynamic_cast<RTI::InteractionClassNotDefined*>(aException) != NULL)
        throw *((RTI::InteractionClassNotDefined*)aException);
    
    if(dynamic_cast<RTI::InteractionClassNotKnown*>(aException) != NULL)
        throw *((RTI::InteractionClassNotKnown*)aException);
    
    if(dynamic_cast<RTI::InteractionClassNotPublished*>(aException) != NULL)
        throw *((RTI::InteractionClassNotPublished*)aException);
    
    if(dynamic_cast<RTI::InteractionClassNotSubscribed*>(aException) != NULL)
        throw *((RTI::InteractionClassNotSubscribed*)aException);
    
    if(dynamic_cast<RTI::InteractionParameterNotDefined*>(aException) != NULL)
        throw *((RTI::InteractionParameterNotDefined*)aException);
    
    if(dynamic_cast<RTI::InteractionParameterNotKnown*>(aException) != NULL)
        throw *((RTI::InteractionParameterNotKnown*)aException);
    
    if(dynamic_cast<RTI::InvalidExtents*>(aException) != NULL)
        throw *((RTI::InvalidExtents*)aException);
    
    if(dynamic_cast<RTI::InvalidFederationTime*>(aException) != NULL)
        throw *((RTI::InvalidFederationTime*)aException);
    
    if(dynamic_cast<RTI::InvalidHandleValuePairSetContext*>(aException) != NULL)
        throw *((RTI::InvalidHandleValuePairSetContext*)aException);
    
    if(dynamic_cast<RTI::InvalidLookahead*>(aException) != NULL)
        throw *((RTI::InvalidLookahead*)aException);
    
    if(dynamic_cast<RTI::InvalidOrderingHandle*>(aException) != NULL)
        throw *((RTI::InvalidOrderingHandle*)aException);
    
    if(dynamic_cast<RTI::InvalidRegionContext*>(aException) != NULL)
        throw *((RTI::InvalidRegionContext*)aException);
    
    if(dynamic_cast<RTI::InvalidResignAction*>(aException) != NULL)
        throw *((RTI::InvalidResignAction*)aException);
    
    if(dynamic_cast<RTI::InvalidRetractionHandle*>(aException) != NULL)
        throw *((RTI::InvalidRetractionHandle*)aException);
    
    if(dynamic_cast<RTI::InvalidTransportationHandle*>(aException) != NULL)
        throw *((RTI::InvalidTransportationHandle*)aException);
    
    if(dynamic_cast<RTI::MemoryExhausted*>(aException) != NULL)
        throw *((RTI::MemoryExhausted*)aException);
    
    if(dynamic_cast<RTI::NameNotFound*>(aException) != NULL)
        throw *((RTI::NameNotFound*)aException);
    
    if(dynamic_cast<RTI::ObjectClassNotDefined*>(aException) != NULL)
        throw *((RTI::ObjectClassNotDefined*)aException);
    
    if(dynamic_cast<RTI::ObjectClassNotKnown*>(aException) != NULL)
        throw *((RTI::ObjectClassNotKnown*)aException);
    
    if(dynamic_cast<RTI::ObjectClassNotPublished*>(aException) != NULL)
        throw *((RTI::ObjectClassNotPublished*)aException);
    
    if(dynamic_cast<RTI::ObjectClassNotSubscribed*>(aException) != NULL)
        throw *((RTI::ObjectClassNotSubscribed*)aException);
    
    if(dynamic_cast<RTI::ObjectNotKnown*>(aException) != NULL)
        throw *((RTI::ObjectNotKnown*)aException);
    
    if(dynamic_cast<RTI::ObjectAlreadyRegistered*>(aException) != NULL)
        throw *((RTI::ObjectAlreadyRegistered*)aException);
    
    if(dynamic_cast<RTI::OwnershipAcquisitionPending*>(aException) != NULL)
        throw *((RTI::OwnershipAcquisitionPending*)aException);
    
    if(dynamic_cast<RTI::RegionInUse*>(aException) != NULL)
        throw *((RTI::RegionInUse*)aException);
    
    if(dynamic_cast<RTI::RegionNotKnown*>(aException) != NULL)
        throw *((RTI::RegionNotKnown*)aException);
    
    if(dynamic_cast<RTI::RestoreInProgress*>(aException) != NULL)
        throw *((RTI::RestoreInProgress*)aException);
    
    if(dynamic_cast<RTI::RestoreNotRequested*>(aException) != NULL)
        throw *((RTI::RestoreNotRequested*)aException);
    
    if(dynamic_cast<RTI::RTIinternalError*>(aException) != NULL)
        throw *((RTI::RTIinternalError*)aException);
    
    if(dynamic_cast<RTI::SpaceNotDefined*>(aException) != NULL)
        throw *((RTI::SpaceNotDefined*)aException);
    
    if(dynamic_cast<RTI::SaveInProgress*>(aException) != NULL)
        throw *((RTI::SaveInProgress*)aException);
    
    if(dynamic_cast<RTI::SaveNotInitiated*>(aException) != NULL)
        throw *((RTI::SaveNotInitiated*)aException);
    
    if(dynamic_cast<RTI::SpecifiedSaveLabelDoesNotExist*>(aException) != NULL)
        throw *((RTI::SpecifiedSaveLabelDoesNotExist*)aException);
    
    if(dynamic_cast<RTI::SynchronizationPointLabelWasNotAnnounced*>(aException) != NULL)
        throw *((RTI::SynchronizationPointLabelWasNotAnnounced*)aException);
    
    if(dynamic_cast<RTI::TimeAdvanceAlreadyInProgress*>(aException) != NULL)
        throw *((RTI::TimeAdvanceAlreadyInProgress*)aException);
    
    if(dynamic_cast<RTI::TimeAdvanceWasNotInProgress*>(aException) != NULL)
        throw *((RTI::TimeAdvanceWasNotInProgress*)aException);
    
    if(dynamic_cast<RTI::TimeConstrainedAlreadyEnabled*>(aException) != NULL)
        throw *((RTI::TimeConstrainedAlreadyEnabled*)aException);
    
    if(dynamic_cast<RTI::TimeConstrainedWasNotEnabled*>(aException) != NULL)
        throw *((RTI::TimeConstrainedWasNotEnabled*)aException);
    
    if(dynamic_cast<RTI::TimeRegulationAlreadyEnabled*>(aException) != NULL)
        throw *((RTI::TimeRegulationAlreadyEnabled*)aException);
    
    if(dynamic_cast<RTI::TimeRegulationWasNotEnabled*>(aException) != NULL)
        throw *((RTI::TimeRegulationWasNotEnabled*)aException);
    
    if(dynamic_cast<RTI::UnableToPerformSave*>(aException) != NULL)
        throw *((RTI::UnableToPerformSave*)aException);
    
    if(dynamic_cast<RTI::ValueCountExceeded*>(aException) != NULL)
        throw *((RTI::ValueCountExceeded*)aException);
    
    if(dynamic_cast<RTI::ValueLengthExceeded*>(aException) != NULL)
        throw *((RTI::ValueLengthExceeded*)aException);

    return;
    
};

std::string Action_RTI_13NG::rtiExceptionToString(RTI::Exception *aException){

    if(dynamic_cast<RTI::ArrayIndexOutOfBounds*>(aException) != NULL)
        return "RTI::ArrayIndexOutOfBounds";

    if(dynamic_cast<RTI::AsynchronousDeliveryAlreadyDisabled*>(aException) != NULL)
        return "RTI::AsynchronousDeliveryAlreadyDisabled";
    
    if(dynamic_cast<RTI::AsynchronousDeliveryAlreadyEnabled*>(aException) != NULL)
        return "RTI::AsynchronousDeliveryAlreadyEnabled";
    
    if(dynamic_cast<RTI::AttributeAcquisitionWasNotRequested*>(aException) != NULL)
        return "RTI::AttributeAcquisitionWasNotRequested";
    
    if(dynamic_cast<RTI::AttributeAcquisitionWasNotCanceled*>(aException) != NULL)
        return "RTI::AttributeAcquisitionWasNotCanceled";
    
    if(dynamic_cast<RTI::AttributeAlreadyBeingAcquired*>(aException) != NULL)
        return "RTI::AttributeAlreadyBeingAcquired";
    
    if(dynamic_cast<RTI::AttributeAlreadyBeingDivested*>(aException) != NULL)
        return "RTI::AttributeAlreadyBeingDivested";
    
    if(dynamic_cast<RTI::AttributeAlreadyOwned*>(aException) != NULL)
        return "RTI::AttributeAlreadyOwned";
    
    if(dynamic_cast<RTI::AttributeDivestitureWasNotRequested*>(aException) != NULL)
        return "RTI::AttributeDivestitureWasNotRequested";
    
    if(dynamic_cast<RTI::AttributeNotDefined*>(aException) != NULL)
        return "RTI::AttributeNotDefined";
    
    if(dynamic_cast<RTI::AttributeNotKnown*>(aException) != NULL)
        return "RTI::AttributeNotKnown";
    
    if(dynamic_cast<RTI::AttributeNotOwned*>(aException) != NULL)
        return "RTI::AttributeNotOwned";
    
    if(dynamic_cast<RTI::AttributeNotPublished*>(aException) != NULL)
        return "RTI::AttributeNotPublished";
    
    if(dynamic_cast<RTI::ConcurrentAccessAttempted*>(aException) != NULL)
        return "RTI::ConcurrentAccessAttempted";
    
    if(dynamic_cast<RTI::CouldNotDiscover*>(aException) != NULL)
        return "RTI::CouldNotDiscover";
    
    if(dynamic_cast<RTI::CouldNotOpenFED*>(aException) != NULL)
        return "RTI::CouldNotOpenFED";
    
    if(dynamic_cast<RTI::CouldNotRestore*>(aException) != NULL)
        return "RTI::CouldNotRestore";
    
    if(dynamic_cast<RTI::DeletePrivilegeNotHeld*>(aException) != NULL)
        return "RTI::DeletePrivilegeNotHeld";
    
    if(dynamic_cast<RTI::DimensionNotDefined*>(aException) != NULL)
        return "RTI::DimensionNotDefined";
    
    if(dynamic_cast<RTI::EnableTimeConstrainedPending*>(aException) != NULL)
        return "RTI::EnableTimeConstrainedPending";
    
    if(dynamic_cast<RTI::EnableTimeConstrainedWasNotPending*>(aException) != NULL)
        return "RTI::EnableTimeConstrainedWasNotPending";
    
    if(dynamic_cast<RTI::EnableTimeRegulationPending*>(aException) != NULL)
        return "RTI::EnableTimeRegulationPending";
    
    if(dynamic_cast<RTI::EnableTimeRegulationWasNotPending*>(aException) != NULL)
        return "RTI::EnableTimeRegulationWasNotPending";
    
    if(dynamic_cast<RTI::ErrorReadingFED*>(aException) != NULL)
        return "RTI::ErrorReadingFED";
    
    if(dynamic_cast<RTI::EventNotKnown*>(aException) != NULL)
        return "RTI::EventNotKnown";
    
    if(dynamic_cast<RTI::FederateAlreadyExecutionMember*>(aException) != NULL)
        return "RTI::FederateAlreadyExecutionMember";
    
    if(dynamic_cast<RTI::FederateInternalError*>(aException) != NULL)
        return "RTI::FederateInternalError";
    
    if(dynamic_cast<RTI::FederateLoggingServiceCalls*>(aException) != NULL)
        return "RTI::FederateLoggingServiceCalls";
    
    if(dynamic_cast<RTI::FederateNotExecutionMember*>(aException) != NULL)
        return "RTI::FederateNotExecutionMember";
    
    if(dynamic_cast<RTI::FederateOwnsAttributes*>(aException) != NULL)
        return "RTI::FederateOwnsAttributes";
    
    if(dynamic_cast<RTI::FederateWasNotAskedToReleaseAttribute*>(aException) != NULL)
        return "RTI::FederateWasNotAskedToReleaseAttribute";
    
    if(dynamic_cast<RTI::FederatesCurrentlyJoined*>(aException) != NULL)
        return "RTI::FederatesCurrentlyJoined";
    
    if(dynamic_cast<RTI::FederationExecutionAlreadyExists*>(aException) != NULL)
        return "RTI::FederationExecutionAlreadyExists";
    
    if(dynamic_cast<RTI::FederationExecutionDoesNotExist*>(aException) != NULL)
        return "RTI::FederationExecutionDoesNotExist";
    
    if(dynamic_cast<RTI::FederationTimeAlreadyPassed*>(aException) != NULL)
        return "RTI::FederationTimeAlreadyPassed";
    
    if(dynamic_cast<RTI::HandleValuePairMaximumExceeded*>(aException) != NULL)
        return "RTI::HandleValuePairMaximumExceeded";
    
    if(dynamic_cast<RTI::InteractionClassNotDefined*>(aException) != NULL)
        return "RTI::InteractionClassNotDefined";
    
    if(dynamic_cast<RTI::InteractionClassNotKnown*>(aException) != NULL)
        return "RTI::InteractionClassNotKnown";
    
    if(dynamic_cast<RTI::InteractionClassNotPublished*>(aException) != NULL)
        return "RTI::InteractionClassNotPublished";
    
    if(dynamic_cast<RTI::InteractionClassNotSubscribed*>(aException) != NULL)
        return "RTI::InteractionClassNotSubscribed";
    
    if(dynamic_cast<RTI::InteractionParameterNotDefined*>(aException) != NULL)
        return "RTI::InteractionParameterNotDefined";
    
    if(dynamic_cast<RTI::InteractionParameterNotKnown*>(aException) != NULL)
        return "RTI::InteractionParameterNotKnown";
    
    if(dynamic_cast<RTI::InvalidExtents*>(aException) != NULL)
        return "RTI::InvalidExtents";
    
    if(dynamic_cast<RTI::InvalidFederationTime*>(aException) != NULL)
        return "RTI::InvalidFederationTime";
    
    if(dynamic_cast<RTI::InvalidHandleValuePairSetContext*>(aException) != NULL)
        return "RTI::InvalidHandleValuePairSetContext";
    
    if(dynamic_cast<RTI::InvalidLookahead*>(aException) != NULL)
        return "RTI::InvalidLookahead";
    
    if(dynamic_cast<RTI::InvalidOrderingHandle*>(aException) != NULL)
        return "RTI::InvalidOrderingHandle";
    
    if(dynamic_cast<RTI::InvalidRegionContext*>(aException) != NULL)
        return "RTI::InvalidRegionContext";
    
    if(dynamic_cast<RTI::InvalidResignAction*>(aException) != NULL)
        return "RTI::InvalidResignAction";
    
    if(dynamic_cast<RTI::InvalidRetractionHandle*>(aException) != NULL)
        return "RTI::InvalidRetractionHandle";
    
    if(dynamic_cast<RTI::InvalidTransportationHandle*>(aException) != NULL)
        return "RTI::InvalidTransportationHandle";
    
    if(dynamic_cast<RTI::MemoryExhausted*>(aException) != NULL)
        return "RTI::MemoryExhausted";
    
    if(dynamic_cast<RTI::NameNotFound*>(aException) != NULL)
        return "RTI::NameNotFound";
    
    if(dynamic_cast<RTI::ObjectClassNotDefined*>(aException) != NULL)
        return "RTI::ObjectClassNotDefined";
    
    if(dynamic_cast<RTI::ObjectClassNotKnown*>(aException) != NULL)
        return "RTI::ObjectClassNotKnown";
    
    if(dynamic_cast<RTI::ObjectClassNotPublished*>(aException) != NULL)
        return "RTI::ObjectClassNotPublished";
    
    if(dynamic_cast<RTI::ObjectClassNotSubscribed*>(aException) != NULL)
        return "RTI::ObjectClassNotSubscribed";
    
    if(dynamic_cast<RTI::ObjectNotKnown*>(aException) != NULL)
        return "RTI::ObjectNotKnown";
    
    if(dynamic_cast<RTI::ObjectAlreadyRegistered*>(aException) != NULL)
        return "RTI::ObjectAlreadyRegistered";
    
    if(dynamic_cast<RTI::OwnershipAcquisitionPending*>(aException) != NULL)
        return "RTI::OwnershipAcquisitionPending";
    
    if(dynamic_cast<RTI::RegionInUse*>(aException) != NULL)
        return "RTI::RegionInUse";
    
    if(dynamic_cast<RTI::RegionNotKnown*>(aException) != NULL)
        return "RTI::RegionNotKnown";
    
    if(dynamic_cast<RTI::RestoreInProgress*>(aException) != NULL)
        return "RTI::RestoreInProgress";
    
    if(dynamic_cast<RTI::RestoreNotRequested*>(aException) != NULL)
        return "RTI::RestoreNotRequested";
    
    if(dynamic_cast<RTI::RTIinternalError*>(aException) != NULL)
        return "RTI::RTIinternalError";
    
    if(dynamic_cast<RTI::SpaceNotDefined*>(aException) != NULL)
        return "RTI::SpaceNotDefined";
    
    if(dynamic_cast<RTI::SaveInProgress*>(aException) != NULL)
        return "RTI::SaveInProgress";
    
    if(dynamic_cast<RTI::SaveNotInitiated*>(aException) != NULL)
        return "RTI::SaveNotInitiated";
    
    if(dynamic_cast<RTI::SpecifiedSaveLabelDoesNotExist*>(aException) != NULL)
        return "RTI::SpecifiedSaveLabelDoesNotExist";
    
    if(dynamic_cast<RTI::SynchronizationPointLabelWasNotAnnounced*>(aException) != NULL)
        return "RTI::SynchronizationPointLabelWasNotAnnounced";
    
    if(dynamic_cast<RTI::TimeAdvanceAlreadyInProgress*>(aException) != NULL)
        return "RTI::TimeAdvanceAlreadyInProgress";
    
    if(dynamic_cast<RTI::TimeAdvanceWasNotInProgress*>(aException) != NULL)
        return "RTI::TimeAdvanceWasNotInProgress";
    
    if(dynamic_cast<RTI::TimeConstrainedAlreadyEnabled*>(aException) != NULL)
        return "RTI::TimeConstrainedAlreadyEnabled";
    
    if(dynamic_cast<RTI::TimeConstrainedWasNotEnabled*>(aException) != NULL)
        return "RTI::TimeConstrainedWasNotEnabled";
    
    if(dynamic_cast<RTI::TimeRegulationAlreadyEnabled*>(aException) != NULL)
        return "RTI::TimeRegulationAlreadyEnabled";
    
    if(dynamic_cast<RTI::TimeRegulationWasNotEnabled*>(aException) != NULL)
        return "RTI::TimeRegulationWasNotEnabled";
    
    if(dynamic_cast<RTI::UnableToPerformSave*>(aException) != NULL)
        return "RTI::UnableToPerformSave";
    
    if(dynamic_cast<RTI::ValueCountExceeded*>(aException) != NULL)
        return "RTI::ValueCountExceeded";
    
    if(dynamic_cast<RTI::ValueLengthExceeded*>(aException) != NULL)
        return "RTI::ValueLengthExceeded";

    return "";
    
};


/////////////////////////////////////////////



