#include<GL/glut.h>
#include<stdio.h>
// a math exige em radianos os angulos
#include <math.h>
#define PI 3.1415926535898
GLfloat escala = 1;
int i = 0;

void circulo (float dx, float dy)
{
    float ang, x, y;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 360; i++)
        // a math exige em radianos os angulos, entao como definimos em graus o i no for, precisamos passar esses angulos em radianos
    {
//angle = 2*PI*i/circle_points;
// passamos o angulo para radianos
        ang = (i * PI) / 180.0;
        // o valor "0" eh para posicionar o elemento "eh o centro de" , o *4 eh para multipilicar o tamanho do circulo
        x = dx + (cos(ang) * escala);
        y = dy + (sin(ang) * escala);
        glVertex2f(x, y);
    }
    glEnd();
}

void desenha(void)
{
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 0, 0);
    glLineWidth(6);

    circulo(0, 0);
    circulo(2, 0);
    circulo(4 , 0);


    glFlush();
}
void listeningKey (unsigned char tecla,
                   GLint x, GLint y)
{
    switch(tecla)
    {
    case '+':
        escala=escala+0.25;
        break;
    case '-':
        escala=escala-0.25;
        break;
    }
    desenha();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Ola Glut");
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}


