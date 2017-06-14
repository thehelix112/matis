// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerInteractionClassName.h,v $
// CVS $Date: 2006/01/05 08:06:09 $
// CVS $Revision: 1.1 $

#ifndef MATIS_CHECKERINTERACTIONCLASSNAME_H
#define MATIS_CHECKERINTERACTIONCLASSNAME_H 1

#include "MATIS_Checker.h"

namespace MATIS {

    /**
     * CHECKER: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class CheckerInteractionClassName : public Checker {
    public:

        //DATAg
        //===============
        
        //LAE data

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        CheckerInteractionClassName();

        //Default Destructor
        ~CheckerInteractionClassName();
        
        bool checkValues(boost::any aValue, std::string byteValue);

    };
    
}


#endif                          // MATIS_CHECKERINTERACTIONCLASSNAME_H
