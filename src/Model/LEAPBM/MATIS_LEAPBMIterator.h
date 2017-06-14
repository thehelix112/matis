// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMIterator.h,v $
// CVS $Date: 2006/01/15 17:00:10 $
// CVS $Revision: 1.6 $

#ifndef MATIS_LEAPBMITERATOR_H
#define MATIS_LEAPBMITERATOR_H 1

#include "MATIS_Types.h"
#include "MATIS_ModelIterator.h"
#include "MATIS_LEAPBMPathway.h"
#include "MATIS_LEAPBMLAEInteraction.h"
#include "MATIS_LEAPBMMethodCall.h"
#include "MATIS_LEAPBMUnordered.h"
#include "MATIS_LAEProperty.h"
#include "MATIS_Action.h"


namespace MATIS {

    class LEAPBMUnordered;
    class LEAPBMGroup;

    /**
     * LEAPBMIterator: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class LEAPBMIterator : public ModelIterator {
    public:

        //DATA
        //===============
        
        //Iterator data
        std::string id;
        handleType currentLAEInteraction;
        handleType currentUnordered;
        handleType currentException;
        bool atStart;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMIterator();

        //Default Destructor
        ~LEAPBMIterator();

        bool operator +=(Action *aAction);

        bool checkPathway(LEAPBMPathway *aPathway, 
                          Action *aAction);
        bool checkException(handleType aExceptionHandle, 
                            Action *aAction);

        bool checkLAEInteraction(LEAPBMLAEInteraction *aLAEInteraction, 
                                 Action *aAction);
        bool checkUnordered(LEAPBMUnordered *aUnordered, 
                            Action *aAction, 
                            handleType *currentTest, 
                            bool *proceed);
        bool checkGroup(LEAPBMGroup *aGroup, 
                        Action *aAction, 
                        handleType *currentTest, 
                        bool *finished);

        bool checkMethodCallContext(LEAPBMMethodCall *aLEAPBMMethodCall,
                                    Action *aAction);
        bool checkMethodCallValues(LEAPBMMethodCall *aLEAPBMMethodCall, 
                                   Action *aAction);
        bool checkPropertySetValue(handleType aPropertySetHandle,
                                   Action* aAction,
                                   bool *isExpectedReturn);

        bool isPropertyInAction(LAEProperty* aLAEProperty, 
                                Action *aAction);
        
        
    private:

    };
    
}


#endif                          // MATIS_LEAPBMITERATOR_H
