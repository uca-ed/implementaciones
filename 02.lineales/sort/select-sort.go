package main

import (
	"fmt"
)

func main() {
	var numeros = []int {15, 14, 13, 12, 10, 9, 8, 7, 6, 5}
	//var indice_menor, clave_menor int
	for i := 0; i < len(numeros)-1; i++ {
		indice_menor := i
		clave_menor := numeros[i]
		for j := i + 1; j < len(numeros); j++ {
			if numeros[j] < clave_menor {
				clave_menor = numeros[j]
				indice_menor = j
			}
		}
		fmt.Println("swap")
		tmp := numeros[i]
		numeros[i] = numeros[indice_menor]
		numeros[indice_menor] = tmp
	}

	for _, m := range numeros {
		fmt.Printf("%d\t", m)
	}

}
