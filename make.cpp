// #include<iostream.h>
#include<GL/glut.h>

// void show()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glBegin(GL_POLYGON);
// 	glColor3f(1.0,0.0,0.0);
// 	glVertex3f(-1.0,0.0,0.0);
// 	glVertex3f(0.0,1.0,0.0);
// 	glVertex3f(0.0,0.0,0.0);
// 	glEnd();
// 	glFlush();
// }
// void square()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glBegin(GL_POLYGON);
// 	glColor3f(1.0,0.0,0.0);
// 	// glVertex3f(-0.1,0.0,0.0);
// 	// glVertex3f(-1.0,-1.0,0.0);
// 	// glVertex3f(1.0,-1.0,0.0);
// 	// glVertex3f(0.0,0.0,0.0);
// 	glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
// 	glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner
// 	glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner
// 	glVertex3f(1.0f, -1.0f, 0.0f);
// 	glEnd();
// 	glFlush();

// }
// void displayme()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glBegin(GL_POLYGON);
// 	// glColor3f(0.0,1.0,0.0);
// 	// glVertex3f(1.0,0.0,0.0);
// 	// glVertex3f(0.0,1.0,0.0);
// 	// glVertex3f(0.0,0.0,0.0);
// 	// show();
// 	// square();
// 	glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
// 	glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner
// 	glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner
// 	// The end of the second triangle
// 	glVertex3f(1.0f, -1.0f, 0.0f); // The bottom right corner
// 	glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
// 	// glVertex3f(-1.0,0.0,0.0);
// 	glEnd();
// 	glFlush();
// 	// show();
// }


void StackedBar(void)
{
// Clear the Screen
glClear(GL_COLOR_BUFFER_BIT);

float colors[6][3] = { { 1,0,0 },{ 1,1,0 },{ 0,1,0 },{ 0,1,1 },{ 1,0,1 },{0,0,1} };
float data[6] = { 20,66,42,28,71,23 };
float x = 0, y = 0;
float dy;

glBegin(GL_QUADS);
for (int i = 0; i < 6; i++) {
    glColor3f(colors[i][0], colors[i][1], colors[i][2]);
    dy = data[i];
    glVertex2f(x, y);
    glVertex2f(x + 5, y);
    glVertex2f(x + 5, y + dy);
    glVertex2f(x, y + dy);
    y += dy;

    //x +=5; incremented x just to see how the pieces are positioned
}
glEnd();

// force execution of GL commands
glFlush();
}
int main(int argc,char **argx)
{
	glutInit(&argc,argx);
	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(700,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lets do it");
	glutDisplayFunc(StackedBar);
	glutMainLoop();
	return 0;
}