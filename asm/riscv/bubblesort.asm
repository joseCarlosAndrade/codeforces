.data

.align 		2 # alinha a memoria para salvar 2^2 bytes

#.space		vetor	28 # reserva 7*4 = 28 bytes
vetor:		.word 	7, 5, 2, 1, 1, 3, 4, 6, 2, 4 # vetor
qnt:		.word   10 #  quantidade de elementos
.text
.globl 		main
.align 		2
main:
	# 7, 5, 2, 1, 1, 3, 4
	# t0 = i
	# t1 = j
	# t2 = MAX
	# t3 = aux
	# s0 = endereco do vetor
	
	lw	t2, qnt
	#addi	t2, x0, 10 # fazendo MAX = 7 
	la	s0, vetor # carrega endereco do vetor em s0
	
	
	addi	t0, x0, 0 # i = 0;
	
	# loop
	f_loop: #  i de 0 a MAX -1, passo 1
		addi 	t1, t2, -1
		#addi 	t1, x0, 6 # j = 0;
		s_loop: # j de i+1, passo -1
			
			# algoritmo
			mv	s2, t1 # s2 = j
			addi 	s1, s2, -1 # s1 = j-1
			
			addi	a2, x0, 4 # salvando 4 em a2
			mul	s1, s1, a2 # corrigindo indexaçao s1 = 4*(j-1)
			mul 	s2, s2, a2  # s2 = 4 * j
			
			
			add	s3, s0, s1 # s3 = endereco de vetor[j-1]
			lw	s5, 0(s3) # s5 = vetor[j-1]
			
			add 	s4, s0, s2 # s4 = endereco de vetor[j]
			lw	s6, 0(s4) # s6  = vetor[j]
			
			#lw	s3, s1(s0) # carregando vetor[j-1] em s3
			#lw 	s4, s2(s0) # carregando vetor [j] em s4
			
			
			
			ble	s5,s6, correct # if vetor[j-1] > vetor [j], continuar, senao, pular;
			
			# trocando posiçao
			# t3 = aux
			mv 	t3, s5 # aux = vetor[j-1]
			mv	t4, s6 # carregando vetor[j] em t4
			sw	t4, 0(s3) # salvando vetor[j] em vetor[j-1]
			sw	t3, 0(s4) # salvando aux ( vetor[j-1]old ) em vetor[j]
			
			correct:
			
		
			addi	t1, t1, -1 # j = j-1
			addi	a1, t0, 1 # fazedo a1 = i+1 (condicao de parada)
			bge	t1, a1, s_loop
		
			
		addi	t0, t0, 1 # i = i+1
		ble	t0, t2, f_loop
		
		# imprimindo
		# t0 = variavel de iteracao
		# t1 = condicao de parada
		addi	t0, x0, 0
		add	t1, x0, t2
		addi	t3, x0, 4 # multiplicacao
		print_loop:
			# s0 => endereco do vetor
			
			# t2 = index do numero atual
			mul	t2, t0, t3 # t2 = i * 4
			
			add	t4, s0, t2 # t4 = endereco do numero atual, tendo t4 = &vetor[0] + 4*i
			
			# printando
			lw	a0, 0(t4)
			addi	a7, x0, 1
			ecall
			
			addi	t0, t0, 1 # i = i+1
			blt 	t0,t1, print_loop
	
	# exit
	addi 	a7, x0, 10
	ecall