.data
.align 		0 # alinha a memoria em 2^0 bytes = 1 byte (caracteres)

my_str:	    	.asciz		"my new memory text\n"
numero_lido: 	.asciz		"\no numero digitado eh: "
newlinec:	.asciz		"\n"
str_aleatorio:	.asciz		"o numero aleatorio gerado eh: "

.align		2 # alinha a memoria em 2^2 bytes=  4 bytes (inteiro)
my_int: .word	100


.text
.globl	main

main:
	#li	a7, 41
	#ecall
	#li	a7, 1
	#ecall

	# printando string inicial
	addi	a7, x0, 4
	la	a0, my_str
	ecall
	
	# printando inteiro na tela
	addi	a7, x0, 1
	lw	a0, my_int
	ecall
	
	jal 	newline
	
	# lendo inteiro do usuario
	addi 	a7, x0, 5
	ecall
	mv	t1, a0
	
	jal 	newline
		
	# printando numero digitado
	addi 	a7, x0, 4
	la	a0, numero_lido
	ecall
	
	addi	a7, x0, 1
	mv	a0, t1
	ecall
	
	# condicao de parada
	addi 	t2, x0, 0
	
	loop:
		jal 	newline
		add	a0, x0, t1
		addi	a7, x0, 1	
		ecall
		
		addi 	t1, t1, -1
		bgt	t1, t2, loop
#fimloop:
	jal 	newline
	
	# gerando numero aleatorio
	addi	a7, x0, 4
	la	a0, str_aleatorio
	ecall
	
	addi	a1, x0, 100
	#li	a0, 0
	jal	generate_random
	mv	t1, a0
	# do whatever you want now with t1
	
	
	# printando numero aleatorio
	addi	a7, x0, 1
	#mv 	a0, t1
	ecall
	
	addi 	a7, x0, 10
	ecall


# prints a newline character
newline:
	addi	a7, x0, 4
	la	a0, newlinec
	ecall
	ret

# prints the integer stored on a1
print_int:
	mv	a1, a0
	addi	a7, x0, 1
	ecall
	
	addi	a7, x0, 4
	la	a0, newlinec
	ecall
	ret


# generates a random number from 1 to max (reg a1) using aaaaaaa algoritmo n sei o nome and store the result on register a0
generate_random:
	
		
	addi	a7, x0, 41 # gera um int aleatorio e coloca em a0
	
	
	#params: 
	mv	t0, a0 # t0 = initial random value
	mv	t1, a1 # t1 =  max (upper bound)
	
	
	addi	t4, x0, 10 # t4 = quantidade de iteracoes do algoritmo (10)
	addi	t5, x0, 0 # t5 = condicao de parada (0)
	
	# procedimento: xn = (xn_-1 * a + c) mod d (10 vezes)
	randomgen_loop:
		
		# gerando a, c (t2,t3)
		addi	a7, x0, 41
		mv	t2, a0
		
		addi	a7, x0, 41
		mv 	t3, a0
		
		##----
		addi	a7, x0, 1
		mv	a0, t2
		ecall
		
		addi	a7, x0, 4
		la	a0, newlinec
		ecall
		
		addi	a7, x0, 1
		mv	a0, t3
		ecall
		
		addi	a7, x0, 4
		la	a0, newlinec
		ecall
		
		##----
		mul	t0, t0, t2 # x = x * a
		add 	t0, t0, t3 # x = x + c
		rem	t0, t0, t1 # x = (x ) mod max (t1)
		
		addi	a7, x0, 1
		add	a0, x0, t1
		ecall
		
		
		addi	t4, t4, -1
		bgt	t4, t5, randomgen_loop
		
	mv	a0, t1
	addi 	a0, a0, 1
	ret
	