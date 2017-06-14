// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_FakeRTIAmbassador.h,v $
// CVS $Date: 2006/01/01 07:40:38 $
// CVS $Revision: 1.3 $






#ifndef MATIS_FAKERTIAMBASSADOR_H
#define MATIS_FAKERTIAMBASSADOR_H


#include "MATIS_LibHookup.h"
#include "RTI.hh"

class FAKE_RTI_NAME {
 public:

//File RTIambServices.hh
//Included in RTI.hh
//                RTI Parameter Passing Memory Conventions
//
// C1  In parameter by value.
// C2  Out parameter by pointer value.
// C3  Function return by value.
// C4  In parameter by const pointer value.  Caller provides memory.
//     Caller may free memory or overwrite it upon completion of
//     the call.  Callee must copy during the call anything it
//     wishes to save beyond completion of the call.  Parameter
//     type must define const accessor methods.
// C5  Out parameter by pointer value.  Caller provides reference to object.
//     Callee constructs an instance on the heap (new) and returns.
//     The caller destroys the instance (delete) at its leisure.
// C6  Function return by pointer value.  Callee constructs an instance on
//     the heap (new) and returns a reference.  The caller destroys the
//     instance (delete) at its leisure.
//

typedef RTI::FederateAmbassador *FederateAmbassadorPtr;

////////////////////////////////////
// Federation Management Services //
////////////////////////////////////

// 4.2
void createFederationExecution (
  const char *executionName, // supplied C4
  const char *FED)           // supplied C4
throw (
  RTI::FederationExecutionAlreadyExists,
  RTI::CouldNotOpenFED,
  RTI::ErrorReadingFED,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 4.3
void destroyFederationExecution (
  const char *executionName) // supplied C4
throw (
  RTI::FederatesCurrentlyJoined,
  RTI::FederationExecutionDoesNotExist,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 4.4
RTI::FederateHandle                                               // returned C3
joinFederationExecution (
  const char                   *yourName,                    // supplied C4
  const char                   *executionName,               // supplied C4
        FederateAmbassadorPtr   federateAmbassadorReference) // supplied C1
throw (
  RTI::FederateAlreadyExecutionMember,
  RTI::FederationExecutionDoesNotExist,
  RTI::CouldNotOpenFED,
  RTI::ErrorReadingFED,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 4.5
void resignFederationExecution (
  RTI::ResignAction theAction) // supplied C1
throw (
  RTI::FederateOwnsAttributes,
  RTI::FederateNotExecutionMember,
  RTI::InvalidResignAction,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 4.6
void registerFederationSynchronizationPoint (
  const char *label,  // supplied C4
  const char *theTag) // supplied C4
throw (
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void registerFederationSynchronizationPoint (
  const char                *label,    // supplied C4
  const char                *theTag,   // supplied C4
  const RTI::FederateHandleSet&   syncSet)  // supplied C4
throw (
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 4.9
void synchronizationPointAchieved (
  const char *label) // supplied C4
throw (
  RTI::SynchronizationPointLabelWasNotAnnounced,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 4.11
void requestFederationSave (
  const char     *label,   // supplied C4
  const RTI::FedTime&  theTime) // supplied C4
throw (
  RTI::FederationTimeAlreadyPassed,
  RTI::InvalidFederationTime,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void requestFederationSave (
  const char *label)     // supplied C4
  throw (
    RTI::FederateNotExecutionMember,
    RTI::ConcurrentAccessAttempted,
    RTI::SaveInProgress,
    RTI::RestoreInProgress,
    RTI::RTIinternalError);

// 4.13
void federateSaveBegun ()
throw (
  RTI::SaveNotInitiated,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 4.14
void federateSaveComplete ()
throw (
  RTI::SaveNotInitiated,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void federateSaveNotComplete ()
throw (
  RTI::SaveNotInitiated,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 4.16
void requestFederationRestore (
  const char *label) // supplied C4
throw (
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 4.20
void federateRestoreComplete ()
  throw (
    RTI::RestoreNotRequested,
    RTI::FederateNotExecutionMember,
    RTI::ConcurrentAccessAttempted,
    RTI::SaveInProgress,
    RTI::RTIinternalError);

void federateRestoreNotComplete ()
throw (
  RTI::RestoreNotRequested,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RTIinternalError);

/////////////////////////////////////
// Declaration Management Services //
/////////////////////////////////////

// 5.2
void publishObjectClass (
        RTI::ObjectClassHandle   theClass,      // supplied C1
  const RTI::AttributeHandleSet& attributeList) // supplied C4
throw (
  RTI::ObjectClassNotDefined,
  RTI::AttributeNotDefined,
  RTI::OwnershipAcquisitionPending,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 5.3
void unpublishObjectClass (
  RTI::ObjectClassHandle theClass) // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::ObjectClassNotPublished,
  RTI::OwnershipAcquisitionPending,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 5.4
void publishInteractionClass (
  RTI::InteractionClassHandle theInteraction) // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 5.5
void unpublishInteractionClass (
  RTI::InteractionClassHandle theInteraction) // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotPublished,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 5.6
void subscribeObjectClassAttributes (
        RTI::ObjectClassHandle   theClass,      // supplied C1
  const RTI::AttributeHandleSet& attributeList, // supplied C4
  RTI::Boolean        active = RTI::RTI_TRUE)
throw (
  RTI::ObjectClassNotDefined,
  RTI::AttributeNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 5.7
void unsubscribeObjectClass (
  RTI::ObjectClassHandle theClass) // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::ObjectClassNotSubscribed,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 5.8
void subscribeInteractionClass (
  RTI::InteractionClassHandle theClass, // supplied C1
  RTI::Boolean           active = RTI::RTI_TRUE)
throw (
  RTI::InteractionClassNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::FederateLoggingServiceCalls,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 5.9
void unsubscribeInteractionClass (
  RTI::InteractionClassHandle theClass) // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotSubscribed,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

////////////////////////////////
// Object Management Services //
////////////////////////////////

// 6.2
RTI::ObjectHandle                          // returned C3
registerObjectInstance (
        RTI::ObjectClassHandle  theClass,  // supplied C1
  const char              *theObject) // supplied C4
throw (
  RTI::ObjectClassNotDefined,
  RTI::ObjectClassNotPublished,
  RTI::ObjectAlreadyRegistered,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

RTI::ObjectHandle                         // returned C3
registerObjectInstance (
        RTI::ObjectClassHandle theClass)  // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::ObjectClassNotPublished,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 6.4
RTI::EventRetractionHandle                               // returned C3
updateAttributeValues (
        RTI::ObjectHandle                 theObject,     // supplied C1
  const RTI::AttributeHandleValuePairSet& theAttributes, // supplied C4
  const RTI::FedTime&                     theTime,       // supplied C4
  const char                        *theTag)        // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::InvalidFederationTime,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void updateAttributeValues (
        RTI::ObjectHandle                 theObject,     // supplied C1
  const RTI::AttributeHandleValuePairSet& theAttributes, // supplied C4
  const char                        *theTag)        // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 6.6
RTI::EventRetractionHandle                                // returned C3
sendInteraction (
        RTI::InteractionClassHandle       theInteraction, // supplied C1
  const RTI::ParameterHandleValuePairSet& theParameters,  // supplied C4
  const RTI::FedTime&                     theTime,        // supplied C4
  const char                        *theTag)         // supplied C4
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotPublished,
  RTI::InteractionParameterNotDefined,
  RTI::InvalidFederationTime,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void sendInteraction (
        RTI::InteractionClassHandle       theInteraction, // supplied C1
  const RTI::ParameterHandleValuePairSet& theParameters,  // supplied C4
  const char                        *theTag)         // supplied C4
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotPublished,
  RTI::InteractionParameterNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 6.8
RTI::EventRetractionHandle                 // returned C3
deleteObjectInstance (
        RTI::ObjectHandle    theObject,    // supplied C1
  const RTI::FedTime&        theTime,      // supplied C4
  const char           *theTag)       // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::DeletePrivilegeNotHeld,
  RTI::InvalidFederationTime,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void deleteObjectInstance (
        RTI::ObjectHandle    theObject,    // supplied C1
  const char           *theTag)       // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::DeletePrivilegeNotHeld,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 6.10
void localDeleteObjectInstance (
  RTI::ObjectHandle    theObject)       // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::FederateOwnsAttributes,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 6.11
void changeAttributeTransportationType (
        RTI::ObjectHandle             theObject,     // supplied C1
  const RTI::AttributeHandleSet&      theAttributes, // supplied C4
  RTI::TransportationHandle     theType)       // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::InvalidTransportationHandle,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 6.12
void changeInteractionTransportationType (
  RTI::InteractionClassHandle theClass, // supplied C1
  RTI::TransportationHandle   theType)  // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotPublished,
  RTI::InvalidTransportationHandle,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 6.15
void requestObjectAttributeValueUpdate (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void requestClassAttributeValueUpdate (
        RTI::ObjectClassHandle   theClass,      // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectClassNotDefined,
  RTI::AttributeNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

///////////////////////////////////
// Ownership Management Services //
///////////////////////////////////

// 7.2
void unconditionalAttributeOwnershipDivestiture (
        RTI::ObjectHandle                  theObject,     // supplied C1
  const RTI::AttributeHandleSet&           theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.3
void negotiatedAttributeOwnershipDivestiture (
        RTI::ObjectHandle                  theObject,     // supplied C1
  const RTI::AttributeHandleSet&           theAttributes, // supplied C4
  const char                         *theTag)        // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::AttributeAlreadyBeingDivested,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.7
void attributeOwnershipAcquisition (
        RTI::ObjectHandle        theObject,         // supplied C1
  const RTI::AttributeHandleSet& desiredAttributes, // supplied C4
  const char               *theTag)            // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::ObjectClassNotPublished,
  RTI::AttributeNotDefined,
  RTI::AttributeNotPublished,
  RTI::FederateOwnsAttributes,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.8
void attributeOwnershipAcquisitionIfAvailable (
        RTI::ObjectHandle        theObject,         // supplied C1
  const RTI::AttributeHandleSet& desiredAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::ObjectClassNotPublished,
  RTI::AttributeNotDefined,
  RTI::AttributeNotPublished,
  RTI::FederateOwnsAttributes,
  RTI::AttributeAlreadyBeingAcquired,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.11
RTI::AttributeHandleSet*                        // returned C6
attributeOwnershipReleaseResponse (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::FederateWasNotAskedToReleaseAttribute,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.12
void cancelNegotiatedAttributeOwnershipDivestiture (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::AttributeDivestitureWasNotRequested,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.13
void cancelAttributeOwnershipAcquisition (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeAlreadyOwned,
  RTI::AttributeAcquisitionWasNotRequested,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.15
void queryAttributeOwnership (
  RTI::ObjectHandle    theObject,    // supplied C1
  RTI::AttributeHandle theAttribute) // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 7.17
RTI::Boolean                          // returned C3
isAttributeOwnedByFederate (
  RTI::ObjectHandle    theObject,     // supplied C1
  RTI::AttributeHandle theAttribute)  // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

//////////////////////////////
// Time Management Services //
//////////////////////////////

// 8.2
void enableTimeRegulation (
  const RTI::FedTime& theFederateTime,  // supplied C4
  const RTI::FedTime& theLookahead)     // supplied C4
throw (
  RTI::TimeRegulationAlreadyEnabled,
  RTI::EnableTimeRegulationPending,
  RTI::TimeAdvanceAlreadyInProgress,
  RTI::InvalidFederationTime,
  RTI::InvalidLookahead,
  RTI::ConcurrentAccessAttempted,
  RTI::FederateNotExecutionMember,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.4
void disableTimeRegulation ()
throw (
  RTI::TimeRegulationWasNotEnabled,
  RTI::ConcurrentAccessAttempted,
  RTI::FederateNotExecutionMember,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.5
void enableTimeConstrained ()
throw (
  RTI::TimeConstrainedAlreadyEnabled,
  RTI::EnableTimeConstrainedPending,
  RTI::TimeAdvanceAlreadyInProgress,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.7
void disableTimeConstrained ()
throw (
  RTI::TimeConstrainedWasNotEnabled,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.8
void timeAdvanceRequest (
 const  RTI::FedTime& theTime) // supplied C4
throw (
  RTI::InvalidFederationTime,
  RTI::FederationTimeAlreadyPassed,
  RTI::TimeAdvanceAlreadyInProgress,
  RTI::EnableTimeRegulationPending,
  RTI::EnableTimeConstrainedPending,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.9
void timeAdvanceRequestAvailable (
const RTI::FedTime& theTime) // supplied C4
  throw (
    RTI::InvalidFederationTime,
    RTI::FederationTimeAlreadyPassed,
    RTI::TimeAdvanceAlreadyInProgress,
    RTI::EnableTimeRegulationPending,
    RTI::EnableTimeConstrainedPending,
    RTI::FederateNotExecutionMember,
    RTI::ConcurrentAccessAttempted,
    RTI::SaveInProgress,
    RTI::RestoreInProgress,
    RTI::RTIinternalError);

// 8.10
void nextEventRequest (
  const RTI::FedTime& theTime) // supplied C4
throw (
  RTI::InvalidFederationTime,
  RTI::FederationTimeAlreadyPassed,
  RTI::TimeAdvanceAlreadyInProgress,
  RTI::EnableTimeRegulationPending,
  RTI::EnableTimeConstrainedPending,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.11
void nextEventRequestAvailable (
  const RTI::FedTime& theTime) // supplied C4
throw (
  RTI::InvalidFederationTime,
  RTI::FederationTimeAlreadyPassed,
  RTI::TimeAdvanceAlreadyInProgress,
  RTI::EnableTimeRegulationPending,
  RTI::EnableTimeConstrainedPending,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.12
void flushQueueRequest (
  const RTI::FedTime& theTime) // supplied C4
throw (
  RTI::InvalidFederationTime,
  RTI::FederationTimeAlreadyPassed,
  RTI::TimeAdvanceAlreadyInProgress,
  RTI::EnableTimeRegulationPending,
  RTI::EnableTimeConstrainedPending,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.14
void enableAsynchronousDelivery()
  throw (
    RTI::AsynchronousDeliveryAlreadyEnabled,
    RTI::FederateNotExecutionMember,
    RTI::ConcurrentAccessAttempted,
    RTI::SaveInProgress,
    RTI::RestoreInProgress,
    RTI::RTIinternalError);

// 8.15
void disableAsynchronousDelivery()
  throw (
    RTI::AsynchronousDeliveryAlreadyDisabled,
    RTI::FederateNotExecutionMember,
    RTI::ConcurrentAccessAttempted,
    RTI::SaveInProgress,
    RTI::RestoreInProgress,
    RTI::RTIinternalError);

// 8.16
void queryLBTS (
  RTI::FedTime& theTime) // returned C5
throw (
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.17
void queryFederateTime (
  RTI::FedTime& theTime) // returned C5
throw (
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.18
void queryMinNextEventTime (
  RTI::FedTime& theTime) // returned C5
throw (
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.19
void modifyLookahead (
  const RTI::FedTime& theLookahead) // supplied C4
throw (
  RTI::InvalidLookahead,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.20
void queryLookahead (
   RTI::FedTime& theTime) // returned C5
throw (
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.21
void retract (
  RTI::EventRetractionHandle theHandle) // supplied C1
throw (
  RTI::InvalidRetractionHandle,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.23
void changeAttributeOrderType (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes, // supplied C4
  RTI::OrderingHandle      theType)       // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::AttributeNotOwned,
  RTI::InvalidOrderingHandle,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 8.24
void changeInteractionOrderType (
  RTI::InteractionClassHandle theClass, // supplied C1
  RTI::OrderingHandle         theType)  // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotPublished,
  RTI::InvalidOrderingHandle,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

//////////////////////////////////
// Data Distribution Management //
//////////////////////////////////

// 9.2
RTI::Region*                           // returned C6
createRegion (
  RTI::SpaceHandle theSpace,           // supplied C1
  RTI::ULong       numberOfExtents)    // supplied C1
throw (
  RTI::SpaceNotDefined,
  RTI::InvalidExtents,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.3
void notifyAboutRegionModification (
  RTI::Region &theRegion)  // supplied C4
throw (
  RTI::RegionNotKnown,
  RTI::InvalidExtents,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.4
void deleteRegion (
  RTI::Region *theRegion) // supplied C1
throw (
  RTI::RegionNotKnown,
  RTI::RegionInUse,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.5
RTI::ObjectHandle                                  // returned C3
registerObjectInstanceWithRegion (
        RTI::ObjectClassHandle theClass,           // supplied C1
  const char             *theObject,          // supplied C4
        RTI::AttributeHandle   * const,    // supplied C4
        RTI::Region           ** const,       // supplied C4
        RTI::ULong             theNumberOfHandles) // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::ObjectClassNotPublished,
  RTI::AttributeNotDefined,
  RTI::AttributeNotPublished,
  RTI::RegionNotKnown,
  RTI::InvalidRegionContext,
  RTI::ObjectAlreadyRegistered,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

RTI::ObjectHandle                              // returned C3
registerObjectInstanceWithRegion (
  RTI::ObjectClassHandle theClass,             // supplied C1
  RTI::AttributeHandle   *const  ,      // supplied C4
  RTI::Region           ** const,         // supplied C4
  RTI::ULong             theNumberOfHandles)   // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::ObjectClassNotPublished,
  RTI::AttributeNotDefined,
  RTI::AttributeNotPublished,
  RTI::RegionNotKnown,
  RTI::InvalidRegionContext,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.6
void associateRegionForUpdates (
        RTI::Region             &theRegion,     // supplied C4
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet &theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotDefined,
  RTI::InvalidRegionContext,
  RTI::RegionNotKnown,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.7
void unassociateRegionForUpdates (
  RTI::Region       &theRegion,     // supplied C4
  RTI::ObjectHandle  theObject)     // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::InvalidRegionContext,
  RTI::RegionNotKnown,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.8
void subscribeObjectClassAttributesWithRegion (
        RTI::ObjectClassHandle   theClass,      // supplied C1
        RTI::Region             &theRegion,     // supplied C4
  const RTI::AttributeHandleSet &attributeList, // supplied C4
  RTI::Boolean        active = RTI::RTI_TRUE)
throw (
  RTI::ObjectClassNotDefined,
  RTI::AttributeNotDefined,
  RTI::RegionNotKnown,
  RTI::InvalidRegionContext,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.9
void unsubscribeObjectClassWithRegion (
  RTI::ObjectClassHandle theClass,          // supplied C1
  RTI::Region           &theRegion)         // supplied C4
throw (
  RTI::ObjectClassNotDefined,
  RTI::RegionNotKnown,
  RTI::ObjectClassNotSubscribed,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.10
void subscribeInteractionClassWithRegion (
  RTI::InteractionClassHandle theClass,        // supplied C1
  RTI::Region                &theRegion,       // supplied C4
  RTI::Boolean           active = RTI::RTI_TRUE)
throw (
  RTI::InteractionClassNotDefined,
  RTI::RegionNotKnown,
  RTI::InvalidRegionContext,
  RTI::FederateLoggingServiceCalls,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.11
void unsubscribeInteractionClassWithRegion (
  RTI::InteractionClassHandle theClass,  // supplied C1
  RTI::Region                &theRegion) // supplied C4
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotSubscribed,
  RTI::RegionNotKnown,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.12
RTI::EventRetractionHandle                                // returned C3
sendInteractionWithRegion (
        RTI::InteractionClassHandle       theInteraction, // supplied C1
  const RTI::ParameterHandleValuePairSet &theParameters,  // supplied C4
  const RTI::FedTime&                     theTime,        // supplied C4
  const char                        *theTag,         // supplied C4
  const RTI::Region                      &theRegion)      // supplied C4
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotPublished,
  RTI::InteractionParameterNotDefined,
  RTI::InvalidFederationTime,
  RTI::RegionNotKnown,
  RTI::InvalidRegionContext,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

void sendInteractionWithRegion (
        RTI::InteractionClassHandle       theInteraction, // supplied C1
  const RTI::ParameterHandleValuePairSet &theParameters,  // supplied C4
  const char                        *theTag,         // supplied C4
  const RTI::Region                      &theRegion)      // supplied C4
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionClassNotPublished,
  RTI::InteractionParameterNotDefined,
  RTI::RegionNotKnown,
  RTI::InvalidRegionContext,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 9.13
void requestClassAttributeValueUpdateWithRegion (
        RTI::ObjectClassHandle   theClass,      // supplied C1
  const RTI::AttributeHandleSet &theAttributes, // supplied C4
  const RTI::Region             &theRegion)     // supplied C4
throw (
  RTI::ObjectClassNotDefined,
  RTI::AttributeNotDefined,
  RTI::RegionNotKnown,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

//////////////////////////
// RTI Support Services //
//////////////////////////

// 10.2
RTI::ObjectClassHandle      // returned C3
getObjectClassHandle (
  const char *theName) // supplied C4
throw (
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.3
char *                         // returned C6
getObjectClassName (
  RTI::ObjectClassHandle theHandle) // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.4
RTI::AttributeHandle                       // returned C3
getAttributeHandle (
  const char             *theName,    // supplied C4
        RTI::ObjectClassHandle whichClass) // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.5
char *                          // returned C6
getAttributeName (
  RTI::AttributeHandle   theHandle,  // supplied C1
  RTI::ObjectClassHandle whichClass) // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::AttributeNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.6
RTI::InteractionClassHandle      // returned C3
getInteractionClassHandle (
  const char *theName)      // supplied C4
throw (
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.7
char *                              // returned C6
getInteractionClassName (
  RTI::InteractionClassHandle theHandle) // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.8
RTI::ParameterHandle                            // returned C3
getParameterHandle (
  const char *theName,                     // supplied C4
        RTI::InteractionClassHandle whichClass) // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.9
char *                               // returned C6
getParameterName (
  RTI::ParameterHandle        theHandle,  // supplied C1
  RTI::InteractionClassHandle whichClass) // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::InteractionParameterNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.10
RTI::ObjectHandle                 // returned C3
getObjectInstanceHandle (
  const char *theName)       // supplied C4
throw (
    RTI::ObjectNotKnown,
    RTI::FederateNotExecutionMember,
    RTI::ConcurrentAccessAttempted,
    RTI::RTIinternalError);

// 10.11
char *                     // returned C6
getObjectInstanceName (
  RTI::ObjectHandle theHandle)  // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.12
RTI::SpaceHandle                // returned C3
getRoutingSpaceHandle (
  const char *theName)     // supplied C4
throw (
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.13
char *                         // returned C6
getRoutingSpaceName (
   //
   // This const was removed for the RTI 1.3 NG to work around a limitation of
   // the Sun 4.2 C++ compiler regarding template instantiation.  The const
   // is unnecessary.
   //
   /* const */ RTI::SpaceHandle theHandle) // supplied C4
throw (
  RTI::SpaceNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.14
RTI::DimensionHandle                   // returned C3
getDimensionHandle (
  const char         *theName,    // supplied C4
        RTI::SpaceHandle   whichSpace) // supplied C1
throw (
  RTI::SpaceNotDefined,
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.15
char *                        // returned C6
getDimensionName (
  RTI::DimensionHandle theHandle,  // supplied C1
  RTI::SpaceHandle     whichSpace) // supplied C1
throw (
  RTI::SpaceNotDefined,
  RTI::DimensionNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.16
RTI::SpaceHandle                      // returned C3
getAttributeRoutingSpaceHandle (
  RTI::AttributeHandle   theHandle,   // supplied C1
  RTI::ObjectClassHandle whichClass)  // supplied C1
throw (
  RTI::ObjectClassNotDefined,
  RTI::AttributeNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError) { return 0; }; // TODO

// 10.17
RTI::ObjectClassHandle            // returned C3
getObjectClass (
  RTI::ObjectHandle theObject)    // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.18
RTI::SpaceHandle                             // returned C3
getInteractionRoutingSpaceHandle (
  RTI::InteractionClassHandle   theHandle)   // supplied C1
throw (
  RTI::InteractionClassNotDefined,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError) { return 0; }; // TODO

// 10.19
RTI::TransportationHandle      // returned C3
getTransportationHandle (
  const char *theName)    // supplied C4
throw (
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.20
char *                            // returned C6
getTransportationName (
  RTI::TransportationHandle theHandle) // supplied C1
throw (
  RTI::InvalidTransportationHandle,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.21
RTI::OrderingHandle         // returned C3
getOrderingHandle (
  const char *theName) // supplied C4
throw (
  RTI::NameNotFound,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.22
char *                      // returned C6
getOrderingName (
  RTI::OrderingHandle theHandle) // supplied C1
throw (
  RTI::InvalidOrderingHandle,
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

// 10.23
void enableClassRelevanceAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 10.24
void disableClassRelevanceAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 10.25
void enableAttributeRelevanceAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 10.26
void disableAttributeRelevanceAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 10.27
void enableAttributeScopeAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 10.28
void disableAttributeScopeAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 10.29
void enableInteractionRelevanceAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

// 10.30
void disableInteractionRelevanceAdvisorySwitch()
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::SaveInProgress,
  RTI::RestoreInProgress,
  RTI::RTIinternalError);

//
RTI::Boolean // returned C3
tick ()
throw (
  RTI::SpecifiedSaveLabelDoesNotExist,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

RTI::Boolean             // returned C3
tick (
  RTI::TickTime minimum, // supplied C1
  RTI::TickTime maximum) // supplied C1
throw (
  RTI::SpecifiedSaveLabelDoesNotExist,
  RTI::ConcurrentAccessAttempted,
  RTI::RTIinternalError);

/*
RTIambassador()
throw (
  RTI::MemoryExhausted,
  RTI::RTIinternalError);

~RTIambassador()
throw (RTI::RTIinternalError);

*/

RTI::RegionToken
getRegionToken(
  RTI::Region *)
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RegionNotKnown,
  RTI::RTIinternalError);

RTI::Region *
getRegion(
  RTI::RegionToken)
throw(
  RTI::FederateNotExecutionMember,
  RTI::ConcurrentAccessAttempted,
  RTI::RegionNotKnown,
  RTI::RTIinternalError);





};

#endif
