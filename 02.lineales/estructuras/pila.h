/* Librería que representa pilas sobre un arreglo 
*/
#define TAMANO 1000000
struct stack {
    int arreglo[TAMANO];
    int tos; // top of stack
};

void inicializar_stack(struct stack* q) {
    q->tos=-1;
}

bool push(struct stack* pila, int valor) {
    if ( pila->tos < TAMANO -1 ) { 
        pila->tos++;
        pila->arreglo[pila->tos] = valor;
        
        return(0);
    }
    printf("stack llena --- error!!!\n");
    return(1);
}

int pop(struct stack* pila) {
    if ( pila->tos >= 0 ) {
        int rta = pila->arreglo[pila->tos];
        pila->tos--;
        return(rta);
    }
    printf("stack vacía --- error!!!\n");
    return(-1);
}

bool pila_vacia(struct stack* pila) {
    return(pila->tos < 0);
}