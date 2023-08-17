package main

import "fmt"

func main()  {
	var numero int = 10
	var custo float64 = 190.6
	const permissao bool = true // const does not support the short declaration
	var usuario string

	fmt.Printf(
		"Printando coisas %v %f %v %q\n",
	numero, custo, permissao, usuario)

	nome := "jose carlos" // inferindo tipos - short assignment operators

	fmt.Printf("jose %s", nome)

	// formatting for getting the types
	fmt.Printf("\nPrintando tipo de nome: %T\n", nome)

	variavel_1, variavel_2 := 10, 23.6
	fmt.Println(variavel_1, variavel_2)

	//  when you dont need to explicitly inform the type
	// int
	// uint
	// float64
	// complex128

	temp := 89.8888
	tempInt := int(temp)
	
	fmt.Println(tempInt)

	// Default:
	/*
	bool
	string
	int
	uint32
	byte
	rune
	float64
	complex128
	*/

	if length := getLength(nome); length < 2 {
		fmt.Prinln("Nome tem menos de 2 caracteres")
	} else {
		fmt.Printf("Nome tem %d caracteres.\n", length)
	}
}

func getLength(string word) uint32 {
	for x:=
}