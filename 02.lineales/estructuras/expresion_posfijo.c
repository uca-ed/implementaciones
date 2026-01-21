#include <stdio.h>
#include "pila.h"
#include "cola.h"
#include <string.h>

struct stack pila;
struct queue cola;
// TO DO: tengo que usar un stack, no una queue


int main() {
  inicializar_stack(&pila);
  inicializar_queue(&cola);
  char* expresion;
  int operando_b;
  int operando_a; 
  int resultado;
  char caracter;

  expresion = "12+64-*33*21-/+96-31+*36*36++*+";

  
  for(int i=0; i<strlen(expresion); i++) {
    enqueue(&cola, expresion[i]);
  }
  
  while (!queue_vacia(&cola)) {
    caracter = dequeue(&cola);
    if ( caracter >= '0' && caracter <= '9')
      push(&pila, caracter - '0');
    else {
      operando_b = pop(&pila);
      operando_a = pop(&pila);
      printf("desencole %d y %d\n", operando_a, operando_b);
      if (caracter == '*') push(&pila, operando_a * operando_b);
      if (caracter == '+') push(&pila, operando_a + operando_b);
      if (caracter == '-') push(&pila, operando_a - operando_b);
      if (caracter == '/') push(&pila, operando_a / operando_b);
    }
  }
  resultado = pop(&pila);
  printf("Resultado de la expresion %s: %d\n", expresion, resultado);
}

