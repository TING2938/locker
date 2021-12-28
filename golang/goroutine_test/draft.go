package main

import (
	"fmt"
	"time"
)

func sum(s []int, sleep int, c chan int) {
	sum := 0
	for _, i := range s {
		sum += i
	}
	time.Sleep(time.Duration(sleep) * time.Second)
	fmt.Printf("calc sum finished\n")
	c <- sum
	time.Sleep(5 * time.Second)
	fmt.Print("channel finished\n")
}

func main() {
	s := []int{1, 2, 3, 4, 5, 6, 7, 8}

	c1 := make(chan int)
	c2 := make(chan int)
	go sum(s[:len(s)/2], 5, c1)
	go sum(s[len(s)/2:], 8, c2)
	x, y := <-c1, <-c2
	fmt.Printf("x: %v\n", x)
	fmt.Printf("y: %v\n", y)
}
