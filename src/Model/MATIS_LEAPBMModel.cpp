// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_LEAPBMModel.cpp,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.4 $


//Entries to this model
UniqueHandleFactory < LEAPBMEntry*, 1 > Model::LEAPBMEntryStore;
//Exits from this model
UniqueHandleFactory < LEAPBMExit*, 1 > Model::LEAPBMExitStore;
//LAESet requirements
UniqueHandleFactory < LEAPBMLAETerm*, 1 > Model::LEAPBMLAETermStore;
//LAEs created
UniqueHandleFactory < LEAPBMLAE*, 1 > Model::LEAPBMLAEStore;
//Method Calls
UniqueHandleFactory < LEAPBMMethodCall*, 1 > Model::LEAPBMMethodCallStore;
//Settings made to LAE Properties
UniqueHandleFactory < LEAPBMPropertySet*, 1 > Model::LEAPBMPropertySetStore;
//References to LAE property values
UniqueHandleFactory < LEAPBMValueReference*, 1 > Model::LEAPBMValueReferenceStore;
//LAEMethodCalls made
UniqueHandleFactory < LEAPBMLAEInteraction*, 1 > Model::LEAPBMLAEInteractionStore;
//LEAPBM Pathways
UniqueHandleFactory < LEAPBMPathway*, 1 > Model::LEAPBMPathwayStore;
//Exceptions
UniqueHandleFactory < LEAPBMException*, 1 > Model::LEAPBMExceptionStore;
//LAEUnordered groups of calls
UniqueHandleFactory < LEAPBMUnordered*, 1 > Model::LEAPBMUnorderedStore;
//Groups
UniqueHandleFactory < LEAPBMGroup*, 1 > Model::LEAPBMGroupStore;
//Links to processes
UniqueHandleFactory < LEAPBMProcess*, 1 > Model::LEAPBMProcessStore;
//Hosts
UniqueHandleFactory < LEAPBMHost*, 1 > Model::LEAPBMHostStore;
//Files
UniqueHandleFactory < LEAPBMFile*, 1 > Model::LEAPBMFileStore;
//Methods
UniqueHandleFactory < LEAPBMMethod*, 1 > Model::LEAPBMMethodStore;


//LAEPolicys
UniqueHandleFactory < LAEPolicy*, 1 > Model::LAEPolicyStore;
//LAEClasses
UniqueHandleFactory < LAEClass*, 1 > Model::LAEClassStore;
//Triggers
UniqueHandleFactory < LAETrigger*, 1 > Model::LAETriggerStore;
//Requirements for other LAESets
UniqueHandleFactory < LAERequirement*, 1 > Model::LAERequirementStore;
//Value Checker Plugins
UniqueHandleFactory < LAEChecker*, 1 > Model::LAECheckerStore;
//Value Function Plugins
UniqueHandleFactory < LAEFunction*, 1 > Model::LAEFunctionStore;
//Properties References 
UniqueHandleFactory < LAEPropertyReference*, 1 > Model::LAEPropertyReferenceStore;
//Methods map
UniqueHandleFactory < LAEMethod*, 1 > Model::LAEMethodStore;
//Methods stage map
UniqueHandleFactory < LAEMethodStage*, 1 > Model::LAEMethodStageStore;
//Methods stageProgression map
UniqueHandleFactory < LAEMethodStageProgression*, 1 > Model::LAEMethodStageProgressionStore;
//Methods restrictions map
UniqueHandleFactory < LAEUnrestricted*, 1 > Model::LAEUnrestrictedStore;
//Properties map
UniqueHandleFactory < LAEProperty*, 1 > Model::LAEPropertyStore;
//sources 
UniqueHandleFactory < LAEPropertySource*, 1 > Model::LAEPropertySourceStore;
//APIMethods
UniqueHandleFactory < APIGroup*, 1 > Model::APIGroupStore;
//Methods map
UniqueHandleFactory < APIMethod*, 1 > Model::APIMethodStore;
//Parameter storage
UniqueHandleFactory < APIParameter*, 1 > Model::APIParameterStore;
//Variables map
UniqueHandleFactory < APIVariable*, 1 > Model::APIVariableStore;
//Exceptions map
UniqueHandleFactory < APIException*, 1 > Model::APIExceptionStore;
//Returns
UniqueHandleFactory < APIReturn*, 1 > Model::APIReturnStore;
//Value Type Groups
UniqueHandleFactory < LAEValueGroup*, 1 > Model::LAEValueGroupStore;
//Value Types
UniqueHandleFactory < LAEValueType*, 1 > Model::LAEValueTypeStore;
