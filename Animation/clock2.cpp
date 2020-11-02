#include <GL/glut.h>
#include <math.h>

struct Point {
	GLint x;
	GLint y;
};

void fun(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat stp = 0;

	if(abs(dx) > abs(dy)) {
		stp = abs(dx);
	} else {
		stp = abs(dy);
	}

	GLfloat incx = dx/stp;
	GLfloat incy = dy/stp;

	for(float i = 1; i <= stp; i++) {
		glVertex2i(x1, y1);
		x1 += incx;
		y1 += incy;
	}
}

void init() {
	glClearColor(1.0, 0.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void draw_circle(Point c, GLfloat radius) {
	GLfloat stp = 1/radius;
	GLfloat x, y;

	for(GLfloat theta = 0; theta <= 360; theta += stp) {
		x = c.x + (radius * cos(theta));
		y = c.y + (radius * sin(theta));
		glVertex2i(x, y);
	}
}

Point c = {200, 200};
GLint radius = 150;


GLint hRadius = 120;
GLint mRadius = 130;
GLint sRadius = 140;


double hDegree = 0;
double mDegree = 0;
double sDegree = 0;

void display(void) {

	Point pHour, pMinute, pSecond;

	pHour.y = c.y + (hRadius * sin(hDegree));
	pHour.x = c.x + (hRadius * cos(hDegree));

	pMinute.y = c.y + (mRadius * sin(mDegree));
	pMinute.x = c.x + (mRadius * cos(mDegree));

	pSecond.y = c.y + (sRadius * sin(sDegree));
	pSecond.x = c.x + (sRadius * cos(sDegree));

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 1.0);
	draw_circle(c, radius);
	glColor3f(1.0, 0.0, 0.0);
	fun(c, pHour);

	glColor3f(0.0, 1.0, 0.0);
	fun(c, pMinute);

	glColor3f(0.0, 0.0, 1.0);
	fun(c, pSecond);
	glEnd();
	glFlush();

	mDegree -= 0.001333333;
	sDegree -= 0.08;
	hDegree -= 0.0002733333;

}

void Timer(int value) {
	glutTimerFunc(33, Timer, 0);
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Rithik :)");
	glutDisplayFunc(display);
	init();
	Timer(0);
	glutMainLoop();

	return 0;
}