// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethodIterator.h,v $
// CVS $Date: 2005/12/04 15:43:48 $
// CVS $Revision: 1.2 $

#ifndef MATIS_LAEMETHODITERATOR_H
#define MATIS_LAEMETHODITERATOR_H 1

#include "MATIS_Types.h"
#include "MATIS_Action.h"

namespace MATIS {

    class LAEMethod;

    /**
     * LAEMethodIterator: class which is responsible for maintaining the
     * collection of groups between which the order of execution is unimportant.
     */
    class LAEMethodIterator {
    public:

        //DATA
        //===============
        
        //Iterator data


        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        LAEMethodIterator();

        //Default Destructor
        ~LAEMethodIterator();

        //current stage handle get method
        vertexLAEMethodStage getCurrentVertex();
        
        //current stage handle set method
        void setCurrentVertex(vertexLAEMethodStage aVertex);

        bool operator +(Action::ActionContextType nextContext);

        LAEMethod *parent;
        
    private:

    };
    
}


#endif                          // MATIS_LAEMETHODITERATOR_H
