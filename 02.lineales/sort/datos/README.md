# Generación de archivos de entrada

En este directorio hay algoritmos para generar datos para los algoritmos de ordenamiento.

Están implementados en AWK y Go, de manera similar.

Para ejecutar el generador de AWK:

`awk -f lista_azar.awk -v cantidad=10000 > datos.csv` generaría 10.000 elementos al azar en el archivo datos.csv.ç
 
Para utilizar el generador de Go: 
```
go build lista_azar.go
./lista_azar 10000 > datos.csv
```

o directamente 

`go run lista_azar.go > datos.csv`

