# Make summary 

Example text to simple make files. Source: [Coursera](https://www.coursera.org/learn/writing-running-fixing-code/)

First case, you have `myProgram`, that depends on `oneFile.o` and `anotherFile.o`. The first depends on `oneFile.c`, `oneHeader.h` and `someHeader.h`, the second, on `anotherFile.c`, `anotherHeader.h` and also `someHeader.h`.

So, in order to build them with make, we could define a FLAG so that we don't have to manually type it every line, and then all the three targes with its dependencies and rules on the next line spaced by TABS.

	CFLAGS=-std=c99 -Wall -march=native
	myProgram: oneFile.o anotherFile.o
		gcc -o myProgram oneFile.o anotherFile.o
	oneFile.o: oneFile.c oneHeader.h someHeader.h
		gcc $(CFLAGS) -c oneFile.c
	anotherFile.o: anotherFile.c anotherHeader.h someHeader.h
		gcc $(CFLAGS) -c anotherFile.c

On this example, we did not set rules for neither of the header files, so we assume they already exist. In case they don't, the make will throuw an error:
	
	make: *** No rule to make target 'oneHeader.h', needed by 'oneFile.o'. Stop.


