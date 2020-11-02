#include <GL/glut.h>
#include <math.h>

void all_circle(GLfloat x, GLfloat y, GLfloat r){
    int i;
    int lineAmount = 100;
    GLfloat twicePi = 2.0f * 3.14;
    
    glBegin(GL_LINE_LOOP);
    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(x + (r * cos(i *  twicePi / lineAmount)),y + (r* sin(i * twicePi / lineAmount)));
    }
    glEnd();
    glFlush();
}
void def_line(float x1 , float y1 , float x2 , float y2){
glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
 glEnd();
}
void dis(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glColor3f(1,1,0);  
def_line(-0.5,0,0.5,0.0);
def_line(-0.5,0,-0.4,0.2);
def_line(-0.3,0,-0.4,0.2);
def_line(-0.1,0,0.0,0.2);
def_line(0.1,0,0,0.2);
def_line(0.5,0,0.4,0.2);
def_line(0.3,0,0.4,0.2);
def_line(-0.3,0,-0.3,-0.2);
def_line(-0.1,0,-0.1,-0.2);
def_line(-0.3,-0.2,-0.1,-0.2);
def_line(0.3,0,0.3,-0.2);
def_line(0.1,-0.2,0.3,-0.2);
def_line(0.1,0,0.1,-0.2);
all_circle(-0.2,-0.1,0.1);
all_circle(0.2,-0.1,0.1);
glFlush();
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB);
 glutInitWindowSize(600, 600);
 glutCreateWindow("Rithik Choudhary");
 glutDisplayFunc(dis);
 glutMainLoop();
 return 0;
}