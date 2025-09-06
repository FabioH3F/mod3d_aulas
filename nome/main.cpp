/*
 * by: fabio
 * proj. desenho linha e triangulo
 *06/09/2025
 */

#include <GL/glut.h>
#include <stdlib.h>

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //define a matriz de transformação da câmera
    glMatrixMode(GL_PROJECTION);
    //seta a matrix identidade para a câmera
    glLoadIdentity();
    //define área de enquadramento da cena
    gluOrtho2D(-10, 10, -10, 10);

    //define a matrix de trnsformação dos modelos
    glMatrixMode(GL_MODELVIEW);
    //seta a matrix identidade para o modelos
    glLoadIdentity();

    glLineWidth(10);
    glBegin(GL_LINES);
        //H
        glVertex2f(-8.0f, 8.0f);
        glVertex2f(-8.0f, -8.0f);

        glVertex2f(-8.0f, 5.0f);
        glVertex2f(-6.0f, 5.0f);

        glVertex2f(-6.0f, 8.0f);
        glVertex2f(-6.0f, -8.0f);

        //E
        glVertex2f(-1.0f, 8.0f);
        glVertex2f(-1.0f, -8.0f);

        glVertex2f(-1.0f, 8.0f);
        glVertex2f(1.0f, 8.0f);

        glVertex2f(-1.0f, 5.0f);
        glVertex2f(1.0f, 5.0f);

        glVertex2f(-1.0f, -8.0f);
        glVertex2f(1.0f, -8.0f);

        //F
        glVertex2f(6.0f, 8.0f);
        glVertex2f(6.0f, -8.0f);

        glVertex2f(6.0f, 8.0f);
        glVertex2f(8.0f, 8.0f);

        glVertex2f(6.0f, 5.0f);
        glVertex2f(8.0f, 5.0f);
    glEnd();

    glFlush();


}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    //as letras maiuscula sao conatntes
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Shapes");
    glClearColor(0.4, 0, 1, 0);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
