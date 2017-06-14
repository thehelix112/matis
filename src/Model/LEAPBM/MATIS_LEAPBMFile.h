// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LEAPBMFile.h,v $
// CVS $Date: 2005/12/01 14:31:56 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LEAPBMFILE_H
#define MATIS_LEAPBMFILE_H 1

#include "MATIS_LEAPBMMethod.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_Types.h"

namespace MATIS {

    /**
     * LEAPBMPROCESS: class which is responsible for maintaining the
     * execution processs of logical entity abstracted program behaviour
     * models.
     */
    class LEAPBMFile : public Hashable, public ModelElement {
    public:

        //DATA
        //===============
        
        //Program data
        std::string id;
        std::string path;

        //Methods
        handleListType methods;


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LEAPBMFile();

        //Default Destructor
        ~LEAPBMFile();

        //Constructor
        LEAPBMFile(std::string aId,
                          std::string aPath);

        //Get id method
        std::string getId();

        //Set id method
        void setId(std::string aId);

        //Get id method
        std::string getPath();

        //Set id method
        void setPath(std::string aPath);


        //Add a Method condition to the process
        void addMethod(LEAPBMMethod aMethod);

        //Delete a Method condition
        void removeMethod(LEAPBMMethod aMethod);

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


#endif                          // MATIS_LEAPBMFILE_H
