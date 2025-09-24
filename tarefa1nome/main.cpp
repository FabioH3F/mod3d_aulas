/*
 * by: fabio
 * proj. tarefa1
 */
#include<stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

GLfloat escala = 0.3f;
GLfloat rotacao = 0.0f;
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat min_escala = 0.1f;

void nome()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    // F
    glVertex2f(-8, -4); glVertex2f(-8, 4);
    glVertex2f(-8, 4);  glVertex2f(-6, 4);
    glVertex2f(-8, 0);  glVertex2f(-6.5f, 0);

    // A
    glVertex2f(-4.5f, -4); glVertex2f(-3, 4);
    glVertex2f(-3, 4);     glVertex2f(-1.5f, -4);
    glVertex2f(-4, 0);     glVertex2f(-2, 0);

    // B
    glVertex2f(0, -4);  glVertex2f(0, 4);
    glVertex2f(0, 4);   glVertex2f(1.5f, 4);
    glVertex2f(1.5f, 4); glVertex2f(1.5f, 1);
    glVertex2f(1.5f, 1); glVertex2f(0, 1);
    glVertex2f(0, 0);   glVertex2f(1.8f, 0);
    glVertex2f(1.8f, 0); glVertex2f(1.8f, -4);
    glVertex2f(1.8f, -4); glVertex2f(0, -4);

    // I
    glVertex2f(3, -4);  glVertex2f(3, 4);
    glVertex2f(2.5f, 4); glVertex2f(3.5f, 4);
    glVertex2f(2.5f, -4); glVertex2f(3.5f, -4);

    // O
    glVertex2f(5.5f, 4); glVertex2f(5.5f, -4);
    glVertex2f(6.5f, 4); glVertex2f(6.5f, -4);
    glVertex2f(5.5f, 4); glVertex2f(6.5f, 4);
    glVertex2f(5.5f, -4); glVertex2f(6.5f, -4);
    glEnd();
}

int dentroTela(GLfloat novo_x, GLfloat novo_y) {
    GLfloat limite = 8.0f * escala;
    return (novo_x - limite > -10 && novo_x + limite < 10 &&
            novo_y - limite > -7 && novo_y + limite < 7);
}


//função para interação de teclado
void listeningKey(unsigned char tecla, GLint col, GLint linha)
{

    switch(tecla)
    {

        case '+': if (escala < 1.0f) escala += 0.05f; break;
        case '-': if (escala > min_escala) escala -= 0.05f; break;
        case 'q': rotacao += 5.0f; break;
        case 'e': rotacao -= 5.0f; break;
        case 'a': if (dentroTela(x - 0.2f, y)) x -= 0.2f; break;
        case 'd': if (dentroTela(x + 0.2f, y)) x += 0.2f; break;
        case 'w': if (dentroTela(x, y + 0.2f)) y += 0.2f; break;
        case 's': if (dentroTela(x, y - 0.2f)) y -= 0.2f; break;
    }
    glutPostRedisplay();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //define a matriz de transformação da câmera
    glMatrixMode(GL_PROJECTION);
    //seta a matrix identidade para a câmera
    glLoadIdentity();
    //define área de enquadramento da cena
    gluOrtho2D(-10, 10, -7, 7);

    //move o objeto
    glTranslatef(x, y, 0.0f);

    /*rotacina o objeto
    ordem dos parmetros ANG, X, Y, Z*/
    glRotatef(rotacao, 0.0f, 0.0f, 1.0f);

    glScalef(escala, escala, 1.0f);

    //define a matrix de transformação dos modelos "não muda o objeto de lugar"
    glMatrixMode(GL_MODELVIEW);
    //seta a matrix identidade para o modelos
    glLoadIdentity();

    nome();

    glFlush();

}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
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
