// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: dlc_server.h,v $
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

#ifndef DLC_SERVER_H
#define DLC_SERVER_H

#ifndef _WIN32
#include <ltdl.h>

#else

//#include <wtypes.h>
//typedef HMODULE lt_dlhandle;

typedef void * lt_dlhandle;

#endif

/**
  \file dlc_server.h
  Declaration of the DLC_Server class and the New<>() template.
 */

#include <string>
#include <map>

class DLC_BASE;

/**
  \class DLC_SERVER dlc_server.h dlc_server.h
  A class holding information about dynamically loaded libraries and classes.
 */
class DLC_SERVER {

    friend class DLC_MAKER_BASE;

  private:
    typedef std::map < const std::string, const DLC_MAKER_BASE *>ClassMap;
    typedef std::map < const std::string, lt_dlhandle > DLLMap;

    ClassMap Classes;
    DLLMap DLLs;

    void enter(const std::string & Id, const DLC_MAKER_BASE * const ptr);
    void remove(const std::string & Id);

  public:
     DLC_SERVER();
    ~DLC_SERVER();

    /* 
     * !
     * Loads the requested library and registers all classes in that
     * library
     * \param name The name of the library (preferably with path).
     * \return true on success, else false.
     */
    bool load(const std::string & name);
    /* 
     * !
     * Unloads the requested library.
     * \warning Before unloading, make sure that no class defined in the
     * library is still in use, or you will be in deep trouble!
     * 
     * \param name The name of the library (preferably with path).
     */
    void unload(const std::string & name);
    DLC_BASE *Get_Instance(const std::string & name);
};

/*!
  Creates a new instance of class \e name and casts the resulting
  pointer to a \e T \e *.
 */
#ifdef __DECCXX
template < class T > T * New(const std::string & name, T * dummy = NULL)
#else
template < class T > T * New(const std::string & name)
#endif
{
    DLC_BASE *tmp = DLC_Server.Get_Instance(name);
    T *tmp2 = dynamic_cast < T * >(tmp);

    if (tmp2)
        return tmp2;
    delete tmp;

    return 0;
}

/*!
  The global DLC server.
 */
extern DLC_SERVER DLC_Server;

#endif
