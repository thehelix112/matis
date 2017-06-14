// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_Hashable.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $





#ifndef MATIS_HASHABLE_H
#define MATIS_HASHABLE_H

#include "MATIS_Types.h"

namespace MATIS {

    class Hashable {

      public:

        //Functionality
        virtual std::string hash() = 0;

        static std::string hashObject(objectType aObjectType, 
                                      std::string id){
            
            char buffer[4];
            *(int*) (&(buffer[0])) = aObjectType;
            return std::string(buffer, 4)+id;
            
        };

    };

}
#endif //MATIS_HASHABLE_H
