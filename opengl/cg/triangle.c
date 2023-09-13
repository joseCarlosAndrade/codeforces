#include<stdio.h>
#include<GL/glew.h>

// #define TRIANGLE 0
// #define SQUARE 1
// #define CIRCLE 2
#define CIRCLE_VERTICES 73

#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<stdlib.h>
#include<math.h>

// defining coodinates data types

typedef struct {
	float x, y;
} coordinates;

// CALLBACK KEY
GLFWkeyfun callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);

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
	"	gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);\n"
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

	// square
	// coordinates vertices[4] = {
	// 	{ -0.50f, -0.50f},
	// 	{ +0.50f, -0.50f},
	// 	{ -0.50f, +0.50f},
	// 	{ +0.50f, +0.50f}
	// };

	// circle
	// coordinates vertices[CIRCLE_VERTICES];
	// float radius = 0.5f;
	// float pi = 3.141592f;
	// float di = 2*pi / CIRCLE_VERTICES;
	
	// for (int i = 0; i < CIRCLE_VERTICES; i++ ) {

	// 	vertices[i].x = radius * cos(i * di);
	// 	vertices[i].y = radius * sin(i * di);

	// 	vertices[i+1].x = radius * cos((i+1) * di);
	// 	vertices[i+1].y = radius * sin((i+1) * di);
	// }

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	GLint loc = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*) 0);

	glfwShowWindow(window);

	// glfwSetKeyCallback(window, callback_key);

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0, 1.0, 1.0, 1.0);
		// glColor3f(0.5f, 1.0f, 0.f);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		// glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		// glDrawArrays(GL_TRIANGLE_FAN, 0, CIRCLE_VERTICES);
		

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

}


GLFWkeyfun callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("Key pressed: %d; Scancode pressed: %d; action: %d; mods: %d\n", key, scancode, action, mods);
}
