#include<GL/glut.h>
GLfloat t,u=1;
void init(){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(10.0);
    glOrtho(0,600,0,600,0,10);
}

float xval=105,yval=105, orig=105;

void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0,1,1);
     glBegin(GL_LINES);
     glVertex2f(100,100);
     glVertex2f(100,200);
     glVertex2f(100,200);
     glVertex2f(200,200);
     glVertex2f(200,200);
     glVertex2f(200,100);
     glVertex2f(200,100);
     glVertex2f(100,100);
     glEnd();
     glFlush();
     glBegin(GL_POINTS);
     glVertex2f(xval,yval);
     glEnd();
     glFlush();
}

void callFill(float x, float y)
{
    glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0,0,1);
     glVertex2f(x,y);
     glEnd();
     glFlush();
}


void fillit()
{
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    glVertex2f(xval,yval);
    glEnd();
    glFlush();
}


void key(unsigned char button,int x,int y){
    if(button=='s'){
            if(xval<195)
            {
                xval+=5;
            }
            else{
                xval=105;
                yval+=5;
                if(yval > 195)
                {
                    for(int temp = 1; temp < 10000000;temp++)
                    {
                        for(int temp2 = 1; temp2 < 10000000 ; temp2++)
                        {
                            ;
                        }
                    }
                    exit(0);
                }
            }
    }
    fillit();
}



int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Window");
    init();
    glutDisplayFunc(display);
   glutKeyboardFunc(key);
    glutMainLoop();
} 
