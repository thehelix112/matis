// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LEAPBMModel.h,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.4 $

// LEAPBM stores

//Entries to this model
static UniqueHandleFactory < LEAPBMEntry*, 1 > LEAPBMEntryStore;
//Exits from this model
static UniqueHandleFactory < LEAPBMExit*, 1 > LEAPBMExitStore;
//LAESet requirements
static UniqueHandleFactory < LEAPBMLAETerm*, 1 > LEAPBMLAETermStore;
//LAEs created
static UniqueHandleFactory < LEAPBMLAE*, 1 > LEAPBMLAEStore;
//Method Calls
static UniqueHandleFactory < LEAPBMMethodCall*, 1 > LEAPBMMethodCallStore;
//Settings made to LAE Properties
static UniqueHandleFactory < LEAPBMPropertySet*, 1 > LEAPBMPropertySetStore;
//References to LAE property values
static UniqueHandleFactory < LEAPBMValueReference*, 1 > LEAPBMValueReferenceStore;
//LAEMethodCalls made
static UniqueHandleFactory < LEAPBMLAEInteraction*, 1 > LEAPBMLAEInteractionStore;
//LEAPBM Pathways
static UniqueHandleFactory < LEAPBMPathway*, 1 > LEAPBMPathwayStore;
//Exceptions
static UniqueHandleFactory < LEAPBMException*, 1 > LEAPBMExceptionStore;
//LAEUnordered groups of calls
static UniqueHandleFactory < LEAPBMUnordered*, 1 > LEAPBMUnorderedStore;
//Groups
static UniqueHandleFactory < LEAPBMGroup*, 1 > LEAPBMGroupStore;
//Links to processes
static UniqueHandleFactory < LEAPBMProcess*, 1 > LEAPBMProcessStore;
//Hosts
static UniqueHandleFactory < LEAPBMHost*, 1 > LEAPBMHostStore;
//Files
static UniqueHandleFactory < LEAPBMFile*, 1 > LEAPBMFileStore;
//Methods
static UniqueHandleFactory < LEAPBMMethod*, 1 > LEAPBMMethodStore;

// LAESet stores

//LAEPolicies
static UniqueHandleFactory < LAEPolicy*, 1 > LAEPolicyStore;
//LAEClasses
static UniqueHandleFactory < LAEClass*, 1 > LAEClassStore;
//Triggers
static UniqueHandleFactory < LAETrigger*, 1 > LAETriggerStore;
//Requirements for other LAESets
static UniqueHandleFactory < LAERequirement*, 1 > LAERequirementStore;
//Value Checker Plugins
static UniqueHandleFactory < LAEChecker*, 1 > LAECheckerStore;
//Value Function Plugins
static UniqueHandleFactory < LAEFunction*, 1 > LAEFunctionStore;
//Property references
static UniqueHandleFactory < LAEPropertyReference*, 1 > LAEPropertyReferenceStore;
//Methods map
static UniqueHandleFactory < LAEMethod*, 1 > LAEMethodStore;
//Methods stage map
static UniqueHandleFactory < LAEMethodStage*, 1 > LAEMethodStageStore;
//Methods stageProgression map
static UniqueHandleFactory < LAEMethodStageProgression*, 1 > LAEMethodStageProgressionStore;
//Methods restrictions
static UniqueHandleFactory < LAEUnrestricted*, 1 > LAEUnrestrictedStore;
//Properties map
static UniqueHandleFactory < LAEProperty*, 1 > LAEPropertyStore;
//sources 
static UniqueHandleFactory < LAEPropertySource*, 1 > LAEPropertySourceStore;
//APIMethods
static UniqueHandleFactory < APIGroup*, 1 > APIGroupStore;
//Methods map
static UniqueHandleFactory < APIMethod*, 1 > APIMethodStore;
//Parameter storage
static UniqueHandleFactory < APIParameter*, 1 > APIParameterStore;
//Variables map
static UniqueHandleFactory < APIVariable*, 1 > APIVariableStore;
//Exceptions map
static UniqueHandleFactory < APIException*, 1 > APIExceptionStore;
//Return storage
static UniqueHandleFactory < APIReturn*, 1 > APIReturnStore;
//Value Type Groups
static UniqueHandleFactory < LAEValueGroup*, 1 > LAEValueGroupStore;
//Value Types
static UniqueHandleFactory < LAEValueType*, 1 > LAEValueTypeStore;


