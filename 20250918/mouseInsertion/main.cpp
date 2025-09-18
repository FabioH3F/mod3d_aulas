/*
 * by: fabio
 * proj. tarefa1
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

float r, g, b, x, y;
bool check=true;

void mouse (int button, int state, int mousex, int y)

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //define a matriz de transformação da câmera
    glMatrixMode(GL_PROJECTION);
    //seta a matrix identidade para a câmera
    glLoadIdentity();
    //define área de enquadramento da cena
    gluOrtho2D(-3, 3, -3, 3);

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
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(display);
    glutMainLoop();
    //return EXIT_SUCCESS;
}
