/* Librería que representa cola sobre un arreglo 
*/
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
        return(0);
    }
    printf("Queue llena --- error!!!\n");
    return(1);
}

int dequeue(struct queue* cola) {
    if ( cola->tamano > 0 ) {
        int rta = cola->arreglo[cola->principio];
        cola->tamano--;
        cola->principio = (cola->principio + 1) % TAMANO; 
        return(rta);
    }
    printf("Queue vacía --- error!!!\n");
    return(-1);
}

bool queue_vacia(struct queue* cola) {
    return(cola->tamano == 0 );
}