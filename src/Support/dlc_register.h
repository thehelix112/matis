// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: dlc_register.h,v $
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

#ifndef DLC_REGISTER_H
#define DLC_REGISTER_H

/**
\file dlc_register.h
Definition of DLC_Register_Macro().
This header file must be included in every file containing a definition
of a dynamically loadable class.
*/

#ifdef _WIN32
#ifdef DSILIDLL_EXPORTS
#define DSILIDLL_API __declspec(dllexport)
#else
#define DSILIDLL_API __declspec(dllimport)
#endif
////DSILIDLL_API void InstallHook(DWORD ProcessId);
#endif	

#include "dlc_maker_base.h"

template < class T > class DLC_MAKER:public DLC_MAKER_BASE {
  public:
  explicit DLC_MAKER(std::string Id):DLC_MAKER_BASE(Id) {
    }

    virtual DLC_BASE *Create() const {
        return new T;
}};

/*!
\def DLC_Register_Macro(Cls)
This macro must be "called" for each dynamically loadable class.
It is just a shorthand for convenience.<br>
<tt>DLC_Register_Macro (foo)</tt> stands for<br>
<tt>static DLC_MAKER<foo> DLC_Reg_foo("foo");</tt>
\param Cls The name of the class
\example dlc_test.cxx
*/
#define DLC_Register_Macro(Cls) static DLC_MAKER<##Cls> ##Cls_DLC_Reg(#Cls); 

#endif
