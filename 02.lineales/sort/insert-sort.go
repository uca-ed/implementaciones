package main

import (
	"fmt"
)

func main() {
	var numeros = []int{15, 14, 13, 12, 10, 9, 8, 7, 6, 5}
	for i := 1; i < len(numeros); i++ {
		j := i
		for j > 0 && numeros[j] < numeros[j-1] {
			fmt.Println("swap")
			tmp := numeros[j]
			numeros[j] = numeros[j-1]
			numeros[j-1] = tmp
			j = j - 1
		}
	}

	for _, m := range numeros {
		fmt.Printf("%d\t", m)
	}

}
