//////////////////////////////////////////////
// StdAfx.h

// This file is used for precompiled headers
// Rarely modified header files should be included.

// Based on code provided by Lynn Allan


#ifndef STDAFX_H
#define STDAFX_H


// Predefinitions for windows.h go here
//#define WIN32_LEAN_AND_MEAN   // Exclude rarely-used stuff from Windows headers
#include "targetver.h"          // Set the supported window features

// Specify Win32xx specific predefinitions here
//#define NO_USING_NAMESPACE        // Don't use Win32xx namespace

typedef  unsigned char  byte;

#if defined(_MSC_VER) && _MSC_VER == 1200   // For Visual Studio 6
    #pragma warning (disable : 4786)  // identifier was truncated
    #pragma warning (disable : 4702)  // unreachable code (bugs in Microsoft's STL)
#endif

// Rarely modified header files should be included here
#include <vector>
#include <map>
#include <string>
#include <sstream>      // Add support for stringstream
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

#include <controls.h>
#include <dialog.h>
#include <docking.h>
#include <file.h>
#include <frame.h>
#include <gdi.h>
#include <listview.h>
#include <mdi.h>
#include <propertysheet.h>
#include <rebar.h>
#include <ribbon.h>
#include <socket.h>
#include <statusbar.h>
#include <stdcontrols.h>
#include <toolbar.h>
#include <treeview.h>
#include <webbrowser.h>
#include <wincore.h>


#endif
