#include <stdio.h>

#define TAMANO 1000000

struct queue {
    int arreglo[TAMANO];
    int principio;
    int tamano;
};


void inicializar_queue(struct queue* q) {
    q->principio=0;
    q->tamano=0;
}

bool enqueue(struct queue* cola, int valor) {
    if ( cola->tamano < TAMANO ) { 
        cola->arreglo[(cola->principio + cola->tamano) % TAMANO] = valor;
        cola->tamano++;
        printf("Debug: Encolando %d con ppio %d, tamano %d\n", valor, cola->principio, cola->tamano);
        return(0);
    }
    printf("Queue llena --- error!!!\n");
    return(1);
}

int dequeue(struct queue* cola) {
    if ( cola->tamano > 0 ) {
        int rta = cola->arreglo[cola->principio];
        printf("Debug - desencolando elemento %d: %d", cola->principio, rta);
        cola->tamano--;
        cola->principio = (cola->principio + 1) % TAMANO; 
        printf("--- ppio = %d\n", cola->principio);
        return(rta);
    }
    printf("Queue vacía --- error!!!\n");
    return(-1);
}

int main() {

    struct queue cola_ejemplo;
    int i, a, b;
    inicializar_queue(&cola_ejemplo);
    for( int i=0; i<50; i++)
      enqueue(&cola_ejemplo, i*3);

    a = dequeue(&cola_ejemplo);
    b = dequeue(&cola_ejemplo);
    
    printf("Primer elemento de la cola: %d\nSegundo: %d", a, b);


    // 50 encolados, 2 desencolados; lleno la queue para que comience en la segunda posición
    // y estén los dos elementos finales al principio del arreglo

    for (i=cola_ejemplo.tamano; i < TAMANO; i++) {
        enqueue(&cola_ejemplo, i);
    }
    printf("Ultimo es %d", i);

    // Debug de la queue
    printf("\n-----------------cola_ejemplo.principio-----------------\n");
    printf("Imprimo el arreglo comenzando en %d, con tamaño %d\n", cola_ejemplo.principio, cola_ejemplo.tamano);
    for (int i=cola_ejemplo.principio; i<cola_ejemplo.tamano+cola_ejemplo.principio; i++) {
        printf("arr[%d]=%d\n", i%TAMANO, cola_ejemplo.arreglo[i%TAMANO]);
    }

    // Desencolo
    int rta;
    rta = dequeue(&cola_ejemplo);
    while (rta >= 0 ) {
        // printf("dequeue: %d\n", rta);
        rta = dequeue(&cola_ejemplo);
    }

}
