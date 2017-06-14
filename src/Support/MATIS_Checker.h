// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_Checker.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $

#ifndef MATIS_CHECKER_H
#define MATIS_CHECKER_H 1

#include "MATIS_Types.h"
#include "MATIS_Plugin.h"

namespace MATIS {

    /**
     * CHECKER: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class Checker : public Plugin {
    public:

        //DATA
        //===============
        
        //LAE data

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        Checker();

        //Default Destructor
        ~Checker();
        
        //Get Id method
        std::string getId();

        //Set Id method
        void setId(std::string aId);

        virtual bool checkValues(boost::any aValue, std::string byteValue);

        bool configure(xmlDoc *, xmlNode *);

        static Checker *getDefaultChecker();
        
    private:

        static Checker *defaultChecker;

    };
    
}


#endif                          // MATIS_CHECKER_H
