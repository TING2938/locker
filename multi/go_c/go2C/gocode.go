package main

import "C"

import (
	"fmt"
)

//export Foo
func Foo(a, b int) int {
	return a + b
}

//export Bar
func Bar(s string) {
	fmt.Printf("I am bar, not foo! %s\n", s)
}

func main() {}
