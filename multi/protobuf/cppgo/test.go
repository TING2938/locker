package main

import (
	"fmt"
	"time"
)

func main() {
	for i := 0; i < 1000000; i++ {
		fmt.Println(i)
		time.Sleep(1 * time.Second)
	}
}
