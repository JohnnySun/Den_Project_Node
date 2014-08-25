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
