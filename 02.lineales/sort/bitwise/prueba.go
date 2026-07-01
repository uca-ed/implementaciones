package main

import (
  "fmt"
  
  "bitwise/popcount"
) 

func main() {
  var p uint64 = 26
  fmt.Println(popcount.PopCount(p))
}

