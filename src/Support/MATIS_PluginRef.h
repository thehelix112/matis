// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_PluginRef.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $







#ifndef MATIS_PLUGINREF_H
#define MATIS_PLUGINREF_H

#include "MATIS_Types.h"
#include <string>
#include <list>

namespace MATIS 
{
	class PluginRef
	{
	public:

		void configure(xmlDocPtr doc, xmlNodePtr cur);

		std::string classname;
		std::string type;
		std::string filename;
		
	};	
}



#endif
