// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_CheckerFedTime.h,v $
// CVS $Date: 2006/01/07 16:25:01 $
// CVS $Revision: 1.2 $

#ifndef MATIS_CHECKERFEDTIME_H
#define MATIS_CHECKERFEDTIME_H 1

#include "MATIS_Checker.h"

namespace MATIS {

    /**
     * CHECKER: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class CheckerFedTime : public Checker {
    public:

        //DATA
        //===============
        
        //usage string
        std::string usageString;

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        CheckerFedTime();

        //Default Destructor
        ~CheckerFedTime();
        
        bool checkValues(boost::any aValue, std::string byteValue);

    private:

        bool checkSingleValue(tokeniserType tokens, RTIfedTime aActionTime);
        bool checkRangeValues(tokeniserType tokens, RTIfedTime aActionTime);
        bool checkSetValues(tokeniserType tokens, RTIfedTime aActionTime);
        
    };
    
}


#endif                          // MATIS_CHECKERFEDTIME_H
