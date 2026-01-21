#include<stdio.h>

#define CANTIDAD 10

int main() {
  int numeros[CANTIDAD] = {15, 14, 13, 12, 10, 9, 8, 7, 6, 5};
  int tmp;
  for (int i=0; i<CANTIDAD; i++) {
    for (int j=0; j<CANTIDAD-i-1; j++) {
        if (numeros[j] > numeros[j+1]) {
            printf("Swap!\n");
            tmp = numeros[j];
            numeros[j] = numeros[j+1];
            numeros[j+1] = tmp;
        }
    }
  }

  for (int i=0; i<CANTIDAD; i++) {
    printf("%d%s", numeros[i], (i==CANTIDAD-1?"":"\t" ));
  }
  printf("\n");
  return(0);
}
