// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerHandleValuePairSet.h,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.1 $

#ifndef MATIS_CHECKERHANDLEVALUEPAIRSET_H
#define MATIS_CHECKERHANDLEVALUEPAIRSET_H 1

#include "MATIS_Checker.h"

namespace MATIS {

    /**
     * CHECKER: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class CheckerHandleValuePairSet : public Checker {
    public:

        //DATA
        //===============
        
        //LAE data

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        CheckerHandleValuePairSet();

        //Default Destructor
        ~CheckerHandleValuePairSet();
        
        bool checkValues(boost::any aValue, std::string byteValue);

    };
    
}


#endif                          // MATIS_CHECKERHANDLEVALUEPAIRSET_H
