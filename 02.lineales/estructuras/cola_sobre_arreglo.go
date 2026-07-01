package main

import (
	"fmt"
)

const TAMANO = 1000000

type Queue struct {
	arreglo   [TAMANO]int
	principio int
	tamano    int
}

func inicializarQueue(q *Queue) {
	q.principio = 0
	q.tamano = 0
}

func enqueue(cola *Queue, valor int) error {
	if cola.tamano < TAMANO {
		cola.arreglo[(cola.principio+cola.tamano)%TAMANO] = valor
		cola.tamano++
		fmt.Printf("Debug: Encolando %d con ppio %d, tamano %d\n", valor, cola.principio, cola.tamano)
		return nil
	}
	fmt.Println("Queue llena --- error!!!")
	return fmt.Errorf("queue llena")
}

func dequeue(cola *Queue) (int, error) {
	if cola.tamano > 0 {
		rta := cola.arreglo[cola.principio]
		fmt.Printf("Debug - desencolando elemento %d: %d", cola.principio, rta)
		cola.tamano--
		cola.principio = (cola.principio + 1) % TAMANO
		fmt.Printf("--- ppio = %d\n", cola.principio)
		return rta, nil
	}
	fmt.Println("Queue vacía --- error!!!")
	return -1, fmt.Errorf("queue vacía")
}

func main() {
	var colaEjemplo Queue
	inicializarQueue(&colaEjemplo)

	for i := 0; i < 50; i++ {
		enqueue(&colaEjemplo, i*3)
	}

	a, _ := dequeue(&colaEjemplo)
	b, _ := dequeue(&colaEjemplo)

	fmt.Printf("Primer elemento de la cola: %d\nSegundo: %d", a, b)

	// 50 encolados, 2 desencolados; lleno la queue para que comience en la segunda posición
	// y estén los dos elementos finales al principio del arreglo
	var ultimoValor int
	for i := colaEjemplo.tamano; i < TAMANO; i++ {
		enqueue(&colaEjemplo, i)
		ultimoValor = i
	}
	fmt.Printf("Ultimo es %d", ultimoValor)

	// Debug de la queue
	fmt.Println("\n-----------------cola_ejemplo.principio-----------------")
	fmt.Printf("Imprimo el arreglo comenzando en %d, con tamaño %d\n", colaEjemplo.principio, colaEjemplo.tamano)
	for i := colaEjemplo.principio; i < colaEjemplo.tamano+colaEjemplo.principio; i++ {
		fmt.Printf("arr[%d]=%d\n", i%TAMANO, colaEjemplo.arreglo[i%TAMANO])
	}

	// Desencolo
	_, err := dequeue(&colaEjemplo)
	for err == nil {
		_, err = dequeue(&colaEjemplo)
	}
}
