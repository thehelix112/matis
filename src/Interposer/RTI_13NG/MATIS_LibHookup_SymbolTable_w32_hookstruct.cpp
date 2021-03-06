// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LibHookup_SymbolTable_w32_hookstruct.cpp,v $
// CVS $Date: 2005/11/11 04:51:13 $
// CVS $Revision: 1.1.1.1 $





DLLPatchStruct MATIS_PatchInfo = 
{
   {
  	  "libRTI-NG.dll",	// contains RTI Ambassador functions
 	  "libRTI-NGd.dll",	// contains RTI Ambassador functions
	  "KERNEL32.DLL",
	  NULL
	},
    false, NULL, // Default hook disabled, NULL function pointer.
    {

        { "LoadLibraryA", MATIS_LoadLibraryA },
        { "LoadLibraryW", MATIS_LoadLibraryW },
        { "LoadLibraryExA", MATIS_LoadLibraryExA },
        { "LoadLibraryExW", MATIS_LoadLibraryExW },
        { "?associateRegionForUpdates@RTIambassador@RTI@@QAEXAAVRegion@2@KABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__associateRegionForUpdates.p },
        { "?attributeOwnershipAcquisition@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@PBD@Z", u_RTI__RTIambassador__attributeOwnershipAcquisition.p },
        { "?attributeOwnershipAcquisitionIfAvailable@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable.p },
        { "?attributeOwnershipReleaseResponse@RTIambassador@RTI@@QAEPAVAttributeHandleSet@2@KABV32@@Z", u_RTI__RTIambassador__attributeOwnershipReleaseResponse.p },
        { "?cancelAttributeOwnershipAcquisition@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__cancelAttributeOwnershipAcquisition.p },
        { "?cancelNegotiatedAttributeOwnershipDivestiture@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture.p },
        { "?changeAttributeOrderType@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@K@Z", u_RTI__RTIambassador__changeAttributeOrderType.p },
        { "?changeAttributeTransportationType@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@K@Z", u_RTI__RTIambassador__changeAttributeTransportationType.p },
        { "?changeInteractionOrderType@RTIambassador@RTI@@QAEXKK@Z", u_RTI__RTIambassador__changeInteractionOrderType.p },
        { "?changeInteractionTransportationType@RTIambassador@RTI@@QAEXKK@Z", u_RTI__RTIambassador__changeInteractionTransportationType.p },
        { "?createFederationExecution@RTIambassador@RTI@@QAEXPBD0@Z", u_RTI__RTIambassador__createFederationExecution.p },
        { "?createRegion@RTIambassador@RTI@@QAEPAVRegion@2@JK@Z", u_RTI__RTIambassador__createRegion.p },
        { "?deleteObjectInstance@RTIambassador@RTI@@QAE?AUEventRetractionHandle_s@2@KABVFedTime@2@PBD@Z", u_RTI__RTIambassador__deleteObjectInstance.p },
        { "?deleteObjectInstance@RTIambassador@RTI@@QAEXKPBD@Z", u_RTI__RTIambassador__deleteObjectInstanceFull.p },
        { "?deleteRegion@RTIambassador@RTI@@QAEXPAVRegion@2@@Z", u_RTI__RTIambassador__deleteRegion.p },
        { "?destroyFederationExecution@RTIambassador@RTI@@QAEXPBD@Z", u_RTI__RTIambassador__destroyFederationExecution.p },
        { "?disableAsynchronousDelivery@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__disableAsynchronousDelivery.p },
        { "?disableAttributeRelevanceAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch.p },
        { "?disableAttributeScopeAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch.p },
        { "?disableClassRelevanceAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch.p },
        { "?disableInteractionRelevanceAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch.p },
        { "?disableTimeConstrained@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__disableTimeConstrained.p },
        { "?disableTimeRegulation@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__disableTimeRegulation.p },
        { "?enableAsynchronousDelivery@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__enableAsynchronousDelivery.p },
        { "?enableAttributeRelevanceAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch.p },
        { "?enableAttributeScopeAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch.p },
        { "?enableClassRelevanceAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch.p },
        { "?enableInteractionRelevanceAdvisorySwitch@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch.p },
        { "?enableTimeConstrained@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__enableTimeConstrained.p },
        { "?enableTimeRegulation@RTIambassador@RTI@@QAEXABVFedTime@2@0@Z", u_RTI__RTIambassador__enableTimeRegulation.p },
        { "?federateRestoreComplete@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__federateRestoreComplete.p },
        { "?federateRestoreNotComplete@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__federateRestoreNotComplete.p },
        { "?federateSaveBegun@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__federateSaveBegun.p },
        { "?federateSaveComplete@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__federateSaveComplete.p },
        { "?federateSaveNotComplete@RTIambassador@RTI@@QAEXXZ", u_RTI__RTIambassador__federateSaveNotComplete.p },
        { "?flushQueueRequest@RTIambassador@RTI@@QAEXABVFedTime@2@@Z", u_RTI__RTIambassador__flushQueueRequest.p },
        { "?getAttributeHandle@RTIambassador@RTI@@QAEKPBDK@Z", u_RTI__RTIambassador__getAttributeHandle.p },
        { "?getAttributeName@RTIambassador@RTI@@QAEPADKK@Z", u_RTI__RTIambassador__getAttributeName.p },
        { "?getAttributeRoutingSpaceHandle@RTIambassador@RTI@@QAEJKK@Z", u_RTI__RTIambassador__getAttributeRoutingSpaceHandle.p },
        { "?getDimensionHandle@RTIambassador@RTI@@QAEKPBDJ@Z", u_RTI__RTIambassador__getDimensionHandle.p },
        { "?getDimensionName@RTIambassador@RTI@@QAEPADKJ@Z", u_RTI__RTIambassador__getDimensionName.p },
        { "?getInteractionClassHandle@RTIambassador@RTI@@QAEKPBD@Z", u_RTI__RTIambassador__getInteractionClassHandle.p },
        { "?getInteractionClassName@RTIambassador@RTI@@QAEPADK@Z", u_RTI__RTIambassador__getInteractionClassName.p },
        { "?getInteractionRoutingSpaceHandle@RTIambassador@RTI@@QAEJK@Z", u_RTI__RTIambassador__getInteractionRoutingSpaceHandle.p },
        { "?getObjectClass@RTIambassador@RTI@@QAEKK@Z", u_RTI__RTIambassador__getObjectClass.p },
        { "?getObjectClassHandle@RTIambassador@RTI@@QAEKPBD@Z", u_RTI__RTIambassador__getObjectClassHandle.p },
        { "?getObjectClassName@RTIambassador@RTI@@QAEPADK@Z", u_RTI__RTIambassador__getObjectClassName.p },
        { "?getObjectInstanceHandle@RTIambassador@RTI@@QAEKPBD@Z", u_RTI__RTIambassador__getObjectInstanceHandle.p },
        { "?getObjectInstanceName@RTIambassador@RTI@@QAEPADK@Z", u_RTI__RTIambassador__getObjectInstanceName.p },
        { "?getOrderingHandle@RTIambassador@RTI@@QAEKPBD@Z", u_RTI__RTIambassador__getOrderingHandle.p },
        { "?getOrderingName@RTIambassador@RTI@@QAEPADK@Z", u_RTI__RTIambassador__getOrderingName.p },
        { "?getParameterHandle@RTIambassador@RTI@@QAEKPBDK@Z", u_RTI__RTIambassador__getParameterHandle.p },
        { "?getParameterName@RTIambassador@RTI@@QAEPADKK@Z", u_RTI__RTIambassador__getParameterName.p },
        { "?getRegion@RTIambassador@RTI@@QAEPAVRegion@2@K@Z", u_RTI__RTIambassador__getRegion.p },
        { "?getRegionToken@RTIambassador@RTI@@QAEKPAVRegion@2@@Z", u_RTI__RTIambassador__getRegionToken.p },
        { "?getRoutingSpaceHandle@RTIambassador@RTI@@QAEJPBD@Z", u_RTI__RTIambassador__getRoutingSpaceHandle.p },
        { "?getRoutingSpaceName@RTIambassador@RTI@@QAEPADJ@Z", u_RTI__RTIambassador__getRoutingSpaceName.p },
        { "?getTransportationHandle@RTIambassador@RTI@@QAEKPBD@Z", u_RTI__RTIambassador__getTransportationHandle.p },
        { "?getTransportationName@RTIambassador@RTI@@QAEPADK@Z", u_RTI__RTIambassador__getTransportationName.p },
        { "?isAttributeOwnedByFederate@RTIambassador@RTI@@QAE?AW4Boolean@2@KK@Z", u_RTI__RTIambassador__isAttributeOwnedByFederate.p },
        { "?joinFederationExecution@RTIambassador@RTI@@QAEKPBD0PAVFederateAmbassador@2@@Z", u_RTI__RTIambassador__joinFederationExecution.p },
        { "?localDeleteObjectInstance@RTIambassador@RTI@@QAEXK@Z", u_RTI__RTIambassador__localDeleteObjectInstance.p },
        { "?modifyLookahead@RTIambassador@RTI@@QAEXABVFedTime@2@@Z", u_RTI__RTIambassador__modifyLookahead.p },
        { "?negotiatedAttributeOwnershipDivestiture@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@PBD@Z", u_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture.p },
        { "?nextEventRequest@RTIambassador@RTI@@QAEXABVFedTime@2@@Z", u_RTI__RTIambassador__nextEventRequest.p },
        { "?nextEventRequestAvailable@RTIambassador@RTI@@QAEXABVFedTime@2@@Z", u_RTI__RTIambassador__nextEventRequestAvailable.p },
        { "?notifyAboutRegionModification@RTIambassador@RTI@@QAEXAAVRegion@2@@Z", u_RTI__RTIambassador__notifyAboutRegionModification.p },
        { "?publishInteractionClass@RTIambassador@RTI@@QAEXK@Z", u_RTI__RTIambassador__publishInteractionClass.p },
        { "?publishObjectClass@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__publishObjectClass.p },
        { "?queryAttributeOwnership@RTIambassador@RTI@@QAEXKK@Z", u_RTI__RTIambassador__queryAttributeOwnership.p },
        { "?queryFederateTime@RTIambassador@RTI@@QAEXAAVFedTime@2@@Z", u_RTI__RTIambassador__queryFederateTime.p },
        { "?queryLBTS@RTIambassador@RTI@@QAEXAAVFedTime@2@@Z", u_RTI__RTIambassador__queryLBTS.p },
        { "?queryLookahead@RTIambassador@RTI@@QAEXAAVFedTime@2@@Z", u_RTI__RTIambassador__queryLookahead.p },
        { "?queryMinNextEventTime@RTIambassador@RTI@@QAEXAAVFedTime@2@@Z", u_RTI__RTIambassador__queryMinNextEventTime.p },
        { "?registerFederationSynchronizationPoint@RTIambassador@RTI@@QAEXPBD0@Z", u_RTI__RTIambassador__registerFederationSynchronizationPoint.p },
        { "?registerFederationSynchronizationPoint@RTIambassador@RTI@@QAEXPBD0ABVFederateHandleSet@2@@Z", u_RTI__RTIambassador__registerFederationSynchronizationPointFull.p },
        { "?registerObjectInstance@RTIambassador@RTI@@QAEKK@Z", u_RTI__RTIambassador__registerObjectInstance.p },
        { "?registerObjectInstance@RTIambassador@RTI@@QAEKKPBD@Z", u_RTI__RTIambassador__registerObjectInstanceFull.p },
        { "?registerObjectInstanceWithRegion@RTIambassador@RTI@@QAEKKPBDQAKQAPAVRegion@2@K@Z", u_RTI__RTIambassador__registerObjectInstanceWithRegion.p },
        { "?registerObjectInstanceWithRegion@RTIambassador@RTI@@QAEKKQAKQAPAVRegion@2@K@Z", u_RTI__RTIambassador__registerObjectInstanceWithRegionFull.p },
        { "?requestClassAttributeValueUpdate@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__requestClassAttributeValueUpdate.p },
        { "?requestClassAttributeValueUpdateWithRegion@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@ABVRegion@2@@Z", u_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion.p },
        { "?requestFederationRestore@RTIambassador@RTI@@QAEXPBD@Z", u_RTI__RTIambassador__requestFederationRestore.p },
        { "?requestFederationSave@RTIambassador@RTI@@QAEXPBD@Z", u_RTI__RTIambassador__requestFederationSave.p },
        { "?requestFederationSave@RTIambassador@RTI@@QAEXPBDABVFedTime@2@@Z", u_RTI__RTIambassador__requestFederationSaveFull.p },
        { "?requestObjectAttributeValueUpdate@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__requestObjectAttributeValueUpdate.p },
        { "?resignFederationExecution@RTIambassador@RTI@@QAEXW4ResignAction@2@@Z", u_RTI__RTIambassador__resignFederationExecution.p },
        { "?retract@RTIambassador@RTI@@QAEXUEventRetractionHandle_s@2@@Z", u_RTI__RTIambassador__retract.p },
        { "?sendInteraction@RTIambassador@RTI@@QAE?AUEventRetractionHandle_s@2@KABVParameterHandleValuePairSet@2@ABVFedTime@2@PBD@Z", u_RTI__RTIambassador__sendInteraction.p },
        { "?sendInteraction@RTIambassador@RTI@@QAEXKABVParameterHandleValuePairSet@2@PBD@Z", u_RTI__RTIambassador__sendInteractionFull.p },
        { "?sendInteractionWithRegion@RTIambassador@RTI@@QAE?AUEventRetractionHandle_s@2@KABVParameterHandleValuePairSet@2@ABVFedTime@2@PBDABVRegion@2@@Z", u_RTI__RTIambassador__sendInteractionWithRegion.p },
        { "?sendInteractionWithRegion@RTIambassador@RTI@@QAEXKABVParameterHandleValuePairSet@2@PBDABVRegion@2@@Z", u_RTI__RTIambassador__sendInteractionWithRegionFull.p },
        { "?subscribeInteractionClass@RTIambassador@RTI@@QAEXKW4Boolean@2@@Z", u_RTI__RTIambassador__subscribeInteractionClass.p },
        { "?subscribeInteractionClassWithRegion@RTIambassador@RTI@@QAEXKAAVRegion@2@W4Boolean@2@@Z", u_RTI__RTIambassador__subscribeInteractionClassWithRegion.p },
        { "?subscribeObjectClassAttributes@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@W4Boolean@2@@Z", u_RTI__RTIambassador__subscribeObjectClassAttributes.p },
        { "?subscribeObjectClassAttributesWithRegion@RTIambassador@RTI@@QAEXKAAVRegion@2@ABVAttributeHandleSet@2@W4Boolean@2@@Z", u_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion.p },
        { "?synchronizationPointAchieved@RTIambassador@RTI@@QAEXPBD@Z", u_RTI__RTIambassador__synchronizationPointAchieved.p },
        { "?tick@RTIambassador@RTI@@QAE?AW4Boolean@2@NN@Z", u_RTI__RTIambassador__tick.p },
        { "?tick@RTIambassador@RTI@@QAE?AW4Boolean@2@XZ", u_RTI__RTIambassador__tickFull.p },
        { "?timeAdvanceRequest@RTIambassador@RTI@@QAEXABVFedTime@2@@Z", u_RTI__RTIambassador__timeAdvanceRequest.p },
        { "?timeAdvanceRequestAvailable@RTIambassador@RTI@@QAEXABVFedTime@2@@Z", u_RTI__RTIambassador__timeAdvanceRequestAvailable.p },
        { "?unassociateRegionForUpdates@RTIambassador@RTI@@QAEXAAVRegion@2@K@Z", u_RTI__RTIambassador__unassociateRegionForUpdates.p },
        { "?unconditionalAttributeOwnershipDivestiture@RTIambassador@RTI@@QAEXKABVAttributeHandleSet@2@@Z", u_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture.p },
        { "?unpublishInteractionClass@RTIambassador@RTI@@QAEXK@Z", u_RTI__RTIambassador__unpublishInteractionClass.p },
        { "?unpublishObjectClass@RTIambassador@RTI@@QAEXK@Z", u_RTI__RTIambassador__unpublishObjectClass.p },
        { "?unsubscribeInteractionClass@RTIambassador@RTI@@QAEXK@Z", u_RTI__RTIambassador__unsubscribeInteractionClass.p },
        { "?unsubscribeInteractionClassWithRegion@RTIambassador@RTI@@QAEXKAAVRegion@2@@Z", u_RTI__RTIambassador__unsubscribeInteractionClassWithRegion.p },
        { "?unsubscribeObjectClass@RTIambassador@RTI@@QAEXK@Z", u_RTI__RTIambassador__unsubscribeObjectClass.p },
        { "?unsubscribeObjectClassWithRegion@RTIambassador@RTI@@QAEXKAAVRegion@2@@Z", u_RTI__RTIambassador__unsubscribeObjectClassWithRegion.p },
        { "?updateAttributeValues@RTIambassador@RTI@@QAE?AUEventRetractionHandle_s@2@KABVAttributeHandleValuePairSet@2@ABVFedTime@2@PBD@Z", u_RTI__RTIambassador__updateAttributeValues.p },
        { "?updateAttributeValues@RTIambassador@RTI@@QAEXKABVAttributeHandleValuePairSet@2@PBD@Z", u_RTI__RTIambassador__updateAttributeValuesFull.p },

       { NULL, NULL }
    }
};
