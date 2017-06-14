// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_FederateAmbassador.h,v $
// CVS $Date: 2005/11/11 04:51:13 $
// CVS $Revision: 1.1.1.1 $






// Automatically generated.  Edit at own risk!

#ifndef MATIS_FEDERATE_AMBASSADOR_H
#define MATIS_FEDERATE_AMBASSADOR_H
#include "RTI.hh"

class MATIS_FederateAmbassador:public RTI::FederateAmbassador {
  public:

    /**
      * Default construction
      */
    MATIS_FederateAmbassador() {
    }

    /**
      * Default destruction
      */ ~
    MATIS_FederateAmbassador()
    throw(RTI::FederateInternalError) {
    }

    void
     synchronizationPointRegistrationSucceeded(const char *label)
     throw(RTI::FederateInternalError);

    void
     synchronizationPointRegistrationFailed(const char *label)
     throw(RTI::FederateInternalError);

    void
     announceSynchronizationPoint(const char *label, const char *tag)
     throw(RTI::FederateInternalError);

    void
     federationSynchronized(const char *label)
     throw(RTI::FederateInternalError);

    void
     initiateFederateSave(const char *label)
     throw(RTI::UnableToPerformSave, RTI::FederateInternalError);

    void
     federationSaved()
     throw(RTI::FederateInternalError);

    void
     federationNotSaved()
     throw(RTI::FederateInternalError);

    void
     requestFederationRestoreSucceeded(const char *label)
     throw(RTI::FederateInternalError);

    void
     requestFederationRestoreFailed(const char *label, const char *reason)
     throw(RTI::FederateInternalError);

    void
     federationRestoreBegun()
     throw(RTI::FederateInternalError);

    void
     initiateFederateRestore(const char *label, RTI::FederateHandle handle)
     throw(RTI::SpecifiedSaveLabelDoesNotExist,
           RTI::CouldNotRestore, RTI::FederateInternalError);

    void
     federationRestored()
     throw(RTI::FederateInternalError);

    void
     federationNotRestored()
     throw(RTI::FederateInternalError);

    void
     startRegistrationForObjectClass(RTI::ObjectClassHandle theClass)
     throw(RTI::ObjectClassNotPublished, RTI::FederateInternalError);

    void
     stopRegistrationForObjectClass(RTI::ObjectClassHandle theClass)
     throw(RTI::ObjectClassNotPublished, RTI::FederateInternalError);

    void
     turnInteractionsOn(RTI::InteractionClassHandle theHandle)
     throw(RTI::InteractionClassNotPublished, RTI::FederateInternalError);

    void
     turnInteractionsOff(RTI::InteractionClassHandle theHandle)
     throw(RTI::InteractionClassNotPublished, RTI::FederateInternalError);

    void
     discoverObjectInstance(RTI::ObjectHandle theObject,
                            RTI::ObjectClassHandle theObjectClass,
                            const char *theObjectName)
     throw(RTI::CouldNotDiscover,
           RTI::ObjectClassNotKnown, RTI::FederateInternalError);

    void
     reflectAttributeValues(RTI::ObjectHandle theObject,
                            const RTI::
                            AttributeHandleValuePairSet & theAttributes,
                            const RTI::FedTime & theTime,
                            const char *theTag,
                            RTI::EventRetractionHandle theHandle)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::FederateOwnsAttributes,
           RTI::InvalidFederationTime, RTI::FederateInternalError);

    void
     reflectAttributeValues(RTI::ObjectHandle theObject,
                            const RTI::
                            AttributeHandleValuePairSet & theAttributes,
                            const char *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::FederateOwnsAttributes, RTI::FederateInternalError);

    void
     receiveInteraction(RTI::InteractionClassHandle theInteraction,
                        const RTI::
                        ParameterHandleValuePairSet & theParameters,
                        const RTI::FedTime & theTime,
                        const char *theTag,
                        RTI::EventRetractionHandle theHandle)
     throw(RTI::InteractionClassNotKnown,
           RTI::InteractionParameterNotKnown,
           RTI::InvalidFederationTime, RTI::FederateInternalError);

    void
     receiveInteraction(RTI::InteractionClassHandle theInteraction,
                        const RTI::
                        ParameterHandleValuePairSet & theParameters,
                        const char *theTag)
     throw(RTI::InteractionClassNotKnown,
           RTI::InteractionParameterNotKnown, RTI::FederateInternalError);

    void
     removeObjectInstance(RTI::ObjectHandle theObject,
                          const RTI::FedTime & theTime,
                          const char *theTag,
                          RTI::EventRetractionHandle theHandle)
     throw(RTI::ObjectNotKnown,
           RTI::InvalidFederationTime, RTI::FederateInternalError);

    void
     removeObjectInstance(RTI::ObjectHandle theObject, const char *theTag)
     throw(RTI::ObjectNotKnown, RTI::FederateInternalError);

    void
     attributesInScope(RTI::ObjectHandle theObject,
                       const RTI::AttributeHandleSet & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown, RTI::FederateInternalError);

    void
     attributesOutOfScope(RTI::ObjectHandle theObject,
                          const RTI::AttributeHandleSet & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown, RTI::FederateInternalError);

    void
     provideAttributeValueUpdate(RTI::ObjectHandle theObject,
                                 const RTI::
                                 AttributeHandleSet & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::AttributeNotOwned, RTI::FederateInternalError);

    void
     turnUpdatesOnForObjectInstance(RTI::ObjectHandle theObject,
                                    const RTI::
                                    AttributeHandleSet & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotOwned, RTI::FederateInternalError);

    void
     turnUpdatesOffForObjectInstance(RTI::ObjectHandle theObject,
                                     const RTI::
                                     AttributeHandleSet & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotOwned, RTI::FederateInternalError);

    void
     requestAttributeOwnershipAssumption(RTI::ObjectHandle theObject,
                                         const RTI::
                                         AttributeHandleSet &
                                         offeredAttributes,
                                         const char *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::AttributeAlreadyOwned,
           RTI::AttributeNotPublished, RTI::FederateInternalError);

    void

     attributeOwnershipDivestitureNotification(RTI::
                                               ObjectHandle theObject,
                                               const RTI::
                                               AttributeHandleSet &
                                               releasedAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::AttributeNotOwned,
           RTI::AttributeDivestitureWasNotRequested,
           RTI::FederateInternalError);

    void

     attributeOwnershipAcquisitionNotification(RTI::
                                               ObjectHandle theObject,
                                               const RTI::
                                               AttributeHandleSet &
                                               securedAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::AttributeAcquisitionWasNotRequested,
           RTI::AttributeAlreadyOwned,
           RTI::AttributeNotPublished, RTI::FederateInternalError);

    void
     attributeOwnershipUnavailable(RTI::ObjectHandle theObject,
                                   const RTI::
                                   AttributeHandleSet & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeAlreadyOwned,
           RTI::AttributeAcquisitionWasNotRequested,
           RTI::FederateInternalError);

    void
     requestAttributeOwnershipRelease(RTI::ObjectHandle theObject,
                                      const RTI::
                                      AttributeHandleSet &
                                      candidateAttributes,
                                      const char *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::AttributeNotOwned, RTI::FederateInternalError);

    void

     confirmAttributeOwnershipAcquisitionCancellation(RTI::
                                                      ObjectHandle
                                                      theObject,
                                                      const RTI::
                                                      AttributeHandleSet
                                                      & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeAlreadyOwned,
           RTI::AttributeAcquisitionWasNotCanceled,
           RTI::FederateInternalError);

    void
     informAttributeOwnership(RTI::ObjectHandle theObject,
                              RTI::AttributeHandle theAttribute,
                              RTI::FederateHandle theOwner)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown, RTI::FederateInternalError);

    void
     attributeIsNotOwned(RTI::ObjectHandle theObject,
                         RTI::AttributeHandle theAttribute)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown, RTI::FederateInternalError);

    void
     attributeOwnedByRTI(RTI::ObjectHandle theObject,
                         RTI::AttributeHandle theAttribute)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotKnown, RTI::FederateInternalError);

    void
     timeRegulationEnabled(const RTI::FedTime & theFederateTime)
     throw(RTI::InvalidFederationTime,
           RTI::EnableTimeRegulationWasNotPending,
           RTI::FederateInternalError);

    void
     timeConstrainedEnabled(const RTI::FedTime & theFederateTime)
     throw(RTI::InvalidFederationTime,
           RTI::EnableTimeConstrainedWasNotPending,
           RTI::FederateInternalError);

    void
     timeAdvanceGrant(const RTI::FedTime & theTime)
     throw(RTI::InvalidFederationTime,
           RTI::TimeAdvanceWasNotInProgress,
           RTI::FederationTimeAlreadyPassed, RTI::FederateInternalError);

    void
     requestRetraction(RTI::EventRetractionHandle theHandle)
     throw(RTI::EventNotKnown, RTI::FederateInternalError);

};
#endif
