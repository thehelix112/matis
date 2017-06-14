// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMIterator.cpp,v $
// CVS $Date: 2006/02/26 14:47:33 $
// CVS $Revision: 1.17 $

#include "MATIS_LEAPBMIterator.h"
#include "MATIS_LEAPBMGroupIterator.h"
#include "MATIS_Action_RTI_13NG.h"
#include "MATIS_LAESet.h"
#include "MATIS_TypeConversion_RTI_13NG.h"
#include "MATIS_LEAPBM.h"

using namespace MATIS;

//Default Constructor
LEAPBMIterator::LEAPBMIterator():
   atStart(true),
   currentLAEInteraction(0),
   currentUnordered(0),
   currentException(0){
    
};

//Default Destructor
LEAPBMIterator::~LEAPBMIterator(){
    
};

//This operator `adds' the program step represented by the Action
//parameter to the current location within the model. The return value
//indicates whether the resulting location is valid within this model
//or not.
bool LEAPBMIterator::operator +=(Action *aAction){

    //if we're at the start we want to go through all the LEAPBMEntries
    bool valid = false;
    LEAPBMPathway *pathway;

    if(atStart){

        LOGMSG(4, "At the start of the model, scan entries...\n");

        //go through each entry and see if this one is covered
        LEAPBM *model = (LEAPBM*)Model::model;

        for(handleListType::iterator it = model->entries.begin(); 
            it != model->entries.end(); 
            ++it){
        
            LEAPBMEntry *entry = Model::LEAPBMEntryStore.getValue(*it);
            LOGMSG(4, "  Scanning entry: " << entry->getId() << "'s pathways...\n");

            for(handleListType::iterator iq = entry->pathways.begin(); 
                iq != entry->pathways.end(); 
                ++iq){

                valid = checkPathway(Model::LEAPBMPathwayStore.getValue(*iq), aAction);
                if(valid){
                    atStart = false;
                    break;
                }
                
            }            
            
        }
        
    } else {

        handleListType *checkList = NULL;

        if(aAction->actionContext == Action::EXCEPTION && currentException == 0){

            LEAPBMLAEInteraction *current = 
                Model::LEAPBMLAEInteractionStore.getValue(currentLAEInteraction);

            //if the Action's context is EXCEPTION we want to check only the exception pathways
            for(handleListType::iterator it = current->exceptions.begin(); 
                it != current->exceptions.end(); 
                ++it){

                valid = checkException((*it), aAction);
                if(valid) break;
            
            }
  
        } else if(currentException > 0){

            //if we are currently inside an exception we just check its pathways   
            //get the existing Exception
            LEAPBMException *current = Model::LEAPBMExceptionStore.getValue(currentException);
            checkList = &(current->pathways);
            
        } else {
            
            
            LEAPBMLAEInteraction *current = 
                Model::LEAPBMLAEInteractionStore.getValue(currentLAEInteraction);

            /*
            LOGMSG(4, "Checking current LAEInteraction\n");
            //also check the current LAE interaction to see if the captured action
            //is still part of the its definition?
            if(checkLAEInteraction(current, aAction)){
                LOGMSG(4, "YES\n");
                //no need to progress as the Action is part of the current LAEInteraction
                return true;
            } 
            LOGMSG(4, "NO\n");*/

            //get the existing LAEInteraction
            LOGMSG(4, "\nPathways of current laemethodcall: " 
                   << current->getId() << "\n");
            checkList = &(current->pathways);

            /*for(handleListType::iterator it = (*checkList).begin(); 
                it != (*checkList).end(); 
                ++it){
                LOGMSG(4, "  current LAEInteraction pathways handle: " << (*it) << "\n");
                } */  
            
        }

        if(checkList != NULL){   

            //for each pathway compare the values of the destination with
            //those in the Action, if a match is found, break out of the loop
            for(handleListType::iterator it = (*checkList).begin(); 
                it != (*checkList).end(); 
                ++it){
                
                //get the pathway pointed to by this
                LEAPBMPathway *aPathway = Model::LEAPBMPathwayStore.getValue(*it);
                LOGMSG(4, "  current pathway, handle: " << (*it) 
                       << ", destination: " << aPathway->destinationId 
                       << ", destinationType: " << Types::destinationTypeTypeToString(
                           aPathway->destinationType) << "\n");

                valid = checkPathway(Model::LEAPBMPathwayStore.getValue(*it), aAction);
                if(valid) return true;
                
            }
            
        }
        
    }

    return valid;
    
}


bool LEAPBMIterator::checkException(handleType aExceptionHandle, Action *aAction){


    LEAPBMException *aException = Model::LEAPBMExceptionStore.getValue(aExceptionHandle);
    
    bool valid = false;

    //compare the exceptions
    RTI::Exception *actionException = TypeConversion_RTI_13NG::getMeta_Exception(*aAction);
    APIException *modelException = Model::APIExceptionStore.getValue(aException->exception);
    
    if(modelException->getName() == Action_RTI_13NG::rtiExceptionToString(actionException)){
        valid = true;
        currentException = aExceptionHandle;
    }
    
    return valid;
    
}


bool LEAPBMIterator::checkPathway(LEAPBMPathway *aPathway, 
                                  Action *aAction){

    LOGMSG(5, "  Scanning pathway id: " << aPathway->destinationId << "\n");

    handleType currentMethodCallTest, currentUnorderedTest;
    LEAPBMLAEInteraction *nextLAEInteraction;
    LEAPBMUnordered *nextUnordered;
    LEAPBMMethodCall *nextMethodCall;
    bool proceed = true;
    bool valid = false;
    bool leavingUnordered = false;

    //check if we are within an unordered group, if we are and are
    //at the end of a particular group we need to check the
    //existing unordered group as well as the pathway

    //check the unordered first so we can determine if other groups
    //are required, if they are then a normal progression is illegal
    //so we won't bother checking
    
    //this is only valid if we are at the end of a group! simple, test
    //to see if the pathway is pointing to a point outside the current unordered!

    //if we are inside an unordered currently.
    if(currentUnordered > 0){

        LEAPBMUnordered *leapbmUnordered = Model::LEAPBMUnorderedStore.getValue(currentUnordered);

        LOGMSG(4, "    Current inside unordered: " << leapbmUnordered->getId() << "\n");

        //and the next point is trying to leave the unordered
        if(!leapbmUnordered->isDestinationContained(aPathway)){

            LOGMSG(4, "      pathway destination not within unordered. Check unordered satisfied: ");
            leavingUnordered = true;
            //check if the requirements for the current unordered have been met
            valid = checkUnordered(leapbmUnordered, aAction, &currentMethodCallTest, &proceed);
            std::string tmp = (valid)?"yes":"no";
            LOGMSG(4, tmp << "\n");

        }

    }

    //if they have we can proceed, but there is no point if the
    //current unordered is valid so skip if this is true
    if(proceed && !valid){

        std::string tmp;
        
        //if the only valid potential pathway is outside this
        //unordered we can safely set it to 0
        if(leavingUnordered){
        
            LOGMSG(4, "    leaving current unordered to none. Resetting group completions\n");
            //reset the group completions within the unordered to zero
            Model::LEAPBMUnorderedStore.getValue(currentUnordered)->resetGroupCompletions();
            
            currentUnordered = 0;
            
        }
        

        currentMethodCallTest = 0;

        //continue on with pathway
        switch(aPathway->destinationType){
            
        case DESTINATIONTYPE_LAEINTERACTION:
            
            //lae method call destinations case:
            //check whether the Action's context matches this destination
            //requires us to get the laemethodcall from the id,
            nextLAEInteraction = Model::LEAPBMLAEInteractionStore.getValue(aPathway->destination);
            currentMethodCallTest = aPathway->destination;

            LOGMSG(4, "    checking pathway destination laeinteraction handle is valid: " << aPathway->destination << "\n");
            LOGMSG(4, "    ================================================================\n");

            valid = checkLAEInteraction(nextLAEInteraction, aAction);
            tmp = (valid)?"yes":"no";

            LOGMSG(4, "    ================================================================\n");
            LOGMSG(4, "    " << tmp << "\n");

            break;
            
        case DESTINATIONTYPE_UNORDEREDGROUP:

            //check each group.
            nextUnordered = Model::LEAPBMUnorderedStore.getValue(aPathway->destination);
            currentUnorderedTest = aPathway->destination;

            LOGMSG(4, "    checking pathway destination unordered group is valid: " << nextUnordered->getId() << "\n");
            LOGMSG(4, "    ================================================================\n");

            valid = checkUnordered(nextUnordered, aAction, &currentMethodCallTest, &proceed);
            tmp = (valid)?"yes":"no";

            LOGMSG(4, "    ================================================================\n");
            LOGMSG(4, "    " << tmp << "\n");

            if(valid){

                //set currentUnordered equal to this one
                LOGMSG(4, "  current unordered is now: " << nextUnordered->getId() << "\n");
                currentUnordered = currentUnorderedTest;
                
            }
            break;

            
        }
        
    }

    if(valid){

        LOGMSG(4, "  pathway handle: " << aPathway->getDestination() << " is valid!\n");
        LOGMSG(4, "  current LAE Method call handle is now: " << currentMethodCallTest << "\n");
     
        //perform this LAEInteraction .This records the values in the
        //appropriate laeInstance objects and record this as the
        //current locations
        currentLAEInteraction = currentMethodCallTest;
        nextLAEInteraction = Model::LEAPBMLAEInteractionStore.getValue(currentMethodCallTest);
        nextLAEInteraction->perform();
        currentException = 0; //if we are going somewhere else then we are no longer in an exception
        
    }

    return valid;
    
}

bool LEAPBMIterator::checkLAEInteraction(LEAPBMLAEInteraction *aLAEInteraction, 
                                         Action *aAction){

    if(aLAEInteraction->methodCall > 0 &&
       aLAEInteraction->propertySet == 0){

        //interaction is a method call one
        bool contextValid = false;
        bool valuesValid = false;

        LEAPBMMethodCall *aMethodCall = 
            Model::LEAPBMMethodCallStore.getValue(aLAEInteraction->methodCall);

        LOGMSG(4, "  about to check context: \n");
        contextValid = checkMethodCallContext(aMethodCall, aAction);
        std::string tmp = (contextValid)?"yes":"no";
        LOGMSG(4, "    result: " << tmp << "\n");

        if(contextValid){   

            LOGMSG(4, "  about to check values: \n");

            valuesValid = checkMethodCallValues(aMethodCall, aAction);

            tmp = (valuesValid)?"yes":"no";
            LOGMSG(4, "    result: " << tmp << "\n");
            
        }
 
        return contextValid && valuesValid;
        
    } else if(aLAEInteraction->propertySet > 0 &&
              aLAEInteraction->methodCall == 0){

        //interaction is a property set
        bool isExpectedReturn = false;
        bool match = checkPropertySetValue(aLAEInteraction->propertySet, aAction, &isExpectedReturn);
        if(!isExpectedReturn)
            return match;
        else
            return false;

    } else {
        
        LOGWRN("Neither or both method call/property set set on LAEInteraction: " << aLAEInteraction->id << "\n");
        
    }

}

bool LEAPBMIterator::checkUnordered(LEAPBMUnordered *aUnordered, 
                                    Action *aAction, 
                                    handleType *currentTest, 
                                    bool *proceed){

    LEAPBMGroup *nextGroup;
    bool valid = false;
    bool finished = false;
    handleListType checkGroups;
    
    *proceed = true;

    //go through ALL the groups to see if they have all been fulfilled
    for(handleListType::iterator it = aUnordered->groups.begin(); 
        it != aUnordered->groups.end(); 
        ++it){

        nextGroup = Model::LEAPBMGroupStore.getValue(*it);
        bool matchesMinimum = false,
            matchesMaximum = false;
        
        LOGMSG(4, "      checking group " << nextGroup->getId() << " completion\n");
        LOGMSG(4, "        m(" << nextGroup->requiredMin << ") < program(" << aUnordered->getGroupCompletion(*it) << ") > m(" << nextGroup->requiredMax << ")\n");
        
        int groupCompleted = aUnordered->getGroupCompletion(*it);

        if(nextGroup->minimumInclusive){

            LOGMSG(4, "Checking completed : " << groupCompleted 
                   << " >= minimum : " << nextGroup->requiredMin << "\n");
            
            matchesMinimum = (groupCompleted >= nextGroup->requiredMin);
            
        } else {

            LOGMSG(4, "Checking completed : " << groupCompleted 
                   << " > minimum : " << nextGroup->requiredMin << "\n");

            matchesMinimum = (groupCompleted > nextGroup->requiredMin);

        }        

        if(!nextGroup->maximumInfinite){
            
            if(nextGroup->maximumInclusive){

            LOGMSG(4, "Checking completed : " << groupCompleted 
                   << " < maximum : " << nextGroup->requiredMax << "\n");
                
                matchesMaximum = (groupCompleted <= nextGroup->requiredMax);

                //if checking (and incrementing) this group is not going
                //to make it mismatch, check it.
                if(((groupCompleted+1) <= nextGroup->requiredMax)){
                    
                    checkGroups.push_back(*it);
                    
                } else {
                    
                    LOGMSG(4, "Do not check group: " << nextGroup->getId() 
                           << " as its maximum has been reached.\n");
                    
                }
                               
                
            } else {

            LOGMSG(4, "Checking completed : " << groupCompleted 
                   << " <= maximum : " << nextGroup->requiredMax << "\n");
                
                matchesMaximum = (groupCompleted < nextGroup->requiredMax);

                //if checking (and incrementing) this group is not going
                //to make it mismatch, check it.
                if(((groupCompleted+1) < nextGroup->requiredMax)){
                    
                    checkGroups.push_back(*it);
                    
                } else {
                    
                    LOGMSG(4, "Do not check group: " << nextGroup->getId() 
                           << " as its maximum has been reached.\n");
                    
                }
                
                
            }

        } else {
            
            matchesMaximum = true;
            
        }        

        *proceed &= (matchesMinimum && matchesMaximum);
        
    }

    if(*proceed){
        LOGMSG(4, "      may proceed past Unordered.\n");
    } else {
        LOGMSG(4, "      may NOT proceed past Unordered.\n");
    }

    //go through each group
    for(handleListType::iterator it = checkGroups.begin(); 
        it != checkGroups.end(); 
        ++it){

        nextGroup = Model::LEAPBMGroupStore.getValue(*it);    

        LOGMSG(4, "      checking group: " << nextGroup->getId() << "\n");
        valid = checkGroup(nextGroup, aAction, currentTest, &finished);
        std::string tmp = (valid)?"yes":"no";
        LOGMSG(4, "        result: " << tmp << "\n");
        
        if(finished){

            LOGMSG(4, "  INCREMENTING completion for group: " << nextGroup->getId() << "\n");
            aUnordered->incGroupCompletion(*it);

        }

        if(valid){
            return true;
        }
        
    }

    return valid;

}

bool LEAPBMIterator::checkGroup(LEAPBMGroup *aGroup, 
                                Action *aAction, 
                                handleType *currentTest, 
                                bool *finished){

    LOGMSG(6, "Group handle: " << aGroup->handle << " Group iterator parent handle: " << aGroup->iter->parentGroup << "\n");

    LEAPBMGroupIterator *anIt = (aGroup->iter);

    bool valid = *anIt+=aAction;

    if(valid){

        //inform this iterator as to what lae interaction the 
        //group iterator matched before it gets reset.
        *currentTest = anIt->currentLAEInteraction;

        if(anIt->finished){
            
            *finished = true;
            anIt->reset();
            
        }

        return true;

    } else {

        return false;

    }
    

    /*
    LEAPBMLAEInteraction *nextLAEInteraction;
    LEAPBMUnordered *nextUnordered;
    *currentTest = aGroup->entry;

    LOGMSG(4, "        group entry type: " << 
           Types::destinationTypeTypeToString(aGroup->getEntryType()) << "\n");

    switch(aGroup->entryType){

    case DESTINATIONTYPE_LAEINTERACTION:
        //check this laemethodcall against the action
        nextLAEInteraction = Model::LEAPBMLAEInteractionStore.getValue(aGroup->entry);
        LOGMSG(4, "        checking LAEInteraction: " << nextLAEInteraction->getId() << "\n");
        return checkLAEInteraction(nextLAEInteraction, aAction);
        break;
        
    case DESTINATIONTYPE_UNORDEREDGROUP:
        //check each group.
        nextUnordered = Model::LEAPBMUnorderedStore.getValue(aGroup->entry);
        LOGMSG(4, "        checking sub unordered: " << nextUnordered->getId() << "\n");
        return checkUnordered(nextUnordered, aAction, currentTest, proceed);
        break;  
            
    }
    
    return false;*/
    
}


//see if the action represents a legal context change
bool LEAPBMIterator::checkMethodCallContext(LEAPBMMethodCall *aLEAPBMMethodCall,
                                            Action *aAction){

    //and get the method_id, lookup the laemethod from the laeset,
    LAEMethod *laeMethod = Model::LAEMethodStore.getValue(aLEAPBMMethodCall->method);
    
    //check that the context for this action is a legal next step
    //in the laemethod's definition (by making use of the iterator
    //in the LAEMethod).
    return (*laeMethod)+(aAction);    
    
}

//match the values from the action to those in the methodcall
bool LEAPBMIterator::checkMethodCallValues(LEAPBMMethodCall *aLEAPBMMethodCall, 
                                           Action *aAction){

    //if no property sets then values match! :D
    if(aLEAPBMMethodCall->propertySets.size() == 0){
        return true;
    }

    //get the property sets of this methodcall if there are any
    for(handleListType::iterator it = aLEAPBMMethodCall->propertySets.begin(); 
        it != aLEAPBMMethodCall->propertySets.end(); 
        ++it){            
        
        bool isExpectedReturn = false;
        if(checkPropertySetValue(*it, aAction, &isExpectedReturn)){

            if(!isExpectedReturn)
                return true;
            
        } else {
            
            break;
            
        }
       
        
    }

    //no property sets matched to return false
    return false;
    
}

bool LEAPBMIterator::checkPropertySetValue(handleType aPropertySetHandle, Action* aAction, bool *isExpectedReturn){ 
         
    *isExpectedReturn = false;
   
    //get this propertyset
    LEAPBMPropertySet *propertySet = Model::LEAPBMPropertySetStore.getValue(aPropertySetHandle);
        
    //get the property
    LAEProperty *property = Model::LAEPropertyStore.getValue(propertySet->property);

    if(!LEAPBM::isPropertyInAction(property, aAction)){
    
        LOGMSG(6, "property: " << property->getId() << " not in action.\n");

        //if its a return thats fine, otherwise return false       
        for(handleListType::iterator iq = property->sources.begin();
            iq != property->sources.end();
            ++iq){
        
            LAEPropertySource *aSource = Model::LAEPropertySourceStore.getValue(*iq);
            if(aSource != NULL &&
               aSource->isReturn()){
                *isExpectedReturn = true;
                return true;
            }   
            
        }
        
        return false;
        
    }
    
    Checker *checker;
    
    //we need to know:
    // - where in the action the value is to come from (xml
    // <laeproperty> `action_storage'). if the properties
    // actionStorageCategory is not ACTION_HANDLE then we need to
    // switch and get the entire value accordingly
    boost::any actionData;

    switch(property->actionStorageCategory){

    case STORAGE_HS:
        actionData = aAction->hs;
        break;
    case STORAGE_HS2:
        actionData = aAction->hs2;
        break;
    case STORAGE_HVPS:
        actionData = aAction->hvps;
        break;
    case STORAGE_HVPS2:
        actionData = aAction->hvps2;
        break;
    case STORAGE_RS:
        actionData = aAction->rs;
        break;            
    case STORAGE_ACTIONHANDLE:
        TypeConversion::getMeta(aAction->metadata, 
                                Action_RTI_13NG::stringToActionMetaHandle(property->actionStorage), 
                                &actionData);
        break;
            
    default:
        break;
            
    }

    //CUSTOM TYPE variables
    LAEValueType *aValueType;
    LAEChecker *laeChecker;

    // - how to compare the two values (based on xml
    // <laeproperty> `type': if type is primitive use default
    // checker, if its not, use the checker pointed to in the
    // <valuetype> `validator'
    switch(property->getType()){
                
    case TYPE_NULL:
        LOGWRN("Null value type given for lae property: " << property->getId() << "\n");
        return false;
                
    case TYPE_LONG:
    case TYPE_SHORT:
    case TYPE_UNSIGNEDINT:
    case TYPE_UNSIGNEDLONG:
    case TYPE_UNSIGNEDSHORT:
    case TYPE_SIGNEDINT:
    case TYPE_SIGNEDLONG:
    case TYPE_SIGNEDSHORT:
    case TYPE_CHAR:
    case TYPE_SIGNEDCHAR:
    case TYPE_UNSIGNEDCHAR:
    case TYPE_STRING:
    case TYPE_INT:
    case TYPE_DOUBLE:
    case TYPE_FLOAT:
    case TYPE_POINTER:
    case TYPE_BOOL:
        //send to the default checker
        checker = Checker::getDefaultChecker();
        break;

    case TYPE_CUSTOM:
        aValueType = Model::LAEValueTypeStore.getValue(property->getCustomType());
        if(aValueType != NULL){
            //get the validator/checker from the valuetype
            LOGMSG(4, "Got LAEValueType: " << aValueType->id << "\n");
            laeChecker = Model::LAECheckerStore.getValue(aValueType->validator); 
            checker = laeChecker->checker;
        } else {
            LOGWRN("Custom value type specified but valuetype: " << property->getCustomType() << " doesn't exist.\nUsing default checker.\n");
            checker = Checker::getDefaultChecker();
        }
            
        break;

    default:
        LOGERR("Invald value type.\n");
        return false;
            
    }
        
    //we need to now get the value to pass to the
    //checker
    std::string modelData = propertySet->getByteValue();

    return checker->checkValues(actionData, modelData);

}

