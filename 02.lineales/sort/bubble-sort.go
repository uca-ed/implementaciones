package main

import (
  "fmt"
)

func main() {
  var numeros= []int{15, 14, 13, 12, 10, 9, 8, 7, 6, 5}
  for i:=0; i<len(numeros)-1; i++ {
    for j:=0; j< len(numeros)-i-1; j++ {
      if numeros[j] > numeros[j+1] {
	 fmt.Println("swap")
	 tmp := numeros[j]
	 numeros[j] = numeros[j+1]
	 numeros[j+1] = tmp
      }
    }
  }

  for _, m:=range numeros {
    fmt.Printf("%d\t", m)
  }


}
