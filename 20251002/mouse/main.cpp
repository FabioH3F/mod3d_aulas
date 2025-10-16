#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

float x1, y1, x2, y2;
int clickCount = 0;
bool check = false;

void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (clickCount == 0)
        {
            x1 = mousex;
            y1 = 480 - mousey;
            clickCount = 1;
            printf("clique na tela\n");
        }
        else
        {
            x2 = mousex;
            y2 = 480 - mousey;
            clickCount = 0;
            check = true;
            printf("clique na tela\n");
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
    }
    glutPostRedisplay();
}

static void display(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    if (check)
    {
        glColor3f(0, 0, 0);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("GLUT Shapes");
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return EXIT_SUCCESS;
}
