// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LibHookup_SymbolTable_w32_funcptrs.cpp,v $
// CVS $Date: 2005/11/11 04:51:13 $
// CVS $Revision: 1.1.1.1 $





void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__associateRegionForUpdates)(class RTI::Region &,unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::associateRegionForUpdates;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::Region &,unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__associateRegionForUpdates = { pf_RTI__RTIambassador__associateRegionForUpdates };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__attributeOwnershipAcquisition)(unsigned long,class RTI::AttributeHandleSet const &,char const *) = 
     &FakeRTIambassador::attributeOwnershipAcquisition;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &,char const *); 
  void *p;
} u_RTI__RTIambassador__attributeOwnershipAcquisition = { pf_RTI__RTIambassador__attributeOwnershipAcquisition };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::attributeOwnershipAcquisitionIfAvailable;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable = { pf_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable };

class RTI::AttributeHandleSet *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__attributeOwnershipReleaseResponse)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::attributeOwnershipReleaseResponse;
union { 
  class RTI::AttributeHandleSet * (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__attributeOwnershipReleaseResponse = { pf_RTI__RTIambassador__attributeOwnershipReleaseResponse };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__cancelAttributeOwnershipAcquisition)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::cancelAttributeOwnershipAcquisition;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__cancelAttributeOwnershipAcquisition = { pf_RTI__RTIambassador__cancelAttributeOwnershipAcquisition };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::cancelNegotiatedAttributeOwnershipDivestiture;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture = { pf_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__changeAttributeOrderType)(unsigned long,class RTI::AttributeHandleSet const &,unsigned long) = 
     &FakeRTIambassador::changeAttributeOrderType;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &,unsigned long); 
  void *p;
} u_RTI__RTIambassador__changeAttributeOrderType = { pf_RTI__RTIambassador__changeAttributeOrderType };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__changeAttributeTransportationType)(unsigned long,class RTI::AttributeHandleSet const &,unsigned long) = 
     &FakeRTIambassador::changeAttributeTransportationType;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &,unsigned long); 
  void *p;
} u_RTI__RTIambassador__changeAttributeTransportationType = { pf_RTI__RTIambassador__changeAttributeTransportationType };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__changeInteractionOrderType)(unsigned long,unsigned long) = 
     &FakeRTIambassador::changeInteractionOrderType;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__changeInteractionOrderType = { pf_RTI__RTIambassador__changeInteractionOrderType };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__changeInteractionTransportationType)(unsigned long,unsigned long) = 
     &FakeRTIambassador::changeInteractionTransportationType;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__changeInteractionTransportationType = { pf_RTI__RTIambassador__changeInteractionTransportationType };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__createFederationExecution)(char const *,char const *) = 
     &FakeRTIambassador::createFederationExecution;
union { 
  void (FakeRTIambassador:: * pf)(char const *,char const *); 
  void *p;
} u_RTI__RTIambassador__createFederationExecution = { pf_RTI__RTIambassador__createFederationExecution };

class RTI::Region *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__createRegion)(long,unsigned long) = 
     &FakeRTIambassador::createRegion;
union { 
  class RTI::Region * (FakeRTIambassador:: * pf)(long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__createRegion = { pf_RTI__RTIambassador__createRegion };

struct RTI::EventRetractionHandle_s
  (FakeRTIambassador:: * pf_RTI__RTIambassador__deleteObjectInstance)(unsigned long,class RTI::FedTime const &,char const *) = 
     &FakeRTIambassador::deleteObjectInstance;
union { 
  struct RTI::EventRetractionHandle_s (FakeRTIambassador:: * pf)(unsigned long,class RTI::FedTime const &,char const *); 
  void *p;
} u_RTI__RTIambassador__deleteObjectInstance = { pf_RTI__RTIambassador__deleteObjectInstance };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__deleteObjectInstanceFull)(unsigned long,char const *) = 
     &FakeRTIambassador::deleteObjectInstance;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,char const *); 
  void *p;
} u_RTI__RTIambassador__deleteObjectInstanceFull = { pf_RTI__RTIambassador__deleteObjectInstanceFull };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__deleteRegion)(class RTI::Region *) = 
     &FakeRTIambassador::deleteRegion;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::Region *); 
  void *p;
} u_RTI__RTIambassador__deleteRegion = { pf_RTI__RTIambassador__deleteRegion };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__destroyFederationExecution)(char const *) = 
     &FakeRTIambassador::destroyFederationExecution;
union { 
  void (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__destroyFederationExecution = { pf_RTI__RTIambassador__destroyFederationExecution };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__disableAsynchronousDelivery)(void) = 
     &FakeRTIambassador::disableAsynchronousDelivery;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__disableAsynchronousDelivery = { pf_RTI__RTIambassador__disableAsynchronousDelivery };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch)(void) = 
     &FakeRTIambassador::disableAttributeRelevanceAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch = { pf_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch)(void) = 
     &FakeRTIambassador::disableAttributeScopeAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch = { pf_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch)(void) = 
     &FakeRTIambassador::disableClassRelevanceAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch = { pf_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch)(void) = 
     &FakeRTIambassador::disableInteractionRelevanceAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch = { pf_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__disableTimeConstrained)(void) = 
     &FakeRTIambassador::disableTimeConstrained;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__disableTimeConstrained = { pf_RTI__RTIambassador__disableTimeConstrained };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__disableTimeRegulation)(void) = 
     &FakeRTIambassador::disableTimeRegulation;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__disableTimeRegulation = { pf_RTI__RTIambassador__disableTimeRegulation };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__enableAsynchronousDelivery)(void) = 
     &FakeRTIambassador::enableAsynchronousDelivery;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__enableAsynchronousDelivery = { pf_RTI__RTIambassador__enableAsynchronousDelivery };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch)(void) = 
     &FakeRTIambassador::enableAttributeRelevanceAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch = { pf_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch)(void) = 
     &FakeRTIambassador::enableAttributeScopeAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch = { pf_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch)(void) = 
     &FakeRTIambassador::enableClassRelevanceAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch = { pf_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch)(void) = 
     &FakeRTIambassador::enableInteractionRelevanceAdvisorySwitch;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch = { pf_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__enableTimeConstrained)(void) = 
     &FakeRTIambassador::enableTimeConstrained;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__enableTimeConstrained = { pf_RTI__RTIambassador__enableTimeConstrained };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__enableTimeRegulation)(class RTI::FedTime const &,class RTI::FedTime const &) = 
     &FakeRTIambassador::enableTimeRegulation;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime const &,class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__enableTimeRegulation = { pf_RTI__RTIambassador__enableTimeRegulation };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__federateRestoreComplete)(void) = 
     &FakeRTIambassador::federateRestoreComplete;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__federateRestoreComplete = { pf_RTI__RTIambassador__federateRestoreComplete };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__federateRestoreNotComplete)(void) = 
     &FakeRTIambassador::federateRestoreNotComplete;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__federateRestoreNotComplete = { pf_RTI__RTIambassador__federateRestoreNotComplete };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__federateSaveBegun)(void) = 
     &FakeRTIambassador::federateSaveBegun;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__federateSaveBegun = { pf_RTI__RTIambassador__federateSaveBegun };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__federateSaveComplete)(void) = 
     &FakeRTIambassador::federateSaveComplete;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__federateSaveComplete = { pf_RTI__RTIambassador__federateSaveComplete };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__federateSaveNotComplete)(void) = 
     &FakeRTIambassador::federateSaveNotComplete;
union { 
  void (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__federateSaveNotComplete = { pf_RTI__RTIambassador__federateSaveNotComplete };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__flushQueueRequest)(class RTI::FedTime const &) = 
     &FakeRTIambassador::flushQueueRequest;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__flushQueueRequest = { pf_RTI__RTIambassador__flushQueueRequest };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getAttributeHandle)(char const *,unsigned long) = 
     &FakeRTIambassador::getAttributeHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *,unsigned long); 
  void *p;
} u_RTI__RTIambassador__getAttributeHandle = { pf_RTI__RTIambassador__getAttributeHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getAttributeName)(unsigned long,unsigned long) = 
     &FakeRTIambassador::getAttributeName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__getAttributeName = { pf_RTI__RTIambassador__getAttributeName };

long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getAttributeRoutingSpaceHandle)(unsigned long,unsigned long) = 
     &FakeRTIambassador::getAttributeRoutingSpaceHandle;
union { 
  long (FakeRTIambassador:: * pf)(unsigned long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__getAttributeRoutingSpaceHandle = { pf_RTI__RTIambassador__getAttributeRoutingSpaceHandle };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getDimensionHandle)(char const *,long) = 
     &FakeRTIambassador::getDimensionHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *,long); 
  void *p;
} u_RTI__RTIambassador__getDimensionHandle = { pf_RTI__RTIambassador__getDimensionHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getDimensionName)(unsigned long,long) = 
     &FakeRTIambassador::getDimensionName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long,long); 
  void *p;
} u_RTI__RTIambassador__getDimensionName = { pf_RTI__RTIambassador__getDimensionName };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getInteractionClassHandle)(char const *) = 
     &FakeRTIambassador::getInteractionClassHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__getInteractionClassHandle = { pf_RTI__RTIambassador__getInteractionClassHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getInteractionClassName)(unsigned long) = 
     &FakeRTIambassador::getInteractionClassName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getInteractionClassName = { pf_RTI__RTIambassador__getInteractionClassName };

long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getInteractionRoutingSpaceHandle)(unsigned long) = 
     &FakeRTIambassador::getInteractionRoutingSpaceHandle;
union { 
  long (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getInteractionRoutingSpaceHandle = { pf_RTI__RTIambassador__getInteractionRoutingSpaceHandle };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getObjectClass)(unsigned long) = 
     &FakeRTIambassador::getObjectClass;
union { 
  unsigned long (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getObjectClass = { pf_RTI__RTIambassador__getObjectClass };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getObjectClassHandle)(char const *) = 
     &FakeRTIambassador::getObjectClassHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__getObjectClassHandle = { pf_RTI__RTIambassador__getObjectClassHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getObjectClassName)(unsigned long) = 
     &FakeRTIambassador::getObjectClassName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getObjectClassName = { pf_RTI__RTIambassador__getObjectClassName };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getObjectInstanceHandle)(char const *) = 
     &FakeRTIambassador::getObjectInstanceHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__getObjectInstanceHandle = { pf_RTI__RTIambassador__getObjectInstanceHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getObjectInstanceName)(unsigned long) = 
     &FakeRTIambassador::getObjectInstanceName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getObjectInstanceName = { pf_RTI__RTIambassador__getObjectInstanceName };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getOrderingHandle)(char const *) = 
     &FakeRTIambassador::getOrderingHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__getOrderingHandle = { pf_RTI__RTIambassador__getOrderingHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getOrderingName)(unsigned long) = 
     &FakeRTIambassador::getOrderingName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getOrderingName = { pf_RTI__RTIambassador__getOrderingName };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getParameterHandle)(char const *,unsigned long) = 
     &FakeRTIambassador::getParameterHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *,unsigned long); 
  void *p;
} u_RTI__RTIambassador__getParameterHandle = { pf_RTI__RTIambassador__getParameterHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getParameterName)(unsigned long,unsigned long) = 
     &FakeRTIambassador::getParameterName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__getParameterName = { pf_RTI__RTIambassador__getParameterName };

class RTI::Region *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getRegion)(unsigned long) = 
     &FakeRTIambassador::getRegion;
union { 
  class RTI::Region * (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getRegion = { pf_RTI__RTIambassador__getRegion };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getRegionToken)(class RTI::Region *) = 
     &FakeRTIambassador::getRegionToken;
union { 
  unsigned long (FakeRTIambassador:: * pf)(class RTI::Region *); 
  void *p;
} u_RTI__RTIambassador__getRegionToken = { pf_RTI__RTIambassador__getRegionToken };

long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getRoutingSpaceHandle)(char const *) = 
     &FakeRTIambassador::getRoutingSpaceHandle;
union { 
  long (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__getRoutingSpaceHandle = { pf_RTI__RTIambassador__getRoutingSpaceHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getRoutingSpaceName)(long) = 
     &FakeRTIambassador::getRoutingSpaceName;
union { 
  char * (FakeRTIambassador:: * pf)(long); 
  void *p;
} u_RTI__RTIambassador__getRoutingSpaceName = { pf_RTI__RTIambassador__getRoutingSpaceName };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getTransportationHandle)(char const *) = 
     &FakeRTIambassador::getTransportationHandle;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__getTransportationHandle = { pf_RTI__RTIambassador__getTransportationHandle };

char *
  (FakeRTIambassador:: * pf_RTI__RTIambassador__getTransportationName)(unsigned long) = 
     &FakeRTIambassador::getTransportationName;
union { 
  char * (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__getTransportationName = { pf_RTI__RTIambassador__getTransportationName };

enum RTI::Boolean
  (FakeRTIambassador:: * pf_RTI__RTIambassador__isAttributeOwnedByFederate)(unsigned long,unsigned long) = 
     &FakeRTIambassador::isAttributeOwnedByFederate;
union { 
  enum RTI::Boolean (FakeRTIambassador:: * pf)(unsigned long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__isAttributeOwnedByFederate = { pf_RTI__RTIambassador__isAttributeOwnedByFederate };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__joinFederationExecution)(char const *,char const *,class RTI::FederateAmbassador *) = 
     &FakeRTIambassador::joinFederationExecution;
union { 
  unsigned long (FakeRTIambassador:: * pf)(char const *,char const *,class RTI::FederateAmbassador *); 
  void *p;
} u_RTI__RTIambassador__joinFederationExecution = { pf_RTI__RTIambassador__joinFederationExecution };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__localDeleteObjectInstance)(unsigned long) = 
     &FakeRTIambassador::localDeleteObjectInstance;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__localDeleteObjectInstance = { pf_RTI__RTIambassador__localDeleteObjectInstance };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__modifyLookahead)(class RTI::FedTime const &) = 
     &FakeRTIambassador::modifyLookahead;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__modifyLookahead = { pf_RTI__RTIambassador__modifyLookahead };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture)(unsigned long,class RTI::AttributeHandleSet const &,char const *) = 
     &FakeRTIambassador::negotiatedAttributeOwnershipDivestiture;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &,char const *); 
  void *p;
} u_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture = { pf_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__nextEventRequest)(class RTI::FedTime const &) = 
     &FakeRTIambassador::nextEventRequest;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__nextEventRequest = { pf_RTI__RTIambassador__nextEventRequest };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__nextEventRequestAvailable)(class RTI::FedTime const &) = 
     &FakeRTIambassador::nextEventRequestAvailable;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__nextEventRequestAvailable = { pf_RTI__RTIambassador__nextEventRequestAvailable };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__notifyAboutRegionModification)(class RTI::Region &) = 
     &FakeRTIambassador::notifyAboutRegionModification;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::Region &); 
  void *p;
} u_RTI__RTIambassador__notifyAboutRegionModification = { pf_RTI__RTIambassador__notifyAboutRegionModification };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__publishInteractionClass)(unsigned long) = 
     &FakeRTIambassador::publishInteractionClass;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__publishInteractionClass = { pf_RTI__RTIambassador__publishInteractionClass };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__publishObjectClass)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::publishObjectClass;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__publishObjectClass = { pf_RTI__RTIambassador__publishObjectClass };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__queryAttributeOwnership)(unsigned long,unsigned long) = 
     &FakeRTIambassador::queryAttributeOwnership;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,unsigned long); 
  void *p;
} u_RTI__RTIambassador__queryAttributeOwnership = { pf_RTI__RTIambassador__queryAttributeOwnership };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__queryFederateTime)(class RTI::FedTime &) = 
     &FakeRTIambassador::queryFederateTime;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime &); 
  void *p;
} u_RTI__RTIambassador__queryFederateTime = { pf_RTI__RTIambassador__queryFederateTime };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__queryLBTS)(class RTI::FedTime &) = 
     &FakeRTIambassador::queryLBTS;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime &); 
  void *p;
} u_RTI__RTIambassador__queryLBTS = { pf_RTI__RTIambassador__queryLBTS };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__queryLookahead)(class RTI::FedTime &) = 
     &FakeRTIambassador::queryLookahead;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime &); 
  void *p;
} u_RTI__RTIambassador__queryLookahead = { pf_RTI__RTIambassador__queryLookahead };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__queryMinNextEventTime)(class RTI::FedTime &) = 
     &FakeRTIambassador::queryMinNextEventTime;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime &); 
  void *p;
} u_RTI__RTIambassador__queryMinNextEventTime = { pf_RTI__RTIambassador__queryMinNextEventTime };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__registerFederationSynchronizationPoint)(char const *,char const *) = 
     &FakeRTIambassador::registerFederationSynchronizationPoint;
union { 
  void (FakeRTIambassador:: * pf)(char const *,char const *); 
  void *p;
} u_RTI__RTIambassador__registerFederationSynchronizationPoint = { pf_RTI__RTIambassador__registerFederationSynchronizationPoint };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__registerFederationSynchronizationPointFull)(char const *,char const *,class RTI::FederateHandleSet const &) = 
     &FakeRTIambassador::registerFederationSynchronizationPoint;
union { 
  void (FakeRTIambassador:: * pf)(char const *,char const *,class RTI::FederateHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__registerFederationSynchronizationPointFull = { pf_RTI__RTIambassador__registerFederationSynchronizationPointFull };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__registerObjectInstance)(unsigned long) = 
     &FakeRTIambassador::registerObjectInstance;
union { 
  unsigned long (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__registerObjectInstance = { pf_RTI__RTIambassador__registerObjectInstance };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__registerObjectInstanceFull)(unsigned long,char const *) = 
     &FakeRTIambassador::registerObjectInstance;
union { 
  unsigned long (FakeRTIambassador:: * pf)(unsigned long,char const *); 
  void *p;
} u_RTI__RTIambassador__registerObjectInstanceFull = { pf_RTI__RTIambassador__registerObjectInstanceFull };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__registerObjectInstanceWithRegion)(unsigned long,char const *,unsigned long * const,class RTI::Region * * const,unsigned long) = 
     &FakeRTIambassador::registerObjectInstanceWithRegion;
union { 
  unsigned long (FakeRTIambassador:: * pf)(unsigned long,char const *,unsigned long * const,class RTI::Region * * const,unsigned long); 
  void *p;
} u_RTI__RTIambassador__registerObjectInstanceWithRegion = { pf_RTI__RTIambassador__registerObjectInstanceWithRegion };

unsigned long
  (FakeRTIambassador:: * pf_RTI__RTIambassador__registerObjectInstanceWithRegionFull)(unsigned long,unsigned long * const,class RTI::Region * * const,unsigned long) = 
     &FakeRTIambassador::registerObjectInstanceWithRegion;
union { 
  unsigned long (FakeRTIambassador:: * pf)(unsigned long,unsigned long * const,class RTI::Region * * const,unsigned long); 
  void *p;
} u_RTI__RTIambassador__registerObjectInstanceWithRegionFull = { pf_RTI__RTIambassador__registerObjectInstanceWithRegionFull };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__requestClassAttributeValueUpdate)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::requestClassAttributeValueUpdate;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__requestClassAttributeValueUpdate = { pf_RTI__RTIambassador__requestClassAttributeValueUpdate };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion)(unsigned long,class RTI::AttributeHandleSet const &,class RTI::Region const &) = 
     &FakeRTIambassador::requestClassAttributeValueUpdateWithRegion;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &,class RTI::Region const &); 
  void *p;
} u_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion = { pf_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__requestFederationRestore)(char const *) = 
     &FakeRTIambassador::requestFederationRestore;
union { 
  void (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__requestFederationRestore = { pf_RTI__RTIambassador__requestFederationRestore };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__requestFederationSave)(char const *) = 
     &FakeRTIambassador::requestFederationSave;
union { 
  void (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__requestFederationSave = { pf_RTI__RTIambassador__requestFederationSave };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__requestFederationSaveFull)(char const *,class RTI::FedTime const &) = 
     &FakeRTIambassador::requestFederationSave;
union { 
  void (FakeRTIambassador:: * pf)(char const *,class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__requestFederationSaveFull = { pf_RTI__RTIambassador__requestFederationSaveFull };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__requestObjectAttributeValueUpdate)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::requestObjectAttributeValueUpdate;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__requestObjectAttributeValueUpdate = { pf_RTI__RTIambassador__requestObjectAttributeValueUpdate };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__resignFederationExecution)(enum RTI::ResignAction) = 
     &FakeRTIambassador::resignFederationExecution;
union { 
  void (FakeRTIambassador:: * pf)(enum RTI::ResignAction); 
  void *p;
} u_RTI__RTIambassador__resignFederationExecution = { pf_RTI__RTIambassador__resignFederationExecution };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__retract)(struct RTI::EventRetractionHandle_s) = 
     &FakeRTIambassador::retract;
union { 
  void (FakeRTIambassador:: * pf)(struct RTI::EventRetractionHandle_s); 
  void *p;
} u_RTI__RTIambassador__retract = { pf_RTI__RTIambassador__retract };

struct RTI::EventRetractionHandle_s
  (FakeRTIambassador:: * pf_RTI__RTIambassador__sendInteraction)(unsigned long,class RTI::ParameterHandleValuePairSet const &,class RTI::FedTime const &,char const *) = 
     &FakeRTIambassador::sendInteraction;
union { 
  struct RTI::EventRetractionHandle_s (FakeRTIambassador:: * pf)(unsigned long,class RTI::ParameterHandleValuePairSet const &,class RTI::FedTime const &,char const *); 
  void *p;
} u_RTI__RTIambassador__sendInteraction = { pf_RTI__RTIambassador__sendInteraction };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__sendInteractionFull)(unsigned long,class RTI::ParameterHandleValuePairSet const &,char const *) = 
     &FakeRTIambassador::sendInteraction;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::ParameterHandleValuePairSet const &,char const *); 
  void *p;
} u_RTI__RTIambassador__sendInteractionFull = { pf_RTI__RTIambassador__sendInteractionFull };

struct RTI::EventRetractionHandle_s
  (FakeRTIambassador:: * pf_RTI__RTIambassador__sendInteractionWithRegion)(unsigned long,class RTI::ParameterHandleValuePairSet const &,class RTI::FedTime const &,char const *,class RTI::Region const &) = 
     &FakeRTIambassador::sendInteractionWithRegion;
union { 
  struct RTI::EventRetractionHandle_s (FakeRTIambassador:: * pf)(unsigned long,class RTI::ParameterHandleValuePairSet const &,class RTI::FedTime const &,char const *,class RTI::Region const &); 
  void *p;
} u_RTI__RTIambassador__sendInteractionWithRegion = { pf_RTI__RTIambassador__sendInteractionWithRegion };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__sendInteractionWithRegionFull)(unsigned long,class RTI::ParameterHandleValuePairSet const &,char const *,class RTI::Region const &) = 
     &FakeRTIambassador::sendInteractionWithRegion;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::ParameterHandleValuePairSet const &,char const *,class RTI::Region const &); 
  void *p;
} u_RTI__RTIambassador__sendInteractionWithRegionFull = { pf_RTI__RTIambassador__sendInteractionWithRegionFull };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__subscribeInteractionClass)(unsigned long,enum RTI::Boolean) = 
     &FakeRTIambassador::subscribeInteractionClass;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,enum RTI::Boolean); 
  void *p;
} u_RTI__RTIambassador__subscribeInteractionClass = { pf_RTI__RTIambassador__subscribeInteractionClass };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__subscribeInteractionClassWithRegion)(unsigned long,class RTI::Region &,enum RTI::Boolean) = 
     &FakeRTIambassador::subscribeInteractionClassWithRegion;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::Region &,enum RTI::Boolean); 
  void *p;
} u_RTI__RTIambassador__subscribeInteractionClassWithRegion = { pf_RTI__RTIambassador__subscribeInteractionClassWithRegion };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__subscribeObjectClassAttributes)(unsigned long,class RTI::AttributeHandleSet const &,enum RTI::Boolean) = 
     &FakeRTIambassador::subscribeObjectClassAttributes;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &,enum RTI::Boolean); 
  void *p;
} u_RTI__RTIambassador__subscribeObjectClassAttributes = { pf_RTI__RTIambassador__subscribeObjectClassAttributes };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion)(unsigned long,class RTI::Region &,class RTI::AttributeHandleSet const &,enum RTI::Boolean) = 
     &FakeRTIambassador::subscribeObjectClassAttributesWithRegion;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::Region &,class RTI::AttributeHandleSet const &,enum RTI::Boolean); 
  void *p;
} u_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion = { pf_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__synchronizationPointAchieved)(char const *) = 
     &FakeRTIambassador::synchronizationPointAchieved;
union { 
  void (FakeRTIambassador:: * pf)(char const *); 
  void *p;
} u_RTI__RTIambassador__synchronizationPointAchieved = { pf_RTI__RTIambassador__synchronizationPointAchieved };

enum RTI::Boolean
  (FakeRTIambassador:: * pf_RTI__RTIambassador__tick)(double,double) = 
     &FakeRTIambassador::tick;
union { 
  enum RTI::Boolean (FakeRTIambassador:: * pf)(double,double); 
  void *p;
} u_RTI__RTIambassador__tick = { pf_RTI__RTIambassador__tick };

enum RTI::Boolean
  (FakeRTIambassador:: * pf_RTI__RTIambassador__tickFull)(void) = 
     &FakeRTIambassador::tick;
union { 
  enum RTI::Boolean (FakeRTIambassador:: * pf)(void); 
  void *p;
} u_RTI__RTIambassador__tickFull = { pf_RTI__RTIambassador__tickFull };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__timeAdvanceRequest)(class RTI::FedTime const &) = 
     &FakeRTIambassador::timeAdvanceRequest;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__timeAdvanceRequest = { pf_RTI__RTIambassador__timeAdvanceRequest };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__timeAdvanceRequestAvailable)(class RTI::FedTime const &) = 
     &FakeRTIambassador::timeAdvanceRequestAvailable;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::FedTime const &); 
  void *p;
} u_RTI__RTIambassador__timeAdvanceRequestAvailable = { pf_RTI__RTIambassador__timeAdvanceRequestAvailable };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unassociateRegionForUpdates)(class RTI::Region &,unsigned long) = 
     &FakeRTIambassador::unassociateRegionForUpdates;
union { 
  void (FakeRTIambassador:: * pf)(class RTI::Region &,unsigned long); 
  void *p;
} u_RTI__RTIambassador__unassociateRegionForUpdates = { pf_RTI__RTIambassador__unassociateRegionForUpdates };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture)(unsigned long,class RTI::AttributeHandleSet const &) = 
     &FakeRTIambassador::unconditionalAttributeOwnershipDivestiture;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleSet const &); 
  void *p;
} u_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture = { pf_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unpublishInteractionClass)(unsigned long) = 
     &FakeRTIambassador::unpublishInteractionClass;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__unpublishInteractionClass = { pf_RTI__RTIambassador__unpublishInteractionClass };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unpublishObjectClass)(unsigned long) = 
     &FakeRTIambassador::unpublishObjectClass;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__unpublishObjectClass = { pf_RTI__RTIambassador__unpublishObjectClass };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unsubscribeInteractionClass)(unsigned long) = 
     &FakeRTIambassador::unsubscribeInteractionClass;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__unsubscribeInteractionClass = { pf_RTI__RTIambassador__unsubscribeInteractionClass };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unsubscribeInteractionClassWithRegion)(unsigned long,class RTI::Region &) = 
     &FakeRTIambassador::unsubscribeInteractionClassWithRegion;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::Region &); 
  void *p;
} u_RTI__RTIambassador__unsubscribeInteractionClassWithRegion = { pf_RTI__RTIambassador__unsubscribeInteractionClassWithRegion };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unsubscribeObjectClass)(unsigned long) = 
     &FakeRTIambassador::unsubscribeObjectClass;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long); 
  void *p;
} u_RTI__RTIambassador__unsubscribeObjectClass = { pf_RTI__RTIambassador__unsubscribeObjectClass };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__unsubscribeObjectClassWithRegion)(unsigned long,class RTI::Region &) = 
     &FakeRTIambassador::unsubscribeObjectClassWithRegion;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::Region &); 
  void *p;
} u_RTI__RTIambassador__unsubscribeObjectClassWithRegion = { pf_RTI__RTIambassador__unsubscribeObjectClassWithRegion };

struct RTI::EventRetractionHandle_s
  (FakeRTIambassador:: * pf_RTI__RTIambassador__updateAttributeValues)(unsigned long,class RTI::AttributeHandleValuePairSet const &,class RTI::FedTime const &,char const *) = 
     &FakeRTIambassador::updateAttributeValues;
union { 
  struct RTI::EventRetractionHandle_s (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleValuePairSet const &,class RTI::FedTime const &,char const *); 
  void *p;
} u_RTI__RTIambassador__updateAttributeValues = { pf_RTI__RTIambassador__updateAttributeValues };

void
  (FakeRTIambassador:: * pf_RTI__RTIambassador__updateAttributeValuesFull)(unsigned long,class RTI::AttributeHandleValuePairSet const &,char const *) = 
     &FakeRTIambassador::updateAttributeValues;
union { 
  void (FakeRTIambassador:: * pf)(unsigned long,class RTI::AttributeHandleValuePairSet const &,char const *); 
  void *p;
} u_RTI__RTIambassador__updateAttributeValuesFull = { pf_RTI__RTIambassador__updateAttributeValuesFull };

