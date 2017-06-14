// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Channel_RTI_13NG.h,v $
// CVS $Date: 2005/12/01 04:43:33 $
// CVS $Revision: 1.3 $





#ifndef MATIS_CHANNEL_RTI_H
#define MATIS_CHANNEL_RTI_H

#include "MATIS_Channel.h"
#include "MATIS_UniqueHandleFactory.h"
#include "MATIS_RTIAmbassador.h"
#include "MATIS_FederateAmbassador.h"
#include "MATIS_Types.h"

namespace MATIS {

    class Channel_RTI_13NG: public Channel {
      public:

        Channel_RTI_13NG();
        ~Channel_RTI_13NG();

        handleType id;
        std::string federation;
        std::string federate;
        std::string FEDFile;
        std::string xmlId;
        handleType federateHandle;
        bool external;

        UniqueHandleFactory < bool, 0 >* externalHandles;

        // rti and fed ambassador pointers,
        // plus flag (inherited from Channel (is_internal)) to 
        // indicate whether the channel is between application
        // and MATIS or between MATIS and RTI (thus allowing determination
        // of how to call rti/fed functions

        RTI::RTIambassador* internalRtiAmb;
        RTI::RTIambassador* externalRtiAmb;
        MATIS_FederateAmbassador* externalFedAmb;
        RTI::FederateAmbassador* internalFedAmb;

        // initialise this class to have all the appropriate ambassadors
        bool initialise();

        // print a channel
        static void print(Channel_RTI_13NG* aChannel);

        // *************************************************
        // These methods provide means to extract information about a
        // RTI_13NG 
        // channel from Model::channels

        static RTI::RTIambassador* getActualRTIAmbassador(handleType channelId);
        static RTI::RTIambassador* getInterceptRTIAmbassador(handleType channelId);
        static RTI::FederateAmbassador* getActualFederateAmbassador(handleType channelId);
        static MATIS_FederateAmbassador* getInterceptFederateAmbassador(handleType channelId);
        static std::string getFederateName(handleType channelId);
        static std::string getFederationName(handleType channelId);
        handleType getFederateHandle(handleType channelId);
		

        // *************************************************

        // *************************************************
        // These methods provides ways for getting the Handle for the
        // channel.

        static handleType getChannelId(MATIS_FederateAmbassador* aDSILIFedAmb);
        static handleType getChannelId(RTI::RTIambassador* aRTIRTIAmb);
        static handleType getChannelId(RTI::FederateAmbassador* aRTIFedAmb);


        // *************************************************

        static std::string Hash(MATIS_FederateAmbassador* interceptFedAmb);
        static std::string Hash(RTI::FederateAmbassador* actualFedAmb);
        static std::string Hash(RTI::RTIambassador* actualRtiAmb);
        static std::string Hash(handleType ambassadorPtr);

    };

}

#endif
