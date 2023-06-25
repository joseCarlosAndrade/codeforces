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

## Clean

If you need to clean the directory of all *.o *.c~ and *.h~ (~ after that stands for editors backups) you can add a `clean` target to your Makefile.

	.PHONY: clean
	clean:
		rm -f myProgram *.o *.c~ *.h~

Note: `.PHONY: clean` indicates that `clean` is a phony target, so make won't generate a `clean` file nor check for its existence.

## Generic rules

Instead of repeating the same rules for different targets, we can use the generic rules. Since in our example we're only building .o files from .c file (besides also depending on the header), we can use the `%.o`, `%.c` signs to indicate files with the same name but .c and .o extensions and the special variable `$<`, which make will set to the name of the first prerequisite of the rule (as we specified, `%.c` files). We also add the dependency of headers on the end of the file, but not setting new rules: 


	CFLAGS=-std=c99 -Wall -march=native
	myProgram: oneFile.o anotherFile.o
		gcc -o myProgram oneFile.o anotherFile.o
	%.o: %.c # Building .o from .c of the same name
		gcc $(CFLAGS) -c $< # Special variable: the %.c name
	.PHONY: clean
	clean:
		rm -f myProgram *.o *.c~ *.h~
	oneFile.o: oneHeader.h someHeader.h
	anotherFile.o: anotherHeader.h someHeader.h

## Makedepend

To avoid writing and tracking all dependencies by hand, there's a tool called `makedepend` that tracks all requirements of the directory and edits the makefile.

