#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

float r, g, b;
float x1, y1, x2, y2;
int clickCount = 0;
bool drawLine = false;

void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (clickCount == 0)
        {
            // Primeiro clique
            x1 = mousex;
            y1 = 480 - mousey;
            clickCount = 1;

            // Gera cor aleatória
            r = (rand() % 10) / 10.0;
            g = (rand() % 10) / 10.0;
            b = (rand() % 10) / 10.0;
        }
        else if (clickCount == 1)
        {
            // Segundo clique
            x2 = mousex;
            y2 = 480 - mousey;
            clickCount = 0;
            drawLine = true;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // Limpa a tela
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        drawLine = false;
        clickCount = 0;
    }
    glutPostRedisplay();
}

static void display(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    if (drawLine)
    {
        glColor3f(r, g, b);
        glLineWidth(3.0);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }

    glFlush();
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("GLUT Shapes");
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return EXIT_SUCCESS;
}
