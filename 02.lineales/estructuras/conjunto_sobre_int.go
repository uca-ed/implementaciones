package main

import (
	"fmt"
)

const TAMANO = 32 // Usamos 32 bits para un uint32

// Mostrar los elementos del conjunto
func imprimir(set uint32, universal []byte) {
	fmt.Print("{ ")
	for i := 0; i < TAMANO; i++ {
		if set&(1<<i) != 0 {
			fmt.Printf("%c ", universal[i])
		}
	}
	fmt.Println("}")
}

// Agregar un elemento al conjunto
func agregar(set uint32, elemento int) uint32 {
	if elemento >= 0 && elemento < TAMANO {
		set |= (1 << elemento)
	}
	return set
}

// Eliminar un elemento del conjunto
func quitar(set uint32, elemento int) uint32 {
	if elemento >= 0 && elemento < TAMANO {
		set &= ^(1 << elemento)
	}
	return set
}

// Verificar si un elemento está en el conjunto
func pertenece(set uint32, elemento int) bool {
	if elemento >= 0 && elemento < TAMANO {
		return (set & (1 << elemento)) != 0
	}
	return false
}

// Unión de dos conjuntos
func unionSet(set1, set2 uint32) uint32 {
	return set1 | set2
}

// Intersección de dos conjuntos
func interseccion(set1, set2 uint32) uint32 {
	return set1 & set2
}

// Diferencia de conjuntos (set1 - set2)
func diferencia(set1, set2 uint32) uint32 {
	return set1 & ^set2
}

// Complemento de un conjunto
func complemento(set uint32) uint32 {
	return ^set
}

// Cardinalidad de un conjunto
func cardinalidad(set uint32) int {
	resp := 0
	aux := uint32(0)
	for set != 0 {
		aux = set - 1
		set = set & aux
		resp++
	}
	return resp
}

func main() {
	var setA uint32 = 0 // Conjunto vacío
	var setB uint32 = 0 // Conjunto vacío
	universal := make([]byte, TAMANO)

	for i := 0; i < TAMANO; i++ {
		universal[i] = byte('A' + i)
	}

	fmt.Printf("Tamaño máximo del conjunto: %d\nUniversal: {", TAMANO)
	// Muestro el universal
	for i := 0; i < TAMANO; i++ {
		if i == 0 {
			fmt.Printf("%c", universal[i])
		} else {
			fmt.Printf(", %c", universal[i])
		}
	}
	fmt.Println("}")

	// Agregar elementos a setA
	setA = agregar(setA, 1)
	setA = agregar(setA, 3)
	setA = agregar(setA, 5)

	// Agregar elementos a setB
	setB = agregar(setB, 3)
	setB = agregar(setB, 4)
	setB = agregar(setB, 5)

	fmt.Print("Conjunto A: ")
	imprimir(setA, universal)

	fmt.Print("Conjunto B: ")
	imprimir(setB, universal)

	fmt.Print("Unión de A y B: ")
	imprimir(unionSet(setA, setB), universal)

	fmt.Print("Intersección de A y B: ")
	imprimir(interseccion(setA, setB), universal)

	fmt.Print("Diferencia A - B: ")
	imprimir(diferencia(setA, setB), universal)

	fmt.Print("Complemento de A: ")
	imprimir(complemento(setA), universal)

	if pertenece(setA, 3) {
		fmt.Println("¿El elemento 3 (D) está en A? Sí")
	} else {
		fmt.Println("¿El elemento 3 (D) está en A? No")
	}

	if pertenece(setA, 2) {
		fmt.Println("¿El elemento 2 (C) está en A? Sí")
	} else {
		fmt.Println("¿El elemento 2 (C) está en A? No")
	}

	// Eliminar un elemento
	setA = quitar(setA, 3)
	fmt.Print("Conjunto A después de eliminar 3: ")
	imprimir(setA, universal)

	fmt.Printf("Cardinalidad de A: %d\n", cardinalidad(setA))
}
