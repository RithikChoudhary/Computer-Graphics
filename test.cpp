
// Basic C++ Program
#include <GL/glut.h>
#include <GL/freeglut.h>
void displayMe(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glColor3f(0.0,1.0,0.0);
glVertex3f(0.5, 0.0, 0.0);
glVertex3f(0.0, 0.5, 0.0);
glVertex3f(0.0, 0.0, 0.0);
// glVertex3f(0.0, 0.0, 0.0);
glEnd();
glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(400, 300);
glutInitWindowPosition(100, 100);
glutCreateWindow("Hello world!");
glutDisplayFunc(displayMe);
//glutDisplayFunc(render);


glutMainLoop();
return 0;
}


