#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>
#include<GL/glut.h>

#include<string.h>

#define WIDTH 500
#define HEIGHT 500

void read_source_file(char * shader, char * file_name);

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Glut window opengl");
    glewInit();
    glutDisplayFunc(display);

    GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    char * vertex_code = NULL;
    char * fragment_code = NULL;

    read_source_file(vertex_code, "shaders/vsource.glsl");
    read_source_file(fragment_code, "shaders/fsource.glsl");

	// associating shader sources with glsl code
	glShaderSource(vertex, 1, &vertex_code, NULL);
	glShaderSource(fragment, 1, &fragment_code, NULL);

	glCompileShader(vertex); // compiling

    init();
    glutMainLoop();
}

void read_source_file(char * shader, char * file_name) {
    FILE *fp = NULL;
    fp = fopen(file_name, "r");
    shader = (char*)calloc(1,sizeof(char));

    while (!feof(fp)) {
        char buffer[100];
        fscanf(fp, "%[^\n]s", buffer);
        shader = realloc(shader, sizeof(char)*(sizeof(buffer) + sizeof(shader) ));

        strcat(shader, buffer);
    }
}