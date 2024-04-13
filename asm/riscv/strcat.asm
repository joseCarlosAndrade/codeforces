.data
.align 		0

str_dest: 	.asciz		"Hello "
#.align		2
#.align		0
str_src:	.asciz		"World from rars!"

.text	
.align		2
.globl 		main

main:
	# plano:
	# receber duas null terminated strings como parametros
	# contar os caracteres das duas
	# alocar um novo espaço de tamanho len(str1) + len(str2)
	# escrever neste novo espaço concatenando as duas
	# mudar o endereço que str_dest aponta para o novo espaço
	
	# s1 = tamanho da str_dest
	la	t1, str_dest
	jal	strlen
	mv	a1, a0
	
	# s2 = tamanho da str_src
	la	t1, str_src
	jal 	strlen
	mv 	a2, a0
	
	la	t1, str_dest
	la	t2, str_src
	jal 	strcat
	
	addi	a7, x0, 4
	ecall

	
	#addi	a7, x0, 1
	#ecall
	
	addi	a7, x0, 10
	ecall
	
	

# funcao que recebe em 
# t1 = endereco de str_dest; 
# t2 = endereco de str_src;
# a1 = tamanho da str_dest;
# a2 = tamanho da str_src
# retorno: a0 = novo endereco da str_dest (string concatenada) 
# regs usados: a0, a1, a2, a3, t1, t2, t3, t4, s1
strcat:
	# salvando conteudo de registradores que serao usados na stack para evitar interferencia no codigo principal 
	addi	sp, sp, -32
	sw	a1, 0(sp)
	sw	a2, 4(sp)
	sw	a3, 8(sp)
	sw	t1, 12(sp)
	sw	t2, 16(sp)
	sw	t3, 20(sp)
	sw	t4, 24(sp)
	sw	s1, 28(sp)
	
	
	# alocar um novo espaco na heap de tamanho = str_dest + str_src (a3 = a1 + a2)
	add	a3, x0, a1 # a3 = a1
	add	a3, a3, a2 # a3 = a3 + a2
	addi	a3, a3, 1 # aloca um byte a mais para caracter nulo
	mv	a0, a3 # a0 tem tamanho de str_src + str_dest
	addi	a7, x0, 9
	ecall
	
	# nao mexer em a0!!!! ja eh o novo retorno
	
	
	
	# t3 -> index das strings atuais
	# t4 -> index das novas strings
	
	#addi	t3, x0, -1 # comeca em -1 para evitar dois labels de jump
	#addi	t4, x0, -1
	mv	t3, a0 # t3 = str final
	mv	t4, t1 # t4 = str_dest
	
	strcat_loop_dest: # copia os dados de str_dest para a nova str (endereco em 0)
		
		
		lb	s1, 0(t4) # pega caractere atual de str_dest
		beqz	s1, strcat_loop_dest_end # sai quando str_dest chega no final
		sb	s1, 0(t3) # salva em str_final
		
		addi	t3, t3, 1 # avancando iteracao
		addi	t4, t4, 1
		
		j	strcat_loop_dest
		
	strcat_loop_dest_end:
		
		
	#addi	t3, x0, -1 # resetando index de t3
	mv	t4, t2 # t4 = endereco da str_src
	strcat_loop_src: # copia os dados da str_src para a nova str
		
		
		lb	s1, 0(t4) # pega caractere atual de str_dest
		beqz	s1, strcat_loop_src_end # sai quando str_dest chega no final
		sb	s1, 0(t3) # salva em str_final
		
		addi	t3, t3, 1 # avancando iteracao
		addi	t4, t4, 1
		
		j	strcat_loop_src
		
	strcat_loop_src_end:
	
	# TODO: TROCAR ENDERECO QUE O PONTEIRO DE STR_DEST APONTA PARA A STRING FINAL
	
	sb	x0, 0(t3) # garantindo que o final de str_final seja 0

	# recuperando valores usados
	
	lw	a1, 0(sp)
	lw	a2, 4(sp)
	lw	a3, 8(sp)
	lw	t1, 12(sp)
	lw	t2, 16(sp)
	lw	t3, 20(sp)
	lw	t4, 24(sp)
	lw	s1, 28(sp)
	
	addi	sp, sp, -32
	
	
	ret
	

# funcao que retorna o numero de caracteres de uma string (sem contar o '\0')
# recebe: t1 = endereco da str
# retorna: a0 = numero de caracteres da str
# regs usados: a0, t1, t2, a5
strlen:
	addi	sp, sp, -12
	sw	t1, 0(sp)
	sw	t2, 4(sp)
	sw	a5, 8(sp)
	
	addi	a0, x0, 0 # incia a resposta com 0
	# t2 = offset do caractere da string (index)

	addi	t2, x0, 0
	
	j 	strlen_loop_first
	
	strlen_loop: # existem maneiras de evitar este jump, mas fique de exercicio pro leitor (lkkkkkkk)
		addi 	a0, a0, 1 # a0 = a0 + 1
	
	strlen_loop_first:
		
		add	t2, t1, a0 # t2 = t1 + t2 => str[0] + 1*i(a0)
		
		# a5 = caractere atual
		lb	a5, 0(t2)
		
		bgtz	a5, strlen_loop # enquanto nao for zero (null) volta para a contagem
		
	
	
	lw	t1, 0(sp)
	lw	t2, 4(sp)
	lw	a5, 8(sp)
	addi	sp, sp, 12
	
	ret
		
	
		
	
	
