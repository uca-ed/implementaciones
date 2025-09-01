#include <stdio.h>
#include <stdbool.h>

// Define el tamaño máximo del conjunto basado en el tamaño de unsigned int
#define TAMANO (sizeof(unsigned int) * 8)

// Mostrar los elementos del conjunto
void imprimir(unsigned int set, char universal[]) {
    printf("{ ");
    for (int i = 0; i < TAMANO; i++) {
        if (set & (1 << i)) {
            printf("%c ", universal[i]);
        }
    }
    printf("}\n");
}

// Agregar un elemento al conjunto
unsigned int agregar(unsigned int set, int elemento) {
    if (elemento >= 0 && elemento < TAMANO) {
        set |= (1 << elemento);
    }
    return set;
}

// Eliminar un elemento del conjunto
unsigned int quitar(unsigned int set, int elemento) {
    if (elemento >= 0 && elemento < TAMANO) {
        set &= ~(1 << elemento);
    }
    return set;
}

// Verificar si un elemento está en el conjunto
bool pertenece(unsigned int set, int elemento) {
    if (elemento >= 0 && elemento < TAMANO) {
        return (set & (1 << elemento)) != 0;
    }
    return false;
}

// Unión de dos conjuntos
unsigned int union_set(unsigned int set1, unsigned int set2) {
    return set1 | set2;
}

// Intersección de dos conjuntos
unsigned int interseccion(unsigned int set1, unsigned int set2) {
    return set1 & set2;
}

// Diferencia de conjuntos (set1 - set2)
unsigned int diferencia(unsigned int set1, unsigned int set2) {
    return set1 & ~set2;
}

// Complemento de un conjunto
unsigned int complemento(unsigned int set) {
    return ~set;
}

// Cardinalidad de un conjunto
int cardinalidad(unsigned int set) {
   int resp = 0;
   unsigned int aux;
   while(set) {
     aux = set - 1;
     set = set & aux;
     resp++;
   }
   return(resp);
}

int main() {
    unsigned int setA = 0; // Conjunto vacío
    unsigned int setB = 0; // Conjunto vacío
    char universal[TAMANO];
    unsigned int i;

    for (i=0; i<TAMANO; i++) {
        universal[i] = 'A'+i;
    }

    printf("Tamaño máximo del conjunto: %d\nUniversal: {", TAMANO);
    // Muestro el universal
    for (i=0; i<TAMANO; i++) {
        printf("%s%c", (i==0)?"":", ", universal[i]);
    }
    printf("}\n");

    // Agregar elementos a setA
    setA = agregar(setA, 1);
    setA = agregar(setA, 3);
    setA = agregar(setA, 5);
    
    // Agregar elementos a setB
    setB = agregar(setB, 3);
    setB = agregar(setB, 4);
    setB = agregar(setB, 5);
    
    printf("Conjunto A: ");
    imprimir(setA, universal);
    
    printf("Conjunto B: ");
    imprimir(setB, universal);
    
    printf("Unión de A y B: ");
    imprimir(union_set(setA, setB), universal);
    
    printf("Intersección de A y B: ");
    imprimir(interseccion(setA, setB), universal);
    
    printf("Diferencia A - B: ");
    imprimir(diferencia(setA, setB), universal);
    
    printf("Complemento de A: ");
    imprimir(complemento(setA), universal);
    
    printf("¿El elemento 3 (D) está en A? %s\n", pertenece(setA, 3) ? "Sí" : "No");
    printf("¿El elemento 2 (C) está en A? %s\n", pertenece(setA, 2) ? "Sí" : "No");
    
    // Eliminar un elemento
    setA = quitar(setA, 3);
    printf("Conjunto A después de eliminar 3: ");
    imprimir(setA, universal);
  
    printf("Cardinalidad de A: %d\n", cardinalidad(setA));

    return 0;
}

