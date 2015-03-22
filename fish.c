#include <GL/glut.h>
#include <stdio.h>

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(5.0);
	glLineWidth(1.0);
	glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
	gluOrtho2D(0.0,400.0,0.0,400.0);
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
 
	glBegin(GL_LINE_LOOP);				//head
	glColor3f(0.0,0.0,0.0);
	glVertex2i(40,200);
	glVertex2i(120,280);
	glVertex2i(320,200);
	glVertex2i(100,160);
	glEnd();
	
	glBegin(GL_LINE_LOOP);			// tail
	glColor3f(0.0,0.0,0.0);
	glVertex2i(320,200);
	glVertex2i(360,240);
	glVertex2i(340,200);
	glVertex2i(360,160);
	glVertex2i(320,200);
	glEnd();
	
/*	glBegin(GL_LINE_LOOP);		 // extra features
	glColor3f(0.0,0.0,0.0);
	glVertex2i(120,280);
	glVertex2i(140,300);
	glVertex2i(280,216);
	glVertex2i(120,280);
	glEnd();
 
	glBegin(GL_LINE_LOOP);		 
	glColor3f(0.0,0.0,0.0);
	glVertex2i(100,160);
	glVertex2i(140,200);
	glVertex2i(120,164);
	glVertex2i(100,160);
	glEnd(); */
	glFlush();
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(150,150);   
	glutInitWindowSize(500,500);
	glutCreateWindow("fish");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
}
