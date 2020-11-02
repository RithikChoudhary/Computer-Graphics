 
#include<GL/glut.h>
#include<math.h>
#include<unistd.h>
#define pi 3.142857

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(-100, 100, -100, 100);
}

void car(int z) //z is the no of time the function is called
{
	float x,y;
	glBegin(GL_POINTS);
		for(float i=0;i<(2*pi);i=i+0.001)
		{
			x = 5 * cos(i);
			y = 5 * sin(i);
			glVertex2f(x-50+25*(z-1),y);
		}
		for(float i=0;i<(2*pi);i=i+0.001)
		{
			x = 5 * cos(i);
			y = 5 * sin(i);
			glVertex2f(x-25+25*(z-1),y);
		}
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-50+25*(z-1),5);
		glVertex2f(-50+25*(z-1),10);
		glVertex2f(-50+25*(z-1),5);
		glVertex2f(-25+25*(z-1),5);
		glVertex2f(-25+25*(z-1),5);
		glVertex2f(-25+25*(z-1),10);
		glVertex2f(-50+25*(z-1),10);
		glVertex2f(-25+25*(z-1),10);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//first car
	for(int i=0;i<10;i++){
	car(1);
	glFlush();
	
	sleep(2);
	
	//second car
	glClear(GL_COLOR_BUFFER_BIT);
	car(2);
	glFlush();
	
	sleep(2);
	
	//third car
	glClear(GL_COLOR_BUFFER_BIT);
	car(3);
	glFlush();
	
	sleep(2);
	
	//fourth car
	glClear(GL_COLOR_BUFFER_BIT);
	car(4);
	glFlush();
}
}

int main(int argc, char** argv)
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	
	glutInitWindowSize(500, 500); 
	glutInitWindowPosition(50,50); 
	
	
	glutCreateWindow("Moving Car"); 
	init(); 
	glutDisplayFunc(display); 
	glutMainLoop(); 
}