// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMGroupIterator.h,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.5 $

#ifndef MATIS_LEAPBMGROUPITERATOR_H
#define MATIS_LEAPBMGROUPITERATOR_H 1

#include "MATIS_Types.h"
#include "MATIS_LEAPBMIterator.h"
#include "MATIS_Action.h"


namespace MATIS {

    /**
     * LEAPBMGroupIterator: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class LEAPBMGroupIterator : public LEAPBMIterator {
    public:

        //DATA
        //===============
        
        //Iterator data
        handleType parentGroup;
        bool finished;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMGroupIterator();

        //Default Destructor
        ~LEAPBMGroupIterator();

        bool operator +=(Action *aAction);

        void reset();

        bool isWithinGroup(handleType aLAEInteractionHandle);
        bool isModelElementWithinGroup(ModelElement *aModelElement);

    private:

    };
    
}


#endif                          // MATIS_LEAPBMGROUPITERATOR_H
