// Copyright 2004 David Andrews
// Authors: David Andrews
// CVS $RCSfile: MATIS_LAEMethodIterator.cpp,v $
// CVS $Date: 2005/12/04 15:43:48 $
// CVS $Revision: 1.3 $

#include "MATIS_LAEMethodIterator.h"
#include "MATIS_LAEMethodStage.h"
#include "MATIS_Model.h"
#include "MATIS_LAESet.h"
#include "MATIS_Action_RTI_13NG.h"

using namespace MATIS;

//Default Constructor
LAEMethodIterator::LAEMethodIterator(){
    
    
};

//Default Destructor
LAEMethodIterator::~LAEMethodIterator(){
    
};

//current stage handle get method
vertexLAEMethodStage LAEMethodIterator::getCurrentVertex(){

    return currentVertex;

};

//current stage handle set method
void LAEMethodIterator::setCurrentVertex(vertexLAEMethodStage aVertex){

    currentVertex = aVertex;

};


