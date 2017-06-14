// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Channel.h,v $
// CVS $Date: 2005/11/22 07:10:50 $
// CVS $Revision: 1.3 $





#ifndef MATIS_CHANNEL_H
#define MATIS_CHANNEL_H

#include "MATIS_UniqueHandleFactory.h"
//#include "MATIS_LEAPBM.h"

namespace MATIS {

    class Channel {

      public:

        //Data
        enum PROTOCOLS {
            PROTOCOL_NONE = 0,  // don't know if this is needed
            PROTOCOL_TRAMPOLINE = 1 << 0,
            PROTOCOL_RTI_13NG = 1 << 1,
            PROTOCOL_RTI_IEEE1516 = 1 << 2,
            PROTOCOL_DIS = 1 << 3,
            PROTOCOL_MATIS_SHM = 1 << 4,
            PROTOCOL_MATIS_CORBA = 1 << 5,
        };

        char protocol;          // char is probably not big enough..
        bool isExternal;

        //Static store of channels
        static UniqueHandleFactory < Channel *, 1 > channels;

        //Model model;
        
        //Functionality

        //Default Constructor
        Channel();

        
        //Default Destructor
        ~Channel(){};
        
        //Get model
        //void setModel(Model aModel);

        //Set model
        //Model getModel();


    };

    // note that channels using external MATIS like SHM and CORBA
    // will require some event processing, so there should be
    // a global method used at all interceptions (or at tick() type calls)
    // to perform network event polling and processing.
    // basically this method would call a process_events() function in
    // all channels that use external networking.

}
#endif
