// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_RTIAmbassador.cpp,v $
// CVS $Date: 2006/02/24 12:55:16 $
// CVS $Revision: 1.3 $






// Automatically generated.  Edit at own risk!

#include "MATIS_Hook_RTI_13NG.h"


void

 MATIS_RTIAmbassador::createFederationExecution(RTI::RTIambassador *
                                                rtiAmb, const char
                                                *executionName,
                                                const char *FED)
throw(RTI::FederationExecutionAlreadyExists,
      RTI::CouldNotOpenFED,
      RTI::ErrorReadingFED,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__createFederationExecution2 != NULL) { 
        
#endif
        try {
#ifdef _WIN32

			rtiAmb->createFederationExecution(executionName, FED);
#else
            funcptr_RTI__RTIambassador__createFederationExecution2(
				rtiAmb,
				executionName,
				FED);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};



// user code
//
#include "Hook/RTI_createFederationExecution2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::destroyFederationExecution(RTI::RTIambassador *
                                                     rtiAmb, const char
                                                     *executionName)
throw(RTI::FederatesCurrentlyJoined,
      RTI::FederationExecutionDoesNotExist,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{
#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__destroyFederationExecution1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->destroyFederationExecution(executionName);
#else
            funcptr_RTI__RTIambassador__destroyFederationExecution1(rtiAmb,
                                                                    executionName);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_destroyFederationExecution1.cpp"


/////////////////////////////////////////////////////

RTI::FederateHandle MATIS_RTIAmbassador::joinFederationExecution(RTI::
                                                                 RTIambassador
                                                                 * rtiAmb,
                                                                 const
                                                                 char
                                                                 *yourName, const
                                                                 char
                                                                 *executionName,
                                                                 RTI::
                                                                 FederateAmbassadorPtr
                                                                 federateAmbassadorReference)
throw(RTI::FederateAlreadyExecutionMember,
      RTI::FederationExecutionDoesNotExist,
      RTI::CouldNotOpenFED,
      RTI::ErrorReadingFED,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__joinFederationExecution3 != NULL) {
#endif
        try {

#ifdef _WIN32
             return
             rtiAmb->joinFederationExecution(yourName, executionName,
                                             federateAmbassadorReference);

#else
            return
                funcptr_RTI__RTIambassador__joinFederationExecution3
                (rtiAmb, yourName, executionName,
                 federateAmbassadorReference);
#endif
        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return 0;
};

// user code
//
#include "Hook/RTI_joinFederationExecution3.cpp"


/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::resignFederationExecution(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    ResignAction theAction)
throw(RTI::FederateOwnsAttributes,
      RTI::FederateNotExecutionMember,
      RTI::InvalidResignAction,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__resignFederationExecution1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->resignFederationExecution(
                                                                   theAction);
#else
            funcptr_RTI__RTIambassador__resignFederationExecution1(rtiAmb,
                                                                   theAction);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};


// user code
//
#include "Hook/RTI_resignFederationExecution1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::registerFederationSynchronizationPoint(RTI::
                                                                 RTIambassador
                                                                 * rtiAmb,
                                                                 const char
                                                                 *label, const char
                                                                 *theTag)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint2
        != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->registerFederationSynchronizationPoint( label, theTag);
#else
            funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint2
                (rtiAmb, label, theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};


// user code
//
#include "Hook/RTI_registerFederationSynchronizationPoint2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::registerFederationSynchronizationPoint(RTI::
                                                                 RTIambassador
                                                                 * rtiAmb,
                                                                 const char
                                                                 *label, const char
                                                                 *theTag,
                                                                 const
                                                                 RTI::
                                                                 FederateHandleSet
                                                                 & syncSet)
throw(RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint3
        != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->registerFederationSynchronizationPoint( label, theTag, syncSet);
#else
            funcptr_RTI__RTIambassador__registerFederationSynchronizationPoint3
                (rtiAmb, label, theTag, syncSet);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_registerFederationSynchronizationPoint3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::synchronizationPointAchieved(RTI::RTIambassador *
                                                       rtiAmb,
                                                       const char *label)
throw(RTI::SynchronizationPointLabelWasNotAnnounced,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__synchronizationPointAchieved1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->synchronizationPointAchieved( label);
#else
            funcptr_RTI__RTIambassador__synchronizationPointAchieved1
                (rtiAmb, label);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_synchronizationPointAchieved1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::requestFederationSave(RTI::RTIambassador *
                                                rtiAmb, const char *label,
                                                const RTI::
                                                FedTime & theTime)
throw(RTI::FederationTimeAlreadyPassed, RTI::InvalidFederationTime,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__requestFederationSave2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->requestFederationSave(
                                                               label,
                                                               theTime);
#else
            funcptr_RTI__RTIambassador__requestFederationSave2(rtiAmb,
                                                               label,
                                                               theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_requestFederationSave2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::requestFederationSave(RTI::RTIambassador *
                                                rtiAmb,
                                                const char *label)
throw(RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__requestFederationSave1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->requestFederationSave(
                                                               label);
#else
            funcptr_RTI__RTIambassador__requestFederationSave1(rtiAmb,
                                                               label);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_requestFederationSave1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::federateSaveBegun(RTI::RTIambassador * rtiAmb)
throw(RTI::SaveNotInitiated,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__federateSaveBegun0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->federateSaveBegun();
#else
            funcptr_RTI__RTIambassador__federateSaveBegun0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_federateSaveBegun0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::federateSaveComplete(RTI::RTIambassador * rtiAmb)
throw(RTI::SaveNotInitiated,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__federateSaveComplete0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->federateSaveComplete();
#else
            funcptr_RTI__RTIambassador__federateSaveComplete0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_federateSaveComplete0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::federateSaveNotComplete(RTI::RTIambassador *
                                                  rtiAmb) throw(RTI::
                                                                SaveNotInitiated,
                                                                RTI::
                                                                FederateNotExecutionMember,
                                                                RTI::
                                                                ConcurrentAccessAttempted,
                                                                RTI::
                                                                RestoreInProgress,
                                                                RTI::
                                                                RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__federateSaveNotComplete0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->federateSaveNotComplete();
#else
            funcptr_RTI__RTIambassador__federateSaveNotComplete0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_federateSaveNotComplete0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::requestFederationRestore(RTI::RTIambassador *
                                                   rtiAmb,
                                                   const char *label)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__requestFederationRestore1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->requestFederationRestore(
                                                                  label);
#else
            funcptr_RTI__RTIambassador__requestFederationRestore1(rtiAmb,
                                                                  label);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_requestFederationRestore1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::federateRestoreComplete(RTI::RTIambassador *
                                                  rtiAmb) throw(RTI::
                                                                RestoreNotRequested,
                                                                RTI::
                                                                FederateNotExecutionMember,
                                                                RTI::
                                                                ConcurrentAccessAttempted,
                                                                RTI::
                                                                SaveInProgress,
                                                                RTI::
                                                                RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__federateRestoreComplete0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->federateRestoreComplete();
#else
            funcptr_RTI__RTIambassador__federateRestoreComplete0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_federateRestoreComplete0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::federateRestoreNotComplete(RTI::RTIambassador *
                                                     rtiAmb)
throw(RTI::RestoreNotRequested,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__federateRestoreNotComplete0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->federateRestoreNotComplete();
#else
            funcptr_RTI__RTIambassador__federateRestoreNotComplete0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_federateRestoreNotComplete0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::publishObjectClass(
	RTI::RTIambassador * rtiAmb,
	RTI::
	ObjectClassHandle theClass,
	const RTI::
	AttributeHandleSet &
	attributeList) 
	throw(RTI::
		  ObjectClassNotDefined,
		  RTI::
		  AttributeNotDefined,
		  RTI::
		  OwnershipAcquisitionPending,
		  RTI::
		  FederateNotExecutionMember,
		  RTI::
		  ConcurrentAccessAttempted,
		  RTI::
		  SaveInProgress,
		  RTI::
		  RestoreInProgress,
		  RTI::
		  RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__publishObjectClass2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->publishObjectClass(
                                                            theClass,
                                                            attributeList);
#else
            funcptr_RTI__RTIambassador__publishObjectClass2(rtiAmb,
                                                            theClass,
                                                            attributeList);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_publishObjectClass2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unpublishObjectClass(RTI::RTIambassador * rtiAmb,
                                               RTI::
                                               ObjectClassHandle theClass)
throw(RTI::ObjectClassNotDefined,
      RTI::ObjectClassNotPublished,
      RTI::OwnershipAcquisitionPending,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unpublishObjectClass1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unpublishObjectClass(
                                                              theClass);
#else
            funcptr_RTI__RTIambassador__unpublishObjectClass1(rtiAmb,
                                                              theClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unpublishObjectClass1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::publishInteractionClass(RTI::RTIambassador *
                                                  rtiAmb,
                                                  RTI::
                                                  InteractionClassHandle
                                                  theInteraction)
throw(RTI::InteractionClassNotDefined, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::SaveInProgress,
      RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__publishInteractionClass1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->publishInteractionClass(
                                                                 theInteraction);
#else
            funcptr_RTI__RTIambassador__publishInteractionClass1(rtiAmb,
                                                                 theInteraction);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_publishInteractionClass1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unpublishInteractionClass(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    InteractionClassHandle
                                                    theInteraction)
throw(RTI::InteractionClassNotDefined,
      RTI::InteractionClassNotPublished,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unpublishInteractionClass1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unpublishInteractionClass(
                                                                   theInteraction);
#else
            funcptr_RTI__RTIambassador__unpublishInteractionClass1(rtiAmb,
                                                                   theInteraction);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unpublishInteractionClass1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::subscribeObjectClassAttributes(RTI::
                                                         RTIambassador *
                                                         rtiAmb,
                                                         RTI::
                                                         ObjectClassHandle
                                                         theClass,
                                                         const RTI::
                                                         AttributeHandleSet
                                                         & attributeList,
                                                         RTI::
                                                         Boolean active)
throw(RTI::ObjectClassNotDefined,
      RTI::AttributeNotDefined,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__subscribeObjectClassAttributes3 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->subscribeObjectClassAttributes( theClass, attributeList, active);
#else
            funcptr_RTI__RTIambassador__subscribeObjectClassAttributes3
                (rtiAmb, theClass, attributeList, active);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_subscribeObjectClassAttributes3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unsubscribeObjectClass(RTI::RTIambassador *
                                                 rtiAmb,
                                                 RTI::ObjectClassHandle
                                                 theClass) throw(RTI::
                                                                 ObjectClassNotDefined,
                                                                 RTI::
                                                                 ObjectClassNotSubscribed,
                                                                 RTI::
                                                                 FederateNotExecutionMember,
                                                                 RTI::
                                                                 ConcurrentAccessAttempted,
                                                                 RTI::
                                                                 SaveInProgress,
                                                                 RTI::
                                                                 RestoreInProgress,
                                                                 RTI::
                                                                 RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unsubscribeObjectClass1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unsubscribeObjectClass(theClass);
#else
            funcptr_RTI__RTIambassador__unsubscribeObjectClass1(rtiAmb,
                                                                theClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unsubscribeObjectClass1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::subscribeInteractionClass(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    InteractionClassHandle
                                                    theClass,
                                                    RTI::Boolean active)
throw(RTI::InteractionClassNotDefined,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::FederateLoggingServiceCalls,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__subscribeInteractionClass2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->subscribeInteractionClass(theClass, active);
#else
            funcptr_RTI__RTIambassador__subscribeInteractionClass2(rtiAmb,
                                                                   theClass,
                                                                   active);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_subscribeInteractionClass2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unsubscribeInteractionClass(RTI::RTIambassador *
                                                      rtiAmb,
                                                      RTI::
                                                      InteractionClassHandle
                                                      theClass)
throw(RTI::InteractionClassNotDefined,
      RTI::InteractionClassNotSubscribed,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unsubscribeInteractionClass1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unsubscribeInteractionClass( theClass);
#else
            funcptr_RTI__RTIambassador__unsubscribeInteractionClass1
                (rtiAmb, theClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unsubscribeInteractionClass1.cpp"

/////////////////////////////////////////////////////

RTI::ObjectHandle MATIS_RTIAmbassador::registerObjectInstance(RTI::
                                                              RTIambassador
                                                              * rtiAmb,
                                                              RTI::
                                                              ObjectClassHandle
                                                              theClass,
                                                              const char
                                                              *theObject)
throw(RTI::ObjectClassNotDefined,
      RTI::ObjectClassNotPublished,
      RTI::ObjectAlreadyRegistered,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__registerObjectInstance2 != NULL) {
#endif
        try {
#ifdef _WIN32
	    return rtiAmb->registerObjectInstance(theClass, theObject);
#else
            return
                funcptr_RTI__RTIambassador__registerObjectInstance2(rtiAmb,
                                                                    theClass,
                                                                    theObject);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_registerObjectInstance2.cpp"

/////////////////////////////////////////////////////

RTI::ObjectHandle MATIS_RTIAmbassador::registerObjectInstance(RTI::
                                                              RTIambassador
                                                              * rtiAmb,
                                                              RTI::
                                                              ObjectClassHandle
                                                              theClass)
throw(RTI::ObjectClassNotDefined, RTI::ObjectClassNotPublished,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__registerObjectInstance1 != NULL) {
#endif
        try {
#ifdef _WIN32
		return	rtiAmb->registerObjectInstance(theClass);
#else
            return
                funcptr_RTI__RTIambassador__registerObjectInstance1(rtiAmb,
                                                                    theClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_registerObjectInstance1.cpp"

/////////////////////////////////////////////////////

RTI::EventRetractionHandle MATIS_RTIAmbassador::
updateAttributeValues(RTI::RTIambassador * rtiAmb,
                      RTI::ObjectHandle theObject,
                      const RTI::
                      AttributeHandleValuePairSet & theAttributes,
                      const RTI::FedTime & theTime,
                      const char *theTag)
throw(RTI::ObjectNotKnown,
      RTI::AttributeNotDefined,
      RTI::AttributeNotOwned,
      RTI::InvalidFederationTime,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__updateAttributeValues4 != NULL) {
#endif
        try {
#ifdef _WIN32
	   return		rtiAmb->
	     updateAttributeValues(theObject, theAttributes, theTime, theTag);
#else
            return
                funcptr_RTI__RTIambassador__updateAttributeValues4(rtiAmb,
                                                                   theObject,
                                                                   theAttributes,
                                                                   theTime,
                                                                   theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
		RTI::EventRetractionHandle_s dummy;
		return dummy; 
};

// user code
//
#include "Hook/RTI_updateAttributeValues4.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::updateAttributeValues(RTI::RTIambassador *
                                                rtiAmb,
                                                RTI::
                                                ObjectHandle theObject,
                                                const RTI::
                                                AttributeHandleValuePairSet
                                                & theAttributes,
                                                const char *theTag)
throw(RTI::ObjectNotKnown, RTI::AttributeNotDefined,
      RTI::AttributeNotOwned, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::SaveInProgress,
      RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__updateAttributeValues3 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->updateAttributeValues(
                                                               theObject,
                                                               theAttributes,
                                                               theTag);
#else
            funcptr_RTI__RTIambassador__updateAttributeValues3(rtiAmb,
                                                               theObject,
                                                               theAttributes,
                                                               theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_updateAttributeValues3.cpp"

/////////////////////////////////////////////////////

RTI::EventRetractionHandle MATIS_RTIAmbassador::sendInteraction(RTI::
                                                                RTIambassador
                                                                * rtiAmb,
                                                                RTI::
                                                                InteractionClassHandle
                                                                theInteraction,
                                                                const
                                                                RTI::
                                                                ParameterHandleValuePairSet
                                                                &
                                                                theParameters,
                                                                const
                                                                RTI::
                                                                FedTime &
                                                                theTime,
                                                                const char
                                                                *theTag)
throw(RTI::InteractionClassNotDefined,
      RTI::InteractionClassNotPublished,
      RTI::InteractionParameterNotDefined,
      RTI::InvalidFederationTime,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__sendInteraction4 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->sendInteraction(
                                                                theInteraction,
                                                                theParameters,
                                                                theTime,
                                                                theTag);
#else
            return funcptr_RTI__RTIambassador__sendInteraction4(rtiAmb,
                                                                theInteraction,
                                                                theParameters,
                                                                theTime,
                                                                theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	RTI::EventRetractionHandle_s bogus_eh;
	return bogus_eh;

};

// user code
//
#include "Hook/RTI_sendInteraction4.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::sendInteraction(RTI::RTIambassador * rtiAmb,
                                          RTI::
                                          InteractionClassHandle
                                          theInteraction,
                                          const RTI::
                                          ParameterHandleValuePairSet &
                                          theParameters,
                                          const char *theTag)
throw(RTI::InteractionClassNotDefined,
      RTI::InteractionClassNotPublished,
      RTI::InteractionParameterNotDefined,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__sendInteraction3 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->sendInteraction(
                                                         theInteraction,
                                                         theParameters,
                                                         theTag);
#else
            funcptr_RTI__RTIambassador__sendInteraction3(rtiAmb,
                                                         theInteraction,
                                                         theParameters,
                                                         theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_sendInteraction3.cpp"

/////////////////////////////////////////////////////

RTI::EventRetractionHandle MATIS_RTIAmbassador::deleteObjectInstance(RTI::
                                                                     RTIambassador
                                                                     *
                                                                     rtiAmb,
                                                                     RTI::
                                                                     ObjectHandle
                                                                     theObject,
                                                                     const
                                                                     RTI::
                                                                     FedTime
                                                                     &
                                                                     theTime,
                                                                     const
                                                                     char
                                                                     *theTag)
throw(RTI::ObjectNotKnown,
      RTI::DeletePrivilegeNotHeld,
      RTI::InvalidFederationTime,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__deleteObjectInstance3 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->deleteObjectInstance(
                                                                  theObject,
                                                                  theTime,
                                                                  theTag);
#else
            return
                funcptr_RTI__RTIambassador__deleteObjectInstance3(rtiAmb,
                                                                  theObject,
                                                                  theTime,
                                                                  theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
		RTI::EventRetractionHandle_s dummy;
		return dummy;  
};

// user code
//
#include "Hook/RTI_deleteObjectInstance3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::deleteObjectInstance(RTI::RTIambassador * rtiAmb,
                                               RTI::ObjectHandle theObject,
                                               const char *theTag)
throw(RTI::ObjectNotKnown,
      RTI::DeletePrivilegeNotHeld,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__deleteObjectInstance2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->deleteObjectInstance(
                                                              theObject,
                                                              theTag);
#else
            funcptr_RTI__RTIambassador__deleteObjectInstance2(rtiAmb,
                                                              theObject,
                                                              theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_deleteObjectInstance2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::localDeleteObjectInstance(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    ObjectHandle theObject)
throw(RTI::ObjectNotKnown,
      RTI::FederateOwnsAttributes,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__localDeleteObjectInstance1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->localDeleteObjectInstance(
                                                                   theObject);
#else
            funcptr_RTI__RTIambassador__localDeleteObjectInstance1(rtiAmb,
                                                                   theObject);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_localDeleteObjectInstance1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::changeAttributeTransportationType(RTI::
                                                            RTIambassador *
                                                            rtiAmb,
                                                            RTI::
                                                            ObjectHandle
                                                            theObject,
                                                            const RTI::
                                                            AttributeHandleSet
                                                            &
                                                            theAttributes,
                                                            RTI::
                                                            TransportationHandle
                                                            theType)
throw(RTI::ObjectNotKnown, RTI::AttributeNotDefined,
      RTI::AttributeNotOwned, RTI::InvalidTransportationHandle,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__changeAttributeTransportationType3 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->changeAttributeTransportationType( theObject, theAttributes, theType);
#else
            funcptr_RTI__RTIambassador__changeAttributeTransportationType3
                (rtiAmb, theObject, theAttributes, theType);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_changeAttributeTransportationType3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::changeInteractionTransportationType(RTI::
                                                              RTIambassador
                                                              * rtiAmb,
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
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__changeInteractionTransportationType2 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->changeInteractionTransportationType( theClass, theType);
#else
            funcptr_RTI__RTIambassador__changeInteractionTransportationType2
                (rtiAmb, theClass, theType);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_changeInteractionTransportationType2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::requestObjectAttributeValueUpdate(RTI::
                                                            RTIambassador *
                                                            rtiAmb,
                                                            RTI::
                                                            ObjectHandle
                                                            theObject,
                                                            const RTI::
                                                            AttributeHandleSet
                                                            &
                                                            theAttributes)
throw(RTI::ObjectNotKnown, RTI::AttributeNotDefined,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__requestObjectAttributeValueUpdate2 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->requestObjectAttributeValueUpdate( theObject, theAttributes);
#else
            funcptr_RTI__RTIambassador__requestObjectAttributeValueUpdate2
                (rtiAmb, theObject, theAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_requestObjectAttributeValueUpdate2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::requestClassAttributeValueUpdate(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           RTI::
                                                           ObjectClassHandle
                                                           theClass,
                                                           const RTI::
                                                           AttributeHandleSet
                                                           & theAttributes)
throw(RTI::ObjectClassNotDefined,
      RTI::AttributeNotDefined,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__requestClassAttributeValueUpdate2 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->requestClassAttributeValueUpdate( theClass, theAttributes);
#else
            funcptr_RTI__RTIambassador__requestClassAttributeValueUpdate2
                (rtiAmb, theClass, theAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_requestClassAttributeValueUpdate2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unconditionalAttributeOwnershipDivestiture(RTI::
                                                                     RTIambassador
                                                                     *
                                                                     rtiAmb,
                                                                     RTI::
                                                                     ObjectHandle
                                                                     theObject,
                                                                     const
                                                                     RTI::
                                                                     AttributeHandleSet
                                                                     &
                                                                     theAttributes)
throw(RTI::ObjectNotKnown,
      RTI::AttributeNotDefined,
      RTI::AttributeNotOwned,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unconditionalAttributeOwnershipDivestiture( theObject, theAttributes);
#else
            funcptr_RTI__RTIambassador__unconditionalAttributeOwnershipDivestiture2
                (rtiAmb, theObject, theAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unconditionalAttributeOwnershipDivestiture2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::negotiatedAttributeOwnershipDivestiture(RTI::
                                                                  RTIambassador
                                                                  * rtiAmb,
                                                                  RTI::
                                                                  ObjectHandle
                                                                  theObject,
                                                                  const
                                                                  RTI::
                                                                  AttributeHandleSet
                                                                  &
                                                                  theAttributes,
                                                                  const
                                                                  char
                                                                  *theTag)
throw(RTI::ObjectNotKnown, RTI::AttributeNotDefined,
      RTI::AttributeNotOwned, RTI::AttributeAlreadyBeingDivested,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture3 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->negotiatedAttributeOwnershipDivestiture( theObject, theAttributes, theTag);
#else
            funcptr_RTI__RTIambassador__negotiatedAttributeOwnershipDivestiture3
                (rtiAmb, theObject, theAttributes, theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_negotiatedAttributeOwnershipDivestiture3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::attributeOwnershipAcquisition(RTI::
                                                        RTIambassador *
                                                        rtiAmb,
                                                        RTI::ObjectHandle
                                                        theObject,
                                                        const RTI::
                                                        AttributeHandleSet
                                                        &
                                                        desiredAttributes,
                                                        const char *theTag)
throw(RTI::ObjectNotKnown, RTI::ObjectClassNotPublished,
      RTI::AttributeNotDefined, RTI::AttributeNotPublished,
      RTI::FederateOwnsAttributes, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::SaveInProgress,
      RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__attributeOwnershipAcquisition3 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->attributeOwnershipAcquisition( theObject, desiredAttributes, theTag);
#else
            funcptr_RTI__RTIambassador__attributeOwnershipAcquisition3
                (rtiAmb, theObject, desiredAttributes, theTag);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_attributeOwnershipAcquisition3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::attributeOwnershipAcquisitionIfAvailable(RTI::
                                                                   RTIambassador
                                                                   *
                                                                   rtiAmb,
                                                                   RTI::
                                                                   ObjectHandle
                                                                   theObject,
                                                                   const
                                                                   RTI::
                                                                   AttributeHandleSet
                                                                   &
                                                                   desiredAttributes)
throw(RTI::ObjectNotKnown, RTI::ObjectClassNotPublished,
      RTI::AttributeNotDefined, RTI::AttributeNotPublished,
      RTI::FederateOwnsAttributes, RTI::AttributeAlreadyBeingAcquired,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->attributeOwnershipAcquisitionIfAvailable( theObject, desiredAttributes);
#else
            funcptr_RTI__RTIambassador__attributeOwnershipAcquisitionIfAvailable2
                (rtiAmb, theObject, desiredAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_attributeOwnershipAcquisitionIfAvailable2.cpp"

/////////////////////////////////////////////////////

RTI::AttributeHandleSet *
    MATIS_RTIAmbassador::attributeOwnershipReleaseResponse(RTI::
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
      RTI::FederateWasNotAskedToReleaseAttribute,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__attributeOwnershipReleaseResponse2 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->attributeOwnershipReleaseResponse( theObject, theAttributes);
#else
            return
                funcptr_RTI__RTIambassador__attributeOwnershipReleaseResponse2
                (rtiAmb, theObject, theAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_attributeOwnershipReleaseResponse2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::
cancelNegotiatedAttributeOwnershipDivestiture(RTI::RTIambassador * rtiAmb,
                                              RTI::ObjectHandle theObject,
                                              const
                                              RTI::
                                              AttributeHandleSet
                                              & theAttributes)
throw(RTI::ObjectNotKnown,
      RTI::AttributeNotDefined,
      RTI::AttributeNotOwned,
      RTI::AttributeDivestitureWasNotRequested,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture2 != NULL) {
#endif
        try {
#ifdef _WIN32
	  rtiAmb->
			  cancelNegotiatedAttributeOwnershipDivestiture( theObject, theAttributes);
#else
            funcptr_RTI__RTIambassador__cancelNegotiatedAttributeOwnershipDivestiture2
                (rtiAmb, theObject, theAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_cancelNegotiatedAttributeOwnershipDivestiture2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::cancelAttributeOwnershipAcquisition(RTI::
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
      RTI::AttributeAlreadyOwned,
      RTI::AttributeAcquisitionWasNotRequested,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__cancelAttributeOwnershipAcquisition2 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->cancelAttributeOwnershipAcquisition( theObject, theAttributes);
#else
            funcptr_RTI__RTIambassador__cancelAttributeOwnershipAcquisition2
                (rtiAmb, theObject, theAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};


// user code
//
#include "Hook/RTI_cancelAttributeOwnershipAcquisition2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::queryAttributeOwnership(RTI::RTIambassador *
                                                  rtiAmb,
                                                  RTI::
                                                  ObjectHandle theObject,
                                                  RTI::AttributeHandle
                                                  theAttribute) throw(RTI::
                                                                      ObjectNotKnown,
                                                                      RTI::
                                                                      AttributeNotDefined,
                                                                      RTI::
                                                                      FederateNotExecutionMember,
                                                                      RTI::
                                                                      ConcurrentAccessAttempted,
                                                                      RTI::
                                                                      SaveInProgress,
                                                                      RTI::
                                                                      RestoreInProgress,
                                                                      RTI::
                                                                      RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__queryAttributeOwnership2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->queryAttributeOwnership(
                                                                 theObject,
                                                                 theAttribute);
#else
            funcptr_RTI__RTIambassador__queryAttributeOwnership2(rtiAmb,
                                                                 theObject,
                                                                 theAttribute);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_queryAttributeOwnership2.cpp"

/////////////////////////////////////////////////////

RTI::Boolean MATIS_RTIAmbassador::isAttributeOwnedByFederate(RTI::
                                                             RTIambassador
                                                             * rtiAmb,
                                                             RTI::
                                                             ObjectHandle
                                                             theObject,
                                                             RTI::
                                                             AttributeHandle
                                                             theAttribute)
throw(RTI::ObjectNotKnown, RTI::AttributeNotDefined,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__isAttributeOwnedByFederate2 != NULL) {
#endif
        try {
#ifdef _WIN32
	  return rtiAmb->isAttributeOwnedByFederate( theObject, theAttribute);
#else
            return
                funcptr_RTI__RTIambassador__isAttributeOwnedByFederate2
                (rtiAmb, theObject, theAttribute);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here");
	return RTI::RTI_FALSE;
};

// user code
//
#include "Hook/RTI_isAttributeOwnedByFederate2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::enableTimeRegulation(RTI::RTIambassador * rtiAmb,
                                               const RTI::
                                               FedTime & theFederateTime,
                                               const RTI::
                                               FedTime & theLookahead)
throw(RTI::TimeRegulationAlreadyEnabled,
      RTI::EnableTimeRegulationPending,
      RTI::TimeAdvanceAlreadyInProgress,
      RTI::InvalidFederationTime,
      RTI::InvalidLookahead,
      RTI::ConcurrentAccessAttempted,
      RTI::FederateNotExecutionMember,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__enableTimeRegulation2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->enableTimeRegulation(
                                                              theFederateTime,
                                                              theLookahead);
#else
            funcptr_RTI__RTIambassador__enableTimeRegulation2(rtiAmb,
                                                              theFederateTime,
                                                              theLookahead);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_enableTimeRegulation2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::disableTimeRegulation(RTI::RTIambassador *
                                                rtiAmb) throw(RTI::
                                                              TimeRegulationWasNotEnabled,
                                                              RTI::
                                                              ConcurrentAccessAttempted,
                                                              RTI::
                                                              FederateNotExecutionMember,
                                                              RTI::
                                                              SaveInProgress,
                                                              RTI::
                                                              RestoreInProgress,
                                                              RTI::
                                                              RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__disableTimeRegulation0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->disableTimeRegulation();
#else
            funcptr_RTI__RTIambassador__disableTimeRegulation0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_disableTimeRegulation0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::enableTimeConstrained(RTI::RTIambassador *
                                                rtiAmb) throw(RTI::
                                                              TimeConstrainedAlreadyEnabled,
                                                              RTI::
                                                              EnableTimeConstrainedPending,
                                                              RTI::
                                                              TimeAdvanceAlreadyInProgress,
                                                              RTI::
                                                              FederateNotExecutionMember,
                                                              RTI::
                                                              ConcurrentAccessAttempted,
                                                              RTI::
                                                              SaveInProgress,
                                                              RTI::
                                                              RestoreInProgress,
                                                              RTI::
                                                              RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__enableTimeConstrained0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->enableTimeConstrained();
#else
            funcptr_RTI__RTIambassador__enableTimeConstrained0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_enableTimeConstrained0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::disableTimeConstrained(RTI::RTIambassador *
                                                 rtiAmb) throw(RTI::
                                                               TimeConstrainedWasNotEnabled,
                                                               RTI::
                                                               FederateNotExecutionMember,
                                                               RTI::
                                                               ConcurrentAccessAttempted,
                                                               RTI::
                                                               SaveInProgress,
                                                               RTI::
                                                               RestoreInProgress,
                                                               RTI::
                                                               RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__disableTimeConstrained0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->disableTimeConstrained();
#else
            funcptr_RTI__RTIambassador__disableTimeConstrained0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_disableTimeConstrained0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::timeAdvanceRequest(RTI::RTIambassador * rtiAmb,
                                             const RTI::FedTime & theTime)
throw(RTI::InvalidFederationTime,
      RTI::FederationTimeAlreadyPassed,
      RTI::TimeAdvanceAlreadyInProgress,
      RTI::EnableTimeRegulationPending,
      RTI::EnableTimeConstrainedPending,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__timeAdvanceRequest1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->timeAdvanceRequest(
                                                            theTime);
#else
            funcptr_RTI__RTIambassador__timeAdvanceRequest1(rtiAmb,
                                                            theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_timeAdvanceRequest1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::timeAdvanceRequestAvailable(RTI::RTIambassador *
                                                      rtiAmb,
                                                      const RTI::
                                                      FedTime & theTime)
throw(RTI::InvalidFederationTime,
      RTI::FederationTimeAlreadyPassed,
      RTI::TimeAdvanceAlreadyInProgress,
      RTI::EnableTimeRegulationPending,
      RTI::EnableTimeConstrainedPending,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__timeAdvanceRequestAvailable1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->timeAdvanceRequestAvailable( theTime);
#else
            funcptr_RTI__RTIambassador__timeAdvanceRequestAvailable1
                (rtiAmb, theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_timeAdvanceRequestAvailable1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::nextEventRequest(RTI::RTIambassador * rtiAmb,
                                           const RTI::FedTime & theTime)
throw(RTI::InvalidFederationTime,
      RTI::FederationTimeAlreadyPassed,
      RTI::TimeAdvanceAlreadyInProgress,
      RTI::EnableTimeRegulationPending,
      RTI::EnableTimeConstrainedPending,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__nextEventRequest1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->nextEventRequest( theTime);
#else
            funcptr_RTI__RTIambassador__nextEventRequest1(rtiAmb, theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code

//
#include "Hook/RTI_nextEventRequest1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::nextEventRequestAvailable(RTI::RTIambassador *
                                                    rtiAmb,
                                                    const RTI::
                                                    FedTime & theTime)
throw(RTI::InvalidFederationTime,
      RTI::FederationTimeAlreadyPassed,
      RTI::TimeAdvanceAlreadyInProgress,
      RTI::EnableTimeRegulationPending,
      RTI::EnableTimeConstrainedPending,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__nextEventRequestAvailable1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->nextEventRequestAvailable(
                                                                   theTime);
#else
            funcptr_RTI__RTIambassador__nextEventRequestAvailable1(rtiAmb,
                                                                   theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_nextEventRequestAvailable1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::flushQueueRequest(RTI::RTIambassador * rtiAmb,
                                            const RTI::FedTime & theTime)
throw(RTI::InvalidFederationTime,
      RTI::FederationTimeAlreadyPassed,
      RTI::TimeAdvanceAlreadyInProgress,
      RTI::EnableTimeRegulationPending,
      RTI::EnableTimeConstrainedPending,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__flushQueueRequest1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->flushQueueRequest(
                                                           theTime);
#else
            funcptr_RTI__RTIambassador__flushQueueRequest1(rtiAmb,
                                                           theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_flushQueueRequest1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::enableAsynchronousDelivery(RTI::RTIambassador *
                                                     rtiAmb)
throw(RTI::AsynchronousDeliveryAlreadyEnabled,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__enableAsynchronousDelivery0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->enableAsynchronousDelivery();
#else
            funcptr_RTI__RTIambassador__enableAsynchronousDelivery0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_enableAsynchronousDelivery0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::disableAsynchronousDelivery(RTI::RTIambassador *
                                                      rtiAmb)
throw(RTI::AsynchronousDeliveryAlreadyDisabled,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__disableAsynchronousDelivery0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->disableAsynchronousDelivery();
#else
            funcptr_RTI__RTIambassador__disableAsynchronousDelivery0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_disableAsynchronousDelivery0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::queryLBTS(RTI::RTIambassador * rtiAmb,
                                    RTI::FedTime & theTime)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__queryLBTS1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->queryLBTS( theTime);
#else
            funcptr_RTI__RTIambassador__queryLBTS1(rtiAmb, theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_queryLBTS1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::queryFederateTime(RTI::RTIambassador * rtiAmb,
                                            RTI::FedTime & theTime)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__queryFederateTime1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->queryFederateTime(
                                                           theTime);
#else
            funcptr_RTI__RTIambassador__queryFederateTime1(rtiAmb,
                                                           theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_queryFederateTime1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::queryMinNextEventTime(RTI::RTIambassador *
                                                rtiAmb,
                                                RTI::
                                                FedTime & theTime)
throw(RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__queryMinNextEventTime1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->queryMinNextEventTime(
                                                               theTime);
#else
            funcptr_RTI__RTIambassador__queryMinNextEventTime1(rtiAmb,
                                                               theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_queryMinNextEventTime1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::modifyLookahead(RTI::RTIambassador * rtiAmb,
                                          const RTI::
                                          FedTime & theLookahead)
throw(RTI::InvalidLookahead, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::SaveInProgress,
      RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__modifyLookahead1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->modifyLookahead(
                                                         theLookahead);
#else
            funcptr_RTI__RTIambassador__modifyLookahead1(rtiAmb,
                                                         theLookahead);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_modifyLookahead1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::queryLookahead(RTI::RTIambassador * rtiAmb,
                                         RTI::FedTime & theTime)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__queryLookahead1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->queryLookahead( theTime);
#else
            funcptr_RTI__RTIambassador__queryLookahead1(rtiAmb, theTime);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_queryLookahead1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::retract(RTI::RTIambassador * rtiAmb,
                                  RTI::EventRetractionHandle theHandle)
throw(RTI::InvalidRetractionHandle,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__retract1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->retract( theHandle);
#else
            funcptr_RTI__RTIambassador__retract1(rtiAmb, theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_retract1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::changeAttributeOrderType(RTI::RTIambassador *
                                                   rtiAmb,
                                                   RTI::
                                                   ObjectHandle theObject,
                                                   const RTI::
                                                   AttributeHandleSet &
                                                   theAttributes,
                                                   RTI::
                                                   OrderingHandle theType)
throw(RTI::ObjectNotKnown,
      RTI::AttributeNotDefined,
      RTI::AttributeNotOwned,
      RTI::InvalidOrderingHandle,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__changeAttributeOrderType3 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->changeAttributeOrderType(
                                                                  theObject,
                                                                  theAttributes,
                                                                  theType);
#else
            funcptr_RTI__RTIambassador__changeAttributeOrderType3(rtiAmb,
                                                                  theObject,
                                                                  theAttributes,
                                                                  theType);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_changeAttributeOrderType3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::changeInteractionOrderType(RTI::RTIambassador *
                                                     rtiAmb,
                                                     RTI::
                                                     InteractionClassHandle
                                                     theClass,
                                                     RTI::
                                                     OrderingHandle
                                                     theType) throw(RTI::
                                                                    InteractionClassNotDefined,
                                                                    RTI::
                                                                    InteractionClassNotPublished,
                                                                    RTI::
                                                                    InvalidOrderingHandle,
                                                                    RTI::
                                                                    FederateNotExecutionMember,
                                                                    RTI::
                                                                    ConcurrentAccessAttempted,
                                                                    RTI::
                                                                    SaveInProgress,
                                                                    RTI::
                                                                    RestoreInProgress,
                                                                    RTI::
                                                                    RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__changeInteractionOrderType2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->changeInteractionOrderType(
                                                                    theClass,
                                                                    theType);
#else
            funcptr_RTI__RTIambassador__changeInteractionOrderType2(rtiAmb,
                                                                    theClass,
                                                                    theType);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_changeInteractionOrderType2.cpp"

/////////////////////////////////////////////////////

RTI::Region * MATIS_RTIAmbassador::createRegion(RTI::RTIambassador *
                                                rtiAmb,
                                                RTI::SpaceHandle theSpace,
                                                RTI::ULong numberOfExtents)
throw(RTI::SpaceNotDefined, RTI::InvalidExtents,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__createRegion2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->createRegion(
                                                             theSpace,
                                                             numberOfExtents);
#else
            return funcptr_RTI__RTIambassador__createRegion2(rtiAmb,
                                                             theSpace,
                                                             numberOfExtents);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_createRegion2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::notifyAboutRegionModification(RTI::
                                                        RTIambassador *
                                                        rtiAmb,
                                                        RTI::Region &
                                                        theRegion)
throw(RTI::RegionNotKnown, RTI::InvalidExtents,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__notifyAboutRegionModification1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->notifyAboutRegionModification( theRegion);
#else
            funcptr_RTI__RTIambassador__notifyAboutRegionModification1
                (rtiAmb, theRegion);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_notifyAboutRegionModification1.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::deleteRegion(RTI::RTIambassador * rtiAmb,
                                       RTI::Region * theRegion)
throw(RTI::RegionNotKnown,
      RTI::RegionInUse,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__deleteRegion1 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->deleteRegion( theRegion);
#else
            funcptr_RTI__RTIambassador__deleteRegion1(rtiAmb, theRegion);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_deleteRegion1.cpp"

/////////////////////////////////////////////////////

RTI::ObjectHandle MATIS_RTIAmbassador::
registerObjectInstanceWithRegion(RTI::RTIambassador * rtiAmb,
                                 RTI::ObjectClassHandle theClass,
                                 const char *theObject,
                                 RTI::AttributeHandle theAttributes[],
                                 RTI::Region * theRegions[],
                                 RTI::ULong theNumberOfHandles)
throw(RTI::ObjectClassNotDefined,
      RTI::ObjectClassNotPublished,
      RTI::AttributeNotDefined,
      RTI::AttributeNotPublished,
      RTI::RegionNotKnown,
      RTI::InvalidRegionContext,
      RTI::ObjectAlreadyRegistered,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion5 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
	  return rtiAmb->
	    registerObjectInstanceWithRegion( theClass, theObject, theAttributes, theRegions,
					      theNumberOfHandles);
#else
            return
                funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion5
                (rtiAmb, theClass, theObject, theAttributes, theRegions,
                 theNumberOfHandles);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_registerObjectInstanceWithRegion5.cpp"

/////////////////////////////////////////////////////

RTI::ObjectHandle MATIS_RTIAmbassador::
registerObjectInstanceWithRegion(RTI::RTIambassador * rtiAmb,
                                 RTI::ObjectClassHandle theClass,
                                 RTI::AttributeHandle theAttributes[],
                                 RTI::Region * theRegions[],
                                 RTI::ULong theNumberOfHandles)
throw(RTI::ObjectClassNotDefined, RTI::ObjectClassNotPublished,
      RTI::AttributeNotDefined, RTI::AttributeNotPublished,
      RTI::RegionNotKnown, RTI::InvalidRegionContext,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion4 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
	  return rtiAmb->
	    registerObjectInstanceWithRegion( theClass, theAttributes, theRegions,
							   theNumberOfHandles);
#else
            return
                funcptr_RTI__RTIambassador__registerObjectInstanceWithRegion4
                (rtiAmb, theClass, theAttributes, theRegions,
                 theNumberOfHandles);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_registerObjectInstanceWithRegion4.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::associateRegionForUpdates(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    Region & theRegion,
                                                    RTI::ObjectHandle
                                                    theObject,
                                                    const RTI::
                                                    AttributeHandleSet &
                                                    theAttributes)
throw(RTI::ObjectNotKnown, RTI::AttributeNotDefined,
      RTI::InvalidRegionContext, RTI::RegionNotKnown,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__associateRegionForUpdates3 != NULL) {
#endif
        try {
#ifdef _WIN32
	  rtiAmb->associateRegionForUpdates(
					    theRegion,
					    theObject,
					    theAttributes);
#else
            funcptr_RTI__RTIambassador__associateRegionForUpdates3(rtiAmb,
                                                                   theRegion,
                                                                   theObject,
                                                                   theAttributes);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_associateRegionForUpdates3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unassociateRegionForUpdates(RTI::RTIambassador *
                                                      rtiAmb,
                                                      RTI::
                                                      Region & theRegion,
                                                      RTI::
                                                      ObjectHandle
                                                      theObject)
throw(RTI::ObjectNotKnown,
      RTI::InvalidRegionContext,
      RTI::RegionNotKnown,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unassociateRegionForUpdates2 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unassociateRegionForUpdates( theRegion, theObject);
#else
            funcptr_RTI__RTIambassador__unassociateRegionForUpdates2
                (rtiAmb, theRegion, theObject);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unassociateRegionForUpdates2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::subscribeObjectClassAttributesWithRegion(RTI::
                                                                   RTIambassador
                                                                   *
                                                                   rtiAmb,
                                                                   RTI::
                                                                   ObjectClassHandle
                                                                   theClass,
                                                                   RTI::
                                                                   Region &
                                                                   theRegion,
                                                                   const
                                                                   RTI::
                                                                   AttributeHandleSet
                                                                   &
                                                                   attributeList,
                                                                   RTI::
                                                                   Boolean
                                                                   active)
throw(RTI::ObjectClassNotDefined, RTI::AttributeNotDefined,
      RTI::RegionNotKnown, RTI::InvalidRegionContext,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion4 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->subscribeObjectClassAttributesWithRegion( theClass, theRegion, attributeList, active);
#else
            funcptr_RTI__RTIambassador__subscribeObjectClassAttributesWithRegion4
                (rtiAmb, theClass, theRegion, attributeList, active);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_subscribeObjectClassAttributesWithRegion4.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unsubscribeObjectClassWithRegion(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           RTI::
                                                           ObjectClassHandle
                                                           theClass,
                                                           RTI::
                                                           Region &
                                                           theRegion)
throw(RTI::ObjectClassNotDefined,
      RTI::RegionNotKnown,
      RTI::ObjectClassNotSubscribed,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unsubscribeObjectClassWithRegion2 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unsubscribeObjectClassWithRegion( theClass, theRegion);
#else
            funcptr_RTI__RTIambassador__unsubscribeObjectClassWithRegion2
                (rtiAmb, theClass, theRegion);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unsubscribeObjectClassWithRegion2.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::subscribeInteractionClassWithRegion(RTI::
                                                              RTIambassador
                                                              * rtiAmb,
                                                              RTI::
                                                              InteractionClassHandle
                                                              theClass,
                                                              RTI::
                                                              Region &
                                                              theRegion,
                                                              RTI::
                                                              Boolean
                                                              active)
throw(RTI::InteractionClassNotDefined,
      RTI::RegionNotKnown,
      RTI::InvalidRegionContext,
      RTI::FederateLoggingServiceCalls,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__subscribeInteractionClassWithRegion3 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->subscribeInteractionClassWithRegion( theClass, theRegion, active);
#else
            funcptr_RTI__RTIambassador__subscribeInteractionClassWithRegion3
                (rtiAmb, theClass, theRegion, active);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_subscribeInteractionClassWithRegion3.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::unsubscribeInteractionClassWithRegion(RTI::
                                                                RTIambassador
                                                                * rtiAmb,
                                                                RTI::
                                                                InteractionClassHandle
                                                                theClass,
                                                                RTI::
                                                                Region &
                                                                theRegion)
throw(RTI::InteractionClassNotDefined,
      RTI::InteractionClassNotSubscribed,
      RTI::RegionNotKnown,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__unsubscribeInteractionClassWithRegion2
        != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->unsubscribeInteractionClassWithRegion( theClass, theRegion);
#else
            funcptr_RTI__RTIambassador__unsubscribeInteractionClassWithRegion2
                (rtiAmb, theClass, theRegion);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_unsubscribeInteractionClassWithRegion2.cpp"

/////////////////////////////////////////////////////

RTI::EventRetractionHandle MATIS_RTIAmbassador::
sendInteractionWithRegion(RTI::RTIambassador * rtiAmb,
                          RTI::InteractionClassHandle theInteraction,
                          const RTI::
                          ParameterHandleValuePairSet & theParameters,
                          const RTI::FedTime & theTime,
                          const char *theTag,
                          const RTI::Region & theRegion)
throw(RTI::InteractionClassNotDefined,
      RTI::InteractionClassNotPublished,
      RTI::InteractionParameterNotDefined,
      RTI::InvalidFederationTime,
      RTI::RegionNotKnown,
      RTI::InvalidRegionContext,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__sendInteractionWithRegion5 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->
sendInteractionWithRegion( theInteraction, theParameters, theTime, theTag,
                 theRegion);
#else
            return
                funcptr_RTI__RTIambassador__sendInteractionWithRegion5
                (rtiAmb, theInteraction, theParameters, theTime, theTag,
                 theRegion);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here");
	RTI::EventRetractionHandle_s dummy;
	return dummy; 
};

// user code
//
#include "Hook/RTI_sendInteractionWithRegion5.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::sendInteractionWithRegion(RTI::RTIambassador *
                                                    rtiAmb,
                                                    RTI::
                                                    InteractionClassHandle
                                                    theInteraction,
                                                    const RTI::
                                                    ParameterHandleValuePairSet
                                                    & theParameters,
                                                    const char *theTag,
                                                    const RTI::
                                                    Region & theRegion)
throw(RTI::InteractionClassNotDefined,
      RTI::InteractionClassNotPublished,
      RTI::InteractionParameterNotDefined,
      RTI::RegionNotKnown,
      RTI::InvalidRegionContext,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__sendInteractionWithRegion4 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->sendInteractionWithRegion(
                                                                   theInteraction,
                                                                   theParameters,
                                                                   theTag,
                                                                   theRegion);
#else
            funcptr_RTI__RTIambassador__sendInteractionWithRegion4(rtiAmb,
                                                                   theInteraction,
                                                                   theParameters,
                                                                   theTag,
                                                                   theRegion);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_sendInteractionWithRegion4.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::requestClassAttributeValueUpdateWithRegion(RTI::
                                                                     RTIambassador
                                                                     *
                                                                     rtiAmb,
                                                                     RTI::
                                                                     ObjectClassHandle
                                                                     theClass,
                                                                     const
                                                                     RTI::
                                                                     AttributeHandleSet
                                                                     &
                                                                     theAttributes,
                                                                     const
                                                                     RTI::
                                                                     Region
                                                                     &
                                                                     theRegion)
throw(RTI::ObjectClassNotDefined,
      RTI::AttributeNotDefined,
      RTI::RegionNotKnown,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion3 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->requestClassAttributeValueUpdateWithRegion( theClass, theAttributes, theRegion);
#else
            funcptr_RTI__RTIambassador__requestClassAttributeValueUpdateWithRegion3
                (rtiAmb, theClass, theAttributes, theRegion);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_requestClassAttributeValueUpdateWithRegion3.cpp"

/////////////////////////////////////////////////////

RTI::ObjectClassHandle MATIS_RTIAmbassador::getObjectClassHandle(RTI::
                                                                 RTIambassador
                                                                 * rtiAmb,
                                                                 const
                                                                 char
                                                                 *theName)
throw(RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getObjectClassHandle1 != NULL) {
#endif
        try {
#ifdef _WIN32
		return	rtiAmb->getObjectClassHandle(
                                                                  theName);
#else
            return
                funcptr_RTI__RTIambassador__getObjectClassHandle1(rtiAmb,
                                                                  theName);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_getObjectClassHandle1.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getObjectClassName(RTI::RTIambassador * rtiAmb,
                                              RTI::
                                              ObjectClassHandle theHandle)
throw(RTI::ObjectClassNotDefined, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getObjectClassName1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getObjectClassName(
                                                                   theHandle);
#else
            return funcptr_RTI__RTIambassador__getObjectClassName1(rtiAmb,
                                                                   theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	
	LOGERR("Shouldn't get here\n");
	return NULL;

};

// user code
//
#include "Hook/RTI_getObjectClassName1.cpp"

/////////////////////////////////////////////////////

RTI::AttributeHandle MATIS_RTIAmbassador::getAttributeHandle(RTI::
                                                             RTIambassador
                                                             * rtiAmb,
                                                             const char
                                                             *theName,
                                                             RTI::
                                                             ObjectClassHandle
                                                             whichClass)
throw(RTI::ObjectClassNotDefined,
      RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getAttributeHandle2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getAttributeHandle(
                                                                   theName,
                                                                   whichClass);
#else
            return funcptr_RTI__RTIambassador__getAttributeHandle2(rtiAmb,
                                                                   theName,
                                                                   whichClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return 0;

};

// user code
//
#include "Hook/RTI_getAttributeHandle2.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getAttributeName(RTI::RTIambassador * rtiAmb,
                                            RTI::AttributeHandle theHandle,
                                            RTI::
                                            ObjectClassHandle whichClass)
throw(RTI::ObjectClassNotDefined, RTI::AttributeNotDefined,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getAttributeName2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getAttributeName(
                                                                 theHandle,
                                                                 whichClass);
#else
            return funcptr_RTI__RTIambassador__getAttributeName2(rtiAmb,
                                                                 theHandle,
                                                                 whichClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return NULL;

};

// user code
//
#include "Hook/RTI_getAttributeName2.cpp"

/////////////////////////////////////////////////////

RTI::InteractionClassHandle MATIS_RTIAmbassador::
getInteractionClassHandle(RTI::RTIambassador * rtiAmb, const char *theName)
throw(RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getInteractionClassHandle1 != NULL) {
#endif
        try {
#ifdef _WIN32
		return 	rtiAmb->
		  getInteractionClassHandle( theName);
#else
            return
                funcptr_RTI__RTIambassador__getInteractionClassHandle1
                (rtiAmb, theName);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_getInteractionClassHandle1.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getInteractionClassName(RTI::RTIambassador *
                                                   rtiAmb,
                                                   RTI::
                                                   InteractionClassHandle
                                                   theHandle) throw(RTI::
                                                                    InteractionClassNotDefined,
                                                                    RTI::
                                                                    FederateNotExecutionMember,
                                                                    RTI::
                                                                    ConcurrentAccessAttempted,
                                                                    RTI::
                                                                    RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getInteractionClassName1 != NULL) {
#endif
        try {
#ifdef _WIN32
		return	rtiAmb->getInteractionClassName( theHandle);
#else
            return
                funcptr_RTI__RTIambassador__getInteractionClassName1
                (rtiAmb, theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_getInteractionClassName1.cpp"

/////////////////////////////////////////////////////

RTI::ParameterHandle MATIS_RTIAmbassador::getParameterHandle(RTI::
                                                             RTIambassador
                                                             * rtiAmb,
                                                             const char
                                                             *theName,
                                                             RTI::
                                                             InteractionClassHandle
                                                             whichClass)
throw(RTI::InteractionClassNotDefined,
      RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getParameterHandle2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getParameterHandle(
                                                                   theName,
                                                                   whichClass);
#else
            return funcptr_RTI__RTIambassador__getParameterHandle2(rtiAmb,
                                                                   theName,
                                                                   whichClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here\n");
	return 0;

};

// user code
//
#include "Hook/RTI_getParameterHandle2.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getParameterName(RTI::RTIambassador * rtiAmb,
                                            RTI::ParameterHandle theHandle,
                                            RTI::
                                            InteractionClassHandle
                                            whichClass) throw(RTI::
                                                              InteractionClassNotDefined,
                                                              RTI::
                                                              InteractionParameterNotDefined,
                                                              RTI::
                                                              FederateNotExecutionMember,
                                                              RTI::
                                                              ConcurrentAccessAttempted,
                                                              RTI::
                                                              RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getParameterName2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getParameterName(
                                                                 theHandle,
                                                                 whichClass);
#else
            return funcptr_RTI__RTIambassador__getParameterName2(rtiAmb,
                                                                 theHandle,
                                                                 whichClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return NULL;

};

// user code
//
#include "Hook/RTI_getParameterName2.cpp"

/////////////////////////////////////////////////////

RTI::ObjectHandle MATIS_RTIAmbassador::getObjectInstanceHandle(RTI::
                                                               RTIambassador
                                                               * rtiAmb,
                                                               const char
                                                               *theName)
throw(RTI::ObjectNotKnown,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getObjectInstanceHandle1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getObjectInstanceHandle( theName);
#else
            return
                funcptr_RTI__RTIambassador__getObjectInstanceHandle1
                (rtiAmb, theName);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_getObjectInstanceHandle1.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getObjectInstanceName(RTI::RTIambassador *
                                                 rtiAmb,
                                                 RTI::
                                                 ObjectHandle theHandle)
throw(RTI::ObjectNotKnown, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getObjectInstanceName1 != NULL) {
#endif
        try {
#ifdef _WIN32
		return	rtiAmb->getObjectInstanceName(
                                                                   theHandle);
#else
            return
                funcptr_RTI__RTIambassador__getObjectInstanceName1(rtiAmb,
                                                                   theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return NULL; 
};

// user code
//
#include "Hook/RTI_getObjectInstanceName1.cpp"

/////////////////////////////////////////////////////

RTI::SpaceHandle MATIS_RTIAmbassador::getRoutingSpaceHandle(RTI::
                                                            RTIambassador
                                                            * rtiAmb,
                                                            const char
                                                            *theName)
throw(RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getRoutingSpaceHandle1 != NULL) {
#endif
        try {
#ifdef _WIN32
		return	rtiAmb->getRoutingSpaceHandle(
                                                                   theName);
#else
            return
                funcptr_RTI__RTIambassador__getRoutingSpaceHandle1(rtiAmb,
                                                                   theName);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_getRoutingSpaceHandle1.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getRoutingSpaceName(RTI::RTIambassador * rtiAmb,
                                               RTI::SpaceHandle theHandle)
throw(RTI::SpaceNotDefined,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getRoutingSpaceName1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getRoutingSpaceName(
                                                                    theHandle);
#else
            return funcptr_RTI__RTIambassador__getRoutingSpaceName1(rtiAmb,
                                                                    theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return NULL;

};

// user code
//
#include "Hook/RTI_getRoutingSpaceName1.cpp"

/////////////////////////////////////////////////////

RTI::DimensionHandle MATIS_RTIAmbassador::getDimensionHandle(RTI::
                                                             RTIambassador
                                                             * rtiAmb,
                                                             const char
                                                             *theName,
                                                             RTI::
                                                             SpaceHandle
                                                             whichSpace)
throw(RTI::SpaceNotDefined,
      RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getDimensionHandle2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getDimensionHandle(
                                                                   theName,
                                                                   whichSpace);
#else
            return funcptr_RTI__RTIambassador__getDimensionHandle2(rtiAmb,
                                                                   theName,
                                                                   whichSpace);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here\n");
	return 0;

};

// user code
//
#include "Hook/RTI_getDimensionHandle2.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getDimensionName(RTI::RTIambassador * rtiAmb,
                                            RTI::DimensionHandle theHandle,
                                            RTI::SpaceHandle whichSpace)
throw(RTI::SpaceNotDefined,
      RTI::DimensionNotDefined,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getDimensionName2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getDimensionName(
                                                                 theHandle,
                                                                 whichSpace);
#else
            return funcptr_RTI__RTIambassador__getDimensionName2(rtiAmb,
                                                                 theHandle,
                                                                 whichSpace);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here\n");
	return NULL;

};

// user code
//
#include "Hook/RTI_getDimensionName2.cpp"

/////////////////////////////////////////////////////

RTI::SpaceHandle MATIS_RTIAmbassador::getAttributeRoutingSpaceHandle(RTI::
                                                                     RTIambassador
                                                                     *
                                                                     rtiAmb,
                                                                     RTI::
                                                                     AttributeHandle
                                                                     theHandle,
                                                                     RTI::
                                                                     ObjectClassHandle
                                                                     whichClass)
throw(RTI::ObjectClassNotDefined, RTI::AttributeNotDefined,
      RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getAttributeRoutingSpaceHandle2 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getAttributeRoutingSpaceHandle( theHandle, whichClass);
#else
            return
                funcptr_RTI__RTIambassador__getAttributeRoutingSpaceHandle2
                (rtiAmb, theHandle, whichClass);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
//#include "Hook/RTI_getAttributeRoutingSpaceHandle2.cpp"

/////////////////////////////////////////////////////

RTI::ObjectClassHandle MATIS_RTIAmbassador::getObjectClass(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           RTI::
                                                           ObjectHandle
                                                           theObject)
throw(RTI::ObjectNotKnown, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getObjectClass1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getObjectClass(
                                                               theObject);
#else
            return funcptr_RTI__RTIambassador__getObjectClass1(rtiAmb,
                                                               theObject);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return 0;

};

// user code
//
#include "Hook/RTI_getObjectClass1.cpp"

/////////////////////////////////////////////////////

RTI::SpaceHandle MATIS_RTIAmbassador::
getInteractionRoutingSpaceHandle(RTI::RTIambassador * rtiAmb,
                                 RTI::InteractionClassHandle theHandle)
throw(RTI::InteractionClassNotDefined, RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getInteractionRoutingSpaceHandle1 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->
			  getInteractionRoutingSpaceHandle( theHandle);
#else
            return
                funcptr_RTI__RTIambassador__getInteractionRoutingSpaceHandle1
                (rtiAmb, theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
//#include "Hook/RTI_getInteractionRoutingSpaceHandle1.cpp"

/////////////////////////////////////////////////////

RTI::TransportationHandle MATIS_RTIAmbassador::
getTransportationHandle(RTI::RTIambassador * rtiAmb, const char *theName)
throw(RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getTransportationHandle1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->
			  getTransportationHandle( theName);
#else
            return
                funcptr_RTI__RTIambassador__getTransportationHandle1
                (rtiAmb, theName);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_getTransportationHandle1.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getTransportationName(RTI::RTIambassador *
                                                 rtiAmb,
                                                 RTI::TransportationHandle
                                                 theHandle) throw(RTI::
                                                                  InvalidTransportationHandle,
                                                                  RTI::
                                                                  FederateNotExecutionMember,
                                                                  RTI::
                                                                  ConcurrentAccessAttempted,
                                                                  RTI::
                                                                  RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getTransportationName1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getTransportationName(
                                                                   theHandle);
#else
            return
                funcptr_RTI__RTIambassador__getTransportationName1(rtiAmb,
                                                                   theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
		LOGERR("Shouldn't get here");
	return 0; 
};

// user code
//
#include "Hook/RTI_getTransportationName1.cpp"

/////////////////////////////////////////////////////

RTI::OrderingHandle MATIS_RTIAmbassador::getOrderingHandle(RTI::
                                                           RTIambassador *
                                                           rtiAmb,
                                                           const char
                                                           *theName)
throw(RTI::NameNotFound,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getOrderingHandle1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getOrderingHandle(
                                                                  theName);
#else
            return funcptr_RTI__RTIambassador__getOrderingHandle1(rtiAmb,
                                                                  theName);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return 0;

};

// user code
//
#include "Hook/RTI_getOrderingHandle1.cpp"

/////////////////////////////////////////////////////

char *MATIS_RTIAmbassador::getOrderingName(RTI::RTIambassador * rtiAmb,
                                           RTI::OrderingHandle theHandle)
throw(RTI::InvalidOrderingHandle,
      RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getOrderingName1 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->getOrderingName(
                                                                theHandle);
#else
            return funcptr_RTI__RTIambassador__getOrderingName1(rtiAmb,
                                                                theHandle);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif

	LOGERR("Shouldn't get here\n");
	return NULL;

};

// user code
//
#include "Hook/RTI_getOrderingName1.cpp"

/////////////////////////////////////////////////////

RTI::RegionToken MATIS_RTIAmbassador::getRegionToken(RTI::RTIambassador *rtiAmb,
                                                     RTI::Region *aRegion)
        throw(
            RTI::FederateNotExecutionMember,
            RTI::ConcurrentAccessAttempted,
            RTI::RegionNotKnown,
            RTI::RTIinternalError){

#ifndef _WIN32
        if (funcptr_RTI__RTIambassador__getRegionToken1 !=
            NULL) {
#endif
            try {
#ifdef _WIN32
                rtiAmb->getRegionToken(aRegion);
#else
                funcptr_RTI__RTIambassador__getRegionToken1
                    (rtiAmb, aRegion);
                
#endif
                
            }
            catch(...) {
                throw;
            }
#ifndef _WIN32
        } else {
        }
#endif
    };

// user code
//
#include "Hook/RTI_getRegionToken1.cpp"

/////////////////////////////////////////////////////////////////

RTI::Region *MATIS_RTIAmbassador::getRegion(RTI::RTIambassador *rtiAmb,
                                            RTI::RegionToken aToken)
        throw(
            RTI::FederateNotExecutionMember,
            RTI::ConcurrentAccessAttempted,
            RTI::RegionNotKnown,
            RTI::RTIinternalError){

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__getRegion1 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->getRegion(aToken);
#else
            funcptr_RTI__RTIambassador__getRegion1
                (rtiAmb, aToken);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_getRegion1.cpp"



/////////////////////////////////////////////////////////////////////////////////

void MATIS_RTIAmbassador::enableClassRelevanceAdvisorySwitch(RTI::
                                                             RTIambassador
                                                             *
                                                             rtiAmb)
throw(RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch0 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->enableClassRelevanceAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__enableClassRelevanceAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_enableClassRelevanceAdvisorySwitch0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::disableClassRelevanceAdvisorySwitch(RTI::
                                                              RTIambassador
                                                              * rtiAmb)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch0 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->disableClassRelevanceAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__disableClassRelevanceAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_disableClassRelevanceAdvisorySwitch0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::enableAttributeRelevanceAdvisorySwitch(RTI::
                                                                 RTIambassador
                                                                 * rtiAmb)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch0
        != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->enableAttributeRelevanceAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__enableAttributeRelevanceAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_enableAttributeRelevanceAdvisorySwitch0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::disableAttributeRelevanceAdvisorySwitch(RTI::
                                                                  RTIambassador
                                                                  * rtiAmb)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->disableAttributeRelevanceAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__disableAttributeRelevanceAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_disableAttributeRelevanceAdvisorySwitch0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::enableAttributeScopeAdvisorySwitch(RTI::
                                                             RTIambassador
                                                             *
                                                             rtiAmb)
throw(RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch0 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->enableAttributeScopeAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__enableAttributeScopeAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_enableAttributeScopeAdvisorySwitch0.cpp"

void MATIS_RTIAmbassador::disableAttributeScopeAdvisorySwitch(RTI::
                                                              RTIambassador
                                                              * rtiAmb)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch0 !=
        NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->disableAttributeScopeAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__disableAttributeScopeAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_disableAttributeScopeAdvisorySwitch0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::enableInteractionRelevanceAdvisorySwitch(RTI::
                                                                   RTIambassador
                                                                   *
                                                                   rtiAmb)
throw(RTI::FederateNotExecutionMember, RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->enableInteractionRelevanceAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__enableInteractionRelevanceAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_enableInteractionRelevanceAdvisorySwitch0.cpp"

/////////////////////////////////////////////////////

void MATIS_RTIAmbassador::disableInteractionRelevanceAdvisorySwitch(RTI::
                                                                    RTIambassador
                                                                    *
                                                                    rtiAmb)
throw(RTI::FederateNotExecutionMember,
      RTI::ConcurrentAccessAttempted,
      RTI::SaveInProgress, RTI::RestoreInProgress, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch0 != NULL) {
#endif
        try {
#ifdef _WIN32
			rtiAmb->disableInteractionRelevanceAdvisorySwitch();
#else
            funcptr_RTI__RTIambassador__disableInteractionRelevanceAdvisorySwitch0
                (rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
};

// user code
//
#include "Hook/RTI_disableInteractionRelevanceAdvisorySwitch0.cpp"

/////////////////////////////////////////////////////

RTI::Boolean MATIS_RTIAmbassador::tick(RTI::RTIambassador * rtiAmb)
throw(RTI::SpecifiedSaveLabelDoesNotExist,
      RTI::ConcurrentAccessAttempted, RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__tick0 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->tick();
#else
            return funcptr_RTI__RTIambassador__tick0(rtiAmb);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return RTI::RTI_FALSE;

};

// user code
//
#include "Hook/RTI_tick0.cpp"

/////////////////////////////////////////////////////

RTI::Boolean MATIS_RTIAmbassador::tick(RTI::RTIambassador * rtiAmb,
                                       RTI::TickTime minimum,
                                       RTI::TickTime maximum)
throw(RTI::SpecifiedSaveLabelDoesNotExist, RTI::ConcurrentAccessAttempted,
      RTI::RTIinternalError)
{

#ifndef _WIN32
    if (funcptr_RTI__RTIambassador__tick2 != NULL) {
#endif
        try {
#ifdef _WIN32
			return rtiAmb->tick( minimum,
								 maximum);
#else
            return funcptr_RTI__RTIambassador__tick2(rtiAmb, minimum,
                                                     maximum);

#endif

        }
        catch(...) {
            throw;
        }
#ifndef _WIN32
    } else {
    }
#endif
	LOGERR("Shouldn't get here\n");
	return RTI::RTI_FALSE;

};

// user code
//
#include "Hook/RTI_tick2.cpp"

/////////////////////////////////////////////////////

// TODO

// getRegionToken, getREgion
