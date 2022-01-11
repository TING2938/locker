#include "func1.h"
#include "func2.h"
#include <stdio.h>

int func2(int a, int b, int c)
{
    printf("call func2\n");
    return func1(a, b) + c;
}
