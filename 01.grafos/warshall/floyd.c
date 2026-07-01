#include <stdio.h>

#define INFINITO -1
#define TAMANO 4

void imprimir_matriz(int matriz[4][4]) {
    for (int i=0; i<TAMANO; i++) {
        for (int j=0; j<TAMANO; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int suma(int a, int b) {
    if (a==INFINITO || b==INFINITO)
        return(INFINITO);
    else
        return(a+b);
}

int minimo(int a, int b) {
    if (a==INFINITO)
        return(b);
    if (b==INFINITO)
        return(a);
    return(a<b?a:b);
}

int floyd(int matriz[TAMANO][TAMANO], int resultado[TAMANO][TAMANO]) {
      for (int i=0; i<TAMANO; i++)
        for (int j=0; j<TAMANO; j++) {
            resultado[i][j] = matriz[i][j];
        }

    for (int k=0; k<TAMANO; k++) 
      for (int i=0; i<TAMANO; i++)
        for (int j=0; j<TAMANO; j++) {
            resultado[i][j] = minimo(resultado[i][j], suma(resultado[i][k], resultado[k][j]));
        }
    
    return(0);
}

int main() {
    int distancias[TAMANO][TAMANO] = {
    {0, 7, 3, 12}, 
    {4, 0, 6, INFINITO},
    {1, INFINITO, 0, 6},
    {2, 1, 1, 0}
    };
    int rta[TAMANO][TAMANO];

    imprimir_matriz(distancias);
    printf("\n\n");
    floyd(distancias, rta);
    imprimir_matriz(rta);
}
