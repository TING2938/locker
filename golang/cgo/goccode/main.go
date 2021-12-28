package main

import (
	"bytes"
	"fmt"
	"unsafe"
)

/*
#include <stdio.h>

struct Student {
	char Name[20];
	int Len;
};

void printStr(void* ptr, int len) {
	printf("len: %d\n", len);
	char* p = (char*)ptr;
	for (int i = 0; i < len; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");
	// printf("p.Name: %s\n", p->Name);
}

void hi() {
    printf("hello world!\n");
}

*/
import "C"

func main() {
	var b bytes.Buffer

	Len := 0
	len := 0

	len, _ = b.WriteString("hello")
	Len += len
	len, _ = b.WriteString("world")
	Len += len
	C.printStr((unsafe.Pointer(&b.Bytes()[0])), C.int(b.Len()))
	fmt.Printf("b.String(): %v\n", b.String())
	b.Reset()
}
