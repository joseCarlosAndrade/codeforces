CXX_FLAGS+=-Wall -Wextra -Wpedantic -Werror -std=c++14 -Iinclude
LD_FLAGS+= -lSDL2

all:
	mkdir -p bin/
	g++ src/main.cpp include/Matrices.hpp $(CXX_FLAGS) $(LD_FLAGS) -O3 -o bin/main

minion:
	mkdir -p bin/
	g++ src/minion.cpp include/Matrices.hpp $(CXX_FLAGS) $(LD_FLAGS) -O3 -o bin/minion

run:
	./bin/main

run_minion:
	./bin/minion
