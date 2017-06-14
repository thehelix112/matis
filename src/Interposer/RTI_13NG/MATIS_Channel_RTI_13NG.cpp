// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Channel_RTI_13NG.cpp,v $
// CVS $Date: 2006/01/04 15:01:22 $
// CVS $Revision: 1.4 $

#include "MATIS_Channel_RTI_13NG.h"

using namespace MATIS;

Channel_RTI_13NG::Channel_RTI_13NG() {

    protocol = PROTOCOL_RTI_13NG;
    externalHandles = new UniqueHandleFactory < bool, 0 >;
    internalRtiAmb = NULL;
    externalRtiAmb = NULL;
    externalFedAmb = NULL;
    internalFedAmb = NULL;
    external = true;

};

void Channel_RTI_13NG::print(Channel_RTI_13NG* aChannel){

    LOGMSG(1, "  protocol             = " << aChannel->protocol << "\n"
           << "  internalRTIAmb       = " << aChannel->internalRtiAmb << "\n"
           << "  internalFedAmb       = " << aChannel->internalFedAmb << "\n"
           << "  externalRTIAmb       = " << aChannel->externalRtiAmb << "\n"
           << "  externalFedAmb       = " << aChannel->externalFedAmb << "\n"
           << "  federate             = " << aChannel->federate << "\n"
           << "  federation           = " << aChannel->federation << "\n"
           << "  FEDFile              = " << aChannel->FEDFile << "\n"
           << "  federateHandle       = " << aChannel->federateHandle << "\n"
           << "  external             = " << ((aChannel->external) ? "true" : "false") << "\n");

}


bool Channel_RTI_13NG::initialise(){
    
    externalFedAmb = new MATIS_FederateAmbassador();
    externalRtiAmb = new RTI::RTIambassador;

   //set the reverse lookup from the external ambassadors reference to this channel
    Channel::channels.setIdToHandle(id, Channel_RTI_13NG::Hash(externalFedAmb));
    Channel::channels.setIdToHandle(id, Channel_RTI_13NG::Hash(externalRtiAmb));

    return true;
    
}


Channel_RTI_13NG::~Channel_RTI_13NG(){

    delete externalHandles;

};



RTI::RTIambassador* Channel_RTI_13NG::getActualRTIAmbassador(handleType aChannelId){
    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(aChannelId));

    if (channel) {

        if (channel->internalRtiAmb != NULL) {

            return channel->internalRtiAmb;

        } else {

            LOGMSG(2, "Warning, Actual RTI Ambassador is null.\n");

        }

    } else {

        LOGERR("Invalid channel handle.\n");

    }

    return NULL;

};

RTI::RTIambassador* Channel_RTI_13NG::getInterceptRTIAmbassador(handleType aChannelId){

    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(aChannelId));

    if (channel) {

        if (channel->externalRtiAmb != NULL) {

            return channel->externalRtiAmb;

        } else {

            LOGMSG(2, "Warning, Intercepting RTI Ambassador is null.\n");

        }

    } else {

        LOGERR("Invalid channel handle.\n");

    }

    return NULL;

};

RTI::FederateAmbassador* Channel_RTI_13NG::getActualFederateAmbassador(handleType aChannelId){

    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(aChannelId));

    if (channel) {

        if (channel->internalFedAmb != NULL) {

            return channel->internalFedAmb;

        } else {

            LOGMSG(2, "Warning, Actual Federate Ambassador is null.\n");

        }

    } else {

        LOGERR("Invalid channel handle.\n");

    }

    return NULL;

};

MATIS_FederateAmbassador* Channel_RTI_13NG::getInterceptFederateAmbassador(handleType aChannelId){

    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(aChannelId));

    if (channel) {

        if (channel->externalFedAmb != NULL) {

            return channel->externalFedAmb;

        } else {

            LOGMSG(2, "Warning, Intercepting Federate Ambassador is null.\n");

        }

    } else {

        LOGERR("Invalid channel handle.\n");

    }

    return NULL;

};

handleType Channel_RTI_13NG::getFederateHandle(handleType aChannelId){

    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(aChannelId));

    if (channel) {

        if (channel->federateHandle > 0) {

            return channel->federateHandle;

        } else {

            LOGMSG(2,"Warning, Federate handle is null.\n");

        }

    } else {

        LOGERR("Invalid channel handle.\n");

    }

    return 0;

};

std::string Channel_RTI_13NG::getFederateName(handleType aChannelId){

    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(aChannelId));

    if (channel) {

        if (channel->federate != "") {

            return channel->federate;

        } else {

            LOGMSG(2,"Warning, Federate name is null.\n");

        }

    } else {

        LOGERR("Invalid channel handle.\n");

    }

    return "";

};

std::string Channel_RTI_13NG::getFederationName(handleType aChannelId){

    Channel_RTI_13NG *channel = (Channel_RTI_13NG *)(Channel::channels.getValue(aChannelId));

    if (channel) {

        if (channel->federation != "") {

            return channel->federation;

        } else {

            LOGMSG(2,"Warning, Federation name is null.\n");

        }

    } else {

        LOGERR("Invalid channel handle.\n");

    }

    return "";

};

//*************************************************

//*************************************************
// These methods provides ways for getting the Handle for the channel.
//
// the channelId must be lookupable from either the fedamb, or the rtiamb!
// create a dedicated map for this in here.

handleType Channel_RTI_13NG::getChannelId(MATIS_FederateAmbassador* aMATISFedAmb){

    bool found = false;    
    std::string fullhan = Hash(aMATISFedAmb);
    handleType retval = 0;
    
    //try reverse lookup of the handle from this hash
    retval = Channel::channels.getExistingHandle(fullhan);
    
    if(retval == 0){
        //lookup didn't work and we have a new channel
        //return a new handle - this shouldn't happen
        LOGERR("Failed lookup of channelId from MATIS Federate Ambassador. Problew with reverse lookup in hook joinFederationExecution probable.\n");
        return Channel::channels.getUniqueHandle(fullhan, &found);
    } else {
        //lookup worked and we have an existing channel
        //return its handle
        return retval;
    }    

};

handleType Channel_RTI_13NG::getChannelId(RTI::RTIambassador* aRTIRTIAmb){

    bool found = false;    
    std::string fullhan = Hash(aRTIRTIAmb);
    handleType retval = 0;
    
    //try reverse lookup of the handle from this hash
    retval = Channel::channels.getExistingHandle(fullhan);
    
    if(retval == 0){
        //lookup didn't work and we have a new channel
        //return a new handle
        return Channel::channels.getUniqueHandle(fullhan, &found);
    } else {
        //lookup worked and we have an existing channel
        //return its handle
        return retval;
    }

};

handleType Channel_RTI_13NG::getChannelId(RTI::FederateAmbassador* aRTIFedAmb){

    LOGERR("Lookup of RTI federate ambassador can't happen because no reverse lookup is set\n");

    
    bool found = false;    
    std::string fullhan = Hash(aRTIFedAmb);
    handleType retval = 0;
    
    //try reverse lookup of the handle from this hash
    retval = Channel::channels.getExistingHandle(fullhan);
    
    if(retval == 0){
        //lookup didn't work and we have a new channel
        //return a new handle - this shouldn't happen
        LOGWRN("Failed lookup of channelId from MATIS Federate Ambassador. Problew with reverse lookup in hook joinFederationExecution probable.\n");
        return Channel::channels.getUniqueHandle(fullhan, &found);
    } else {
        //lookup worked and we have an existing channel
        //return its handle
        return retval;
    }

};




std::string Channel_RTI_13NG::Hash(MATIS_FederateAmbassador* aInterceptFedAmb){

    return Hash((handleType) aInterceptFedAmb);

};

std::string Channel_RTI_13NG::Hash(RTI::FederateAmbassador* aActualFedAmb){

    return Hash((handleType) aActualFedAmb);

};

std::string Channel_RTI_13NG::Hash(RTI::RTIambassador* aActualRtiAmb){

    return Hash((handleType) aActualRtiAmb);

};


std::string Channel_RTI_13NG::Hash(handleType aAmbassadorPtr){

    char buffer[5];    
    *(handleType *) (&(buffer[0])) = (char) PROTOCOL_RTI_13NG;
    *(handleType *) (&(buffer[1])) = aAmbassadorPtr;
    return std::string(buffer, 5);

};
