// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMGroupIterator.cpp,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.13 $

#include "MATIS_LEAPBMGroupIterator.h"
#include "MATIS_Action_RTI_13NG.h"
#include "MATIS_LAESet.h"
#include "MATIS_TypeConversion_RTI_13NG.h"
#include "MATIS_LEAPBM.h"

using namespace MATIS;

//Default Constructor
LEAPBMGroupIterator::LEAPBMGroupIterator(){

    LEAPBMIterator();
    
};

//Default Destructor
LEAPBMGroupIterator::~LEAPBMGroupIterator(){
    
};

//This operator `adds' the program step represented by the Action
//parameter to the current location within the model. The return value
//indicates whether the resulting location is valid within this model
//or not.
bool LEAPBMGroupIterator::operator +=(Action *aAction){

    //if this action takes us to a vertex whose pathways are the end
    //of the group, and it is valid, increment the unordered counter
    //of completion.

    //if we're at the start we want to go through all the LEAPBMEntries
    bool valid = false;
    LEAPBMPathway *pathway;

    if(atStart){

        LOGMSG(4, "GI: At the start of the group, check entry...\n");

        LEAPBMGroup *aGroup = Model::LEAPBMGroupStore.getValue(parentGroup);
        if(aGroup == NULL){
            LOGWRN("Group iterator reference to parent group invalid!\n");
            return false;
        }

        handleType currentMethodCallTest, currentUnorderedTest;
        LEAPBMLAEInteraction *nextLAEInteraction;
        LEAPBMUnordered *nextUnordered;
        LEAPBMMethodCall *nextMethodCall;
        bool proceed = true;
        std::string tmp;

        //continue on with pathway
        switch(aGroup->entryType){
            
        case DESTINATIONTYPE_LAEINTERACTION:
            
            //lae method call destinations case:
            //check whether the Action's context matches this destination
            //requires us to get the laemethodcall from the id,
            nextLAEInteraction = Model::LEAPBMLAEInteractionStore.getValue(aGroup->entry);
            currentMethodCallTest = aGroup->entry;
            
            LOGMSG(4, "    GI: checking pathway destination laeinteraction handle is valid: " << aGroup->entry << "\n");
            LOGMSG(4, "    GI: ================================================================\n");
            
            valid = checkLAEInteraction(nextLAEInteraction, aAction);
            tmp = (valid)?"yes":"no";
            
            LOGMSG(4, "    GI: ================================================================\n");
            LOGMSG(4, "    " << tmp << "\n");
            
            break;
            
        case DESTINATIONTYPE_UNORDEREDGROUP:
            
            //check each group.
            nextUnordered = Model::LEAPBMUnorderedStore.getValue(aGroup->entry);
            currentUnorderedTest = aGroup->entry;
            
            LOGMSG(4, "    GI: checking pathway destination unordered group is valid: " << nextUnordered->getId() << "\n");
            LOGMSG(4, "    GI: ================================================================\n");
            
            valid = checkUnordered(nextUnordered, aAction, &currentMethodCallTest, &proceed);
            tmp = (valid)?"yes":"no";
            
            LOGMSG(4, "    GI: ================================================================\n");
            LOGMSG(4, "    " << tmp << "\n");
            
            if(valid){
                
                //set currentUnordered equal to this one
                LOGMSG(4, "  GI: current unordered is now: " << nextUnordered->getId() << "\n");
                currentUnordered = currentUnorderedTest;
                
            }
            break;
            
        }

        if(valid){
            
            LOGMSG(4, "  GI: entry with handle : " << aGroup->entry << " is valid!\n");
            LOGMSG(4, "  GI: current LAE Method call handle is now: " << currentMethodCallTest << "\n");
            
            //perform this LAEInteraction .This records the values in the
            //appropriate laeInstance objects and record this as the
            //current locations
            currentLAEInteraction = currentMethodCallTest;
            nextLAEInteraction = Model::LEAPBMLAEInteractionStore.getValue(currentMethodCallTest);
            //nextLAEInteraction->perform(); // this will get done in the LEAPBMIterator
            currentException = 0; //if we are going somewhere else then we are no longer in an exception

            atStart = false;
        
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

            LOGMSG(4, "GI: Checking current LAEInteraction\n");
            //also check the current LAE interaction to see if the captured action
            //is still part of the its definition?
            if(checkLAEInteraction(current, aAction)){
                LOGMSG(4, "YES\n");
                //no need to progress as the Action is part of the current LAEInteraction
                return true;
            } 
            LOGMSG(4, "NO\n");

            //get the existing LAEInteraction
            LOGMSG(4, "\nGI: Pathways of current laemethodcall: " 
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
                LOGMSG(4, "  GI: current pathway, handle: " << (*it) 
                       << ", destination: " << aPathway->destinationId 
                       << ", destinationType: " << Types::destinationTypeTypeToString(
                           aPathway->destinationType) << "\n");

                valid = checkPathway(Model::LEAPBMPathwayStore.getValue(*it), aAction);
                if(valid) break;
                
            }
            
        }
        
    }

    //all performing/setting of currentLAEInteraction will have been performed by now
    //so we can check whether its the last one. If it is, reset the iterator and increment
    //the group counter.
    if(valid){
        
        if(!isWithinGroup(currentLAEInteraction)){
            LOGMSG(4, "GI: the next progression within this iterator is at the end of the group.\n");
            finished = true;
        }
        
    }

    return valid;
    
}

bool LEAPBMGroupIterator::isWithinGroup(handleType aLAEInteractionHandle){
    
    LOGMSG(4, "calling isWithinGroup\n");

    LEAPBMLAEInteraction *currentLAEInteraction = 
            Model::LEAPBMLAEInteractionStore.getValue(aLAEInteractionHandle);

    if(currentLAEInteraction == NULL){
        LOGERR("Group iterator points to invalid LAE Interaction!\n");
    }

    bool isWithin = false;
    LEAPBMLAEInteraction *aLAEInteraction;
    LEAPBMUnordered *aUnordered;
    
    //go through each of the pathway destinations for this current element
    for(handleListType::iterator it = currentLAEInteraction->pathways.begin(); 
        it != currentLAEInteraction->pathways.end(); 
        ++it){

        LEAPBMPathway *aPathway = Model::LEAPBMPathwayStore.getValue(*it);        

        switch(aPathway->destinationType){
            
        case DESTINATIONTYPE_LAEINTERACTION:
            aLAEInteraction = Model::LEAPBMLAEInteractionStore.getValue(aPathway->destination);
            isWithin |= isModelElementWithinGroup((ModelElement*)aLAEInteraction);
            break;
            
        case DESTINATIONTYPE_UNORDEREDGROUP:
            aUnordered = Model::LEAPBMUnorderedStore.getValue(aPathway->destination);
            isWithin |= isModelElementWithinGroup((ModelElement*)aUnordered);
            break;
            
        }

        if(isWithin) return true;
        
    }

    return false;
    
}

bool LEAPBMGroupIterator::isModelElementWithinGroup(ModelElement *aModelElement){

    ModelElement *currentModelElement = aModelElement;

    //traverse back up the tree to see if one of the LAEinteraction's parent handle/type
    //match those of this iterator
    while(currentModelElement->parentType != OBJECT_LEAPBM){

        switch(currentModelElement->parentType){

        case OBJECT_LEAPBMGROUP:
            if(currentModelElement->parentHandle == parentGroup){                
                LOGMSG(4, "interaction IS within group.\n");
                return true;
            }
            currentModelElement = 
                LEAPBM::LEAPBMGroupStore.getValue(currentModelElement->parentHandle);
            break;
                
        case OBJECT_LEAPBMUNORDERED:
            currentModelElement = 
                LEAPBM::LEAPBMUnorderedStore.getValue(currentModelElement->parentHandle);
            break;
            
        }
        
    }

    LOGMSG(4, "interaction is not within group.\n");
    return false;

}


void LEAPBMGroupIterator::reset(){

    atStart = true;
    currentLAEInteraction = 0;
    currentUnordered = 0;
    currentException = 0;
    
}

    
