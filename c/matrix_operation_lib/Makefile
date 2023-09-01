C_ARGS=-Wall -std=c99 -march=native

all: main.c initialization.c matrix_operations.h
	gcc *c -o bin/main $(C_ARGS)

run: 
	./bin/main

init: initialization.o 
	gcc operations.o -o bin/main $(C_ARGS)

initialization.o: initialization.c matrix_operations.h
	gcc initialization.c -c $(C_ARGS)

clean:
	rm bin/main
	rm *.o
