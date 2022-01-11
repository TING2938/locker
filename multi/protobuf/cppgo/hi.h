#ifndef __HI_TEST__
#define __HI_TEST__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct 
{
    void* p;
    size_t n;
} Gostr;


Gostr hi2();



#ifdef __cplusplus
}
#endif

#endif // !__HI_TEST__
