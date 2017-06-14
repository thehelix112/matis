// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_RTIAmbassador.h,v $
// CVS $Date: 2005/11/22 07:10:45 $
// CVS $Revision: 1.2 $






// Automatically generated.  Edit at own risk!

#ifndef MATIS_RTIAMBASSADOR_H
#define MATIS_RTIAMBASSADOR_H
#include "RTI.hh"

class MATIS_RTIAmbassador {

  public:
    static
    void (*funcptr_RTI__RTIambassador__createFederationExecution2) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    const
                                                                    char *,
                                                                    const
                                                                    char
                                                                    *);

    static void createFederationExecution(RTI::RTIambassador * rtiAmb,
                                          const char *executionName,
                                          const char *FED)
     throw(RTI::FederationExecutionAlreadyExists,
           RTI::CouldNotOpenFED,
           RTI::ErrorReadingFED,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__destroyFederationExecution1) (RTI::
                                                                     RTIambassador
                                                                     *,
                                                                     const
                                                                     char
                                                                     *);

    static void destroyFederationExecution(RTI::RTIambassador * rtiAmb,
                                           const char *executionName)
     throw(RTI::FederatesCurrentlyJoined,
           RTI::FederationExecutionDoesNotExist,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        FederateHandle
        (*funcptr_RTI__RTIambassador__joinFederationExecution3)
     (RTI::RTIambassador *,
      const char *, const char *, RTI::FederateAmbassadorPtr);

    static RTI::FederateHandle joinFederationExecution(RTI::RTIambassador *
                                                       rtiAmb, const char
                                                       *yourName, const char
                                                       *executionName,
                                                       RTI::
                                                       FederateAmbassadorPtr
                                                       federateAmbassadorReference)
     throw(RTI::FederateAlreadyExecutionMember,
           RTI::FederationExecutionDoesNotExist,
           RTI::CouldNotOpenFED,
           RTI::ErrorReadingFED,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__resignFederationExecution1) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    ResignAction);

    static void resignFederationExecution(RTI::RTIambassador * rtiAmb,
                                          RTI::ResignAction theAction)
     throw(RTI::FederateOwnsAttributes,
           RTI::FederateNotExecutionMember,
           RTI::InvalidResignAction,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint2)
     (RTI::RTIambassador *, const char *, const char *);

    static void registerFederationSynchronizationPoint(RTI::RTIambassador *
                                                       rtiAmb,
                                                       const char *label,
                                                       const char *theTag)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint3)
     (RTI::RTIambassador *,
      const char *, const char *, const RTI::FederateHandleSet &);

    static void registerFederationSynchronizationPoint(RTI::RTIambassador *
                                                       rtiAmb,
                                                       const char *label,
                                                       const char *theTag,
                                                       const RTI::
                                                       FederateHandleSet &
                                                       syncSet)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__synchronizationPointAchieved1)
     (RTI::RTIambassador *, const char *);

    static void synchronizationPointAchieved(RTI::RTIambassador * rtiAmb,
                                             const char *label)
     throw(RTI::SynchronizationPointLabelWasNotAnnounced,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__requestFederationSave2) (RTI::
                                                                RTIambassador
                                                                *,
                                                                const
                                                                char *,
                                                                const
                                                                RTI::
                                                                FedTime &);

    static void requestFederationSave(RTI::RTIambassador * rtiAmb,
                                      const char *label,
                                      const RTI::FedTime & theTime)
     throw(RTI::FederationTimeAlreadyPassed,
           RTI::InvalidFederationTime,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__requestFederationSave1) (RTI::
                                                                RTIambassador
                                                                *,
                                                                const
                                                                char *);

    static void requestFederationSave(RTI::RTIambassador * rtiAmb,
                                      const char *label)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__federateSaveBegun0) (RTI::
                                                                   RTIambassador
                                                                   *);

    static void federateSaveBegun(RTI::RTIambassador * rtiAmb)
     throw(RTI::SaveNotInitiated,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__federateSaveComplete0) (RTI::
                                                                      RTIambassador
                                                                      *);

    static void federateSaveComplete(RTI::RTIambassador * rtiAmb)
     throw(RTI::SaveNotInitiated,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__federateSaveNotComplete0) (RTI::
                                                                  RTIambassador
                                                                  *);

    static void federateSaveNotComplete(RTI::RTIambassador * rtiAmb)
     throw(RTI::SaveNotInitiated,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__requestFederationRestore1) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   const
                                                                   char *);

    static void requestFederationRestore(RTI::RTIambassador * rtiAmb,
                                         const char *label)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__federateRestoreComplete0) (RTI::
                                                                  RTIambassador
                                                                  *);

    static void federateRestoreComplete(RTI::RTIambassador * rtiAmb)
     throw(RTI::RestoreNotRequested,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__federateRestoreNotComplete0) (RTI::
                                                                     RTIambassador
                                                                     *);

    static void federateRestoreNotComplete(RTI::RTIambassador * rtiAmb)
     throw(RTI::RestoreNotRequested,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__publishObjectClass2) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    ObjectClassHandle,
                                                                    const
                                                                    RTI::
                                                                    AttributeHandleSet
                                                                    &);

    static void publishObjectClass(RTI::RTIambassador * rtiAmb,
                                   RTI::ObjectClassHandle theClass,
                                   const RTI::
                                   AttributeHandleSet & attributeList)
     throw(RTI::ObjectClassNotDefined,
           RTI::AttributeNotDefined,
           RTI::OwnershipAcquisitionPending,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__unpublishObjectClass1) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      RTI::
                                                                      ObjectClassHandle);

    static void unpublishObjectClass(RTI::RTIambassador * rtiAmb,
                                     RTI::ObjectClassHandle theClass)
     throw(RTI::ObjectClassNotDefined,
           RTI::ObjectClassNotPublished,
           RTI::OwnershipAcquisitionPending,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__publishInteractionClass1) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  RTI::
                                                                  InteractionClassHandle);

    static void publishInteractionClass(RTI::RTIambassador * rtiAmb,
                                        RTI::
                                        InteractionClassHandle
                                        theInteraction)
     throw(RTI::InteractionClassNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__unpublishInteractionClass1) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    InteractionClassHandle);

    static void unpublishInteractionClass(RTI::RTIambassador * rtiAmb,
                                          RTI::
                                          InteractionClassHandle
                                          theInteraction)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotPublished,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__subscribeObjectClassAttributes3)
     (RTI::RTIambassador *,
      RTI::ObjectClassHandle,
      const RTI::AttributeHandleSet &, RTI::Boolean);

    static void subscribeObjectClassAttributes(RTI::RTIambassador * rtiAmb,
                                               RTI::
                                               ObjectClassHandle theClass,
                                               const RTI::
                                               AttributeHandleSet &
                                               attributeList,
                                               RTI::Boolean active)
     throw(RTI::ObjectClassNotDefined,
           RTI::AttributeNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__unsubscribeObjectClass1) (RTI::
                                                                 RTIambassador
                                                                 *,
                                                                 RTI::
                                                                 ObjectClassHandle);

    static void unsubscribeObjectClass(RTI::RTIambassador * rtiAmb,
                                       RTI::ObjectClassHandle theClass)
     throw(RTI::ObjectClassNotDefined,
           RTI::ObjectClassNotSubscribed,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__subscribeInteractionClass2) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    InteractionClassHandle,
                                                                    RTI::
                                                                    Boolean);

    static void subscribeInteractionClass(RTI::RTIambassador * rtiAmb,
                                          RTI::
                                          InteractionClassHandle theClass,
                                          RTI::Boolean active)
     throw(RTI::InteractionClassNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::FederateLoggingServiceCalls,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__unsubscribeInteractionClass1) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      RTI::
                                                                      InteractionClassHandle);

    static void unsubscribeInteractionClass(RTI::RTIambassador * rtiAmb,
                                            RTI::
                                            InteractionClassHandle
                                            theClass)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotSubscribed,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        ObjectHandle(*funcptr_RTI__RTIambassador__registerObjectInstance2)
     (RTI::RTIambassador *, RTI::ObjectClassHandle, const char *);

    static RTI::ObjectHandle registerObjectInstance(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    ObjectClassHandle
                                                    theClass,
                                                    const char *theObject)
     throw(RTI::ObjectClassNotDefined,
           RTI::ObjectClassNotPublished,
           RTI::ObjectAlreadyRegistered,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        ObjectHandle(*funcptr_RTI__RTIambassador__registerObjectInstance1)
     (RTI::RTIambassador *, RTI::ObjectClassHandle);

    static RTI::ObjectHandle registerObjectInstance(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    ObjectClassHandle
                                                    theClass)
     throw(RTI::ObjectClassNotDefined,
           RTI::ObjectClassNotPublished,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        EventRetractionHandle
        (*funcptr_RTI__RTIambassador__updateAttributeValues4) (RTI::
                                                               RTIambassador
                                                               *,
                                                               RTI::
                                                               ObjectHandle,
                                                               const RTI::
                                                               AttributeHandleValuePairSet
                                                               &,
                                                               const RTI::
                                                               FedTime &,
                                                               const char
                                                               *);

    static RTI::EventRetractionHandle updateAttributeValues(RTI::
                                                            RTIambassador *
                                                            rtiAmb,
                                                            RTI::
                                                            ObjectHandle
                                                            theObject,
                                                            const RTI::
                                                            AttributeHandleValuePairSet
                                                            &
                                                            theAttributes,
                                                            const RTI::
                                                            FedTime &
                                                            theTime,
                                                            const char
                                                            *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::InvalidFederationTime,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__updateAttributeValues3) (RTI::
                                                                RTIambassador
                                                                *,
                                                                RTI::
                                                                ObjectHandle,
                                                                const
                                                                RTI::
                                                                AttributeHandleValuePairSet
                                                                &,
                                                                const
                                                                char *);

    static void updateAttributeValues(RTI::RTIambassador * rtiAmb,
                                      RTI::ObjectHandle theObject,
                                      const RTI::
                                      AttributeHandleValuePairSet &
                                      theAttributes, const char *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        EventRetractionHandle
        (*funcptr_RTI__RTIambassador__sendInteraction4)
     (RTI::RTIambassador *,
      RTI::InteractionClassHandle,
      const RTI::ParameterHandleValuePairSet &,
      const RTI::FedTime &, const char *);

    static RTI::EventRetractionHandle sendInteraction(RTI::RTIambassador *
                                                      rtiAmb,
                                                      RTI::
                                                      InteractionClassHandle
                                                      theInteraction,
                                                      const RTI::
                                                      ParameterHandleValuePairSet
                                                      & theParameters,
                                                      const RTI::
                                                      FedTime & theTime,
                                                      const char *theTag)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotPublished,
           RTI::InteractionParameterNotDefined,
           RTI::InvalidFederationTime,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__sendInteraction3) (RTI::
                                                                 RTIambassador
                                                                 *,
                                                                 RTI::
                                                                 InteractionClassHandle,
                                                                 const
                                                                 RTI::
                                                                 ParameterHandleValuePairSet
                                                                 &,
                                                                 const char
                                                                 *);

    static void sendInteraction(RTI::RTIambassador * rtiAmb,
                                RTI::InteractionClassHandle theInteraction,
                                const RTI::
                                ParameterHandleValuePairSet &
                                theParameters, const char *theTag)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotPublished,
           RTI::InteractionParameterNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        EventRetractionHandle
        (*funcptr_RTI__RTIambassador__deleteObjectInstance3) (RTI::
                                                              RTIambassador
                                                              *,
                                                              RTI::
                                                              ObjectHandle,
                                                              const RTI::
                                                              FedTime &,
                                                              const char
                                                              *);

    static RTI::EventRetractionHandle deleteObjectInstance(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           RTI::
                                                           ObjectHandle
                                                           theObject,
                                                           const RTI::
                                                           FedTime &
                                                           theTime,
                                                           const char
                                                           *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::DeletePrivilegeNotHeld,
           RTI::InvalidFederationTime,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__deleteObjectInstance2) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      RTI::
                                                                      ObjectHandle,
                                                                      const
                                                                      char
                                                                      *);

    static void deleteObjectInstance(RTI::RTIambassador * rtiAmb,
                                     RTI::ObjectHandle theObject,
                                     const char *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::DeletePrivilegeNotHeld,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__localDeleteObjectInstance1) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    ObjectHandle);

    static void localDeleteObjectInstance(RTI::RTIambassador * rtiAmb,
                                          RTI::ObjectHandle theObject)
     throw(RTI::ObjectNotKnown,
           RTI::FederateOwnsAttributes,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__changeAttributeTransportationType3)
     (RTI::RTIambassador *,
      RTI::ObjectHandle,
      const RTI::AttributeHandleSet &, RTI::TransportationHandle);

    static void changeAttributeTransportationType(RTI::RTIambassador *
                                                  rtiAmb,
                                                  RTI::
                                                  ObjectHandle theObject,
                                                  const RTI::
                                                  AttributeHandleSet &
                                                  theAttributes,
                                                  RTI::
                                                  TransportationHandle
                                                  theType)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::InvalidTransportationHandle,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void
     (*funcptr_RTI__RTIambassador__changeInteractionTransportationType2)
     (RTI::RTIambassador *,
      RTI::InteractionClassHandle, RTI::TransportationHandle);

    static void changeInteractionTransportationType(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    InteractionClassHandle
                                                    theClass,
                                                    RTI::
                                                    TransportationHandle
                                                    theType)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotPublished,
           RTI::InvalidTransportationHandle,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__requestObjectAttributeValueUpdate2)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &);

    static void requestObjectAttributeValueUpdate(RTI::RTIambassador *
                                                  rtiAmb,
                                                  RTI::
                                                  ObjectHandle theObject,
                                                  const RTI::
                                                  AttributeHandleSet &
                                                  theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__requestClassAttributeValueUpdate2)
     (RTI::RTIambassador *,
      RTI::ObjectClassHandle, const RTI::AttributeHandleSet &);

    static void requestClassAttributeValueUpdate(RTI::RTIambassador *
                                                 rtiAmb,
                                                 RTI::
                                                 ObjectClassHandle
                                                 theClass,
                                                 const RTI::
                                                 AttributeHandleSet &
                                                 theAttributes)
     throw(RTI::ObjectClassNotDefined,
           RTI::AttributeNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture2)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &);

    static void unconditionalAttributeOwnershipDivestiture(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           RTI::
                                                           ObjectHandle
                                                           theObject,
                                                           const RTI::
                                                           AttributeHandleSet
                                                           & theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture3)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &, const char *);

    static void negotiatedAttributeOwnershipDivestiture(RTI::
                                                        RTIambassador *
                                                        rtiAmb,
                                                        RTI::
                                                        ObjectHandle
                                                        theObject,
                                                        const RTI::
                                                        AttributeHandleSet
                                                        & theAttributes,
                                                        const char *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::AttributeAlreadyBeingDivested,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__attributeOwnershipAcquisition3)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &, const char *);

    static void attributeOwnershipAcquisition(RTI::RTIambassador * rtiAmb,
                                              RTI::ObjectHandle theObject,
                                              const RTI::
                                              AttributeHandleSet &
                                              desiredAttributes,
                                              const char *theTag)
     throw(RTI::ObjectNotKnown,
           RTI::ObjectClassNotPublished,
           RTI::AttributeNotDefined,
           RTI::AttributeNotPublished,
           RTI::FederateOwnsAttributes,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable2)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &);

    static void attributeOwnershipAcquisitionIfAvailable(RTI::
                                                         RTIambassador *
                                                         rtiAmb,
                                                         RTI::
                                                         ObjectHandle
                                                         theObject,
                                                         const RTI::
                                                         AttributeHandleSet
                                                         &
                                                         desiredAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::ObjectClassNotPublished,
           RTI::AttributeNotDefined,
           RTI::AttributeNotPublished,
           RTI::FederateOwnsAttributes,
           RTI::AttributeAlreadyBeingAcquired,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::AttributeHandleSet *
        (*funcptr_RTI__RTIambassador__attributeOwnershipReleaseResponse2)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &);

    static RTI::AttributeHandleSet *
        attributeOwnershipReleaseResponse(RTI::RTIambassador * rtiAmb,
                                          RTI::ObjectHandle theObject,
                                          const RTI::
                                          AttributeHandleSet &
                                          theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::FederateWasNotAskedToReleaseAttribute,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture2)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &);

    static void cancelNegotiatedAttributeOwnershipDivestiture(RTI::
                                                              RTIambassador
                                                              * rtiAmb,
                                                              RTI::
                                                              ObjectHandle
                                                              theObject,
                                                              const RTI::
                                                              AttributeHandleSet
                                                              &
                                                              theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::AttributeDivestitureWasNotRequested,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void
     (*funcptr_RTI__RTIambassador__cancelAttributeOwnershipAcquisition2)
     (RTI::RTIambassador *,
      RTI::ObjectHandle, const RTI::AttributeHandleSet &);

    static void cancelAttributeOwnershipAcquisition(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    ObjectHandle theObject,
                                                    const RTI::
                                                    AttributeHandleSet &
                                                    theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeAlreadyOwned,
           RTI::AttributeAcquisitionWasNotRequested,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__queryAttributeOwnership2) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  RTI::
                                                                  ObjectHandle,
                                                                  RTI::
                                                                  AttributeHandle);

    static void queryAttributeOwnership(RTI::RTIambassador * rtiAmb,
                                        RTI::ObjectHandle theObject,
                                        RTI::AttributeHandle theAttribute)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        Boolean(*funcptr_RTI__RTIambassador__isAttributeOwnedByFederate2)
     (RTI::RTIambassador *, RTI::ObjectHandle, RTI::AttributeHandle);

    static RTI::Boolean isAttributeOwnedByFederate(RTI::RTIambassador *
                                                   rtiAmb,
                                                   RTI::
                                                   ObjectHandle theObject,
                                                   RTI::
                                                   AttributeHandle
                                                   theAttribute)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__enableTimeRegulation2) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      const
                                                                      RTI::
                                                                      FedTime
                                                                      &,
                                                                      const
                                                                      RTI::
                                                                      FedTime
                                                                      &);

    static void enableTimeRegulation(RTI::RTIambassador * rtiAmb,
                                     const RTI::FedTime & theFederateTime,
                                     const RTI::FedTime & theLookahead)
     throw(RTI::TimeRegulationAlreadyEnabled,
           RTI::EnableTimeRegulationPending,
           RTI::TimeAdvanceAlreadyInProgress,
           RTI::InvalidFederationTime,
           RTI::InvalidLookahead,
           RTI::ConcurrentAccessAttempted,
           RTI::FederateNotExecutionMember,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__disableTimeRegulation0) (RTI::
                                                                RTIambassador
                                                                *);

    static void disableTimeRegulation(RTI::RTIambassador * rtiAmb)
     throw(RTI::TimeRegulationWasNotEnabled,
           RTI::ConcurrentAccessAttempted,
           RTI::FederateNotExecutionMember,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__enableTimeConstrained0) (RTI::
                                                                RTIambassador
                                                                *);

    static void enableTimeConstrained(RTI::RTIambassador * rtiAmb)
     throw(RTI::TimeConstrainedAlreadyEnabled,
           RTI::EnableTimeConstrainedPending,
           RTI::TimeAdvanceAlreadyInProgress,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__disableTimeConstrained0) (RTI::
                                                                 RTIambassador
                                                                 *);

    static void disableTimeConstrained(RTI::RTIambassador * rtiAmb)
     throw(RTI::TimeConstrainedWasNotEnabled,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__timeAdvanceRequest1) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    const
                                                                    RTI::
                                                                    FedTime
                                                                    &);

    static void timeAdvanceRequest(RTI::RTIambassador * rtiAmb,
                                   const RTI::FedTime & theTime)
     throw(RTI::InvalidFederationTime,
           RTI::FederationTimeAlreadyPassed,
           RTI::TimeAdvanceAlreadyInProgress,
           RTI::EnableTimeRegulationPending,
           RTI::EnableTimeConstrainedPending,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__timeAdvanceRequestAvailable1) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      const
                                                                      RTI::
                                                                      FedTime
                                                                      &);

    static void timeAdvanceRequestAvailable(RTI::RTIambassador * rtiAmb,
                                            const RTI::FedTime & theTime)
     throw(RTI::InvalidFederationTime,
           RTI::FederationTimeAlreadyPassed,
           RTI::TimeAdvanceAlreadyInProgress,
           RTI::EnableTimeRegulationPending,
           RTI::EnableTimeConstrainedPending,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__nextEventRequest1) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  const
                                                                  RTI::
                                                                  FedTime
                                                                  &);

    static void nextEventRequest(RTI::RTIambassador * rtiAmb,
                                 const RTI::FedTime & theTime)
     throw(RTI::InvalidFederationTime,
           RTI::FederationTimeAlreadyPassed,
           RTI::TimeAdvanceAlreadyInProgress,
           RTI::EnableTimeRegulationPending,
           RTI::EnableTimeConstrainedPending,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__nextEventRequestAvailable1) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    const
                                                                    RTI::
                                                                    FedTime
                                                                    &);

    static void nextEventRequestAvailable(RTI::RTIambassador * rtiAmb,
                                          const RTI::FedTime & theTime)
     throw(RTI::InvalidFederationTime,
           RTI::FederationTimeAlreadyPassed,
           RTI::TimeAdvanceAlreadyInProgress,
           RTI::EnableTimeRegulationPending,
           RTI::EnableTimeConstrainedPending,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__flushQueueRequest1) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   const
                                                                   RTI::
                                                                   FedTime
                                                                   &);

    static void flushQueueRequest(RTI::RTIambassador * rtiAmb,
                                  const RTI::FedTime & theTime)
     throw(RTI::InvalidFederationTime,
           RTI::FederationTimeAlreadyPassed,
           RTI::TimeAdvanceAlreadyInProgress,
           RTI::EnableTimeRegulationPending,
           RTI::EnableTimeConstrainedPending,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__enableAsynchronousDelivery0) (RTI::
                                                                     RTIambassador
                                                                     *);

    static void enableAsynchronousDelivery(RTI::RTIambassador * rtiAmb)
     throw(RTI::AsynchronousDeliveryAlreadyEnabled,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__disableAsynchronousDelivery0) (RTI::
                                                                      RTIambassador
                                                                      *);

    static void disableAsynchronousDelivery(RTI::RTIambassador * rtiAmb)
     throw(RTI::AsynchronousDeliveryAlreadyDisabled,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__queryLBTS1) (RTI::
                                                           RTIambassador *,
                                                           RTI::FedTime &);

    static void queryLBTS(RTI::RTIambassador * rtiAmb,
                          RTI::FedTime & theTime)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__queryFederateTime1) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   FedTime
                                                                   &);

    static void queryFederateTime(RTI::RTIambassador * rtiAmb,
                                  RTI::FedTime & theTime)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__queryMinNextEventTime1) (RTI::
                                                                RTIambassador
                                                                *,
                                                                RTI::
                                                                FedTime &);

    static void queryMinNextEventTime(RTI::RTIambassador * rtiAmb,
                                      RTI::FedTime & theTime)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__modifyLookahead1) (RTI::
                                                                 RTIambassador
                                                                 *,
                                                                 const
                                                                 RTI::
                                                                 FedTime
                                                                 &);

    static void modifyLookahead(RTI::RTIambassador * rtiAmb,
                                const RTI::FedTime & theLookahead)
     throw(RTI::InvalidLookahead,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__queryLookahead1) (RTI::
                                                                RTIambassador
                                                                *,
                                                                RTI::
                                                                FedTime &);

    static void queryLookahead(RTI::RTIambassador * rtiAmb,
                               RTI::FedTime & theTime)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__retract1) (RTI::
                                                         RTIambassador *,
                                                         RTI::
                                                         EventRetractionHandle);

    static void retract(RTI::RTIambassador * rtiAmb,
                        RTI::EventRetractionHandle theHandle)
     throw(RTI::InvalidRetractionHandle,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__changeAttributeOrderType3) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   ObjectHandle,
                                                                   const
                                                                   RTI::
                                                                   AttributeHandleSet
                                                                   &,
                                                                   RTI::
                                                                   OrderingHandle);

    static void changeAttributeOrderType(RTI::RTIambassador * rtiAmb,
                                         RTI::ObjectHandle theObject,
                                         const RTI::
                                         AttributeHandleSet &
                                         theAttributes,
                                         RTI::OrderingHandle theType)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::AttributeNotOwned,
           RTI::InvalidOrderingHandle,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__changeInteractionOrderType2) (RTI::
                                                                     RTIambassador
                                                                     *,
                                                                     RTI::
                                                                     InteractionClassHandle,
                                                                     RTI::
                                                                     OrderingHandle);

    static void changeInteractionOrderType(RTI::RTIambassador * rtiAmb,
                                           RTI::
                                           InteractionClassHandle theClass,
                                           RTI::OrderingHandle theType)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotPublished,
           RTI::InvalidOrderingHandle,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::Region *
        (*funcptr_RTI__RTIambassador__createRegion2) (RTI::RTIambassador *,
                                                      RTI::SpaceHandle,
                                                      RTI::ULong);

    static RTI::Region * createRegion(RTI::RTIambassador * rtiAmb,
                                      RTI::SpaceHandle theSpace,
                                      RTI::ULong numberOfExtents)
     throw(RTI::SpaceNotDefined,
           RTI::InvalidExtents,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__notifyAboutRegionModification1)
     (RTI::RTIambassador *, RTI::Region &);

    static void notifyAboutRegionModification(RTI::RTIambassador * rtiAmb,
                                              RTI::Region & theRegion)
     throw(RTI::RegionNotKnown,
           RTI::InvalidExtents,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static void (*funcptr_RTI__RTIambassador__deleteRegion1) (RTI::
                                                              RTIambassador
                                                              *,
                                                              RTI::
                                                              Region *);

    static void deleteRegion(RTI::RTIambassador * rtiAmb,
                             RTI::Region * theRegion)
     throw(RTI::RegionNotKnown,
           RTI::RegionInUse,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        ObjectHandle
        (*funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion5)
     (RTI::RTIambassador *,
      RTI::ObjectClassHandle,
      const char *, RTI::AttributeHandle *, RTI::Region **, RTI::ULong);

    static RTI::ObjectHandle registerObjectInstanceWithRegion(RTI::
                                                              RTIambassador
                                                              * rtiAmb,
                                                              RTI::
                                                              ObjectClassHandle
                                                              theClass,
                                                              const char
                                                              *theObject,
                                                              RTI::
                                                              AttributeHandle
                                                              theAttributes
                                                              [],
                                                              RTI::Region *
                                                              theRegions[],
                                                              RTI::
                                                              ULong
                                                              theNumberOfHandles)
     throw(RTI::ObjectClassNotDefined,
           RTI::ObjectClassNotPublished,
           RTI::AttributeNotDefined,
           RTI::AttributeNotPublished,
           RTI::RegionNotKnown,
           RTI::InvalidRegionContext,
           RTI::ObjectAlreadyRegistered,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        ObjectHandle
        (*funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion4)
     (RTI::RTIambassador *,
      RTI::ObjectClassHandle,
      RTI::AttributeHandle *, RTI::Region **, RTI::ULong);

    static RTI::ObjectHandle registerObjectInstanceWithRegion(RTI::
                                                              RTIambassador
                                                              * rtiAmb,
                                                              RTI::
                                                              ObjectClassHandle
                                                              theClass,
                                                              RTI::
                                                              AttributeHandle
                                                              theAttributes
                                                              [],
                                                              RTI::Region *
                                                              theRegions[],
                                                              RTI::
                                                              ULong
                                                              theNumberOfHandles)
     throw(RTI::ObjectClassNotDefined,
           RTI::ObjectClassNotPublished,
           RTI::AttributeNotDefined,
           RTI::AttributeNotPublished,
           RTI::RegionNotKnown,
           RTI::InvalidRegionContext,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__associateRegionForUpdates3) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    Region
                                                                    &,
                                                                    RTI::
                                                                    ObjectHandle,
                                                                    const
                                                                    RTI::
                                                                    AttributeHandleSet
                                                                    &);

    static void associateRegionForUpdates(RTI::RTIambassador * rtiAmb,
                                          RTI::Region & theRegion,
                                          RTI::ObjectHandle theObject,
                                          const RTI::
                                          AttributeHandleSet &
                                          theAttributes)
     throw(RTI::ObjectNotKnown,
           RTI::AttributeNotDefined,
           RTI::InvalidRegionContext,
           RTI::RegionNotKnown,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__unassociateRegionForUpdates2) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      RTI::
                                                                      Region
                                                                      &,
                                                                      RTI::
                                                                      ObjectHandle);

    static void unassociateRegionForUpdates(RTI::RTIambassador * rtiAmb,
                                            RTI::Region & theRegion,
                                            RTI::ObjectHandle theObject)
     throw(RTI::ObjectNotKnown,
           RTI::InvalidRegionContext,
           RTI::RegionNotKnown,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion4)
     (RTI::RTIambassador *,
      RTI::ObjectClassHandle,
      RTI::Region &, const RTI::AttributeHandleSet &, RTI::Boolean);

    static void subscribeObjectClassAttributesWithRegion(RTI::
                                                         RTIambassador *
                                                         rtiAmb,
                                                         RTI::
                                                         ObjectClassHandle
                                                         theClass,
                                                         RTI::
                                                         Region &
                                                         theRegion,
                                                         const RTI::
                                                         AttributeHandleSet
                                                         & attributeList,
                                                         RTI::
                                                         Boolean active)
     throw(RTI::ObjectClassNotDefined,
           RTI::AttributeNotDefined,
           RTI::RegionNotKnown,
           RTI::InvalidRegionContext,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__unsubscribeObjectClassWithRegion2)
     (RTI::RTIambassador *, RTI::ObjectClassHandle, RTI::Region &);

    static void unsubscribeObjectClassWithRegion(RTI::RTIambassador *
                                                 rtiAmb,
                                                 RTI::
                                                 ObjectClassHandle
                                                 theClass,
                                                 RTI::Region & theRegion)
     throw(RTI::ObjectClassNotDefined,
           RTI::RegionNotKnown,
           RTI::ObjectClassNotSubscribed,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void
     (*funcptr_RTI__RTIambassador__subscribeInteractionClassWithRegion3)
     (RTI::RTIambassador *,
      RTI::InteractionClassHandle, RTI::Region &, RTI::Boolean);

    static void subscribeInteractionClassWithRegion(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    InteractionClassHandle
                                                    theClass,
                                                    RTI::
                                                    Region & theRegion,
                                                    RTI::Boolean active)
     throw(RTI::InteractionClassNotDefined,
           RTI::RegionNotKnown,
           RTI::InvalidRegionContext,
           RTI::FederateLoggingServiceCalls,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void
     (*funcptr_RTI__RTIambassador__unsubscribeInteractionClassWithRegion2)
     (RTI::RTIambassador *, RTI::InteractionClassHandle, RTI::Region &);

    static void unsubscribeInteractionClassWithRegion(RTI::RTIambassador *
                                                      rtiAmb,
                                                      RTI::
                                                      InteractionClassHandle
                                                      theClass,
                                                      RTI::
                                                      Region & theRegion)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotSubscribed,
           RTI::RegionNotKnown,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        EventRetractionHandle
        (*funcptr_RTI__RTIambassador__sendInteractionWithRegion5) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   InteractionClassHandle,
                                                                   const
                                                                   RTI::
                                                                   ParameterHandleValuePairSet
                                                                   &,
                                                                   const
                                                                   RTI::
                                                                   FedTime
                                                                   &,
                                                                   const
                                                                   char *,
                                                                   const
                                                                   RTI::
                                                                   Region
                                                                   &);

    static RTI::EventRetractionHandle sendInteractionWithRegion(RTI::
                                                                RTIambassador
                                                                * rtiAmb,
                                                                RTI::
                                                                InteractionClassHandle
                                                                theInteraction,
                                                                const RTI::
                                                                ParameterHandleValuePairSet
                                                                &
                                                                theParameters,
                                                                const RTI::
                                                                FedTime &
                                                                theTime,
                                                                const char
                                                                *theTag,
                                                                const RTI::
                                                                Region &
                                                                theRegion)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotPublished,
           RTI::InteractionParameterNotDefined,
           RTI::InvalidFederationTime,
           RTI::RegionNotKnown,
           RTI::InvalidRegionContext,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__sendInteractionWithRegion4) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    InteractionClassHandle,
                                                                    const
                                                                    RTI::
                                                                    ParameterHandleValuePairSet
                                                                    &,
                                                                    const
                                                                    char *,
                                                                    const
                                                                    RTI::
                                                                    Region
                                                                    &);

    static void sendInteractionWithRegion(RTI::RTIambassador * rtiAmb,
                                          RTI::
                                          InteractionClassHandle
                                          theInteraction,
                                          const RTI::
                                          ParameterHandleValuePairSet &
                                          theParameters,
                                          const char *theTag,
                                          const RTI::Region & theRegion)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionClassNotPublished,
           RTI::InteractionParameterNotDefined,
           RTI::RegionNotKnown,
           RTI::InvalidRegionContext,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion3)
     (RTI::RTIambassador *,
      RTI::ObjectClassHandle,
      const RTI::AttributeHandleSet &, const RTI::Region &);

    static void requestClassAttributeValueUpdateWithRegion(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           RTI::
                                                           ObjectClassHandle
                                                           theClass,
                                                           const RTI::
                                                           AttributeHandleSet
                                                           & theAttributes,
                                                           const RTI::
                                                           Region &
                                                           theRegion)
     throw(RTI::ObjectClassNotDefined,
           RTI::AttributeNotDefined,
           RTI::RegionNotKnown,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::
        ObjectClassHandle
        (*funcptr_RTI__RTIambassador__getObjectClassHandle1)
     (RTI::RTIambassador *, const char *);

    static RTI::ObjectClassHandle getObjectClassHandle(RTI::RTIambassador *
                                                       rtiAmb,
                                                       const char *theName)
     throw(RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char *(*funcptr_RTI__RTIambassador__getObjectClassName1) (RTI::
                                                                     RTIambassador
                                                                     *,
                                                                     RTI::
                                                                     ObjectClassHandle);

    static char *getObjectClassName(RTI::RTIambassador * rtiAmb,
                                    RTI::ObjectClassHandle theHandle)
     throw(RTI::ObjectClassNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        AttributeHandle(*funcptr_RTI__RTIambassador__getAttributeHandle2)
     (RTI::RTIambassador *, const char *, RTI::ObjectClassHandle);

    static RTI::AttributeHandle getAttributeHandle(RTI::RTIambassador *
                                                   rtiAmb,
                                                   const char *theName,
                                                   RTI::
                                                   ObjectClassHandle
                                                   whichClass)
     throw(RTI::ObjectClassNotDefined,
           RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char *(*funcptr_RTI__RTIambassador__getAttributeName2) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   AttributeHandle,
                                                                   RTI::
                                                                   ObjectClassHandle);

    static char *getAttributeName(RTI::RTIambassador * rtiAmb,
                                  RTI::AttributeHandle theHandle,
                                  RTI::ObjectClassHandle whichClass)
     throw(RTI::ObjectClassNotDefined,
           RTI::AttributeNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        InteractionClassHandle
        (*funcptr_RTI__RTIambassador__getInteractionClassHandle1) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   const
                                                                   char *);

    static RTI::InteractionClassHandle getInteractionClassHandle(RTI::
                                                                 RTIambassador
                                                                 * rtiAmb,
                                                                 const char
                                                                 *theName)
     throw(RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char
    *(*funcptr_RTI__RTIambassador__getInteractionClassName1) (RTI::
                                                              RTIambassador
                                                              *,
                                                              RTI::
                                                              InteractionClassHandle);

    static char *getInteractionClassName(RTI::RTIambassador * rtiAmb,
                                         RTI::
                                         InteractionClassHandle theHandle)
     throw(RTI::InteractionClassNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        ParameterHandle(*funcptr_RTI__RTIambassador__getParameterHandle2)
     (RTI::RTIambassador *, const char *, RTI::InteractionClassHandle);

    static RTI::ParameterHandle getParameterHandle(RTI::RTIambassador *
                                                   rtiAmb,
                                                   const char *theName,
                                                   RTI::
                                                   InteractionClassHandle
                                                   whichClass)
     throw(RTI::InteractionClassNotDefined,
           RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char *(*funcptr_RTI__RTIambassador__getParameterName2) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   ParameterHandle,
                                                                   RTI::
                                                                   InteractionClassHandle);

    static char *getParameterName(RTI::RTIambassador * rtiAmb,
                                  RTI::ParameterHandle theHandle,
                                  RTI::InteractionClassHandle whichClass)
     throw(RTI::InteractionClassNotDefined,
           RTI::InteractionParameterNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        ObjectHandle(*funcptr_RTI__RTIambassador__getObjectInstanceHandle1)
     (RTI::RTIambassador *, const char *);

    static RTI::ObjectHandle getObjectInstanceHandle(RTI::RTIambassador *
                                                     rtiAmb,
                                                     const char *theName)
     throw(RTI::ObjectNotKnown,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char
    *(*funcptr_RTI__RTIambassador__getObjectInstanceName1) (RTI::
                                                            RTIambassador
                                                            *,
                                                            RTI::
                                                            ObjectHandle);

    static char *getObjectInstanceName(RTI::RTIambassador * rtiAmb,
                                       RTI::ObjectHandle theHandle)
     throw(RTI::ObjectNotKnown,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        SpaceHandle(*funcptr_RTI__RTIambassador__getRoutingSpaceHandle1)
     (RTI::RTIambassador *, const char *);

    static RTI::SpaceHandle getRoutingSpaceHandle(RTI::RTIambassador *
                                                  rtiAmb,
                                                  const char *theName)
     throw(RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char *(*funcptr_RTI__RTIambassador__getRoutingSpaceName1) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      RTI::
                                                                      SpaceHandle);

    static char *getRoutingSpaceName(RTI::RTIambassador * rtiAmb,
                                     RTI::SpaceHandle theHandle)
     throw(RTI::SpaceNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        DimensionHandle(*funcptr_RTI__RTIambassador__getDimensionHandle2)
     (RTI::RTIambassador *, const char *, RTI::SpaceHandle);

    static RTI::DimensionHandle getDimensionHandle(RTI::RTIambassador *
                                                   rtiAmb,
                                                   const char *theName,
                                                   RTI::
                                                   SpaceHandle whichSpace)
     throw(RTI::SpaceNotDefined,
           RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char *(*funcptr_RTI__RTIambassador__getDimensionName2) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   DimensionHandle,
                                                                   RTI::
                                                                   SpaceHandle);

    static char *getDimensionName(RTI::RTIambassador * rtiAmb,
                                  RTI::DimensionHandle theHandle,
                                  RTI::SpaceHandle whichSpace)
     throw(RTI::SpaceNotDefined,
           RTI::DimensionNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        SpaceHandle
        (*funcptr_RTI__RTIambassador__getAttributeRoutingSpaceHandle2)
     (RTI::RTIambassador *, RTI::AttributeHandle, RTI::ObjectClassHandle);

    static RTI::SpaceHandle getAttributeRoutingSpaceHandle(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           RTI::
                                                           AttributeHandle
                                                           theHandle,
                                                           RTI::
                                                           ObjectClassHandle
                                                           whichClass)
     throw(RTI::ObjectClassNotDefined,
           RTI::AttributeNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        ObjectClassHandle(*funcptr_RTI__RTIambassador__getObjectClass1)
     (RTI::RTIambassador *, RTI::ObjectHandle);

    static RTI::ObjectClassHandle getObjectClass(RTI::RTIambassador *
                                                 rtiAmb,
                                                 RTI::
                                                 ObjectHandle theObject)
     throw(RTI::ObjectNotKnown,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        SpaceHandle
        (*funcptr_RTI__RTIambassador__getInteractionRoutingSpaceHandle1)
     (RTI::RTIambassador *, RTI::InteractionClassHandle);

    static RTI::SpaceHandle getInteractionRoutingSpaceHandle(RTI::
                                                             RTIambassador
                                                             * rtiAmb,
                                                             RTI::
                                                             InteractionClassHandle
                                                             theHandle)
     throw(RTI::InteractionClassNotDefined,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        TransportationHandle
        (*funcptr_RTI__RTIambassador__getTransportationHandle1) (RTI::
                                                                 RTIambassador
                                                                 *,
                                                                 const char
                                                                 *);

    static RTI::TransportationHandle getTransportationHandle(RTI::
                                                             RTIambassador
                                                             * rtiAmb,
                                                             const char
                                                             *theName)
     throw(RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char
    *(*funcptr_RTI__RTIambassador__getTransportationName1) (RTI::
                                                            RTIambassador
                                                            *,
                                                            RTI::
                                                            TransportationHandle);

    static char *getTransportationName(RTI::RTIambassador * rtiAmb,
                                       RTI::TransportationHandle theHandle)
     throw(RTI::InvalidTransportationHandle,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::
        OrderingHandle(*funcptr_RTI__RTIambassador__getOrderingHandle1)
     (RTI::RTIambassador *, const char *);

    static RTI::OrderingHandle getOrderingHandle(RTI::RTIambassador *
                                                 rtiAmb,
                                                 const char *theName)
     throw(RTI::NameNotFound,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static char *(*funcptr_RTI__RTIambassador__getOrderingName1) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  RTI::
                                                                  OrderingHandle);

    static char *getOrderingName(RTI::RTIambassador * rtiAmb,
                                 RTI::OrderingHandle theHandle)
     throw(RTI::InvalidOrderingHandle,
           RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::RegionToken(*funcptr_RTI__RTIambassador__getRegionToken1) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  RTI::
                                                                  Region*);

    static RTI::RegionToken getRegionToken(RTI::RTIambassador * rtiAmb, 
                                           RTI::Region *)
        throw(RTI::FederateNotExecutionMember,
              RTI::ConcurrentAccessAttempted,
              RTI::RegionNotKnown,
              RTI::RTIinternalError);

    static char *(*funcptr_RTI__RTIambassador__getRegion1) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  RTI::
                                                                  RegionToken);
    
    static RTI::Region *getRegion(RTI::RTIambassador * rtiAmb,
                                  RTI::RegionToken)
        throw(
            RTI::FederateNotExecutionMember,
            RTI::ConcurrentAccessAttempted,
            RTI::RegionNotKnown,
            RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void enableClassRelevanceAdvisorySwitch(RTI::RTIambassador *
                                                   rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void
     (*funcptr_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void disableClassRelevanceAdvisorySwitch(RTI::RTIambassador *
                                                    rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void enableAttributeRelevanceAdvisorySwitch(RTI::RTIambassador *
                                                       rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void disableAttributeRelevanceAdvisorySwitch(RTI::
                                                        RTIambassador *
                                                        rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
    void (*funcptr_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void enableAttributeScopeAdvisorySwitch(RTI::RTIambassador *
                                                   rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void
     (*funcptr_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void disableAttributeScopeAdvisorySwitch(RTI::RTIambassador *
                                                    rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void enableInteractionRelevanceAdvisorySwitch(RTI::
                                                         RTIambassador *
                                                         rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static
        void

     (*funcptr_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch0)
     (RTI::RTIambassador *);

    static void disableInteractionRelevanceAdvisorySwitch(RTI::
                                                          RTIambassador *
                                                          rtiAmb)
     throw(RTI::FederateNotExecutionMember,
           RTI::ConcurrentAccessAttempted,
           RTI::SaveInProgress,
           RTI::RestoreInProgress, RTI::RTIinternalError);

    static RTI::Boolean(*funcptr_RTI__RTIambassador__tick0) (RTI::
                                                             RTIambassador
                                                             *);

    static RTI::Boolean tick(RTI::RTIambassador * rtiAmb)
     throw(RTI::SpecifiedSaveLabelDoesNotExist,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

    static RTI::Boolean(*funcptr_RTI__RTIambassador__tick2) (RTI::
                                                             RTIambassador
                                                             *,
                                                             RTI::TickTime,
                                                             RTI::
                                                             TickTime);

    static RTI::Boolean tick(RTI::RTIambassador * rtiAmb,
                             RTI::TickTime minimum, RTI::TickTime maximum)
     throw(RTI::SpecifiedSaveLabelDoesNotExist,
           RTI::ConcurrentAccessAttempted, RTI::RTIinternalError);

};

#endif
