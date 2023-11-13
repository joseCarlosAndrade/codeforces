GL_FLAGS=-lglfw -lGL -lGLEW
CXX_FLAGS=-std=c++14 -O3 -Wall -Iinclude -g
# CFLAGS =  --cflags=opencv
# LIBS =  --libs=opencv

all: 
	mkdir -p bin/
	g++ texture.cpp -o bin/textures ${GL_FLAGS} ${CXX_FLAGS} 

run:
	./bin/textures