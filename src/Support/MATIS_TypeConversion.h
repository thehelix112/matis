// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_TypeConversion.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $








#ifndef MATIS_TYPECONVERSION_H
#define MATIS_TYPECONVERSION_H 1

#include "MATIS_Action.h"
#include "MATIS_Types.h"

namespace MATIS {

	class TypeConversion {

	public:

       static bool getMeta(const handleValuePairSetType& aHVPS,
                           handleType aHandle, 
                           boost::any* aValue);

	};

}
#endif                          // MATIS_TYPECONVERSION_H
