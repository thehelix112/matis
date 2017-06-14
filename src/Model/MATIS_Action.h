// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Action.h,v $
// CVS $Date: 2006/01/16 13:41:03 $
// CVS $Revision: 1.4 $








#ifndef MATIS_ACTION_H
#define MATIS_ACTION_H

#include "MATIS_TypeConversion.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

/**
 * MATIS::Action: Container of data passed between singals and their corresponding slots and their marshallers. 
 */

namespace MATIS {

    class Action {

      public:
        Action();
        ~Action();

        handleValuePairSetType metadata;
        handleValuePairSetType hvps;
        handleValuePairSetType hvps2;
        handleSetType hs;
        handleSetType hs2;
        regionSetType rs;

        handleType actionId;
        handleType channelId;
        
        bool outgoing;        

        typedef enum {
            // Special
            NOP,                // defines null action
            EXCEPTION,          // identifies this as an exception

            // BEGIN PROTOCOL SPECIFIC STUFF THAT HAS TO BE HERE

            // BEGIN RTI_13NG
            //--------------------------------
            // RTI AMBASSADOR

            //federation management
            CREATE_FEDERATION_EXECUTION, 
            DESTROY_FEDERATION_EXECUTION, 
            FEDERATE_RESTORE_COMPLETE,
            FEDERATE_RESTORE_NOT_COMPLETE,
            FEDERATE_SAVE_BEGUN,
            FEDERATE_SAVE_COMPLETE,
            FEDERATE_SAVE_NOT_COMPLETE,			
            JOIN_FEDERATION_EXECUTION, 
            REGISTER_FEDERATION_SYNCHRONISATION_POINT2,
            REGISTER_FEDERATION_SYNCHRONISATION_POINT3,
            REQUEST_FEDERATION_RESTORE,
            REQUEST_FEDERATION_SAVE1,
            REQUEST_FEDERATION_SAVE2,
            RESIGN_FEDERATION_EXECUTION,
            SYNCHRONISATION_POINT_ACHIEVED,

            //declaration management  (TESTING TO FOLLOW)
            PUBLISH_INTERACTION_CLASS, 
            PUBLISH_OBJECT_CLASS, 
            SUBSCRIBE_INTERACTION_CLASS, 
            SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES, 
            UNPUBLISH_INTERACTION_CLASS, 
            UNPUBLISH_OBJECT_CLASS, 
            UNSUBSCRIBE_INTERACTION_CLASS, 
            UNSUBSCRIBE_OBJECT_CLASS, 

            //object management  (TESTING TO FOLLOW)
            CHANGE_ATTRIBUTE_TRANSPORTATION_TYPE, 
            CHANGE_INTERACTION_TRANSPORTATION_TYPE, 
            DELETE_OBJECT_INSTANCE2, 
            DELETE_OBJECT_INSTANCE3, 
            LOCAL_DELETE_OBJECT_INSTANCE, 
            REGISTER_OBJECT_INSTANCE1, 
            REGISTER_OBJECT_INSTANCE2, 
            REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE, 
            REQUEST_OBJECT_ATTRIBUTE_VALUE_UPDATE, 
            SEND_INTERACTION3, 
            SEND_INTERACTION4, 
            UPDATE_ATTRIBUTE_VALUES3, 
            UPDATE_ATTRIBUTE_VALUES4, 

            //ownership managment
            ATTRIBUTE_OWNERSHIP_ACQUISITION,
            ATTRIBUTE_OWNERSHIP_ACQUISITION_IF_AVAILABLE,
            ATTRIBUTE_OWNERSHIP_RELEASE_RESPONSE,
            CANCEL_ATTRIBUTE_OWNERSHIP_ACQUISITION,
            CANCEL_NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE,
            IS_ATTRIBUTE_OWNED_BY_FEDERATE,
            NEGOTIATED_ATTRIBUTE_OWNERSHIP_DIVESTITURE,
            QUERY_ATTRIBUTE_OWNERSHIP,
            UNCONDITIONAL_ATTRIBUTE_OWNERSHIP_DIVESTITURE,

            //time management  (TESTING TO FOLLOW)
            ENABLE_TIME_CONSTRAINED, 
            ENABLE_TIME_REGULATION, 
            DISABLE_TIME_CONSTRAINED, 
            DISABLE_TIME_REGULATION, 
            ENABLE_ASYNCHRONOUS_DELIVERY, 
            DISABLE_ASYNCHRONOUS_DELIVERY, 
            CHANGE_ATTRIBUTE_ORDER_TYPE, 
            CHANGE_INTERACTION_ORDER_TYPE, 
            FLUSH_QUEUE_REQUEST, 
            MODIFY_LOOKAHEAD, 
            NEXT_EVENT_REQUEST, 
            NEXT_EVENT_REQUEST_AVAILABLE, 
            QUERY_FEDERATE_TIME, 
            QUERY_LBTS, 
            QUERY_LOOKAHEAD, 
            QUERY_MINNEXTEVENTTIME, 
            RETRACT, //WAITING FOR ERH's TO BE ENTITIES
            TIME_ADVANCE_REQUEST, 
            TIME_ADVANCE_REQUEST_AVAILABLE, 

            //data distribution management
            ASSOCIATE_REGION_FOR_UPDATES,
            CREATE_REGION,
            DELETE_REGION,
            NOTIFY_ABOUT_REGION_MODIFICATION,
            REGISTER_OBJECT_INSTANCE_WITH_REGION4,
            REGISTER_OBJECT_INSTANCE_WITH_REGION_SUB1,
            REGISTER_OBJECT_INSTANCE_WITH_REGION5,
            REQUEST_CLASS_ATTRIBUTE_VALUE_UPDATE_WITH_REGION,
            SEND_INTERACTION_WITH_REGION4,
            SEND_INTERACTION_WITH_REGION5,
            SUBSCRIBE_INTERACTION_CLASS_WITH_REGION,
            SUBSCRIBE_OBJECT_CLASS_ATTRIBUTES_WITH_REGION,
            UNASSOCIATE_REGION_FOR_UPDATES,
            UNSUBSCRIBE_INTERACTION_CLASS_WITH_REGION,
            UNSUBSCRIBE_OBJECT_CLASS_WITH_REGION,

            //miscellaneous
            DISABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH,
            DISABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH,
            DISABLE_CLASS_RELEVANCE_ADVISORY_SWITCH,
            DISABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH,
            ENABLE_ATTRIBUTE_RELEVANCE_ADVISORY_SWITCH,
            ENABLE_ATTRIBUTE_SCOPE_ADVISORY_SWITCH,
            ENABLE_CLASS_RELEVANCE_ADVISORY_SWITCH,
            ENABLE_INTERACTION_RELEVANCE_ADVISORY_SWITCH,
            GET_ATTRIBUTE_HANDLE, 
            GET_ATTRIBUTE_NAME, 
            GET_ATTRIBUTE_ROUTING_SPACE_HANDLE,
            GET_DIMENSION_HANDLE,
            GET_DIMENSION_NAME,
            GET_INTERACTION_CLASS_HANDLE, 
            GET_INTERACTION_CLASS_NAME, 
            GET_INTERACTION_ROUTING_SPACE_HANDLE,
            GET_OBJECT_CLASS,
            GET_OBJECT_CLASS_HANDLE, 
            GET_OBJECT_CLASS_NAME, 
            GET_OBJECT_INSTANCE_HANDLE, 
            GET_OBJECT_INSTANCE_NAME,
            GET_ORDERING_HANDLE,
            GET_ORDERING_NAME,
            GET_PARAMETER_HANDLE, 
            GET_PARAMETER_NAME, 
            GET_REGION,
            GET_REGION_TOKEN,
            GET_ROUTING_SPACE_HANDLE,
            GET_ROUTING_SPACE_NAME,
            GET_TRANSPORTATION_HANDLE,
            GET_TRANSPORTATION_NAME,
            TICK0, 
            TICK2, //HACKED TO TEST


            //---------------------------------------
            // FEDERATE AMBASSADOR

            //time management
            REQUEST_RETRACTION,
            TIME_ADVANCE_GRANT, 
            TIME_REGULATION_ENABLED, 
            TIME_CONSTRAINED_ENABLED, 

            //federate managment
            ANNOUNCE_SYNCHRONISATION_POINT,
            FEDERATION_NOT_RESTORED,
            FEDERATION_NOT_SAVED,
            FEDERATION_RESTORE_BEGUN,
            FEDERATION_RESTORED,
            FEDERATION_SAVED,
            FEDERATION_SYNCHRONISED,
            INITIATE_FEDERATE_RESTORE,
            INITIATE_FEDERATE_SAVE,
            REQUEST_FEDERATION_RESTORE_FAILED,
            REQUEST_FEDERATION_RESTORE_SUCCEEDED,
            SYNCHRONISATION_POINT_REGISTRATION_FAILED,
            SYNCHRONISATION_POINT_REGISTRATION_SUCCEEDED,

            //declaration management
            START_REGISTRATION_FOR_OBJECT_CLASS,
            STOP_REGISTRATION_FOR_OBJECT_CLASS,
            TURN_INTERACTIONS_OFF,
            TURN_INTERACTIONS_ON,

            //object management
            ATTRIBUTES_IN_SCOPE,
            ATTRIBUTES_OUT_OF_SCOPE,
            DISCOVER_OBJECT_INSTANCE,
            PROVIDE_ATTRIBUTE_VALUE_UPDATE,
            RECEIVE_INTERACTION3,
            RECEIVE_INTERACTION5,
            REFLECT_ATTRIBUTE_VALUES3,
            REFLECT_ATTRIBUTE_VALUES5,
            REMOVE_OBJECT_INSTANCE2,
            REMOVE_OBJECT_INSTANCE4,
            TURN_UPDATES_OFF_FOR_OBJECT_INSTANCE,
            TURN_UPDATES_ON_FOR_OBJECT_INSTANCE,

            //ownership managment
            ATTRIBUTE_IS_NOT_OWNED,
            ATTRIBUTE_OWNED_BY_RTI,
            ATTRIBUTE_OWNERSHIP_ACQUISITION_NOTIFICATION,
            ATTRIBUTE_OWNERSHIP_DIVESTITURE_NOTIFICATION,
            ATTRIBUTE_OWNERSHIP_UNAVAILABLE,
            CONFIRM_ATTRIBUTE_OWNERSHIP_ACQUISITION_CANCELLATION,
            INFORM_ATTRIBUTE_OWNERSHIP,
            REQUEST_ATTRIBUTE_OWNERSHIP_ASSUMPTION,
            REQUEST_ATTRIBUTE_OWNERSHIP_RELEASE,			

            // END RTI_13NG
        }  ActionContextType;

        ActionContextType actionContext;

    public:
        
        void* execute();
        void* request();
        std::string hash();
        
        //Static store of Actions
        static UniqueHandleFactory < Action*, 1 > actions;

    };

};
#endif                          // MATIS_ACTION_H
