// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_FunctionExistsInRTIHandleSet.h,v $
// CVS $Date: 2005/12/01 14:37:15 $
// CVS $Revision: 1.1 $

#ifndef MATIS_FUNCTIONEXISTSINRTIHANDLESET_H
#define MATIS_FUNCTIONEXISTSINRTIHANDLESET_H 1

#include "MATIS_Function.h"

namespace MATIS {

    /**
     * CHECKER: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class FunctionExistsInRTIHandleSet : public Function {
    public:

        //DATA
        //===============
        
        //LAE data

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        FunctionExistsInRTIHandleSet();

        //Default Destructor
        ~FunctionExistsInRTIHandleSet();
        
        //bool checkValues(boost::any aValue, std::string byteValue);

    };
    
}


#endif                          // MATIS_FUNCTIONEXISTSINRTIHANDLESET_H
