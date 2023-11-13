all: item.o ab.o main.o soma.o
	gcc item.o ab.o main.o soma.o -o ab -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

ab.o:
	gcc -c ab.c -o ab.o

soma.o:
	gcc -c soma.c -o soma.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o ab

run:
	./ab
