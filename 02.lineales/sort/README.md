# Sort - Algoritmmos de ordenamiento

Este directorio tiene implementaciones de algoritmos de ordenamiento sobre arreglos:

* Bubble Sort (ordenamiento por burbuja) [bubble-sort.c](./bubble-sort.c) y [bubble-sort.go](./bubble-sort.go)
* Select Sort (ordenamiento por selección) [select-sort.c](./select-sort.c) y [select-sort.go](./select-sort.go)
* Insert Sort (ordenamiento por inserción) [insert-sort.c](./insert-sort.c) y [insert-sort.go](./insert-sort.go)


Las implementaciones están hechas en C y en Go. En ambos casos con iguales arreglos estáticos.
Para utilizar archivos de entrada y manejar mayores tamaños, están implementados generadores de archivos para input en el subdirectorio [datos](./datos/) y respectivas implementaciones para tratar archivos en [desde_archivos](desde_archivos/).

Referencia sobre los algoritmos en el capítulo 8 de "Aho, Hopcroft, Ullman, **Estructuras de datos y Algoritmos**"


Cómo ejecutar los ejemplos? 

En c, 

```
gcc bubble-sort.c -o bubble-sort
./bubble-sort
```

En Go,
```
go build bubble-sort.go -o bubble-sort
./bubble-sort
```

