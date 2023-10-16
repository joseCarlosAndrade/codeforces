all: main.c bin/lista.o bin/item.o
	mkdir -p bin/
	gcc -o bin/main main.c bin/*.o -Wall -std=c99

bin/lista.o: src/lista.c include/lista.h
	mkdir -p bin/
	gcc -c src/lista.c -o bin/lista.o

bin/item.o: src/item.c include/item.h
	mkdir -p bin/
	gcc -c src/item.c -o bin/item.o

run:
	./bin/main

