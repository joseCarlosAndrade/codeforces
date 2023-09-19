C_FLAGS=-std=c99 -Wall -march=native

run:
	./bin/maze

all: maze/maze.c stack.o item.o
	mkdir -p bin/
	gcc bin/*.o maze/maze.c $(C_FLAGS) -o bin/maze

stack_check: tests/stack_check.c stack.o item.o
	mkdir -p bin/
	gcc bin/*.o tests/stack_check.c $(C_FLAGS) -o bin/stack_example

run_example:
	./bin/stack_example

stack.o: src/stack.c include/stack.h
	mkdir -p bin/
	gcc -c src/stack.c -o bin/stack.o

item.o: src/item.c include/item.h
	mkdir -p bin/
	gcc -c src/item.c -o bin/item.o

clean:
	rm bin/*
		
