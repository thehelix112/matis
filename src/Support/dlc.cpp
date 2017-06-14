// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: dlc.cpp,v $
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

#include "dlc_server.h"
#include "dlc_maker_base.h"
#include "MATIS_Types.h"


/////////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
#pragma warning (disable:4786)  // 255 character limit easily exceeded with STL
#endif


#ifdef _WIN32
#include <windows.h>

bool lt_dlinit() {
  return false;
}


void lt_dlclose(lt_dlhandle val) {
  if (val) {
    FreeLibrary((HMODULE)val);
  }
}


lt_dlhandle lt_dlopen(const char* filename) {
  lt_dlhandle module = LoadLibrary (filename);

  // TODO: implement search path, and failure checking if
  // returned module is already open (if so, LoadLibrary failed)

  return module;
}

bool lt_dlexit() {
  return false;
}

const char* lt_dlerror() {
  static char defaultval[] = "no error retrieval possible";
  return defaultval;
}

#endif


///////////////////////////////////////////////////////////////////////////////////

//explicit
DLC_MAKER_BASE::DLC_MAKER_BASE(std::string Id)
:  Identity(Id)
{
    DLC_Server.enter(Identity, this);
}

DLC_MAKER_BASE::~DLC_MAKER_BASE()
{
    DLC_Server.remove(Identity);
}


DLC_SERVER::DLC_SERVER()
{
    if (lt_dlinit()) {
        LOGMSG(0, "Error DLC_Server::cannot initialise dynamic loader\n");
        exit(1);
    }
}

DLC_SERVER::~DLC_SERVER()
{
    for (DLLMap::iterator iter = DLLs.begin(); iter != DLLs.end(); iter++)
        lt_dlclose(iter->second);   // JMW
    if (lt_dlexit()) {
        LOGMSG(0, "Error DLC_Server::cannot shut down dynamic loader\n");
    }
}

bool DLC_SERVER::load(const std::string & name)
{
    if (DLLs.find(name) != DLLs.end()) {
        // std::cerr << "ERROR DLC_Server::load: library " << name
        // << " already registered." << endl;
        return false;
    }
    lt_dlhandle tmp = lt_dlopen(name.c_str());  // JMW (, RTLD_NOW);

    if (!tmp) {
        LOGMSG(0, "Error: library  " << name
            << " found, but could not open");
        LOGMSG(0, "Error from dlopen was: " << lt_dlerror());

        return false;
    }
    DLLs[name] = tmp;
    return true;
}

void DLC_SERVER::unload(const std::string & name)
{
    DLLMap::iterator iter = DLLs.find(name);
    if (iter == DLLs.end()) {
        LOGMSG(0, "Error library " << name
            << " not registered.");
        return;
    }
    lt_dlclose(iter->second);
    DLLs.erase(iter);
}

DLC_BASE *DLC_SERVER::Get_Instance(const std::string & name)
{
    ClassMap::const_iterator iter = Classes.find(name);
    if (iter == Classes.end()) {
        // std::cerr << "ERROR DLC_Server::Get_Instance " << name <<
        // " not registered." << endl;
        return 0;
    }
    return (iter->second)->Create();
}

void DLC_SERVER::enter(const std::string & Id,
                       const DLC_MAKER_BASE * const ptr)
{
    if (Classes.find(Id) != Classes.end()) {
        // std::cerr << "ERROR DLC_Server::enter: class "
        // << Id << " already registered." << endl;
        return;
    }
    Classes[Id] = ptr;
}

void DLC_SERVER::remove(const std::string & Id)
{
    ClassMap::iterator iter = Classes.find(Id);
    if (iter == Classes.end()) {
        // std::cerr << "ERROR DLC_Server::remove: class "
        // << Id << " not registered." << endl;
        return;
    }
    Classes.erase(iter);
}



DLC_SERVER DLC_Server;
