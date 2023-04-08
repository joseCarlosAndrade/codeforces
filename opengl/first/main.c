#include <GL/gl.h>
#include <GL/glut.h>   // Consider using freeglut.h instead, if available.
#include <stdio.h>     // (Used only for some information messages to standard out.)
#include <stdlib.h>     

// callback para redesenhar
void DrawCallback(void)
{
    // limpa o buffer do desenho e deixa com a cor especificada
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();

}

void Initialization(void)
{
    // define a cor de fundo
    //  4 parametros GLclampf (float ) de 0 a 1: r g b a
    
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char ** argv)
{
    // define display mode como single buffer e rgb
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Window name");
    glutDisplayFunc(DrawCallback); // definimos o callback
    Initialization();
    glutMainLoop();
}