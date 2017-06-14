// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_TypeConversion.cpp,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $








#include "MATIS_TypeConversion.h"
#include "MATIS_Action.h"

using namespace MATIS;

bool TypeConversion::getMeta(const handleValuePairSetType& aHVPS,
                             handleType aHandle, 
                             boost::any* aValue){

    handleValuePairSetType::const_iterator it = aHVPS.find(aHandle);

    if (it == aHVPS.end()) {
        LOGWRN("Handle not found in handle value pair set\n");
        return false;
    } else {
        *aValue = (*it).second;
        return true;
    }
}
