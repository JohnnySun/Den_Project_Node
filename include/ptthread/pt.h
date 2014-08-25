/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 */

#ifndef __PT_H__
#define __PT_H__

#include "lc.h"

struct pt { lc_t lc; };

#define PT_WAITING 0
#define PT_YIELDED 1
#define PT_EXITED  2
#define PT_ENDED   3

/*
Initializes a protothread. Initialization must be done prior to starting to execute the 
protothread 
*/
#define PT_INIT(pt)   LC_INIT((pt)->lc)

/* This macro used to declare a protothread. All protothreads must be declared with this macro.*/
#define PT_THREAD(name_args) char name_args

/*
This macro is used to declare the starting point of a protothread. It should be placed at 
the start of the function in which the protothread runs. All C statements above the PT_BEGIN()
invokation will be executed each time the protothread is scheduled. 
*/
#define PT_BEGIN(pt) { char PT_YIELD_FLAG = 1; LC_RESUME((pt)->lc)

/*
This macro is used for declaring that a protothread ends. It must always be used together with 
a matching PT_BEGIN() macro.
*/
#define PT_END(pt) LC_END((pt)->lc); PT_YIELD_FLAG = 0; \
                   PT_INIT(pt); return PT_ENDED; }

/*
Block and wait until condition is true.This macro blocks the protothread until the specified 
condition is true.
*/
#define PT_WAIT_UNTIL(pt, condition)	        \
  do {						\
    LC_SET((pt)->lc);				\
    if(!(condition)) {				\
      return PT_WAITING;			\
    }						\
  } while(0)

/*Block and wait while condition is true.This function blocks and waits while condition is true. */
#define PT_WAIT_WHILE(pt, cond)  PT_WAIT_UNTIL((pt), !(cond))

/*
Block and wait until a child protothread completes,This macro schedules a child protothread. 
The current protothread will block until the child protothread completes.
note The child protothread must be manually initialized with the PT_INIT() function before this 
function is used.
*/
#define PT_WAIT_THREAD(pt, thread) PT_WAIT_WHILE((pt), PT_SCHEDULE(thread))

/*
Spawn a child protothread and wait until it exits.This macro spawns a child protothread 
and waits until it exits. The macro can only be used within a protothread.
*/
#define PT_SPAWN(pt, child, thread)		\
  do {						\
    PT_INIT((child));				\
    PT_WAIT_THREAD((pt), (thread));		\
  } while(0)

/*
Restart the protothread. This macro will block and cause the running protothread to restart
its execution at the place of the PT_BEGIN() call.
*/
#define PT_RESTART(pt)				\
  do {						\
    PT_INIT(pt);				\
    return PT_WAITING;			\
  } while(0)

/*
Exit the protothread. This macro causes the protothread to exit. If the protothread was spawned 
by another protothread, the parent protothread will become unblocked and can continue to run.
*/
#define PT_EXIT(pt)				\
  do {						\
    PT_INIT(pt);				\
    return PT_EXITED;			\
  } while(0)

/*
Schedule a protothread.
This function shedules a protothread. The return value of the function is non-zero if the protothread 
is running or zero if the protothread has exited.
*/
#define PT_SCHEDULE(f) ((f) < PT_EXITED)

/* 
Yield from the current protothread.This function will yield the protothread, thereby allowing
other processing to take place in the system.
*/
#define PT_YIELD(pt)				\
  do {						\
    PT_YIELD_FLAG = 0;				\
    LC_SET((pt)->lc);				\
    if(PT_YIELD_FLAG == 0) {			\
      return PT_YIELDED;			\
    }						\
  } while(0)

/* This function will yield the protothread, until the specified condition evaluates to true.*/
#define PT_YIELD_UNTIL(pt, cond)		\
  do {						\
    PT_YIELD_FLAG = 0;				\
    LC_SET((pt)->lc);				\
    if((PT_YIELD_FLAG == 0) || !(cond)) {	\
      return PT_YIELDED;			\
    }						\
  } while(0)

#endif

