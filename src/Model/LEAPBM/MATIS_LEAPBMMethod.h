// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSmethod: MATIS_LEAPBMMethod.h,v $
// CVS $Date: 2005/12/05 12:53:00 $
// CVS $Revision: 1.3 $

#ifndef MATIS_LEAPBMMETHOD_H
#define MATIS_LEAPBMMETHOD_H 1

#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMPROCESS: class which is responsible for maintaining the details of a 
     * general method call - NOT LAE method call.
     */
    class LEAPBMMethod : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Program data
        std::string id;
        std::string name;
        bool unrestricted;
        

        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMMethod();

        //Default Destructor
        ~LEAPBMMethod();

        //Constructor
        LEAPBMMethod(std::string aId,
                     std::string aName);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get unrestricted method
        bool getUnrestricted();

        //Set unrestricted method
        void setUnrestricted(bool aUnrestricted);


        //Get id method
        std::string getName();

        //Set id method
        void setName(std::string aName);

        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);

        NULL_POST_CONFIGURATION

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);

        //return a string hash of the current object
        std::string hash();


        
    private:
    };
    
}


#endif                          // MATIS_LEAPBMMETHOD_H
