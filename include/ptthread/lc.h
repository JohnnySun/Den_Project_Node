/*	A part of node
	Den Project
	Copyright 2007-2014 BMY-Soft

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifdef DOXYGEN
  #define LC_INIT(lc)
  #define LC_SET(lc)
  #define LC_RESUME(lc)
  #define LC_END(lc)
#endif


#ifndef __LC_H__
  #define __LC_H__
  #ifdef LC_INCLUDE
    #include LC_INCLUDE
  #else
    #include "lc-sw.h"
  #endif
#endif
