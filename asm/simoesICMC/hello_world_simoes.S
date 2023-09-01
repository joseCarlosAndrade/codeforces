;loadn	carregar um valor fixo para um registrador
loadn	r0,#'a'
loadn	r1,#0
loadn	r2,#609

;outchar apenas printa o valor de registrador na posicao registrador
outchar	r0,r1

;inc 	incrementa
inc	r1
outchar	r2,r1

;definicao de segmento de data para string
helloWorld: string "HELLO WORLD SIMOES"

;carregando o endereço de memoria do inicio de helloWorld para r0
loadn	r0,#helloWorld
loadn	r4,#0
loadn	r3,#40 ;40 comeca a proxima linha

;label para loop
hello_loop:
	;loadi : reg1 reg2 carrega o valor armazenado no endereco guardado em reg2 para reg1
	loadi	r2,r0
	
	outchar	r2,r3
	inc	r0
	inc	r3
	

	cmp	r2,r4
	jne	hello_loop

;instucao para parar o codigo (rotina de saida)
halt



;FAZER NO LOOP: A CADA ITERACAO, CARREGAR ALGUMA COR EM ALGUM REG, SHIFTAR 8 BITS PRA ESQUERDA E SOMAR COM O CARACTERE PARA GERAR CARACTERE COM COR
