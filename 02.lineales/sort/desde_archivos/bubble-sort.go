package main

import (
  "fmt"
  "os"
  "log"
  "bufio"
  "strconv"
)

func main() {
  var numeros= []int{}
  var numero int

  nombre_archivo:="datos.txt"
  if len(os.Args) > 1 {
    nombre_archivo = os.Args[1]
  }

	archivo, err := os.Open(nombre_archivo)
	if err != nil {
		log.Fatal("No se pudo abrir el archivo:", err)
	}
  
  scanner := bufio.NewScanner(archivo)

  for scanner.Scan() {
    numero, _ = strconv.Atoi(scanner.Text())
    numeros = append(numeros, numero)  
  }

  archivo.Close()
  for i:=0; i<len(numeros)-1; i++ {
    for j:=0; j< len(numeros)-i-1; j++ {
      if numeros[j] > numeros[j+1] {
	 
	 tmp := numeros[j]
	 numeros[j] = numeros[j+1]
	 numeros[j+1] = tmp
      }
    }
  }

  for _, m:=range numeros {
    fmt.Printf("%d\n", m)
  }

}
