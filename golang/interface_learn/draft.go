package main

import "fmt"

type Chicken struct {
}

func (c *Chicken) isChicken() bool {
	fmt.Print("is chicken")
	return true
}

func main() {
	chi := Chicken{}
	a := chi.isChicken()
	fmt.Printf("a: %v\n", a)
}
