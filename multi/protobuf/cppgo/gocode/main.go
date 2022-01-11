package main

import (
	"fmt"
	"reflect"
	"test_pb/pbtest"
	"unsafe"

	"google.golang.org/protobuf/proto"
)

/*
#cgo CFLAGS: -I ../
#cgo LDFLAGS: -L ../ -lhi
#include "hi.h"
*/
import "C"

func main() {

	ret := C.hi2()

	bh := reflect.SliceHeader{
		Data: uintptr(ret.p),
		Len:  int(ret.n),
		Cap:  int(ret.n),
	}
	bbb := *(*[]byte)(unsafe.Pointer(&bh))

	gohw := pbtest.Helloworld{}
	proto.Unmarshal(bbb, &gohw)
	fmt.Printf("gohw.Id: %v\n", *gohw.Id)
	fmt.Printf("gohw.Str: %v\n", *gohw.Str)
	fmt.Printf("gohw.Wow: %v\n", *gohw.Wow)

	fmt.Println("Hi, vim-go", ret)
	fmt.Printf("ret.n: %v\n", ret.n)

	fmt.Printf("bbb: %s\n", string(bbb))

}
