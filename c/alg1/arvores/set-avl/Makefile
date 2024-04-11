C_FLAGS+=-Wall -Wextra -Wpedantic  -std=c99 -Iinclude

all:
	mkdir -p bin/
	gcc -o bin/main $(C_FLAGS) src/*.c

run:
	./bin/main