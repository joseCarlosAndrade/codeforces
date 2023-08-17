package main

import (
	"fmt"
)

func Sqrt(x float64) float64 {
	z:=1.0
	last_z :=z
	//last_z := z
	
	for  ;; {
		z -= (z*z - x) / (2*z)
		if error:=(z-last_z)*(z-last_z); error < 0.000000001 {
			break
		}
		last_z = z
	}
	return z
}

func main() {
	fmt.Println(Sqrt(121))
}
