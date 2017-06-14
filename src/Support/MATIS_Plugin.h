// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Plugin.h,v $
// CVS $Date: 2005/11/16 06:06:38 $
// CVS $Revision: 1.2 $








#ifndef MATIS_PLUGIN_H
#define MATIS_PLUGIN_H
#include "MATIS_Types.h"
#include <string>
#include "dlc_base.h"
#include "MATIS_TypeConversion.h"

#ifdef MATIS_COMPILE
#define MATIS_PLUGIN_REGISTER(Cls) static DLC_MAKER<##Cls> DLC_Reg_##Cls(#Cls);
#else
#define MATIS_PLUGIN_REGISTER(Cls)
#endif

namespace MATIS {

    class Plugin: public DLC_BASE {
        
    public:

        void setIdentity(std::string thelabel, 
                         std::string theid);

        Plugin();
        virtual ~Plugin();

        bool attach();

        std::string label;
        std::string id;

        virtual bool configure(xmlDoc *doc, xmlNode *cur){
            LOGMSG(2, "No configuration method defined.\n");
            return true;
        };

    };

}

#endif                          // MATIS_PLUGIN_H
