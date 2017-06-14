// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerHandleSet.h,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.1 $

#ifndef MATIS_CHECKERHANDLESET_H
#define MATIS_CHECKERHANDLESET_H 1

#include "MATIS_Checker.h"

namespace MATIS {

    /**
     * CHECKER: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class CheckerHandleSet : public Checker {
    public:

        //DATA
        //===============
        
        //LAE data

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        CheckerHandleSet();

        //Default Destructor
        ~CheckerHandleSet();
        
        bool checkValues(boost::any aValue, std::string byteValue);

    };
    
}


#endif                          // MATIS_CHECKERHANDLESET_H
