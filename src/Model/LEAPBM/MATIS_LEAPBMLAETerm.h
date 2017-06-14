// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMLAETerm.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LEAPBMLAETERM_H
#define MATIS_LEAPBMLAETERM_H 1

#include "MATIS_Types.h"
#include "MATIS_ConfigurationElement.h"

namespace MATIS {

    class LAESet;

    /**
     * LEAPBMLAETerm: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class LEAPBMLAETerm : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //LAETerm data
        std::string id;
        std::string version;
        std::string path;

        LAESet *LAEs;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMLAETerm();

        //Default Destructor
        ~LEAPBMLAETerm();

        //Constructor
        LEAPBMLAETerm(std::string aId,
                      std::string aVersion,
                      std::string aPath);

        //Get Id method
        std::string getId();

        //Set Id method
        void setId(std::string aId);

        //Get Version method
        std::string getVersion();

        //Set Version method
        void setVersion(std::string aVersion);

        //Get Path method
        std::string getPath();

        //Set Path method
        void setPath(std::string aPath);

        
        //Load the configuration
        bool loadConfiguration(ConfigurationElement *aElement);
        bool postConfigurationLoad();

        //Save the configuration
        bool saveConfiguration(ConfigurationElement *aElement);


        //return a string hash of the current object
        std::string hash();

        
    private:

    };
    
}


#endif                          // MATIS_LEAPBMLAETERM_H
