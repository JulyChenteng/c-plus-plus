#ifndef _CONFIG_H 
#define _CONFIG_H

#include "stl_alloc.h"

#ifdef _USE_MALLOC

typedef __malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;  //令alloc为第一级配置器

#else		   

#    define __NODE_ALLOCATOR_THREADS false
typedef __default_alloc_template<__NODE_ALLOCATOR_THREADS, 0> alloc;
 
#endif /* !_USE_MALLOC */

#endif