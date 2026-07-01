package main

import (
	"fmt"
)

// Estructura de Pila (Stack)
type ExpresionStack struct {
	arreglo [100]int
	tope    int
}

// Estructura de Cola (Queue)
type ExpresionQueue struct {
	arreglo   [100]byte
	principio int
	tamano    int
}

// Funciones para la Pila
func inicializarExpresionStack(pila *ExpresionStack) {
	pila.tope = -1
}

func pushExpresion(pila *ExpresionStack, valor int) {
	if pila.tope < 99 {
		pila.tope++
		pila.arreglo[pila.tope] = valor
	}
}

func popExpresion(pila *ExpresionStack) int {
	if pila.tope >= 0 {
		valor := pila.arreglo[pila.tope]
		pila.tope--
		return valor
	}
	return -1
}

func expresionStackVacia(pila *ExpresionStack) bool {
	return pila.tope == -1
}

// Funciones para la Cola
func inicializarExpresionQueue(cola *ExpresionQueue) {
	cola.principio = 0
	cola.tamano = 0
}

func enqueueExpresion(cola *ExpresionQueue, valor byte) {
	if cola.tamano < 100 {
		cola.arreglo[(cola.principio+cola.tamano)%100] = valor
		cola.tamano++
	}
}

func dequeueExpresion(cola *ExpresionQueue) byte {
	if cola.tamano > 0 {
		valor := cola.arreglo[cola.principio]
		cola.tamano--
		cola.principio = (cola.principio + 1) % 100
		return valor
	}
	return 0
}

func expresionQueueVacia(cola *ExpresionQueue) bool {
	return cola.tamano == 0
}

func main() {
	var pila ExpresionStack
	var cola ExpresionQueue

	inicializarExpresionStack(&pila)
	inicializarExpresionQueue(&cola)

	expresion := "12+64-*33*21-/+96-31+*36*36++*+"

	var operandoB, operandoA, resultado int
	var caracter byte

	// Cargar expresión en la cola
	for i := 0; i < len(expresion); i++ {
		enqueueExpresion(&cola, expresion[i])
	}

	for !expresionQueueVacia(&cola) {
		caracter = dequeueExpresion(&cola)
		if caracter >= '0' && caracter <= '9' {
			pushExpresion(&pila, int(caracter-'0'))
		} else {
			operandoB = popExpresion(&pila)
			operandoA = popExpresion(&pila)
			fmt.Printf("desencole %d y %d\n", operandoA, operandoB)

			switch caracter {
			case '*':
				pushExpresion(&pila, operandoA*operandoB)
			case '+':
				pushExpresion(&pila, operandoA+operandoB)
			case '-':
				pushExpresion(&pila, operandoA-operandoB)
			case '/':
				pushExpresion(&pila, operandoA/operandoB)
			}
		}
	}

	resultado = popExpresion(&pila)
	fmt.Printf("Resultado de la expresion %s: %d\n", expresion, resultado)
}
