package main

import "fmt"

/*
#cgo CFLAGS: -I ../ccode
#cgo LDFLAGS: -L ../ccode -lhi
#include "hi.h" //非标准c头文件，所以用引号
*/
import "C"

func main() {
	C.hi(C.CString("ddf"))
	fmt.Println("Hi, vim-go")

}
