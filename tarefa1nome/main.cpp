/*
 * by: fabio
 * proj. desenho linha e triangulo
 */

#include <GL/glut.h>
#include <stdlib.h>

GLfloat escala = 0.3f;

//função para interação de teclado
void listeningKey(unsigned char tecla, GLint col, GLint linha)
{
    switch(tecla)
    {
        case '+':escala=escala+0.05f;
                break;
        case '-':escala=escala-0.05f;
                break;
    }
    glutPostRedisplay();
    //display();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //define a matriz de transformação da câmera
    glMatrixMode(GL_PROJECTION);
    //seta a matrix identidade para a câmera
    glLoadIdentity();
    //define área de enquadramento da cena
    gluOrtho2D(-3, 3, -3, 3);

    //move o objeto
    glTranslatef(-2.0f, 2.0f, 0.0f);

    /*rotacina o objeto
    ordem dos parmetros ANG, X, Y, Z*/
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);

    glScalef(escala, escala, 0);

    //define a matrix de trnsformação dos modelos "não muda o objeto de lugar"
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
    glutKeyboardFunc(listeningKey);
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(display);
    glutMainLoop();
    //return EXIT_SUCCESS;
}
