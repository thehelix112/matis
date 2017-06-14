// cistring.h:	extension of STL string class to do case-insensitive comparisons
//
//	ref:		N. Josuttis "The C++ Standard Library"	11.2.14
//
//	Mar 2002 . created [pjb]
//	Oct 2004 . additional comparison operators [pjb]
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CISTRING_H_20020320_)
#define AFX_CISTRING_H_20020320_

#include <string>
#include <iostream>
#include <cctype>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// case-insensitive replacement for std::char_traits<char> 
//
struct cichar_traits : public std::char_traits<char>  
{

    static bool eq(const char & c1, const char & c2)
    { return toupper(c1) == toupper(c2); }

    static bool lt(const char & c1, const char & c2)
    { return toupper(c1) < toupper(c2); }

    // compare up to n characters of s1 and s2
    static int compare(const char * s1, const char * s2, size_t n)
    { 
        for (size_t i = 0; i < n; ++i)
            if (!eq(s1[i], s2[i]))
                return lt(s1[i], s2[i]) ? -1 : 1;
        return 0;
    }

    //search c in s
    static const char * find(const char * s, size_t n, const char & c)
    {
        for (size_t i = 0; i < n; ++i)
            if (eq(s[i], c))
                return &(s[i]);
        return 0;
    }

};


// cistring typedef
//
typedef std::basic_string<char, cichar_traits> cistring;


// necessary output operator (s is just converted to an std::string)
//
static std::ostream & operator << (std::ostream & os, const cistring & s)
{
    return os << std::string(s.data(), s.length());
}


// operators for comparison with string types other than cistring
// - comparison is case-independent if either operand is a cistring
// - the remaining operand may be a std::string or a char *
//
#ifdef WIN32
inline bool __cdecl operator > (const cistring & _L, const std::string & _R)
#else
    inline bool operator > (const cistring & _L, const std::string & _R)
#endif
{ return (_L.compare(_R.c_str()) > 0); }

#ifdef WIN32
inline bool __cdecl operator > (const std::string & _L, const cistring & _R)
#else
    inline bool operator > (const std::string & _L, const cistring & _R)
#endif
{ return (_R.compare(_L.c_str()) < 0); }

#ifdef WIN32
inline bool __cdecl operator >= (const cistring & _L, const std::string & _R)
#else
    inline bool operator >= (const cistring & _L, const std::string & _R)
#endif
{ return (_L.compare(_R.c_str()) >= 0); }

#ifdef WIN32
inline bool __cdecl operator >= (const std::string & _L, const cistring & _R)
#else
    inline bool operator >= (const std::string & _L, const cistring & _R)
#endif
{ return (_R.compare(_L.c_str()) <= 0); }

#ifdef WIN32
inline bool __cdecl operator == (const cistring & _L, const std::string & _R)
#else
    inline bool operator == (const cistring & _L, const std::string & _R)
#endif
{ return (_L.compare(_R.c_str()) == 0); }

#ifdef WIN32
inline bool __cdecl operator == (const std::string & _L, const cistring & _R)
#else
    inline bool operator == (const std::string & _L, const cistring & _R)
#endif
{ return (_R.compare(_L.c_str()) == 0); }

#ifdef WIN32
inline bool __cdecl operator <= (const cistring & _L, const std::string & _R)
#else
    inline bool operator <= (const cistring & _L, const std::string & _R)
#endif
{ return (_L.compare(_R.c_str()) <= 0); }

#ifdef WIN32
inline bool __cdecl operator <= (const std::string & _L, const cistring & _R)
#else
    inline bool operator <= (const std::string & _L, const cistring & _R)
#endif
{ return (_R.compare(_L.c_str()) >= 0); }

#ifdef WIN32
inline bool __cdecl operator < (const cistring & _L, const std::string & _R)
#else
    inline bool operator < (const cistring & _L, const std::string & _R)
#endif
{ return (_L.compare(_R.c_str()) < 0); }

#ifdef WIN32
inline bool __cdecl operator < (const std::string & _L, const cistring & _R)
#else
    inline bool operator < (const std::string & _L, const cistring & _R)
#endif
{ return (_R.compare(_L.c_str()) > 0); }



#endif // !defined(AFX_CISTRING_H_20020320_)
