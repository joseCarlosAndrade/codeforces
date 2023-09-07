#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include<map>
#include<chrono>
#include<stdio.h>
#include<stdlib.h>

#define WIDTH 500
#define HEIGHT 500

struct key {
    bool cur, prev;
};

GLFWwindow * window;
GLFWmonitor *monitor;

bool running, fullscreen;

std::map<int, key> keyMap;

void closeFunctionCallback(GLFWwindow*window) {
    std::cout << "Closing window.." << std::endl;
    running = false;
    glfwSetWindowShouldClose(window, 1);
}

void update() {

}
void input() {
    glfwPollEvents(); // processes all the events
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { // if escape is pressed
        running = false;
        glfwSetWindowShouldClose(window, 1);
    }

    if (glfwGetKey(window, GLFW_KEY_F)== GLFW_PRESS && keyMap[GLFW_KEY_F].prev) {
        if (!fullscreen) glfwSetWindowMonitor(window, monitor, 0, 0, WIDTH, HEIGHT, 0);
        if(fullscreen) glfwSetWindowMonitor(window,NULL, 0, 0, WIDTH, HEIGHT, 0);

        fullscreen = !fullscreen;
    }

    if (glfwSetWindowCloseCallback(window, closeFunctionCallback));

    keyMap[GLFW_KEY_F].prev = glfwGetKey(window, GLFW_KEY_F); // saves the last state of key f on map
}
void draw() {
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //draw stuff

    glBegin(GL_TRIANGLE_FAN);


    glfwSwapBuffers(window);
}

int main(void) {

    // gints to window system
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    if(!glfwInit()) fprintf(stderr, "not initialized\n");

    window = glfwCreateWindow(WIDTH, HEIGHT, "windowwww", NULL, NULL);
    if(window==NULL) {
        std::cout << "Failed to open window" << std::endl; 
        glfwTerminate();
    }

    glfwMakeContextCurrent(window); // focuses on window
    monitor = glfwGetPrimaryMonitor();
    running =true;
    fullscreen=false;

    double lastTime = 0.0;

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

    // associating the created programns to main code
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	// linking
	glLinkProgram(program);
	glUseProgram(program);


    GLfloat vertices[6][2] = {
        {-50/WIDTH, -50/WIDTH},
        {0, -50/WIDTH},
        {0, 0},
        {0, 0},
        {-50/WIDTH, 0},
        {-50/WIDTH, -50/WIDTH},
    };

    GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	GLint loc = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*) 0);
    
    while(running) {
        double time = glfwGetTime();
        double deltaTime = time-lastTime;

        if(deltaTime >= 1/30) { // only run this 60 times a second
            lastTime = time;
            draw();
        }
    
        update();
        input();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}