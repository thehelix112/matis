// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_ModelIterator.h,v $
// CVS $Date: 2006/01/03 12:20:04 $
// CVS $Revision: 1.2 $





#ifndef MATIS_MODELITERATOR_H
#define MATIS_MODELITERATOR_H

#include "MATIS_Action.h"
#include "MATIS_ConfigurationStore.h"
#include "MATIS_ModelIterator.h"

namespace MATIS {

    class ModelIterator {

      public:
        
        /* Data */
        handleType currentPoint;

        /* Functionality */

        virtual bool operator +=(Action *aAction);

        /* Static Functionality */


    };


}
#endif //MATIS_MODELITERATOR_H
