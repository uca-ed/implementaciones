#include<stdio.h>
#include<stdlib.h>
/*
Bubble sort leyendo un archivo que se pasa por parámetro

Modo de uso:
bubble-sort <nombre_archivo>

Si no se provee un nombre de archivo, se usa datos.txt por defecto.

Para no modificar el tamaño de memoria reservado en cada iteración, se trabaja con bloques de TAMANO_INICIAL de memoria reservada.
*/
#define TAMANO_INICIAL 100000
#define NOMBRE_ARCHIVO "datos.txt"

int main(int argc, char *argv[]) {
  int tmp;
  FILE *archivo;
  int *numeros;
  int numero, cantidad, tamano;
  char *nombre_archivo;
  
  tamano = TAMANO_INICIAL;
  cantidad = 0;

  if (argc > 1)
    nombre_archivo = argv[1];
  else
    nombre_archivo = NOMBRE_ARCHIVO;


  if ((archivo = fopen(nombre_archivo, "r")) == NULL) {
    printf("No se pudo abrir el archivo\n");
    return(1);
  }

  numeros = (int*)malloc(TAMANO_INICIAL * sizeof(int));

  while (!feof(archivo)) {
    fscanf(archivo, "%d\n", &numero);
    if (cantidad == tamano) {
      tamano += TAMANO_INICIAL;
      numeros = realloc(numeros, tamano * sizeof(int));
    }
    numeros[cantidad] = numero;
    cantidad ++;
  }


  for (int i=0; i<cantidad; i++) {
    for (int j=0; j<cantidad-i-1; j++) {
        if (numeros[j] > numeros[j+1]) {
            //printf("Swap!\n");
            tmp = numeros[j];
            numeros[j] = numeros[j+1];
            numeros[j+1] = tmp;
        }
    }
  }

  for (int i=0; i<cantidad; i++) {
    printf("%d%s", numeros[i], (i==cantidad-1?"":"\n" ));
  }
  free(numeros);
  numeros=NULL;
  fclose(archivo);
  return(0);
}

