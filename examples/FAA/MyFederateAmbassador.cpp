//-----------------------------------------------------------------
// Project Include Files
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// System Include Files
//-----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

#include "MyFederateAmbassador.h"

MyFederateAmbassador::MyFederateAmbassador()
{
}

MyFederateAmbassador::~MyFederateAmbassador()
throw(RTI::FederateInternalError)
{
}

////////////////////////////////////
// Federation Management Services //
////////////////////////////////////

void MyFederateAmbassador::synchronizationPointRegistrationSucceeded (
  const char *label) // supplied C4)
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : synchronizationPointRegistrationSucceeded not supported in FedAmbassador"
        << endl;
}

void MyFederateAmbassador::synchronizationPointRegistrationFailed (
  const char *label) // supplied C4)
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : synchronizationPointRegistrationFailed not supported in FedAmbassador"
        << endl;
}

void MyFederateAmbassador::announceSynchronizationPoint (
  const char *label, // supplied C4
  const char *tag)   // supplied C4
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : announceSynchronizationPoint not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::federationSynchronized (
  const char *label) // supplied C4)
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : federationSynchronized not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::initiateFederateSave (
  const char *label) // supplied C4
throw (
  RTI::UnableToPerformSave,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : initiateFederateSave not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::federationSaved ()
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : federationSaved not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::federationNotSaved ()
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : federationNotSaved not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::requestFederationRestoreSucceeded (
  const char *label) // supplied C4
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : requestFederationRestoreSucceeded not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::requestFederationRestoreFailed (
  const char *label) // supplied C4
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : requestFederationRestoreFailed not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::requestFederationRestoreFailed (
  const char *label,
  const char *reason) // supplied C4
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : requestFederationRestoreFailed not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::federationRestoreBegun ()
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : federationRestoreBegun not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::initiateFederateRestore (
  const char               *label,   // supplied C4
        RTI::FederateHandle handle)  // supplied C1
throw (
  RTI::SpecifiedSaveLabelDoesNotExist,
  RTI::CouldNotRestore,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : initiateFederateRestore not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::federationRestored ()
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : federationRestored not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::federationNotRestored ()
throw (
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : federationNotRestored not supported in FedAmbassador" << endl;
}


/////////////////////////////////////
// Declaration Management Services //
/////////////////////////////////////

void MyFederateAmbassador::startRegistrationForObjectClass (
        RTI::ObjectClassHandle   theClass)      // supplied C1
throw (
  RTI::ObjectClassNotPublished,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : startRegistrationForObjectClass not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::stopRegistrationForObjectClass (
        RTI::ObjectClassHandle   theClass)      // supplied C1
throw (
  RTI::ObjectClassNotPublished,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : stopRegistrationForObjectClass not supported in FedAmbassador" << endl;
}


void MyFederateAmbassador::turnInteractionsOn (
  RTI::InteractionClassHandle theHandle) // supplied C1
throw (
  RTI::InteractionClassNotPublished,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : turnInteractionsOn not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::turnInteractionsOff (
  RTI::InteractionClassHandle theHandle) // supplied C1
throw (
  RTI::InteractionClassNotPublished,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : turnInteractionsOff not supported in FedAmbassador" << endl;
}

////////////////////////////////
// Object Management Services //
////////////////////////////////

void MyFederateAmbassador::discoverObjectInstance (
  RTI::ObjectHandle          theObject,      // supplied C1
  RTI::ObjectClassHandle     theObjectClass, // supplied C1
  const char *          theObjectName)  // supplied C4
throw (
  RTI::CouldNotDiscover,
  RTI::ObjectClassNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : discoverObjectInstance not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::reflectAttributeValues (
        RTI::ObjectHandle                 theObject,     // supplied C1
  const RTI::AttributeHandleValuePairSet& theAttributes, // supplied C4
  const RTI::FedTime&                     theTime,       // supplied C1
  const char                             *theTag,        // supplied C4
        RTI::EventRetractionHandle        theHandle)     // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::FederateOwnsAttributes,
  RTI::InvalidFederationTime,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : reflectAttributeValues not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::reflectAttributeValues (
        RTI::ObjectHandle                 theObject,     // supplied C1
  const RTI::AttributeHandleValuePairSet& theAttributes, // supplied C4
  const char                             *theTag)        // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::FederateOwnsAttributes,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : reflectAttributeValues not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::receiveInteraction (
        RTI::InteractionClassHandle       theInteraction, // supplied C1
  const RTI::ParameterHandleValuePairSet& theParameters,  // supplied C4
  const RTI::FedTime&                     theTime,        // supplied C4
  const char                             *theTag,         // supplied C4
        RTI::EventRetractionHandle        theHandle)      // supplied C1
throw (
  RTI::InteractionClassNotKnown,
  RTI::InteractionParameterNotKnown,
  RTI::InvalidFederationTime,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : receiveInteraction not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::receiveInteraction (
        RTI::InteractionClassHandle       theInteraction, // supplied C1
  const RTI::ParameterHandleValuePairSet& theParameters,  // supplied C4
  const char                             *theTag)         // supplied C4
throw (
  RTI::InteractionClassNotKnown,
  RTI::InteractionParameterNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : receiveInteraction not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::removeObjectInstance (
        RTI::ObjectHandle          theObject, // supplied C1
  const RTI::FedTime&              theTime,   // supplied C4
  const char                      *theTag,    // supplied C4
        RTI::EventRetractionHandle theHandle) // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::InvalidFederationTime,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : removeObjectInstance not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::removeObjectInstance (
        RTI::ObjectHandle          theObject, // supplied C1
  const char                      *theTag)    // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : removeObjectInstance not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::attributesInScope (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : attributesInScope not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::attributesOutOfScope (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : attributesOutOfScope not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::provideAttributeValueUpdate (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::AttributeNotOwned,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : provideAttributeValueUpdate not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::turnUpdatesOnForObjectInstance (
        RTI::ObjectHandle        theObject,     // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotOwned,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : turnUpdatesOnForObjectInstance not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::turnUpdatesOffForObjectInstance (
        RTI::ObjectHandle        theObject,      // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotOwned,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : turnUpdatesOffForObjectInstance not supported in FedAmbassador" << endl;
}

///////////////////////////////////
// Ownership Management Services //
///////////////////////////////////

void MyFederateAmbassador::requestAttributeOwnershipAssumption (
        RTI::ObjectHandle        theObject,         // supplied C1
  const RTI::AttributeHandleSet& offeredAttributes, // supplied C4
  const char                    *theTag)            // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::AttributeAlreadyOwned,
  RTI::AttributeNotPublished,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : requestAttributeOwnershipAssumption not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::attributeOwnershipDivestitureNotification (
        RTI::ObjectHandle        theObject,          // supplied C1
  const RTI::AttributeHandleSet& releasedAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::AttributeNotOwned,
  RTI::AttributeDivestitureWasNotRequested,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : attributeOwnershipDivestitureNotification not supported in FedAmbassador"
        << endl;
}

void MyFederateAmbassador::attributeOwnershipAcquisitionNotification (
        RTI::ObjectHandle        theObject,         // supplied C1
  const RTI::AttributeHandleSet& securedAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::AttributeAcquisitionWasNotRequested,
  RTI::AttributeAlreadyOwned,
  RTI::AttributeNotPublished,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : attributeOwnershipAcquisitionNotification not supported in FedAmbassador"
        << endl;
}

void MyFederateAmbassador::attributeOwnershipUnavailable (
        RTI::ObjectHandle        theObject,         // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::AttributeAlreadyOwned,
  RTI::AttributeAcquisitionWasNotRequested,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : attributeOwnershipUnavailable not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::requestAttributeOwnershipRelease (
        RTI::ObjectHandle        theObject,           // supplied C1
  const RTI::AttributeHandleSet& candidateAttributes, // supplied C4
  const char                    *theTag)              // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::AttributeNotOwned,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : requestAttributeOwnershipRelease not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::confirmAttributeOwnershipAcquisitionCancellation (
        RTI::ObjectHandle        theObject,         // supplied C1
  const RTI::AttributeHandleSet& theAttributes) // supplied C4
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::AttributeAlreadyOwned,
  RTI::AttributeAcquisitionWasNotCanceled,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : confirmAttributeOwnershipAcquisitionCancellation not"
        << " supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::informAttributeOwnership (
  RTI::ObjectHandle    theObject,    // supplied C1
  RTI::AttributeHandle theAttribute, // supplied C1
  RTI::FederateHandle  theOwner)     // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : informAttributeOwnership not supported in FedAmbassador" << endl;
}

 void MyFederateAmbassador::attributeIsNotOwned (
  RTI::ObjectHandle    theObject,    // supplied C1
  RTI::AttributeHandle theAttribute) // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : attributeIsNotOwned not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::attributeOwnedByRTI (
  RTI::ObjectHandle    theObject,    // supplied C1
  RTI::AttributeHandle theAttribute) // supplied C1
throw (
  RTI::ObjectNotKnown,
  RTI::AttributeNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : attributeOwnedByRTI not supported in FedAmbassador" << endl;
}

//////////////////////////////
// Time Management Services //
//////////////////////////////

void MyFederateAmbassador::timeRegulationEnabled (
 const  RTI::FedTime& theFederateTime) // supplied C4
throw (
  RTI::InvalidFederationTime,
  RTI::EnableTimeRegulationWasNotPending,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : timeRegulationEnabled not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::timeConstrainedEnabled (
  const RTI::FedTime& theFederateTime) // supplied C4
throw (
  RTI::InvalidFederationTime,
  RTI::EnableTimeConstrainedWasNotPending,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : timeConstrainedEnabled not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::timeAdvanceGrant (
  const RTI::FedTime& theTime) // supplied C4
throw (
  RTI::InvalidFederationTime,
  RTI::TimeAdvanceWasNotInProgress,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : timeAdvanceGrant not supported in FedAmbassador" << endl;
}

void MyFederateAmbassador::requestRetraction (
  RTI::EventRetractionHandle theHandle) // supplied C1
throw (
  RTI::EventNotKnown,
  RTI::FederateInternalError)
{
   cerr << "[FAA][MyFederateAmbassador] : requestRetraction not supported in FedAmbassador" << endl;
}

