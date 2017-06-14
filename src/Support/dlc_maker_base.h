// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: dlc_maker_base.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $






/*
 *  DLC - Utility for dynamic loading of classes
 *  Copyright (C) 1999/2000 Martin Reinecke
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  See the README file for more information.
 */

#ifndef DLC_MAKER_BASE_H
#define DLC_MAKER_BASE_H

#include <string>


class DLC_MAKER_BASE {
private:
	std::string Identity;
	
public:
	explicit DLC_MAKER_BASE(std::string Id);
	virtual ~ DLC_MAKER_BASE();
	
	virtual DLC_BASE *Create() const = 0;
};
 


#endif
