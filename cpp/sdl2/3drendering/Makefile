CXX_FLAGS+=-Wall -Wextra -Wpedantic -Werror -std=c++14 -Iinclude
LD_FLAGS+= -lSDL2

points_to_line:
	mkdir -p bin/
	g++ src/points_to_line.cpp include/Matrices.hpp $(CXX_FLAGS) $(LD_FLAGS) -O3 -o bin/points_to_line
