#include <stdio.h>

typedef struct
{
    int integer;
    char *c_str;
    void *ptr;
    int array[8][2];
} TestStruct;

TestStruct *hello(TestStruct *pTestSt)
{
    printf("hello world\n");
    printf("%d || %s || %d\n", pTestSt->integer, pTestSt->c_str, pTestSt->array[2][1]);
    pTestSt->integer = 42;
    return pTestSt;
}
