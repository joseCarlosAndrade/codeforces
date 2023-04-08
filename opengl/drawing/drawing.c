#include <GL/gl.h>
#include <GL/glut.h>   // Consider using freeglut.h instead, if available.
#include <stdio.h>     // (Used only for some information messages to standard out.)
#include <stdlib.h>   

void DrawCallback(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    // cor concorrente (atual) da maquina de estados
    glColor3f(0.0f, 1.0f, 0.0f);

    // renderiza um quadrado
    glBegin(GL_QUADS);
        glVertex2i(100, 150);
        glVertex2i(100, 100);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(150, 100);
        glVertex2i(150, 150);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(200, 200);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(10, 10);
    glEnd();

    glFlush();
}

void Initialization(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}

// callback para redimensionamento da janela
void ResizeWindow(GLsizei w, GLsizei h)
{
    // evitar divisao por 0 
    if (h == 0) h =1;

    // tamanho janela de visualizaçao
    glViewport(0, 0, w, h);

    // sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

// https://stackoverflow.com/questions/49705057/not-understanding-the-gluortho2d-function
// equivalencia de lados para o viewport (janela que apresenta a visualizaçao)
    if (w <= h) gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else gluOrtho2D(0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 350);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Square");
    glutDisplayFunc(DrawCallback);
    glutReshapeFunc(ResizeWindow);
    Initialization();
    glutMainLoop();
}