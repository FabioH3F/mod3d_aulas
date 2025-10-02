#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
GLfloat windowWidth;
GLfloat windowHeight;

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 3.0f);
    glBegin(GL_QUADS);
        glVertex2i(x1,y1+rsize);
        glVertex2i(x1,y1);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2i(x1+rsize,y1);
        glVertex2i(x1+rsize,y1+rsize);
    glEnd();

    //swap, pq na main na, glutInitDisplayMode, esta com parametros double
    glutSwapBuffers();
}
void Timer(int value)//aqui tem a movimentacao de quadros por tempo
{
// Muda a direcao o quando chega na borda esquerda ou direita
    if(x1 > windowWidth-rsize || x1 < 0)
        xstep = -xstep;
// Muda a direcao o quando chega na borda superior ou inferior
    if(y1 > windowHeight-rsize || y1 < 0)
        ystep = -ystep;
// Verifica o de bordas. Se a window for menor e o quadrado sair do volume de
    if(x1 > windowWidth-rsize)
        x1 = windowWidth-rsize-1;
    if(y1 > windowHeight-rsize)
        y1 = windowHeight-rsize-1;

    //incrementar os valores dos vertices com a translacao
    x1 += xstep;
    y1 += ystep;

    glutPostRedisplay();

    //func. (daqui quanto tempo qure que a mostre a imagem novamente)
    glutTimerFunc(5,Timer, 0);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    printf("\n w: %d h: %d ", w, h);
    //viewport eh a posicao da camera
    //para 3d eh legal usar 4 VP (z, y, x, pesp.)
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    windowWidth = w;
    windowHeight = h;
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    // eh recomendado usar o framebuffer GLUT_DOUBLE, para ficar limpo,s em resquicio do desenho anterior
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Animacao");
    glutDisplayFunc(Desenha);
    //quando alterar o user alterar o tamnho da jeanela
    glutReshapeFunc(AlteraTamanhoJanela);
    glutTimerFunc(5, Timer, 0);
    glutMainLoop();
}
