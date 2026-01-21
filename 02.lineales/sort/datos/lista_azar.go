package main

import (
	"fmt"
	"os"
	"math/rand/v2"
	"strconv"
)


func main() {
	cantidad := 10000
	fmt.Println(cantidad)
	if (len(os.Args) >= 2 ) {
		cantidad, _ = strconv.Atoi(os.Args[1])
	}
	
	fmt.Println(cantidad)
	for i:=0; i < cantidad; i++ {
		fmt.Println(rand.IntN(150000))
	}

}
