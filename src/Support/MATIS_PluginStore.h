// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_PluginStore.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $








#ifndef MATIS_PLUGINSTORE_H
#define MATIS_PLUGINSTORE_H

#include "dlc_server.h"
#include "MATIS_Plugin.h"
#include "MATIS_Checker.h"
#include "MATIS_Function.h"

namespace MATIS {

    class PluginStore {

        typedef std::map < const char *,
                           std::string > FileNameHashType;
        
    protected:
        
        PluginStore();        

        FileNameHashType functionFilenames;
        FileNameHashType functionNames;

        FileNameHashType checkerFilenames;
        FileNameHashType checkerNames;

    public:

        static Function* getFunction(std::string aId);
        static void setFunctionFilename(std::string aId, std::string aFilename);
        static void setFunctionName(std::string aId, std::string aName);

        static Checker* getChecker(std::string aId);
        static void setCheckerFilename(std::string aId, std::string aFilename);
        static void setCheckerName(std::string aId, std::string aName);
        
        static PluginStore *getStore();
        Plugin *getInstance(std::string aName, std::string aSuggestedPath = "");

        void initialise();

    private:

        std::string getPluginFullPath(std::string aName);

        /**
         * @link
         * @shapeType PatternLink
         * @pattern Singleton
         * @supplierRole Singleton factory 
         */
        /* 
         * # PluginStore _dsilI_PluginStore; 
         */
        static PluginStore *store;
    };

}
#endif                          // MATIS_PLUGINSTORE_H
