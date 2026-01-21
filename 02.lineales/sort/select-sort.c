#include<stdio.h>

#define CANTIDAD 10

int main() {
  int numeros[CANTIDAD] = {15, 14, 13, 12, 10, 9, 8, 7, 6, 5};
  int tmp, indice_menor, clave_menor;
  for (int i=0; i<CANTIDAD; i++) {
    indice_menor = i;
		clave_menor = numeros[i];
    for (int j=i+1; j<CANTIDAD; j++) {
        if (numeros[j] < clave_menor) {
            clave_menor = numeros[j];
            indice_menor = j;
        }
        tmp = numeros[i];
        numeros[i] = numeros[indice_menor];
        numeros[indice_menor] = tmp;

    }
  }

  for (int i=0; i<CANTIDAD; i++) {
    printf("%d%s", numeros[i], (i==CANTIDAD-1?"":"\t" ));
  }
  printf("\n");
  return(0);
}
