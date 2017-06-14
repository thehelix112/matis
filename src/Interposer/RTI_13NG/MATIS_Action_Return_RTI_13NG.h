// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Action_Return_RTI_13NG.h,v $
// CVS $Date: 2006/01/08 12:46:13 $
// CVS $Revision: 1.2 $





#ifndef MATIS_ACTION_RETURN_RTI_13NG_H
#define MATIS_ACTION_RETURN_RTI_13NG_H

#include <RTI.hh>

// this should perform mappings via UniqueID mechanism, so one Action_Return_RTI_13NG
// value can be associated with multiple values so that retract() will work.

/**
 * MATIS_Action_Return_RTI_13NG: 
 */

namespace MATIS {
    
    class Action_Return_RTI_13NG {
    public:
        
        RTI::EventRetractionHandle valErh;
        handleType valHandle;
        RTI::Boolean valBool;
        RTI::AttributeHandleSet* valAHSPtr;
        RTI::Region* valRegionPtr;
        char *valStringPtr;
        RTI::RegionToken valRegionToken;
        
        Action_Return_RTI_13NG(){
            
            valErh.theSerialNumber = 0;
            valErh.sendingFederate = 0;
            valHandle = 0;
            valBool = RTI::RTI_FALSE;
            
        };

        Action_Return_RTI_13NG(const RTI::EventRetractionHandle & theerh) {

            valErh.theSerialNumber = theerh.theSerialNumber;
            valErh.sendingFederate = theerh.sendingFederate;

        }

        Action_Return_RTI_13NG(handleType thehandle) {

            valHandle = thehandle;
        }

        Action_Return_RTI_13NG(bool thebool) {

            valBool = (thebool) ? RTI::RTI_TRUE : RTI::RTI_FALSE;

        }

        // TODO
        // + exception info
        // + Action_Return_RTI_13NG handles (if due to making a getBlahHandle call)
        // 
        // also TODO, proper internalising and grouping of erh's.
    };

    
}


#endif

