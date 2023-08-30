all: ponto.o circulo.o main.o
	gcc circulo.o ponto.o main.c -o main -std=c99 -Wall -lm
main.o: main.c circulo.h ponto.h
	gcc -c main.c

ponto.o: ponto.c ponto.h
	gcc -c ponto.c -o ponto.o
	
circulo.o: circulo.c circulo.h ponto.h
	gcc -c circulo.c -o circulo.o

run:
	./main
clean:
	rm ponto.o
	rm circulo.o
	rm main
