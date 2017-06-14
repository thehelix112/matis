// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LibHookup_HookInit_RTI_13NG.cpp,v $
// CVS $Date: 2005/11/22 07:10:45 $
// CVS $Revision: 1.2 $





void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__createFederationExecution2) (RTI::
                                                               RTIambassador
                                                               *,
                                                               const char
                                                               *,
                                                               const char
                                                               *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__destroyFederationExecution1) (RTI::
                                                                RTIambassador
                                                                *,
                                                                const char
                                                                *) = NULL;

RTI::FederateHandle(*MATIS_RTIAmbassador::
                    funcptr_RTI__RTIambassador__joinFederationExecution3)
    (RTI::RTIambassador *, const char *, const char *,
     RTI::FederateAmbassadorPtr) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__resignFederationExecution1) (RTI::
                                                               RTIambassador
                                                               *,
                                                               RTI::
                                                               ResignAction)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint2)
    (RTI::RTIambassador *, const char *, const char *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint3)
    (RTI::RTIambassador *,
     const char *, const char *, const RTI::FederateHandleSet &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__synchronizationPointAchieved1) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  const
                                                                  char *) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__requestFederationSave2) (RTI::
                                                           RTIambassador *,
                                                           const char *,
                                                           const RTI::
                                                           FedTime &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__requestFederationSave1) (RTI::
                                                           RTIambassador *,
                                                           const char *) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__federateSaveBegun0) (RTI::
                                                       RTIambassador *) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__federateSaveComplete0) (RTI::
                                                          RTIambassador *)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__federateSaveNotComplete0) (RTI::
                                                             RTIambassador
                                                             *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__requestFederationRestore1) (RTI::
                                                              RTIambassador
                                                              *,
                                                              const char *)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__federateRestoreComplete0) (RTI::
                                                             RTIambassador
                                                             *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__federateRestoreNotComplete0) (RTI::
                                                                RTIambassador
                                                                *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__publishObjectClass2) (RTI::
                                                        RTIambassador *,
                                                        RTI::
                                                        ObjectClassHandle,
                                                        const RTI::
                                                        AttributeHandleSet
                                                        &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unpublishObjectClass1) (RTI::
                                                          RTIambassador *,
                                                          RTI::
                                                          ObjectClassHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__publishInteractionClass1) (RTI::
                                                             RTIambassador
                                                             *,
                                                             RTI::
                                                             InteractionClassHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unpublishInteractionClass1) (RTI::
                                                               RTIambassador
                                                               *,
                                                               RTI::
                                                               InteractionClassHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__subscribeObjectClassAttributes3) (RTI::
                                                                    RTIambassador
                                                                    *,
                                                                    RTI::
                                                                    ObjectClassHandle,
                                                                    const
                                                                    RTI::
                                                                    AttributeHandleSet
                                                                    &,
                                                                    RTI::
                                                                    Boolean)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unsubscribeObjectClass1) (RTI::
                                                            RTIambassador
                                                            *,
                                                            RTI::
                                                            ObjectClassHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__subscribeInteractionClass2) (RTI::
                                                               RTIambassador
                                                               *,
                                                               RTI::
                                                               InteractionClassHandle,
                                                               RTI::
                                                               Boolean) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unsubscribeInteractionClass1) (RTI::
                                                                 RTIambassador
                                                                 *,
                                                                 RTI::
                                                                 InteractionClassHandle)
    = NULL;

RTI::ObjectHandle(*MATIS_RTIAmbassador::
                  funcptr_RTI__RTIambassador__registerObjectInstance2)
    (RTI::RTIambassador *, RTI::ObjectClassHandle, const char *) = NULL;

RTI::ObjectHandle(*MATIS_RTIAmbassador::
                  funcptr_RTI__RTIambassador__registerObjectInstance1)
    (RTI::RTIambassador *, RTI::ObjectClassHandle) = NULL;

RTI::EventRetractionHandle(*MATIS_RTIAmbassador::
                           funcptr_RTI__RTIambassador__updateAttributeValues4)
    (RTI::RTIambassador *, RTI::ObjectHandle,
     const RTI::AttributeHandleValuePairSet &, const RTI::FedTime &,
     const char *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__updateAttributeValues3) (RTI::
                                                           RTIambassador *,
                                                           RTI::
                                                           ObjectHandle,
                                                           const RTI::
                                                           AttributeHandleValuePairSet
                                                           &,
                                                           const char *) =
NULL;

RTI::EventRetractionHandle(*MATIS_RTIAmbassador::
                           funcptr_RTI__RTIambassador__sendInteraction4)
    (RTI::RTIambassador *, RTI::InteractionClassHandle,
     const RTI::ParameterHandleValuePairSet &, const RTI::FedTime &,
     const char *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__sendInteraction3) (RTI::RTIambassador *,
                                                     RTI::
                                                     InteractionClassHandle,
                                                     const RTI::
                                                     ParameterHandleValuePairSet
                                                     &,
                                                     const char *) = NULL;

RTI::EventRetractionHandle(*MATIS_RTIAmbassador::
                           funcptr_RTI__RTIambassador__deleteObjectInstance3)
    (RTI::RTIambassador *, RTI::ObjectHandle, const RTI::FedTime &,
     const char *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__deleteObjectInstance2) (RTI::
                                                          RTIambassador *,
                                                          RTI::
                                                          ObjectHandle,
                                                          const char *) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__localDeleteObjectInstance1) (RTI::
                                                               RTIambassador
                                                               *,
                                                               RTI::
                                                               ObjectHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__changeAttributeTransportationType3)
    (RTI::RTIambassador *,
     RTI::ObjectHandle,
     const RTI::AttributeHandleSet &, RTI::TransportationHandle) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__changeInteractionTransportationType2)
    (RTI::RTIambassador *,
     RTI::InteractionClassHandle, RTI::TransportationHandle) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__requestObjectAttributeValueUpdate2)
    (RTI::RTIambassador *,
     RTI::ObjectHandle, const RTI::AttributeHandleSet &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__requestClassAttributeValueUpdate2) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      RTI::
                                                                      ObjectClassHandle,
                                                                      const
                                                                      RTI::
                                                                      AttributeHandleSet
                                                                      &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture2)
    (RTI::RTIambassador *,
     RTI::ObjectHandle, const RTI::AttributeHandleSet &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture3)
    (RTI::RTIambassador *,
     RTI::ObjectHandle, const RTI::AttributeHandleSet &, const char *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__attributeOwnershipAcquisition3) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   ObjectHandle,
                                                                   const
                                                                   RTI::
                                                                   AttributeHandleSet
                                                                   &,
                                                                   const
                                                                   char *)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable2)
    (RTI::RTIambassador *,
     RTI::ObjectHandle, const RTI::AttributeHandleSet &) = NULL;

RTI::AttributeHandleSet *
(*MATIS_RTIAmbassador::
 funcptr_RTI__RTIambassador__attributeOwnershipReleaseResponse2) (RTI::
                                                                  RTIambassador
                                                                  *,
                                                                  RTI::
                                                                  ObjectHandle,
                                                                  const
                                                                  RTI::
                                                                  AttributeHandleSet
                                                                  &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture2)
    (RTI::RTIambassador *,
     RTI::ObjectHandle, const RTI::AttributeHandleSet &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__cancelAttributeOwnershipAcquisition2)
    (RTI::RTIambassador *,
     RTI::ObjectHandle, const RTI::AttributeHandleSet &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__queryAttributeOwnership2) (RTI::
                                                             RTIambassador
                                                             *,
                                                             RTI::
                                                             ObjectHandle,
                                                             RTI::
                                                             AttributeHandle)
    = NULL;

RTI::Boolean(*MATIS_RTIAmbassador::
             funcptr_RTI__RTIambassador__isAttributeOwnedByFederate2)
    (RTI::RTIambassador *, RTI::ObjectHandle, RTI::AttributeHandle) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__enableTimeRegulation2) (RTI::
                                                          RTIambassador *,
                                                          const RTI::
                                                          FedTime &,
                                                          const RTI::
                                                          FedTime &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__disableTimeRegulation0) (RTI::
                                                           RTIambassador *)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__enableTimeConstrained0) (RTI::
                                                           RTIambassador *)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__disableTimeConstrained0) (RTI::
                                                            RTIambassador
                                                            *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__timeAdvanceRequest1) (RTI::
                                                        RTIambassador *,
                                                        const RTI::
                                                        FedTime &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__timeAdvanceRequestAvailable1) (RTI::
                                                                 RTIambassador
                                                                 *,
                                                                 const
                                                                 RTI::
                                                                 FedTime &)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__nextEventRequest1) (RTI::RTIambassador *,
                                                      const RTI::
                                                      FedTime &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__nextEventRequestAvailable1) (RTI::
                                                               RTIambassador
                                                               *,
                                                               const RTI::
                                                               FedTime &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__flushQueueRequest1) (RTI::
                                                       RTIambassador *,
                                                       const RTI::
                                                       FedTime &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__enableAsynchronousDelivery0) (RTI::
                                                                RTIambassador
                                                                *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__disableAsynchronousDelivery0) (RTI::
                                                                 RTIambassador
                                                                 *) = NULL;

void (*MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__queryLBTS1) (RTI::
                                                                     RTIambassador
                                                                     *,
                                                                     RTI::
                                                                     FedTime
                                                                     &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__queryFederateTime1) (RTI::
                                                       RTIambassador *,
                                                       RTI::FedTime &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__queryMinNextEventTime1) (RTI::
                                                           RTIambassador *,
                                                           RTI::
                                                           FedTime &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__modifyLookahead1) (RTI::RTIambassador *,
                                                     const RTI::
                                                     FedTime &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__queryLookahead1) (RTI::RTIambassador *,
                                                    RTI::FedTime &) = NULL;

void (*MATIS_RTIAmbassador::funcptr_RTI__RTIambassador__retract1) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   EventRetractionHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__changeAttributeOrderType3) (RTI::
                                                              RTIambassador
                                                              *,
                                                              RTI::
                                                              ObjectHandle,
                                                              const RTI::
                                                              AttributeHandleSet
                                                              &,
                                                              RTI::
                                                              OrderingHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__changeInteractionOrderType2) (RTI::
                                                                RTIambassador
                                                                *,
                                                                RTI::
                                                                InteractionClassHandle,
                                                                RTI::
                                                                OrderingHandle)
    = NULL;

RTI::Region *
(*MATIS_RTIAmbassador::
 funcptr_RTI__RTIambassador__createRegion2) (RTI::RTIambassador *,
                                             RTI::SpaceHandle,
                                             RTI::ULong)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__notifyAboutRegionModification1) (RTI::
                                                                   RTIambassador
                                                                   *,
                                                                   RTI::
                                                                   Region
                                                                   &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__deleteRegion1) (RTI::RTIambassador *,
                                                  RTI::Region *) = NULL;

RTI::ObjectHandle(*MATIS_RTIAmbassador::
                  funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion5)
    (RTI::RTIambassador *, RTI::ObjectClassHandle, const char *,
     RTI::AttributeHandle *, RTI::Region **, RTI::ULong) = NULL;

RTI::ObjectHandle(*MATIS_RTIAmbassador::
                  funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion4)
    (RTI::RTIambassador *, RTI::ObjectClassHandle, RTI::AttributeHandle *,
     RTI::Region **, RTI::ULong) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__associateRegionForUpdates3) (RTI::
                                                               RTIambassador
                                                               *,
                                                               RTI::
                                                               Region &,
                                                               RTI::
                                                               ObjectHandle,
                                                               const RTI::
                                                               AttributeHandleSet
                                                               &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unassociateRegionForUpdates2) (RTI::
                                                                 RTIambassador
                                                                 *,
                                                                 RTI::
                                                                 Region &,
                                                                 RTI::
                                                                 ObjectHandle)
    = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion4)
    (RTI::RTIambassador *,
     RTI::ObjectClassHandle,
     RTI::Region &, const RTI::AttributeHandleSet &, RTI::Boolean) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unsubscribeObjectClassWithRegion2) (RTI::
                                                                      RTIambassador
                                                                      *,
                                                                      RTI::
                                                                      ObjectClassHandle,
                                                                      RTI::
                                                                      Region
                                                                      &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__subscribeInteractionClassWithRegion3)
    (RTI::RTIambassador *,
     RTI::InteractionClassHandle, RTI::Region &, RTI::Boolean) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__unsubscribeInteractionClassWithRegion2)
    (RTI::RTIambassador *, RTI::InteractionClassHandle, RTI::Region &) = NULL;

RTI::EventRetractionHandle(*MATIS_RTIAmbassador::
                           funcptr_RTI__RTIambassador__sendInteractionWithRegion5)
    (RTI::RTIambassador *, RTI::InteractionClassHandle,
     const RTI::ParameterHandleValuePairSet &, const RTI::FedTime &,
     const char *, const RTI::Region &) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__sendInteractionWithRegion4) (RTI::
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
                                                               Region &) =
NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion3)
    (RTI::RTIambassador *,
     RTI::ObjectClassHandle,
     const RTI::AttributeHandleSet &, const RTI::Region &) = NULL;

RTI::ObjectClassHandle(*MATIS_RTIAmbassador::
                       funcptr_RTI__RTIambassador__getObjectClassHandle1)
    (RTI::RTIambassador *, const char *) = NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getObjectClassName1) (RTI::
                                                         RTIambassador *,
                                                         RTI::
                                                         ObjectClassHandle)
    = NULL;

RTI::AttributeHandle(*MATIS_RTIAmbassador::
                     funcptr_RTI__RTIambassador__getAttributeHandle2)
    (RTI::RTIambassador *, const char *, RTI::ObjectClassHandle) = NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getAttributeName2) (RTI::
                                                       RTIambassador *,
                                                       RTI::
                                                       AttributeHandle,
                                                       RTI::
                                                       ObjectClassHandle) =
NULL;

RTI::InteractionClassHandle(*MATIS_RTIAmbassador::
                            funcptr_RTI__RTIambassador__getInteractionClassHandle1)
    (RTI::RTIambassador *, const char *) = NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getInteractionClassName1) (RTI::
                                                              RTIambassador
                                                              *,
                                                              RTI::
                                                              InteractionClassHandle)
    = NULL;

RTI::ParameterHandle(*MATIS_RTIAmbassador::
                     funcptr_RTI__RTIambassador__getParameterHandle2)
    (RTI::RTIambassador *, const char *, RTI::InteractionClassHandle) =
NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getParameterName2) (RTI::
                                                       RTIambassador *,
                                                       RTI::
                                                       ParameterHandle,
                                                       RTI::
                                                       InteractionClassHandle)
    = NULL;

RTI::ObjectHandle(*MATIS_RTIAmbassador::
                  funcptr_RTI__RTIambassador__getObjectInstanceHandle1)
    (RTI::RTIambassador *, const char *) = NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getObjectInstanceName1) (RTI::
                                                            RTIambassador
                                                            *,
                                                            RTI::
                                                            ObjectHandle) =
NULL;

RTI::SpaceHandle(*MATIS_RTIAmbassador::
                 funcptr_RTI__RTIambassador__getRoutingSpaceHandle1)
    (RTI::RTIambassador *, const char *) = NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getRoutingSpaceName1) (RTI::
                                                          RTIambassador *,
                                                          RTI::
                                                          SpaceHandle) =
NULL;

RTI::DimensionHandle(*MATIS_RTIAmbassador::
                     funcptr_RTI__RTIambassador__getDimensionHandle2)
    (RTI::RTIambassador *, const char *, RTI::SpaceHandle) = NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getDimensionName2) (RTI::
                                                       RTIambassador *,
                                                       RTI::
                                                       DimensionHandle,
                                                       RTI::SpaceHandle) =
NULL;

RTI::SpaceHandle(*MATIS_RTIAmbassador::
                 funcptr_RTI__RTIambassador__getAttributeRoutingSpaceHandle2)
    (RTI::RTIambassador *, RTI::AttributeHandle, RTI::ObjectClassHandle) =
NULL;

RTI::ObjectClassHandle(*MATIS_RTIAmbassador::
                       funcptr_RTI__RTIambassador__getObjectClass1) (RTI::
                                                                     RTIambassador
                                                                     *,
                                                                     RTI::
                                                                     ObjectHandle)
    = NULL;

RTI::SpaceHandle(*MATIS_RTIAmbassador::
                 funcptr_RTI__RTIambassador__getInteractionRoutingSpaceHandle1)
    (RTI::RTIambassador *, RTI::InteractionClassHandle) = NULL;

RTI::TransportationHandle(*MATIS_RTIAmbassador::
                          funcptr_RTI__RTIambassador__getTransportationHandle1)
    (RTI::RTIambassador *, const char *) = NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getTransportationName1) (RTI::
                                                            RTIambassador
                                                            *,
                                                            RTI::
                                                            TransportationHandle)
    = NULL;

RTI::OrderingHandle(*MATIS_RTIAmbassador::
                    funcptr_RTI__RTIambassador__getOrderingHandle1) (RTI::
                                                                     RTIambassador
                                                                     *,
                                                                     const
                                                                     char
                                                                     *) =
NULL;

char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getOrderingName1) (RTI::RTIambassador *,
                                                      RTI::
                                                      OrderingHandle) =
NULL;

RTI::RegionToken (*MATIS_RTIAmbassador::
                  funcptr_RTI__RTIambassador__getRegionToken1) (RTI::RTIambassador*,
                                                                RTI::Region*) = NULL;


char *(*MATIS_RTIAmbassador::
       funcptr_RTI__RTIambassador__getRegion1) (RTI::RTIambassador *,
                                                RTI::RegionToken) = NULL;


void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

void (*MATIS_RTIAmbassador::
      funcptr_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch0)
    (RTI::RTIambassador *) = NULL;

RTI::Boolean(*MATIS_RTIAmbassador::
             funcptr_RTI__RTIambassador__tick0) (RTI::RTIambassador *) =
NULL;

RTI::Boolean(*MATIS_RTIAmbassador::
             funcptr_RTI__RTIambassador__tick2) (RTI::RTIambassador *,
                                                 RTI::TickTime,
                                                 RTI::TickTime) = NULL;
