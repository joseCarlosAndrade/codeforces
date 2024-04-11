.data
.align 		0 # alinha a memoria em 2^0 bytes = 1 byte (caracteres)

newlinec:	.asciz		"\n"
str_aleatorio:	.asciz		"Bem vindo ao jogo da adivinhação! \n"
str_maior:	.asciz		"O numero que voce digitou é MAIOR que o correto..\n"
str_ḿenor:	.asciz		"O numero que voce digitou é MENOR que o correto..\n"
str_correto:	.asciz		"O numero que voce digitou ESTA correto!! \n"
str_hist:	.asciz 		"Suas tentativas foram \n"
str_ntentativas:.asciz		"Total de tentativas: \n"


.align		2 # alinha a memoria em 2^2 bytes=  4 bytes (inteiro)
head:		.space		4 # reserva 4 bytes a partir do endereço head
#my_int: .word	100

#.align 2

.text
.globl	main

main:	
	# s0 = ponteiro que aponta para o no atual
	#addi	s0, x0, 0 # comeca com nulo
	
	addi	s4, x0, 0 # s4 = numero de tentativas


	jal 	newline
	
	# Boas vindas
	addi	a7, x0, 4
	la	a0, str_aleatorio
	ecall
	
	addi	a1, x0, 100
	#li	a0, 0
	jal	generate_random
	mv	t1, a0
	# do whatever you want now with t1
	
	mv	a1, t1
	jal 	alocar_primeiro_no
	
	
	# printando numero aleatorio (ja esta em a0) TODO: REMOVER
	#addi	a7, x0, 1
	#mv 	a0, t1
	#ecall
	
	
	
	guess_loop:
		addi	s4, s4, 1 # incrementando o numero de tentativas
	
		# aceitando input do usuario
		addi	a7, x0, 5
		ecall # retorna o numreo lido em a0
		
		#add	s1, x0, a0 # carregando chute em s1
		mv	s1, a0
		jal 	alocar_no # alocando novo no
		
		mv   	a2, s1 # carregando parametros
		mv	a1, t1
		jal	processar_input # retorna em a0 resultado do processo
		mv 	t4, a0 # guardando em t4
		
		bgtz	t4, print_maior
		bltz	t4, print_menor
		
	
	# voce conseguiu
	addi	a7, x0, 4
	la 	a0, str_correto
	ecall
	
	
	
	addi	a7, x0, 1
	add 	a0, x0, t1
	ecall
	
	jal 	newline
	
	# historico + numeor de tentativas 
	addi	a7, x0, 4
	la	a0, str_hist
	ecall
	
	# passando primeiro no para s1
	la	s1, head
	lw	s1, 0(s1)	
	
	jal	print_tentativas
	
	addi 	a7, x0, 4
	la	a0, str_ntentativas # o numero de tentativas eh
	ecall 
	
	#jal 	newline
	
	addi	a7, x0, 1
	mv	a0, s4
	ecall
	
	# exit
	addi 	a7, x0, 10
	ecall
	
	
	#str_hist
	#str_ntentativas
	

# end main --- ####################################


# prints a newline character
newline:
	addi	a7, x0, 4
	la	a0, newlinec
	ecall
	ret


# generates a random number from 1 to max (reg a1) using aaaaaaa algoritmo n sei o nome and store the result on register a0
generate_random:
	
		
	addi	a7, x0, 42 # gera um int aleatorio e coloca em a0
	
	
	#params: 
	mv	t0, a0 # t0 = initial random value
	mv	t1, a1 # t1 =  max (upper bound)
	
	
	addi	t4, x0, 10 # t4 = quantidade de iteracoes do algoritmo (10)
	addi	t5, x0, 0 # t5 = condicao de parada (0)
	
	# procedimento: xn = (xn_-1 * a + c) mod d (10 vezes)
	randomgen_loop:
		
		# gerando a, c (t2,t3)
		addi	a7, x0, 42
		ecall
		mv	t2, a0
		
		ecall
		mv 	t3, a0
		
		mul	t0, t0, t2 # x = x * a
		add 	t0, t0, t3 # x = x + c
		mul	t0, t0, t0 # eleva o numero ao quadrado para garantir que sempre sera positivo
		rem	t0, t0, t1 # x = (x ) mod max (t1)
		
		
		addi	t4, t4, -1
		bgt	t4, t5, randomgen_loop
		
	mv	a0, t0
	addi 	a0, a0, 1 # garantir que o numero esta na range [1,100]
	ret
	

# parametros: 
	# a1 = numero a ser adivinhado
	# a2 = numero desta tentativa
# retorna:
	# a0 = resultado do processamento (0 -> correto, 1 -> muito alto, -1 -> muito baixo)
processar_input:
	bgt	a2, a1, maior # tentativa muito alta
	blt	a2, a1, menor # tentativa muito baixa
	
	# se chegar ate aqui, eh porque esta correto
	addi 	a0, x0, 0
	ret
 	maior:
 		addi	a0, x0, 1
 		ret 
 	menor:
 		addi	a0, x0, -1
 		ret
 
 # rotinas auxiliares para printar resultados das operacoes (ambas retornam ao loop de input do usuario)
 print_maior:
 	addi	a7, x0, 4
 	la	a0, str_maior
 	ecall
 	j guess_loop
 
 print_menor:
	addi	a7, x0, 4
 	la	a0, str_ḿenor
 	ecall
 	j guess_loop
 	
# aloca o primeiro no (procedimento diferente). faz s0 apontar pro primeiro no
# parametros: a1 = valor do no a ser alocado
 alocar_primeiro_no:
 	
 	# ecall  9 alocar memoria -> a0 numero de bytes a ser alocado -> a0 endereco da memoria alocada
 	addi	a7, x0, 9
 	addi	a0, x0, 8
 	ecall
 	
 	# fazendo conteudo do header ser endereco do primeiro no
 	la	s2, head
 	sw	a0, 0(s2)
 	

 	mv	s0, a0 # fazendo s0 apontar pro primeiro no
 	
 	sw	a1, 0(s0) # colocando numero no primeiro no 
 	sw	x0, 4(s0) # colocando endereco nulo no ponteiro do primeiro no 
 	ret
 	
# aloca proximos nos
# parametros: s1 -> valor a ser alocado
# retorno -> void
alocar_no:
	# s0 -> no atual
	# s1 -> valor a ser alocado
	
	addi 	a7, x0, 9 # syscall 9 :alocaŕ
	addi	a0, x0, 8 # quantidaade de bytes a ser alocado (8)
	ecall # endereco do novo bloco 
	
	sw	a0, 4(s0) # fazendo ultimo no apontar para o novo no (a0)

 	mv	s0, a0 # faznedo s0 apontar para o novo no
 	sw	s1, 0(s0) # salvando o chute no no novo no
 	sw	x0, 4(s0) # apontando o novo no para 0
 
 
	ret

# printa a sequencia de tentativas + o numero de tentativas
# s1 tem o ENDEREÇO do conteudo do primeiro no
print_tentativas:
	lw	s1, 4(s1) # atualiza o no ( so chega aqui se o proximo no nao for nulo


	
	lw	a0, 0(s1) # printa tentativa
	addi 	a7, x0, 1
	ecall
	
	# salvando endereço de retorno	
	addi	sp, sp, -4 # uma palavra
	sw	ra, 0(sp)
	jal	newline
	lw	ra, 0(sp)
	addi	sp, sp, 4
	
	lw	s3, 4(s1) # coloca ponteiro do proximo no em s3
	bgt	s3, x0, print_tentativas # se o ponteiro for maior que zero, recomeçar o loop
	
	ret 	# volta , fim da impressao
	
	
