// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_FederateAmbassador.cpp,v $
// CVS $Date: 2005/11/11 04:51:13 $
// CVS $Revision: 1.1.1.1 $






// Automatically generated.  Edit at own risk!

#include "MATIS_Hook_RTI_13NG.h"

//File federateAmbServices.hh
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
////////////////////////////////////
// Federation Management Services //
////////////////////////////////////
// 4.7


// user code
#include "Hook/Fed_synchronizationPointRegistrationSucceeded1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_synchronizationPointRegistrationFailed1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_announceSynchronizationPoint2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_federationSynchronized1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_initiateFederateSave1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_federationSaved0.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_federationNotSaved0.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_requestFederationRestoreSucceeded1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_requestFederationRestoreFailed2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_federationRestoreBegun0.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_initiateFederateRestore2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_federationRestored0.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_federationNotRestored0.cpp"


/////////////////////////////////////////////////////

/////////////////////////////////////
// Declaration Management Services //
/////////////////////////////////////

// user code
#include "Hook/Fed_startRegistrationForObjectClass1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_stopRegistrationForObjectClass1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_turnInteractionsOn1.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_turnInteractionsOff1.cpp"


/////////////////////////////////////////////////////

////////////////////////////////
// Object Management Services //
////////////////////////////////

// user code
#include "Hook/Fed_discoverObjectInstance3.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_reflectAttributeValues5.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_reflectAttributeValues3.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_receiveInteraction5.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_receiveInteraction3.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_removeObjectInstance4.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_removeObjectInstance2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_attributesInScope2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_attributesOutOfScope2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_provideAttributeValueUpdate2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_turnUpdatesOnForObjectInstance2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_turnUpdatesOffForObjectInstance2.cpp"


/////////////////////////////////////////////////////

///////////////////////////////////
// Ownership Management Services //
///////////////////////////////////

// user code
#include "Hook/Fed_requestAttributeOwnershipAssumption3.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_attributeOwnershipDivestitureNotification2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_attributeOwnershipAcquisitionNotification2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_attributeOwnershipUnavailable2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_requestAttributeOwnershipRelease3.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_confirmAttributeOwnershipAcquisitionCancellation2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_informAttributeOwnership3.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_attributeIsNotOwned2.cpp"


/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_attributeOwnedByRTI2.cpp"


/////////////////////////////////////////////////////

//////////////////////////////
// Time Management Services //
//////////////////////////////

// user code
#include "Hook/Fed_timeRegulationEnabled1.cpp"

/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_timeConstrainedEnabled1.cpp"

/////////////////////////////////////////////////////

// user code
#include "Hook/Fed_timeAdvanceGrant1.cpp"

/////////////////////////////////////////////////////


// user code
#include "Hook/Fed_requestRetraction1.cpp"

/////////////////////////////////////////////////////
