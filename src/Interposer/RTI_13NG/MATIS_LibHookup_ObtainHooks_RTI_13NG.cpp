// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LibHookup_ObtainHooks_RTI_13NG.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.2 $






// Automatically generated.  Edit at own risk!

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__createFederationExecution2 =
(void (*)(RTI::RTIambassador *, const char *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__createFederationExecution2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__destroyFederationExecution1 =
(void (*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__destroyFederationExecution1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__joinFederationExecution3 =
(RTI::
 FederateHandle(*)(RTI::RTIambassador *, const char *, const char *,
                   RTI::FederateAmbassadorPtr)) 
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__joinFederationExecution3");

MATIS_RTIAmbassador::
    funcptr_RTI__RTIambassador__resignFederationExecution1 =
    (void (*)(RTI::RTIambassador *, RTI::ResignAction))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__resignFederationExecution1");

MATIS_RTIAmbassador::
    funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint2 =
    (void (*)(RTI::RTIambassador *, const char *, const char *))
    MATIS_LibHookup::
    getFunctionPointer
    ("RTI__RTIambassador__registerFederationSynchronizationPoint2");

MATIS_RTIAmbassador::
    funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint3 =
    (void (*)
     (RTI::RTIambassador *, const char *, const char *,
      const RTI::FederateHandleSet &))
    MATIS_LibHookup::
    getFunctionPointer
    ("RTI__RTIambassador__registerFederationSynchronizationPoint3");

MATIS_RTIAmbassador::
    funcptr_RTI__RTIambassador__synchronizationPointAchieved1 =
    (void (*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__synchronizationPointAchieved1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__requestFederationSave2 =
    (void (*)(RTI::RTIambassador *, const char *, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__requestFederationSave2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__requestFederationSave1 =
    (void (*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__requestFederationSave1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__federateSaveBegun0 =
    (void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__federateSaveBegun0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__federateSaveComplete0 =
    (void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__federateSaveComplete0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__federateSaveNotComplete0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__federateSaveNotComplete0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__requestFederationRestore1 =
(void (*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__requestFederationRestore1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__federateRestoreComplete0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__federateRestoreComplete0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__federateRestoreNotComplete0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__federateRestoreNotComplete0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__publishObjectClass2 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectClassHandle,
  const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__publishObjectClass2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__unpublishObjectClass1 =
(void (*)(RTI::RTIambassador *, RTI::ObjectClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__unpublishObjectClass1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__publishInteractionClass1 =
(void (*)(RTI::RTIambassador *, RTI::InteractionClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__publishInteractionClass1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__unpublishInteractionClass1 =
(void (*)(RTI::RTIambassador *, RTI::InteractionClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__unpublishInteractionClass1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__subscribeObjectClassAttributes3 = (void (*)
                                                               (RTI::
                                                                RTIambassador
                                                                *,
                                                                RTI::
                                                                ObjectClassHandle,
                                                                const
                                                                RTI::
                                                                AttributeHandleSet
                                                                &,
                                                                RTI::
                                                                Boolean))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__subscribeObjectClassAttributes3");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__unsubscribeObjectClass1 =
(void (*)(RTI::RTIambassador *, RTI::ObjectClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__unsubscribeObjectClass1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__subscribeInteractionClass2 = (void (*)
                                                          (RTI::
                                                           RTIambassador
                                                           *,
                                                           RTI::
                                                           InteractionClassHandle,
                                                           RTI::
                                                           Boolean))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__subscribeInteractionClass2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__unsubscribeInteractionClass1 =
(void (*)(RTI::RTIambassador *, RTI::InteractionClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__unsubscribeInteractionClass1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__registerObjectInstance2 =
(RTI::
 ObjectHandle(*)(RTI::RTIambassador *, RTI::ObjectClassHandle,
                 const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__registerObjectInstance2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__registerObjectInstance1 =
(RTI::ObjectHandle(*)(RTI::RTIambassador *, RTI::ObjectClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__registerObjectInstance1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__updateAttributeValues4 =
(RTI::
 EventRetractionHandle(*)(RTI::RTIambassador *, RTI::ObjectHandle,
                          const RTI::AttributeHandleValuePairSet &,
                          const RTI::FedTime &, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__updateAttributeValues4");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__updateAttributeValues3 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectHandle,
  const RTI::AttributeHandleValuePairSet &, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__updateAttributeValues3");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__sendInteraction4 =
(RTI::
 EventRetractionHandle(*)(RTI::RTIambassador *,
                          RTI::InteractionClassHandle,
                          const RTI::ParameterHandleValuePairSet &,
                          const RTI::FedTime &, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__sendInteraction4");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__sendInteraction3 =
(void (*)
 (RTI::RTIambassador *, RTI::InteractionClassHandle,
  const RTI::ParameterHandleValuePairSet &, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__sendInteraction3");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__deleteObjectInstance3 =
(RTI::
 EventRetractionHandle(*)(RTI::RTIambassador *, RTI::ObjectHandle,
                          const RTI::FedTime &, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__deleteObjectInstance3");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__deleteObjectInstance2 =
(void (*)(RTI::RTIambassador *, RTI::ObjectHandle, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__deleteObjectInstance2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__localDeleteObjectInstance1 =
(void (*)(RTI::RTIambassador *, RTI::ObjectHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__localDeleteObjectInstance1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__changeAttributeTransportationType3 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectHandle,
  const RTI::AttributeHandleSet &, RTI::TransportationHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__changeAttributeTransportationType3");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__changeInteractionTransportationType2 =
(void (*)
 (RTI::RTIambassador *, RTI::InteractionClassHandle,
  RTI::TransportationHandle))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__changeInteractionTransportationType2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__requestObjectAttributeValueUpdate2 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectHandle,
  const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__requestObjectAttributeValueUpdate2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__requestClassAttributeValueUpdate2 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectClassHandle,
  const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__requestClassAttributeValueUpdate2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture2
= (void (*)
   (RTI::RTIambassador *, RTI::ObjectHandle,
    const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture3 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectHandle,
  const RTI::AttributeHandleSet &, const char *))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture3");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__attributeOwnershipAcquisition3 = (void (*)
                                                              (RTI::
                                                               RTIambassador
                                                               *,
                                                               RTI::
                                                               ObjectHandle,
                                                               const
                                                               RTI::
                                                               AttributeHandleSet
                                                               &,
                                                               const
                                                               char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__attributeOwnershipAcquisition3");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable2 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectHandle,
  const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__attributeOwnershipReleaseResponse2 =
(RTI::AttributeHandleSet *
 (*)(RTI::RTIambassador *, RTI::ObjectHandle,
     const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__attributeOwnershipReleaseResponse2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture2
= (void (*)
   (RTI::RTIambassador *, RTI::ObjectHandle,
    const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__cancelAttributeOwnershipAcquisition2 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectHandle,
  const RTI::AttributeHandleSet &))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__cancelAttributeOwnershipAcquisition2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__queryAttributeOwnership2 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectHandle, RTI::AttributeHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__queryAttributeOwnership2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__isAttributeOwnedByFederate2 =
(RTI::
 Boolean(*)(RTI::RTIambassador *, RTI::ObjectHandle,
            RTI::AttributeHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__isAttributeOwnedByFederate2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__enableTimeRegulation2 =
(void (*)
 (RTI::RTIambassador *, const RTI::FedTime &, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__enableTimeRegulation2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__disableTimeRegulation0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__disableTimeRegulation0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__enableTimeConstrained0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__enableTimeConstrained0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__disableTimeConstrained0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__disableTimeConstrained0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__timeAdvanceRequest1 =
(void (*)(RTI::RTIambassador *, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__timeAdvanceRequest1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__timeAdvanceRequestAvailable1 =
(void (*)(RTI::RTIambassador *, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__timeAdvanceRequestAvailable1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__nextEventRequest1 =
(void (*)(RTI::RTIambassador *, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__nextEventRequest1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__nextEventRequestAvailable1 =
(void (*)(RTI::RTIambassador *, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__nextEventRequestAvailable1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__flushQueueRequest1 =
(void (*)(RTI::RTIambassador *, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__flushQueueRequest1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__enableAsynchronousDelivery0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__enableAsynchronousDelivery0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__disableAsynchronousDelivery0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__disableAsynchronousDelivery0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__queryLBTS1 =
(void (*)(RTI::RTIambassador *, RTI::FedTime &))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__queryLBTS1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__queryFederateTime1 =
(void (*)(RTI::RTIambassador *, RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__queryFederateTime1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__queryMinNextEventTime1 =
(void (*)(RTI::RTIambassador *, RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__queryMinNextEventTime1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__modifyLookahead1 =
(void (*)(RTI::RTIambassador *, const RTI::FedTime &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__modifyLookahead1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__queryLookahead1 =
(void (*)(RTI::RTIambassador *, RTI::FedTime &))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__queryLookahead1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__retract1 =
(void (*)(RTI::RTIambassador *, RTI::EventRetractionHandle))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__retract1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__changeAttributeOrderType3 = (void (*)
                                                         (RTI::
                                                          RTIambassador
                                                          *,
                                                          RTI::
                                                          ObjectHandle,
                                                          const RTI::
                                                          AttributeHandleSet
                                                          &,
                                                          RTI::
                                                          OrderingHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__changeAttributeOrderType3");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__changeInteractionOrderType2 = (void (*)
                                                           (RTI::
                                                            RTIambassador
                                                            *,
                                                            RTI::
                                                            InteractionClassHandle,
                                                            RTI::
                                                            OrderingHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__changeInteractionOrderType2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__createRegion2 =
(RTI::Region * (*)(RTI::RTIambassador *, RTI::SpaceHandle, RTI::ULong))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__createRegion2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__notifyAboutRegionModification1 =
(void (*)(RTI::RTIambassador *, RTI::Region &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__notifyAboutRegionModification1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__deleteRegion1 =
(void (*)(RTI::RTIambassador *, RTI::Region *))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__deleteRegion1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion5 =
(RTI::
 ObjectHandle(*)(RTI::RTIambassador *, RTI::ObjectClassHandle,
                 const char *, RTI::AttributeHandle *, RTI::Region **,
                 RTI::ULong))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__registerObjectInstanceWithRegion5");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion4 =
(RTI::
 ObjectHandle(*)(RTI::RTIambassador *, RTI::ObjectClassHandle,
                 RTI::AttributeHandle *, RTI::Region **, RTI::ULong))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__registerObjectInstanceWithRegion4");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__associateRegionForUpdates3 = (void (*)
                                                          (RTI::
                                                           RTIambassador
                                                           *,
                                                           RTI::
                                                           Region &,
                                                           RTI::
                                                           ObjectHandle,
                                                           const RTI::
                                                           AttributeHandleSet
                                                           &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__associateRegionForUpdates3");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__unassociateRegionForUpdates2 =
(void (*)(RTI::RTIambassador *, RTI::Region &, RTI::ObjectHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__unassociateRegionForUpdates2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion4 =
(void (*)
 (RTI::RTIambassador *, RTI::ObjectClassHandle, RTI::Region &,
  const RTI::AttributeHandleSet &, RTI::Boolean))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__subscribeObjectClassAttributesWithRegion4");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__unsubscribeObjectClassWithRegion2 =
(void (*)(RTI::RTIambassador *, RTI::ObjectClassHandle, RTI::Region &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__unsubscribeObjectClassWithRegion2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__subscribeInteractionClassWithRegion3 =
(void (*)
 (RTI::RTIambassador *, RTI::InteractionClassHandle, RTI::Region &,
  RTI::Boolean))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__subscribeInteractionClassWithRegion3");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__unsubscribeInteractionClassWithRegion2 =
(void (*)
 (RTI::RTIambassador *, RTI::InteractionClassHandle, RTI::Region &))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__unsubscribeInteractionClassWithRegion2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__sendInteractionWithRegion5 =
(RTI::
 EventRetractionHandle(*)(RTI::RTIambassador *,
                          RTI::InteractionClassHandle,
                          const RTI::ParameterHandleValuePairSet &,
                          const RTI::FedTime &, const char *,
                          const RTI::Region &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__sendInteractionWithRegion5");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__sendInteractionWithRegion4 = (void (*)
                                                          (RTI::
                                                           RTIambassador
                                                           *,
                                                           RTI::
                                                           InteractionClassHandle,
                                                           const RTI::
                                                           ParameterHandleValuePairSet
                                                           &,
                                                           const char
                                                           *,
                                                           const RTI::
                                                           Region &))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__sendInteractionWithRegion4");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion3
= (void (*)
   (RTI::RTIambassador *, RTI::ObjectClassHandle,
    const RTI::AttributeHandleSet &, const RTI::Region &))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion3");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getObjectClassHandle1 =
(RTI::ObjectClassHandle(*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getObjectClassHandle1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getObjectClassName1 =
(char *(*)(RTI::RTIambassador *, RTI::ObjectClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getObjectClassName1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getAttributeHandle2 =
(RTI::
 AttributeHandle(*)(RTI::RTIambassador *, const char *,
                    RTI::ObjectClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getAttributeHandle2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getAttributeName2 =
(char
 *(*)(RTI::RTIambassador *, RTI::AttributeHandle,
      RTI::ObjectClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getAttributeName2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__getInteractionClassHandle1 =
(RTI::InteractionClassHandle(*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getInteractionClassHandle1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getInteractionClassName1 =
(char *(*)(RTI::RTIambassador *, RTI::InteractionClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getInteractionClassName1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getParameterHandle2 =
(RTI::
 ParameterHandle(*)(RTI::RTIambassador *, const char *,
                    RTI::InteractionClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getParameterHandle2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getParameterName2 =
(char
 *(*)(RTI::RTIambassador *, RTI::ParameterHandle,
      RTI::InteractionClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getParameterName2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getObjectInstanceHandle1 =
(RTI::ObjectHandle(*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getObjectInstanceHandle1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getObjectInstanceName1 =
(char *(*)(RTI::RTIambassador *, RTI::ObjectHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getObjectInstanceName1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getRoutingSpaceHandle1 =
(RTI::SpaceHandle(*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getRoutingSpaceHandle1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getRoutingSpaceName1 =
(char *(*)(RTI::RTIambassador *, RTI::SpaceHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getRoutingSpaceName1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getDimensionHandle2 =
(RTI::
 DimensionHandle(*)(RTI::RTIambassador *, const char *,
                    RTI::SpaceHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getDimensionHandle2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getDimensionName2 =
(char
 *(*)(RTI::RTIambassador *, RTI::DimensionHandle, RTI::SpaceHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getDimensionName2");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__getAttributeRoutingSpaceHandle2 =
(RTI::
 SpaceHandle(*)(RTI::RTIambassador *, RTI::AttributeHandle,
                RTI::ObjectClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getAttributeRoutingSpaceHandle2");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getObjectClass1 =
(RTI::ObjectClassHandle(*)(RTI::RTIambassador *, RTI::ObjectHandle))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__getObjectClass1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__getInteractionRoutingSpaceHandle1 =
(RTI::
 SpaceHandle(*)(RTI::RTIambassador *, RTI::InteractionClassHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getInteractionRoutingSpaceHandle1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getTransportationHandle1 =
(RTI::TransportationHandle(*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getTransportationHandle1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getTransportationName1 =
(char *(*)(RTI::RTIambassador *, RTI::TransportationHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getTransportationName1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getOrderingHandle1 =
(RTI::OrderingHandle(*)(RTI::RTIambassador *, const char *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getOrderingHandle1");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__getOrderingName1 =
(char *(*)(RTI::RTIambassador *, RTI::OrderingHandle))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__getOrderingName1");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__enableClassRelevanceAdvisorySwitch0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__disableClassRelevanceAdvisorySwitch0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer("RTI__RTIambassador__enableAttributeScopeAdvisorySwitch0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__disableAttributeScopeAdvisorySwitch0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch0 =
(void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch0");

MATIS_RTIAmbassador::
funcptr_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch0
= (void (*)(RTI::RTIambassador *))
    MATIS_LibHookup::
getFunctionPointer
("RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__tick0 =
(RTI::Boolean(*)(RTI::RTIambassador *))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__tick0");

MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__tick2 =
(RTI::Boolean(*)(RTI::RTIambassador *, RTI::TickTime, RTI::TickTime))
    MATIS_LibHookup::getFunctionPointer("RTI__RTIambassador__tick2");
