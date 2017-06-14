// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_Function.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_FUNCTION_H
#define MATIS_FUNCTION_H 1

#include "MATIS_Types.h"
#include "MATIS_Plugin.h"

namespace MATIS {

    /**
     * FUNCTION: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class Function : public Plugin {
    public:

        //DATA
        //===============
        
        //LAE data

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        Function();

        //Default Destructor
        ~Function();
        
        //Get Id method
        std::string getId();

        //Set Id method
        void setId(std::string aId);

    };
    
}


#endif                          // MATIS_FUNCTION_H
