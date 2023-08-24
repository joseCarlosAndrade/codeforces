#include<stdio.h>
#include<GL/glew.h>

#define 

#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<stdlib.h>
#include<math.h>

// defining coodinates data types

typedef struct {
	float x, y;
} coordinates;

int main( int argc, char ** argv)
{

	glfwInit();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // sets window visibility to false so it loads correctly before showing up

	GLFWwindow * window = glfwCreateWindow(500, 500, "Black Eyes Sunflower", NULL, NULL);

	glfwMakeContextCurrent(window); 

	// Status initialization of glew
	GLint GlewInitResult = glewInit();
	printf("Status of Glew initialization: %s\n", glewGetErrorString(GlewInitResult));

	// GLSL LANGUAGE SIMPLE EXAMPLE - its recommended to write this on another file
	const GLchar * vertex_code =
	"attribute vec2 position;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = vec4(position, 0.0, 1.0);\n"
	"}\n";

	const GLchar* fragment_code =
	"uniform vec4 color;\n"
	"void main() {\n"
	"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
	"}\n"; //rgba normalized

	// requiring gpu slots
	GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

	// associating shader sources with glsl code
	glShaderSource(vertex, 1, &vertex_code, NULL);
	glShaderSource(fragment, 1, &fragment_code, NULL);

	glCompileShader(vertex); // compiling

	// error handling
	GLint isCompiled = 0;

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &isCompiled);
	if(isCompiled == GL_FALSE)
	{
		int infoLength = 512;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &infoLength);

		char info[infoLength];
		glGetShaderInfoLog(vertex, infoLength, NULL, info);

		printf("Error on vertex shader: %s\n", &info);
	}
	glCompileShader(fragment);

    isCompiled = 0;
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE){

        //descobrindo o tamanho do log de erro
        int infoLength = 512;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &infoLength);

        //recuperando o log de erro e imprimindo na tela
        char info[infoLength];                                        
        glGetShaderInfoLog(fragment, infoLength, NULL, info);         
                                                                      
        printf("Erro de compilacao no Fragment Shader.\n");           
        printf("--> %s\n",&info);                                     
                                                                      
    }                 

	// associating the created programns to main code
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	// linking
	glLinkProgram(program);
	glUseProgram(program);

	// CREATING THE VERTICES 
	// simple triangle:
	coordinates vertices[3] = {
		{-0.5f, 0.0f},
		{0.0f, 0.5f},
		{0.5f, 0.0f}
	};

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	GLint loc = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*) 0);

	glfwShowWindow(window);

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0, 1.0, 1.0, 1.0);

		glDrawArrays(GL_TRIANGLES, 0, 32);

		glfwSwapBuffers(window);
	}


}
