// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBM.cpp,v $
// CVS $Date: 2006/02/26 14:47:33 $
// CVS $Revision: 1.19 $

#include "MATIS_LEAPBM.h"
#include "rdtscTimer.h"
#include <fstream>

using namespace MATIS;


handleType LEAPBM::drawingUnordered;


//Default Constructor
LEAPBM::LEAPBM():
    id(""){

    totalCycles = 0;
    calls = 0;
    rejections = 0;
    isConfigured = false;
    
    char *fenv = getenv("MATIS_DETECTIONONLY");
    if (fenv != NULL) {

        cistring detectionOnlyString(fenv);
        detection = (detectionOnlyString == "true" ||
                     detectionOnlyString == "yes");

        LOGMSG(1, "string got: " << fenv << "\n");
        
        if(detection){
        
            LOGMSG(1, "Detecting anomalies only.\n");    
            
        }

    }

    outfile.open("leapbm.anomalies");

    rejected = false;
    
};

//Default Destructor
LEAPBM::~LEAPBM(){
    
};

//Constructor
LEAPBM::LEAPBM(std::string aId):
    id(aId){

    totalCycles = 0;
    calls = 0;
    rejections = 0;
    isConfigured = false;

    char *fenv = getenv("MATIS_DETECTIONONLY");
    if (fenv != NULL) {

        cistring detectionOnlyString(fenv);
        detection = (detectionOnlyString == "true" ||
                     detectionOnlyString == "yes");

        if(detection){
        
            LOGMSG(1, "Detecting anomalies only.\n");    
            
        }
   
    }


    rejected = false;
    
};


//Get id method
std::string LEAPBM::getId(){

    LOGMSG(5, "BEGIN LEAPBM: " << id << " getting id\n");
    LOGMSG(5, "END LEAPBM: " << id << " getting id\n");

    return id;

};


//Set id method
void LEAPBM::setId(std::string aId){

    LOGMSG(5, "BEGIN LEAPBM: " << id << " setting id\n");

    id = aId;

    LOGMSG(5, "END LEAPBM: " << id << " setting id\n");

};


//return a string hash of the current object
std::string LEAPBM::hash(){

    LOGMSG(5, "BEGIN LEAPBM: " << id << " hash\n");
    LOGMSG(5, "END LEAPBM: " << id << " hash\n");

    return (id);
    
};


//Determine if the Action is in conformance with this LEAPBM
bool LEAPBM::request(Action* aAction, bool *executeAnyway){

    //reset this as none have been performed as yet
    performedUnrestrictedMethodCall = 0;

    unsigned long long int beforeCycles = rdtsc();
    //std::cerr << "MATIS: beforeCycles: " << beforeCycles << "\n";

    /*if(rejected){

        exit(1);

        if(!checkUnrestricted(aAction)){
            ++rejections;
            ++calls;
        }

        *executeAnyway = true;
        return false;

        }*/

    //determine if the action represents a legal step
    bool retval = (iter += aAction);

    LOGMSG(1, "Action " << Action_RTI_13NG::getContextAsString(aAction->actionContext) << "... ");
    //Action_RTI_13NG::print(aAction);

    if(!retval){

        //if the action was rejected as part of the interaction graph,
        //check if the action is one of the unrestricted ones!
        LOGMSG(4, "Unrestricted action? ");
        if(checkUnrestricted(aAction)){
            
            LOGMSG(4, "YES\n");
            //std::cerr << "MATIS: afterCycles: " << rdtsc() << "\n";
            totalCycles += (rdtsc()-beforeCycles);
            return true;
            
        } else {
            
            LOGMSG(4, "NO\n");

            LOGMSG(1, "REJECTED.\n");
        
            ++rejections;
            ++calls;

            //write this to the data file
            outputAnomaly(rejections);

            ////next time don't check anymore
            //rejected = true;

            *executeAnyway = true;
            //std::cerr << "MATIS: afterCycles: " << rdtsc() << "\n";
            totalCycles += (rdtsc()-beforeCycles);

            //summary();
            //exit(1);

            return false;
            
        }
        
    }

    ++calls;
    LOGMSG(1, "ACCEPTED.\n");
    //std::cerr << "MATIS: afterCycles: " << rdtsc() << "\n";
    totalCycles += (rdtsc()-beforeCycles);
    return retval;    

}    

void LEAPBM::summary(){
    
    //work out how much of the model/program was non-anomalous and not
    //
    //calls variables gives us the number of LAE interactions performed
    //size of the LAEInteractionStore gives us the total number in the model

    /*unsigned long total = Model::LEAPBMLAEInteractionStore.size();
    unsigned long called = 0;
    std::map < handleType, LEAPBMLAEInteraction* >::iterator it = 
        Model::LEAPBMLAEInteractionStore.getIterator();

    bool retval = false;

    //for each unrestricteds
    for(it = Model::LEAPBMLAEInteractionStore.begin(); 
        it != Model::LEAPBMLAEInteractionStore.end();
        ++it){
        
        LEAPBMLAEInteraction *aInteraction = (*it).second;

        if(aInteraction->performed)
            called++;
        
            }*/

    std::cerr << "\n---------------------------------------------------------------\n";
    std::cerr << "SUMMARY: Total number of interactions: " << calls << "\n";
    std::cerr << "SUMMARY: Number of anomalies: " << rejections << "\n";    
    double percentage = ((double)rejections/(double)calls)*100;
    std::cerr << "SUMMARY: Percentage anomalous: " << percentage << "\n";
    //1736921890 is number provided by test program.
    std::cerr << "SUMMARY: Total cycles spent detecting: " << totalCycles << "\n";
    std::cerr << "SUMMARY: Total time spent detecting: " << ((double)totalCycles/1736921890) << "\n";
    std::cerr << "---------------------------------------------------------------\n";

    outfile.close();

}


bool LEAPBM::checkUnrestricted(Action *aAction){

    //go through the unrestricteds present in the model directly
    handleListType::iterator it;
    //std::map < handleType, LAEUnrestricted >::iterator it = 
    //    Model::LAEUnrestrictedStore.getIterator();

    bool retval = false;

    //for each unrestricteds
    //for(it = Model::LAEUnrestrictedStore.begin(); 
    //    it != Model::LAEUnrestrictedStore.end();
    //    ++it){
    for(it = ((LEAPBM*)Model::model)->unrestrictedLAEMethods.begin();
        it != ((LEAPBM*)Model::model)->unrestrictedLAEMethods.end();
        ++it){

        LAEMethod *aLAEMethod = 
            Model::LAEMethodStore.getValue(*it);

        for(handleListType::iterator iq = aLAEMethod->unrestricteds.begin();
            iq != aLAEMethod->unrestricteds.end();
            ++iq){            

            //get the specifics of the unrestriction itself
            LAEUnrestricted *aUnrestricted = 
                Model::LAEUnrestrictedStore.getValue(*iq);
        

            LOGMSG(6, "\nGetting Unrestricted: \n" <<
                   "    afterInteraction: " << aUnrestricted->afterInteraction << "\n" <<
                   "    beforeInteraction: " << aUnrestricted->beforeInteraction << "\n" <<
                   "    parent LAEMethod handle: " << aUnrestricted->parentHandle << "\n" <<
                   "    parent LAEMethod id: " << aLAEMethod->getId() << "\n");
            
            
            //after limitation
            //check the laemethod is in the model's list of performed ones
            if(aUnrestricted->afterInteraction > 0){
                
                LOGMSG(6, "Unrestriced is allowed only after interaction id: " 
                       << (Model::LAEMethodStore.getValue(aUnrestricted->afterInteraction))->getId() 
                       << "\n");
                
                bool inList = false;
                for(handleListType::iterator iq = ((LEAPBM*)Model::model)->performedLAEMethods.begin();
                    iq != ((LEAPBM*)Model::model)->performedLAEMethods.end();
                    ++iq){
                    
                    LOGMSG(6, "LAEMethod: " << (*iq) << " has been performed.\n");
                    if((*iq) == aUnrestricted->afterInteraction){
                        LOGMSG(6, "afterInteraction: " << aUnrestricted->afterInteraction 
                               << " has been performed.\n");
                        inList = true;
                        break;
                    }
                    
                }
                
                if(!inList)
                    return false;
                
            }
            
            //before limitation
            //check the laemethod is NOT in the model's list of performed ones
            if(aUnrestricted->beforeInteraction > 0){
                
                LOGMSG(6, "Unrestricted is allowed only before interaction id: " 
                       << (Model::LAEMethodStore.getValue(aUnrestricted->beforeInteraction))->getId() 
                       << "\n");
                
                bool inList = false;
                for(handleListType::iterator iq = ((LEAPBM*)Model::model)->performedLAEMethods.begin();
                    iq != ((LEAPBM*)Model::model)->performedLAEMethods.end();
                    ++iq){
                    
                    LOGMSG(6, "LAEMethod: " << (*iq) << " has been performed.\n");
                    if((*iq) == aUnrestricted->beforeInteraction){
                        LOGMSG(6, "beforeInteraction: " << aUnrestricted->beforeInteraction 
                               << " has been performed.\n");
                        inList = true;
                        break;
                    }
                    
                }
                
                if(inList) 
                    return false;
                
            }
            
        }

        //if the required before/after interactions have/not been done does this action match?
        if((*aLAEMethod)+(aAction)){

            //this action must be performed.
            performUnrestricted(aLAEMethod, aAction);
            
            //return true
            return true;
        }

    }

    return retval;
    
    // OR
    //go through the LAETerms and fetch the LAE classes from them.
    
}


void LEAPBM::performUnrestricted(LAEMethod *aLAEMethod, Action *aAction){
    

    //if this method is a constructor class then it is more than likely associated with a LAE
    //  lookup the LAE from the values provided in this method/action?
    //    
    //    search every LAE for unrestricted method calls

    for(handleListType::iterator it = LAEs.begin();
        it != LAEs.end();
        ++it){
        
        LEAPBMLAE *laeInstance = Model::LEAPBMLAEStore.getValue(*it);

        //go through every lae method call looking for an unrestricted one
        for(handleListType::iterator iq = laeInstance->methodCalls.begin();
            iq != laeInstance->methodCalls.end();
            ++iq){

            LEAPBMMethodCall *laeMethodCall = Model::LEAPBMMethodCallStore.getValue(*iq);
            LAEMethod *bLAEMethod = Model::LAEMethodStore.getValue(laeMethodCall->method);

            //if this method is what is, unrestricted and, about to be executed
            if(bLAEMethod == aLAEMethod){
                
                LOGMSG(4, "checking lae instance: " << laeInstance->getId() 
                       << " methodcall: " << laeMethodCall->getId() << "\n");

                LOGMSG(4, "  LAE method matches authorised unrestricted method\n");

                //if the unrestricted methodcall being performed is used in the LAE
                //  if propertyset(s) match this method/action
                //    then set the property value of the LAE according to the call.

                bool match = true;
                handleListType matchList;

                //for each <propertyset> in the <methodcall> go and check the LAE's property value
                for(handleListType::iterator iu = laeMethodCall->propertySets.begin(); 
                    iu != laeMethodCall->propertySets.end(); 
                    ++iu){

                    LEAPBMPropertySet *apropset = Model::LEAPBMPropertySetStore.getValue(*iu);
                    LAEProperty *aprop = Model::LAEPropertyStore.getValue(apropset->property);

                    LOGMSG(4, "  does set of property: " << aprop->id << " match action... ");

                    //if the value in the property set matches what is in the action
                    //then this is the correct laeInstance and we should set its property value.
                    bool isExpectedReturn;
                    bool thisMatch = iter.checkPropertySetValue(*iu, aAction, &isExpectedReturn);
                    
                    match &= thisMatch;

                    if(thisMatch && !isExpectedReturn){
                        LOGMSG(4, "YES\n");
                        matchList.push_back(*iu);
                    } else {
                        LOGMSG(4, "NO\n");
                    }
                    
                }

                if(match){
                    
                    for(handleListType::iterator iu = matchList.begin(); 
                        iu != matchList.end(); 
                        ++iu){

                        LOGMSG(4, "Setting value.\n");
                        
                        LEAPBMPropertySet *propertySet = Model::LEAPBMPropertySetStore.getValue(*iu);
                        laeInstance->setPropertyValue(propertySet->property, 
                                                      propertySet->getByteValue());

                        //record the performedUnrestrictedMethodCall for use in result.
                        performedUnrestrictedMethodCall = (*iq);
                        //add this LEAPBMMethodCall to the list of ones that have been performed.
                        ((LEAPBM*)Model::model)->performedLAEMethods.push_back(laeMethodCall->method);
                        
                    }

                }
                
            }

        }        
        
    }
    
}


//informed of the result of an Action
void LEAPBM::result(Action *aAction, void *aReturnValue){

    LOGMSG(4, "about to perform result\n");

    //the result of the aAction call is aReturnValue.
    //we need to set the values of propertys whose sources is the return value of this call.

    //if performedUnrestrictedMethodCall > 0 then thats the last thing
    //that happened otherwise we assume this action matches the
    //current laemethocall pointed to by the iterator. This could be
    //dangerous?

    LEAPBMMethodCall *methodCall = NULL;

    if(performedUnrestrictedMethodCall > 0){

        methodCall = Model::LEAPBMMethodCallStore.getValue(performedUnrestrictedMethodCall);
        
    } else if(iter.currentLAEInteraction > 0){

        LOGMSG(4, "about to get current LAE interaction.");

        //get the leapbmmethodcall
        LEAPBMLAEInteraction *aLAEInteraction = 
            Model::LEAPBMLAEInteractionStore.getValue(iter.currentLAEInteraction);

        if(aLAEInteraction == NULL)
            return;

        LOGMSG(4, "about to get current LAE interaction's methodcall.");
        
        //and get the method_id, lookup the method call from the laeset
        methodCall = Model::LEAPBMMethodCallStore.getValue(aLAEInteraction->methodCall);
        
    }
    
    //some basic checks
    if(methodCall == NULL)
        return;
        
    //look up the parent laeinstance from the lae method call
    LEAPBMLAE *laeInstance = Model::LEAPBMLAEStore.getValue(methodCall->parentHandle);

    if(laeInstance == NULL)
        return;

    LOGMSG(4, "checking for returns on lae instance: " << laeInstance->getId() << "\n");

    //go through all the methodCall's propertysets until we find one with a property 
    //whose source is a return value
    LEAPBMPropertySet *propertySet = NULL;
    LAEProperty *property = NULL;
    bool returnSource = false;
    for(handleListType::iterator it = methodCall->propertySets.begin();
        it != methodCall->propertySets.end();
        ++it){
    
        //get property
        propertySet = Model::LEAPBMPropertySetStore.getValue(*it);
        property = Model::LAEPropertyStore.getValue(propertySet->getProperty());

        LOGMSG(4, "  checking sources of property property: " << property->getId() << "\n");

        //go through all the sources to the property to check if one is a return
        LAEPropertySource *propertySource = NULL;
        for(handleListType::iterator iq = property->sources.begin();
            iq != property->sources.end();
            ++iq){

            //get property sources which are apireturn.
            propertySource = Model::LAEPropertySourceStore.getValue(*iq);            

            if(propertySource->isReturn()){
                // bingo

                LOGMSG(4, "property: " << property->getId() << " has a source which is an apireturn.\n");

                //fetch the apireturn and the apimethod associated with it.                
                APIMethod *aAPIMethod;
                APIReturn *aAPIReturn = Model::APIReturnStore.getValue(propertySource->APIReturn);
                if(aAPIReturn != NULL){
                     aAPIMethod = Model::APIMethodStore.getValue(aAPIReturn->parentHandle);
                } else {
                    LOGWRN("Property Source: `" << propertySource->getId() << "' refers to an invalid API return.\n");
                    continue;
                }

                LOGMSG(4, "    checking the return's parent method matches the action's context.\n");
                
                //check the context_id of the apimethod is the same as the action, in this way we
                //are checking if the return value we have is supposed to be here
                if(aAPIMethod->contextId == 
                   Action_RTI_13NG::getContextAsString(aAction->actionContext)){

                    LOGMSG(4, "action's context matches the apimethod context whose return is a source to this property.\n");

                    //there will only be one apireturn so we can skip the rest
                    returnSource = true;
                    break;
                }
                
            }

        }    

        if(returnSource){

            LOGMSG(4, "  YES\n");

            LOGMSG(6, "set the property value to what was returned: " << (char *)aReturnValue << "\n")
            
            //need to cast the return type appropriately depending on the action context.
            std::string byteValue = 
                Action_RTI_13NG::getByteValueFromActionReturn(aAction, aReturnValue);

            //set the byte value of the propertyset to aReturnValue
            propertySet->setByteValue(byteValue);
            
            //set the property value of the lae instance
            laeInstance->setPropertyValue(propertySet->property, propertySet->getByteValue());
            break;
            
        }
        
    }
    
}

/*

    For most Models the single string argument will provide the path
    to a source file for which a model is to be generated, however,
    LEAPBMS are configured prior to this with all the locations of any
    number of course files required. Thus making this argument surplus
    to requirements.

    There can potentially be checks in place to ascertain the type
    of programming language being used, however for now we will
    focus on C/C++.

    Using the configuration provided, we can parse the source file
    (and included ones as required) searching for the triggers we
    have been configured with.

    We will need to build a model of the included files. In this way
    we can determine what function calls made by the program are
    from which file. The configuration of the program should list
    all the files which form the code basis.

    We will make assumptions:

    1. .h or .hpp files ONLY contain declarations of functions and variables
    2. .cpp files contain the definitions of all functions declared in .h/hpp

    From this model we can determine what we should search other
    files for, and what we should assume is `outside' the definition
    of this program. I.e, any function call which is not part of the
    user-defined code and is also not part of any LAE (as per
    configuration), can be ignored as irrelevant.

*/

//generates a model based on a source file
void LEAPBM::generate(std::string aFilePath){

    LOGMSG(5, "BEGIN LEAPBM: " << id << " generation\n");

    //Ensure the LEAPBM instance has been configured
    if(!isConfigured) LOGERR("LEAPBM not configured.. aborting.");

    LOGMSG(5, "END LEAPBM: " << id << " generation\n");
    
}


/*

    Before anything is done a view of the program and its
    functionality must be developed. This involves determining
    several things: 

    1. What LAEs the programs LEAPBM is to be in terms of.  

    2. The location of all files which consitute this program, and
    building a bi-directional map between the files and the function
    definitions (and/or LAEs) they contain.

*/

//the path to any additional configuration information
//that the model requires in order to generate a model
void LEAPBM::configure(std::string aFilePath){

    //extract the top bits out of the .xml file

    //we have finished configuring this LEAPBM instance
    isConfigured = true;
    
}


//extract the top bits of the xml file
void LEAPBM::loadHeader(){
    
    //get the leapbm id, and the starting point id.

    //get the list of sources

    
}



//loads a previously save'd model from a file
bool LEAPBM::loadConfiguration(ConfigurationStore *aConfigurationStore){

    //first thing to do is get the laeterm elements from the
    //configuration store and instantiate an laeset from this.
    
    //configure the ID of this LEAPBM.
    setId(aConfigurationStore->rootElement.getParameterValue("id").c_str());

    //go through the list of sub-elements
    typedef std::list < ConfigurationElement > configurationElementListType;
    configurationElementListType elements = aConfigurationStore->rootElement.getElementList();
    for(configurationElementListType::iterator it = elements.begin(); it != elements.end(); ++it){
                                               
        if((*it).name == "laeterm"){

            LEAPBMLAETerm *aLAETerm = new LEAPBMLAETerm;
            aLAETerm->loadConfiguration(&(*it));
            aLAETerm->parentType = OBJECT_LEAPBM;
            LAETerms.push_back(Model::LEAPBMLAETermStore.addValue(aLAETerm));
            
        }

        if((*it).name == "process"){

            LEAPBMProcess *aProcess = new LEAPBMProcess;
            aProcess->loadConfiguration(&(*it));
            aProcess->parentType = OBJECT_LEAPBM;
            processes.push_back(Model::LEAPBMProcessStore.addValue(aProcess));
            
        }

        if((*it).name == "lae"){

            LEAPBMLAE *aLAE = new LEAPBMLAE;
            aLAE->loadConfiguration(&(*it));
            aLAE->parentType = OBJECT_LEAPBM;
            LAEs.push_back(Model::LEAPBMLAEStore.addValue(aLAE));
            
        }

        if((*it).name == "entry"){

            LEAPBMEntry *aEntry = new LEAPBMEntry;
            aEntry->loadConfiguration(&(*it));
            aEntry->parentType = OBJECT_LEAPBM;
            entries.push_back(Model::LEAPBMEntryStore.addValue(aEntry));
            
        }

        if((*it).name == "LAEInteraction"){

            LEAPBMLAEInteraction *aLAEInteraction = new LEAPBMLAEInteraction;
            aLAEInteraction->loadConfiguration(&(*it));
            aLAEInteraction->parentType = OBJECT_LEAPBM;
            LAEInteractions.push_back(Model::LEAPBMLAEInteractionStore.addValue(aLAEInteraction));
            
        }

        if((*it).name == "unordered"){

            LEAPBMUnordered *aUnordered = new LEAPBMUnordered;
            aUnordered->loadConfiguration(&(*it));
            aUnordered->parentType = OBJECT_LEAPBM;
            unordereds.push_back(Model::LEAPBMUnorderedStore.addValue(aUnordered));
            
        }

        if((*it).name == "exit"){

            LEAPBMExit *aExit = new LEAPBMExit;
            aExit->loadConfiguration(&(*it));
            aExit->parentType = OBJECT_LEAPBM;
            exits.push_back(Model::LEAPBMExitStore.addValue(aExit));
            
        }
                                                                               
    }

    //set the iterator to the start
    iter.atStart = true;

    return true;
    
}

//finalise configuration
bool LEAPBM::postConfigurationLoad(){

    bool success = true;

    //go through and finish all the links between things
    handleListType::iterator it;

    LOGMSG(6, "LEAPBMProcesses\n");
    for(it = processes.begin(); it != processes.end(); ++it){
        success &= (Model::LEAPBMProcessStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LEAPBMExit\n");    
    for(it = exits.begin(); it != exits.end(); ++it){
        success &= (Model::LEAPBMExitStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LEAPBMLAETerm\n");
    for(it = LAETerms.begin(); it != LAETerms.end(); ++it){
        success &= (Model::LEAPBMLAETermStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LEAPBMLAEStore\n");
    for(it = LAEs.begin(); it != LAEs.end(); ++it){
        success &= (Model::LEAPBMLAEStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LEAPBMLAEInteraction\n");
    for(it = LAEInteractions.begin(); it != LAEInteractions.end(); ++it){
        success &= (Model::LEAPBMLAEInteractionStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LEAPBMUnordered\n");
    for(it = unordereds.begin(); it != unordereds.end(); ++it){
        success &= (Model::LEAPBMUnorderedStore.getValue(*it))->postConfigurationLoad();
    }

    LOGMSG(6, "LEAPBMEntry\n");
    for(it = entries.begin(); it != entries.end(); ++it){
        success &= (Model::LEAPBMEntryStore.getValue(*it))->postConfigurationLoad();
    }

    loaded = success;

    //std::cout << "Outputting dot file and quitting.\n";

    outputDot("leapbm.dot");
    outputInfo("leapbm.info");
    //exit(1);

    return success;
    
}

//saves a generated model to a file
bool LEAPBM::saveConfiguration(ConfigurationStore *aConfigurationStore){
 
    return false;
    
}


//This function spits out information about the LEAPBM, such as average branching factor

void LEAPBM::outputInfo(std::string outputfile){

    
    std::ofstream outfile(outputfile.c_str());

    outfile << "LEAPBM: " << id << "\n";
    //number of lae interactions
    outfile << "number of interactions: " << LAEInteractions.size() << "\n";
    outfile << "number of unordered interactions: " << unrestrictedLAEMethods.size() << "\n";
    //calculate the average branching factor
    int numberOfUnrestricted = unrestrictedLAEMethods.size();
    int pathwaysInc = 0;
    int pathwaysExc = 0;
    
    //go through each LAEinteraction and count its number of pathways
    for(handleListType::iterator it = LAEInteractions.begin(); it != LAEInteractions.end(); ++it){

        pathwaysInc += (Model::LEAPBMLAEInteractionStore.getValue(*it)->pathways).size();
        pathwaysInc += numberOfUnrestricted;

        pathwaysExc += (Model::LEAPBMLAEInteractionStore.getValue(*it)->pathways).size();
        
    }

    outfile << "average branching factor including unordereds: " << ((double)pathwaysInc)/LAEInteractions.size() << "\n";
    outfile << "average branching factor excluding unordereds: " << ((double)pathwaysExc)/LAEInteractions.size() << "\n";
    
    outfile.close();

}


//This function spits out the dot formatted finite state automata
void LEAPBM::outputAnomaly(int totalRejections){

    outfile << ((double)(rdtsc()-startCPUCycles))/1736921890 << "\t\t" << totalRejections << "\n";

}



//This function spits out the dot formatted finite state automata
void LEAPBM::outputDot(std::string outputfile){

    handleListType::iterator it;

    //if(!loaded){
    //    LOGWRN("No LEAPBM loaded to output.\n");
    //    return;
    //}
    
    std::ofstream outfile(outputfile.c_str());
    outfile << "digraph \"" << id << "\" {\n";
    outfile << "  ratio=auto;\n";

    //go through the LEAPBM structure and get the dot representations of things.
    for(it = entries.begin(); it != entries.end(); ++it){
        outfile << (Model::LEAPBMEntryStore.getValue(*it))->getDot(1);
    }

    outfile << "\n";

    for(it = LAEInteractions.begin(); it != LAEInteractions.end(); ++it){
        outfile << (Model::LEAPBMLAEInteractionStore.getValue(*it))->getDot(1);
    }

    outfile << "\n";

    for(it = unordereds.begin(); it != unordereds.end(); ++it){
        outfile << (Model::LEAPBMUnorderedStore.getValue(*it))->getDot(1);
    }

    outfile << "\n";

    for(it = exits.begin(); it != exits.end(); ++it){
        outfile << (Model::LEAPBMExitStore.getValue(*it))->getDot(1);
    }

    outfile << "}\n";

    outfile.close();
    
}

        




