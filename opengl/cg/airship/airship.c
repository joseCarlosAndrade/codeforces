#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>

// #define TRIANGLE 0
// #define SQUARE 1
// #define CIRCLE 2
// #define CIRCLE_VERTICES 7

#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<stdlib.h>
#include<math.h>

#define T_JUMP 0.001
#define PI 3.1415
// defining coodinates data types

typedef struct {
	float x, y;
} coordinates;

typedef struct {
	float * matrix;
	float *tx;
	float *ty;
	float tx_inc;
	float ty_inc;
	float angle;
	float angle_inc;
} transform_matrix;

transform_matrix transform_t;
transform_matrix transform_r;
transform_matrix transform_s;

int holding = 0;
int current_key = 0;


// CALLBACK KEY
static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);

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
	"uniform mat4 transle_transformation;\n"
	"uniform mat4 rotate_transformation;\n"
	"uniform mat4 scale_transformation;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = transle_transformation*rotate_transformation*scale_transformation*vec4(position, 0.0, 1.0);\n"
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

	// DEFINING AIRSHIP
	coordinates airship[3] = {
		{-0.1f, 0.0f},
		{ 0.1f, 0.0f},
		{ 0.0f, 0.2f}
	};

	// SENDING AIRSHIP DATA TO GPU
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(airship), airship, GL_DYNAMIC_DRAW);

	GLint loc = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(airship[0]), (void*) 0);

	// window showing
	glfwShowWindow(window);

	// defining callback key function
	glfwSetKeyCallback(window, callback_key);

	// translation matrix definition
	transform_t.matrix = (float*)calloc(16, sizeof(float));
	for(int i = 0; i < 4; i++) {
		transform_t.matrix[i*4 +i] = 1;
	}
	transform_t.tx = &(transform_t.matrix[3]);
	transform_t.ty = &(transform_t.matrix[7]);
	transform_t.tx_inc = 0;
	transform_t.ty_inc = 0;

	// rotation matrix definition
	transform_r.matrix = (float*)calloc(16, sizeof(float));
	for(int i = 0; i < 4; i++) {
		transform_r.matrix[i*4 +i] = 1;
	}

	transform_r.matrix[0] = cos(0);
	transform_r.matrix[1] = -sin(0);
	transform_r.matrix[4] = sin(0);
	transform_r.matrix[5] = cos(0);
	transform_r.angle = 0;
	transform_r.angle_inc = 0;

	// scale matrix
	transform_s.matrix = (float*) calloc(16, sizeof(float));
	for(int i = 0; i < 4; i++) {
		transform_s.matrix[i*4 +i] = 1;
	}
	transform_s.tx = &(transform_s.matrix[0]);
	transform_s.ty = &(transform_s.matrix[5]);
	transform_s.tx_inc = 0;
	transform_s.ty_inc = 0;

	while(!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE)!= GLFW_PRESS)
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.99, 0.99, 0.99, 1.0);

		if (holding) {
			if (current_key == GLFW_KEY_UP) (transform_t.ty_inc ) += T_JUMP ;
			else if (current_key == GLFW_KEY_DOWN) (transform_t.ty_inc ) -= T_JUMP ;
			else if (current_key == GLFW_KEY_RIGHT) (transform_t.tx_inc ) += T_JUMP ;
			else if (current_key == GLFW_KEY_LEFT) (transform_t.tx_inc ) -= T_JUMP ;
		}

		// TRANSFORM MATRIX
		// *(transform_t.tx) += transform_t.tx_inc;
		// *(transform_t.ty) += transform_t.ty_inc;
		float ang_t = transform_r.angle + PI/2;
		*(transform_t.tx) += transform_t.tx_inc * sin(ang_t)+ transform_t.ty_inc * cos(ang_t);
		*(transform_t.ty) += transform_t.ty_inc * sin(ang_t)+ transform_t.tx_inc * cos(ang_t);

		printf("tx: %lf; ty: %lf; ang: %lf; scale: %lf\n", *(transform_t.tx), *(transform_t.ty), transform_r.angle, *(transform_s.tx));

		// if (*(transform_t.tx) >= 1) 
		*(transform_t.tx) *= 1-2*( abs( *(transform_t.tx)) > 1);
		*(transform_t.ty) *= 1-2*( abs( *(transform_t.ty)) > 1);

		// minha logica para desacelerar a nave quando holding == 0
		transform_t.tx_inc += -(0.01 * !holding*10)*transform_t.tx_inc;
		transform_t.ty_inc += -(0.01 * !holding*10)*transform_t.ty_inc;
		
		
		loc = glGetUniformLocation(program, "transle_transformation");
		glUniformMatrix4fv(loc, 1, GL_TRUE, transform_t.matrix);

		// rotation matrix
		float ang = transform_r.angle;
		transform_r.matrix[0] = cos(ang);
		transform_r.matrix[1] = -sin(ang);
		transform_r.matrix[4] = sin(ang);
		transform_r.matrix[5] = cos(ang);
		loc = glGetUniformLocation(program, "rotate_transformation");
		glUniformMatrix4fv(loc, 1, GL_TRUE, transform_r.matrix);

		// scale matrix
		loc = glGetUniformLocation(program, "scale_transformation");
		glUniformMatrix4fv(loc, 1, GL_TRUE, transform_s.matrix);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

}


static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// printf("Key pressed: %d; Scancode pressed: %d; action: %d; mods: %d\n", key, scancode, action, mods);
	current_key = key;

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
		{
			if (key == GLFW_KEY_D) transform_r.angle -= 0.07;
			if (key == GLFW_KEY_A) transform_r.angle += 0.07;
			if (key == GLFW_KEY_W) {
				*(transform_s.tx) += 0.07;
				*(transform_s.ty) += 0.07;
			}
			if (key == GLFW_KEY_S) {
				*(transform_s.tx) -= 0.07;
				*(transform_s.ty) -= 0.07;
			}
			
			holding = 1;
		}
	else holding = 0;

} 
